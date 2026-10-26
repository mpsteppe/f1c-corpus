int __thiscall sub_4B7880(_DWORD *this)
{
  int result; // eax

  if ( dword_7639F8 )
    return sub_4B78E0(1);
  if ( dword_763A24 )
    return sub_4B78E0(0);
  if ( dword_763A50 )
    return sub_4C0C10(this[19]);
  result = dword_763A7C;
  if ( dword_763A7C )
    return sub_4C0C40(this[19]);
  return result;
}
