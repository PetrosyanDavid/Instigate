#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){

    int n;
    string str_input = "";
    cout<<"Please input number of scores: " << flush;
    while(true)
    {
        getline(cin, str_input);
        istringstream my_stream(str_input);
        if (my_stream >> n){
            break;
        }
        cout << "Invalid input, please try again" << endl;
    }
    int a[n];
    int sum = 0;
    int less = 0;
    int more = 0;
    double avrg = 0;
    string loop_string;
    int loop_int;

    for(int i = 0 ; i < n ; i++){
        cout << "Please input the " << i+1 << " score: " << flush;
        while(true){
            cin >> loop_string;
            istringstream loop_int(loop_string);
            if(loop_int >> a[i]){
                break;
            }
            cout << "Invalid input, try again" << endl; 
        }
        sum+=a[i];

    }

    avrg=(double)sum/n;

    for(int i=0; i<n; i++){
        if(a[i]>=avrg) more++;
        else less++;
    }

    cout << "The average score is: "<< avrg << endl;
    cout << "Number of scores above or equal to average: " << more << endl;
    cout << "Number of scores below average: " << less << endl;
    return 0;
}
