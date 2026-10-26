int __thiscall sub_59F5A0(_DWORD *this, int a2, int a3, int a4, int a5, int a6)
{
  if ( sub_59F1B0(this, a4, a6) )
    return -1;
  this[7] = a2;
  this[8] = a3;
  this[14] = a6;
  if ( (a6 & 0xF) != 0 && sub_5A6610((int)&unk_7E6B48, (int)this, a5) )
    return -1;
  else
    return 0;
}
