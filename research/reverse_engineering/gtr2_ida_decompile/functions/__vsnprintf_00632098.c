int __cdecl _vsnprintf(char *const Buffer, const size_t BufferCount, const char *const Format, va_list ArgList)
{
  int v4; // edi
  char *v6; // [esp+8h] [ebp-20h] BYREF
  size_t v7; // [esp+Ch] [ebp-1Ch]
  char *v8; // [esp+10h] [ebp-18h]
  int v9; // [esp+14h] [ebp-14h]

  v7 = BufferCount;
  v9 = 66;
  v8 = Buffer;
  v6 = Buffer;
  v4 = _output(&v6, Format, ArgList);
  if ( Buffer )
  {
    if ( (--v7 & 0x80000000) != 0 )
      sub_637022(0, &v6);
    else
      *v6 = 0;
  }
  return v4;
}
