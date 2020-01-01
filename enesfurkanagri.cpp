#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

int main() // odevde sadece dosyadan aldigim girdiyi bir ogrenci dizisine aktarip ilk indisinde numarasi, diger indislerde de cevaplari olacak sekilde yeni bir dosyaya yazdirabildim.
{
	ifstream girdi("input.txt");
	int i=0,j=0,soruSayisi=0,sayac=0; 
	string satir[101],ogrenci[100][12],gecici,gecicicevap[10];
	getline(girdi, gecici); // ilk satirdaki soru sayisini aliyor
	stringstream cevir(gecici); 
	cevir >> soruSayisi;	// stringi interegera ceviriyor
	string cevapAnahtari[soruSayisi];
	
	while(getline(girdi, satir[i])) // tum satirlari okuyup diziye aktariyor
	{
		i++;
	}
	girdi.close();
	for(i=0; i<satir[0].length(); i++) // 2. satiri okuyup cevap anahtari dizisini dolduruyor
	{
		if(satir[0][i] != ',')
		{
			cevapAnahtari[sayac]=satir[0][i];
			sayac++;
		}
	}
	
	sayac=0;
	for(i=1; i<5; i++) // 3. satiri okuyup ogrenci numaralarini ogrenci dizisinin 0. indisine aktariyor
	{
		ogrenci[i-1][0]=satir[i].substr(0,9); // ogrenci numaralari 9 haneli oldugu icin bu sekilde kopyaladim 
	}
	
							
	gecici=satir[1].substr(9);	// 1. ogrencinin cevaplarini geciciye aktariyor
	
	for(i=0; i<gecici.length(); i++) // 1. ogrencinin cevaplarini gecicicevap[] dizisine bos biraktigi sorular gorunecek sekilde aktariyor
	{
		if(gecici[i] != ',' && sayac <= 10)
		{
			gecicicevap[sayac]=gecici[i];
			sayac++;
		}
		if(gecici[i]==',' && gecici[i+1]==',')
		{
			gecicicevap[sayac]=" ";
			sayac++;
		}
	}
	
	for(i=0; i<10; i++)		// cevabin son halini ogrenci[] dizisine aktariyor
	{
		ogrenci[0][i+1]=gecicicevap[i];
	}
	
	
	sayac=0;
	gecici=satir[2].substr(9);	// 2. ogrencinin cevaplarini geciciye aktariyor		
	
	for(i=0; i<gecici.length(); i++) // 2. ogrencinin cevaplarini gecicicevap[] dizisine bos biraktigi sorular gorunecek sekilde aktariyor
	{
		if(gecici[i] != ',' && sayac <= 10)
		{
			gecicicevap[sayac]=gecici[i];
			sayac++;
		}
		if(gecici[i]==',' && gecici[i+1]==',')
		{
			gecicicevap[sayac]=" ";
			sayac++;
		}
	}
	
	for(i=0; i<10; i++)		// cevabin son halini ogrenci[] dizisine aktariyor
	{
		ogrenci[1][i+1]=gecicicevap[i];
	}
	
	
	sayac=0;
	gecici=satir[3].substr(9);	// 3. ogrencinin cevaplarini geciciye aktariyor		
	
	for(i=0; i<gecici.length(); i++) // 3. ogrencinin cevaplarini gecicicevap[] dizisine bos biraktigi sorular gorunecek sekilde aktariyor
	{
		if(gecici[i] != ',' && sayac <= 10)
		{
			gecicicevap[sayac]=gecici[i];
			sayac++;
		}
		if(gecici[i]==',' && gecici[i+1]==',')
		{
			gecicicevap[sayac]=" ";
			sayac++;
		}
	}
	
	for(i=0; i<10; i++)		// cevabin son halini ogrenci[] dizisine aktariyor
	{
		ogrenci[2][i+1]=gecicicevap[i];
	}
	
	sayac=0;
	gecici=satir[4].substr(9);	// 4. ogrencinin cevaplarini geciciye aktariyor		
	
	for(i=0; i<gecici.length(); i++) // 4. ogrencinin cevaplarini gecicicevap[] dizisine bos biraktigi sorular gorunecek sekilde aktariyor
	{
		if(gecici[i] != ',' && sayac <= 10)
		{
			gecicicevap[sayac]=gecici[i];
			sayac++;
		}
		if(gecici[i]==',' && gecici[i+1]==',' || gecici[i+1]=='\0')
		{
			gecicicevap[sayac]=" ";
			sayac++;
		}
	}
	
	for(i=0; i<10; i++)		// cevabin son halini ogrenci[] dizisine aktariyor
	{
		ogrenci[3][i+1]=gecicicevap[i];
	}
	
	ofstream dyaz;
	dyaz.open("output.txt");

	for(i=0;i<4;i++)		// ogrenci dizisini dosyaya yaziyor
	{
		for(j=0;j<12;j++)
		{
			dyaz << ogrenci[i][j];
		}
		dyaz << endl;
	}
	dyaz.close();
	cout << "output.txt'ye yazildi..";
	return 0;
}
