char __thiscall sub_583430(_DWORD *this, int a2, char a3)
{
  char result; // al
  _DWORD *v4; // esi
  _DWORD *v5; // edx
  int v6; // edi
  void *v7; // edi

  result = 0;
  if ( a2 )
  {
    v4 = (_DWORD *)*this;
    v5 = 0;
    if ( *this )
    {
      while ( *v4 != a2 )
      {
        v5 = v4;
        v4 = (_DWORD *)v4[1];
        if ( !v4 )
          return result;
      }
      if ( v4 == (_DWORD *)this[2] )
        this[2] = v4[1];
      v6 = v4[1];
      if ( v5 )
        v5[1] = v6;
      else
        *this = v6;
      if ( (_DWORD *)this[1] == v4 )
        this[1] = v5;
      --this[3];
      if ( !a3 )
        *((_BYTE *)v4 + 8) = 0;
      if ( *((_BYTE *)v4 + 8) )
      {
        v7 = (void *)*v4;
        if ( *v4 )
        {
          SEHGuardedFunctionWithExceptionHandling(*v4);
          FreeWrapper_7bcf(v7);
        }
      }
      FreeWrapper_7bcf(v4);
      return 1;
    }
  }
  return result;
}

