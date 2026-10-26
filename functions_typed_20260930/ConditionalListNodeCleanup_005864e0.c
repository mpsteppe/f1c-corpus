char __thiscall sub_5864E0(_BYTE *this)
{
  char result; // al
  void *v2; // esi

  result = this[8];
  if ( result )
  {
    v2 = *(void **)this;
    if ( *(_DWORD *)this )
    {
      SEHGuardedFunctionWithExceptionHandling(*(_DWORD *)this);
      return FreeWrapper_7bcf(v2);
    }
  }
  return result;
}

