#include <bits/stdc++.h> 
#define ll long long int
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forinc(i,a,b) for(ll i=a;i<b;i++)
#define fordec(i,a,b) for(ll i=a;i<b;i--)
using namespace std;
// Check each element as int or not
bool isNumberString(string str){
    forinc(i,0,str.length()){
        if(str[i]<'0' || str[i]>'9'){
            return false;
        }
    }
    return true;
}
// Return Sum of Digits
int sumDigits(int no){
    int sum=0;
    while(no!=0){
        sum+=(no%10);
        no/=10;
    }
    return sum;
}
//Convert char value to int
int char_to_int(char str){
    return (str-'0');
}
// Using Luhn Algo. Check if number is valid or not
bool isValid(string str){
    int cnt=0;
    for(int i=str.length()-1;i>=0;i--){
        if(cnt==1){
            int curr_no=char_to_int(str[i]);
            if(curr_no*2 > 9){
                str[i]=char(sumDigits(curr_no*2));
            }
            cnt=0;
        }
        cnt++;
    }
    int sum=0; 
    forinc(i,0,str.length()){
        sum+=(str[i]-'0');
    }
    if(sum%10 == 0) return true;
    return false;
}
signed main() {
    FAST;
    string card_no;
    cout<<"This Code Uses Luhn Algorithm to validate a Credit Card Number."<<endl;
    cout<<"If you have to exit print 'exit'"<<endl;
    while(1){
        cin>>card_no;
        bool check=false;
        if(card_no == "exit"){
            break;
        }
        else if(isNumberString(card_no)){
            if(isValid(card_no)){
            	cout<<"Valid!"<<"    ";
	        	if(card_no[0]=='4') cout<<"VisaCard"<<endl;
	        	else if(card_no[0]=='5') cout<<"Master-Card"<<endl;
	        	else if(card_no[0]=='6') cout<<"Discover-Card"<<endl;
	        	else if(card_no[0]=='3' && card_no[1]=='7') cout<<"American Express Card"<<endl;
	        }
	        else{
	            cout<<"Invalid!"<<endl;
	        }   
        }
    }
    return 0;
}
