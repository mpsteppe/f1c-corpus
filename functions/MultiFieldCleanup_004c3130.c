int __thiscall sub_4C3130(void *this)
{
  int v2; // ebx
  LPVOID *v3; // edi
  int result; // eax
  void *v5; // esi

  if ( *((_DWORD *)this + 245) )
  {
    do
    {
      v2 = *(_DWORD *)(*((_DWORD *)this + 245) + 16);
      v3 = (LPVOID *)*((_DWORD *)this + 245);
      if ( v3 )
      {
        if ( v3[2] )
          FreeWrapper_7bcf(v3[2]);
        ShortComputation_4370(v3);
        FreeWrapper_7bcf(v3);
      }
      *((_DWORD *)this + 245) = v2;
    }
    while ( v2 );
  }
  if ( *((_DWORD *)this + 246) )
    FreeWrapper_7bcf(*((LPVOID *)this + 246));
  if ( *((_DWORD *)this + 243) )
    FreeWrapper_7bcf(*((LPVOID *)this + 243));
  if ( *((_DWORD *)this + 8) )
    FreeWrapper_7bcf(*((LPVOID *)this + 8));
  if ( *((_DWORD *)this + 6) )
    FreeWrapper_7bcf(*((LPVOID *)this + 6));
  if ( *((_DWORD *)this + 4) )
    FreeWrapper_7bcf(*((LPVOID *)this + 4));
  result = *((_DWORD *)this + 2);
  if ( result )
    result = FreeWrapper_7bcf(*((LPVOID *)this + 2));
  v5 = *(void **)this;
  if ( v5 )
    return FreeWrapper_7bcf(v5);
  return result;
}
