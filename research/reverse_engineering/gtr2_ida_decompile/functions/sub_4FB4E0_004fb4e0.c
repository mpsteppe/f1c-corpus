int __thiscall sub_4FB4E0(_DWORD *this, int a2)
{
  int result; // eax
  int *v4; // ecx

  if ( !byte_B6F118 )
    sub_4094C0();
  result = sub_5BFC80(this[4]);
  if ( !(_BYTE)result )
  {
    v4 = (int *)this[4];
    if ( *(_DWORD *)(v4[25] + 15576) )
    {
      return sub_4074A0(v4);
    }
    else
    {
      sub_54B280(v4 + 15);
      return sub_4094C0();
    }
  }
  return result;
}
