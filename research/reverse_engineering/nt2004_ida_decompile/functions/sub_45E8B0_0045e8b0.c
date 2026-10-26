char __thiscall sub_45E8B0(int this)
{
  char result; // al

  result = sub_4634D0(dword_764D70);
  if ( result )
  {
    sub_45E2F0((_DWORD *)this);
    result = byte_769968;
    if ( byte_769968 )
      *(_BYTE *)(this + 1) = 1;
    else
      *(_BYTE *)(this + 1) = 0;
  }
  return result;
}
