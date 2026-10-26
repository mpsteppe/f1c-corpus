import ctypes, ctypes.wintypes, struct

PROCESS_VM_READ = 0x10
pid = 5492
kernel32 = ctypes.windll.kernel32
hProcess = kernel32.OpenProcess(PROCESS_VM_READ, False, pid)

buf_256 = ctypes.create_string_buffer(256)
def read_str(addr, maxlen=64):
    kernel32.ReadProcessMemory(hProcess, addr, buf_256, maxlen, None)
    s = buf_256.raw.split(b'\x00')[0]
    return s.decode('latin-1', errors='replace') if s else ''

# Driver data array: DAT_005f0dec + i * 0x48C0
driver_base = 0x005F0DEC
print("=== Driver block (0x005F0DEC + 1*0x48C0) ===")
for name_off in range(0, 0x200, 4):
    addr = driver_base + 1*0x48C0 + name_off
    s = read_str(addr, 32)
    if s and len(s) > 2 and s.strip():
        print(f'  +0x{name_off:04x}: "{s.strip()}"')

# Vehicle struct
veh = 0x005f0f98
print("=== Vehicle struct (0x005f0f98) ===")
for name_off in range(0, 0x1000, 4):
    addr = veh + name_off
    s = read_str(addr, 32)
    if s and len(s) > 2 and s.strip():
        print(f'  +0x{name_off:04x}: "{s.strip()}"')

kernel32.CloseHandle(hProcess)
