#include "lexer.h"
using namespace std;
//for printing tokens names, Same as the enum defined in lexer.h
string reserved[] = {
    "END_OF_FILE",
    "Identifier",
	"Relational_Operator",
	"Special_Character",
	"Number",
	"Strings",
	"Comments",
	"Arithmetic_Operators",
	"Starting_Bracket",
	"Closing_Bracket",
	"IO_Operators",
    "Assignment_Operator",
    "Keyword",
	"Error"
	};
token::token()
{
    this->lexeme = "";
    this->tokenType = TokenType::ERROR;
}
token::token(string lexeme, TokenType tokenType)
{
    this->lexeme = lexeme;
    this->tokenType = tokenType;
}
void token::Print()
{
    cout << "{" << lexeme << " , "
        << reserved[(int)tokenType] << "}\n";
}
int lexer::getCurrentPointer()
{
    return index;
}
void lexer::setCurrentPointer(int pos)
{
    if (pos >= 0 && pos < tokens.size())
        index = pos;
    else
        index = 0;
}
void lexer::Tokenize()//function that tokenizes your input stream
{
    vector<char>::iterator it = stream.begin();
    string str;
    bool comment=false;
    for (it = stream.begin(); it != stream.end(); ){
        // cout << *it<< endl;
        if(*it=='%')
        {
            tokens.push_back(token(string("%"), TokenType::AO));
            it++;
        }
        else if(*it=='-'){
            tokens.push_back(token(string("-"), TokenType::AO));
            it++;
        }
        else if(*it=='+'){
            tokens.push_back(token(string("+"), TokenType::AO));
            it++;
        }
        else if(*it=='/'){
            tokens.push_back(token(string("/"), TokenType::AO));
            it++;
        }
        else if(*it=='*'){
            tokens.push_back(token(string("*"), TokenType::AO));
            it++;
        }
        else if(*it=='('){
            tokens.push_back(token(string("("), TokenType::SB));
            it++;
        }
        else if(*it==')'){
            tokens.push_back(token(string(")"), TokenType::CB));
            it++;
        }
        else if(*it==':'){
            it++;
            if(*it=='='){
                *it++;
                tokens.push_back(token(string(":="), TokenType::ASSIGN));
            }
            else
                tokens.push_back(token(string(":"), TokenType::SC));

        }
        else if(*it==';'){
            tokens.push_back(token(string(";"), TokenType::SC));
            it++;
            while(*it!='\n'){
                // cout << 'it';
                if (it+1 == stream.end())
                {
                    str.push_back(*it);
                    break;
                }
                str.push_back(*it);
                it++;
            }
            it++;
            if(str.length()>0){
                // cout << endl <<str<<endl;
                
                tokens.push_back(token(string(str), TokenType::CMTS));
                str="";
            }
        }
        else if(*it=='@'){
            tokens.push_back(token(string("@"), TokenType::SC));
            it++;
        }
        else if(*it=='|'){
            tokens.push_back(token(string("|"), TokenType::SC));
            it++;
        }
        // else if(*it=='`'){
        //     tokens.push_back(token(string("`"), TokenType::SC));
        //     it++;
        // }
        else if(*it=='=')
        {
            tokens.push_back(token(string("="), TokenType::RO));
            it++;
        }
        else if (*it=='<')
        {
            it++;
            if(*it=='<'){
                tokens.push_back(token(string("<<"), TokenType::IO));   
                it++;
            }
            else if(*it=='='){
                tokens.push_back(token(string("<="), TokenType::RO));
                it++;
            }
            else if(*it=='>'){
                tokens.push_back(token(string("<>"), TokenType::RO));
                it++;
            }
            else
                tokens.push_back(token(string("<"), TokenType::RO));
            /* code */
        }
        else if (*it=='>')
        {
            it++;
            if(*it=='>'){
                tokens.push_back(token(string(">>"), TokenType::IO));   
                it++;
            }
            else if(*it=='='){
                tokens.push_back(token(string(">="), TokenType::RO));
                it++;
            }
            else
                tokens.push_back(token(string(">"), TokenType::RO));
            /* code */
        }
        else if(*it=='`'){
            // cout <<"String";
            it++;
            str="";
            if(*it!='`'){
                while(*it!='`'){
                    str.push_back(*it);
                    it++;
                }
                // cout << endl<<str<<endl;
                tokens.push_back(token(string(str), TokenType::STR));
                str="";
                it++;
            }
            else if(*it=='`')
                it++;

        }
        else if(*it=='_'){
            str="";
            str.push_back(*it);
            it++;
            while((*it>='A'&&*it<='Z')||(*it>='a'&&*it<='z')||(*it=='_')){
                str.push_back(*it);
                it++;
            }
            tokens.push_back(token(string(str), TokenType::ID));
            str="";
        }
        else if((*it>='A'&&*it<='Z')||(*it>='a'&&*it<='z')||(*it=='_')){
            str="";
            str.push_back(*it);
            it++;
            while((*it>='A'&&*it<='Z')||(*it>='a'&&*it<='z')||(*it=='_')||(*it>='0'&&*it<='9')){
                str.push_back(*it);
                it++;
            }
            if((str=="markazi")||(str=="kaam")||(str=="karo")||(str=="rakho")||(str=="jab")
            ||(str=="tak")||(str=="bas")||(str=="agar")||(str=="to")||(str=="warna")||(str=="phir")
            ||(str=="dekhao")||(str=="lo")||(str=="chalao")||(str=="wapas")||(str=="bhejo")
            ||(str=="adad")||(str=="khali")||(str=="khatam")){
                tokens.push_back(token(string(str), TokenType::KEY));
                str="";
            }
            else{
                tokens.push_back(token(string(str), TokenType::ID));
                str="";
            }
        }
        else if(*it>='0'&&*it<='9'){
            str="";
            str.push_back(*it);
            it++;
            while(*it>='0'&&*it<='9'){
                str.push_back(*it);
                it++;
            }
            tokens.push_back(token(string(str), TokenType::NUM));
            str="";

        }
        else
            it++;
    }
    // cout << endl <<getCurrentPointer()<< endl;
    
	//your implementation goes here
	//push_back EOF token at end to identify End of File
    tokens.push_back(token(string(""), TokenType::END_OF_FILE));
}
lexer::lexer(const char filename[])
{
    //constructors: takes file name as an argument and store all
    //the contents of file into the class varible stream
    // cout<<filename;
    ifstream fin(filename);
    if (!fin) //if file not found
    {
        cout << "file not found" << endl;
    }
    else
    {
        char byte = 0;
        while (fin.get(byte))
        { //store file contents into stream
            if (byte != '\r')
                stream.push_back(byte);
        }
        stream.push_back(' ');//dummy spaces appended at the end
        stream.push_back(' ');
        //Tokenize function to get all the (token,lexeme) pairs
        // printRaw();
        Tokenize();
        // printRaw();
        //assigning tokens to iterator::pointer
        index = 0;
    }
}
lexer::lexer()
{
    index = -1;
}
void lexer::printRaw()
{
    //helper function to print the content of file
    vector<char>::iterator it = stream.begin();
    for (it = stream.begin(); it != stream.end(); it++)
    {
        cout << *it;
    }
    cout << endl;
}
token lexer::getNextToken()
{
    //this function will return single (token,lexeme) pair on each call
    //this is an iterator which is pointing to the beginning of vector of tokens
    token _token;
    if (index == tokens.size())
    {                       // return end of file if
        _token.lexeme = ""; // index is too large
        _token.tokenType = TokenType::END_OF_FILE;
    }
    else
    {
        _token = tokens[index];
        index = index + 1;
    }
    return _token;
}
void lexer::resetPointer()
{
    index = 0;
}
token lexer::peek(int howFar)
{
    if (howFar <= 0)
    { // peeking backward or in place is not allowed
        cout << "LexicalAnalyzer:peek:Error: non positive argument\n";
        exit(-1);
    }

    int peekIndex = index + howFar - 1;
    if (peekIndex > (tokens.size() - 1))
    {                                                 // if peeking too far
        return token("", TokenType::END_OF_FILE); // return END_OF_FILE
    }
    else
        return tokens[peekIndex];
}