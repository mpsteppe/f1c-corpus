char __thiscall sub_45CCB0(char *this, char *Source, int a3, int a4, int a5)
{
  int v7; // eax
  _DWORD *v8; // ecx
  int v9; // esi
  char *v10; // esi

  if ( !Source || !strlen(Source) )
    return 0;
  if ( sub_45C720(this, Source) )
    return 1;
  v7 = sub_45C7A0((int *)this, a5);
  v9 = v7;
  if ( v7 < 0 )
    return 0;
  sub_45C6C0(v8, v7);
  v10 = &this[140 * v9];
  strncpy(v10 + 68, Source, 0x7Fu);
  v10[195] = 0;
  *((_DWORD *)v10 + 51) = a5;
  *((_DWORD *)v10 + 49) = a3;
  *((_DWORD *)v10 + 50) = a4;
  return 1;
}
