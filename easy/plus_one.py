class Solution:
    def plusOne(self, digits):
        cadena = ""
        for num in digits:
            cadena += str(num)
        
        cadena = str(int(cadena)+1)

        return [int(caracter) for caracter in cadena]
    
    print(plusOne(0, [1,2,3]))