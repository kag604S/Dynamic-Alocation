//
// Created by Admin on 03.05.2024.
//
#include "array.h"
#include <stdio.h>
#include <stdlib.h>
FILE * fptr; // wskaźnik na file
int findMaximumValue(int array[], int SIZE) {
    int max = array[0];
    for (int i = 0; i < SIZE; ++i )
    {
        if(array[i] > max) max = array[i];
    }
    return max;
}
int findMiniumValue(int array[], int SIZE) {
    int min = array[0];
    for (int i = 0; i < SIZE; ++i )
    {
        if(array[i] < min) min = array[i];
    }
    return min;
}
float calculateAverage(int array[], int SIZE){
    int sum = 0;
    for (int i = 0; i < SIZE; ++i ) {
        sum += array[i];
    }
    float avg = (float)sum / SIZE; // (float)zamiana int na float by wynik wyszedł float
    return avg;
}
void fileenter(int array[], int SIZE)
{
    fptr = fopen("letters.txt", "w+");// otwarcie pliku w trypie odczytu + (zapisu)
    if (fptr == NULL)
    {
        exit(1);
    }
    for (int u = 0; u < SIZE ; ++u)
    {
        fputc(array[u], fptr);// wpisuje znak do pliku
    }

    fclose(fptr);
}
void readFile(int array[], int SIZE)
{
    fptr = fopen("letters.txt", "r+"); // przyjmuje ścieszkę oraz tryb otwarcia odczyt + (zapis)
    fseek(fptr, 0, SEEK_SET); // ustawienie kursora w pliku na początek
    printf("File content:\n");
    for (int i = 0; i < SIZE; i++) //pętla odczytująca z pliku tablice
    {
        array [i] = fgetc(fptr); //wczytuje znak ze strumienia pliku
        fseek(fptr, 0, SEEK_CUR);
        printf("%d\n", array [i]);
    }
    printf("\n");
    fclose(fptr);
}
int* enterValue(int *array, int *s) { // funkcja zwracająca wskaźnik int, przyjmuje tablice oraz jej wskaźnik na aktualną wielkość
    // () argumenty zmiennych, kopie ich wartości, podanych przy wywołaniu
    int element;
    (*s)++; // s++ dodaje 1 do wartości zmiennej, *s++ dodaje 1 do indexu wskaźnika
    array = (int *)realloc(array, (*s) * sizeof(int)); // wskaźnik realloc przyjmuje array i mnoży rozmiar s razy wielkość int
    //ta linia odpowiada za zmienianie wilkości tablicy array
    if (array == NULL) { // nie ma wskaźnika funkcja realloc nie powiodła się
        printf("Memory allocation error!");
        exit(1);
    }
    printf("Enter number to add: ");
    scanf("%d", &element); // &element przekazanie wskaźnika na element do funkcji scanf
    array[(*s) - 1] = element; //*s odwołanie do zmiennej wskazywanej przez wskaźnik
    return array;
}
void printArray(int array[], int s) // podobnie jak w enterValue tylko int s oznacza kopie zmiennej z wartością SIZE
{
    for (int i = 0; i < s; i++) {
        printf("array[%d] = %d\n", i, array[i]); // array[i] można też w tym wypadku array++
        //array++       ++array
    }
    printf("\n"); // '\n' <- ender '\t' <- tab
}
int* deleteValues(int *array, int *s) { // int* nazwa = &s; 0x32534645
    if (*s == 0) {
        printf("Array is already empty!\n");
        return array;
    }
    (*s)--;
    array = (int *)realloc(array, (*s) * sizeof(int));
    if (array == NULL && *s > 0) {
        printf("Memory allocation error!");
        exit(1);
    }
    return array;
}