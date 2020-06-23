#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
/**
 * 给你两个二进制字符串，返回它们的和（用二进制表示）。
 * 输入为 非空 字符串且只包含数字 1 和 0。
 *  
 * 示例 1:
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 * 提示：
 * 每个字符串仅由字符 '0' 或 '1' 组成。
 * 1 <= a.length, b.length <= 10^4
 * 字符串如果不是 "0" ，就都不含前导零。
 * 
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/add-binary
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
public:
    string addBinary(string a, string b) {
        if(a.empty()) return b;
        if (b.empty()) return a;

        if(a.length() > b.length())
        {
            while (b.length()!= a.length())
            {
               b = "0"+b;
            }
        }
        else if (a.length() < b.length())
        {
           while (a.length()!= b.length())
            {
               a = "0"+a;
            }
        }

        std::string retStr{};
        bool carry = false;
        for (int i = a.length()-1; i >= 0; i--)
        {
            if (a.at(i) == b.at(i))
           {
               retStr += carry ? "1":"0";
               carry = a.at(i) == '1' ? true : false;
           }
           else
           {
               retStr += carry?"0":"1";
           }
        }

        if (carry)
        {
           retStr += "1";
        }
        
        reverse(retStr.begin(),retStr.end());

        return retStr;
    }
};