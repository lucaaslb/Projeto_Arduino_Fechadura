// ===============================================================================
        //Trabalho de conclusão de curso 
        //Centro Paula Souza, ETEC Lauro Gomes
        // Eletronica 2° Semestre 2014
        // Lucas Lacerda Bernardo
        // Cofre com fechadura de combinação

// =====================================================================================================

#include <LiquidCrystal.h> //Inclui a biblioteca LiquidCrystal.h 

#define botao 8 //Define botao como 8 
#define IN1 6 //Pinos do drive da Ponte H L298N
#define IN2 7 //Pinos do drive da Ponte H L298N
#define botaofp 9 //Define Botão fecha porta como 9

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Instância o LCD com os respectivos pinos que serão utilizados 

int map_pot; //Variável para armazenar o valor da escla de 0 a 5 do potenciômetro 
int i=0; //Variável para contagem 


char senha[] = "0000"; //Variável para armazernar os digitos da combinação 
char senhadesejada[] = "0205"; //Variável para armazenar a senha desejada = "0205"

void setup() 
{   

  lcd.begin(16,2); //Inicia o LCD   
  pinMode(A1, OUTPUT); //Configura o pino A1 como saída   
  pinMode(A2, OUTPUT); //Configura o pino A2 como saída   
  pinMode(A3, OUTPUT); //Configura o pino A3 como saída   
  pinMode(A4, OUTPUT); //Configura o pino A4 como saída   
  pinMode(A5, OUTPUT); //Configura o pino A5 como saída 

} 

void loop() 
{   
 if(!digitalRead(botaofp)) //Lê se o botão fecha porta foi pressionado
  {
    //Gira o Motor A no sentido horario
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    delay(500);
    //Para o motor A
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
    delay(700);
    lcd.setCursor(0,0); //Limpa a tela do LCD   
    lcd.print(" PORTA FECHADA  "); //Escreve a frase "Digite a Senha: "
    delay(1500);
    lcd.clear(); //Limpa a tela do LCD
    lcd.setCursor(0,0);
    lcd.print("SENHA: ");
    
  }
  
  lcd.setCursor(0,0); //Limpa a tela do LCD   
  lcd.print("SENHA: "); //Escreve a frase "Digite a Senha: "   

  map_pot = map(analogRead(A0), 0,1023, 0,6); //Pega o valor do potenciômetro e converte para uma escala de 0 a 6     

    if(map_pot > 0 ) 
    digitalWrite(A1, HIGH); //Se o valor aferido for maior que 0   
  else digitalWrite(A1, LOW); //Acende o primeiro LED   
  if(map_pot > 1 ) digitalWrite(A2, HIGH); //Se o valor aferido for maior que 1  
  else digitalWrite(A2, LOW); //Acende o segundo LED   
  if(map_pot > 2 ) digitalWrite(A3, HIGH); //Se o valor aferido for maior que 2   
  else digitalWrite(A3, LOW); //Acende o terceiro LED   
  if(map_pot > 3 ) digitalWrite(A4, HIGH); //Se o valor aferido for maior que 3   
  else digitalWrite(A4, LOW); //Acende o quarto LED   
  if(map_pot > 4 ) digitalWrite(A5, HIGH); //Se o valor aferido for maior que 4   
  else digitalWrite(A5, LOW); //Acende o quinto LED   

  if(!digitalRead(botao)) //Se o botão for pressionado   
  {     

    lcd.setCursor(i+7,0); //Posiciona o cursor na segunda linha     
    lcd.print("*"); //Imprime o caractere "*"     

    if(map_pot == 0) senha[i] = '0'; //Se o digito for 0, armazena na respectiva posição da senha     
    else if(map_pot == 1) senha[i] = '1'; //Se o digito for 1, armazena na respectiva posição da senha     
    else if(map_pot == 2) senha[i] = '2'; //Se o digito for 2, armazena na respectiva posição da senha     
    else if(map_pot == 3) senha[i] = '3'; //Se o digito for 3, armazena na respectiva posição da senha     
    else if(map_pot == 4) senha[i] = '4'; //Se o digito for 4, armazena na respectiva posição da senha     
    else if(map_pot == 5) senha[i] = '5'; //Se o digito for 5, armazena na respectiva posição da senha    

    i++; //Incrementa a posição da senha     
    while(!digitalRead(botao)){     
    } //Aguarda o botão ser despressionado   
  }   

  if(i>3) //Se os 4 dígitos forem recebidos   
  {      

    //Compara todos os digitos da senha]       
    //E se tiver algum digito não correspondente     

    if(senha[0] != senhadesejada[0] || senha[1] != senhadesejada[1] || senha[2] != senhadesejada[2] || senha[3] != senhadesejada[3])     

    {       

      //Efeito de entrada da frase "SENHA INCORRETA"       
      lcd.clear(); //Limpa a tela do LCD       
      lcd.setCursor(0,0); //Posiciona o cursor na primeira coluna da primeira linha       
      lcd.print("S"); //Imprime na tela a lembra "S"       
      delay(200); //Aguarda 200 milissegundos       
      lcd.setCursor(1,0 ); //Posiciona o cursor na segunda coluna da primeira linha       
      lcd.print("E"); //Imprime na tela a lembra "E"       
      delay(200); //Aguarda 200 milissegundos       
      lcd.setCursor(2,0); //Posiciona o cursor na terceira coluna da primeira linha       
      lcd.print("N"); //Imprime na tela a lembra "N"       
      delay(200); //Aguarda 200 milissegundos       
      lcd.setCursor(3,0); //Posiciona o cursor na quarta coluna da primeira linha       
      lcd.print("H"); //Imprime na tela a lembra "H"       
      delay(200); //Aguarda 200 milissegundos       
      lcd.setCursor(4,0); //Posiciona o cursor na quinta coluna da primeira linha       
      lcd.print("A "); //Imprime na tela a lembra "A"       
      delay(200); //Aguarda 200 milissegundos       
      lcd.setCursor(6,0); //Posiciona o cursor na sétima coluna da primeira linha       
      lcd.print("I"); //Imprime na tela a lembra "I"       
      delay(200); //Aguarda 200 milissegundos       
      lcd.setCursor(7,0); //Posiciona o cursor na oitava coluna da primeira linha       
      lcd.print("N"); //Imprime na tela a lembra "N"       
      delay(200); //Aguarda 200 milissegundos       
      lcd.setCursor(8,0); //Posiciona o cursor na nona coluna da primeira linha       
      lcd.print("C"); //Imprime na tela a lembra "C"       
      delay(200); //Aguarda 200 milissegundos       
      lcd.setCursor(9,0); //Posiciona o cursor na décima coluna da primeira linha       
      lcd.print("O"); //Imprime na tela a lembra "O"       
      delay(200); //Aguarda 200 milissegundos       
      lcd.setCursor(10,0); //Posiciona o cursor na décima primeira coluna da primeira linha   
      lcd.print("R"); //Imprime na tela a lembra "R"       
      delay(200); //Aguarda 200 milissegundos       
      lcd.setCursor(11,0); //Posiciona o cursor na décima segunda coluna da primeira linha
      lcd.print("R"); //Imprime na tela a lembra "R"       
      delay(200); //Aguarda 200 milissegundos       
      lcd.setCursor(12,0); //Posiciona o cursor na décima terceira coluna da primeira linha
      lcd.print("E"); //Imprime na tela a lembra "E"       
      delay(200); //Aguarda 200 milissegundos       
      lcd.setCursor(13,0); //Posiciona o cursor na décima quarta coluna da primeira linha
      lcd.print("T"); //Imprime na tela a lembra "T"       
      delay(200); //Aguarda 200 milissegundos       
      lcd.setCursor(14,0); //Posiciona o cursor na décima quinta coluna da primeira linha
      lcd.print("A"); //Imprime na tela a lembra "A"       
      delay(200); //Aguarda 200 milissegundos       

      //==================================================================              

      //Laço para o efeito de piscagem da frase "SENHA INCORRETA"       
      for(int i=0;i<3;i++)       
      {         
        lcd.clear(); //Limpa a tela do LCD         
        lcd.setCursor(0,0); //Posiciona o cursor na primeira coluna da primeira linha         
        delay(500); //Aguarda 200 milissegundos         
        lcd.print("SENHA INCORRETA"); //Imprime a frase "SENHA INCORRETA"         
        delay(500); //Aguarda 500 milissegundos
        lcd.clear(); //Limpa a tela do LCD         
        lcd.setCursor(0,0); //Posiciona o cursor na primeira coluna da primeira linha
        lcd.print("SENHA");
      }            
    }     

    //===========================================================              

    else //Senão     
    {       

      //Laço para o efeito de piscagem da frase "SENHA CORRETA"
      for(int i=0;i<1;i++)       
      {         
        lcd.clear(); //Limpa a tela do LCD         
        lcd.setCursor(0,0); //Posiciona o cursor na primeira coluna da primeira linha         
        delay(300); //Aguarda 300 milissegundos         
        lcd.print(" SENHA CORRETA"); //Imprime a frase "SENHA CORRETA"      
        delay(1000);
        lcd.clear(); //Limpa a tela do LCD        
        delay(500);


        digitalWrite (IN1, HIGH);
        digitalWrite (IN2, LOW);
        delay(500);
        digitalWrite (IN1, HIGH);
        digitalWrite (IN2, HIGH); 
        delay(700);

        lcd.clear(); // limpa a tela do lcd
        lcd.setCursor(0,0); //Posiciona o cursor na primeira coluna da primeira linha
        lcd.print("  PORTA ABERTA  ");
        delay(5000);

        lcd.clear(); //Limpa a tela do LCD         
        lcd.setCursor(0,0); //Posiciona o cursor na primeira coluna da primeira linha
        lcd.print("SENHA : ");


 
      }     

    }          

    i=0; //Zera a variável de contagem das posições  
   
    

  } 



}



