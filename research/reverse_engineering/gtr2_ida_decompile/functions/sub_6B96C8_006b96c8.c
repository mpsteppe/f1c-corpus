int __stdcall sub_6B96C8(_DWORD *a1, unsigned int a2, int a3, int a4, int a5, unsigned int a6, _BYTE *a7, int a8)
{
  bool v8; // zf
  int v9; // ebx
  int v10; // esi
  int v11; // eax
  int v12; // eax
  int v13; // eax
  unsigned int v14; // ebx
  int v16; // [esp-8h] [ebp-18h]
  int v17; // [esp-8h] [ebp-18h]
  int v19; // [esp+Ch] [ebp-4h]

  v19 = 0;
  if ( !a7 || *a7 != *off_91AA4C || a8 != 56 )
    return -6;
  if ( !a1 )
    return -2;
  v8 = a1[8] == 0;
  a1[6] = 0;
  if ( v8 )
  {
    a1[8] = sub_6DAC77;
    a1[10] = 0;
  }
  if ( !a1[9] )
    a1[9] = sub_6DAC93;
  if ( a2 == -1 )
    a2 = 6;
  v9 = a4;
  if ( a4 < 0 )
  {
    v9 = -a4;
    v19 = 1;
    a4 = -a4;
  }
  if ( a5 < 1 || a5 > 9 || a3 != 8 || v9 < 9 || v9 > 15 || a2 > 9 || a6 > 2 )
    return -2;
  v10 = ((int (__stdcall *)(_DWORD, int, int))a1[8])(a1[10], 1, 5816);
  if ( v10 )
  {
    a1[7] = v10;
    *(_DWORD *)(v10 + 40) = v9;
    *(_DWORD *)(v10 + 24) = v19;
    *(_DWORD *)(v10 + 44) = (1 << a4) - 1;
    *(_DWORD *)(v10 + 72) = a5 + 7;
    *(_DWORD *)v10 = a1;
    *(_DWORD *)(v10 + 68) = 1 << (a5 + 7);
    *(_DWORD *)(v10 + 76) = (1 << (a5 + 7)) - 1;
    *(_DWORD *)(v10 + 36) = 1 << a4;
    *(_DWORD *)(v10 + 80) = (a5 + 9) / 3u;
    v11 = ((int (__stdcall *)(_DWORD, int, int))a1[8])(a1[10], 1 << a4, 2);
    v16 = *(_DWORD *)(v10 + 36);
    *(_DWORD *)(v10 + 48) = v11;
    v12 = ((int (__stdcall *)(_DWORD, int, int))a1[8])(a1[10], v16, 2);
    v17 = *(_DWORD *)(v10 + 68);
    *(_DWORD *)(v10 + 56) = v12;
    *(_DWORD *)(v10 + 60) = ((int (__stdcall *)(_DWORD, int, int))a1[8])(a1[10], v17, 2);
    *(_DWORD *)(v10 + 5780) = 1 << (a5 + 6);
    v13 = ((int (__stdcall *)(_DWORD, int, int))a1[8])(a1[10], 1 << (a5 + 6), 4);
    v14 = *(_DWORD *)(v10 + 5780);
    *(_DWORD *)(v10 + 12) = 4 * v14;
    v8 = *(_DWORD *)(v10 + 48) == 0;
    *(_DWORD *)(v10 + 8) = v13;
    if ( !v8 && *(_DWORD *)(v10 + 56) && *(_DWORD *)(v10 + 60) && v13 )
    {
      *(_DWORD *)(v10 + 5776) = v14 + v13 + 2 * v14;
      *(_DWORD *)(v10 + 124) = a2;
      *(_DWORD *)(v10 + 5788) = v13 + 2 * (v14 >> 1);
      *(_DWORD *)(v10 + 128) = a6;
      *(_BYTE *)(v10 + 29) = 8;
      return sub_6B9659(a1);
    }
    a1[6] = off_91AAA4[0];
    sub_6B8B6D((int)a1);
  }
  return -4;
}
