char __thiscall sub_4081E0(_BYTE *this)
{
  char result; // al
  void *v2; // esi

  result = this[8];
  if ( result )
  {
    v2 = *(void **)this;
    if ( *(_DWORD *)this )
    {
      MultiStageCleanupWithFree(*(_DWORD **)this);
      return FreeWrapper_7bcf(v2);
    }
  }
  return result;
}

