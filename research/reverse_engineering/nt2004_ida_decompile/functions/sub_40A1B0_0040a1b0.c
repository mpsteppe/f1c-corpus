char __thiscall sub_40A1B0(int **this, char *String2)
{
  int *v3; // ecx
  const char *v4; // eax
  int *v5; // eax
  bool v6; // zf
  int v7; // eax
  const char *v8; // eax
  int *v9; // eax
  int *v10; // eax

  v3 = this[4];
  if ( v3 )
  {
    v4 = (const char *)sub_459B80(v3);
    if ( !_strcmpi(v4, String2) )
      return 0;
  }
  v5 = *this;
  v6 = *this == 0;
  this[2] = *this;
  if ( v6 )
    return 0;
  v7 = *v5;
  if ( !v7 )
    return 0;
  while ( 1 )
  {
    v8 = (const char *)sub_459B80(v7);
    v6 = _strcmpi(v8, String2) == 0;
    v9 = this[2];
    if ( v6 )
      break;
    if ( v9 )
    {
      v10 = (int *)v9[1];
      this[2] = v10;
      if ( v10 )
      {
        v7 = *v10;
        if ( v7 )
          continue;
      }
    }
    return 0;
  }
  if ( v9 )
    return sub_40A7D0(*v9);
  else
    return sub_40A7D0(0);
}
