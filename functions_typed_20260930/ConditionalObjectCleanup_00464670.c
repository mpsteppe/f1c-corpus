char __thiscall sub_464670(int *this)
{
  int v1; // esi
  char result; // al
  void *v3; // ecx
  int v5; // eax
  int v6; // ecx

  v5 = *this;
  v6 = *(_DWORD *)(*this + 16312);
  if ( v6 )
  {
    VTableCallViaOffset0x7c(v6, *(_DWORD *)(v5 + 16764));
    PointerCheckWithFallback(*this + 16312);
    *(_DWORD *)(*this + 16312) = 0;
  }
  v1 = *this + 112528;
  result = BooleanFlagResetWithSideEffects((_BYTE *)v1);
  v3 = *(void **)(v1 + 12);
  if ( v3 )
  {
    result = NetworkCleanup(v3);
    *(_DWORD *)(v1 + 12) = 0;
  }
  return result;
}

