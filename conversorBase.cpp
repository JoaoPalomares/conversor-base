#include <iostream>
using namespace std;

// Converte string hexadecimal (ou decimal) para decimal
unsigned long long paraDecimal(char numero[], int baseOrigem) {
    int i = 0;
    while (numero[i] != '\0') i++;

    unsigned long long resultado = 0;
    unsigned long long potencia = 1;

    for (int j = i - 1; j >= 0; j--) {
        char c = numero[j];
        int digito;

        if (c >= '0' && c <= '9')
            digito = c - '0';
        else if (c >= 'A' && c <= 'F')
            digito = c - 'A' + 10;
        else if (c >= 'a' && c <= 'f')
            digito = c - 'a' + 10;
        else {
            cout << "Digito invalido para base ate 16!" << endl;
            return 0;
        }

        if (digito >= baseOrigem) {
            cout << "Digito fora da base!" << endl;
            return 0;
        }

        resultado += digito * potencia;
        potencia *= baseOrigem;
    }

    return resultado;
}

// Converte decimal para base até 16
void deDecimal(unsigned long long numero, int baseDestino, char convertido[]) {
    int i = 0;

    do {
        int resto = numero % baseDestino;
        if (resto < 10)
            convertido[i++] = '0' + resto;
        else
            convertido[i++] = 'A' + (resto - 10);
        numero /= baseDestino;
    } while (numero > 0);

    convertido[i] = '\0';

    // Inverter
    for (int j = 0; j < i / 2; j++) {
        char temp = convertido[j];
        convertido[j] = convertido[i - 1 - j];
        convertido[i - 1 - j] = temp;
    }
}

int main() {
    char numero[100];
    int baseOrigem, baseDestino;
    char resultado[100];

    cout << "Base do numero (2 a 16): ";
    cin >> baseOrigem;
    cout << "Digite o numero: ";
    cin >> numero;
    cout << "Base desejada (2 a 16): ";
    cin >> baseDestino;

    if (baseOrigem < 2 || baseOrigem > 16 || baseDestino < 2 || baseDestino > 16) {
        cout << "Bases devem estar entre 2 e 16." << endl;
        return 1;
    }

    unsigned long long decimal = paraDecimal(numero, baseOrigem);
    deDecimal(decimal, baseDestino, resultado);

    cout << "Resultado: " << resultado << endl;

    return 0;
}