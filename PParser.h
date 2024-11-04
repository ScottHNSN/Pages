#ifndef PPARSER_H
#define PPARSER_H
#include "PDirector.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <variant>
#include "POwnerTree.h"
#include "PFrame.h"
#include <algorithm>
class PParser : public PDirector { /* >>> Parser agent for PageConfig.txt files <<< */
public:
    PNode<PFrame>* PageRoot = nullptr;
    enum tokentype {
        SET,
        LEFT_BRACE,
        RIGHT_BRACE,
        LEFT_PARANTHESE,
        RIGHT_PARANTHESE,
        START_PTREE,
        END_PTREE
        };

        class token {
        public:
            token(std::string SubjectObject) {
                if (SubjectObject == "set") {
                    *tokenreferral = tokentype::SET;
                } else if (SubjectObject == "{") {
                    stringreferral = nullptr;
                    *tokenreferral = tokentype::LEFT_BRACE;
                } else if (SubjectObject == "}") {
                    stringreferral = nullptr;
                    *tokenreferral = tokentype::RIGHT_BRACE;
                } else if (SubjectObject == "(") {
                    stringreferral = nullptr;
                    *tokenreferral = tokentype::LEFT_BRACE;
                } else if (SubjectObject == ")") {
                    stringreferral = nullptr;
                    *tokenreferral = tokentype::RIGHT_BRACE;
                } else if (SubjectObject == "PageTree:") {
                    stringreferral = nullptr;
                    *tokenreferral = tokentype::START_PTREE;
                } else if (SubjectObject == "EndPageTree") {
                    stringreferral == nullptr;
                    *tokenreferral = tokentype::END_PTREE;
                }
                else {
                    tokenreferral = nullptr;
                    *stringreferral = SubjectObject;
                }
            }
                std::variant<std::string, tokentype> ReturnToken() {
                    if(stringreferral == nullptr) {
                      return *tokenreferral;
                    } else if (tokenreferral == nullptr) {
                        return *stringreferral;
                    } else {
                        throw std::invalid_argument("Invalid Argument");
                    }
                }
        private:
            std::string *stringreferral = new std::string("");
            tokentype *tokenreferral = new tokentype;
        };

    std::string ReturnSentence(std::fstream* filesubject) {
        std::string getlinebuffer;
        std::getline(*filesubject, getlinebuffer);
        return getlinebuffer;
    }
        void PopulateTokenList(std::string SubjectSentence, std::vector<token> *SubjectTokenArray) {
        int sentencelength = SubjectSentence.length();
        std::string stringbfr("");
        for (int currentchar; currentchar < sentencelength; currentchar++) {
            if (SubjectSentence[currentchar] != ' ') {
            stringbfr.push_back(SubjectSentence[currentchar]);
            } else {
                token *tokenbfr = new token(stringbfr);
                SubjectTokenArray->push_back(*tokenbfr);
                delete tokenbfr;
            }
        }
    }
        void PopulatePTree(std::vector<token> *Tokens, PNode<PFrame>* currentparent) { // every token is a PTree until definition ends
            for (int linenumber, Tokens->at(linenumber).ReturnToken() != std::variant<std::string, tokentype>(tokentype::END_PTREE)) {
            if (Tokens->at(1).ReturnToken() == std::variant<std::string, tokentype>()) {
            PNode<PFrame>* CurrentNode= currentparent->AddChild();
                }
            }
        }
        void ParseTokens(std::vector<token> *TokensOfSentence, PNode<PFrame>* RootOf) {
            // parsetokens creates a Psetting object for a Pframe and assigns it to the PFrame. special tokens are PageTree:, EndPageTree
            if (RootOf = nullptr) {

            RootOf = new PNode<PFrame>;
            }                                   // every decleration begins with a keyword
            // fwcccccccccccccccccccccccccccccccccirst token should always be keyword
            if (TokensOfSentence->at(1)  == ) {}
            for (int i = 2; i < TokensOfSentence->size(); i++) { //parse: go into the the toiken handler if token, go into the unique expression / file handler/ creator/adder to tree / should check first is



            }
        }
        void StartParsing(){
            int CrtLineNr = 1;
            std::fstream PageConfigFile("");
            int Linecount = std::count(std::istreambuf_iterator<char>(PageConfigFile), std::istreambuf_iterator<char>(), '\n');

            PNode<PFrame>* CurrentPRTPointer = nullptr;
            std::string sentence;
            std::vector<token>*  SubjectSentence;
            for (CrtLineNr = 1; CrtLineNr < Linecount; CrtLineNr++) {

            sentence = ReturnSentence(&PageConfigFile);
            SubjectSentence = new std::vector<token>;
            PopulateTokenList(sentence, SubjectSentence);

            if (SubjectSentence->at(1).ReturnToken() == std::variant<std::string, tokentype>(tokentype::START_PTREE)) {
                PopulatePTree(SubjectSentence, CurrentPRTPointer);
                SubjectSentence = nullptr;
            } else {
                throw "error";
            }
            ParseTokens(SubjectSentence, PageRoot);
            delete SubjectSentence;
        }
    };



#endif // PPARSER_H
