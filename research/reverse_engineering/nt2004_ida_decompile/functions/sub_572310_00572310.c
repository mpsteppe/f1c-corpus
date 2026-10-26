char __thiscall sub_572310(_BYTE *this)
{
  int v1; // eax

  LOBYTE(v1) = this[8];
  if ( (_BYTE)v1 )
  {
    v1 = *(_DWORD *)this;
    if ( *(_DWORD *)this )
      LOBYTE(v1) = sub_5BE8AE();
  }
  return v1;
}
