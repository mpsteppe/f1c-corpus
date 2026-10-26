// Address: 0x0057aec0
// Size: 38 bytes
// Name: sub_57AEC0
// Type: _BYTE *__thiscall(_BYTE *this)
// Source: IDA Hex-Rays decompilation

_BYTE *__thiscall sub_57AEC0(_BYTE *this)
{
  _BYTE *result; // eax

  result = this;
  this[4] = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *(_DWORD *)this = &off_5B8A1C;
  return result;
}
