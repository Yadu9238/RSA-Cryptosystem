#include"Anirban166.h" //Generic header inclusive of all headers
//iostream, math.h/cmath, string.h/cstring and stdlib.h/cstdlib used here.
using l = long int;
using namespace std;

//Variables:
l p, q, n, t, flag, e[100], d[100], temp[100], j, m[100], en[100], i;
char msg[100];
//Note: Using vectors instead of static arrays is a better choice, which 
//I wasn't aware of initially and will require some changes in the code.
//Syntax? convert e[100] to vector<long int>e(100) and so on.

//Functions:
int prime(l); //prime check
void ce(); //calculate exponent e
l cd(l); //calculate exponent d (return value)
void encrypt(); //encrypt plaintext
void decrypt(); //decrypt ciphertext

int primecheck(l var) // Basic prime check function, can be bool as well.(returns 0/1)
{
	int i,j = sqrt(var);
	for (i = 2; i <= j; ++i)
		if (var % i == 0)
			return 0;
	return 1;
}

void ce() // Calculating public exponent e
{
	int k = 0;
	for (i = 2; i < t; i++)
	{
		if (t % i == 0)
			continue;
		flag = primecheck(i);
		if (flag == 1 && i != p && i != q)
		{
			e[k] = i;
			flag = cd(e[k]);
			if (flag > 0)
			{
				d[k] = flag;
				k++;
			}
			if (k == 99)
				break;
		}
	}
}

	l cd(l x) // Calculating private exponent d
	{
		long int k = 1;
		while (2==2)
		{
			k = k + t;
			if (k % x == 0)
				return (k / x);
		}
	}

	void encrypt() // Encryption function
	{
		l pt, ct, key = e[0], k, len;
		i = 0;
		len = strlen(msg);
		while (i != len)
		{
			pt = m[i];
			pt = pt - 96;
			k = 1;
			for (j = 0; j < key; j++)
			{
				k = k * pt;
				k = k % n;
			}
			temp[i] = k;
			ct = k + 96;
			en[i] = ct;
			i++;
		}
		en[i] = -1;
		cout << "Encrypted Message :\n";
		for (i = 0; en[i] != -1; i++)
			printf("%c", en[i]);
	}
	void decrypt() // Decryption function
	{
		l pt, ct, key = d[0], k;
		i = 0;
		while (en[i] != -1)
		{
			ct = temp[i];
			k = 1;
			for (j = 0; j < key; j++)
			{
				k = k * ct;
				k = k % n;
			}
			pt = k + 96;
			m[i] = pt;
			i++;
		}
		m[i] = -1;
		cout << "Decrypted Message :\n";
		for (i = 0; m[i] != -1; i++)
			printf("%c", m[i]);
	}

	int main()
	{
		cout << "Enter a prime :\n";
		cin >> p;
		flag = primecheck(p);
		if (flag == 0)
		{
			cout << "Wrong input!\n";
			exit(1);
		}
		cout << "Enter another prime :\n";
		cin >> q;
		flag = primecheck(q);
		if (flag == 0 || p == q)
		{
			cout << "Wrong input!\n";
			exit(1);
		}
		cout << "Enter message for encryption :\n";
		fflush(stdin);
		cin >> msg;
		for (i = 0; msg[i] != '\0'; i++)
			m[i] = msg[i];
		n = p * q;
		t = (p - 1) * (q - 1); //Euler's totient. (Pronounced as 'Oiler's Totient')
		ce();
		cout << "Possible values of exponents 'e' and 'd' are :\n";
		for (i = 0; i < j - 1; i++)
			cout << e[i] << "\t" << d[i] << "\n";
		encrypt();
		decrypt();
		return 0;
	}
