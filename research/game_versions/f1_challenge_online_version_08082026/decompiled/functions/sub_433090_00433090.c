int __thiscall sub_433090(int this)
{
  int result; // eax
  void *v3; // esi

  sub_432CC0((_DWORD *)this);
  if ( *(_DWORD *)(this + 20) )
    sub_587BCF(*(LPVOID *)(this + 20));
  result = *(_DWORD *)(this + 8);
  if ( result )
    result = sub_587BCF(*(LPVOID *)(this + 8));
  v3 = *(void **)this;
  if ( v3 )
    return sub_587BCF(v3);
  return result;
}
