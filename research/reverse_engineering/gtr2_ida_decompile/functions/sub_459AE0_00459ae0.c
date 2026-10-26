int __thiscall sub_459AE0(int *this)
{
  int result; // eax
  int v3; // esi
  int v4; // edx
  float *v5; // ecx
  float *v6; // ebx
  float *v7; // ebp
  int v8; // eax
  int v9; // ecx
  int v10; // eax
  int i; // [esp+8h] [ebp-4h]

  result = *this;
  v3 = 0;
  for ( i = 0; i < *this; ++i )
  {
    v4 = this[2];
    v5 = *(float **)(v3 + v4 + 8);
    v6 = *(float **)(v3 + v4);
    v7 = *(float **)(v3 + v4 + 16);
    if ( *v6 == *v5 && v6[4] == v5[4] || *v5 == *v7 && v5[4] == v7[4] || *v7 == *v6 && v7[4] == v6[4] )
    {
      v8 = 32 * *this;
      v9 = *(_DWORD *)(v8 + v4 - 32);
      v10 = v8 + v4 - 32;
      *(_DWORD *)(v3 + v4) = v9;
      *(_DWORD *)(v3 + v4 + 4) = *(_DWORD *)(v10 + 4);
      *(_DWORD *)(v3 + v4 + 8) = *(_DWORD *)(v10 + 8);
      *(_DWORD *)(v3 + v4 + 12) = *(_DWORD *)(v10 + 12);
      *(_DWORD *)(v3 + v4 + 16) = *(_DWORD *)(v10 + 16);
      *(_DWORD *)(v3 + v4 + 20) = *(_DWORD *)(v10 + 20);
      *(_BYTE *)(v3 + v4 + 24) = *(_BYTE *)(v10 + 24);
      *(_BYTE *)(v3 + v4 + 25) = *(_BYTE *)(v10 + 25);
      *(_WORD *)(v3 + v4 + 26) = *(_WORD *)(v10 + 26);
      --*this;
    }
    result = i + 1;
    v3 += 32;
  }
  return result;
}
