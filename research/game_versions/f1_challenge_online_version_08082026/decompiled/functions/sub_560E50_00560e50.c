void __thiscall sub_560E50(int this)
{
  void *v2; // edi
  void *v3; // edi
  LPVOID *v4; // esi

  if ( *(_DWORD *)(this + 12) )
  {
    nullsub_3();
    v2 = *(void **)(this + 12);
    if ( v2 )
    {
      j_nullsub_3(*(void **)(this + 12));
      sub_587BCF(v2);
    }
  }
  v3 = *(void **)(this + 28);
  if ( v3 )
  {
    j_nullsub_3(*(void **)(this + 28));
    sub_587BCF(v3);
  }
  v4 = *(LPVOID **)(this + 32);
  if ( v4 )
  {
    sub_560B90(v4);
    sub_587BCF(v4);
  }
}
