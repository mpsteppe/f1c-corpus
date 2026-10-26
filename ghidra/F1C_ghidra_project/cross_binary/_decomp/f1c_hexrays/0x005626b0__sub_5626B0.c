// f1c  0x005626b0  size=94
int __thiscall sub_5626B0(int this, char *buf)
{
  _BYTE v3[1400]; // [esp+Ch] [ebp-578h] BYREF

  v3[0] = byte_5EA438[0];
  memset(&v3[1], 0, 1399);
  (*(void (__fastcall **)(_BYTE *, int, _DWORD))(this + 200))(v3, 1400, *(_DWORD *)(this + 256));
  return sub_562710(buf, (int)v3);
}
