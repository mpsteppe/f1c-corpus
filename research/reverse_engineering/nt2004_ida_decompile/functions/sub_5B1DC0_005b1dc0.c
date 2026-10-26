int __thiscall sub_5B1DC0(int this, char *String2, char *String, char *a4)
{
  int v5; // edx
  int v6; // ecx
  char v7; // al
  BOOL v8; // eax
  const char *v9; // ecx
  char *v10; // esi
  char *v11; // eax
  char *v12; // edx
  char v13; // cl
  char *v14; // eax
  char *v15; // edx
  char v16; // cl

  v5 = 0;
  if ( !*(_BYTE *)(this + 12) )
    goto LABEL_8;
  v6 = this + 12;
  do
  {
    v7 = *(_BYTE *)++v6;
    if ( v7 == 61 )
      ++v5;
  }
  while ( v7 );
  if ( v5 == 1 )
    v8 = sub_5B1CB0((char *)this, String2);
  else
LABEL_8:
    v8 = sub_5B1D20((const char **)this, String2);
  if ( !v8 )
    return 0;
  v9 = *(const char **)(this + 2060);
  v10 = (char *)(this + 1036);
  strcpy(v10, v9);
  v11 = strtok(v10, asc_6100B8);
  if ( v11 )
  {
    if ( String )
    {
      v12 = (char *)(String - v11);
      do
      {
        v13 = *v11;
        v11[(_DWORD)v12] = *v11;
        ++v11;
      }
      while ( v13 );
      _strupr(String);
      v14 = strtok(0, asc_6100B8);
      if ( v14 )
      {
        if ( a4 )
        {
          v15 = (char *)(a4 - v14);
          do
          {
            v16 = *v14;
            v14[(_DWORD)v15] = *v14;
            ++v14;
          }
          while ( v16 );
          _strupr(a4);
        }
      }
    }
  }
  return 1;
}
