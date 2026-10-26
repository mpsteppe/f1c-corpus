int __cdecl vsprintf(char *const Buffer, const char *const Format, va_list ArgList)
{
  int v3; // edi
  char *v5; // [esp+8h] [ebp-20h] BYREF
  int v6; // [esp+Ch] [ebp-1Ch]
  char *v7; // [esp+10h] [ebp-18h]
  int v8; // [esp+14h] [ebp-14h]

  v6 = 0x7FFFFFFF;
  v8 = 66;
  v7 = Buffer;
  v5 = Buffer;
  v3 = _output(&v5, Format, ArgList);
  if ( Buffer )
  {
    if ( --v6 < 0 )
      sub_637022(0, &v5);
    else
      *v5 = 0;
  }
  return v3;
}
