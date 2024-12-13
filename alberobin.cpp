#include <iostream>
template <typename T>
class AlberoBinario {
private:
    T nodi[100]; 
    bool occupato[100]; 

public:
    AlberoBinario() {
        for (int i = 0; i < 100; ++i) {
            occupato[i] = false;
        }
    }

    bool alberoVuoto() const {
        return !occupato[0]; 
    }

    void insRadice(const T& valore) {
        if (!occupato[0]) {
            nodi[0] = valore;
            occupato[0] = true;
        }
    }

    T radice() const {
        if (!alberoVuoto()) {
            return nodi[0];
        }
        return T();
    }

    bool isFoglia(int indice) const {
        if (indice >= 0 && indice < 100 && occupato[indice]) {
            int sinistro = figlioSinistro(indice);
            int destro = figlioDestro(indice);
            return (sinistro >= 100 || !occupato[sinistro]) && (destro >= 100 || !occupato[destro]);
        }
        return false;
    }

    int figlioSinistro(int indice) const {
        int sinistro = 2 * indice + 1;
        if (sinistro < 100) {
            return sinistro;
        }
        return -1;
    }

    int figlioDestro(int indice) const {
        int destro = 2 * indice + 2;
        if (destro < 100) {
            return destro;
        }
        return -1;
    }

    void insFiglioSinistro(int indice, const T& valore) {
        if (indice < 0 || indice >= 100) {
            return;
        }
        int sinistro = figlioSinistro(indice);
        if (occupato[indice] && !occupato[sinistro]) {
            nodi[sinistro] = valore;
            occupato[sinistro] = true;
        }
    }

    void insFiglioDestro(int indice, const T& valore) {
        if (indice < 0 || indice >= 100) {
            return;
        }
        int destro = figlioDestro(indice);
        if (occupato[indice] && !occupato[destro]) {
            nodi[destro] = valore;
            occupato[destro] = true;
        }
    }

    void rimuovi(int indice) {
        if (indice < 0 || indice >= 100 || !occupato[indice]) {
            return;
        }
        if (isFoglia(indice)) {
            occupato[indice] = false;
        }
    }

    void stampa() const {
        for (int i = 0; i < 100; ++i) {
            if (occupato[i]) {
                std::cout << "Pos " << i << ", Valore: " << nodi[i];
                int sinistro = 2 * i + 1;
                int destro = 2 * i + 2;
                std::cout << ", Figliosinistro: " << ((sinistro < 100 && occupato[sinistro]) ? std::to_string(nodi[sinistro]) : "null");
                std::cout << ", Figliodestro: " << ((destro < 100 && occupato[destro]) ? std::to_string(nodi[destro]) : "null") << std::endl;
            }
        }
    }
};

int main() {
    AlberoBinario<int> albero;

    albero.insRadice(7);
    albero.insFiglioSinistro(0, 9);
    albero.insFiglioDestro(0, 12);
    albero.insFiglioSinistro(1, 33);
    albero.insFiglioDestro(1, 65);

    
    albero.stampa();

    std::cout << "Rimuovo il nodo 33 (foglia):" << std::endl;
    albero.rimuovi(3);

    albero.stampa();

    return 0;
}
