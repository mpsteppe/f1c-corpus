int __thiscall sub_4BBDC0(_DWORD *this, char a2)
{
  int result; // eax

  sub_4EDFE0(1);
  if ( a2 )
  {
    sub_4EEC20(1);
    sub_4EEC50(1);
    sub_4EECE0(1);
  }
  else
  {
    sub_4EEC20(0);
    sub_4EEC50(0);
    sub_4EECE0(0);
  }
  result = sub_428150(off_5FD348);
  *(_BYTE *)this = 0;
  this[1] = 1;
  return result;
}
