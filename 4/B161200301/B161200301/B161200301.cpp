/*********************************************************************************
**							      SAKARYA ÜNİVERSİTESİ
**					    BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**						 BİLİŞİM SİSTEMLERİ MÜHENDİSLİĞİ BÖLÜMÜ
**							    PROGRAMLAMAYA GİRİŞ DERSİ
**							       2017-2018 GÜZ DÖNEMİ
** 
**							ÖDEV NUMARASI..........: 4
**							ÖĞRENCİ ADI............: Kübra KISMET
**							ÖĞRENCİ NUMARASI.......: B161200301
**                          DERSİN ALINDIĞI GRUP...: A
**********************************************************************************/

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

struct Metin
{
		char kelime[100];
		char araters[100];
		char istenenharf[100];
		int uzunluk = 0;
		int adet = 0;
		int bayrak = 0;				
};

int main()
{
	setlocale(LC_ALL, "Turkish");	
		
	while (true)
	{
		Metin metin;
		int secim;

		system("cls");
		
		cout << "..:: String İşlemleri ::.." << endl;
		cout << "İşlem Yapılacak Stringi giriniz: ";  
		cin >> metin.kelime;
		cout << "İstenen Harf: "; 
		cin >> metin.istenenharf;
		
		//Aranan harf uzunluğunu bulur.
		for (; metin.istenenharf[metin.uzunluk] != '\0';) metin.uzunluk++;
		//Aranan harf girişi birden fazla harf içeriyor mu cevabını bulur.
		if (metin.uzunluk == 1)
		{
			metin.uzunluk = 0;
			//Girilen kelimenin uzunluğu bulunur.
			for (; metin.kelime[metin.uzunluk] != '\0';) metin.uzunluk++;
			//Aranan harf cümle içerisinde var mı? Varsa kaç adet cevabını bulur.
			//Eğer 2 adet bulunursa döngüyü durdurur. İşleme devam eder.
			for (int i = 0; i < metin.uzunluk; i++)
			{
				if (metin.istenenharf[0] == metin.kelime[i])
				{
					metin.adet++;
					if (metin.adet >= 2) break;
				}
			}
			
			if (metin.adet < 2)
				cout << "Cümle içerisinde aranan harf bulunamamıştır." << endl;
			else
			{
				cout << "1-Ara Metni Tersten Yaz" << endl;
				cout << "2-Ara Metni Tekrarlı Yaz" << endl;
				cout << "Seçiminiz: ";
				cin >> secim;

				switch (secim)
				{
				case 1:	metin.adet = 0;
					//Aranan harf arasındaki kelimeyi tersine çevirerek araters dizisine aktarır.
					for (int i = 0; i < metin.uzunluk; i++)
					{
						if (metin.kelime[i] == metin.istenenharf[0])
						{
							metin.bayrak += 1;
							if (metin.bayrak == 2)
							{
								metin.adet++;
								metin.araters[metin.uzunluk - i] = metin.kelime[i];
								for (i = metin.uzunluk - metin.adet +2 ; i+1  <= metin.uzunluk; i++)
								{
									cout << metin.araters[i];
								}
								cout << endl;
								break;
							}
						}
						if (metin.bayrak == 1)
						{
							metin.araters[metin.uzunluk - i] = metin.kelime[i];
							metin.adet++;
						}
					}break;			

				case 2: //Aranan harf aralığındaki kelimeyi bulur ve 5 kez ekrana yazdırır.
					for (int i = 0; i < 5; i++)
					{
						for (int j = 0; j <= metin.uzunluk; j++)
						{
							if (metin.kelime[j] == metin.istenenharf[0])
							{
								metin.bayrak += 1;
								if (metin.bayrak == 2)
								{
									cout << metin.kelime[j+1] << endl;
								}
							}
							else if (metin.bayrak == 1)
							{
								cout << metin.kelime[j];
							}
						}
						metin.bayrak = 0;
					}break;

				default: cout << "Hatalı Seçim Yaptınız." << endl; break;
				}
			}
		}	  
		else 
		cout << "Birden fazla harf girişi yaptınız." << endl;
		cout << "Devam etmek için bir tuşa basınız." << endl;
	 	_getche();
	}
	return 0;
}