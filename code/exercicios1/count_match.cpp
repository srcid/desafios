#include <bits/stdc++.h>

using namespace std;

enum RuleKey {
        type = 0,
        color,
        name
};

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int totalMatches = 0;
        unordered_map<string,int> table ({
            {"type",type},
            {"color",color},
            {"name",name}
        });
        
        for (vector<string> item : items) {
            if (item.at(table.at(ruleKey)) == ruleValue)
                totalMatches++;
        }

        return totalMatches;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<string>> items{{"phone","blue","pixel"},{"computer","silver","phone"},{"phone","gold","iphone"}};
    string ruleKey = "type", ruleValue = "phone";
    Solution s;
    cout << s.countMatches(items, ruleKey, ruleValue) << endl;

    return 0;
}
