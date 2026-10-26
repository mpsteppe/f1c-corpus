int __cdecl strtoxl(char *a1, char **a2, int a3, int a4)
{
  int *v4; // esi
  char *v5; // ecx
  char v6; // bl
  char *i; // edi
  int v8; // eax
  char *v9; // edi
  unsigned int v10; // eax
  wchar_t v11; // cx
  unsigned int v12; // ecx
  int v13; // ecx
  char *v14; // edi
  unsigned int v16; // [esp+Ch] [ebp-4h]

  v4 = *(int **)(_getptd() + 100);
  if ( v4 != off_91290C )
    v4 = (int *)__updatetlocinfo();
  v5 = a1;
  v16 = 0;
  v6 = *a1;
  for ( i = a1 + 1; ; ++i )
  {
    if ( v4[10] <= 1 )
    {
      v8 = *(_BYTE *)(v4[18] + 2 * (unsigned __int8)v6) & 8;
    }
    else
    {
      v8 = __isctype_mt(v4, (unsigned __int8)v6, 8);
      v5 = a1;
    }
    if ( !v8 )
      break;
    v6 = *i;
  }
  if ( v6 == 45 )
  {
    a4 |= 2u;
LABEL_12:
    v6 = *i++;
    goto LABEL_13;
  }
  if ( v6 == 43 )
    goto LABEL_12;
LABEL_13:
  if ( a3 < 0 || a3 == 1 || a3 > 36 )
  {
    if ( a2 )
      *a2 = v5;
    return 0;
  }
  if ( !a3 )
  {
    if ( v6 != 48 )
    {
      a3 = 10;
      goto LABEL_28;
    }
    if ( *i != 120 && *i != 88 )
    {
      a3 = 8;
      goto LABEL_28;
    }
    a3 = 16;
  }
  if ( a3 == 16 && v6 == 48 && (*i == 120 || *i == 88) )
  {
    v9 = i + 1;
    v6 = *v9;
    i = v9 + 1;
  }
LABEL_28:
  v10 = 0xFFFFFFFF / a3;
  while ( 1 )
  {
    v11 = off_913150[(unsigned __int8)v6];
    if ( (v11 & 4) != 0 )
    {
      v12 = v6 - 48;
    }
    else
    {
      if ( (v11 & 0x103) == 0 )
        break;
      v13 = v6 < 97 || v6 > 122 ? v6 : v6 - 32;
      v12 = v13 - 55;
    }
    if ( v12 >= a3 )
      break;
    a4 |= 8u;
    if ( v16 < v10 || v16 == v10 && v12 <= 0xFFFFFFFF % a3 )
      v16 = v12 + a3 * v16;
    else
      a4 |= 4u;
    v6 = *i++;
  }
  v14 = i - 1;
  if ( (a4 & 8) != 0 )
  {
    if ( (a4 & 4) != 0 || (a4 & 1) == 0 && ((a4 & 2) != 0 && v16 > 0x80000000 || (a4 & 2) == 0 && v16 > 0x7FFFFFFF) )
    {
      *_errno() = 34;
      if ( (a4 & 1) != 0 )
        v16 = -1;
      else
        v16 = ((a4 & 2) != 0) + 0x7FFFFFFF;
    }
  }
  else
  {
    if ( a2 )
      v14 = a1;
    v16 = 0;
  }
  if ( a2 )
    *a2 = v14;
  if ( (a4 & 2) != 0 )
    return -v16;
  return v16;
}
