int sub_42DC40()
{
  int v0; // ebx
  _DWORD *v1; // eax
  int *v2; // edx
  char *v3; // ecx
  int *v4; // eax
  int v5; // eax
  int v6; // ecx

  v0 = 0;
  v1 = &unk_62BF68;
  do
  {
    if ( v1[4146] != -1 )
      dword_75AAD0[v0++] = (int)v1;
    v1 += 6326;
  }
  while ( (int)v1 < (int)byte_7547E8 );
  if ( v0 < 48 )
  {
    memset((void *)(4 * v0 + 7711440), 0, 4 * (48 - v0));
    v2 = (int *)(4 * v0 + 7711440);
    do
    {
      v3 = (char *)&unk_62BF68;
      while ( 2 )
      {
        v4 = dword_75AAD0;
        while ( (char *)*v4 != v3 )
        {
          if ( (int)++v4 >= (int)&dword_75AB90 )
          {
            if ( v3 )
            {
              *v2 = (int)v3;
              goto LABEL_15;
            }
            break;
          }
        }
        v3 += 25304;
        if ( (int)v3 < (int)byte_7547E8 )
          continue;
        break;
      }
LABEL_15:
      ++v2;
    }
    while ( (int)v2 < (int)&dword_75AB90 );
  }
  v5 = 0;
  dword_75AAC0 = 0;
  for ( dword_75AAC8 = 0; v5 < v0; ++v5 )
  {
    v6 = dword_75AAD0[v5];
    if ( v6 == dword_75AAC4 )
      dword_75AAC0 = v5;
    if ( v6 == dword_75AACC )
      dword_75AAC8 = v5;
  }
  return v0;
}
