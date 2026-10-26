import ctypes, struct
pid=18532;k32=ctypes.windll.kernel32;h=k32.OpenProcess(0x20|0x8,False,pid)
b=ctypes.create_string_buffer(4)
def r(a): k32.ReadProcessMemory(h,a,b,4,None);return struct.unpack('<I',b.raw)[0]
def rf(a): k32.ReadProcessMemory(h,a,b,4,None);return struct.unpack('<f',b.raw)[0]
def wf(a,v): k32.WriteProcessMemory(h,a,struct.pack('<f',v),4,None)

veh=r(0x7C54F0+1*4)
print(f"Schumacher rear wing (0x0394): {rf(veh+0x0394):.4f}")
wf(veh+0x0394, 1.0)
print(f"  -> set to 1.0 (fully detached)")
print(f"  verify: {rf(veh+0x0394):.4f}")
print("Spectate Schumacher — does he pit now?")
k32.CloseHandle(h)
