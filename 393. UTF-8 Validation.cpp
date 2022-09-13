#include <vector>

class Solution {
public:
    bool validUtf8(std::vector<int>& data) {
        int idx = 0;
        int count = 1;
        while (idx < data.size()) {
            int first_byte = data[idx];
            if ((first_byte & 0x80) == 0x00) {
                // use 1000 0000 as mask to see if start with 0
                count = 1;
            } else if ((first_byte & 0xe0) == 0xc0) {
                // use 1110 0000 as mask to see if start with 110
                count = 2;
            } else if ((first_byte & 0xf0) == 0xe0) {
                // use 1111 0000 as mask to see if start with 1110
                count = 3;
            } else if ((first_byte & 0xf8) == 0xf0) {
                // use 1111 1000 as mask to see if start with 11110
                count = 4;
            } else {
                return false;
            }

            while (count > 1) {
                idx++;
                count--;
                // thr following count - 1 byte should all start with 10
                if (idx == data.size() || (data[idx] & 0xc0) != 0x80)
                    return false;
            }
            idx++;
        }

        return count == 1;
    }
};
