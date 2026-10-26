void __thiscall sub_4EDE00(_DWORD *this, char *Destination, int a3)
{
  int v3; // edi
  const char **v4; // eax
  const char *v5; // ecx
  const char *v6; // eax
  CHAR *v7; // eax

  if ( Destination && a3 > 0 )
  {
    v3 = dword_7D6A5C + 1232 * this[6313];
    if ( !(unsigned __int8)sub_4EED40(this) )
      goto LABEL_12;
    if ( *(_DWORD *)dword_7689CC != 8 )
      goto LABEL_12;
    v4 = (const char **)(*(int (__thiscall **)(int))(*(_DWORD *)dword_76BB24 + 100))(dword_76BB24);
    if ( !v4 )
      goto LABEL_12;
    v5 = *v4;
    if ( !*v4 )
      v5 = &byte_629120;
    v6 = *(const char **)v3;
    if ( !*(_DWORD *)v3 )
      v6 = &byte_629120;
    if ( !_strcmpi(v6, v5) )
    {
      v7 = sub_46DFA0();
      strncpy(Destination, v7, a3 - 1);
      Destination[a3 - 1] = 0;
    }
    else
    {
LABEL_12:
      if ( v3 )
        strncpy(Destination, (const char *)(v3 + 168), a3 - 1);
      else
        strncpy(Destination, &byte_629120, a3 - 1);
      Destination[a3 - 1] = 0;
    }
  }
}
