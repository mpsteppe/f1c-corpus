int __thiscall sub_502730(CHAR ****this)
{
  CHAR ***v2; // eax
  bool v3; // zf
  CHAR **i; // eax
  CHAR *v5; // eax
  int v6; // eax
  CHAR ***v7; // eax
  CHAR ***v8; // eax
  CHAR ***v9; // esi
  CHAR ***v10; // ebp
  char v11; // al
  int result; // eax

  v2 = *this;
  v3 = *this == 0;
  this[2] = *this;
  if ( !v3 )
  {
    for ( i = *v2; i; i = *v8 )
    {
      v5 = *i;
      if ( !v5 )
        v5 = &byte_629120;
      v6 = sub_592CD0(v5);
      sub_592C40(v6);
      v7 = this[2];
      if ( !v7 )
        break;
      v8 = (CHAR ***)v7[1];
      this[2] = v8;
      if ( !v8 )
        break;
    }
  }
  v9 = *this;
  while ( v9 )
  {
    v10 = v9;
    v11 = *((_BYTE *)v9 + 8);
    v9 = (CHAR ***)v9[1];
    if ( v11 && *v10 )
    {
      if ( **v10 )
        sub_5BE8AE();
      sub_5BE8AE();
    }
    sub_5BE8AE();
  }
  result = 0;
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  return result;
}
