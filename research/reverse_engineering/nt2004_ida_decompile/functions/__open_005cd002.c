int _open(const char *FileName, int OpenFlag, ...)
{
  int v3; // [esp+Ch] [ebp+Ch]
  va_list va; // [esp+10h] [ebp+10h] BYREF

  va_start(va, OpenFlag);
  v3 = va_arg(va, _DWORD);
  return _sopen(FileName, OpenFlag, 64, v3);
}
