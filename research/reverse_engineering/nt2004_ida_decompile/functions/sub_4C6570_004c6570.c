int __thiscall sub_4C6570(int this)
{
  int result; // eax
  void *v3; // esi

  if ( *(_DWORD *)(this + 20) )
    sub_5BE8AE(*(LPVOID *)(this + 20));
  result = *(_DWORD *)(this + 12);
  if ( result )
    result = sub_5BE8AE(*(LPVOID *)(this + 12));
  v3 = *(void **)(this + 4);
  if ( v3 )
    return sub_5BE8AE(v3);
  return result;
}
