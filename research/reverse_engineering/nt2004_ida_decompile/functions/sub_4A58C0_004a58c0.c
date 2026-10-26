int __thiscall sub_4A58C0(_DWORD *this, int a2, int a3)
{
  _DWORD *v3; // ecx
  int result; // eax

  v3 = (_DWORD *)this[13];
  if ( v3 )
  {
    sub_49CB60(v3, v3[33]);
    return sub_4B1460(a2, a3);
  }
  return result;
}
