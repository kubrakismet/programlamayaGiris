/************************************************************
**				   SAKARYA ÜNİVERİSTESİ                   
**		BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ        
**		 BİLİŞİM SİSTEMLERİ MÜHENDİSLİĞİ BÖLÜMÜ          
**		       POGRAMLAMAYA GİRİŞ DERSİ                   
**			     2017-2018 GÜZ DÖNEMİ                     
**                                                       
**				ÖDEV NUMARASI.........: 2                
**				ÖĞRENCİ ADI...........: KÜBRA KISMET     
**				ÖĞRENCİ NUMARASI......: B161200301       
**                                                       
************************************************************/

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include<conio.h>
using namespace std;

int main()
{
	while (true)
	{
		setlocale(LC_ALL, "Turkish");
		cout << "..::Matris İşlemleri::.." << endl;

		int satir, i, j;
		cout << "Matris satır sayısını giriniz (1-10 arasında) : "; cin >> satir;
		int matris[10][10];
		    //matrisin satır değerini öğrendikten sonra 1,1 den son değerine kadar kullanıcının değer atamasını sağlıyoruz.
		for (i = 1; i <= satir; ++i)
		{
			for (j = 1; j <= satir; ++j)
			{
				cout << "[" << i << "][" << j << "]: "; cin >> matris[i][j];
			}
		}
		    //matrisi ekrana yazdırıyor.
		for (int i = 1; i <= satir; i++)
		{
			for (int j = 1; j <= satir; j++)
				cout << setw(5) << matris[i][j] << "  ";
			cout << endl;
		}

		int secim;
		cout << "1-Satır En Büyük: " << endl << "2-Satır Toplam: " << endl << "Seçiminiz: ";
		cin >> secim;
		cout << "Sonuc: ";
		int buyukSayi;
		switch (secim)
		{
		 	 //1.secenek secilmesiyle çalışan kısım olan en büyüğü bulma işlemi için iç içe for kullanmanın yanı sıra if koşul döngüsü ile satırda ki sayıların büyük olanını bulup ekrana yazdırıyoruz.
		case 1:  buyukSayi= matris[0][0];
			for (int i = 1; i <= satir; i++)
			{
				for (int j = 1; j <= satir; j++)
				{
					if (matris[i][j] > buyukSayi)
					{
						 buyukSayi = matris[i][j];
					}
				}
				cout << buyukSayi << "   ";
				buyukSayi = matris[i][0];
			} break;
		  	 //2. secenek secilmesiyle çalışan kısım olan toplama işlemi için iç içe for kullanıyoruz.
		case 2: for (int i = 1; i <= satir; i++)
		{
			int toplam = 0;
			for (int j = 1; j <= satir; j++)
			{
				toplam += matris[i][j];
			}
			cout << toplam << "   ";
		} break;
		default: cout << "Hatalı Seçim"; break;
		}
		system("pause");
		system("cls");		
	}  _getch();
}