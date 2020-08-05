#include<stdio.h>
#include<queue>

using namespace std;

/*This problem ruins okonomiyaki.*/
int capA, capB, capC, capD, target;
int caps[4];

struct State {
    int c[4];
    int steps;

    State(int av, int bv, int cv, int dv) {
        steps = 0;
        c[0] = av;
        c[1] = bv;
        c[2] = cv;
        c[3] = dv;
    }

    State() {}
};

void set(State s, int cup, int vol, queue<State> *states, bool ved[30][30][30][30]) {
    s.c[cup] = vol;
    s.steps++;
    if (!ved[s.c[0]][s.c[1]][s.c[2]][s.c[3]]) {
        //printf("set: ved[%i][%i][%i][%i]	steps:%i\node",s.c[0],s.c[1],s.c[2],s.c[3],s.steps);
        ved[s.c[0]][s.c[1]][s.c[2]][s.c[3]] = true;
        states->push(s);
    }
}

void transfer(State s, int from, int to, queue<State> *states, bool ****ved) {
    if (s.c[from] + s.c[to] <= caps[to]) {
        s.c[to] += s.c[from];
        s.c[from] = 0;
    } else {
        int dif = caps[to] - s.c[to];
        s.c[from] -= dif;
        s.c[to] += dif;
    }
    s.steps++;
    if (!ved[s.c[0]][s.c[1]][s.c[2]][s.c[3]]) {
        //printf("fil: ved[%i][%i][%i][%i]	steps:%i\node",s.c[0],s.c[1],s.c[2],s.c[3],s.steps);
        ved[s.c[0]][s.c[1]][s.c[2]][s.c[3]] = true;
        states->push(s);
    }
}

int find_min_step(queue<State> *stateQ, bool ****pattern) {
    //init
    stateQ->push(State(0, 0, 0, 0));
    pattern[0][0][0][0] = true;

    //BFS
    int i, j;
    while (!stateQ->empty()) {
        State s = stateQ->front();
        stateQ->pop();

        //Checking
        for (i = 0; i < 4; i++)
            if (s.c[i] == target) return s.steps;    //optimal

        for (i = 0; i < 4; i++) {
            set(s, i, caps[i], stateQ, pattern);    //fill
            set(s, i, 0, stateQ, pattern);    //empty
        }

        for (i = 0; i < 4; i++)
            for (j = 0; j < 4; j++) {
                if (i == j) continue;
                transfer(s, i, j, stateQ, pattern);
            }

    }
    return -1;
}

int main() {
    while (~scanf("%i %i %i %i %i", &capA, &capB, &capC, &capD, &target)) {
        bool ved[30][30][30][30] = {0};
        caps[0] = capA;
        caps[1] = capB;
        caps[2] = capC;
        caps[3] = capD;

        queue<State> *states = new queue<State>;
        if (capA < target && capB < target && capC < target && capD < target)
            printf("-1\n");
        else {
            printf("%i\n", find_min_step(states, ved));
        }
        delete states;
    }

    return 0;
}
