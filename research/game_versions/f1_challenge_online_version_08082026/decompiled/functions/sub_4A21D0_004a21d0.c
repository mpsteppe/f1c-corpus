int __thiscall sub_4A21D0(__int16 *this, const char *a2, const char *a3, int a4, char a5)
{
  char v6[68]; // [esp+4h] [ebp-48h] BYREF
  int v7; // [esp+48h] [ebp-4h]

  strcpy(v6, a3);
  v6[64] = 1;
  v7 = 0;
  return sub_4A2010(this, a2, (int)v6, a4, a5);
}
