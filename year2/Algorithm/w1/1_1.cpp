#include <iostream>
using namespace std;


int main(){
    int flag = 0;
    int x,value,i,j;
    cin >> x;
    cin >> value;
    int arr[x];
    for(i = 0;i<x;i++){
        cin >> arr[i];
    }

    for(i = 0;i<x;i++){
        for(j = i+1;j<x;j++){
            if(arr[i] + arr[j] == value){
                cout <<i << " " << j<<endl;
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            break;
        }
    }
    if(flag == 0){
        cout << "-1"<<endl;
    }


}

// #include <iostream>

// int main() {
//     int n, x;
//     std::cin >> n >> x;

//     int arrayData[n];
//     for (int i = 0; i < n; ++i) {
//         std::cin >> arrayData[i];
//     }

//     int firstIndex = -1, secondIndex = -1;

//     for (int i = 0; i < n; ++i) {
//         int complement = x - arrayData[i];
//         for (int j = i + 1; j < n; ++j) {
//             if (arrayData[j] == complement) {
//                 firstIndex = i;
//                 secondIndex = j;
//                 break;
//             }
//         }
//         if (firstIndex != -1) {
//             break;
//         }
//     }

//     if (firstIndex != -1) {
//         std::cout << firstIndex << " " << secondIndex << std::endl;
//     } else {
//         std::cout << -1 << std::endl;
//     }

//     return 0;
// }

