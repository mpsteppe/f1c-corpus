int *__thiscall sub_40C120(_DWORD *this, int a2)
{
  int *result; // eax
  int v3; // esi
  int v4; // eax

  result = (int *)this[14];
  this[16] = result;
  if ( result )
  {
    v3 = *result;
    if ( *result )
    {
      while ( *(_DWORD *)v3 != a2 )
      {
        v4 = this[16];
        if ( v4 )
          this[16] = *(_DWORD *)(v4 + 4);
        result = (int *)this[16];
        if ( result )
        {
          v3 = *result;
          if ( *result )
            continue;
        }
        return result;
      }
      if ( *(_DWORD *)(v3 + 12) )
      {
        fclose(*(FILE **)(v3 + 12));
        *(_DWORD *)(v3 + 12) = 0;
      }
      return (int *)sub_40BEF0();
    }
  }
  return result;
}
