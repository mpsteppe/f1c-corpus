char __thiscall sub_4191D0(int this)
{
  void *v2; // eax

  LOBYTE(v2) = *(_BYTE *)(this + 16);
  if ( !(_BYTE)v2 )
  {
    sub_5BE8AE(*(LPVOID *)(this + 40));
    v2 = operator new(0x100000u);
    *(_DWORD *)(this + 40) = v2;
    if ( v2 )
      *(_BYTE *)(this + 16) = 1;
  }
  return (char)v2;
}
