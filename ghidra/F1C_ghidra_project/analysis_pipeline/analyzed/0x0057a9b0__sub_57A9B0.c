// Address: 0x0057a9b0
// Size: 32 bytes
// Name: sub_57A9B0
// Type: _DWORD *__thiscall(_DWORD *this, char)
// Source: IDA Hex-Rays decompilation

_DWORD *__thiscall sub_57A9B0(_DWORD *this, char a2)
{
  *this = &off_5B8A00;
  if ( (a2 & 1) != 0 )
    sub_587BCF(this);
  return this;
}
