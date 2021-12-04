#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <sstream>
#include <vector>
#include "MySharePtr.h"
using namespace std;

typedef vector<string>::size_type CLine;

class CQueryResult
{
public:
    CQueryResult(const string& _queryWord, shared_ptr<set<CLine> > _lines, shared_ptr<vector<string> > _linesText);
    friend ostream& operator<<(ostream& os, const CQueryResult& _queryResult);

private:
    string m_queryWord;
    shared_ptr<set<CLine> > m_linesFound;
    shared_ptr<vector<string> > m_linesText;
};
CQueryResult::CQueryResult(const string& _queryWord, shared_ptr<set<CLine> > _lines, shared_ptr<vector<string> > _linesText)
        :m_queryWord(_queryWord), m_linesFound(_lines), m_linesText(_linesText)
{
}

string makeAppend(int _n, const string& _original, const string& _append)
{
    return _n > 1 ? _original + _append : _original;
}
ostream& operator<<(ostream& os, const CQueryResult& _queryResult)
{

    os<<"\""<<_queryResult.m_queryWord<<"\" occurs "<<_queryResult.m_linesFound->size()<<" "
      <<makeAppend(_queryResult.m_linesFound->size(), "time", "s")<<" :"<<endl;
    for (auto itr = _queryResult.m_linesFound->cbegin(); itr != _queryResult.m_linesFound->cend(); ++itr)
    {
        os<<"   "<<setw(3)<<*itr + 1<<" "<<_queryResult.m_linesText->at(*itr)<<endl;
    }
    return os;
}

class CTextQuery
{
public:
    CTextQuery(ifstream& _fin);
    CQueryResult query(const string& _queryWord) const;
private:
    shared_ptr<vector<string> > m_linesText;
    map<string, shared_ptr<set<CLine> > > m_wordMap;
};
CTextQuery::CTextQuery(ifstream& _fin)
        :m_linesText(new vector<string>)
{
    string lineText;
    int currentLine = 0;
    while (getline(_fin, lineText))
    {
        //cout<<currentLine+1<<" "<<lineText<<endl;
        m_linesText->push_back(lineText);
        istringstream iss(lineText);
        string word;
        while(iss>>word)
        {
            auto& lines = m_wordMap[word];//没有会创建空的shared_ptr,注意这里的引用类型（有何好处？）
            if (!lines)
            {
                lines.reset(new set<CLine>);
            }
            lines->insert(currentLine);
        }
        ++currentLine;
    }
}
CQueryResult CTextQuery::query(const string& _queryWord) const
{
    static shared_ptr<set<CLine>> notFound(new set<CLine>);//（设置一个静态的函数成员变量有何好处？）这里主要是可以利用此对象来判断是否存在数据
    auto itr = m_wordMap.find(_queryWord);
    if (itr != m_wordMap.end())
    {
        return CQueryResult(_queryWord, itr->second, m_linesText);
    }
    else
    {
        return CQueryResult(_queryWord, notFound, m_linesText);
    }
}

int main()
{
    ifstream fin("CPlusPlus.txt");
    CTextQuery textQuery(fin);
    CQueryResult queryResult = textQuery.query("C++");
    cout<<queryResult<<endl;

    return 0;
}



