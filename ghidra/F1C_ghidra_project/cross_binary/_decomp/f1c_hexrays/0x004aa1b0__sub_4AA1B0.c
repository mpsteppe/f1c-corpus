// f1c  0x004aa1b0  size=37
int __thiscall sub_4AA1B0(int this)
{
  int result; // eax
  void *v3; // esi

  result = *(_DWORD *)(this + 12);
  if ( result )
    result = sub_587BCF(*(LPVOID *)(this + 12));
  v3 = *(void **)(this + 4);
  if ( v3 )
    return sub_587BCF(v3);
  return result;
}
