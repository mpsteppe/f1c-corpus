// Address: 0x00502c12
// Size: 13 bytes
// Name: sub_502C12
// Type: _DWORD *__thiscall(_DWORD *this)
// Source: IDA Hex-Rays decompilation

_DWORD *__thiscall sub_502C12(_DWORD *this)
{
  _DWORD *result; // eax

  result = this;
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  return result;
}
