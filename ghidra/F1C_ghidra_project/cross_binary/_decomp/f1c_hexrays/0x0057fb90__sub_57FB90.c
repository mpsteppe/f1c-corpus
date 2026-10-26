// f1c  0x0057fb90  size=73
char __thiscall sub_57FB90(int this)
{
  if ( !*(_BYTE *)(this + 2676) )
  {
    if ( !WSAStartup(0x202u, (LPWSADATA)(this + 1912)) )
    {
      *(_BYTE *)(this + 2676) = 1;
      return *(_BYTE *)(this + 2676);
    }
    *(_BYTE *)(this + 2676) = 0;
    sub_57D400((void *)0xFFFFFFFF);
  }
  return *(_BYTE *)(this + 2676);
}
