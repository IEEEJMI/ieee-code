#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <bits/stdc++.h>
#define sync ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

using namespace std;
vector<string> split_string(string);

long fact(long n) {
    return (n==0||n==1) ? 1 : (fact(n-1) * n);
}

long combinations(long n, long r){
    return fact(n) / (fact(n-r) * fact(r));
}

long distributions(long n, long r){
    return combinations(n,r) * pow((n-r) , r);
}

long long sigma(vector<long> arr){
    long long sum = 0;
    for(long long x=0; x<arr.size(); x++) sum+= arr[x];
    return sum;
}

long long find_min_range(vector<long long> Sigma) {
    long long min = Sigma[0];
    for(long k=0; k<Sigma.size(); k++) if (Sigma[k]<min) min = Sigma[k];
    return min;
}

int main() {
    sync;
    int t;
    cin>>t;
    
    while(t) {        
        // Input for each test case
        long N, K;
        cin>>N>>K;
        long long dogsize[N];
        for(long l=0; l<N; l++)
            cin>>dogsize[l];
        
        vector<long> bucket_sizes;
        for(long l=1; l<=N; l++)
            bucket_sizes.push_back(l);
        
        vector<vector<long> > combos;
        long long sel_buckets = pow(2, K), ic;
        int h=0;
        for(ic=1; ic<sel_buckets; ic++){
            if((long)__builtin_popcount(ic)!=K) continue;
            vector<long> sel;
            for(int j=0; j<K; j++)
                if(ic&(1<<j))
                    sel.push_back(bucket_sizes[j]);

            if(sigma(sel)==N){
                //combos[h].insert(combos[h].end(), sel.begin(), sel.end());
                combos.push_back(sel);
                h++;
            }
        }
        
        for(int o=0; o<10; o++)
        	cout<<combos[o][1];
        
        vector<long> Range;
        vector<long long> SigmaRanges;
        for(int m=0; m<distributions(N,K) ; m++){
            long long avail = pow(2, N), i;
            for(int k=0; k<K;){
                for(i=1; i<avail; i++){
                    //if(__builtin_popcount(i)!=combos[m][k]) continue;
					int a = INT_MAX, b = INT_MIN;
                    for(long j=0; j<N; j++)
                        if(i&(1<<j) && avail&(1<<j)){
                            a = min(a, (int)dogsize[j]);
                            b = max(b, (int)dogsize[j]);
                            Range.push_back(b-a);
                        }
                    avail = avail ^ i;
                    k++;
                    break;
                }
            }
            SigmaRanges.push_back(sigma(Range));
        }
        long long result = find_min_range(SigmaRanges);
        cout<<result<<"\n";
        t--;
    }    
    return 0;
}
