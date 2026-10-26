void *__thiscall sub_59EFD0(int *this)
{
  void *result; // eax
  int *v2; // esi
  void *v3; // esi

  result = (void *)this[715];
  v2 = this + 711;
  if ( result )
  {
    result = (void *)WaitForSingleObject(result, this[716]);
    if ( !result || result == (void *)128 )
    {
      result = (void *)sub_525140(v2);
      v3 = (void *)v2[4];
      if ( v3 )
        return (void *)ReleaseMutex(v3);
    }
  }
  return result;
}
