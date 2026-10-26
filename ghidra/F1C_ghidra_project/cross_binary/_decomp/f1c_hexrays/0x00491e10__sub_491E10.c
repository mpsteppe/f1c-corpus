// f1c  0x00491e10  size=47
int __thiscall sub_491E10(int this, char a2)
{
  if ( *(_BYTE *)(this + 8) && *(_DWORD *)this )
    sub_587BCF(*(LPVOID *)this);
  if ( (a2 & 1) != 0 )
    sub_587BCF((LPVOID)this);
  return this;
}
