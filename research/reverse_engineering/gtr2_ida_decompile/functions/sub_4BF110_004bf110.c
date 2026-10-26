int __thiscall sub_4BF110(int this)
{
  void *v2; // eax
  __int32 v3; // edx
  int v5; // [esp+0h] [ebp-14h]

  v2 = *(void **)(this + 368);
  if ( v2 )
    j_j__free(v2);
  if ( *(_DWORD *)(this + 360) )
    j_j__free(*(void **)(this + 360));
  if ( *(_DWORD *)(this + 352) )
    j_j__free(*(void **)(this + 352));
  nullsub_7((void *)(this + 312));
  return sub_491800(v3, v5);
}
