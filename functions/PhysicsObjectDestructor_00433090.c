int __thiscall sub_433090(int this)
{
  int result; // eax
  void *v3; // esi

  SessionConfigDefaultInit((_DWORD *)this);
  if ( *(_DWORD *)(this + 20) )
    FreeWrapper_7bcf(*(LPVOID *)(this + 20));
  result = *(_DWORD *)(this + 8);
  if ( result )
    result = FreeWrapper_7bcf(*(LPVOID *)(this + 8));
  v3 = *(void **)this;
  if ( v3 )
    return FreeWrapper_7bcf(v3);
  return result;
}
