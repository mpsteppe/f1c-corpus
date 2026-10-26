int __thiscall sub_4646F0(int this, char a2)
{
  if ( *(_BYTE *)(this + 8) )
    FreeWrapper_7bcf(*(LPVOID *)this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf((LPVOID)this);
  return this;
}
