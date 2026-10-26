int __stdcall sub_4C54F0(int a1)
{
  int v1; // esi
  char *v2; // eax
  char v3; // cl
  char *v4; // eax
  char v5; // cl
  char v8[128]; // [esp+4h] [ebp-80h] BYREF

  v1 = 396 * dword_8AC48C + dword_8AC490;
  v2 = (char *)(v1 + 260);
  do
  {
    v3 = *v2;
    byte_8AC398[(_DWORD)v2 - 260 - v1] = *v2;
    ++v2;
  }
  while ( v3 );
  v4 = (char *)(v1 + 4);
  do
  {
    v5 = *v4;
    v8[(_DWORD)v4 - 4 - v1] = *v4;
    ++v4;
  }
  while ( v5 );
  StringFormatWithBufferOverflowCheck(&byte_8AC3E8, "%s.SCN", v8);
  StringFormatWithBufferOverflowCheck(&byte_8AC438, "%s.AIW", v8);
  StringCopyWithBufferRealloc(&byte_8AC3E8);
  StringCopyWithBufferRealloc(byte_8AC398);
  return StringCopyWithBufferRealloc(&byte_8AC438);
}
