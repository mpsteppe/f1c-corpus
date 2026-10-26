int __thiscall sub_5223B0(char *this, int a2, float a3, char a4)
{
  char *v4; // edx
  int *v5; // eax
  bool v6; // zf
  int v7; // ecx
  int v8; // eax
  int *v9; // eax

  v4 = &this[16 * a2 + 64];
  v5 = *(int **)v4;
  v6 = *(_DWORD *)v4 == 0;
  *((_DWORD *)v4 + 2) = *(_DWORD *)v4;
  if ( v6 )
    return 0;
  v7 = *v5;
  if ( !*v5 )
    return 0;
  while ( 1 )
  {
    if ( a4 )
      *(_DWORD *)(v7 + 196) = 0;
    if ( (*(_DWORD *)(v7 + 196) == -190986834 || a3 >= (double)*(float *)(v7 + 196))
      && (*(_DWORD *)(v7 + 200) == -190986834 || a3 <= (double)*(float *)(v7 + 200)) )
    {
      return v7;
    }
    v8 = *((_DWORD *)v4 + 2);
    if ( v8 )
      *((_DWORD *)v4 + 2) = *(_DWORD *)(v8 + 4);
    v9 = (int *)*((_DWORD *)v4 + 2);
    if ( !v9 )
      break;
    v7 = *v9;
    if ( !*v9 )
      return v7;
  }
  return 0;
}
