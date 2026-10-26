import ctypes, struct

pid = 5492
k32 = ctypes.windll.kernel32
h = k32.OpenProcess(0x20 | 0x8, False, pid)
b4 = ctypes.create_string_buffer(4)

def ru32(addr):
    k32.ReadProcessMemory(h, addr, b4, 4, None)
    return struct.unpack('<I', b4.raw)[0]
def wu32(addr, val):
    k32.WriteProcessMemory(h, addr, struct.pack('<I', val), 4, None)

# Slot 2 = Michael Schumacher
veh = ru32(0x007C54F0 + 2 * 4)
print(f'Slot 2 veh=0x{veh:08x}')

# Check current state
print(f'  FinishState (+0x4064) = {ru32(veh + 0x4064)} (before)')
print(f'  ReasonCode  (+0x4068) = {ru32(veh + 0x4068)} (before)')
print(f'  PitFlag              = {ru32(0x005F073C + 2 * 0x48C0)} (before)')

# Retire
wu32(veh + 0x4064, 2)   # FinishState = DNF
wu32(veh + 0x4068, 5)   # ReasonCode = gearbox
wu32(0x005F073C + 2 * 0x48C0, 3)  # PitFlag = pitting

print(f'  FinishState (+0x4064) = {ru32(veh + 0x4064)} (after)')
print(f'  ReasonCode  (+0x4068) = {ru32(veh + 0x4068)} (after)')
print(f'  PitFlag              = {ru32(0x005F073C + 2 * 0x48C0)} (after)')
print('Schumacher retired. Spectate and watch.')

k32.CloseHandle(h)
