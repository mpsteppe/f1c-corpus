int __stdcall sub_44D480(const void *a1, int a2, _DWORD *a3)
{
  _BYTE v4[32]; // [esp+8h] [ebp-20h] BYREF

  sub_44B2D0((int)v4);
  qmemcpy(v4, a1, 0x18u);
  sub_44B300((int)v4, a2);
  return sub_44BEC0(a3, (int)v4, 0);
}
