#include<bits/stdc++.h>
using namespace std;

string getEncryptedString(string input, int key){
    string outputString;
    for(int i=0;i<input.length();i++){
        outputString.push_back(input[i]+key);
    }
    return outputString;
}

string getDecryptedString(string input, int key){
    string outputString;
    for(int i=0;i<input.length();i++){
        outputString.push_back(input[i]-key);
    }
    return outputString;
}

void encrypt(int key){
    fstream inputFile;
    inputFile.open("originalInformation.txt", ios::in);
    fstream outputFile;
    outputFile.open("codedInformation.txt", ios::out);
    if(inputFile.is_open() && outputFile.is_open()){
        string ip;
        while(getline(inputFile, ip)){
            string encryptedString = getEncryptedString(ip, key);
            outputFile<<encryptedString;
            outputFile<<"\n";
        }
        inputFile.close();
        outputFile.close();
    }
}

void decrypt(int key){
    fstream inputFile;
    inputFile.open("codedInformation.txt", ios::in);
    fstream outputFile;
    outputFile.open("originalInformation.txt", ios::out);
    if(inputFile.is_open() && outputFile.is_open()){
        string ip;
        while(getline(inputFile, ip)){
            string encryptedString = getDecryptedString(ip, key);
            outputFile<<encryptedString;
            outputFile<<"\n";
        }
        inputFile.close();
        outputFile.close();
    }
}

int main(){
    int key;
    cout<<"Enter Key:"<<endl;
    cin>>key;
    int choice;
    cout<<"Enter Choice: 1. Encrypt  2. Decrypt"<<endl;
    cin>>choice;

    switch (choice)
    {
        case 1:
            encrypt(key);
            break;
        case 2:
            decrypt(key);
            break;
        
        default:
            break;
    }
    return 0;
}