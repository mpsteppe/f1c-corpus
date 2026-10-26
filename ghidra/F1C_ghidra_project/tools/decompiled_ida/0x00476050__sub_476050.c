// Address: 0x00476050
// Size: 14 bytes
// Name: sub_476050
// Type: int __thiscall(_DWORD *this)
// Source: IDA Hex-Rays decompilation

int __thiscall sub_476050(_DWORD *this)
{
  return (*(int (__thiscall **)(_DWORD *, _DWORD, _DWORD))(*this + 8))(this, this[5], this[6]);
}
