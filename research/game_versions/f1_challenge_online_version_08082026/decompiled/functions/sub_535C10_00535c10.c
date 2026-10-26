int __fastcall sub_535C10(_DWORD *a1, unsigned int a2, int a3, int a4, int a5, unsigned int a6, _BYTE *a7, int a8)
{
  int v9; // ebp
  int v11; // eax
  int v12; // ebx
  _DWORD *v13; // eax
  _DWORD *v14; // esi
  int v15; // eax
  int v16; // eax
  int v17; // edx
  int v18; // eax
  int v19; // edx
  int v20; // eax
  unsigned int v21; // ecx
  int v22; // [esp+14h] [ebp-4h]

  v9 = 0;
  v22 = a2;
  if ( !a7 || *a7 != *off_5DA818[0] || a8 != 56 )
    return -6;
  if ( !a1 )
    return -2;
  v11 = a1[8];
  a1[6] = 0;
  if ( !v11 )
  {
    a1[8] = sub_536FD0;
    a1[10] = 0;
  }
  if ( !a1[9] )
    a1[9] = &sub_536FF0;
  if ( a2 == -1 )
  {
    v22 = 6;
    a2 = 6;
  }
  v12 = a4;
  if ( a4 < 0 )
  {
    v9 = 1;
    v12 = -a4;
  }
  if ( a5 < 1 || a5 > 9 || a3 != 8 || v12 < 8 || v12 > 15 || a2 > 9 || a6 > 2 )
    return -2;
  v13 = (_DWORD *)((int (__fastcall *)(_DWORD, int, int))a1[8])(a1[10], 1, 5809);
  v14 = v13;
  if ( !v13 )
    return -4;
  a1[7] = v13;
  v13[6] = v9;
  *(_DWORD *)((char *)v13 + 38) = v12;
  *v13 = a1;
  *(_DWORD *)((char *)v13 + 34) = 1 << v12;
  *(_DWORD *)((char *)v13 + 42) = (1 << v12) - 1;
  v15 = 1 << (a5 + 7);
  *(_DWORD *)((char *)v14 + 70) = a5 + 7;
  *(_DWORD *)((char *)v14 + 66) = v15;
  *(_DWORD *)((char *)v14 + 74) = v15 - 1;
  *(_DWORD *)((char *)v14 + 78) = (a5 + 9) / 3u;
  v16 = ((int (__fastcall *)(_DWORD, int, int))a1[8])(a1[10], 1 << v12, 2);
  v17 = *(_DWORD *)((char *)v14 + 34);
  *(_DWORD *)((char *)v14 + 46) = v16;
  v18 = ((int (__fastcall *)(_DWORD, int, int))a1[8])(a1[10], v17, 2);
  v19 = *(_DWORD *)((char *)v14 + 66);
  *(_DWORD *)((char *)v14 + 54) = v18;
  *(_DWORD *)((char *)v14 + 58) = ((int (__fastcall *)(_DWORD, int, int))a1[8])(a1[10], v19, 2);
  *(_DWORD *)((char *)v14 + 5775) = 1 << (a5 + 6);
  v20 = ((int (__thiscall *)(_DWORD, int))a1[8])(a1[10], 4);
  v21 = *(_DWORD *)((char *)v14 + 5775);
  v14[2] = v20;
  v14[3] = 4 * v21;
  if ( *(_DWORD *)((char *)v14 + 46) && *(_DWORD *)((char *)v14 + 54) && *(_DWORD *)((char *)v14 + 58) && v20 )
  {
    *((_BYTE *)v14 + 29) = 8;
    *(_DWORD *)((char *)v14 + 5783) = v20 + 2 * (v21 >> 1);
    *(_DWORD *)((char *)v14 + 5771) = v20 + 2 * v21 + v21;
    *(_DWORD *)((char *)v14 + 126) = a6;
    *(_DWORD *)((char *)v14 + 122) = v22;
    return sub_535E10(a1);
  }
  else
  {
    a1[6] = off_5DA834[0];
    sub_5361D0(a1);
    return -4;
  }
}
