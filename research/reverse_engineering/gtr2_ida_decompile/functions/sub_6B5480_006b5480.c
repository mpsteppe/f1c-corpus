_DWORD *__stdcall sub_6B5480(int *a1, unsigned int a2, unsigned int a3)
{
  unsigned int v3; // ebx
  int v5; // eax
  int v6; // eax
  _DWORD *v7; // esi
  int v8; // eax
  int v9; // edx
  int v11; // [esp+14h] [ebp+8h]

  v3 = a3;
  v11 = a1[1];
  if ( a3 > 0x3B9AC9F0 )
  {
    v5 = *a1;
    *(_DWORD *)(v5 + 20) = 54;
    *(_DWORD *)(v5 + 24) = 3;
    (*(void (__stdcall **)(int *))v5)(a1);
  }
  if ( (a3 & 7) != 0 )
    v3 = 8 - (a3 & 7) + a3;
  if ( a2 >= 2 )
  {
    v6 = *a1;
    *(_DWORD *)(v6 + 20) = 14;
    *(_DWORD *)(v6 + 24) = a2;
    (*(void (__stdcall **)(int *))v6)(a1);
  }
  v7 = (_DWORD *)sub_6D3B00(a1, v3 + 16);
  if ( !v7 )
  {
    v8 = *a1;
    *(_DWORD *)(v8 + 20) = 54;
    *(_DWORD *)(v8 + 24) = 4;
    (*(void (__stdcall **)(int *))v8)(a1);
  }
  *(_DWORD *)(v11 + 76) += v3 + 16;
  v9 = *(_DWORD *)(v11 + 4 * a2 + 60);
  *(_DWORD *)(v11 + 4 * a2 + 60) = v7;
  v7[1] = v3;
  *v7 = v9;
  v7[2] = 0;
  return v7 + 4;
}
