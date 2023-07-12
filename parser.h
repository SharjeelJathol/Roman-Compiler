#ifndef _PARSER_H_
#define _PARSER_H_
#include "lexer.h"
//for future assignments leave it as it is
class parser
{
    lexer _lexer;
public:
    void syntax_error();
    token expect(TokenType expected_type);
    parser(const char filename[]);
    void readAndPrintAllInput();
    void resetPointer();
    void EXP();
    void LOOP();
    void FUNCTION();
    void FUNCARG();
    void FUNCARGS();
    void STATEMENTS();
    void CALLFUNC();
    void VARIABLE();
    void ASSIGN();
    void ARGS();
    void IF();
    void ELSEIF();
    void ELSE();
    void RETURN();
    void F();
    void Q();
    void T();
    void R();
    void REXP();
    void COUT();
    void CIN();
    void PRINT();
    void match(string tok);
    void match(TokenType token);
    /*Terminal functions goes here use peek and expect*/
    /*use TokenType:: for token names for example
        expect(TokenType::ASSIGN);   //example function call
      */
	//all your parser function goes here
};
#endif
