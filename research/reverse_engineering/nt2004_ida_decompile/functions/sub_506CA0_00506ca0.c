int __stdcall sub_506CA0(const char *a1)
{
  unsigned int v1; // ebx
  const char *v2; // edx
  int result; // eax
  _BYTE v4[256]; // [esp+Ch] [ebp-100h] BYREF

  if ( a1 )
  {
    sub_578600(a1);
    v1 = 0;
    if ( strlen(a1) )
    {
      v2 = a1;
      do
      {
        if ( *v2 == 46 )
          break;
        ++v1;
        v2[v4 - a1] = *v2;
        ++v2;
      }
      while ( v1 < strlen(a1) );
    }
    v4[v1] = 0;
    return sub_578600(v4);
  }
  return result;
}
