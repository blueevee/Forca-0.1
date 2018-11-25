#include <bits/stdc++.h>
#include <locale.h>

using namespace std;

string escolherPalavra(){
    fstream file;
    int i=0;
     //banco de palavras
    vector < string > palavras(100);
    string nomeArquivo, aux;
    int auxi;
      //leitura do arquivo de banco
    do{

    cout << "Digite o banco de palavras:";
    cin >> nomeArquivo;
    file.open(nomeArquivo, fstream::in);
    }while(!file.is_open());
         // alimentando vetor
    while (getline(file, aux)){
        palavras[i++] = aux;
    }
    //escolhendo palavra aleatoria
    srand(time(nullptr));
    auxi = rand() % 100;

    file.close();
    return palavras[auxi];
}
void regra() {
    setlocale(LC_ALL, "Portuguese");

     cout<<"+-----------------------------------------+"<<endl
         <<"|                                         |"<<endl
         <<"|          O JOGO (da forca):             |"<<endl
         <<"|                                         |"<<endl
         <<"|  O objetivo deste jogo é descobrir uma  |"<<endl
         <<"|palavra adivinhando as letras que ela    |"<<endl
         <<"|possui. A cada rodada, os jogadores irão |"<<endl
         <<"|simultaneamente escolher uma letra que   |"<<endl
         <<"|suspeitem fazer parte da palavra.        |"<<endl
         <<"| Caso a palavra contenha esta letra,     |"<<endl
         <<"|será mostrado em que posição(ões) ela    |"<<endl
         <<"|está. Entretanto, caso esta letra não    |"<<endl
         <<"|na palavra, será desenhada uma parte do  |"<<endl
         <<"|corpo do boneco do jogador.Se todas as 7 |"<<endl
         <<"|partes do corpo do boneco estiverem      |"<<endl
         <<"|desenhadas, o jogador estará fora da     |"<<endl
         <<"|partida.                                 |"<<endl
         <<"|                                         |"<<endl
         <<"|                JOGADORES:               |"<<endl
         <<"|                                         |"<<endl
         <<"| EU quero um máximo de 7.                |"<<endl
         <<"|                                         |"<<endl
         <<"|                PONTUAÇÃO:               |"<<endl
         <<"|                                         |"<<endl
         <<"| Um jogo de Forca consiste de 5 partidas,|"<<endl
         <<"|partidas, cada uma com uma palavra a     |"<<endl
         <<"|ser descoberta.                          |"<<endl
         <<"| Cada palavra valerá 60 pontos, que serão|"<<endl
         <<"|divididos entre todos os jogadores que   |"<<endl
         <<"|descobrirem a palavra. Assim, se um      |"<<endl
         <<"|acertar a palavra, ele ganhará 60 pontos;|"<<endl
         <<"|Se dois jogadores acertarem,  cada um    |"<<endl
         <<"|ganhará 30 pontos, e assim por diante.   |"<<endl
         <<"|  Além disso, os jogadores que acertarem |"<<endl
         <<"|ganharão um bônus de acordo com a        |"<<endl
         <<"|quantidade de erros que cometeram.       |"<<endl
         <<"|Este bônus vale, inicialmente, 60 pontos,|"<<endl
         <<"|e a cada erro do jogador seu valor fica  |"<<endl
         <<"|10 pontos menor.                         |"<<endl
         <<"|                                         |"<<endl
         <<"|           AGORA SÓ VAI, GG              |"<<endl
         <<"|                                         |"<<endl
         <<"|  Att, Dona dessa p***a toda             |"<<endl
         <<"|                                         |"<<endl
         <<"+-----------------------------------------+" <<endl;

}
void rank(){

}

void desenhoForca(int erros){
     //desenho da forca
     system("color 8F");
    system("cls");
    switch(erros){
        case 0:
         cout<< "______________"<<endl
         << "|             "<<endl
         << "|             "<<endl
         << "|             "<<endl
         << "|             "<<endl
         << "|             "<<endl
         << "|             "<<endl
         << "|             "<<endl
            << "|             "<<endl;
        break;
        case 1:
         cout<< "______________"<<endl
         << "|         O   "<<endl
         << "|             "<<endl
         << "|             "<<endl
         << "|             "<<endl
         << "|             "<<endl
         << "|             "<<endl
         << "|             "<<endl
         << "|             "<<endl;
        break;
        case 2:
         cout<< "______________"<<endl
         << "|         O   "<<endl
         << "|         |   "<<endl
         << "|             "<<endl
         << "|             "<<endl
         << "|             "<<endl
         << "|             "<<endl
         << "|             "<<endl
         << "|             "<<endl;
        break;
        case 3:
         cout<< "______________"<<endl
         << "|         O   "<<endl
         << "|         |)  "<<endl
         << "|             "<<endl
         << "|             "<<endl
         << "|             "<<endl
         << "|             "<<endl
         << "|             "<<endl
         << "|             "<<endl;
        break;
        case 4:
         cout<< "______________"<<endl
         << "|         O   "<<endl
         << "|        /|)  "<<endl
         << "|             "<<endl
         << "|             "<<endl
         << "|             "<<endl
         << "|             "<<endl
         << "|             "<<endl
         << "|             "<<endl;
        break;
        case 5:
         cout<< "______________"<<endl
         << "|         O   "<<endl
         << "|        /|)  "<<endl
         << "|         |   "<<endl
         << "|             "<<endl
         << "|             "<<endl
         << "|             "<<endl
         << "|             "<<endl
         << "|             "<<endl;
        break;
        case 6:
         cout<< "______________"<<endl
         << "|         O   "<<endl
         << "|        /|)  "<<endl
         << "|         |   "<<endl
         << "|          )  "<<endl
         << "|             "<<endl
         << "|             "<<endl
         << "|             "<<endl
         << "|             "<<endl;
        break;
        case 7:
         cout<< "______________"<<endl
         << "|         O   "<<endl
         << "|        /|)  "<<endl
         << "|         |   "<<endl
         << "|        / )  "<<endl
         << "|             "<<endl
         << "|             "<<endl
         << "|             "<<endl
         << "|             "<<endl;
        break;
    }


}
int ojogo(  string& palavra){
    char auxc;
    int  erros=0, auxi=0, ac=0, cont;
    vector<char> letras;
    vector < char> palavraEscolhida(palavra.size(), '_');
    system("cls");

    while(ac <= palavra.size() and erros < 7 ){
        desenhoForca(erros);

    //printando tamanho da palavra escolhida
        for (int s=0; s < palavra.size(); s++){
            cout <<palavraEscolhida[s]<< ' ';
        }
        if(ac == palavra.size()) break;
        do{ //recebendo letra
            cout <<endl<< "Digite uma letra:";
            cin >> auxc;
     //armazenando as tentativas
            letras.push_back(auxc);
           }while(!isalpha(auxc));
        //contadora se houveram acertos ou não
        cont = 0;
        for (int i = 0; i < palavra.size(); i++){
            if (auxc==palavra[i]){
                ac++;
                //verificar se houve algum acerto
                cont++;

                palavraEscolhida[i]=toupper(auxc);
            }

        }cout<< endl<<"Tentados:";
        //imprimindo tentativas
        for(auto letra: letras)
           cout << letra << ' ';

         cout <<endl;
        system("pause");
        if(cont== 0) erros++;
    }
    if(ac == palavra.size()){
            system("color EF");
    	cout <<endl<< "PARABENS!" << endl;
        cout<< "       ___________      "<<endl
             <<"      '._==_==_=_.'     "<<endl
             <<"      .-\\:      /-.    "<<endl
             <<"     | (|:.     |) |    "<<endl
             <<"      '-|:.     |-'     "<<endl
             <<"        \\::.    /      "<<endl
             <<"         '::. .'        "<<endl
             <<"           ) (          "<<endl
             <<"         _.' '._        "<<endl
             <<"        '-------'       "<<endl;

	}
	else if (erros==7){
	    system("color 04");
    	desenhoForca(erros);
        cout<< "Que pena, o boneco foi enforcado!"<<endl
            << "    _______________         "<<endl
             <<"   /               \\       "<<endl
             <<"  /                 \\      "<<endl
             <<"//                   \\/\\  "<<endl
             <<"\\|   XXXX     XXXX   | /   "<<endl
             <<" |   XXXX     XXXX   |/     "<<endl
             <<" |   XXX       XXX   |      "<<endl
             <<" |                   |      "<<endl
             <<" \\__      XXX      __/     "<<endl
             <<"   | |           | |        "<<endl
             <<"   | I I I I I I I |        "<<endl
             <<"   |  I I I I I I  |        "<<endl
             <<"   \\             _/        "<<endl
             <<"    \\_         _/          "<<endl
             <<"      \\_______/            "<<endl;
            cout<<"Palavra correta: ";
        for (int s=0; s < palavra.size(); s++){
           if(!isalpha(palavraEscolhida[s]))
                 palavraEscolhida[s] = tolower(palavra[s]);
                cout <<palavraEscolhida[s]<< ' ';
        }
    }

}


int inicio(){
    string palavra = escolherPalavra();
    int op;
    system("color 57");
     cout<<"+-----------------------+"<<endl
     <<"|    JOGO DA FORCA      |"<<endl
     <<"|                       |"<<endl
     <<"|    1-JOGAR            |"<<endl
     <<"|    2-REGRAS           |"<<endl
     <<"|    3-SOBRE            |"<<endl
     <<"|                       |"<<endl
     <<"|                       |"<<endl
     <<"+-----------------------+" <<endl;
do{
    cin>>op;
    switch(op){
    case 1:
   // cout>>"Digite quantos jogares teremos nessa rodada:";
   // cin<<qtjog;
    //for(int i=0; i < 5; i++)
        ojogo(palavra);

        break;
    case 2:
        regra();
        break;
    case 3:
       cout<<"Meu joguinho, eu que fiz, agradecimentos ao monitor hacker"<<endl
        <<"que me ajudou (bastante) com os bugs, mas o resto do joguinho eu que fiz."<<endl
        <<"Obrigada José(muito mesmo), obrigada migos, obrigada computador que não "<<endl
        <<"funcionou quando eu precisei e nenhum obrigada para Tiago que me encheu"<<endl
        <<"a porra do saco até que eu virasse uma bolha de H2Ódio"<<endl
        <<"e um obrigada especial para Evelyn que no caso sou eu "<<endl
        <<"e que sobreviveu até aqui sem socar a cara de ninguém."<<endl
        << "   Att, Blueevee."<<endl;
        break;
    }
    return op;
}while (op > 3);
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    return inicio();
}
