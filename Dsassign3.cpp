#include <iostream>
using namespace std;

int main() {
    int n,j;
    char s;
    cout << "Enter number of servers: ";
    cin >> n;
    j=0;
    int arr[n];
    int h_val[n]; 
    
    

    
    while(1) {
	cout<<"Enter 'Y' to add clients and 'N' to Exit:";
	cin>>s;
	    if (s=='Y'||s=='y'){ 
			cout << "Enter the client ids:\n";
        cin >> arr[j];
        h_val[j] = arr[j] % n;
        cout << "Server No: " << h_val[j] << " Client id: " << arr[j] << endl;
        j++;
    } else if(s=='N'||s=='n'){
		cout<<"Exited";
		break;
	}
	else{
		cout<<"Invalid Input";
		break;
}
}
    return 0;
}
