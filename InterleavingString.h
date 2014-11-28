#ifndef _Interleaving_STRING_ADDR
#define _Interleaving_STRING_ADDR
#include "commonHeader.h"

    bool isInterleave(string s1, string s2, string s3) {
		if (s1.size()+s2.size()!=s3.size()) return false;
		if (s3.empty()) return true;
		int size1 = (int)s1.size(), size2 = (int)s2.size();
		vector<vector<bool>> v(size1+1, vector<bool>(size2+1, false));
		v[size1][size2] = true;
		for(int i=1;i<=s3.size();i++){
			for(int j=0;j<=i;j++){
				if (j>size1 || i-j>size2) continue;
//				cout<<i<<" "<<j<<" "<<s3[s3.size()-i]<<" "<<s1[size1-j]<<" "<<s2[size2-i+j]<<endl;
				if (j>0 && s1[size1-j]==s3[s3.size()-i] && v[size1-j+1][size2-i+j])
					v[size1-j][size2-i+j] = v[size1-j+1][size2-i+j]; 
				if (i-j>0 && s2[size2-i+j]==s3[s3.size()-i] &&  v[size1-j][size2-i+j+1])
					v[size1-j][size2-i+j] = v[size1-j][size2-i+j+1];
			}
		}
		return v[0][0];
    }

#endif