int __thiscall sub_45B400(_DWORD *this)
{
  _DWORD *v1; // esi

  v1 = this + 1;
  *this = &off_59F080;
  ShortComputation_d000(this + 1);
  if ( v1[10] )
    FreeWrapper_7bcf((LPVOID)v1[10]);
  return ResourceCleanup_cd10(v1);
}
