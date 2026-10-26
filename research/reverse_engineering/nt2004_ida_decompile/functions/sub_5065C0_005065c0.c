int __thiscall sub_5065C0(_DWORD *this)
{
  int result; // eax

  if ( *this )
    result = sub_59ECC0(0, 0, 0, 0);
  if ( this[1] )
  {
    sub_5AD880();
    result = sub_5AD820(this[1]);
  }
  *((_BYTE *)this + 8) = 0;
  return result;
}
