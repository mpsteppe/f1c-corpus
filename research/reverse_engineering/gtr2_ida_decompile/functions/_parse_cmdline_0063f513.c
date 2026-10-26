char **__usercall parse_cmdline@<eax>(char *a1@<eax>, char *a2@<ecx>, _DWORD *a3@<esi>, char **a4, _DWORD *a5)
{
  _DWORD *v5; // ebx
  BOOL v6; // edx
  char **v8; // ecx
  char v9; // cl
  int v10; // ebx
  char **v11; // ecx
  int v12; // ebx
  unsigned int v13; // edx
  unsigned __int8 v14; // cl
  char **result; // eax
  BOOL v16; // [esp+8h] [ebp-4h]

  v5 = a5;
  v6 = 0;
  *a3 = 0;
  *a5 = 1;
  if ( a4 )
  {
    v8 = a4++;
    *v8 = a2;
  }
  do
  {
    if ( *a1 == 34 )
    {
      ++a1;
      v6 = !v6;
      v9 = 34;
    }
    else
    {
      ++*a3;
      if ( a2 )
        *a2++ = *a1;
      v9 = *a1;
      v10 = (unsigned __int8)*a1++;
      if ( (byte_FBB281[v10] & 4) != 0 )
      {
        ++*a3;
        if ( a2 )
          *a2++ = *a1;
        ++a1;
      }
      v5 = a5;
      if ( !v9 )
      {
        --a1;
        goto LABEL_17;
      }
    }
  }
  while ( v6 || v9 != 32 && v9 != 9 );
  if ( a2 )
    *(a2 - 1) = 0;
LABEL_17:
  v16 = 0;
  while ( *a1 )
  {
    while ( *a1 == 32 || *a1 == 9 )
      ++a1;
    if ( !*a1 )
      break;
    if ( a4 )
    {
      v11 = a4++;
      *v11 = a2;
    }
    ++*v5;
    while ( 1 )
    {
      v12 = 1;
      v13 = 0;
      while ( *a1 == 92 )
      {
        ++a1;
        ++v13;
      }
      if ( *a1 == 34 )
      {
        if ( (v13 & 1) == 0 )
        {
          if ( v16 && a1[1] == 34 )
            ++a1;
          else
            v12 = 0;
          v16 = !v16;
        }
        v13 >>= 1;
      }
      for ( ; v13; --v13 )
      {
        if ( a2 )
          *a2++ = 92;
        ++*a3;
      }
      v14 = *a1;
      if ( !*a1 || !v16 && (v14 == 32 || v14 == 9) )
        break;
      if ( v12 )
      {
        if ( a2 )
        {
          if ( (byte_FBB281[v14] & 4) != 0 )
          {
            *a2++ = v14;
            ++a1;
            ++*a3;
          }
          *a2++ = *a1;
        }
        else if ( (byte_FBB281[v14] & 4) != 0 )
        {
          ++a1;
          ++*a3;
        }
        ++*a3;
      }
      ++a1;
    }
    if ( a2 )
      *a2++ = 0;
    ++*a3;
    v5 = a5;
  }
  result = a4;
  if ( a4 )
    *a4 = 0;
  ++*v5;
  return result;
}
