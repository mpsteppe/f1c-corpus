// f1c  0x00567940  size=37
int __thiscall sub_567940(int this)
{
  int result; // eax
  void *v3; // esi

  result = *(_DWORD *)(this + 24);
  if ( result )
    result = sub_587BCF(*(LPVOID *)(this + 24));
  v3 = *(void **)(this + 16);
  if ( v3 )
    return sub_587BCF(v3);
  return result;
}
