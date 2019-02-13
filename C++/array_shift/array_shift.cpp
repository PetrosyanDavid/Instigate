#include <iostream>

// shifth function prototype
void shift(int* ,int, int);

int main() {

    std::cout<<"Enter your array size "; 
    int n = 0;
    std::cin>>n;
    int array[n];

    std::cout<<"Enter your value to be searched ";
    int input = 0;

    std::cin>>input;
    std::cout<<"Input array numbers "<<std::endl; 
    for (int i = 0; i < n; i++){
        std::cin >> array[i];
    }

    //shift function call
    shift(array , n, input);
    for(int i = 0; i < n; i++){
        std::cout << array[i] << std::flush;
    }
    std::cout<<std::endl;


        return 0;

}

void shift ( int a[], int size, int input){

    for(int i = 0; i<size; ++i){
        if(a[i] != input){
            continue;
        }
        else{
            for (int j = i; j < size - 1; j++){
                a[j] = a[j+1];
            }
            a[size-1] = 0;
            break;
        }
    }
}


