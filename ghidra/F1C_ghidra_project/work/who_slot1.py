import ctypes, struct
pid=19880;k32=ctypes.windll.kernel32;h=k32.OpenProcess(0x10,False,pid)
b=ctypes.create_string_buffer(64);b4=ctypes.create_string_buffer(4)
def r(a): k32.ReadProcessMemory(h,a,b4,4,None); return struct.unpack('<I',b4.raw)[0]
def name(veh):
    k32.ReadProcessMemory(h,veh+0x4620,b,64,None)
    raw=b.raw; null=raw.find(b'\x00')
    if null>=0: raw=raw[:null]
    return ''.join(chr(c) if 32<=c<127 else '' for c in raw).strip()
veh=r(0x7C54F0+4)
print(f'Slot 1: {name(veh)} finish={r(veh+0x4064)}')
k32.CloseHandle(h)
