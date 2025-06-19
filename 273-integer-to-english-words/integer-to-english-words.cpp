class Solution {
public:
string numToWords(int num){
            vector<string> underTen =  {"","One","Two", "Three","Four","Five","Six","Seven","Eight","Nine"};
        vector<string> underTwenty = {"","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        vector<string> underHundred = {"","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};

        if(num<10) return underTen[num];
        if(num<20 && num>10) return underTwenty[num%10];
        if(num<100) return underHundred[num/10] + (num%10>0?" ":"") + underTen[num%10];
        if(num<1000) return underTen[num/100] + " Hundred"+ (num%100>0?" ":"") + numToWords(num%100);
        if(num<1000000) return numToWords(num/1000) + " Thousand"+ (num%1000>0?" ":"") + numToWords(num%1000);
        if(num<1000000000) return numToWords(num/1000000) + " Million"+ (num%1000000>0?" ":"") + numToWords(num%1000000);
        return numToWords(num/1000000000) + " Billion"+ (num%1000000000>0?" ":"") + numToWords(num%1000000000);
    }
    string numberToWords(int num) {
        if(num  == 0) return "Zero";
        return numToWords(num);
    }
};