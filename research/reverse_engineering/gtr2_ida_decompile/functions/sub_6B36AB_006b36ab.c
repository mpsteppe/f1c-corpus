int __thiscall sub_6B36AB(int this)
{
  int v2; // eax
  _DWORD v4[3]; // [esp+4h] [ebp-Ch] BYREF

  sub_6460B4("tx", 0, v4);
  v2 = v4[1];
  *(_DWORD *)(this + 48) = 0;
  *(_BYTE *)(this + 113) |= 2u;
  *(_DWORD *)(this + 264) = v2;
  *(_DWORD *)(this + 40) = 64;
  *(_DWORD *)(this + 44) = 64;
  *(_DWORD *)(this + 108) = *(_DWORD *)(this + 108) & 0x7FFFFCFC | 0x80000202;
  *(_DWORD *)(this + 56) = 0x2000;
  return 0;
}
