int __thiscall sub_4DCD10(_DWORD *this)
{
  int v2; // ecx
  void *v3; // edi

  v2 = this[1];
  if ( v2 )
  {
    DestructorWithConditionalFreeFlagClear(v2);
    v3 = (void *)this[1];
    if ( v3 )
    {
      EmptyStub_7470(this[1]);
      FreeWrapper_7bcf(v3);
    }
  }
  if ( *this )
    ResourceCascadeCleanup(*this);
  return ShortComputation_cb70(this);
}

