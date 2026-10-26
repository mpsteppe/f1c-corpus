int __thiscall sub_405410(_DWORD *this)
{
  int result; // eax
  void *v3; // esi

  ConditionalCleanupWithDualFree();
  sub_4D4860();
  result = VTableDestructorWrapperWithNullCheck(this + 12);
  v3 = (void *)this[1];
  if ( v3 )
    return FreeWrapper_7bcf(v3);
  return result;
}

