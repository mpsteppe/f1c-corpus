int __thiscall sub_405410(_DWORD *this)
{
  int result; // eax
  void *v3; // esi

  sub_4054A0();
  sub_4D4860();
  result = sub_52D8C0(this + 12);
  v3 = (void *)this[1];
  if ( v3 )
    return sub_587BCF(v3);
  return result;
}
