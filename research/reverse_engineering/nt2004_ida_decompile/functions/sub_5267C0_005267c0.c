int __thiscall sub_5267C0(void **this)
{
  int v2; // eax

  if ( this[6] )
  {
    j_nullsub_6(this[6]);
    sub_5BE8AE();
  }
  v2 = sub_592CD0(aFtframerate);
  if ( v2 )
    sub_592C40(v2);
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  this[5] = 0;
  this[4] = 0;
  this[6] = 0;
  this[8] = 0;
  this[7] = 0;
  this[10] = 0;
  this[9] = 0;
  *((_BYTE *)this + 44) = 0;
  *((_BYTE *)this + 108) = 0;
  return 0;
}
