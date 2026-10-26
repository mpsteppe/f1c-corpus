int __thiscall sub_435480(char **this)
{
  char *v2; // ecx
  char *v3; // eax
  int v4; // edi
  int v5; // eax
  int v6; // ecx
  const char **v7; // esi
  const char *v8; // eax
  char *v9; // esi

  sub_434F10(this);
  sub_434FA0((CHAR ***)this);
  sub_435470(this);
  v2 = dword_766594;
  if ( !dword_766594 )
    v2 = &byte_629120;
  v3 = sub_435430(v2);
  sub_578600(v3);
  if ( sub_41F230(dword_62A170, &byte_629120, Destination) )
  {
    if ( &byte_629120 )
    {
      strncpy(Destination, &byte_629120, 0x1FFu);
      byte_62A37B = 0;
    }
    else
    {
      Destination[0] = 0;
    }
  }
  sub_578600(Destination);
  v4 = 0;
  while ( 1 )
  {
    v5 = v4++;
    if ( v5 < 0 || v5 >= *((_DWORD *)*this + 11) )
      break;
    v6 = *((_DWORD *)*this + 8);
    if ( v5 > 0 )
    {
      while ( v6 )
      {
        v6 = *(_DWORD *)(v6 + 4);
        if ( --v5 <= 0 )
          goto LABEL_13;
      }
      break;
    }
LABEL_13:
    if ( !v6 )
      break;
    v7 = *(const char ***)v6;
    if ( !*(_DWORD *)v6 )
      break;
    v8 = *v7;
    if ( !*v7 )
      v8 = &byte_629120;
    if ( !_strcmpi(v8, &byte_629120) )
    {
      v9 = (char *)*v7;
      if ( !v9 )
        v9 = &byte_629120;
      sub_435700(v9);
      break;
    }
  }
  sub_435470(this);
  return 0;
}
