/*
    # Trie
        => Trie data structure is same like a tree but node can have maximum of n child.
        => Application:
            *) To implement Dictionamry
                -> Store word
                -> search word in O(word-length)
                -> remove word
            *) Finding prefix string
*/

#include <iostream>
#include <stdio.h>
using namespace std;

// For creating the Dictionary
struct TrieNode
{
    char data;
    TrieNode *child[26];
    // here atleast 26 child in this example because we are trying to create a dictionary
    int wordEnd;
    // wordEnd will keep count of which of the word are ending in the current position
};

int main()
{

    return 0;
}