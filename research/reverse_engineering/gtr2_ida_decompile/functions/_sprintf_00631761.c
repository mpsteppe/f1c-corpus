int sprintf(char *const Buffer, const char *const Format, ...)
{
  int v2; // edi
  char *v4; // [esp+8h] [ebp-20h] BYREF
  int v5; // [esp+Ch] [ebp-1Ch]
  char *v6; // [esp+10h] [ebp-18h]
  int v7; // [esp+14h] [ebp-14h]
  va_list va; // [esp+38h] [ebp+10h] BYREF

  va_start(va, Format);
  v5 = 0x7FFFFFFF;
  v7 = 66;
  v6 = Buffer;
  v4 = Buffer;
  v2 = _output(&v4, Format, va);
  if ( Buffer )
  {
    if ( --v5 < 0 )
      sub_637022(0, &v4);
    else
      *v4 = 0;
  }
  return v2;
}
