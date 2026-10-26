// f1c  0x00552760  size=88
int __thiscall sub_552760(int this)
{
  bool v2; // zf
  void *v3; // esi

  sub_53CB90(*(void **)(this + 100));
  v2 = (*(_DWORD *)(this + 36) & 0x20000) == 0;
  *(_DWORD *)(this + 100) = 0;
  if ( !v2 )
  {
    sub_540EB0(dword_8B78A0, *(_DWORD *)(this + 12));
    if ( *(_DWORD *)(this + 12) )
      sub_587BCF(*(LPVOID *)(this + 12));
    v3 = *(void **)(this + 2152);
    if ( v3 )
    {
      j_nullsub_3(v3);
      sub_587BCF(v3);
    }
  }
  return 0;
}
