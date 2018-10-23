#include<bits/stdc++.h>
#include<math.h>
#include<string.h>
using namespace std;

#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

vector<string> split_string(string);

int main() {    
    int N, Q;

    cin>>N;
    vector<int> P;
    
    string t_P;
    vector<string> tt_P;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, t_P);
    tt_P = split_string(t_P);
    
    for(int i=0; i<tt_P.size(); i++)
        P.push_back(stoi(tt_P[i]));

    cin>>Q;
    vector<int> G; 
    for(int i=0; i<Q; i++) {
        int temp;
        cin>>temp;
        G.push_back(temp);
    }

    // N = 5;
    // P = {10, 3, 5, 8, 6};
    // Q = 2;
    // G = {7, 4};

    while(Q) {
        int flag = 0;
        for(ll i=0; i<pow(2, N); i++) {
            vector<int> select;
            if(__builtin_popcount(i)>0) {
                for(int j=0; j<N; j++)
                    if((1<<j)&i) select.push_back(P[j]);
            } 
            else
                continue;

            int agr=0;
            for(int k=0; k<select.size(); k++){
                agr = agr | select[k];
            }

            if(agr==G[G.size()-Q]){
                flag=1;
                cout<<"YES"<<endl;  
                break;
            }
        }
        if(!flag) cout<<"NO"<<endl;
        // DO NOT WRITE BELOW THIS LINE
        Q--;
    }

    return 0;
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