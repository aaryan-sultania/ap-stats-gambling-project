#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "baccarat.h"

void calc_player_tie_banker_odds() {
    std::vector<double> shoe = {16, 4, 4, 4, 4, 4, 4, 4, 4, 4};
    double player_win_prob = 0;
    double banker_win_prob = 0;
    double tie_prob = 0;

    for (int i1 = 0; i1 < 10; i1++) {
    for (int i2 = 0; i2 < 10; i2++) {
    for (int i3 = 0; i3 < 10; i3++) {
    for (int i4 = 0; i4 < 10; i4++) {
    for (int i5 = 0; i5 < 10; i5++) {
    for (int i6 = 0; i6 < 10; i6++) {
    
    int outcome = game_instance(i1, i2, i3, i4, i5 , i6);
    std::vector<double> shoe_copy = shoe;
    double probability = shoe[i1] / std::accumulate(shoe.begin(), shoe.end(), 0);
    shoe_copy[i1] -= 1;
    probability *= shoe_copy[i2] / std::accumulate(shoe_copy.begin(), shoe_copy.end(), 0);
    shoe_copy[i2] -= 1;
    probability *= shoe_copy[i3] / std::accumulate(shoe_copy.begin(), shoe_copy.end(), 0);
    shoe_copy[i3] -= 1;
    probability *= shoe_copy[i4] / std::accumulate(shoe_copy.begin(), shoe_copy.end(), 0);
    shoe_copy[i4] -= 1;
    probability *= shoe_copy[i5] / std::accumulate(shoe_copy.begin(), shoe_copy.end(), 0);
    shoe_copy[i5] -= 1;
    probability *= shoe_copy[i6] / std::accumulate(shoe_copy.begin(), shoe_copy.end(), 0);
    shoe_copy[i6] -= 1; 
    switch (outcome)
    {
    case PLAYER_WIN:
        player_win_prob += probability;
        break;
    case BANKER_WIN:
        banker_win_prob += probability;
        break;
    case TIE:
        tie_prob += probability;
        break;
    }

    }}}}}}
    std::cout<<"Player Win Probabitliy: "<<player_win_prob<<std::endl;
    std::cout<<"Banker Win Probabitliy: "<<banker_win_prob<<std::endl;
    std::cout<<"Tie Probabitliy: "<<tie_prob<<std::endl;
}

void calc_pairs_odds() {
    std::vector<double> shoe = {5, 2, 4, 1, 12, 7, 7, 2, 9, 1, 13, 17, 4};

    double player_pair_prob = 0;
    double banker_pair_prob = 0;
    double either_pair_prob = 0;

    for (int i1 = 0; i1 < 13; i1++) {
    for (int i2 = 0; i2 < 13; i2++) {
    for (int i3 = 0; i3 < 13; i3++) {
    for (int i4 = 0; i4 < 13; i4++) {

    std::vector<double> shoe_copy = shoe;
    double probability = shoe[i1] / std::accumulate(shoe.begin(), shoe.end(), 0);
    shoe_copy[i1] -= 1;
    probability *= shoe_copy[i2] / std::accumulate(shoe_copy.begin(), shoe_copy.end(), 0);
    shoe_copy[i2] -= 1;
    probability *= shoe_copy[i3] / std::accumulate(shoe_copy.begin(), shoe_copy.end(), 0);
    shoe_copy[i3] -= 1;
    probability *= shoe_copy[i4] / std::accumulate(shoe_copy.begin(), shoe_copy.end(), 0);
    shoe_copy[i4] -= 1;
    
    bool is_player_pair = (i1 == i2);
    bool is_banker_pair = (i3 == i4);
    if (is_player_pair) player_pair_prob += probability;
    if (is_banker_pair) banker_pair_prob += probability;
    if (is_player_pair || is_banker_pair) either_pair_prob += probability;

    }}}}

    std::cout<<"Player Pair Probabitliy: "<<player_pair_prob<<std::endl;
    std::cout<<"Banker Pair Probabitliy: "<<banker_pair_prob<<std::endl;
    std::cout<<"Either Pair Probability: "<<either_pair_prob<<std::endl;
}

int main() {
    calc_pairs_odds();
    return 0;
}