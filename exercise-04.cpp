/*
Author    		: SURIADI VAJRAKARUNA
NPM		        : 140810180038
Deskripsi	    : strukdat-04 (exercise)
Tahun           : 2019
*/

#include <iostream>
#include<string>
#include<iomanip>
using namespace std;

struct pegawai
{
    char nama[50];
    string bidang;
    int gaji;
    pegawai* next;
};
typedef pegawai* pointer;
typedef pointer List;

void createList(List& First)
{
    First = NULL;
}

void createElmt (pointer& pBaru)
{
    pBaru = new pegawai;
    cout<<"Nama     	: "; cin.ignore();cin.getline(pBaru->nama,30);
    cout<<"Bidang		: "; cin>>pBaru->bidang;
    cout<<"Gaji     	: "; cin>>pBaru->gaji;
    pBaru->next=NULL;
}

void insertFirst (List& First, pointer pBaru)
{
    if(First==NULL) First=pBaru;
    else
	{
        pBaru->next=First;
        First=pBaru;
    }
}

void insertLast (List& First, pointer pBaru)
{
    pointer Last;
    if (First==NULL) First=pBaru;
    else 
	{
        Last=First;
        while (Last->next!=NULL)
		{
            Last=Last->next;
        }
        Last->next=pBaru;
    }
}

void traversal (List First)
{
    pointer pBantu;
    pBantu=First;
    int i=1;
    cout<<"No\tNama\t\t\t\t\t\tBidang\t\t\tGaji\t\t\t"<<endl;
    while(pBantu != NULL)
	{
		cout<<i<<"\t"<<pBantu->nama<<"\t\t\t\t\t"<<pBantu->bidang<<"\t\t\t"<<pBantu->gaji<<endl;
        pBantu=pBantu->next;
        i++;
    }
}

void deleteFirst(List& First, pointer& pHapus)
{
    if(First==NULL)
	{
        pHapus=NULL;
        cout<<"List kosong!"<<endl;
    }
    else if(First->next==NULL){
        pHapus=First;
        First=NULL;
    }
    else
	{
        pHapus=First;
        First=First->next;
        pHapus->next=NULL;
    }
}

void deleteLast (List& First, pointer& pHapus)
{
    pointer Last, precLast;
    if (First==NULL)
	{
        pHapus=NULL;
        cout<<"List kosong!"<<endl;
    }
    else if(First->next==NULL)
	{
        pHapus=First;
        First=NULL;
    }
    else 
	{
        Last=First;
        precLast=NULL;
        while (Last->next!=NULL)
		{
            precLast=Last;
            Last=Last->next;
        }
        pHapus=Last;
        precLast->next=NULL;
    }
}

int main()
{
    pointer pBaru;
    List first;
	char pil,pil1;
	
	createList(first);
	do {
	cout << "Pilih aksi yang ingin dijalankan: \n1. Insert First \n2. Insert Last \n3. Delete First \n4. Delete Last \n5. Traversal \nPilihan [1/2/3/4/5]: ";
	cin >> pil;
	switch(pil)
		{
			case '1': createElmt(pBaru); 
					  insertLast(first, pBaru); 
					  break;
			case '2': createElmt(pBaru);
            		  insertLast(first, pBaru);
        			  break;
			case '3': deleteFirst(first, pBaru); break;
			case '4': deleteLast(first, pBaru); break;
			case '5': traversal(first); break;
			default: cout << "Pilihan anda tidak ada. "; break;
		}
	cout << "Apakah anda masih mau menyunting data? [Y/N] "; cin >> pil1;
	} while (pil1=='Y' || pil1 == 'y');
	cout << "Hasil Akhir Data: " << endl;
	traversal(first);
}
