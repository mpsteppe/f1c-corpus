int sub_663C69(int a1, _DWORD *a2, const char *a3, char *Format, ...)
{
  int v4; // eax
  int v5; // edx
  char Buffer[256]; // [esp+0h] [ebp-100h] BYREF
  va_list va; // [esp+118h] [ebp+18h] BYREF

  va_start(va, Format);
  _vsnprintf(Buffer, 0x100u, Format, va);
  Buffer[255] = 0;
  v4 = sub_663B95(a2);
  sub_65DDE6((_DWORD *)(*(_DWORD *)v5 + 24), v4, a3, "%s", Buffer);
  return 0;
}
