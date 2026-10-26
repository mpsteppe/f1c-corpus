import ctypes, struct
pid=18532;k32=ctypes.windll.kernel32;h=k32.OpenProcess(0x10,False,pid)
b=ctypes.create_string_buffer(4)
def r(a): k32.ReadProcessMemory(h,a,b,4,None);return struct.unpack('<I',b.raw)[0]
def rf(a): k32.ReadProcessMemory(h,a,b,4,None);return struct.unpack('<f',b.raw)[0]

DRV=0x5F0DEC; STR=0x48C0
ri=7; si=1  # Raikkonen=7, Schumacher=1

# Check driver block for Raikkonen's unique float damage values
print("=== Driver block damage region (0x0390-0x0400) ===")
for off in range(0x0390, 0x0400, 4):
    rv=rf(DRV+ri*STR+off)
    sv=rf(DRV+si*STR+off)
    if abs(rv-sv)>0.001:
        print(f"  drv+0x{off:04X} Rai={rv:.4f} Sch={sv:.4f} diff={rv-sv:.4f}")

# Also check ALL floats in driver block where Rai != 0 and Sch == 0
print("\n=== Driver block: Rai != 0, Sch == 0 ===")
for off in range(0, 0x4000, 4):
    rv=rf(DRV+ri*STR+off)
    sv=rf(DRV+si*STR+off)
    if rv != 0 and sv == 0 and abs(rv) < 100:
        print(f"  drv+0x{off:04X} Rai={rv:.4f}")

# Check veh for defense against overwriting
# Try writing at a higher memory region
rveh=r(0x7C54F0+7*4)
print(f"\n=== veh+0x0394 stable read => {rf(rveh+0x0394):.4f}")

k32.CloseHandle(h)
