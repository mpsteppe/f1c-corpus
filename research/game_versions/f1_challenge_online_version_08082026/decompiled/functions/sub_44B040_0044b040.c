int __stdcall sub_44B040(const void *a1, int a2, _DWORD *a3)
{
  _BYTE v4[32]; // [esp+8h] [ebp-20h] BYREF

  sub_448E90((int)v4);
  qmemcpy(v4, a1, 0x18u);
  sub_448EC0((int)v4, a2);
  return sub_449A80(a3, (int)v4, 0);
}
