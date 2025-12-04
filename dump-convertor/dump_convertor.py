file_name = 'sos48k_only.bin'

byte_in_string = 0
byte_count = 0
print('file_name', file_name)
print()
with open(file_name, 'rb') as file:
    byte = file.read(1)
    while byte:
        int_byte = int.from_bytes(byte, byteorder='big')
        hex_value = hex(int_byte)
        byte_count += 1
        if byte_in_string < 15:
            print(hex_value + ', ', end="")
            byte_in_string += 1
        else:
             print(hex_value + ', ')
             byte_in_string = 0
        byte = file.read(1)
print('byte_count', byte_count)
print('end_addr', hex(byte_count-1))
