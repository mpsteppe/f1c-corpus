int __thiscall sub_681DE0(_DWORD *this, int a2, int a3, int a4)
{
  const char *v5; // eax
  char v7[64]; // [esp+8h] [ebp-40h] BYREF

  sub_630FE0((int)v7, *(_DWORD *)(*(_DWORD *)(a2 + 104) + 24), 63);
  v7[63] = 0;
  v5 = sub_681C52(this, a2);
  sub_632041(a3, a4, "%s semantic '%s'", v5, v7);
  *(_BYTE *)(a3 + a4 - 1) = 0;
  return 0;
}
