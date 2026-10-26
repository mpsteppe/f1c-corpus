int __thiscall sub_49ECC0(_DWORD *this)
{
  int result; // eax
  void *v3; // edi

  if ( this[3] )
  {
    result = DestructorWithConditionalFreeFlagClear();
    v3 = (void *)this[3];
    if ( v3 )
    {
      EmptyStub_7470(this[3]);
      result = FreeWrapper_7bcf(v3);
    }
    this[3] = 0;
  }
  return result;
}
