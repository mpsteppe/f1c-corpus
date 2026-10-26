int __thiscall sub_49EC60(_DWORD *this)
{
  int result; // eax
  void *v3; // edi

  if ( this[2] )
  {
    result = DestructorWithConditionalFreeFlagClear();
    v3 = (void *)this[2];
    if ( v3 )
    {
      EmptyStub_7470(this[2]);
      result = FreeWrapper_7bcf(v3);
    }
    this[2] = 0;
  }
  return result;
}
