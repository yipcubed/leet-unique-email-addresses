#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

// https://leetcode.com/problems/unique-email-addresses/

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:

    string sanitize(const string& s) {
        string res;
        for (auto c: s) {
            switch(c) {
                case '+': return res;
                case '.': break;
                default: res.push_back(c); // res += c;
            }
        }
        return res;
    }

    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> es;
        for(auto& email: emails) {
            int at = email.find('@');
            es.insert(sanitize(email.substr(0, at)) + email.substr(at, email.size() - at));
        }
        // cout << es << endl;
        return es.size();
    }
};

void test1() {
    vector<string> v1{"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};

    cout << "2 ? " << Solution().numUniqueEmails(v1) << endl;
}

void test2() {

}

void test3() {

}