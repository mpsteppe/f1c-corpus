int __stdcall sub_4F6A10(char *Buffer, int a2)
{
  const char *v2; // ecx
  const char *v3; // eax

  v2 = (const char *)dword_62A0B0;
  if ( !dword_62A0B0 )
    v2 = &byte_629120;
  v3 = *(const char **)dword_62A068;
  if ( !*(_DWORD *)dword_62A068 )
    v3 = &byte_629120;
  return sprintf(Buffer, "%s%sterrain.ini", v3, v2);
}
