int sub_4B9F60()
{
  int result; // eax
  const char *v1; // edx
  const char *v2; // ecx
  const char *v3; // eax
  char Buffer[256]; // [esp+0h] [ebp-100h] BYREF

  result = 1;
  if ( dword_7D6B58 + 400 * dword_7D6B54 && dword_7688E8 == 1 )
  {
    v1 = (const char *)(dword_7D6B58 + 400 * dword_7D6B54 + 4);
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
    v3 = (const char *)dword_62A0A8;
    if ( !dword_62A0A8 )
      v3 = &byte_629120;
    sprintf(Buffer, "%s%s%s", v3, v2, aBik_0);
    return sub_527460(Buffer, 1);
  }
  return result;
}
