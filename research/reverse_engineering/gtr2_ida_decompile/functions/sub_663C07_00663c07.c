int sub_663C07(_DWORD *a1, _DWORD *a2, int a3, char *Format, ...)
{
  int v4; // eax
  char Buffer[256]; // [esp+4h] [ebp-100h] BYREF
  va_list va; // [esp+11Ch] [ebp+18h] BYREF

  va_start(va, Format);
  a1[19] = 1;
  _vsnprintf(Buffer, 0x100u, Format, va);
  Buffer[255] = 0;
  v4 = sub_663B95(a2);
  sub_65DD1F((_DWORD *)(*a1 + 24), v4, a3, "%s", Buffer);
  return 0;
}
