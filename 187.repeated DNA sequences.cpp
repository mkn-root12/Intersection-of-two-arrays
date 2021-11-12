class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<int> words; //substrings that appear once
        unordered_set<int> doubleWords; //appear twice
        unordered_map<char, int> bitRepresentation;
        
        //we use 2 bit to represent a char
        bitRepresentation['A'] = 0;
        bitRepresentation['C'] = 1;
        bitRepresentation['G'] = 2;
        bitRepresentation['T'] = 3;
        
        vector<string> ans;
        
        // cout << s.size() << " " << (int)s.size() - 10 + 1 << endl;
        
        /*
        (int)s.size():
        Need to convert it from size_t to int!!
        Because size_t is unsigned, and (size_t)0-10+1 will be 18446744073709551607 which is larger than 0!
        */
        for(int i = 0; i < (int)s.size() - 10 + 1; i++){
            //convert s.substr(i, 10) into its bit representation
            int value = 0;
            for(int j = i; j < i+10; j++){
                value = (value << 2) + bitRepresentation[s[j]];
            }
            
            //if the substring appear once but not twice
            //a.k.a, it's the second time the substring appears
            if(!words.insert(value).second && doubleWords.insert(value).second){
                ans.push_back(s.substr(i, 10));
            }
        }
        
        return ans;
    }
};
