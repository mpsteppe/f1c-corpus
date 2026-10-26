_DWORD *__thiscall sub_67677A(_DWORD *this, char *a2, int a3)
{
  char v4; // al
  unsigned int v5; // edi
  int v6; // eax
  unsigned int i; // edi
  _DWORD *v8; // ecx
  int v9; // eax
  unsigned int v12; // [esp+18h] [ebp+8h]
  unsigned int v13; // [esp+1Ch] [ebp+Ch]

  while ( 1 )
  {
    while ( isspace(*a2) )
      ++a2;
    v4 = *a2;
    if ( !*a2 )
      return this;
    if ( v4 != 91 )
      break;
    do
      ++a2;
    while ( isspace(*a2) );
    if ( !isdigit(*a2) )
      return 0;
    v5 = 0;
    while ( isdigit(*a2) )
      v5 = *a2++ + 10 * v5 - 48;
    while ( isspace(*a2) )
      ++a2;
    if ( *a2 != 93 )
      return 0;
    v6 = sub_676393((int)this, v5);
    if ( !v6 )
      return 0;
    a3 = 0;
    ++a2;
LABEL_34:
    this = (_DWORD *)v6;
  }
  if ( v4 == 46 )
    goto LABEL_20;
  if ( a3 )
  {
    while ( isspace(*a2) )
LABEL_20:
      ++a2;
    for ( i = 0; isalnum(a2[i]) || a2[i] == 95; ++i )
      ;
    if ( i )
    {
      v8 = this;
      v13 = 0;
      v12 = *(unsigned __int16 *)(this[6] + 10);
      while ( v13 < v12 )
      {
        v9 = *(_DWORD *)(*(_DWORD *)(v8[14] + 4 * v13) + 4);
        if ( v9 && !sub_67347A(a2, v9 + *(_DWORD *)(*v8 + 8), i) )
        {
          v6 = sub_6736C9(this, v13);
          if ( !v6 )
            return 0;
          a3 = 0;
          a2 += i;
          goto LABEL_34;
        }
        ++v13;
        v8 = this;
      }
    }
  }
  return 0;
}
