//By CristoRM
 
//Inicializamos los pines de los LEDS
int azul=6;
int verde=7;
int rojo=8;
//Creamos variables para que almacenen el estado del led
int a=0,v=0,r=0;
void setup()  
{
  Serial.begin(9600);
  pinMode(azul,OUTPUT);//Azul
  pinMode(verde,OUTPUT);//Verde
  pinMode(rojo,OUTPUT);//Rojo
}

void loop() 
{
  if (Serial.available())
  {
      char dato=Serial.read();
      if(dato=='0'){                              //Sirve para apagar todas las luces
        a=0; v=0; r=0;
        digitalWrite(azul,LOW);
        digitalWrite(rojo,LOW);
        digitalWrite(verde,LOW);
        Serial.println();
      }
      //Por ejemplo, le damos envíamos 1, entra a este if
      if(dato=='1'){
        a++;            //Aquí a se vuelve 1, sí entra de nuevo se hace 2, 3,4,5...
        if(a%2==1){     //Sí entra en 1 esta prendido, la idea sería que sí entra en 2 se apaga, en 3 se prende, entonces, se 
                        //prende en los impares, por eso cuando el residuo es 1
          Serial.println(" Se prende led AZUL");
          digitalWrite(azul,HIGH);                //Prende led AZUL
        }else{          //Y aquí va el caso de los pares ya, osea se apaga
          Serial.println(" Se apaga led AZUL");
          digitalWrite(azul,LOW);                 //Apaga led AZUL
        }  
      }
      //El resultado es análogo para los otros dos leds
      if(dato=='2'){              
        v++;
        if(v%2==1){
          Serial.println(" Se prende led VERDE"); 
          digitalWrite(verde,HIGH);               //Prende led VERDE
        }else{
          Serial.println(" Se apaga led VERDE");  
          digitalWrite(verde,LOW);                //Apaga led VERDE
        }
        
      }
      if(dato=='3'){
        r++;
        if(r%2==1){
          Serial.println(" Se prende led ROJO");
          digitalWrite(rojo,HIGH);                //Prende led ROJO
        }else{
          Serial.println(" Se apaga led ROJO");
          digitalWrite(rojo,LOW);                 //Prende led ROJO
        }  
      }
      
  }
}
