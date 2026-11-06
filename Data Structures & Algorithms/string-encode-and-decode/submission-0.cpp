class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for (const string& s : strs) {
            encoded += to_string(s.length()) + "#" + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        int n = s.length();

        while (i < n) {
            // 1. 尋找 '#' 的位置，以確定長度數字的範圍
            int j = i;
            while (s[j] != '#') {
                j++;
            }

            // 2. 解析出字串長度
            int length = stoi(s.substr(i, j - i));

            // 3. 根據長度取出實際的字串內容
            string str = s.substr(j + 1, length);
            result.push_back(str);

            // 4. 移動指標 i 到下一個編碼的開頭
            i = j + 1 + length;
        }

        return result;
    }
};
