#include "ComunicationPort.hpp"

ComunicationPort::ComunicationPort(){
}

int ComunicationPort::ReceivedFruits() {
  if (Serial.available() > 0) {  
    String recebido = Serial.readStringUntil('\n');  // Lê o valor recebido
    recebido.trim();  // Remove espaços extras e quebras de linha

    Serial.print("Recebido: ");
    Serial.println(recebido);

    // Verifica os comandos e retorna os valores correspondentes
    if (recebido == "F0") return 0;
    if (recebido == "F1") return 1;
    if (recebido == "F2") return 2;
  }

  return -1;  // Retorna -1 caso o valor recebido não seja válido
}

// void ComunicationPort::ReceivedFruits(int weight) {
    
// }
