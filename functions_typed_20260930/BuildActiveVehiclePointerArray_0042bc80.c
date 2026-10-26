int sub_42BC80()
{
  int v0; // ebx
  _DWORD *v1; // eax
  char **v2; // edx
  char *v3; // ecx
  int *v4; // eax
  int v5; // eax
  int v6; // ecx

  v0 = 0;
  v1 = &stru_5EC6D8;
  do
  {
    if ( v1[3250] != -1 )
      dword_7C54F0[v0++] = (int)v1;
    v1 += 4656;
  }
  while ( (int)v1 < (int)byte_7C54D8 );
  if ( v0 < 104 )
  {
    memset((void *)(4 * v0 + 8148208), 0, 4 * (104 - v0));
    v2 = (char **)(4 * v0 + 8148208);
    do
    {
      v3 = (char *)&stru_5EC6D8;
      while ( 2 )
      {
        v4 = dword_7C54F0;
        while ( (char *)*v4 != v3 )
        {
          if ( (int)++v4 >= (int)&byte_7C5690 )
          {
            if ( v3 )
            {
              *v2 = v3;
              goto LABEL_15;
            }
            break;
          }
        }
        v3 += 18624;
        if ( (int)v3 < (int)byte_7C54D8 )
          continue;
        break;
      }
LABEL_15:
      ++v2;
    }
    while ( (int)v2 < (int)&byte_7C5690 );
  }
  v5 = 0;
  dword_7C54DC = 0;
  for ( dword_7C54E4 = 0; v5 < v0; ++v5 )
  {
    v6 = dword_7C54F0[v5];
    if ( v6 == dword_7C54E0 )
      dword_7C54DC = v5;
    if ( v6 == dword_7C54E8 )
      dword_7C54E4 = v5;
  }
  return v0;
}

