#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string>

using namespace std;

struct simpul{
	string nama;
	int data;
	simpul *right;
	simpul *down;
};
simpul *kiriatas;

bool isEmpty()
{
	return kiriatas == NULL;
}

void garis()
{
	cout<<"--------------------------------------------"<<endl;
}

void header()
{
	cout<<"--------------------------------------------"<<endl;
	cout<<"                                      [*]"<<endl;
}

void menu()
{
	cout<<"Program Algoritma dan Struktur Data        "<<endl;
	garis();
	cout<<"Dibuat oleh Eureka Labdawara!              "<<endl;
	garis();
	cout<<"Pilih dari Menu dibawah ini!               "<<endl;
	garis();
	cout<<" a. Input Data Nilai                       "<<endl;
	cout<<" b. Output Data Nilai                       "<<endl;
	cout<<" c. Hitung Rata                            "<<endl;
	cout<<" x. Press 'x' for Exit                     "<<endl;
}

void submenu1()
{
	header();
	garis();
	cout<<" 1. Input Nilai Ulangan Baru"<<endl;
	cout<<" 2. Hapus Data"<<endl;
	garis();
}

void insertnilai(string na, int da)
{
	simpul *t = new simpul;
	t->nama = na;
	t->data = da;
	t->down = NULL;
	t->right = NULL;
	ulang:
	if(isEmpty())
	kiriatas = t;
	else
	{
		simpul *curr;
		curr = kiriatas;
		while(curr->nama != na)
		{
		if (curr->down)
		curr= curr->down;
		else
		curr->down = t; 
		}
		while(curr->right != NULL)
		{
		curr= curr->right; 
		}
		curr->right  = t; 
	}
	cout<<"Data berhasil dimasukkan"<<endl;
}

void tampil(simpul *p)
{
	simpul *bantu;
	if (p!=NULL)
	{
		disini:
		bantu = p;
		cout<<p->nama<<"  ";
		mylabel:
		cout<<p->data<<"  ";
		if (p->right != NULL)
		{
		p = p->right;
		goto mylabel;
		}
		else
		{
		cout<<endl;
		if (bantu->down !=NULL)
		{
		p = bantu->down;
		goto disini;
		}
		else{return;}
		}
		
	}
	else
	{
			cout<<"Data Masih belum ada.."<<endl;
			return;
	}
}

void print()
{
	tampil(kiriatas);
}

void rata(simpul *p)
{
	int stor, bagi, hasil;
	bagi =1;
	if (p!=NULL)
	{
		cout<<p->nama<<"  ";
		mylabel:
		stor=stor + p->data ;
		if (p->right)
		{
		p = p->right;
		bagi++;
		goto mylabel;
		}
		hasil = stor / bagi;
		cout<<endl;
		if (p->down)
		tampil(p->down);
	}
	else
	{
			cout<<"Data Masih belum ada.."<<endl;
			return;
	}
}

void printrata()
{
	rata(kiriatas);
}
int main()
{
	string q;
	char pil , yesno;
	int pilsub, r;
	yesno = 'x';
	while (yesno == 'x' or yesno =='X')
	{
		system("cls");
		header();
		garis();
		menu();
		garis();
		cout<<"Masukan Pilihan!"<<endl;
		cin>>pil;
		switch (pil)
		{
			default :
				cout<<"Inputan anda salah!"<<endl;
				getch();
			break;
			
			case 'a':
				system ("cls");
				submenu1();
				cout<<"Masukan Pilihan!"<<endl;
				cin>>pilsub;
				switch (pilsub)
					{
					case 1:
					cout<<"Masukan Nama Mata Pelajaran yang ditambahkan nilai!"<<endl;
					cin>>q;
					cout<<"Masukan Nilai Mata Pelajaran!"<<endl;
					cin>>r;
					insertnilai(q,r);
					getch();
					break;
					}
			break;
			
			case 'b':
			cout<<"Data :"<<endl;
			print();
			getch();
			break;
			
			case 'c':
			cout<<"Rata-rata: "<<endl;
			printrata();
			getch();
			break;
		
			case 'x':
			cout<<"Yakin? [Y/N]"<<endl;
			cin>>yesno;
			if (yesno =='Y' or yesno =='y')
			{
				exit(0);
			}
			else
			{
				yesno = 'x';
			}
			break;
		}
	}	
}
