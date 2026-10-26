import os
from cryptography.hazmat.primitives.ciphers.aead import AESGCM

# 1. Geração da Chave AES-256
# 256 bits equivalem a 32 bytes. Em um sistema real, essa chave deve ser 
# guardada em um local seguro (como um cofre de senhas ou KMS) e nunca no código.
chave_aes256 = AESGCM.generate_key(bit_length=256)
aesgcm = AESGCM(chave_aes256)

# 2. Criação do Nonce (Vetor de Inicialização)
# O GCM requer um "nonce" (number used once) de 12 bytes para cada criptografia.
# NUNCA reutilize o mesmo nonce com a mesma chave.
nonce = os.urandom(12)

# 3. Preparação da Mensagem
# A criptografia trabalha com bytes, então strings precisam ser convertidas.
mensagem_original = b"Informacao confidencial de cartao de credito"
print(f"Mensagem original: {mensagem_original.decode('utf-8')}")

# 4. Criptografar
# O método encrypt gera o texto cifrado e anexa automaticamente uma tag de 
# autenticação de 16 bytes no final.
texto_cifrado = aesgcm.encrypt(nonce, mensagem_original, associated_data=None)
print(f"Texto cifrado (em hexadecimal): {texto_cifrado.hex()}")

# 5. Descriptografar
# Para descriptografar, você precisa da mesma chave, do mesmo nonce e do texto cifrado.
# Se o texto ou a tag de autenticação forem alterados por um invasor, 
# a descriptografia falhará imediatamente lançando uma exceção (InvalidTag).
mensagem_descriptografada = aesgcm.decrypt(nonce, texto_cifrado, associated_data=None)
print(f"Mensagem descriptografada: {mensagem_descriptografada.decode('utf-8')}")