// Address: 0x005831b0
// Size: 87 bytes
// Name: sub_5831B0
// Type: char *__thiscall(_DWORD *this, char)
// Source: IDA Hex-Rays decompilation

char *__thiscall sub_5831B0(_DWORD *this, char a2)
{
  if ( (a2 & 2) != 0 )
  {
    sub_58A5F7(this, 308, *(this - 1), sub_57BC70);
    if ( (a2 & 1) != 0 )
      sub_587BCF(this - 1);
    return (char *)(this - 1);
  }
  else
  {
    sub_57BC70(this);
    if ( (a2 & 1) != 0 )
      sub_587BCF(this);
    return (char *)this;
  }
}
