int __thiscall sub_5528B0(int *this)
{
  if ( (this[9] & 0x20000) != 0 )
  {
    ObjectResetWithVirtualRelease(dword_8B78A0, this[3]);
    if ( this[3] )
      FreeWrapper_7bcf((LPVOID)this[3]);
    this[3] = 0;
  }
  return 0;
}
