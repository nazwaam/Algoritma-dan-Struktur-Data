#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>

using namespace std;

int random(int bil)
{
    int jumlah = rand() % bil;
    return jumlah;
}

void randomize()
{
    srand(time(NULL));
}

void clrscr()
{
    system("cls");
}

void Sequential()
{
    clrscr();
    int data[100];
    int cari = 20;
    int counter = 0;
    int flag = 0;
    int save;
    randomize();
    printf("generating 100 number . . .\n");
    for(int i = 0; i < 100; i++)
    {
        data[i] = random(100) + 1;
        printf("%d ", data[i]);
    }
    printf("\n done. \n");

    for(int i = 0; i < 100; i++)
    {
        if(data[i] == cari)
        {
            counter++;
            flag = 1;
            save = i;
        }
    }

    if (flag == 1)
    {
        printf("Data ada, sebanyak %d! \n", counter);
        printf("pada indeks ke=%d", save);
    }
    else
    {
        printf("Data tidak ada! \n");
    }
}

void binary()
{
    int n, kiri, kanan, tengah, temp, key;
    bool ketemu = false;

    cout << "Masukkan jumlah data? ";
    cin >> n;
    int *angka = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Angka ke - [" << i << "] : ";
        cin >> angka[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (angka[j] > angka[j + 1])
            {
                temp = angka[j];
                angka[j] = angka[j + 1];
                angka[j + 1] = temp;
            }
        }
    }
    cout << "=========================================================================\n";
    cout << "Data yang telah diurutkan adalah : \n";
    for (int i = 0; i < n; i++)
    {
        cout << angka[i] << " ";
    }
    cout << "\n=========================================================================\n";
    cout << "Masukkan angka yang dicari : ";
    cin >> key;

    kiri = 0;
    kanan = n - 1;
    while (kiri <= kanan)
    {
        tengah = (kiri + kanan) / 2;
        if (key == angka[tengah])
        {
            ketemu = true;
            break;
        }
        else if (key < angka[tengah])
        {
            kanan = tengah - 1;
        }
        else
        {
            kiri = tengah + 1;
        }
    }

    if (ketemu == true)
    {
        cout << "Angka ditemukan pada indeks : " << tengah << "!\n";
    }
    else
    {
        cout << "Angka tidak ditemukan!";
    }

    delete[] angka;
}

void tiga()
{
    cout << "\nSequential Searching (pencarian berurutan)\n";
    cout << "Pengertian :\n";
    cout << "Metode pencarian yang mengecek satu per satu dari awal sampai akhir sampai menemukan data yang dicari\n";
    cout << "Contoh Sederhana :\n";
    cout << "Bayangkan sedang mencari nama teman di daftar absen yang tidak urut. kita akan membaca dari baris pertama, kedua, ketiga ... sampai ketemu namanya.\n";
    cout << "Kelebihan :\n";
    cout << "1. Bisa digunakan untuk data yang belum diurutkan\n";
    cout << "2. Mudah dipahami dan diterapkan\n";
    cout << "Kekurangan :\n";
    cout << "Lambat jika data banyak, karena harus periksa satu per satu.\n\n";
    cout << "Binary Searching (pencarian Biner)\n";
    cout << "Pengertian :\n";
    cout << "Metode pencarian yang membagi dua bagian data terus-menerus, lalu memilih bagian yang mungkin berisi data.\n";
    cout << "Syarat :\n";
    cout << "Data harus sudah diurutkan lebih dulu\n";
    cout << "Contoh Sederhana :\n";
    cout << "Bayangkan sedang mencari nomor halaman di kamus. kita buka halaman tengah, lalu cek :\n";
    cout << "  - Jika terlalu besar, ambil bagian sebelah kiri\n";
    cout << "  - Jika terlalu kecil, ambil bagian sebelah kanan\n";
    cout << "  - Lanjutkan hingga ketemu\n";
    cout << "Kelebihan :\n";
    cout << "Jauh lebih cepat dibandingkan sequential, terutama untuk data besar\n";
    cout << "Kekurangan :\n";
    cout << "Harus sudah urut dulu, tidak bisa dipakai di data acak\n";
}

int main()
{
    int n;
    cout << "Pilih menu\n";
    cout << "1. Sequential Searching\n";
    cout << "2. Binary Searching\n";
    cout << "3. Jelaskan Perbedaan Sequential Searching dan Bnary Searching?\n";
    cout << "4. Exit\n";
    cout << "Pilih :\n";
    cin >> n;
    switch(n)
    {
        case 1 :
            Sequential();
            break;
        case 2 :
            binary();
            break;
        case 3 :
            tiga();
        default :
            break;
    }
}