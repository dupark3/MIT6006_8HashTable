#include <cmath> // abs
#include <iostream>


#define MAX 1000

bool hash[MAX + 1][2];

void insert(int keys[], int size){
    for(int i = 0; i < size; ++i){
        if (keys[i] >= 0){
            hash[keys[i]][0] = true;
        } else {
            hash[std::abs(keys[i])][1] = true;
        }
    }
}

int main(){
    int keys[] = {1, -5, 2, 3, 0, -10, 15};
    int size = sizeof(keys) / sizeof(int);
    insert(keys, size);

}