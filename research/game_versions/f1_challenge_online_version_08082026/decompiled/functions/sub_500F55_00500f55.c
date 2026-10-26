int __thiscall sub_500F55(int this)
{
  int result; // eax
  void *v3; // edi
  void *v4; // esi

  if ( *(_DWORD *)(this + 4) && *(_DWORD *)(this + 56) )
    sub_587BCF(*(LPVOID *)(this + 4));
  result = *(_DWORD *)(this + 8);
  if ( result && *(_DWORD *)(this + 60) )
    result = sub_587BCF(*(LPVOID *)(this + 8));
  v3 = *(void **)(this + 76);
  if ( v3 )
  {
    sub_500F55(*(_DWORD *)(this + 76));
    result = sub_587BCF(v3);
  }
  v4 = *(void **)(this + 80);
  if ( v4 )
  {
    sub_500F55(v4);
    return sub_587BCF(v4);
  }
  return result;
}
