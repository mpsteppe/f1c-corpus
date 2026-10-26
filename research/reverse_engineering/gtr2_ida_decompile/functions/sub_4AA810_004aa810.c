int __thiscall sub_4AA810(_DWORD *this)
{
  unsigned __int64 v2; // rax

  sub_4CDE20(dword_B640C0 != 5);
  LODWORD(v2) = dword_B70618[9 * *(_DWORD *)dword_B72314];
  if ( (_DWORD)v2 == 1 )
  {
    this[76] = 0;
  }
  else if ( (_DWORD)v2 )
  {
    v2 = (unsigned __int64)(flt_B70858 * 10.0);
    this[76] = v2;
  }
  else
  {
    this[76] = 11;
  }
  return v2;
}
