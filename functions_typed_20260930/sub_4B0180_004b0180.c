int __stdcall sub_4B0180(const char *a1, int a2)
{
  const char *v2; // eax

  v2 = (const char *)dword_5EC440;
  if ( !dword_5EC440 )
    v2 = byte_5EA438;
  StringFormatWithBufferOverflowCheck(a2, "%s%s\\", v2, a1);
  return 0;
}

