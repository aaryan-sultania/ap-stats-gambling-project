#include "baccarat.h"

int compare_values(int v1, int v2) {
    if (v1 > v2) return PLAYER_WIN;
    else if (v1 == v2) return TIE;
    else if (v1 < v2) return BANKER_WIN;
    else return 3;
}

int game_instance(int c1, int c2, int c3, int c4, int c5, int c6) {
    int player_2_card_hand_value = (c1+c2)%10;
    int banker_2_card_hand_value = (c3+c4)%10;
    int player_3_card_hand_value = (c1+c2+c5)%10;
    int banker_3_card_hand_value = (c3+c4+c6)%10;
    if (player_2_card_hand_value >= 8 || banker_2_card_hand_value >= 8) return compare_values(player_2_card_hand_value, banker_2_card_hand_value);
    else if (player_2_card_hand_value >= 6) {
        if (banker_2_card_hand_value >= 6) return compare_values(player_2_card_hand_value, banker_2_card_hand_value);
        else return compare_values(player_2_card_hand_value, banker_3_card_hand_value);
    }
    else { // if (player_2_card_hand_value <= 5)
        bool banker_draws = false;
        switch (banker_2_card_hand_value)
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
        if (banker_draws) return compare_values(player_3_card_hand_value, banker_3_card_hand_value);
        else return compare_values(player_3_card_hand_value, banker_2_card_hand_value);
    }
}