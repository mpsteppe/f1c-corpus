int __thiscall sub_49ECC0(_DWORD *this)
{
  int result; // eax
  void *v3; // edi

  if ( this[3] )
  {
    result = sub_5502C0();
    v3 = (void *)this[3];
    if ( v3 )
    {
      j_nullsub_3(this[3]);
      result = sub_587BCF(v3);
    }
    this[3] = 0;
  }
  return result;
}
