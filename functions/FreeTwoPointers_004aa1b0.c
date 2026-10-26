int __thiscall sub_4AA1B0(int this)
{
  int result; // eax
  void *v3; // esi

  result = *(_DWORD *)(this + 12);
  if ( result )
    result = FreeWrapper_7bcf(*(LPVOID *)(this + 12));
  v3 = *(void **)(this + 4);
  if ( v3 )
    return FreeWrapper_7bcf(v3);
  return result;
}
