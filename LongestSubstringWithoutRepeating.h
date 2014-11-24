#ifndef _LONGEST_SUBSTRING_WITHOUT_REPEATING
#define _LONGEST_SUBSTRING_WITHOUT_REPEATING
#include "commonHeader.h"

	int lengthOfLongestSubstring(string s) {
		unordered_map<char, bool> m;
		int prev = 0, max = 1;
		for(int i=0;i<(int)s.size();i++){
			if (!m[s[i]]) m[s[i]] = true;
			else {
				cout<<s.substr(prev, i-prev)<<endl;
				max = max < i-prev ? i-prev : max;
				while(s[prev]!=s[i]) {
					m[s[prev]] = false;
					prev++;
				}
				prev++;
			}
		}
		return max < s.size()-prev ? s.size()-prev : max;;
	}

#endif