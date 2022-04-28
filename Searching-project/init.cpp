// begin 
string search;
ifstream inFile;
string line;

inFile.open(test.html);

if(!inFile){
cout << "Unable to open file" << endl;
exit(1);
}
cout << "Enter word to search for: ";
cin >>search;


size_t pos;
while(inFile.good())
  {
      getline(inFile,line); // get line from file
      pos=line.find(search); // search
      if(pos!=string::npos) // string::npos is returned if string is not found
        {
            cout <<"Found!";
            break;
        }
  }
// please try to aggretate more code :)
