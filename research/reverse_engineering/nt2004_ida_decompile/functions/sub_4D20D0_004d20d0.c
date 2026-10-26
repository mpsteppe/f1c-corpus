int __stdcall sub_4D20D0(int a1, int a2, int a3, int a4)
{
  _BYTE v5[1536]; // [esp+4h] [ebp-C00h] BYREF
  _BYTE v6[1536]; // [esp+604h] [ebp-600h] BYREF

  sub_4D1CF0(a1, (int)v6);
  sub_4D1CF0(a2, (int)v5);
  return sub_5A98A0(v6, v5, a3, a4);
}
