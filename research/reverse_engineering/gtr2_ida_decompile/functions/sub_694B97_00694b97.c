int sub_694B97(int a1, int a2, int a3, char *Format, ...)
{
  _DWORD *v4; // eax
  int result; // eax
  char Buffer[256]; // [esp+4h] [ebp-100h] BYREF
  va_list va; // [esp+11Ch] [ebp+18h] BYREF

  va_start(va, Format);
  _vsnprintf(Buffer, 0x100u, Format, va);
  v4 = (_DWORD *)(*(_DWORD *)(a1 + 4) + 24);
  Buffer[255] = 0;
  result = sub_65DD1F(v4, a2, a3, "%s", Buffer);
  *(_DWORD *)(a1 + 64) = 1;
  return result;
}
