#include <iostream>
using namespace std;

// Struktur Node
struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// 1. Sisip Awal
void sisipAwal(int nilai) {
    Node* baru = new Node();
    baru->data = nilai;
    baru->next = head;
    head = baru;
    cout << "Berhasil sisip di AWAL: " << nilai << endl;
}

// 2. Sisip Akhir
void sisipAkhir(int nilai) {
    Node* baru = new Node();
    baru->data = nilai;
    baru->next = NULL;
    if (head == NULL) {
        head = baru;
        cout << "Berhasil sisip di AKHIR (list kosong): " << nilai << endl;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = baru;
    cout << "Berhasil sisip di AKHIR: " << nilai << endl;
}

// 3. Hapus Node (hapus berdasarkan nilai)
void hapus(int nilai) {
    if (head == NULL) {
        cout << "List kosong, tidak bisa dihapus!\n";
        return;
    }
    Node* temp = head;
    Node* prev = NULL;
    // Hapus node pertama
    if (temp != NULL && temp->data == nilai) {
        head = temp->next;
        delete temp;
        cout << "Berhasil hapus data: " << nilai << endl;
        return;
    }
    // Cari node yang akan dihapus
    while (temp != NULL && temp->data != nilai) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Data " << nilai << " tidak ditemukan!\n";
        return;
    }
    prev->next = temp->next;
    delete temp;
    cout << "Berhasil hapus data: " << nilai << endl;
}

// 4. Traversal / Tampilkan seluruh isi list
void traversal() {
    if (head == NULL) {
        cout << "Linked List KOSONG\n";
        return;
    }
    cout << "Isi Linked List: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Main menu uji coba
int main() {
    int pilih, angka;
    do {
        cout << "\n==== MENU SINGLY LINKED LIST ====\n";
        cout << "1. Sisip Awal\n";
        cout << "2. Sisip Akhir\n";
        cout << "3. Hapus Data\n";
        cout << "4. Traversal (Tampilkan)\n";
        cout << "5. Keluar\n";
        cout << "Pilihanmu: ";
        cin >> pilih;
        switch (pilih) {
            case 1:
                cout << "Masukkan angka: "; cin >> angka; sisipAwal(angka); break;
            case 2:
                cout << "Masukkan angka: "; cin >> angka; sisipAkhir(angka); break;
            case 3:
                cout << "Angka yang akan dihapus: "; cin >> angka; hapus(angka); break;
            case 4: traversal(); break;
            case 5: cout << "Selesai\n"; break;
            default: cout << "Pilihan salah!\n";
        }
    } while (pilih != 5);
    return 0;
}
