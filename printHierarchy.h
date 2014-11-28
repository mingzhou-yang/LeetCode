#ifndef _Interleaving_STRING_ADDR
#define _Interleaving_STRING_ADDR
#include "commonHeader.h"

void printHierarchy(vector<pair<char, char>> &data){
//�洢����֮��Ĺ�ϵ��m����
    unordered_map<char, vector<char>> m;
    for(int i=0;i<(int)data.size();i++){
        if (m.find(data[i].first)==m.end()){
            vector<char> v;
            v.push_back(data[i].second);
            m[data[i].first] = v;
        }
        else m[data[i].first].push_back(data[i].second);
    }
//Ѱ����˻���
    unordered_map<char, bool> findFather;
    char father;
    for(unordered_map<char, vector<char>>::iterator it=m.begin();it!=m.end();++it){
        findFather[it->first] = true;
    }
    for(unordered_map<char, vector<char>>::iterator it=m.begin();it!=m.end();++it){
        for(int i=0;i<(int)((it->second).size());i++){
            if (findFather.find((it->second)[i])!=findFather.end()) findFather[it->second[i]] = false;
        }
    }
    for(unordered_map<char, vector<char>>::iterator it=m.begin();it!=m.end();++it){
        if (findFather[it->first]){
            father = it->first;
            break;        
        }
    }
    
//�������֮��Ľṹ
    unordered_map<char, int> hierarchy;
    stack<char> s;
    s.push(father);
    hierarchy[father] = 0;
    while(!s.empty()){
        char topic = s.top();
        s.pop();
        for(int i=0;i<hierarchy[topic];i++) cout<<"    ";
        cout<<topic<<endl;
        for(int i=0;i<(int)m[topic].size();i++){
            s.push(m[topic][i]);
            hierarchy[m[topic][i]] = hierarchy[topic]+1;
        }
    }
}

#endif