#include <iostream>
#include <locale.h>

using namespace std;


struct cadastro
{
    int id;
    string nome;
    string fab;
    string datafab;
    string nserie;
    string precoaquisicao;
    cadastro *prox;
    cadastro *ant;
};

void cadastrar (cadastro*&inicio)
{
    setlocale(LC_ALL, "Portuguese");
	
	system("cls");

    cadastro *novo = new cadastro;

    cout << "Digite o id do equipamento: ";
    cin >> novo -> id;
    cout << endl;
    cout << "Digite o nome do equipamento: ";
    cin >> novo -> nome;
    cout << endl;
    cout << "Digite a fabricante do equipamento: ";
    cin >> novo -> fab;
    cout << endl;
    cout << "Digite a data de fabricação do equipamento (dd/mm/aa): ";
    cin >> novo -> datafab;
    cout << endl;
    cout << "Digite o número de série do equipamento: ";
    cin >> novo -> nserie;
    cout << endl;
    cout << "Digite o preço de aquisição do equipamento: ";
    cin >> novo -> precoaquisicao;
    cout << endl;
    
    if (inicio == NULL)
    {
        inicio = novo;
        novo -> prox = NULL;
        novo -> ant = NULL;
    }
    
    else
    {
        cadastro *percorredor = inicio;

        while (percorredor -> prox != NULL)
        {
            percorredor = percorredor -> prox;
        }

        percorredor -> prox = novo;

        novo -> prox = NULL;

        novo -> ant = percorredor;
    }

    system("cls");
}

    void visualizar(cadastro*inicio)
    {

        system("cls");

        cout << "**** LISTA DE CADASTROS **** \n";
        cout << endl;

        while(inicio != NULL)
        {
            cout << " " << "Id do equipamento: " << inicio -> id << endl;
            cout << endl;           
            cout << " " << "Nome: " << inicio -> nome << endl;
            cout << " " << "Fabricante: " << inicio -> fab << endl;
            cout << " " << "Data de fabricação: " << inicio -> datafab << endl;
            cout << " " << "Número de série: " << inicio -> nserie << endl;
            cout << " " << "Preço de aquisição: " << inicio -> precoaquisicao << endl;

            inicio = inicio -> prox;
        }

        cout << endl;
        cout << "**************************** \n";
        cout << endl;
    }

    void sair(cadastro*inicio)
    {
        exit (0);

    }


    int menu()
    {
        int opcao=0;

        cout << "**** OQUE DESEJA FAZER? **** \n";
		cout << endl;
		cout << "1) Registrar equipamento \n";
        cout << "2) Visualizar equipamentos \n";
        cout << "3) Editar equipamentos \n";
        cout << "4) Sair \n";
        cout << endl;
        
        cout << "Opcao: ";
        
        cin >> opcao;
        
        return opcao;
    }

    void editar (cadastro*&inicio)
    {

        system("cls");

        int id=0;

        cout << "Digite o id do equipamento que deseja alterar: ";
        cin >> id;

        cadastro *percorredor = inicio;

        while ((percorredor -> id != id) && (percorredor -> prox != NULL))
        {
            percorredor = percorredor -> prox;
        }
        
        if (percorredor -> id != id)
        {
            cout << "Id nao encontrado" << endl;
            cout << endl;
        }
        
        else
        {
            cout << "Digite o novo id do equipamento: ";
            cin >> percorredor -> id;
            cout << endl;
            cout << "Digite o novo nome do equipamento: ";
            cin >> percorredor -> nome;
            cout << endl;
            cout << "Digite a nova fabricante do equipamento: ";
            cin >> percorredor -> fab;
            cout << endl;
            cout << "Digite a nova data de fabricação do equipamento (dd/mm/aa): ";
            cin >> percorredor -> datafab;
            cout << endl; 
            cout << "Digite o novo número de série do equipamento: ";
            cin >> percorredor -> nserie;
            cout << endl;
            cout << "Digite o novo preço de aquisição do equipamento: ";
            cin >> percorredor -> precoaquisicao;
            
        }
    }

      
    int main()
    {
        cadastro *inicio = NULL;

        int opcao=0;

        do
        {
            opcao = menu();
            
            switch(opcao)
            {
                case 1: cadastrar(inicio);

                break;

                case 2: visualizar(inicio);

                break;

                case 3: editar(inicio);

                break;
                
                case 4: sair(inicio);

                break;
            }
        }

        while(opcao != 0);

        system("pause");

        return 0;

    }

