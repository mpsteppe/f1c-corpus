int __thiscall sub_5B9F90(int *this)
{
  int v2; // eax

  if ( this[4] > 0 )
    return 2;
  v2 = this[18];
  if ( v2 == 3 || !v2 )
    return 1;
  else
    return v2 != 1 ? 3 : 0;
}
