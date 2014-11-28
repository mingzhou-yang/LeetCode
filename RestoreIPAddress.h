#ifndef _RESTORE_IP_ADDR
#define _RESTORE_IP_ADDR
#include "commonHeader.h"

		int toInt(string s){
			int sign = 1;
			int num=0;
			for(int i=0;i<(int)s.size();i++){
				if (s[i]=='-') sign = -1;
				else{
					num *= 10;
					num += (int)(s[i]-'0');
				}
			}
			return sign*num;
		}

		string toString(int num){
			if (!num) return "0";
			string ret;
			while(num>0){
				char c = num%10 + '0';
				ret = c + ret;
				num /= 10;
			}
			return ret;
		}

		string toAddr(vector<string> addr){
			return addr[0]+"."+addr[1]+"."+addr[2]+"."+addr[3];
		}

	void restoreIp(string s, int num, int pos, vector<string> &addr, vector<string> &v){
		if (num==1){
			int size = s.size()-pos;
			if (size>3) return;
			int i = toInt(s.substr(pos, size));
			if (i<=255) {
				string str = toString(i);
				if (str.size()<size) return;
				addr.push_back(str);
				v.push_back( toAddr(addr));
				addr.pop_back();
			}
			return;
		}
	
		for(int i=1;i<=3&&pos+i<s.size();i++){
			int j = toInt(s.substr(pos, i));
			if (j<=255){
				string str = toString(j);
				if (str.size()<i) continue;
				addr.push_back(str);
				restoreIp(s, num-1, pos+i, addr, v);
				addr.pop_back();
			}
		}

	}

	vector<string> restoreIpAddresses(string s) {
		vector<string> ret;
		vector<string> addr;
		if (s.size()<4) return ret;
		restoreIp(s, 4, 0, addr, ret);
		return ret;
	}

#endif