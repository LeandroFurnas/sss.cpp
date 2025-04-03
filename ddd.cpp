#include <iostream>
using namespace std;

void compra(int opc, float &cred, int &stock) {
    char decisao;
    float precos[] = {0.0, 1.50, 1.00, 0.50, 1.25, 3.00, 3.50};
    int stockArray[] = {0, 3, 5, 10, 4, 20, 10};

    if (opc < 1 || opc > 6) {
        cout << "Opção Inválida! Escolha um número de 1 a 6.\n";
        return;
    }

    cout << "\nEscolheste ";
    switch (opc) {
            case 1: cout << "o Pãozinho"; 
            cout <<" Temos " << stockArray[opc] << " unidades restantes " << endl;          
        break;
            case 2: cout << "o Leite"; 
            cout <<" Temos " << stockArray[opc] << " unidades restantes " << endl;
        break;
            case 3: cout << "a Água";
            cout <<" Temos " << stockArray[opc] << " unidades restantes " << endl;
         break;
            case 4: cout << "a Manteiga"; 
            cout <<" Temos " << stockArray[opc] << " unidades restantes " << endl;
        break;
            case 5: cout << "a Gelatina"; 
            cout <<" Temos " << stockArray[opc] << " unidades restantes " << endl;
        break;
            case 6: cout << "os Crepes"; 
            cout <<" Temos " << stockArray[opc] << " unidades restantes " << endl;
        break;


    }
    
    cout << "Por $" << precos[opc] << ". Tens a certeza? (s/n): ";
    cin >> decisao;

    if (decisao == 's' || decisao == 'S') {

        if (cred >= precos[opc]) {
            if(stockArray[opc] > 0){
            cred -= precos[opc];
            cout << "Compra realizada com sucesso! Saldo restante: $" << cred << endl;
            stockArray[opc]--;
            cout << "\n" << stockArray[opc] << " restantes " << endl;
            if(stockArray[opc] == 0){
                cout << " Acabou o Stock " << endl;
            }
           }

        } else {
            cout << "Saldo insuficiente! Tens apenas $" << cred << endl;



        }
    } else {
        cout << "Compra cancelada.\n";
    }


    cout << "Pressiona Enter se queres fazer Outra compra.";
    cin.ignore();
    cin.get();


    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    int opc;
    float cred = 1000.00;
    int stockArray[] = {0, 3, 5, 10, 4, 20, 10};
    while (true) {
        cout << "-------------------------------------------------" << endl;
        cout << "|         Bem-vindo à Lojinha do Blud!          |" << endl;
        cout << "|        Aqui nos vendemos so o básico!         |" << endl;
        cout << "| 1 - Pao        ($1.50)                        |" << endl;
        cout << "| 2 - Leite      ($1.00)                        |" << endl;
        cout << "| 3 - Agua       ($0.50)                        |" << endl;
        cout << "| 4 - Manteiga   ($1.25)                        |" << endl;
        cout << "| 5 - Gelatina   ($3.00)                        |" << endl;
        cout << "| 6 - Crepes     ($3.50)                        |" << endl;
        cout << "| Escolha uma das opcoes pelo numero acima:     |" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "Saldo Atual: $" << cred << endl;
        cout << "Digite 0 para sair da loja. " << endl;

        cin >> opc;

        if (opc == 0) {
            cout << "Obrigado por visitar a lojinha! Volte sempre!\n";
            break;
        }

        compra(opc, cred, stockArray[opc]);
    }

    return 0;
}
