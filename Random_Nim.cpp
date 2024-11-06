#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long

// Function to calculate power mod (for modular inverse)
ll mod_pow(ll a, ll p, ll mod) {
    ll result = 1;
    while (p > 0) {
        if (p & 1) result = (result * a) % mod;
        a = (a * a) % mod;
        p >>= 1;
    }
    return result;
}

// Function to calculate probability of Alice winning a single dice roll
pair<ll, ll> calculate_probability(ll D) {
    ll total_outcomes = D * D; // Total dice roll outcomes
    ll alice_wins = (D * (D + 1)) / 2; // Outcomes where Alice wins or ties
    
    // Calculate modular inverse of total_outcomes
    ll q_inv = mod_pow(total_outcomes, MOD - 2, MOD);
    return { (alice_wins * q_inv) % MOD, total_outcomes % MOD };
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while (T--) {
        ll N, D;
        cin >> N >> D;
        
        vector<ll> A(N);
        ll nim_sum = 0;
        
        for (ll i = 0; i < N; i++) {
            cin >> A[i];
            nim_sum ^= A[i];
        }
        
        auto [P, Q] = calculate_probability(D);
        
        // If nim_sum is zero, Alice is guaranteed to lose
        if (nim_sum == 0) {
            cout << 0 << endl;
        } else {
            // Calculate answer as P * Q^-1 % MOD
            ll result = (P * mod_pow(Q, MOD - 2, MOD)) % MOD;
            cout << result << endl;
        }
    }
    
    return 0;
}
