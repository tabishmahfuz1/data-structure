// Online C++ compiler to run C++ program online
#include <iostream>
#include <map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    if ( s.length() == 0 ) return 0;
    
    std::map<char, int> map;
    int l = 0, r = 1, max_length = 1, c_length = 1;
    map[s[0]] = 0;
    while ( r < s.length() ) {
        std::map<char, int>::iterator iter = map.find(s[r]);
        cout << "Checking " << s[l] << " at " << l << " and " << s[r] << " at " << r << endl;
        if ( iter != map.end() && iter->second >= l ) {
            cout << "Found duplicate character " << s[r] << " at " << iter->second << endl;
            l = iter->second + 1;
            map[s[r]] = r;
            r++;
            
            cout << "Set l: " << l << " and r: " << r << endl;
            c_length = r - l;
            continue;
        }

        map[s[r]] = r;

        c_length++;

        if ( c_length > max_length ) {
            max_length = c_length;
            cout << "Updated Max Length: " << max_length << endl;
        }
        r++;
    }
    
    if ( c_length > max_length ) {
        max_length = c_length;
        cout << "Updated Max Length: " << max_length << endl;
    }

    return max_length;
}

int main() {
    // Write C++ code here
    cout << lengthOfLongestSubstring("abba") << endl;

    return 0;
}
