int __fastcall sub_536300(_DWORD *a1, int a2)
{
  int v3; // ebx
  unsigned int v5; // eax
  int v6; // ecx
  bool v7; // zf
  unsigned int v8; // edx
  unsigned int v9; // eax
  _DWORD *v10; // ecx
  unsigned int v11; // ecx
  _DWORD *v12; // ecx
  _DWORD *v14; // ecx
  int v15; // eax

  v3 = 0xFFFF;
  if ( (unsigned int)(a1[3] - 5) < 0xFFFF )
    v3 = a1[3] - 5;
  while ( 1 )
  {
    v5 = *(_DWORD *)((char *)a1 + 106);
    if ( v5 <= 1 )
    {
      sub_536440(a1);
      v5 = *(_DWORD *)((char *)a1 + 106);
      if ( !v5 )
        break;
    }
    v6 = *(_DWORD *)((char *)a1 + 98);
    *(_DWORD *)((char *)a1 + 106) = 0;
    v7 = v5 + v6 == 0;
    *(_DWORD *)((char *)a1 + 98) = v5 + v6;
    v8 = *(_DWORD *)((char *)a1 + 98);
    v9 = *(_DWORD *)((char *)a1 + 82) + v3;
    if ( !v7 && v8 < v9
      || (*(_DWORD *)((char *)a1 + 98) = v9,
          *(_DWORD *)((char *)a1 + 106) = v8 - v9,
          sub_5381F0(v3, 0),
          v10 = (_DWORD *)*a1,
          *(_DWORD *)((char *)a1 + 82) = *(_DWORD *)((char *)a1 + 98),
          sub_536160(v10),
          *(_DWORD *)(*a1 + 16)) )
    {
      v11 = *(_DWORD *)((char *)a1 + 98) - *(_DWORD *)((char *)a1 + 82);
      if ( v11 < *(_DWORD *)((char *)a1 + 34) - 262 )
        continue;
      sub_5381F0(v11, 0);
      v12 = (_DWORD *)*a1;
      *(_DWORD *)((char *)a1 + 82) = *(_DWORD *)((char *)a1 + 98);
      sub_536160(v12);
      if ( *(_DWORD *)(*a1 + 16) )
        continue;
    }
    return 0;
  }
  if ( !a2 )
    return 0;
  sub_5381F0(*(_DWORD *)((char *)a1 + 98) - *(_DWORD *)((char *)a1 + 82), a2 == 4);
  v14 = (_DWORD *)*a1;
  *(_DWORD *)((char *)a1 + 82) = *(_DWORD *)((char *)a1 + 98);
  sub_536160(v14);
  v15 = 0;
  if ( !*(_DWORD *)(*a1 + 16) )
    return a2 != 4 ? 0 : 2;
  LOBYTE(v15) = a2 == 4;
  return 2 * v15 + 1;
}
