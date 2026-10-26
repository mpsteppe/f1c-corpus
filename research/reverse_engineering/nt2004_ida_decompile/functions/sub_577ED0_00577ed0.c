int __thiscall sub_577ED0(char *String, char *String2, char *Stringa, char *a4)
{
  int v5; // edx
  char *v6; // ecx
  char v7; // al
  int v8; // eax
  char *v9; // eax
  char *v10; // edx
  char v11; // cl
  char *v12; // eax
  char *v13; // edx
  char v14; // cl

  v5 = 0;
  if ( !String[408] )
    goto LABEL_8;
  v6 = String + 408;
  do
  {
    v7 = *++v6;
    if ( v7 == 61 )
      ++v5;
  }
  while ( v7 );
  if ( v5 == 1 )
    v8 = sub_577DA0(String, String2);
  else
LABEL_8:
    v8 = sub_577DB0(String, String2);
  if ( !v8 )
    return 0;
  strcpy(String, *((const char **)String + 96));
  v9 = strtok(String, asc_6100B8);
  if ( v9 )
  {
    if ( Stringa )
    {
      v10 = (char *)(Stringa - v9);
      do
      {
        v11 = *v9;
        v9[(_DWORD)v10] = *v9;
        ++v9;
      }
      while ( v11 );
      _strupr(Stringa);
      v12 = strtok(0, asc_6100B8);
      if ( v12 )
      {
        if ( a4 )
        {
          v13 = (char *)(a4 - v12);
          do
          {
            v14 = *v12;
            v12[(_DWORD)v13] = *v12;
            ++v12;
          }
          while ( v14 );
          _strupr(a4);
        }
      }
    }
  }
  return 1;
}
