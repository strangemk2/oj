#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

set<string> get_dictionary(const string &vocabulary)
{
    set<string> result;
    
    size_t pos = 0;
    while (true)
    {
        auto new_pos = vocabulary.find(',', pos);
        if (pos == string::npos) break;
        auto word = vocabulary.substr(pos, new_pos - pos);
        result.insert(word);
        pos = new_pos + 1;
    }
    
    return result;
}

bool word_split(string input, vector<string> &result, const set<string> &dictionary)
{
    if (input.length() == 0) return false;
    if (dictionary.count(input)) return true;
    
    for (size_t i = 0; i < input.length(); ++i)
    {
        auto word = input.substr(0, i);
        if (dictionary.count(word))
        {
            result.push_back(word);
            word_split(input.substr(i+1), result, dictionary);
            result.pop_back();
        }
    }
	return false;
}

int main()
{
    string vacabulary = "sky,the,blue,grass,green,is,run,value,algorithm";
    auto dictionary = get_dictionary(vacabulary);
    vector<string> result;
    return word_split("theskyisblue", result, dictionary);
}
