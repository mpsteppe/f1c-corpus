// f1c  0x00542950  size=85
int __thiscall sub_542950(_DWORD *this, int a2, int a3, int a4, int a5)
{
  if ( sub_5426E0(this, a4, a5) )
    return -1;
  this[7] = a2;
  this[8] = a3;
  this[6] = a5;
  if ( (a5 & 0xF) != 0 && sub_53F720((int)&unk_8B78A0, this, 0) )
    return -1;
  else
    return 0;
}
