import ctypes, struct
k32 = ctypes.windll.kernel32
h = k32.OpenProcess(0x0010, 0, 4988)

names = ['Matias','M.Schumacher','Hakkinen','Coulthard','Barrichello','R.Schumacher',
         'TesterA','Raikkonen','Trulli','Frentzen','Hill','Irvine','Montoya',
         'Fisichella','Manning','Heidfeld','Salo','Sarrazin','Alesi','De La Rosa',
         'Webber','Alonso']

garage_confirmed = {6, 11, 17, 21, 8}  # TesterA, Irvine, Sarrazin, Alonso, Trulli

print("=== Cars with +0x3D70==0 (off-track) or +0x4544==0 (no driver) ===")
print(f"{'Slot':>4s} {'Name':16s} {'FS':4s} {'3D70':>12s} {'4544':>5s} {'3D6C':>5s} {'Garage':6s}")
for s in range(22):
    vp = (ctypes.c_uint * 1)()
    k32.ReadProcessMemory(h, ctypes.c_void_p(0x007C54F0 + s*4), vp, 4, None)
    veh = vp[0]
    if not veh: continue
    fs = (ctypes.c_int * 1)()
    k32.ReadProcessMemory(h, ctypes.c_void_p(veh + 0x4064), fs, 4, None)
    d370 = (ctypes.c_int * 1)()
    k32.ReadProcessMemory(h, ctypes.c_void_p(veh + 0x3D70), d370, 4, None)
    d4544 = (ctypes.c_int * 1)()
    k32.ReadProcessMemory(h, ctypes.c_void_p(veh + 0x4544), d4544, 4, None)
    d3d6c = (ctypes.c_int * 1)()
    k32.ReadProcessMemory(h, ctypes.c_void_p(veh + 0x3D6C), d3d6c, 4, None)
    fs_str = {0:'RUN',1:'FIN',2:'DNF',3:'DSQ'}.get(fs[0],str(fs[0]))
    garage = 'YES' if s in garage_confirmed else ''
    mark = ''
    if d370[0] == 0: mark = ' <-- OFFTRACK'
    if d4544[0] == 0: mark += ' NODRIVER'
    print(f"{s:4d} {names[s]:16s} {fs_str:4s} {d370[0]:>12d} {d4544[0]:>5d} {d3d6c[0]:>5d} {garage:6s}{mark}")

k32.CloseHandle(h)
