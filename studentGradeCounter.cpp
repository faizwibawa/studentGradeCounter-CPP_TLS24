#include <iostream>
#include <iomanip>
#include <malloc.h>
#include <stdio.h>
#include <windows.h>

using namespace std;

int indexAdd = 0;
struct GradesData{
    string nama;
    int gradeUTS;
    int gradeUAS;
    int gradeTugas;
};

void CList (string words);
void CListE (string words, string addersS = "", int addersI = 0);

void AddIt(struct GradesData *mainData);
void ShowIt(struct GradesData *mainData);
int CombineIt(struct GradesData *mainData, int type, int point, int totalGrade);

int main() {
    int mainAnswer;
    GradesData mainData[100];
    bool menuResult = false;
    while (menuResult == false) {
        system("cls");
        cout << "Main menu\n";
        CListE("1. Tambah Data Nilai Mahasiswa");
        CListE("2. Tampilkan Semua Data");
        CListE("3. Keluar");
        cout << "Pilihan anda: "; cin >> mainAnswer;

        switch(mainAnswer){
            case 1:
                {
                    AddIt(mainData);
                    ++indexAdd;
                }
                break;
            case 2:
                {
                    if(indexAdd != 0 )
                        ShowIt(mainData);

                    else{
                        system("cls");
                        cout << "\n\n\tData masih kosong.\n";
                        cout << "\tSilakan kembali ke main menu untuk menambahkan data\n\n";
                        system("pause");
                    }
                }
                break;
            case 3:
                {menuResult = true;}
                break;
            default:
                {
                    system("cls");
                    cout << "Opsi tidak dikenali, mengulangi program...";
                    system("pause");
                } break;
        }
    }

    system("cls");
    cout << "Terima kasih telah menggunakan program ini";
    return 0;
}

void CList (string words) {
    cout << "\t" << words;
}

void CListE (string words, string addersS, int addersI) {
    if (addersI == 0)
        cout << "\t" << words << addersS << "\n";
    else
        cout << "\t" << words << addersS << addersI << "\n";
}

void AddIt(struct GradesData *mainData){
    GradesData tempData = GradesData();
    system("cls");
    cout << "Menu Penambahan Data Nilai Mahasiswa\n";
    CList("Nama Mahasiswa\t: "); cin.ignore(); getline(cin, tempData.nama);
    CList("Nilai UTS\t: "); cin >> tempData.gradeUTS;
    CList("Nilai UAS\t: "); cin >> tempData.gradeUAS;
    CList("Nilai Tugas\t: "); cin >> tempData.gradeTugas;
    mainData[indexAdd] = tempData;
}

void ShowIt(struct GradesData *mainData) {
    system("cls");
    cout << "Data Nilai Mahasiswa\n\n";
    for (int i = 0; i < indexAdd; ++i) {
        CListE("Data no.", "", (i + 1));
        CListE("\tNama Mahasiswa\t: ", mainData[i].nama);
        CListE("\tNilai UTS\t: ", "", mainData[i].gradeUTS);
        CListE("\tNilai UAS\t: ", "", mainData[i].gradeUAS);
        CListE("\tNilai Tugas\t: ", "", mainData[i].gradeTugas);
        cout << endl;
    }
    CListE("Total Nilai UTS Mahasiswa: ", "", CombineIt(mainData, 1, 0, 0));
    CListE("Total Nilai UAS Mahasiswa: ", "", CombineIt(mainData, 2, 0, 0));
    CListE("Total Nilai Tugas Mahasiswa: ", "", CombineIt(mainData, 3, 0, 0));
    cout << endl;
    CListE("Rerata Nilai UTS Mahasiswa: ", "", (CombineIt(mainData, 1, 0, 0)/(indexAdd + 1)));
    CListE("Rerata Nilai UAS Mahasiswa: ", "", (CombineIt(mainData, 2, 0, 0)/(indexAdd + 1)));
    CListE("Rerata Nilai Tugas Mahasiswa: ", "", (CombineIt(mainData, 3, 0, 0)/(indexAdd + 1)));
    cout << endl;
    CListE("Total Nilai Mahasiswa: ", "", (CombineIt(mainData, 1, 0, 0) + CombineIt(mainData, 2, 0, 0) + CombineIt(mainData, 1, 0, 0)));
    CListE("Rerata Nilai Mahasiswa: ", "", ((CombineIt(mainData, 1, 0, 0)/(indexAdd + 1)) + (CombineIt(mainData, 2, 0, 0)/(indexAdd + 1)) + (CombineIt(mainData, 3, 0, 0)/(indexAdd + 1)))/3);
    cout << "\n\n"; system("pause");
}

int CombineIt(struct GradesData *mainData, int type, int point, int totalGrade){
    if (point == indexAdd) 
        return totalGrade;
    switch(type) {
        case 1: 
            {totalGrade += mainData[point].gradeUTS;}
            break;
        case 2:
            {totalGrade += mainData[point].gradeUAS;}
            break;
        case 3:
            {totalGrade += mainData[point].gradeTugas;}
            break;
    }
    ++point;
    CombineIt(mainData, type, point, totalGrade);
}
