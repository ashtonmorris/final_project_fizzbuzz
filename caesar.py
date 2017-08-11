import cs50
import sys

def main():
    if len(sys.argv) != 2:
        print("Invalid input, try again: ")
        exit(1)
    
    print("plaintext: ", end = "")
        
    key = int(sys.argv[1])
    ciphertext = []
    plaintext = cs50.get_string()
    for symbol in plaintext:
        if symbol.isalpha():
            ciphertext.append(caesar(symbol, key))
        else:
            ciphertext.append(symbol)
                
    print("ciphertext: ", "".join(ciphertext))
    exit(0)

def caesar(char, key):
    if char.isupper():
        return chr(((ord(char) - 65 + key) % 26) + 65)
    else:
        return chr(((ord(char) - 97 + key) % 26) + 97)
        
if __name__ == "__main__":
    main()