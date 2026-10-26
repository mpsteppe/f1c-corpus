char __thiscall sub_491E40(int this)
{
  LPVOID v1; // eax

  LOBYTE(v1) = *(_BYTE *)(this + 8);
  if ( (_BYTE)v1 )
  {
    v1 = *(LPVOID *)this;
    if ( *(_DWORD *)this )
      LOBYTE(v1) = sub_587BCF(*(LPVOID *)this);
  }
  return (char)v1;
}
