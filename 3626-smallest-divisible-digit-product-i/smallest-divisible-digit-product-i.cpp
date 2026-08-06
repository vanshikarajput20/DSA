class Solution {
public:
    int digitProduct(long long x) {
        int product = 1;

        while (x > 0) {
            product *= (x % 10);
            x /= 10;
        }

        return product;
    }

    int smallestNumber(int n, int t) {
        while(true){
            int product = digitProduct(n);

            if(product % t == 0){
                return n;
            }

            n++;
        }
        return 0;
    }
};