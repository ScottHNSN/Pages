#ifndef PFRAME_H
#define PFRAME_H
#include <vector>
#include <any>
#include "POwnerTree.h"
class PFrame { /* >>> Metadata holder for pages <<< */
public:
    class PSetting {
    public:

        /* >>> every PFrame will hold a vector of PSettings which will be given by PParser and built into a page by PPuilder */
        /* PSettings are defined by two things: the enum  for the keyword and a vector of enum modifiers and pointers to PNode tree variables
         * variables will be refrenced as a pointer to their address in the PNode tree. PParser will handle this and bla bal bla im gonna start wriing */
    private:

        std::vector<std::any> variables;
        enum modifier { // we'll keep it clean and simple for now: no modifiers

        };
        PNode<PFrame>* holder; // how this is supposed to work is that for these settings of course there are settings for other pages like gesture area on one page which trigger another, so it will need to hold pointer to a PNode which it can help PBuilder refer to at runtime, so it can't just hold itself by default. there are tokens, for the parser, and PSettings for the builder. as easy as that
        std::vector<modifier> modifierlist;
public:
  enum keyword {
    MAX_SIZE,
    MIN_SIZE,
    GESTUREAREA,
    GESTUREANIMATION,

  };
        void GivePSetting(keyword givenkeyword, std::vector<modifier> givenmodifierlist, PNode<PFrame>* givenholder = nullptr, std::vector<std::any> givenvariables) {
            appliedkeyword = givenkeyword;
            modifierlist = givenmodifierlist;
            holder = givenholder;
            variables = givenvariables;
    }
    keyword appliedkeyword;

        };
        PFrame() {

        }
        PSetting* NodePSetting = new PSetting;

};
#endif // PDIRECTOR_H

