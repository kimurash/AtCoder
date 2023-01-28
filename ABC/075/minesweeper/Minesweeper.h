#ifndef ___Minesweeper
#define ___Minesweeper

#include <bits/stdc++.h>

class Minesweeper{
private:
    int height;
    int width;
    std::vector<std::string> field;
    // std::vector<std::vector<int>> count;
public:
    Minesweeper(int H, int W);
    ~Minesweeper();

    void count_bomb(int i, int j);
    bool is_bomb(int i, int j) const;
};

#endif