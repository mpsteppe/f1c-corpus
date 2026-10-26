char __thiscall sub_432A10(void *this)
{
  const char *v1; // edx
  int v2; // ecx
  const char *v3; // eax

  v1 = *(const char **)(*(_DWORD *)this + 8);
  if ( !v1 )
    v1 = &byte_5EA438;
  v2 = strlen(v1);
  if ( v2 > 0 )
  {
    v3 = &v1[v2 - 1];
    if ( *v3 == 92 )
      v3 = &v1[v2 - 2];
    if ( v3 > v1 )
    {
      while ( *v3 != 92 )
      {
        if ( --v3 <= v1 )
        {
          *v3 = 0;
          return 0;
        }
      }
      ++v3;
    }
    *v3 = 0;
  }
  return 0;
}

