#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string input_string);

int sumKaro(int **C, int s_X, int s_Y, int e_X, int e_Y) {
    int sum=0;

    for(int i=s_X; i<e_X; i++){
        for(int j=s_Y; j<e_Y; j++){
            sum+=C[i][j];
        }
    }
}

int findMax(vector<int> arr){
    int max = arr[0];
    for(int m=0; m<arr.size(); m++)
        if(arr[m]>max) max = arr[m];
}

void findMaxRectangle(int N, int M, int A[3], int B[3]) {
    int C[3][3];
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            C[i][j] = A[i] * B[j];

    vector<int> sums;
    for(int s_X=0; s_X<N; s_X++){
        for(int s_Y=0; s_Y<M; s_Y++){
            for(int e_X=s_X; e_X<N; e_X++){
                for(int e_Y=s_Y; e_Y<N; e_Y++){
                    int sum=0;
                    for(int i=s_X; i<=e_X; i++){
                        for(int j=s_Y; j<=e_Y; j++){
                            sum+=C[i][j];
                        }
                    }
                    sums.push_back(sum);
                    //sums.push_back(sumKaro(C, s_X, s_Y, e_X, e_Y));
                }
            }
        }
    }

    int max = findMax(sums);
    cout<<max;
}

int main() {
    int N, M;
    cin>>N>>M;
    
    // string t_A, t_B;
    // vector<string> tt_A, tt_B;

    // getline(cin, t_A);
    // getline(cin, t_B);

    // tt_A = split_string(t_A);
    // tt_B = split_string(t_B);

    // vector<int> A, B;
    // for(int i=0; i<tt_A.size(); i++)
    //     A.push_back( stoi(tt_A[i]) );
    
    // for(int j=0; j<tt_B.size(); j++)
    //     B.push_back( stoi(tt_B[j]) );

    int A[3], B[3];
    cin>>A[0]>>A[1]>>A[2];
    cin>>B[0]>>B[1]>>B[2];

    findMaxRectangle(N, M, A, B);
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
