#include <string>

// note
/* 0 : 움직일 수 있는 공간 -> " " 빈 문자열
   1 : 가로 벽 -> "-"
   2 : Gate가 될 수 없는 벽 (Immune Wall) -> "X"
   3 : Snake head -> "@"
   4 : Snake body -> "w"
   5 : Growth Item -> 하트 유니코드 ♥ "\u2665"
   6 : Poison Item -> 별 유니코드 ★ "\u2605"
   7 : Gate -> "#"
   8 : 세로 벽 -> "|"
*/

std::string stage1[] =
{
    "2111111111111111111111112",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "2111111111111111111111112"
};

std::string stage2[] =
{
    "1111111111111111111111112",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000011111110008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000111111100000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "2111111111111111111111112"
};

std::string stage3[] =
{
    "2111111111111111111111112",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000008000000000000008",
    "8000000008000000000000008",
    "8000000008000000000000008",
    "8000000008000000000000008",
    "8000000001111111000000008",
    "8000000000000008000000008",
    "8000000000000008000000008",
    "8000000000000008000000008",
    "8000000000000008000000008",
    "8000000000000008000000008",
    "8000000000000008000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "2111111111111111111111111"
};

std::string stage4[] =
{
    "2111111111111111111111112",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000800008",
    "8000011111000000000800008",
    "8000000000000000000800008",
    "8000000000000000000800008",
    "8000000000000000000800008",
    "8000000000000000000800008",
    "8000000000000000000800008",
    "8000001111110000000800008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000800000000000000008",
    "8000000800000000000000008",
    "8000000800000000000000008",
    "8000000800000000000000008",
    "8000000800000011110000008",
    "8000000800000000000000008",
    "8000000800000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "8000000000000000000000008",
    "2111111111111111111111112"
};