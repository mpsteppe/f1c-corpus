char __thiscall sub_5775A0(void **this, const void *a2, signed int a3)
{
  char result; // al

  if ( a3 > (int)this[1] )
  {
    if ( *this )
      sub_5BE8AE();
    sub_577560(a3, this);
    this[1] = (void *)a3;
  }
  if ( *this && a3 > 0 )
  {
    qmemcpy(*this, a2, a3);
    result = 1;
    this[2] = (void *)a3;
  }
  else
  {
    this[2] = 0;
    return 1;
  }
  return result;
}
