/****************************************************************************
**
**				ÖĞRENCİ ADI.................: Deniz Berfin TAŞTAN
**				ÖĞRENCİ NUMARASI............: B181210010
**				DERS GRUBU..................: 1-D
****************************************************************************/

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

const int MAX_BOYUT = 25;
void Menu(int, int[][25]);
void Yazdir(int, int[][25]);
void SutunSatirDegistir(int, int[][25]);
void TeklerBasa(int, int[][25]);
void SutunTers(int, int[][25]);
void Toplam(int, int[][25]);

int main()
{
	int boyut = 0;
	srand(time(NULL));

	do
	{
		cout << "Matris boyutu 5-25 araliginda olmalidir." << endl << endl;
		cout << "Boyut giriniz : ";
		cin >> boyut;
	} while (boyut < 5 || boyut > 25);

	int matris[MAX_BOYUT][MAX_BOYUT]; //Max boyut tanimlaniyor ve max boyutta matris olusturuluyor.

	for (int i = 0; i < boyut; i++)
	{
		for (int j = 0; j < boyut; j++)
		{
			matris[i][j] = rand() % 9 + 1;   //Her matris elemanina 1-9 arasi random deger ataniyor.
		}
	}
	Yazdir(boyut, matris);
	Menu(boyut, matris);

	return 0;
}


void Menu(int boyut, int matris[][25])     //Seceneklerin gosterildigi ve secim yapilan Menu fonksiyonu.
{
	cout << "1-Sutun-Satir Degistir" << endl;
	cout << "2-Tekleri Basa Al(Satir)" << endl;
	cout << "3-Ters Cevir(Sutun)" << endl;
	cout << "4-Toplamlari Yazdir" << endl;

	int secim = 0;
	do {
		cin >> secim;
	} while (secim < 1 || secim > 4);
	switch (secim)
	{
	case 1:
		SutunSatirDegistir(boyut, matris);
		Yazdir(boyut, matris);
		break;
	case 2:
		TeklerBasa(boyut, matris);
		Yazdir(boyut, matris);
		break;
	case 3:
		SutunTers(boyut, matris);
		Yazdir(boyut, matris);
		break;
	case 4:
		Toplam(boyut, matris);
		Yazdir(boyut, matris);
		break;
	default:
		break;
	}
}

void Yazdir(int boyut, int matris[][25])
{
	int sira = boyut / boyut; //Sira numaralari icin 1'den 25'e kadar artabilen degisken.
	cout << setw(7);          //Sira numaralari icin bosluk.
	for (int i = 0; i < boyut; i++)
	{
		cout << sira << setw(4); // Siralarin arasinda bosluk ve siralarin yazdirilmasi.
		sira++;
	}
	cout << endl << endl;

	cout << setw(9);      // Sira numaralarinin altindaki cizgilerin solundaki bosluk.

	for (int j = 0; j < boyut; j++)
	{
		cout << "____"; //Cizgiler.
	}
	cout << endl << endl;

	sira = boyut / boyut;  //Sira tekrar 1'e getiriliyor.
	for (int i = 0; i < boyut; i++)
	{
		cout << setw(2) << right << sira << setw(2) << "|"; //Satirlarin sira numaralarinin ve satirin yazdirilmasi.
		sira++;
		for (int j = 0; j < boyut; j++)
		{
			cout << setw(4) << matris[i][j];
		}
		cout << endl << endl;
	}
}

void SutunSatirDegistir(int boyut, int matris[][25])
{
	int sutun = 0, satir = 0;  //Istenen satir ve sutun degiskenleri.
	do
	{
		if (satir > boyut || sutun > boyut)
		{
			cout << "Hatali giris ! Lutfen tekrar giriniz : " << endl;
		}
		cout << " Satir : "; cin >> satir;
		cout << " Sutun : "; cin >> sutun;
	} while (satir < 1 || satir>boyut || sutun < 1 || sutun>boyut);  //Sartlar saglanmazsa tekrarlayan girdi dongusu.

	int _satir[MAX_BOYUT];
	int _sutun[MAX_BOYUT];

	for (int i = 0; i < boyut; i++)
	{
		for (int j = 0; j < boyut; j++)
		{
			if (i == satir - 1)
			{
				_satir[j] = matris[i][j];  //Belirtilen satir ve sutun yeni dizilere atiliyor.
			}
			if (j == sutun - 1)
			{
				_sutun[i] = matris[i][j];
			}
		}
	}

	for (int i = 0; i < boyut; i++)
	{
		for (int j = 0; j < boyut; j++)
		{
			if (i == satir - 1)
			{
				matris[i][j] = _sutun[j];  //Yeni dizilerdeki satir matristeki sutunun yerine , sutun ise satirin yerine yaziliyor.
			}
			if (j == sutun - 1)
			{
				matris[i][j] = _satir[i];
			}
		}
	}

	matris[satir - 1][sutun - 1] = _satir[satir - 1] + _sutun[sutun - 1];  //Kesisimler toplaniyor.

}

void TeklerBasa(int boyut, int matris[][25])
{
	int satir = 0;
	cout << "Satir No : ";
	cin >> satir;  //Satir aliniyor.

	if (satir > 4 && satir < boyut + 1)
	{
		int _satir[MAX_BOYUT];    //Satir icin dizi olusturuluyor.

		for (int i = 0; i < boyut; i++)
		{
			for (int j = 0; j < boyut; j++)
			{
				if (i == (satir - 1))
				{
					_satir[j] = matris[i][j];   //Belirtilen satir yeni diziye atiliyor.
				}
			}
		}

		int tekSayisi = 0;
		for (int i = 0; i < boyut; i++)  //Dizi taranip tek sayilar dizinin basina atiliyor.Dizi basindakiler tek sayilarin
		{                                //eski yerlerine atiliyor.
			if (_satir[i] % 2 == 1)
			{
				int temp = _satir[i];
				_satir[i] = _satir[tekSayisi];
				_satir[tekSayisi] = temp;
				tekSayisi++;
			}
		}

		for (int i = 0; i < boyut; i++)
		{
			for (int j = 0; j < boyut; j++)
			{
				if (i == satir - 1)
				{
					matris[i][j] = _satir[j];  //Dizi tekrar matrise atiliyor.
				}
			}
		}
	}
	else
	{
		cout << "HATALI GIRIS !!" << endl;
		Yazdir(boyut, matris);
		Menu(boyut, matris);
	}
}

void SutunTers(int boyut, int matris[][25])
{
	int sutun = 0;
	int _sutun[MAX_BOYUT];
	do
	{
		if (sutun > boyut)
		{
			cout << "Hatali Giris ! Lutfen tekrar giriniz : " << endl;
		}
		cout << "Sutun giriniz : ";   //Sutun aliniyor.
		cin >> sutun;
	} while (sutun <1 || sutun>boyut);

	for (int i = 0; i < boyut; i++)
	{
		for (int j = 0; j < boyut; j++)
		{
			if (j == sutun - 1)
			{
				_sutun[i] = matris[i][j]; //Belirtilen sutun diziye atiliyor.
			}
		}
	}

	for (int i = 0; i < boyut; i++)
	{
		for (int j = 0; j < boyut; j++)
		{
			if (j == sutun - 1)
			{
				matris[i][j] = _sutun[boyut - 1 - i];   //Dizi ters cevrilip matrise atiliyor.
			}
		}
	}
}

void Toplam(int boyut, int matris[][25])
{
	int toplam = 0;

	for (int i = 0; i < boyut; i++)
	{
		for (int j = 0; j < boyut; j++)
		{
			toplam += matris[i][j];  //Matrisin her elemani toplam degiskenine ekleniyor.
		}
	}
	cout << "Toplam Deger : " << toplam << endl << endl;

	for (int i = 0; i < boyut; i++)
	{
		for (int j = 0; j < boyut; j++)
		{
			matris[i][j] = toplam - matris[i][j];   //Her elemanin yerine degeri toplamdan cikartilarak yazdiriliyor.
			toplam = matris[i][j];  //Her adimda yazilan eleman toplam degerine ataniyor.
		}
	}

}