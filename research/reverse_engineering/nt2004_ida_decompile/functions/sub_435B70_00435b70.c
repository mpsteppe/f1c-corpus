int __thiscall sub_435B70(const char **this, int a2)
{
  int v3; // eax
  const char *v4; // edx
  unsigned int v5; // kr04_4
  const char *i; // eax
  char *v7; // eax
  _BYTE v9[512]; // [esp+4h] [ebp-200h] BYREF

  v3 = sub_4CE000(a2);
  sub_578600(v3);
  v4 = *this;
  if ( !*this )
    v4 = &byte_629120;
  v5 = strlen(v4) + 1;
  if ( (int)(v5 - 1) > 0 )
  {
    for ( i = &v4[v5 - 2]; i >= v4; *i-- = 0 )
    {
      if ( *i == 92 )
        break;
    }
  }
  sub_578560(off_5FE074[0]);
  v7 = (char *)*this;
  if ( !*this )
    v7 = &byte_629120;
  sub_57B040(v7, 512);
  return sub_578600(v9);
}
