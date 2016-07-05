import struct

def packto_byte(eightbit):
    onebyte = 0
    for x in eightbit:
        onebyte = onebyte * 2 + x
    return onebyte

def unpack_byte(onebyte):
    eightbit = [None] * 8
    for i in [7,6,5,4,3,2,1,0]:
        eightbit[i] = onebyte % 2
        onebyte = onebyte // 2
    return eightbit

def packto_bytes(nbits):
    n = len(nbits); rem = n % 8
    if rem > 0:
        nbits.extend([0]*(8-rem))
    bytes = []
    for i in range(0, n, 8):
        bytes.append(packto_byte(nbits[i:i+8]))
    return bytes

def unpack_bytes(bytes):
    nbits = []
    for x in bytes:
        nbits.extend(unpack_byte(x))
    return nbits

def is_short_int(x):
    return ((-32768 <= x) and (x <= 32767))

def write_to_buffer(nums):
    buf, nbits = bytearray(), []
    for i in nums:
        if is_short_int(i):
            nbits.append(0)
            nbits.extend(unpack_bytes(list(struct.pack('h', i))))
            # nbits.extend(unpack_bytes([ord(x) for x
            #         in list(struct.pack('h', i))]))
        else:
            nbits.append(1)
            nbits.extend(unpack_bytes(list(struct.pack('i', i))))
            # nbits.extend(unpack_bytes([ord(x) for x
            #         in list(struct.pack('i', i))]))
        while len(nbits) >= 8:
            buf.extend(bytearray(packto_bytes(nbits[:8])))
            nbits = nbits[8:]
    buf.extend(bytearray(packto_bytes(nbits)))
    return buf

def read_from_buffer(buf):
    nbits = unpack_bytes(list(buf))
    nums, i, n = [], 0, len(nbits)
    while i < n:
        if nbits[i] == 0:
            i = i + 1
            if i + 16 > n: break
            nums.append(struct.unpack('h', bytearray(
                    packto_bytes(nbits[i:i+16])))[0])
            i = i + 16
        else:
            i = i + 1
            if i + 32 > n: break
            nums.append(struct.unpack('i', bytearray(
                    packto_bytes(nbits[i:i+32])))[0])
            i = i + 32
    return nums


print(read_from_buffer(write_to_buffer([])))
print(read_from_buffer(write_to_buffer([0])))
print(read_from_buffer(write_to_buffer([1])))
print(read_from_buffer(write_to_buffer([-1])))
print(read_from_buffer(write_to_buffer([0,1,-1,2,-2,2333333])))
print(read_from_buffer(write_to_buffer(range(33))))

with open('task_142_test1.txt', 'r') as fin:
    nums = []
    for s in fin.readlines():
        nums.append(int(s))
    buf = write_to_buffer(nums)
    print(len(buf) / 400000.0)
    # nums2 = read_from_buffer(buf)
    # for i in nums2:
    #     print(i)
