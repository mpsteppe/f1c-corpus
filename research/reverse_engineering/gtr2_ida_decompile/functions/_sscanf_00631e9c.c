int sscanf(const char *const Buffer, const char *const Format, ...)
{
  _DWORD v3[8]; // [esp+0h] [ebp-20h] BYREF
  va_list va; // [esp+30h] [ebp+10h] BYREF

  va_start(va, Format);
  v3[3] = 73;
  v3[2] = Buffer;
  v3[0] = Buffer;
  v3[1] = sub_6354D0(Buffer);
  return _input(v3, Format, va);
}
