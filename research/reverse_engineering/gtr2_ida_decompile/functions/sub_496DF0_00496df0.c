int __stdcall sub_496DF0(char *Buffer, int a2)
{
  const CHAR *v2; // eax
  const char *v3; // eax
  char v4; // cl
  const char *v5; // ecx
  _BYTE v7[256]; // [esp+0h] [ebp-100h] BYREF

  v2 = dword_B7235C;
  if ( !dword_B7235C )
    v2 = WindowName;
  sub_630FE0(v7, v2, 255);
  v7[255] = 0;
  v3 = v7;
  if ( v7[0] == 32 )
  {
    do
      v4 = *++v3;
    while ( v4 == 32 );
  }
  v5 = *(const char **)dword_91CA70;
  if ( !*(_DWORD *)dword_91CA70 )
    v5 = WindowName;
  return sub_41D810(Buffer, a2 - 1, "%s%s", v5, v3);
}
