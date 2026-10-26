int __thiscall sub_413DD0(int this)
{
  int result; // eax
  void *v3; // esi

  result = *(_DWORD *)(this + 4);
  if ( result )
    result = sub_5BE8AE(*(LPVOID *)(this + 4));
  v3 = *(void **)(this + 8);
  if ( v3 )
    return sub_5BE8AE(v3);
  return result;
}
