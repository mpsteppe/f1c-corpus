int __fastcall sub_62C2F0(_DWORD *a1, unsigned int a2, int a3, int a4, int a5, unsigned int a6, _BYTE *a7, int a8)
{
  int v9; // ebp
  bool v10; // zf
  int v11; // ebx
  _DWORD *v12; // eax
  _DWORD *v13; // esi
  int v14; // eax
  int v15; // eax
  int v16; // edx
  int v17; // eax
  int v18; // edx
  int v19; // eax
  unsigned int v20; // ecx
  int v21; // edx
  int v23; // [esp+14h] [ebp-4h]

  v9 = 0;
  v23 = a2;
  if ( !a7 || *a7 != *off_911680[0] || a8 != 56 )
    return -6;
  if ( !a1 )
    return -2;
  v10 = a1[8] == 0;
  a1[6] = 0;
  if ( v10 )
  {
    a1[8] = &sub_62CBD0;
    a1[10] = 0;
  }
  if ( !a1[9] )
    a1[9] = &sub_62CBF0;
  if ( a2 == -1 )
  {
    v23 = 6;
    a2 = 6;
  }
  v11 = a4;
  if ( a4 < 0 )
  {
    v9 = 1;
    v11 = -a4;
  }
  if ( a5 < 1 || a5 > 9 || a3 != 8 || v11 < 8 || v11 > 15 || a2 > 9 || a6 > 2 )
    return -2;
  v12 = (_DWORD *)((int (__fastcall *)(_DWORD, int, int))a1[8])(a1[10], 1, 5809);
  v13 = v12;
  if ( v12 )
  {
    a1[7] = v12;
    v12[6] = v9;
    *(_DWORD *)((char *)v12 + 38) = v11;
    *(_DWORD *)((char *)v12 + 42) = (1 << v11) - 1;
    v14 = 1 << (a5 + 7);
    *(_DWORD *)((char *)v13 + 70) = a5 + 7;
    *v13 = a1;
    *(_DWORD *)((char *)v13 + 66) = v14;
    *(_DWORD *)((char *)v13 + 74) = v14 - 1;
    *(_DWORD *)((char *)v13 + 78) = (a5 + 9) / 3u;
    *(_DWORD *)((char *)v13 + 34) = 1 << v11;
    v15 = ((int (__fastcall *)(_DWORD, int, int))a1[8])(a1[10], 1 << v11, 2);
    v16 = *(_DWORD *)((char *)v13 + 34);
    *(_DWORD *)((char *)v13 + 46) = v15;
    v17 = ((int (__fastcall *)(_DWORD, int, int))a1[8])(a1[10], v16, 2);
    v18 = *(_DWORD *)((char *)v13 + 66);
    *(_DWORD *)((char *)v13 + 54) = v17;
    *(_DWORD *)((char *)v13 + 58) = ((int (__fastcall *)(_DWORD, int, int))a1[8])(a1[10], v18, 2);
    *(_DWORD *)((char *)v13 + 5775) = 1 << (a5 + 6);
    v19 = ((int (__thiscall *)(_DWORD, int))a1[8])(a1[10], 4);
    v20 = *(_DWORD *)((char *)v13 + 5775);
    v13[3] = 4 * v20;
    v21 = *(_DWORD *)((char *)v13 + 46);
    v13[2] = v19;
    if ( v21 && *(_DWORD *)((char *)v13 + 54) && *(_DWORD *)((char *)v13 + 58) && v19 )
    {
      *(_DWORD *)((char *)v13 + 5783) = v19 + 2 * (v20 >> 1);
      *(_DWORD *)((char *)v13 + 122) = v23;
      *(_DWORD *)((char *)v13 + 5771) = v20 + v19 + 2 * v20;
      *(_DWORD *)((char *)v13 + 126) = a6;
      *((_BYTE *)v13 + 29) = 8;
      return sub_62C280(a1);
    }
    a1[6] = off_91169C[0];
    sub_62B4F0((int)a1);
  }
  return -4;
}
