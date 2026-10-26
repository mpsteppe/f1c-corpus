char __thiscall sub_45D490(int this)
{
  char result; // al

  result = StateCheckWrapper(dword_7CD25C);
  if ( result )
  {
    sub_45CD70((_DWORD *)this);
    result = byte_7D0F94;
    if ( byte_7D0F94 )
      *(_BYTE *)(this + 1) = 1;
    else
      *(_BYTE *)(this + 1) = 0;
  }
  return result;
}

