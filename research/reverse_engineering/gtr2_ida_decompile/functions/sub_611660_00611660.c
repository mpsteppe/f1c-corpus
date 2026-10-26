int __userpurge sub_611660@<eax>(
        _DWORD *a1@<ecx>,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        unsigned int a7,
        _DWORD *a8,
        int *a9,
        int a10,
        unsigned int a11,
        int a12,
        int a13)
{
  int result; // eax
  int v15; // ebp
  int v16; // eax
  int v17; // ecx
  int v18; // eax
  int v19; // [esp+24h] [ebp-Ch]

  result = a2;
  if ( a2 )
  {
    if ( (a7 & 0x100) == 0 )
      a1[2] = (*(int (__stdcall **)(_DWORD, int, _DWORD))(*(_DWORD *)a1[2387] + 228))(a1[2387], 7, 0);
    if ( a6 )
    {
      result = (*(int (__thiscall **)(_DWORD *, int))(*a1 + 328))(a1, a6);
      if ( !result )
        return result;
      v15 = 256;
      sub_609BF0(4);
      sub_60A820(a1 + 705, a9);
      sub_60A3A0(a1 + 705, (a11 >> 10) & 1);
      sub_60A3F0(a1 + 705, (a11 >> 11) & 1);
      if ( (a7 & 0x40) != 0 )
        v15 = 1280;
      if ( (a11 & 0x80u) != 0 )
      {
        v15 |= 1u;
        sub_60A000(3);
      }
      if ( (a7 & 0x20) != 0 )
      {
        v15 |= 0x800u;
        a3 = ~(a7 >> 1) & 0x40000 | 0x20005;
        sub_60A000(2);
      }
    }
    else
    {
      v15 = 256;
      sub_609BF0(0);
      if ( (a7 & 0x20) != 0 )
      {
        v15 = 2304;
        sub_60A000(2);
        a3 = 327686;
      }
    }
    (*(void (__thiscall **)(_DWORD *, int, int, int))(*a1 + 20))(a1, v15, a3, a12);
    sub_60A790(a1 + 257);
    (*(void (__thiscall **)(_DWORD *, _DWORD, _DWORD *, _DWORD, _DWORD))(*a1 + 40))(a1, 0, a8, 0, 0);
    (*(void (__thiscall **)(_DWORD *, _DWORD, int))(*a1 + 28))(a1, 0, a5);
    v16 = sub_5F7B60(a8, 0, 0);
    sub_5FA770(v16, 0, 0, 0);
    v17 = a1[2387];
    if ( a13 )
      v18 = (*(int (__stdcall **)(int, int, int, int))(*(_DWORD *)v17 + 324))(v17, 6, a6, a13);
    else
      v18 = (*(int (__stdcall **)(int, int, int, int))(*(_DWORD *)v17 + 324))(v17, 4, a6, (int)a7 / 3);
    v19 = a1[1208];
    a1[2] = v18;
    result = (*(int (__cdecl **)(_DWORD, int, int))(*(_DWORD *)a1[2387] + 228))(a1[2387], 7, v19);
    a1[2] = result;
  }
  return result;
}
