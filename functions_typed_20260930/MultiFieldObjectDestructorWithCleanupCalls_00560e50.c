void __thiscall sub_560E50(int this)
{
  void *v2; // edi
  void *v3; // edi
  LPVOID *v4; // esi

  if ( *(_DWORD *)(this + 12) )
  {
    EmptyStub_0170();
    v2 = *(void **)(this + 12);
    if ( v2 )
    {
      EmptyStub_7470(*(void **)(this + 12));
      FreeWrapper_7bcf(v2);
    }
  }
  v3 = *(void **)(this + 28);
  if ( v3 )
  {
    EmptyStub_7470(*(void **)(this + 28));
    FreeWrapper_7bcf(v3);
  }
  v4 = *(LPVOID **)(this + 32);
  if ( v4 )
  {
    ConditionalFreeOfField(v4);
    FreeWrapper_7bcf(v4);
  }
}

