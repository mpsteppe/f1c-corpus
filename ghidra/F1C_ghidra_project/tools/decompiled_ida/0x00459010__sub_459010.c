// Address: 0x00459010
// Size: 90 bytes
// Name: sub_459010
// Type: int __thiscall(int this)
// Source: IDA Hex-Rays decompilation

int __thiscall sub_459010(int this)
{
  int result; // eax
  _DWORD v3[3]; // [esp+4h] [ebp-Ch] BYREF

  memset(v3, 0, sizeof(v3));
  sub_456150(v3);
  *(_DWORD *)(this + 188) = 0;
  *(_BYTE *)(this + 204) = 0;
  *(_DWORD *)(this + 172) = 1065353216;
  result = sub_456130(this + 144);
  *(_BYTE *)(this + 160) = 1;
  return result;
}
