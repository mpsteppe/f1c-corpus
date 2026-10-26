int __stdcall sub_4CD510(const char *a1, char *Buffer)
{
  const char *v2; // eax

  v2 = *(const char **)dword_62A0D0;
  if ( !*(_DWORD *)dword_62A0D0 )
    v2 = &byte_629120;
  sprintf(Buffer, "%s%s\\", v2, a1);
  return 0;
}
