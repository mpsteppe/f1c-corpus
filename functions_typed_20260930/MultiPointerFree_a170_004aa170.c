int __thiscall sub_4AA170(int this)
{
  int result; // eax
  void *v3; // esi

  if ( *(_DWORD *)(this + 20) )
    FreeWrapper_7bcf(*(LPVOID *)(this + 20));
  result = *(_DWORD *)(this + 12);
  if ( result )
    result = FreeWrapper_7bcf(*(LPVOID *)(this + 12));
  v3 = *(void **)(this + 4);
  if ( v3 )
    return FreeWrapper_7bcf(v3);
  return result;
}

