#include <cmath> // abs
#include <iostream>


#define MAX 1000

// a 2D hash table capable of storing values from -MAX to MAX. 
// the second index is for nonnegative  or neg numbers. 0 of nonnegative, 1 if neg. 
bool hash[MAX + 1][2];

bool search(int key){
    if (key >= 0)
        return hash[key][0];
    else 
        return hash[std::abs(key)][1];
}

void insert(int keys[], int size){
    for(int i = 0; i < size; ++i){
        if (keys[i] >= 0)
            hash[keys[i]][0] = true;
        else
            hash[std::abs(keys[i])][1] = true;
    }
}

void deletion(int key){
    if (key >= 0)
        hash[key][0] = false;
    else
        hash[std::abs(key)][1] = false;
}

int main(){
    int keys[] = {1, -5, 2, 3, 0, -10, 15};
    int size = sizeof(keys) / sizeof(int);
    insert(keys, size);
    deletion(2);

    for (int i = -10; i != 17; ++i){
        if(search(i))
            std::cout << i << " is present" << std::endl;
        else
            std::cout << i << " is not present" << std::endl;
    }

}