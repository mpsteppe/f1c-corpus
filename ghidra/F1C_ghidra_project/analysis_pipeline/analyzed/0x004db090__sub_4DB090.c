// Address: 0x004db090
// Size: 31 bytes
// Name: sub_4DB090
// Type: _DWORD *__thiscall(_DWORD *this, char)
// Source: IDA Hex-Rays decompilation

_DWORD *__thiscall sub_4DB090(_DWORD *this, char a2)
{
  *this = &off_5AD06C;
  if ( (a2 & 1) != 0 )
    sub_587BCF(this);
  return this;
}
