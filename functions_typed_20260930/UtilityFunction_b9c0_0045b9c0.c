char __thiscall sub_45B9C0(char *this, const char *a2, int a3, int a4, int a5)
{
  int v7; // eax
  _DWORD *v8; // ecx
  int v9; // esi
  char *v10; // esi

  if ( !a2 || !strlen(a2) )
    return 0;
  if ( StringArrayComparisonSearch(this, a2) )
    return 1;
  v7 = RotatingIndexSearchWithThreshold((int *)this, a5);
  v9 = v7;
  if ( v7 < 0 )
    return 0;
  PerIndexStructFieldResetter(v8, v7);
  v10 = &this[92 * v9];
  sub_587DD0(v10 + 60, a2, 79);
  v10[139] = 0;
  *((_DWORD *)v10 + 37) = a5;
  *((_DWORD *)v10 + 35) = a3;
  *((_DWORD *)v10 + 36) = a4;
  return 1;
}

