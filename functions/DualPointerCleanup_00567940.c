int __thiscall sub_567940(int this)
{
  int result; // eax
  void *v3; // esi

  result = *(_DWORD *)(this + 24);
  if ( result )
    result = FreeWrapper_7bcf(*(LPVOID *)(this + 24));
  v3 = *(void **)(this + 16);
  if ( v3 )
    return FreeWrapper_7bcf(v3);
  return result;
}
