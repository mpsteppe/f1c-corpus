int sub_694BED(int a1, int a2, const char *a3, char *Format, ...)
{
  _DWORD *v4; // eax
  char Buffer[256]; // [esp+0h] [ebp-100h] BYREF
  va_list va; // [esp+118h] [ebp+18h] BYREF

  va_start(va, Format);
  _vsnprintf(Buffer, 0x100u, Format, va);
  v4 = (_DWORD *)(*(_DWORD *)(a1 + 4) + 24);
  Buffer[255] = 0;
  return sub_65DDE6(v4, a2, a3, "%s", Buffer);
}
