int __thiscall sub_542E50(_DWORD *this)
{
  void *v3; // ebx

  if ( sub_53FB80(dword_8B78A0, (int)this) )
  {
    sub_53C590(-1, aErrorDeallocat);
    return -1;
  }
  else
  {
    v3 = (void *)this[1];
    this[6] = 0;
    *this = 0;
    this[10] = 0;
    this[9] = 0;
    this[8] = 0;
    this[7] = 0;
    this[13] = 0;
    this[12] = 6;
    if ( v3 )
    {
      j_nullsub_3(v3);
      sub_587BCF(v3);
      this[1] = 0;
    }
    this[2] = 0;
    this[3] = 0;
    this[4] = 0;
    this[5] = 0;
    return 0;
  }
}
