int __thiscall sub_59FA90(_DWORD *this)
{
  void *v3; // ebx

  if ( sub_5A6A60((int)&unk_7E6B48, (int)this) )
  {
    sub_591C60((int)this, -1, aErrorDeallocat);
    return -1;
  }
  else
  {
    v3 = (void *)this[2];
    this[14] = 0;
    *this = 0;
    this[10] = 0;
    this[9] = 0;
    this[8] = 0;
    this[7] = 0;
    this[13] = 0;
    this[12] = 6;
    if ( v3 )
    {
      j_nullsub_6(v3);
      sub_5BE8AE();
      this[2] = 0;
    }
    this[3] = 0;
    this[4] = 0;
    this[5] = 0;
    this[6] = 0;
    return 0;
  }
}
