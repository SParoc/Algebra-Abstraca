#include "RSA.h"

RSA::RSA(int bits)
{
	//generarClaves(bits);
	p = conv<ZZ>("133703200583468512661940432437566863407787679375191198021182394001727112515491681580670006353031754813630530689356804621156798873462922538358236701009654144656966779773923959709451115013507018986171378937418182904382379083300515595682496495062355576643841282263973977977761696170072730204255345839194356614647");
	q = conv<ZZ>("145284907096566282745132629119492245185339711065838105121594330695204255464564972532294702624503672406228791984129568541540637277547535437880139594520787926744827603775216037392640919351334859456360301321341826189189183897100688287287323740452550075006053031118540399294413977033015231371603286739991413533961");

	N = p * q;
	phiN = (p - 1) * (q - 1);
	e = ZZ(11);
	d = conv<ZZ>("17659142795711626973627945882287198115587366265970447151302434056579678231539289846243675768051303866212979348103488621200963426641856118892911983751066087504471910443142436011204337331679958010834089980139213422867191264559091079061280593984520819752287005122376242585049866801128382271263605439107193319377905242236937866204218879261485369042697865307232104186782220771907888296940845973068089093593393172448536320000389450407251894083535798811233556654575865095088989005321922469538395299308082823737446864266885236741542806514260819508207338414523398579560535086503024146597059244266530997796839954553357049434691");
	/*do
	{
		e = randomRC4(bits);
	} while (mcd(e, phiN) != 1);
	d = inversa(e, phiN);*/
}

RSA::RSA(ZZ _e, ZZ _N)
{
	e = _e;
	N = _N;
}

string RSA::cifrar(string mensaje)
{
	string mensajeCifrado, mensajeAux;
	int digitosN = ZZaString(N).length();

	for (int i = 0; i < mensaje.length(); i++)
	{
		//Funcion                  convierte a string la letra	    digitos de la posicion de la letra				digitos del alfabeto
		mensajeAux += insertCeros(to_string(abc.find(mensaje[i])), to_string(abc.find(mensaje[i])).length(), to_string(abc.length()).length());
	}
	//Añade la letra menos significativa para completar bloques "W"
	if (mod(conv<ZZ>(mensajeAux.length()), conv<ZZ>(digitosN - 1)) != 0)
	{
		mensajeAux.append("22");
		if (mod(conv<ZZ>(mensajeAux.length()), conv<ZZ>(digitosN - 1)) == 1)
		{
			mensajeAux.pop_back();
		}
	}

	for (int i = 0; i < mensajeAux.length(); i += digitosN - 1)
	{
		//Convierte a ZZ el substring
		ZZ bloquecito(INIT_VAL, mensajeAux.substr(i, digitosN - 1).c_str());
		//Convierte a string la exponenciacion modular para luego agregarle ceros
		string result = ZZaString(expMod(bloquecito, e, N));
		mensajeCifrado += insertCeros(result, result.length(), digitosN);
	}
	return mensajeCifrado;
}

string RSA::descifrar(string mensajeCifrado)
{
	string mensaje, mensajeAux;
	int digitosN = ZZaString(N).length();

	for (int i = 0; i < mensajeCifrado.length(); i += digitosN) 
	{
		ZZ bloquecito(INIT_VAL, mensajeCifrado.substr(i, digitosN).c_str());
		string result = ZZaString(expMod(bloquecito, d, N));
		mensajeAux += insertCeros(result, result.length(), digitosN - 1);
	}

	for (int i = 0; i < mensajeAux.length(); i += to_string(abc.length()).length()) 
	{
		mensaje += abc[stoi(mensajeAux.substr(i,2))];
	}
	return mensaje;
}

string RSA::firmar(string mensaje)
{
	return string();
}

void RSA::generarClaves(int bits)
{

	p = randomRC4(bits);
	q = randomRC4(bits);

	while (!Fermat(p))
	{
		p += 2;
	}

	while (!Fermat(q))
	{
		q += 2;
	}

}




