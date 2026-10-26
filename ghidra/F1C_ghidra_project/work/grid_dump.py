import ctypes, struct
pid=14596;k32=ctypes.windll.kernel32;h=k32.OpenProcess(0x10,False,pid)
b=ctypes.create_string_buffer(0x1230 * 2)  # 2 slots

# Grid slot 0 first 256 bytes
k32.ReadProcessMemory(h, 0x5EF9A0, b, 256, None)
print("=== Grid slot 0 (first 64 ints) ===")
for i in range(0, 256, 4):
    v = struct.unpack_from('<I', b.raw, i)[0]
    f = struct.unpack_from('<f', b.raw, i)[0]
    print(f"  +{i:04X}: int={v:11d} (0x{v:08X}) float={f:.4f}")

# Read slot index: veh+0x40 for first 5 cars
print("\n=== Vehicle slot IDs (veh+0x40) ===")
bn=ctypes.create_string_buffer(64)
def name(veh):
    k32.ReadProcessMemory(h,veh+0x4620,bn,64,None)
    raw=bn.raw;null=raw.find(b'\x00')
    if null>=0: raw=raw[:null]
    return ''.join(chr(c) if 32<=c<127 else '' for c in raw).strip()

for i in range(5):
    veh_addr = 0x7C54F0 + i*4
    b4=ctypes.create_string_buffer(4)
    k32.ReadProcessMemory(h, veh_addr, b4, 4, None)
    veh = struct.unpack('<I', b4.raw)[0]
    if veh > 0x10000:
        slot = struct.unpack_from('<I', b.raw, 0)[0] if i==0 else 0
        b4b=ctypes.create_string_buffer(4)
        k32.ReadProcessMemory(h, veh+0x40, b4b, 4, None)
        slot_id = struct.unpack('<I', b4b.raw)[0]
        print(f"  [{i}] {name(veh)} veh+0x40 = {slot_id}")

k32.CloseHandle(h)
