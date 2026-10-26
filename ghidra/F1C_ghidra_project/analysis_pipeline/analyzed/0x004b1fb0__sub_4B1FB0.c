// Address: 0x004b1fb0
// Size: 9 bytes
// Name: sub_4B1FB0
// Type: __int16 __thiscall(_WORD *this)
// Source: IDA Hex-Rays decompilation

__int16 __thiscall sub_4B1FB0(_WORD *this)
{
  __int16 result; // ax

  result = this[11];
  this[10] = result;
  return result;
}
