class Solution {
public:
    int myAtoi(string s) {
        int i = 0;

        while(i < s.length() && s[i] == ' '){
            i++;
        }

        int sign = 1;

        if(s[i] == '-'){
            sign = -1;
            i++;
        }
        else if(s[i] == '+'){
            i++;
        }

        long long num = 0;

        while(i < s.length() && isdigit(s[i])){
            num = num * 10 + (s[i] -'0');
            if(sign == 1 && num > INT_MAX){
            return INT_MAX;

            }
            else if(sign == -1 && -num < INT_MIN){
                return INT_MIN;

            }
            i++;
        }
        return (int)(sign * num);
    }
};