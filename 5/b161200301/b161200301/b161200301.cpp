/************************************************************
**				   SAKARYA ÜNİVERİSTESİ
**		BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**		  BİLİŞİM SİSTEMLERİ MÜHENDİSLİĞİ BÖLÜMÜ
**		        POGRAMLAMAYA GİRİŞ DERSİ
**			      2017-2018 GÜZ DÖNEMİ
**
**				ÖDEV NUMARASI..........: 5
**				ÖĞRENCİ ADI............: KÜBRA KISMET
**				ÖĞRENCİ NUMARASI.......: B161200301
**              DERSİN ALINDIĞI GRUP...: A
************************************************************/

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
using namespace std;

struct Musteri
{
	string ad;
	string soyad;
	int TC;
	int musteriNo;
};
struct Oda
{
	int odaNo;
	int ücret;
};
int main()
{
	int secim;
	do
	{
		setlocale(LC_ALL, "Turkish");

		Oda oda;
		Musteri musteri;
		fstream ofs;
		ofstream dosyaYazOda("oda.txt", ios::app);
		ofstream bosdosya("bos.txt", ios::app);
		ofstream dosyaYazMusteri("musteri.txt", ios::app);
		ofstream dosyaYazBirlikte("musterikayit.txt", ios::app);
		
		ofstream yenidosyaYazOda("oda1.txt",ios::app);
		ofstream yenidosyaYazMusteri("oda2.txt",ios::app);
		ofstream yenidosyaYazBirlikte("oda3.txt",ios::app);
		
		ifstream dosyaOkuOda("oda.txt", ios::in);
		ifstream dosyaOkuMusteri("musteri.txt", ios::in);
		ifstream dosyaOkuBirlikte("musterikayit.txt", ios::in);

		system("cls");
		cout << "Otel İşlemleri" << endl;
		cout << "-----------------" << endl;
		cout << "1-Oda İşlemleri" << endl;
		cout << "2-Müşteri İşlemleri" << endl;
		cout << "3-Oda Kayıt İşlemleri" << endl;
		cout << "99-Çıkış" << endl;
		cout << "Seçiminiz: " << endl; cin >> secim;		
		
		switch (secim)
		{
	case 1:
			cout << "1-Oda Ekle" << endl;// oda no ve ücreti
			cout << "2-Oda Sil" << endl;
			cout << "3-Odaları Listele" << endl;		
			cout << "4-Üst Menü" << endl;
			cout << "Seçiminiz: " << endl; cin >> secim;
						
			switch (secim)
				{ 
		        case 1:
				cout << "Oda Numarası : "; cin >> oda.odaNo;
				cout << "Ücreti : "; cin >> oda.ücret;
				dosyaYazOda << oda.odaNo << "\r\n";
				dosyaYazOda << oda.ücret << "\r\n";
				
				system("pause");
				break;
				case 2: 
					int silinecek;
					ofs.open("oda1.txt", ofstream::out | ofstream::trunc);//oda1.txt nin içini siliyor.
					cout << "Silinecek Odanın Numarası :"; cin >> silinecek;
					while (dosyaOkuOda>>oda.odaNo>>oda.ücret)
					{			
					   if (oda.odaNo != silinecek)
						{	
							yenidosyaYazOda << oda.odaNo << "\r\n";//\r\n enter alt satıra geciyor.
							yenidosyaYazOda << oda.ücret << "\r\n";
						}
					}
					yenidosyaYazOda.close();
					dosyaOkuOda.close();
					dosyaYazOda.close();
					ofs.close();
					remove("oda.txt");
					rename("oda1.txt","oda.txt");
					system("pause");
					break;
					case 3:
						cout << "ODALARIMIZ VE ÜCRETLERİ "<<endl;
						while(dosyaOkuOda>>oda.odaNo>>oda.ücret)//listeleme işlemi yaparken  en son listelenen elemanı iki kere yazmamasını sağlıyor okuma işlemi bir fonksiyon ve okuma işlemi söyle işleniyor: en son elemanı da ekrana çıkardıktan sonra elinde halen en son ki eleman var
						{							  		   //yani while ın içi true dönüyor ve bir alt satıra geçiyor ama listelenicek bir veri kalmadığı için içi 0bu yüzden de elindeki veriyi bir daha yazıyor					
						cout <<"Oda Numarası :"<< oda.odaNo << endl;
						cout <<"Odanın Ücreti :"<< oda.ücret << endl;
						cout << endl;
						}
						system("pause");
						break;
					case 4: break;//üst menüye dönüş
					default: cout << "Hatalı Seçim" << endl;
					break;
			  	 }
			 break;
		case 2:
				cout << "1-Müşteri Ekle" << endl;// müsteri no TC ad soyad
				cout << "2-Müşteri Sil" << endl;
				cout << "3-Müşterileri Listele" << endl;
				cout << "4-Üst Menü" << endl;
				cout << "Seçiminiz: " << endl; cin >> secim;
				switch (secim)
				{
				case 1:
					cout << "Musteri Numarası : "; cin >> musteri.musteriNo;	
					cout << "Adı : "; cin >> musteri.ad;
					cout << "Soyadı : "; cin >> musteri.soyad;
					cout << "T.C : "; cin >> musteri.TC;
					dosyaYazMusteri << musteri.musteriNo << "\r\n";
					dosyaYazMusteri << musteri.ad << "\r\n";
					dosyaYazMusteri << musteri.soyad << "\r\n";
					dosyaYazMusteri << musteri.TC << "\r\n";
				break;
				case 2:
					int sil;
					ofs.open("oda2.txt", std::ofstream::out | std::ofstream::trunc);//oda2.txt nin içini siliyor.
					cout << "Silinecek Müşterinin Numarası :"; cin >> sil;
					while (dosyaOkuMusteri >> musteri.musteriNo >> musteri.ad >> musteri.soyad >> musteri.TC)
					{
						if (musteri.musteriNo != sil)
						{
							yenidosyaYazMusteri << musteri.musteriNo << "\r\n";
							yenidosyaYazMusteri << musteri.ad << "\r\n";
							yenidosyaYazMusteri << musteri.soyad << "\r\n";
							yenidosyaYazMusteri << musteri.TC << "\r\n";
						}
					}
					yenidosyaYazMusteri.close();
					dosyaOkuMusteri.close();
					dosyaYazMusteri.close();
					ofs.close();
					remove("musteri.txt");
					rename("oda2.txt","musteri.txt");
					system("pause");
					break;

				case 3:
					cout << "MÜŞTERİLERİMİZ"<<endl;
					while (dosyaOkuMusteri>> musteri.musteriNo>> musteri.ad>> musteri.soyad>> musteri.TC)//yukarda açıkladım 2 kere yazmayı önlüyor.
					{
					cout << "Müsterinin Numarası : "<< musteri.musteriNo << endl;
					cout << "Müsterinin Adı : " << musteri.ad << endl;
					cout << "Müsterinin Soyadı : " << musteri.soyad << endl;
					cout << "Müsteri T.C : " << musteri.TC << endl;	
					cout << endl;
					}
					system("pause");
					break;
				case 4: break;//üsrt menüye dönüş
				default: cout << "Hatalı Seçim" << endl;
					break;
				}			
			 break;
		case 3:
				cout << "1-Odaya Müşteri Ekle" << endl;//oda no ile müşteri no
				cout << "2-Odadan Müşteri Sil" << endl;
				cout << "3-Odada ki Müşterileri Listele" << endl;
				cout << "4-Üst Menü" << endl;
				cout << "Seçiminiz: " << endl; cin >> secim;
				switch (secim)
				{
				case 1:
					cout << "Seçmek İstediğiniz Oda :" << endl; cin >> oda.odaNo;
					cout << "Aktarılacak Müşterinin Numarası :" << endl; cin >> musteri.musteriNo;
					dosyaYazBirlikte << oda.odaNo<<endl;
					dosyaYazBirlikte << musteri.musteriNo<<endl;
					break;
				case 2:
					int silme;
					ofs.open("oda3.txt", std::ofstream::out | std::ofstream::trunc);//oda3.txt nin içini siliyor.
					cout << "Oda Numarası ile kayıtlı müsteriyi sil:"; cin >> silme;
					while (dosyaOkuBirlikte>>oda.odaNo>>musteri.musteriNo)
					{
						if (oda.odaNo!=silme)
						{
							yenidosyaYazBirlikte << oda.odaNo << "\r\n";
							yenidosyaYazBirlikte << musteri.musteriNo << "\r\n";
						}
					}
					yenidosyaYazBirlikte.close();
					dosyaOkuBirlikte.close();
					dosyaYazBirlikte.close();
					ofs.close();
					remove("musterikayit.txt");
					rename("oda3.txt","musterikayit.txt");
					system("pause");
					break;
				case 3:
					cout << "ODALARA KAYITLI OLAN MÜŞTERİLERİMİZ" <<endl;
					while (dosyaOkuBirlikte>> oda.odaNo>> musteri.musteriNo)
					{
						cout << "Odanın Numarası :" << oda.odaNo << "    " << "Müşterinin Numarasi :" <<musteri.musteriNo <<endl;
					}
					system("pause");
					break;
				case 4: break;//üst menüye dönüş
				default: cout << "Hatalı Seçim" << endl;
					break;
				}					
		  	 break;
		case 99: break;//çıkış
		
			default:
			cout << "Hatalı Seçim" << endl;
			system("pause");	
			break;
		}
	}
while (secim != 99);	
_getch();

 return 0;  
} 

//system("del dosya.txt");