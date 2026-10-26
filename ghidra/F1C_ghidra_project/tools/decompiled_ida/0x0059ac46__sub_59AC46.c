// Address: 0x0059ac46
// Size: 29 bytes
// Name: sub_59AC46
// Type: _DWORD *__thiscall(_DWORD *this, char)
// Source: IDA Hex-Rays decompilation

_DWORD *__thiscall sub_59AC46(_DWORD *this, char a2)
{
  *this = &std::locale::facet::`vftable';
  if ( (a2 & 1) != 0 )
    sub_587BCF(this);
  return this;
}
