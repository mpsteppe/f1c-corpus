// Address: 0x004071f0
// Size: 43 bytes
// Name: sub_4071F0
// Type: int __thiscall(_DWORD *this, int, int, _DWORD *)
// Source: IDA Hex-Rays decompilation

int __thiscall sub_4071F0(_DWORD *this, int a2, int a3, _DWORD *a4)
{
  this[31] = *a4;
  this[32] = a4[1];
  this[33] = a4[2];
  return sub_407D40(a2, a3);
}
