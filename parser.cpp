#include "parser.h"
#include "lexer.cpp"

// int index=0;
token look;
int tabs=0;
int addr=0;
ofstream fout("sybmol_table.txt");
// vector<token>::iterator it;// = _lexer.begin();


void parser::syntax_error()
{
    cout << "SYNTAX ERROR\n";
    exit(1);
}
token parser::expect(TokenType expected_type)
{
    token t = _lexer.getNextToken();
    if (t.tokenType != expected_type)
        syntax_error();
    return t;
}
parser::parser(const char filename[])
{
    _lexer = lexer(filename);
}
void printTabs(){
    for(int i=0; i<tabs; i++)
        cout << '\t';
}
void printToken(){
        // cout << "TABS"<< tabs;
    for(int i=0; i<tabs; i++)
        cout << '\t';
    cout << look.lexeme<<endl;
}
void parser::match(string tok) {
    if (look.lexeme == tok){
        printTabs();
        cout << tok << endl;
        look = _lexer.getNextToken();
        // look.Print();
        // tabs++;
    }
    else
        syntax_error();
}
void parser::match(TokenType token) {
    if (look.tokenType == token){
        printTabs();
        cout << look.lexeme << endl;
        look = _lexer.getNextToken();
        // tabs++;
    }
    else
        syntax_error();
}

// void parser::EXP(){
//     tabs++;
//     printTabs();
//     cout << "EXP" << endl;
//     tabs--;
// }

void parser::PRINT(){
    tabs++;
    printTabs();
    cout << "PRINT" << endl;
    if(look.tokenType==TokenType::IO){
        tabs++;
        match("<<");
        // tabs--;
        if(look.tokenType==TokenType::ID){
            tabs++;
            match(TokenType::ID);
            PRINT();
            tabs--;
        }
        else if(look.tokenType==TokenType::STR){
            tabs++;
            match(TokenType::STR);
            PRINT();
            tabs--;
        }
        else if(look.tokenType==TokenType::NUM){
            tabs++;
            match(TokenType::NUM);
            PRINT();
            tabs--;
        }
        tabs--;
    }
    else if(look.tokenType==TokenType::SC){
        if(look.lexeme==";"){
            tabs++;
            match(";");
            tabs--;
        }
        else
            syntax_error();
    }
    tabs--;
}

void parser::COUT(){
    tabs++;
    printTabs();
    cout << "COUT" << endl;
    if(look.lexeme=="dekhao"){
        tabs++;
        match("dekhao");
        tabs++;
        match("<<");
        

    
        if(look.tokenType==TokenType::ID){
            tabs++;
            token check=_lexer.peek(_lexer.getCurrentPointer()+1);
            if((check).tokenType==TokenType::AO){
                EXP();
            }
            else{
                tabs++;
                match(TokenType::ID);
                tabs--;
                PRINT();
            }
            tabs--;
        }
        else if(look.tokenType==TokenType::STR){
            tabs++;
            match(TokenType::STR);
            // cout << "STR";
            PRINT();
            tabs--;
        }
        else if(look.tokenType==TokenType::NUM){
            tabs++;
            token check=_lexer.peek(_lexer.getCurrentPointer()+1);
            if((check).tokenType==TokenType::AO){
                EXP();
            }
            else{
                match(TokenType::NUM);
                PRINT();
            }
            tabs--;
        }
        else
            syntax_error();
        tabs--;
        tabs--;
    }
    else
        syntax_error();
    tabs--;
    
}



void parser::CIN(){
    printTabs();
    cout << "CIN" << endl;
    tabs++;
    if(look.tokenType==TokenType::KEY){
        if(look.lexeme=="lo"){
            // printToken();
            // tabs++;
            // tabs--;
            match("lo");
            // tabs++;
            // look=expect(TokenType::IO);
            // look=_lexer.getNextToken();
            if(look.lexeme=="<<"){
                // tabs++;
                // tabs--;
                match("<<");
                // cout << "<<";
                if(look.tokenType==TokenType::ID){
                    tabs++;
                    match(TokenType::ID);
                    tabs--;
                    match(">>");
                    tabs++;
                    match(TokenType::ID);
                    tabs--;
                    if(look.lexeme=="@"){
                        // tabs++;
                        match("@");
                        if(look.lexeme=="adad"){
                            // cout << look.lexeme <<endl;
                            // tabs++;
                            match("adad");   
                            // tabs--;
                            // match(";");
                        }
                        else if(look.lexeme=="khali"){
                            // tabs++;
                            match("khali");
                            // tabs--;
                        }
                        else
                            syntax_error();
                        // tabs--;
                    }
                    // tabs++;
                    match(";");
                    // tabs--;
                    // tabs--;
                    // tabs--;
                    // tabs--;
                }
                else if(look.tokenType==TokenType::STR){
                    // tabs++;
                    match(TokenType::STR);
                    // tabs++;
                    match(">>");
                    tabs++;
                    match(TokenType::ID);
                    tabs--;
                    if(look.lexeme=="@"){
                        // tabs++;
                        match("@");
                        if(look.lexeme=="adad"){
                            // cout << look.lexeme <<endl;
                            // tabs++;
                            match("adad");   
                            // tabs--;
                        }
                        else if(look.lexeme=="khali"){
                            // tabs++;
                            match("khali");
                            // tabs--;
                            // match(";");
                        }
                        else
                            syntax_error();
                        tabs--;
                    }
                    // tabs++;
                    match(";");
                    // tabs--;
                    // tabs--;
                    // tabs--;
                    // tabs--;
                }
                else if(look.tokenType==TokenType::NUM){
                    // tabs--;
                    tabs++;
                    match(TokenType::NUM);
                    tabs--;
                    match(">>");
                    tabs++;
                    match(TokenType::ID);
                    tabs--;
                    if(look.lexeme=="@"){
                        match("@");
                        if(look.lexeme=="adad"){
                            // cout << look.lexeme <<endl;
                            // tabs++;
                            match("adad");   
                            // tabs--;
                            // match(";");
                        }
                        else if(look.lexeme=="khali"){
                            // tabs++;
                            match("khali");
                            // tabs--;
                        }
                        else
                            syntax_error();
                    }
                    // tabs++;
                    match(";");
                    // tabs--;
                    // tabs--;
                    // tabs--;
                    // tabs--;

                }
                else
                    syntax_error();
                // tabs++;
                // tabs--;
                
            }
            else if(look.lexeme==">>"){
                // cout << ">>";
                // tabs++;
                match(">>");
                tabs++;
                match(TokenType::ID);
                tabs--;
                if(look.lexeme=="@"){
                    // tabs++;
                    match("@");
                    if(look.lexeme=="adad"){
                        // cout << look.lexeme <<endl;
                        // tabs++;
                        match("adad");   
                        // tabs--;
                        // match(";");
                    }
                    else if(look.lexeme=="khali"){
                        // tabs++;
                        match("khali");
                        // tabs--;
                    }
                    else
                        syntax_error();
                    // tabs--;
                }
                // tabs++;
                match(";");
                // tabs--;
                // tabs--;
                // tabs--;
            }
            else
                syntax_error();
            // tabs--;
        }
    }
    tabs--;
}

// EXP -> TR
void parser::EXP(){
    printTabs();
    cout << "EXP" << endl;
    tabs++;
    T();
    R();
    tabs--;
}
// R -> +EXP R 
// R -> -EXP R
// R-> ^
void parser::R(){
    printTabs();
    cout << "R"<< endl;
    tabs++;
    if(look.lexeme=="+"){
        match("+");
        tabs++;
        EXP();
        R();
        tabs--;
    }
    else if(look.lexeme=="-"){
        match("-");
        tabs++;
        EXP();
        R();
        tabs--;
    }
    tabs--;
}
// T -> F Q
void parser::T(){
    printTabs();
    cout << "T"<< endl;
    tabs++;
    F();
    Q();
    tabs--;
}
// Q -> * T Q
// Q -> / T Q
// Q -> % T Q
// Q -> ^
void parser::Q(){
    printTabs();
    cout << "Q"<< endl;
    tabs++;
    if(look.lexeme=="*"){
        match("*");
        tabs++;
        T();
        Q();
        tabs--;
    }
    else if(look.lexeme=="/"){
        match("/");
        tabs++;
        T();
        Q();
        tabs--;
    }
    else if(look.lexeme=="%"){
        match("%");
        tabs++;
        T();
        Q();
        tabs--;
    }
    tabs--;
}
// F -> id
// F -> Num
// F -> (E)

void parser::F(){
    printTabs();
    cout << "F" << endl;
    tabs++;
    if(look.tokenType==TokenType::ID){
        tabs++;
        match(TokenType::ID);
        tabs--;
    }
    else if(look.tokenType==TokenType::NUM){
        tabs++;
        match(TokenType::NUM);
        tabs--;
    }
    else if(look.tokenType==TokenType::SB){
        match(TokenType::SB);
        tabs++;
        EXP();
        tabs--;
        match(TokenType::CB);
    }
    else
        syntax_error();
    tabs--;
}





void parser::REXP(){
    printTabs();
    cout << "REXP" << endl;
    tabs++;
    if(look.tokenType==TokenType::ID){
        int index=_lexer.getCurrentPointer();
        token check=_lexer.getNextToken();
        if(check.tokenType==TokenType::AO){
            _lexer.setCurrentPointer(index);
            EXP();
        }
        else{
            _lexer.setCurrentPointer(index);
            tabs++;
            match(TokenType::ID);
            tabs--;
        }
    }
    else if(look.tokenType==TokenType::NUM){
        int index=_lexer.getCurrentPointer();
        token check=_lexer.getNextToken();
        if(check.tokenType==TokenType::AO){
            _lexer.setCurrentPointer(index);
            EXP();
        }
        else{
            _lexer.setCurrentPointer(index);
            tabs++;
            match(TokenType::NUM);
            tabs--;
        }
    }
    if (look.tokenType==TokenType::RO)
    {
        // tabs++;
        match(TokenType::RO);
        // tabs--;
    }
    else
        syntax_error();
    if(look.tokenType==TokenType::ID){
        int index=_lexer.getCurrentPointer();
        token check=_lexer.getNextToken();
        if(check.tokenType==TokenType::AO){
            _lexer.setCurrentPointer(index);
            EXP();
        }
        else{
            _lexer.setCurrentPointer(index);
            tabs++;
            match(TokenType::ID);
            tabs--;
        }
    }
    else if(look.tokenType==TokenType::NUM){
        int index=_lexer.getCurrentPointer();
        token check=_lexer.getNextToken();
        if(check.tokenType==TokenType::AO){
            _lexer.setCurrentPointer(index);
            EXP();
        }
        else{
            _lexer.setCurrentPointer(index);
            tabs++;
            match(TokenType::NUM);
            tabs--;
        }
    }
    tabs--;
}



void parser::CALLFUNC(){
    printTabs();
    cout << "CALLFUNC" << endl;
    tabs++;
    if(look.lexeme=="chalao"){
        match("chalao");
        tabs++;
        match(TokenType::ID);
        tabs--;
        match("(");
        if(look.tokenType==TokenType::ID){
            tabs++;
            match(TokenType::ID);
            tabs--;
            ARGS();
        }
        else if(look.tokenType==TokenType::NUM){
            tabs++;
            match(TokenType::NUM);
            tabs--;
            ARGS();
        }
        else if(look.lexeme=="chalao"){
            CALLFUNC();
        }
        else
            syntax_error();
        ARGS();
        match(")");
    }
    tabs--;
}

void parser::LOOP(){
    printTabs();
    cout << "LOOP" << endl;
    tabs++;
    if(look.lexeme=="jab"){
        // tabs++;
        match("jab");
        // tabs++;
        match("tak");
        // tabs++;
        match(TokenType::SB);
        REXP();
        // tabs++;
        match(TokenType::CB);
        // tabs++;
        match("karo");
        while(look.lexeme!="bas"){
            STATEMENTS();
        }
        // tabs++;
        match("bas");
        // tabs++;
        match("karo");
        // tabs--;
        // tabs--;
        // tabs--;
        // tabs--;
        // tabs--;
        // tabs--;
        // tabs--;
    }
    else
        syntax_error();
    tabs--;
}

void parser::ARGS(){
    printTabs();
    cout << "ARGS" << endl;
    tabs++;
    if(look.lexeme=="|"){
        match("|");
        if(look.tokenType==TokenType::ID){
            tabs++;
            match(TokenType::ID);
            tabs--;
            ARGS();
        }
        else if(look.tokenType==TokenType::NUM){
            tabs++;
            match(TokenType::NUM);
            tabs--;
            ARGS();
        }
        else if(look.lexeme=="chalao"){
            CALLFUNC();
        }
        else
            syntax_error();
    }
    tabs--;
}

void parser::ASSIGN(){
    printTabs();
    cout << "ASSIGN" << endl;
    tabs++;
    if(look.lexeme=="@"){
        match("@");
        // if(look.lexeme=="khali"){
        //     match("khali");
        //     if(look.lexeme==":="){
        //         match(":=");
        //         if(look.tokenType==TokenType::ID){
        //             tabs++;
        //             match(TokenType::ID);
        //             tabs--;
        //         }
        //         else if(look.tokenType==TokenType::NUM){
        //             tabs++;
        //             match(TokenType::NUM);
        //             tabs--;
        //         }
        //         else if(look.lexeme=="chalao"){
        //             CALLFUNC();
        //         }
        //         else 
        //             syntax_error();
        //     }
        // }
        // else 
        if(look.lexeme=="adad"){
            match("adad");
            if(look.lexeme==":="){
                match(":=");
                if(look.tokenType==TokenType::ID){
                    int index=_lexer.getCurrentPointer();
                    token check=_lexer.getNextToken();
                    if(check.tokenType==TokenType::AO){
                        _lexer.setCurrentPointer(index);
                        EXP();
                    }
                    else{
                        _lexer.setCurrentPointer(index);
                        tabs++;
                        match(TokenType::ID);
                        tabs--;
                    }
                }
                else if(look.tokenType==TokenType::NUM){
                    int index=_lexer.getCurrentPointer();
                    token check=_lexer.getNextToken();
                    if(check.tokenType==TokenType::AO){
                        _lexer.setCurrentPointer(index);
                        EXP();
                    }
                    else{
                        _lexer.setCurrentPointer(index);
                        tabs++;
                        match(TokenType::NUM);
                        tabs--;
                    }
                }
                else if(look.lexeme=="chalao"){
                    CALLFUNC();
                    match(";");
                }
                else 
                    syntax_error();
            }
        }
    }
    else if(look.lexeme==":="){
        match(":=");
        if(look.tokenType==TokenType::ID){
            int index=_lexer.getCurrentPointer();
            token check=_lexer.getNextToken();
            if(check.tokenType==TokenType::AO){
                _lexer.setCurrentPointer(index);
                EXP();
                match(";");
            }
            else{
                _lexer.setCurrentPointer(index);
                tabs++;
                match(TokenType::ID);
                tabs--;
                match(";");
            }
        }
        else if(look.tokenType==TokenType::NUM){
            int index=_lexer.getCurrentPointer();
            token check=_lexer.getNextToken();
            if(check.tokenType==TokenType::AO){
                _lexer.setCurrentPointer(index);
                EXP();
                match(";");
            }
            else{
                _lexer.setCurrentPointer(index);
                tabs++;
                match(TokenType::NUM);
                tabs--;
                match(";");
            }
        }
        else if(look.lexeme=="chalao"){
            CALLFUNC();
            match(";");
        }
        else 
            syntax_error();

    }
    else
        syntax_error();
    tabs--;
}

void parser::VARIABLE(){
    printTabs();
    cout << "VARIABLE" << endl;
    tabs++;
    if(look.lexeme=="rakho"){
        match("rakho");
        tabs++;
        int index=_lexer.getCurrentPointer();
        token check=_lexer.getNextToken();
        _lexer.setCurrentPointer(index);
        match(TokenType::ID);
        addr+=4;
        // fout.write(check.lexeme);
        // fout.out(check.lexeme);
        tabs--;
        ASSIGN();

    }
    tabs--;
}

void parser::ELSEIF(){
    printTabs();
    cout << "ELSEIF" << endl;
    tabs++;
    match("warna");
    match("agar");
    match(TokenType::SB);
    REXP();
    match(TokenType::CB);
    match("to");
    match("phir");
    while(look.lexeme!="bas" && look.lexeme!="warna")
    {
        STATEMENTS();
    }
    // look.Print();
    if(look.lexeme=="warna"){
        // match("warna");
        int index=_lexer.getCurrentPointer();
        token check=_lexer.getNextToken();
        if(check.lexeme=="agar")
        {
            _lexer.setCurrentPointer(index);
            ELSEIF();
        }
        else if(check.lexeme=="phir"){
            _lexer.setCurrentPointer(index);
            ELSE();
        }
    }
    else if(look.lexeme=="bas"){
        match("bas");
        match("karo");
    }
    
    tabs--;
}
void parser::ELSE(){
    printTabs();
    cout << "ELSE" << endl;
    tabs++;
    match("warna");
    match("phir");
    while(look.lexeme!="bas")
        STATEMENTS();
    match("bas");
    match("karo");
    tabs--;
}

void parser::IF(){
    printTabs();
    cout << "IF" << endl;
    tabs++;
    if(look.lexeme=="agar"){
        match("agar");
        match(TokenType::SB);
        REXP();
        match(TokenType::CB);
        match("to");
        match("phir");
        match("karo");
        while(look.lexeme!="bas" && look.lexeme!="warna")
        {
            STATEMENTS();
            // look.Print();
        }
        // look.Print();
        if(look.lexeme=="warna"){
            // match("warna");
            int index=_lexer.getCurrentPointer();
            token check=_lexer.getNextToken();
            if(check.lexeme=="agar")
            {
                _lexer.setCurrentPointer(index);
                ELSEIF();
            }
            else if(check.lexeme=="phir"){
                _lexer.setCurrentPointer(index);
                ELSE();
            }
            else
                syntax_error();
        }
        else if(look.lexeme=="bas"){
            match("bas");
            match("karo");
        }
    }
    tabs--;
}


void parser::RETURN(){
    printTabs();
    tabs++;
    cout << "RETURN" << endl;
    match("wapas");
    match("bhaijo");
    if(look.tokenType==TokenType::ID){
        tabs++;
        match(TokenType::ID);
        tabs--;
        match(";");
    }
    else if(look.tokenType==TokenType::NUM){
        tabs++;
        match(TokenType::NUM);
        tabs--;
        match(";");
    }
    else
        syntax_error();
    // match(";");
    tabs--;
}

void parser::FUNCARGS(){
    printTabs();
    cout << "FUNCARGS" << endl;
    tabs++;
    if(look.lexeme=="|"){
        match("|");
        match(TokenType::ID);
        match("@");
        match("adad");
        FUNCARGS();
    }
    tabs--;
}

void parser::FUNCARG(){
    printTabs();
    cout << "FUNCARG" << endl;
    tabs++;
    if(look.tokenType==TokenType::ID){
        match(TokenType::ID);
        match("@");
        match("adad");
        if(look.lexeme=="|"){
            FUNCARGS();
        }
    }
    tabs--;
}

void parser::FUNCTION(){
    printTabs();
    cout << "FUNCTION" << endl;
    tabs++;
    match("kaam");
    look.Print();
    
    // look.Print();
    if (look.tokenType==TokenType::ID){
        int index=_lexer.getCurrentPointer();
        token check=_lexer.getNextToken();
        _lexer.setCurrentPointer(index);
        match(TokenType::ID);
        // fout.write(check.lexeme);
        // fout.out(check.lexeme);
        match("@");
        if(look.lexeme=="adad"){
            match("adad");
            match(TokenType::SB);
            FUNCARG();
            match(TokenType::CB);
            while(look.lexeme!="kaam"){
                STATEMENTS();
            }
            match("kaam");
            match("khatam");
        }
        else if(look.lexeme=="khali"){
            match("khali");
            match(TokenType::SB);
            FUNCARG();
            match(TokenType::CB);
            match("karo");
            while(look.lexeme!="kaam"){
                STATEMENTS();
            }
            match("kaam");
            match("khatam");
        }
        else
            syntax_error();
    }
    else if(look.tokenType==TokenType::KEY){
        match("markazi");
        match("@");
        // fout.write(check.lexeme);
        if(look.lexeme=="adad"){
            match("adad");
            match(TokenType::SB);
            match(TokenType::CB);
            while(look.lexeme!="kaam"){
                STATEMENTS();
            }
            match("kaam");
            match("khatam");
        }
        else if(look.lexeme=="khali"){
            match("khali");
            match(TokenType::SB);
            match(TokenType::CB);
            match("karo");
            while(look.lexeme!="kaam"){
                STATEMENTS();
            }
            match("kaam");
            match("khatam");
        }
        else
            syntax_error();
    }
    
    tabs--;
}

void parser::STATEMENTS(){
    if(look.tokenType==TokenType::KEY)
    {
        if(look.lexeme=="dekhao"){
            COUT();
        }
        else if(look.lexeme=="lo"){
            CIN();
        }
        else if(look.lexeme=="rakho"){
            VARIABLE();
        }
        else if(look.lexeme=="jab"){
            LOOP();
        }
        else if(look.lexeme=="chalao"){
            CALLFUNC();
        }
        else if(look.lexeme=="wapas"){
            RETURN();
        }
        else if(look.lexeme=="agar"){
            IF();
        }
        else if(look.lexeme=="kaam"){
            FUNCTION();
        }
        else{
            // EXP();
            // look.Print();
            look = _lexer.getNextToken();
            // look.Print();
        }

        
        //     // break;
    }
    else
    {
        // look.Print();
        look=_lexer.getNextToken();
        // look.Print();
    }
        // EXP();
    // tabs--;
}

void parser::readAndPrintAllInput() //read and print allinputs (provided)
{
    // token t;
    look = _lexer.getNextToken();
    // cout << _lexer.getCurrentPointer();
    while (look.tokenType != TokenType::END_OF_FILE)
    {
        STATEMENTS();
        // look.Print();
        // look = _lexer.getNextToken();
    }
}
void parser::resetPointer()
{
    _lexer.resetPointer();
}
//this function is for sample purposes only
/*
bool parser::statements()
{
    //statements-- > COLON LPAREN start RPAREN
    if (_lexer.peek(1).tokenType == TokenType::COLON)
    {
        expect(TokenType::COLON);
        if (_lexer.peek(1).tokenType == TokenType::LPAREN)
        {
            expect(TokenType::LPAREN);
            start();
            if (_lexer.peek(1).tokenType == TokenType::RPAREN)
            {
                expect(TokenType::RPAREN);
                return true;
            }
        }
    }
    return false;
}*/ 