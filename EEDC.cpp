/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<iostream>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    long int N, Q, L, R;
    cin >> N;
    char A[N];
    for(int i = 0; i < N; i++) 
        cin >> A[i];
    
    string as = A;
    
    int index_luck[N];
    long int N_1 = N-1;
    if(A[N_1] != 0)
        index_luck[0] = 0;
    else if(stoull(as.substr(1, N_1)) % 30 != 0) 
        index_luck[0] = 0;
    else
        index_luck[0] = 1;
    
    if(A[N-2] != 0)
        index_luck[N_1] = 0;
    else if(stoull(as.substr(0, N_1)) % 30 != 0)
        index_luck[N_1] = 0;
    else
        index_luck[N_1] = 1;
        
    
    
    for(int i = 1; i < N_1; i++){
		string s1 = as.substr(0,i), s2 = as.substr(i+1,(N - i - 1));
		int s1_l = s1.length(), s2_l = s2.length(), last_two_digits_s2 = stoi(s2.substr(s2_l - (s2_l >= 2? 2 : s2_l)));
		try{
			// unsigned long long int a1 = stoull(as.substr(0,i)), a2 = stoull(as.substr(i+1,(N - i - 1)));
			int last_two_digits_s1 = stoi(s1.substr(s1_l - (s1_l >= 2? 2 : 1)));
			if(i == N_1-1)
				last_two_digits_s2 = stoi(s2.substr(s2_l - 1));
			cout << last_two_digits_s1 << " | "<< last_two_digits_s2 << endl;
			// if((a1 + a2) % 30 == 0)
				// index_luck[i] = 1;
			// else
				// index_luck[i] = 0;
		} catch(...){
			// cout << i << ": "<< as.substr(0,i) << " | " << as.substr(i+1,(N - i - 1)) << endl;
			cout << i <<">> S1: "<< s1.substr(s1_l - (s1_l >= 2? 2 : s1_l)) << " S2: " << s2.substr(s2_l - (s2_l >= 2? 2 : s2_l))<<endl;
			return 0;
		}
    }
    return 0;
	// for(int i =0; i <N ; i++){
		// cout << index_luck[i] << " ";
	// }
	
    cin >> Q;
    while(Q--) {
        cin >> L >> R;
        int lucky_indicies = 0;
        for(int i = L; i <= R; i++){
            lucky_indicies += index_luck[i];
        }
        cout << lucky_indicies << endl;
    }
    return 0;
}