/*  Nama    : Findia Permata
    Nim     : 24343104
    Tgl     : 29 November 2024
    Matkul  : fundamental pemograman
   
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *inputFile, *outputFile;
    char operator;
    double a, b, hasil;

    // membuka file input_1.txt untuk membaca
    inputFile = fopen("C:\\Users\\acer\\Documents\\Fundamental sem.1\\input_1.txt", "r");
    if (inputFile == NULL) {
        printf("File input_1.txt tidak dapat dibuka!\n");
        return 1;
    }

    // membuka atau membuat file output_1.txt untuk menulis
    outputFile = fopen("C:\\Users\\acer\\Documents\\Fundamental sem.1\\output_1.txt", "w");
    if (outputFile == NULL) {
        printf("File output_1.txt tidak dapat dibuka!\n");
        fclose(inputFile);
        return 1;
    }

    // Membaca data dari input file dan melakukan perhitungan
    while (fscanf(inputFile, "%lf %c %lf", &a, &operator, &b) != EOF) {
        // Menggunakan switch untuk memilih operasi berdasarkan operator
        switch (operator) {
            case '+':
                hasil = a + b;
                break;
            case '-':
                hasil = a - b;
                break;
            case '*':
                hasil = a * b;
                break;
            case '/':
                if (b != 0) {
                    hasil = a / b;
                } else {
                    fprintf(outputFile, "Error: Division by zero\n");
                    continue;  // Skip the current iteration if division by zero
                }
                break;
            default:
                fprintf(outputFile, "Error: Invalid operator '%c'\n", operator);
                continue;  // Skip the current iteration if the operator is invalid
        }

        // Menulis hasil ke file output_1.txt
        fprintf(outputFile, "Hasil dari %.4f %c %.4f adalah: %.4f\n", a, operator, b, hasil);
    }

    // Menutup file
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
