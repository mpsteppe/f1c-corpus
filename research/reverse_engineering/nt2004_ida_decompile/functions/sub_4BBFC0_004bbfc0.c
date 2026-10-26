bool __thiscall sub_4BBFC0(_DWORD *this, int a2)
{
  bool v3; // zf

  if ( (dword_7D7540 > 0 || dword_75CBB4 < 5) && !a2 && this[1] == 2 )
  {
    sub_4BBF80(this);
    if ( dword_75CBB4 < 5 && dword_7D7928 == 2 && dword_6290F4 >= 2 )
      sub_4BBF10();
  }
  v3 = a2 == this[1];
  this[1] = a2;
  return !v3;
}
