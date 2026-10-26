void __thiscall sub_6138B0(int this)
{
  int i; // edi

  for ( i = 0; i < *(_DWORD *)(this + 16); ++i )
    j__free(*(void **)(*(_DWORD *)(this + 12) + 4 * i));
  j__free(*(void **)(this + 12));
  *(_DWORD *)(this + 12) = 0;
  *(_DWORD *)(this + 16) = 0;
  *(_DWORD *)(this + 20) = 0;
  *(_DWORD *)(this + 24) = 0;
}
