int __stdcall sub_53A160(int a1)
{
  int v1; // esi
  char *v2; // eax
  char v3; // cl
  char *v4; // eax
  char v5; // cl
  char v8[128]; // [esp+4h] [ebp-80h] BYREF

  v1 = 396 * dword_BE1CD4 + dword_BE1CD8;
  v2 = (char *)(v1 + 260);
  do
  {
    v3 = *v2;
    byte_BE1BE0[(_DWORD)v2 - 260 - v1] = *v2;
    ++v2;
  }
  while ( v3 );
  v4 = (char *)(v1 + 4);
  do
  {
    v5 = *v4;
    v8[(_DWORD)v4 - 4 - v1] = *v4;
    ++v4;
  }
  while ( v5 );
  sprintf(byte_BE1C30, "%s.TRK", v8);
  sprintf(byte_BE1C80, "%s.AIW", v8);
  sub_615860(byte_BE1C30);
  sub_615860(byte_BE1BE0);
  return sub_615860(byte_BE1C80);
}
