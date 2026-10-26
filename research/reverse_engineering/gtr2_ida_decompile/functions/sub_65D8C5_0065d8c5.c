int __thiscall sub_65D8C5(_DWORD *this, char *a2, double *a3)
{
  char *i; // ebx
  unsigned int v5; // eax
  _BYTE *v6; // esi
  char v8[12]; // [esp+0h] [ebp-10h] BYREF
  int v9; // [esp+Ch] [ebp-4h]

  v9 = 0;
  i = a2;
  if ( (unsigned int)a2 < this[1] && isdigit(*a2) )
  {
    do
      ++i;
    while ( (unsigned int)i < this[1] && isdigit(*i) );
    v5 = this[1];
    if ( (unsigned int)i < v5 && *i == 46 )
    {
      if ( (unsigned int)++i < v5 )
      {
        do
        {
          if ( !isdigit(*i) )
            break;
          ++i;
        }
        while ( (unsigned int)i < this[1] );
      }
    }
    else
    {
      v9 = 1;
    }
  }
  else
  {
    if ( (unsigned int)(a2 + 1) >= this[1] || *a2 != 46 || !isdigit(a2[1]) )
      return 0;
    for ( i = a2 + 2; (unsigned int)i < this[1] && isdigit(*i); ++i )
      ;
  }
  v6 = i + 1;
  if ( (unsigned int)(i + 1) < this[1] && sub_635155(*i) == 101 && isdigit((char)*v6) )
  {
    for ( i += 2; (unsigned int)i < this[1] && isdigit(*i); ++i )
      ;
    goto LABEL_37;
  }
  if ( (unsigned int)(i + 2) < this[1] && sub_635155(*i) == 101 && *v6 == 45 && isdigit(i[2]) )
  {
    for ( i += 3; (unsigned int)i < this[1] && isdigit(*i); ++i )
      ;
    goto LABEL_37;
  }
  if ( v9 )
    return 0;
LABEL_37:
  if ( a3 )
  {
    v9 = i - a2;
    sub_631BD0((i - a2 + 4) & 0xFFFFFFFC, v8[0]);
    qmemcpy(v8, a2, i - a2);
    v8[i - a2] = 0;
    *a3 = atof(v8);
  }
  return i - a2;
}
