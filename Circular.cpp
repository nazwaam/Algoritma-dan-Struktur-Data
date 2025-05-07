#include <iostream>
using namespace std;

//struktur node untuk nyimpan data dan petunjuk ke node lain
struct Node {
    int data; //nilai yang disimpan
    Node* prev; //penunjuk ke node sebelumnya
    Node* next; //penunjuk ke node selanjutnya
};

//pointer ke node pertama (head) dari linked list
Node* head = nullptr;

//fungsi untuk nambah data di akhir list
void tambahDiAkhir(int nilai) {
    //buat node baru
    Node* nodeBaru = new Node{nilai, nullptr, nullptr};

    //jika list masih kosong
    if (head == nullptr) {
        //node baru menunjuk ke diri sendiri
        nodeBaru->next = nodeBaru; 
        nodeBaru->prev = nodeBaru;
        head = nodeBaru; //jadikan node ini sebagai kepala
        return;
    }

    //kalau list udah ada isinya
    Node* tail = head->prev; //ambil node terakhir

    //hubungkan node baru ke kepala dan ekor
    nodeBaru->next = head;
    nodeBaru->prev = tail;

    tail->next = nodeBaru;
    head->prev = nodeBaru;
}

//fungsi buat ngapus data dari awal list
void hapusDepan() {
    //kalau list kosong, keluar dari fungsi
    if(head == nullptr)
    return;

    //kalau cuman ada satu node
    if (head-> next == head) {
        delete head;
        head = nullptr;
        return;
    }

    //kalau ada lebih dari satu node
    Node* nodeDihapus = head;
    Node* tail = head->prev;

    head = head->next; //geser kepala ke node berikutnya
    head->prev = tail; //hubungkan kepala baru ke ekor
    tail->next = head; //hubungkan ekor ke kepala baru

    delete nodeDihapus; //hapus node lama
}

//fungsi untuk nampilkan isi list
void tampilkanList() {
    //kalau list kosong
    if (head == nullptr) {
        cout << "List masih kosong\n";
        return;
    }

    Node* sekarang = head;
    cout << "Isi list : ";

    //cetak data dari setiap node, selama belum kembali ke kepala
    do {
        cout << sekarang->data << " ";
        sekarang = sekarang->next;
    }
    while (sekarang != head);

    cout << endl;
}

//fungsi utama
int main() {
    //tambahkan data ke list
    tambahDiAkhir(10);
    tambahDiAkhir(20);
    tambahDiAkhir(30);

    tampilkanList();

    //hapus data dari depan
    hapusDepan();

    tampilkanList();
    return 0;
}