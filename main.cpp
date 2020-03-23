#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct TNode{
int nim;
string nama;
TNode *next;
}*head;

void insertBelakang (int nim, string nama);
void tampilList();
void hapusBelakang();
void clearList();




    int main()
    {
        head = NULL;
        int nim;
        string nama;
        char ulang,pilih;

        // masukkan data

        do{
        input:
        cout<<"\tSingle Linked List Non Circular"<<endl<<endl;
        cout<<"Masukkan Nama dan Nim"<<endl;
        cout << "NAMA: ";
        cin >> nama;
        cout << "NIM: ";
        cin >> nim;

        insertBelakang(nim, nama);
        cout << "lagi? (y/n) ";
        cin >> ulang;
        }while(ulang == 'y' || ulang== 'Y');
        // Tampilkan data
        tampilList();

        // Hapus data
        do {
        cout << "\n1. Hapus Data Dari Belakang \n2. Hapus Semua Data \n3. Tampilkan list \n ";
        cout<<"\n masukkan pilihan";
        int pil;
        cin >> pil;
        if (pil == 1){
            	hapusBelakang();
        	}
        else if(pil == 2){
        	    clearList();
        	}
        else if (pil == 3){
            tampilList();
        }
        	else
            cout << "input salah";
            cout<<"Apakah ingin kembali ke menu utama: ";
            cin>>ulang;
        }
            while (ulang =='y');
        getch();
        return 0;
    }


     void insertBelakang(int nim, string nama)
    {
        TNode *baru,*bantu;
        baru = new TNode;
        baru->nim = nim;
        baru->nama = nama;
        baru->next = NULL;
        if(head == NULL)
        {
            head=baru;
            head->next = NULL;
        }
        else
        {
            bantu=head;
            while(bantu->next!=NULL)
            {
                bantu=bantu->next;
            }
            bantu->next = baru;
        }
        cout<<"Data baru telah ditambahkan\n";
    }

    void tampilList()
    {
        TNode *bantu;
        bantu = head;
        if(head != NULL)
        {
            while(bantu!=NULL)
            {
                cout<<bantu->nama<<"\t \t "<<bantu->nim<<endl;
                bantu=bantu->next;
            }
            cout<<endl;
        }
        else
            cout<<"masih kosong\n";
    }


    void hapusBelakang()
    {
        TNode *hapus,*bantu;
        int nim;
        string nama;
        if(head != NULL)
        {
            if(head->next !=NULL)
            {
                bantu = head;
                while(bantu->next->next!=NULL)
                {
                    bantu = bantu->next;
                }
                hapus = bantu->next;
                nim = hapus->nim;
                nama = hapus->nama;
                bantu->next = NULL;
                delete hapus;
            }
            else
            {
                nim = head->nim;
                nama = head->nama;
                head = NULL;
            }
            cout<<nama<<" Terhapus\n";
        }
        else
            cout<<"masih kosong\n";
    }

    void clearList()
    {
        TNode *bantu,*hapus;
        bantu = head;
        while(bantu!=NULL)
        {
            hapus = bantu;;
            bantu = bantu->next;
            delete hapus;
        }
        head = NULL;}
