import serial
import time

porta = 'COM3'  # Verifique a porta correta no Gerenciador de Dispositivos
baudrate = 115200

try:
    # Abre a comunicação serial com timeout
    arduino = serial.Serial(porta, baudrate, timeout=2)

    # Aguarde o Arduino resetar
    time.sleep(2)

    # Envia uma mensagem para o Arduino
    arduino.write(b'F3')

    # Aguarde um curto período antes de ler
    time.sleep(0.5)

    # Lê a resposta do Arduino
    resposta = arduino.readline().decode().strip()

    # Se não houver resposta, exibir uma mensagem
    if resposta:
        print("Resposta do Arduino:", resposta)
    else:
        print("Nenhuma resposta do Arduino.")

    # Fecha a comunicação serial
    arduino.close()

except serial.SerialException as e:
    print(f"Erro ao acessar a porta serial: {e}")
