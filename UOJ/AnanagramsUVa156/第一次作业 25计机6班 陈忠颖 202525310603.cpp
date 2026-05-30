#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    map<string, string> region;  //回溯原来单词
    map<string, int> is_visit; //输入文本中是否已存在，并计数
    string in_word, word_tmp;
    set<string> words, out_words;
    while (cin  >> in_word) {
        word_tmp = in_word;
        for (int i=0; i<word_tmp.length(); ++i) {
            word_tmp[i] = tolower(word_tmp[i]);   //换成小写
        }
        sort(word_tmp.begin(), word_tmp.end());   //变成有序单个单词
        words.insert(word_tmp);  //压入单词集合，并排序
        is_visit[word_tmp]++;
        region[word_tmp] = in_word; //取第一个出现的单词
    }
    for (set<string>::iterator it = words.begin(); it != words.end(); ++it) {
        if (is_visit[*it] > 1) continue;    //排查重复单词
        out_words.insert(region[*it]);  //回溯原来的单词，并排序
    }
    for (set<string>::iterator it = out_words.begin(); it != out_words.end(); ++it) {
        cout << *it << endl;
    }
    return 0;
}

//ladder came tape soon leader acme RIDE lone Dreis peat ScAlE orb eye Rides dealer NotE derail LaCeS drIed noel dire Disk mace Rob dries
