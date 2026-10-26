int __thiscall sub_688FBF(_DWORD *this, int a2, int a3)
{
  int v3; // eax
  unsigned int *v4; // esi
  _DWORD *v5; // edi
  int result; // eax
  unsigned int v7; // edx
  unsigned int v8; // eax
  unsigned int v9; // ecx
  bool v10; // zf

  v3 = this[5];
  v4 = *(unsigned int **)(v3 + 4 * a2);
  v5 = *(_DWORD **)(v3 + 4 * a3);
  v5[12] = a2;
  result = sub_688F3E(this, v4, (int)v5);
  if ( result >= 0 )
  {
    v7 = *v4 & 0xE000000;
    v8 = *v5 & 0xE000000;
    v9 = *v4 & 0xF1FFFFFF;
    *v4 = v9;
    if ( v7 > v8 )
      v8 = v7;
    v10 = v4[24] == 0;
    *v4 = v8 | v9;
    if ( v10 )
    {
      v4[24] = v5[24];
      v4[25] = v5[25];
    }
    return 0;
  }
  return result;
}
