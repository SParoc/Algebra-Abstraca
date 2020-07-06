#include <iostream>
#include <vector>
#include <NTL/ZZ.h>
#include <windows.h>
NTL_CLIENT
using namespace std;

void generar(int K[], int n);
void RC4(vector<int>& vec);
void DES(vector<int>& vec, int K[], int n);
void corrIzquierda(int V[]);
void corrDerecha(int V[]);
void semillas(vector<int>& k);
int mod(long long a, int b);

ZZ rand(int bits)
{
    vector<int> num;
    int n = 0;
    for (int i = 0; i < bits / 48; i++) {
        int K[48];
        generar(K, mod(n, 16));
        num.insert(num.end(), K, K + 48);
        n++;
    }
    int K[48];
    generar(K, mod(n, 16));
    num.insert(num.end(), K, K + bits - num.size());
    num[0] = 1;
    num[bits - 1] = 1;
    ZZ x(0), y(1);
    for (int i = num.size() - 1; i >= 0; i--)
    {
        if (num[i])
        {
            x += y;
        }
        y *= 2;
    }
    return x;
}
void generar(int K[], int n)
{
    vector<int> vec;
    RC4(vec);
    DES(vec, K, n);
}
void RC4(vector<int>& vec)
{
    int S[256];
    int f, aux, t;
    vector<int> k;
    semillas(k);
    for (int i = 0; i < 256; i++)
    {
        S[i] = i;
    }
    f = 0;
    for (int i = 0; i < 256; i++)
    {
        f = (f + S[i] + k[mod(i, k.size())]) % 256;
        aux = S[i];
        S[i] = S[f];
        S[f] = aux;
    }
    f = 0;
    int i = 0;

    while (vec.size() < 64)
    {
        i = mod(i + 1, 256);
        f = mod(f + S[i], 256);
        aux = S[i];
        S[i] = S[f];
        S[f] = aux;
        t = mod(S[i] + S[f], 256);
        int bin[8];
        for (int i = 0, x = S[t]; i < 8; i++, x /= 2)
        {
            bin[i] = mod(x, 2);
        }
        for (int i = 7; i >= 0; i--)
        {
            vec.push_back(bin[i]);
        }
    }
}
void DES(vector<int>& vec, int K[], int n) {
    int PC1[56] = {
   57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,
   62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4 };
    int PC2[48] = {
   14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,45,33,48,44,
   49,39,56,34,53,46,42,50,36,29,32 };
    int Kn[16] = { 1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1 };
    int C[28], D[28];
    for (int i = 0; i < 28; i++)
    {
        C[i] = vec[PC1[i] - 1];
        D[i] = vec[PC1[i + 28] - 1];
    }
    for (int i = 0; i < Kn[n]; i++)
    {
        corrIzquierda(C);
        corrDerecha(D);
    }
    int CD[56];
    for (int i = 0; i < 28; i++)
    {
        CD[i] = C[i];
        CD[i + 28] = D[i];
    }
    for (int i = 0; i < 48; i++)
    {
        K[i] = CD[PC2[i] - 1];
    }
}
void corrIzquierda(int V[])
{
    int x = V[0];
    for (int i = 0; i < 28; i++) {
        V[i] = V[i + 1];
    }
    V[27] = x;
}
void corrDerecha(int V[])
{
    int x = V[27];
    for (int i = 27; i > 0; i--)
    {
        V[i] = V[i - 1];
    }
    V[0] = x;
}
void semillas(vector<int>& k)
{
    MEMORYSTATUSEX estado;
    estado.dwLength = sizeof(estado);
    GlobalMemoryStatusEx(&estado);
    SYSTEMTIME tiempo;
    GetSystemTime(&tiempo);
    k.push_back(mod(tiempo.wMilliseconds, 256));
    k.push_back(mod(estado.ullTotalPhys - estado.ullAvailPhys, 256));
    k.push_back(mod(estado.ullAvailPhys, 256));
    k.push_back(mod(estado.ullTotalPageFile - estado.ullAvailPageFile, 256));
    k.push_back(mod(estado.ullAvailPageFile, 256));
}
int mod(long long a, int b)
{
    int m;
    (a < 0 && b > 0) ? (m = (a / b) - 1) : (m = a / b);
    return a - m * b;
}
