import ctypes, struct, sys
sys.stdout.reconfigure(encoding='utf-8', errors='replace')

pid = 5492
k32 = ctypes.windll.kernel32
h = k32.OpenProcess(0x10, False, pid)
b4 = ctypes.create_string_buffer(4)
b64 = ctypes.create_string_buffer(80)

def ru32(addr):
    k32.ReadProcessMemory(h, addr, b4, 4, None)
    return struct.unpack('<I', b4.raw)[0]

def rs(addr, n=80):
    k32.ReadProcessMemory(h, addr, b64, n, None)
    s = b64.raw
    null = s.find(b'\x00')
    if null > 0: s = s[:null]
    elif null == 0: return '[null]'
    try: return s.decode('utf-8', errors='backslashreplace')
    except: return repr(s)

arr_base = 0x007C54F0
for i in range(1, 8):
    veh = ru32(arr_base + i * 4)
    if veh < 0x10000:
        print(f'slot {i}: NULL')
        continue
    name_ptr = ru32(veh + 0x4620)
    name = rs(name_ptr, 80) if name_ptr > 0x10000 else '[bad ptr]'
    state = ru32(veh + 0x4064)
    reason = ru32(veh + 0x4068)
    pitflag = ru32(0x005F073C + i * 0x48C0)
    print(f'slot {i}: veh=0x{veh:08x} finish={state} reason={reason} pit={pitflag} name={name}')

k32.CloseHandle(h)
