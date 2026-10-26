import ctypes, struct, os
TH32CS_SNAPPROCESS = 0x2
k32 = ctypes.windll.kernel32

class PROCESSENTRY32(ctypes.Structure):
    _fields_ = [('dwSize', ctypes.c_uint32), ('cntUsage', ctypes.c_uint32),
                ('th32ProcessID', ctypes.c_uint32), ('th32DefaultHeapID', ctypes.c_void_p),
                ('th32ModuleID', ctypes.c_uint32), ('cntThreads', ctypes.c_uint32),
                ('th32ParentProcessID', ctypes.c_uint32), ('pcPriClassBase', ctypes.c_int32),
                ('dwFlags', ctypes.c_uint32), ('szExeFile', ctypes.c_char * 260)]

snap = k32.CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0)
pe = PROCESSENTRY32()
pe.dwSize = ctypes.sizeof(PROCESSENTRY32)
pid = 0
if k32.Process32First(snap, ctypes.byref(pe)):
    while True:
        n = pe.szExeFile.decode()
        if 'F1' in n: pid = pe.th32ProcessID; print(f'PID={pid} {n}')
        if not k32.Process32Next(snap, ctypes.byref(pe)): break
k32.CloseHandle(snap)

if pid:
    h = k32.OpenProcess(0x10|0x20|0x8, False, pid)
    b = ctypes.create_string_buffer(4); bn = ctypes.create_string_buffer(64)
    def r(a): k32.ReadProcessMemory(h, a, b, 4, None); return struct.unpack('<I', b.raw)[0]
    def name(veh):
        if veh < 0x10000: return "?"
        k32.ReadProcessMemory(h, veh+0x4620, bn, 64, None)
        raw = bn.raw; null = raw.find(b'\x00')
        if null >= 0: raw = raw[:null]
        return ''.join(chr(c) if 32 <= c < 127 else '' for c in raw).strip()
    
    vc = r(0x5C329C)
    st = r(0x7C56A4)
    gs = r(0x7C569C)
    print(f'VCount={vc} Session={st} State={gs}')
    
    for i in range(vc):
        veh = r(0x7C54F0 + i*4)
        if veh > 0x10000:
            fs = r(veh + 0x4064)
            rc = r(veh + 0x4068)
            nm = name(veh)
            alonso = "<<<" if "Alonso" in nm else ""
            if fs != 0 or alonso:
                print(f'  [{i:2d}] {nm:35s} finish={fs} reason={rc} {alonso}')
    k32.CloseHandle(h)
