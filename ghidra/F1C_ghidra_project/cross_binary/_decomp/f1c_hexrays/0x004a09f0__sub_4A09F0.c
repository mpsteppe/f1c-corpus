// f1c  0x004a09f0  size=140
int sub_4A09F0()
{
  int result; // eax
  const char *v1; // edx
  const char *v2; // ecx
  const char *v3; // eax
  _BYTE v4[256]; // [esp+0h] [ebp-100h] BYREF

  result = 1;
  if ( dword_8AC490 + 396 * dword_8AC48C && dword_7D032C == 1 )
  {
    v1 = (const char *)(dword_8AC490 + 396 * dword_8AC48C + 4);
    v2 = &v1[strlen(v1)];
    if ( v2 > v1 )
    {
      while ( *v2 != 92 )
      {
        if ( --v2 <= v1 )
          goto LABEL_8;
      }
      ++v2;
    }
LABEL_8:
    v3 = (const char *)dword_5EC418;
    if ( !dword_5EC418 )
      v3 = byte_5EA438;
    sub_58815F(v4, "%s%s%s", v3, v2, aBik_0);
    return sub_4F9B70(v4, 1);
  }
  return result;
}
