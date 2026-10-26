int __thiscall sub_4B1280(int this)
{
  int result; // eax
  void *v3; // esi

  result = *(_DWORD *)(this + 12);
  if ( result )
    result = sub_5BE8AE(*(LPVOID *)(this + 12));
  v3 = *(void **)(this + 4);
  if ( v3 )
    return sub_5BE8AE(v3);
  return result;
}
