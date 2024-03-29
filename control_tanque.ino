const int Trigger = 2;   //Pin digital 2 para el Trigger del sensor
const int Echo = 3;   //Pin digital 3 para el Echo del sensor
const int Solenoid = 4;
void setup() {
  Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  pinMode(Solenoid,OUTPUT);
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
  digitalWrite(Solenoid, LOW);
}

int distance_control(){
  long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros
 
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm
  
  Serial.print("Distancia: ");
  Serial.print(d);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm ");
  Serial.println();
  return d;
}

void loop(){
  int distance = distance_control();
  delay(1000);
  
}
