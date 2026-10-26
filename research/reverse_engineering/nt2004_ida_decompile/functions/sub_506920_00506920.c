int __thiscall sub_506920(_DWORD *this)
{
  int v2; // eax
  int result; // eax

  v2 = this[1];
  if ( v2 )
  {
    sub_5A2B00(v2);
    this[1] = 0;
  }
  result = *this;
  if ( *this )
  {
    result = sub_5A1AD0(*this);
    *this = 0;
  }
  return result;
}
