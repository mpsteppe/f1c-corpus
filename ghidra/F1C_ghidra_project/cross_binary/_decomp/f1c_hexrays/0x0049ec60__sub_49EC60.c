// f1c  0x0049ec60  size=49
int __thiscall sub_49EC60(_DWORD *this)
{
  int result; // eax
  void *v3; // edi

  if ( this[2] )
  {
    result = sub_5502C0();
    v3 = (void *)this[2];
    if ( v3 )
    {
      j_nullsub_3(this[2]);
      result = sub_587BCF(v3);
    }
    this[2] = 0;
  }
  return result;
}
