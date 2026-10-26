void __thiscall sub_6464C0(int this)
{
  void *v2; // edi
  void *v3; // esi

  if ( *(_DWORD *)(this + 4) && *(_DWORD *)(this + 56) )
    j__free(*(void **)(this + 4));
  if ( *(_DWORD *)(this + 8) && *(_DWORD *)(this + 60) )
    j__free(*(void **)(this + 8));
  v2 = *(void **)(this + 76);
  if ( v2 )
  {
    sub_6464C0(*(_DWORD *)(this + 76));
    j__free(v2);
  }
  v3 = *(void **)(this + 80);
  if ( v3 )
  {
    sub_6464C0(v3);
    j__free(v3);
  }
}
