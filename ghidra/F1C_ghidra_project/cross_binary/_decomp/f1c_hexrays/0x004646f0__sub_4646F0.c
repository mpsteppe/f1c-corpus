// f1c  0x004646f0  size=43
int __thiscall sub_4646F0(int this, char a2)
{
  if ( *(_BYTE *)(this + 8) )
    sub_587BCF(*(LPVOID *)this);
  if ( (a2 & 1) != 0 )
    sub_587BCF((LPVOID)this);
  return this;
}
