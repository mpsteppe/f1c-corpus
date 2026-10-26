int __thiscall sub_5A98D0(_DWORD *this, int a2, int a3, int a4, int a5)
{
  int result; // eax

  if ( a2 )
    result = sub_5B4600(a2, this, a3, a4, a5);
  else
    result = sub_5A9AD0(a3, a4, 1);
  this[14] &= ~0x400u;
  return result;
}
