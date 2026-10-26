int __thiscall sub_40A660(int **this, char *String1)
{
  int *v3; // eax
  bool v4; // zf
  int v5; // esi
  const char *v6; // eax
  int *v7; // eax
  int *v8; // eax

  v3 = *this;
  v4 = *this == 0;
  this[2] = *this;
  if ( v4 )
    return 0;
  v5 = *v3;
  if ( *v3 )
  {
    do
    {
      v6 = (const char *)sub_459B80(v5);
      if ( !_strcmpi(String1, v6) )
        break;
      v7 = this[2];
      if ( !v7 )
        return 0;
      v8 = (int *)v7[1];
      this[2] = v8;
      if ( !v8 )
        return 0;
      v5 = *v8;
    }
    while ( *v8 );
  }
  return v5;
}
