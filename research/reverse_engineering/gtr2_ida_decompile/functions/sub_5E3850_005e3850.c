int __thiscall sub_5E3850(_DWORD *this, int a2, int a3)
{
  int **v4; // eax
  int *v5; // ecx
  int result; // eax
  int v7; // eax
  int **v8; // eax

  v4 = (int **)this[133];
  this[135] = v4;
  if ( !v4 )
    return 0;
  v5 = *v4;
  if ( !*v4 )
    return 0;
  while ( 1 )
  {
    result = sub_5E3740(v5, a2, a3);
    if ( result )
      break;
    v7 = this[135];
    if ( v7 )
      this[135] = *(_DWORD *)(v7 + 4);
    v8 = (int **)this[135];
    if ( v8 )
    {
      v5 = *v8;
      if ( *v8 )
        continue;
    }
    return 0;
  }
  return result;
}
