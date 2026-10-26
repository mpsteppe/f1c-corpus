int __thiscall sub_552760(int this)
{
  bool v2; // zf
  void *v3; // esi

  sub_53CB90(*(void **)(this + 100));
  v2 = (*(_DWORD *)(this + 36) & 0x20000) == 0;
  *(_DWORD *)(this + 100) = 0;
  if ( !v2 )
  {
    ObjectResetWithVirtualRelease(dword_8B78A0, *(_DWORD *)(this + 12));
    if ( *(_DWORD *)(this + 12) )
      FreeWrapper_7bcf(*(LPVOID *)(this + 12));
    v3 = *(void **)(this + 2152);
    if ( v3 )
    {
      EmptyStub_7470(v3);
      FreeWrapper_7bcf(v3);
    }
  }
  return 0;
}
