#include <iostream>

using namespace std;

int A, B, C, D, E, F, G , H;

int main() {

    cin >> A >> B >> C >> D >> E >> F >> G >> H;

    if((A + C + F + H) - (B + D + E + G) != 0){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    while (A + C + F + H > 0){
        if (A > 0 && B > 0){
            cout << "AB-" << endl;
            A--;
            B--;
        }
        if(A > 0 && D > 0){
            cout << "AD-" << endl;
            A--;
            D--;
        }
        if(A > 0 && E >0){
            cout << "AE-" << endl;
            A--;
            E--;
        }
        if(A > 0 && G > 0){
            cout << "BF+" << endl << "AB-" << endl << "GF-" << endl;
            A--;
            G--;
        }

        if (C > 0 && B > 0){
            cout << "CB-" << endl;
            C--;
            B--;
        }
        if(C > 0 && D > 0){
            cout << "CD-" << endl;
            C--;
            D--;
        }
        if(C > 0 && G >0){
            cout << "CG-" << endl;
            C--;
            G--;
        }
        if(C > 0 && E > 0){
            cout << "FB+" << endl << "EF-" << endl << "CB-" << endl;
            C--;
            E--;
        }

        if (F > 0 && E > 0){
            cout << "FE-" << endl;
            F--;
            E--;
        }
        if(F > 0 && G > 0){
            cout << "FG-" << endl;
            F--;
            G--;
        }
        if(F > 0 && B >0){
            cout << "FB-" << endl;
            F--;
            B--;
        }
        if(F > 0 && D > 0){
            cout << "AE+" << endl << "DA-" << endl << "FE-" << endl;
            F--;
            D--;
        }

        if (H > 0 && G > 0){
            cout << "HG-" << endl;
            H--;
            G--;
        }
        if(H > 0 && D > 0){
            cout << "HD-" << endl;
            H--;
            D--;
        }
        if(H > 0 && E >0){
            cout << "HE-" << endl;
            H--;
            E--;
        }
        if(H > 0 && B > 0){
            cout << "EA+" << endl << "BA-" << endl << "EH-" << endl;
            H--;
            B--;
        }
    }

    return 0;
}
