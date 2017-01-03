// leetcode-79-212-查找单词.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
  public:
    bool exist(vector<vector<char> > &board, string word) {
		m=board.size();
    	n=board[0].size();
        for(int x=0;x<m;x++)
            for(int y=0;y<n;y++)
            {
    			if(isFound(board,word.c_str(),x,y))
    				return true;
            }
            return false;
    }
    private:
    	int m;
    	int n;
        bool isFound(vector<vector<char> > &board, const char* w, int x, int y)
        {
    		if(x<0||y<0||x>=m||y>=n||board[x][y]=='\0'||*w!=board[x][y])
    			return false;
            if(*(w+1)=='\0')
                return true;
    		char t=board[x][y];
    		board[x][y]='\0';
    		if(isFound(board,w+1,x-1,y)||isFound(board,w+1,x+1,y)||isFound(board,w+1,x,y-1)||isFound(board,w+1,x,y+1))
    			return true; 
    		board[x][y]=t;
            return false;
     }
};
// word search 2
class TrieNode
{
public:
	bool is_end;
    vector<TrieNode*> children;
    TrieNode(){
        is_end=false;
        children=vector<TrieNode*>(26, NULL);
    }
};
class Trie
{
public:
	TrieNode* root;
	TrieNode* getRoot()
	{
		return root;
	}
	Trie(vector<string>& words){
        root=new TrieNode();
        for(int i=0; i<words.size(); ++i)
            addWord(words[i]);
    }
	void addWord(const string& word){
        TrieNode* cur=root;
        for(int i=0; i<word.size(); ++i){
            int index=word[i]-'a';
            if(cur->children[index]==NULL)   
               cur->children[index]=new TrieNode();
            cur=cur->children[index];    
        }
        cur->is_end=true;
    }
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie(words);
        TrieNode* root=trie->getRoot();
		set<string> result_set;
		for(int x=0; x<board.size(); ++x)
            for(int y=0; y<board[0].size(); ++y)
                findWords(board, x, y, root, "", result_set);
		vector<string> result;
        for(auto it:result_set)    result.push_back(it);
        return result;
    }
	void findWords(vector<vector<char>>& board, int x, int y, TrieNode* root, string word, set<string>& result){
        if(x<0||x>=board.size()||y<0||y>=board[0].size() || board[x][y]==' ') return;
        
        if(root->children[board[x][y]-'a'] != NULL){
            word=word+board[x][y];
            root=root->children[board[x][y]-'a']; 
            if(root->is_end) result.insert(word);
            char c=board[x][y];
            board[x][y]=' ';
            findWords(board, x+1, y, root, word, result);
            findWords(board, x-1, y, root, word, result);
            findWords(board, x, y+1, root, word, result);
            findWords(board, x, y-1, root, word, result);
            board[x][y]=c;        
        }
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

