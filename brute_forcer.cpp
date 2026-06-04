#include <iostream>
#include <vector>
#include <unordered_set>

const int PLAYER_WIN = 0;
const int TIE = 1;
const int BANKER_WIN = 2;

int compare_values(int v1, int v2) {
    if (v1 > v2) return PLAYER_WIN;
    else if (v1 == v2) return TIE;
    else if (v1 < v2) return BANKER_WIN;
}

int game_instance(int c1, int c2, int c3, int c4, int c5, int c6) {
    int player_hand_value = (c1+c2)%10;
    int banker_hand_value = (c3+c4)%10;
    if (player_hand_value >= 8 || banker_hand_value >= 8) return compare_values(player_hand_value, banker_hand_value);
    else if (player_hand_value >= 6) {
        if (banker_hand_value >= 6) return compare_values(player_hand_value, banker_hand_value);
        else return compare_values(player_hand_value, (banker_hand_value + c6)%10);
    }
    else if (player_hand_value<6) {
        bool banker_draws = false;
        switch (banker_hand_value)
        {
        case 0:
        case 1:
        case 2:
            banker_draws = true;
            break;
        case 3:
            if (c5 != 8) banker_draws = true;
            break;
        case 4:
            if (2 <= c5 && c5 <= 7) banker_draws = true;
            break;
        case 5:
            if (4 <= c5 && c5 <= 7) banker_draws = true;
            break;
        case 6:
            if (6 <= c5 && c5 <= 7) banker_draws = true;
            break;
        }
        if (banker_draws) return compare_values((player_hand_value + c5) % 10, (banker_hand_value + c6) % 10);
        else return compare_values((player_hand_value + c5) % 10, (banker_hand_value + c6) % 10);
    }

}

int compute_odds() {
    std::vector<int> deck = {
        1, 1, 1, 1,
        2, 2, 2, 2,
        3, 3, 3, 3,
        4, 4, 4, 4,
        5, 5, 5, 5,
        6, 6, 6, 6,
        7, 7, 7, 7,
        8, 8, 8, 8,
        9, 9, 9, 9,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
    };

    int num_pw = 0;
    int num_bw = 0;
    int num_tie = 0;
    int num_games = 0;

    for (int i1 = 0; i1 < 52; i1++) {
    for (int i2 = 0; i2 < 52; i2++) {
    if (i2 == i1) continue;
    std::cout<<i1<<" "<<i2<<std::endl;
    for (int i3 = 0; i3 < 52; i3++) {
    if (i3 == i1) continue;
    if (i3 == i2) continue;
    for (int i4 = 0; i4 < 52; i4++) {
    if (i4 == i1) continue;
    if (i4 == i2) continue;
    if (i4 == i3) continue;
    for (int i5 = 0; i5 < 52; i5++) {
    if (i5 == i1) continue;
    if (i5 == i2) continue;
    if (i5 == i3) continue;
    if (i5 == i4) continue;
    for (int i6 = 0; i6 < 52; i6++) {
    if (i6 == i1) continue;
    if (i6 == i2) continue;
    if (i6 == i3) continue;
    if (i6 == i4) continue;
    if (i6 == i5) continue;
    
    int outcome = game_instance(deck[i1], deck[i2], deck[i3], deck[i4], deck[i5], deck[i6]);
    switch (outcome)
    {
    case PLAYER_WIN:
        num_pw += 1;
        break;
    case TIE:
        num_tie += 1;
        break;
    case BANKER_WIN:
        num_bw += 1;
        break;
    }
    num_games += 1;
    }}}}}}
    std::cout<<num_pw<<" "<<num_bw<<" "<<num_tie<<" "<<num_games;
    return 0;
}

int main() {
    compute_odds();
}