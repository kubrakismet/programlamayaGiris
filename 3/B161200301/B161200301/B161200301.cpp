/****************************************************************************
**							      SAKARYA ÜNİVERSİTESİ
**					    BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**						 BİLİŞİM SİSTEMLERİ MÜHENDİSLİĞİ BÖLÜMÜ
**						    	 PROGRAMLAMAYA GİRİŞ DERSİ
**							       2017-2018 GÜZ DÖNEMİ
**
**							ÖDEV NUMARASI..........: 3
**							ÖĞRENCİ ADI............: Mustafa ACAR - Kübra KISMET
**							ÖĞRENCİ NUMARASI.......: B161200304 - B161200301
**                          DERSİN ALINDIĞI GRUP...: A
****************************************************************************/

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");
	while (true)
	{
		char kelime[100];
		char istenenharf[100];
		int uzunluk = 0;
		int adet = 0;
		int bayrak = 0;
		
		system("CLS");
		
		cout << "..:: String İşlemleri ::.." << endl;
		cout << "İşlem Yapılacak Stringi giriniz: ";
		cin >> kelime;
		cout << "İstenen Harf: ";
		cin >> istenenharf;
		
		//Aranan harf uzunluğunu bulur.
		for (; istenenharf[uzunluk] != '\0';) uzunluk++;
		//Aranan harf girişi birden fazla harf içeriyor mu cevabını bulur.
		if (uzunluk == 1)
		{
			uzunluk = 0;
			//Girilen kelimenin uzunluğunu bulur.
			for (; kelime[uzunluk] != '\0';) uzunluk++;
			//Aranan harfin girilen kelime içerisinde kaç adet olduğunu bulur.
			//Eğer 2 adet bulunursa döngüden çıkar. İşlemlere devam eder.
			for (int i = 0; i < uzunluk; i++)
			{
				if (istenenharf[0] == kelime[i])
				{
					adet++;
					if (adet >= 2) break;
				}
			}
			
			if (adet < 2) cout << "Cümle içerisinde aranan harf bulunamamıştır." << endl;
			else
			{
				int j = 1;
				for (int i = 0; i < uzunluk; i++)
				{
					//Aranan harf arasındaki kelimeyi bulur.
					if (kelime[i] == istenenharf[0])
					{
						bayrak += 1;
						if (bayrak == 2)
						{
							cout << endl; break;
						}
					}
					if (bayrak == 1)
					{
						cout << kelime[j];
						j++;
					}
				}
			}
		}
		
		else cout << "Birden fazla harf girişi yaptınız." << endl;
		cout << "Devam etmek için bir tuşa basınız.";
		_getche();
	}
	return 0;
}