int __thiscall sub_5ADE10(void **this)
{
  int result; // eax

  if ( this[12] )
  {
    j_nullsub_6(this[12]);
    result = sub_5BE8AE();
    this[12] = 0;
  }
  *(_BYTE *)this = 0;
  return result;
}
