#include<iostream>
#include<string>
using namespace std;

int main(void)
{

    string num;
    cin >> num;
    int multi;


    string firstletter, secondletter, allLetter;
    int allNum = atoi(num.c_str());

    for (int i = num.length() - 1; i > 0; i--)
    {
        firstletter = num[i - 1];
        secondletter = num[i];

        int m = atoi(firstletter.c_str());
        int n = atoi(secondletter.c_str());

        if (n == 9)
        {
            allNum++;
            num = to_string(allNum);

        }
        else if (n >= 5)
        {
            m++;
            num.replace(i - 1, 1, to_string(m));

            for (int k = i; k < num.length(); k++)
                num.replace(k, 1, "0");


        }
        else {


            for (int k = i; k < num.length(); k++)
                num.replace(k, 1, "0");


        }

        allNum = atoi(num.c_str());
    }

    cout << num;





}
//https://mayple.tistory.com/entry/CSTL-12%EC%9E%A5-string ¹®ÀÚ¿­
//https://yeolco.tistory.com/29