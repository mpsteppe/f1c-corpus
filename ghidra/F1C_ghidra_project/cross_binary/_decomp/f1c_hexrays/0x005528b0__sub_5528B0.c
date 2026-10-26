// f1c  0x005528b0  size=53
int __thiscall sub_5528B0(int *this)
{
  if ( (this[9] & 0x20000) != 0 )
  {
    sub_540EB0(dword_8B78A0, this[3]);
    if ( this[3] )
      sub_587BCF((LPVOID)this[3]);
    this[3] = 0;
  }
  return 0;
}
