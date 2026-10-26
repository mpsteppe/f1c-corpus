int *__thiscall sub_4CD640(_DWORD *this, char *Buffer, int a3)
{
  int *result; // eax
  char v4; // cl
  const char *v5; // edx
  const char *v6; // ecx
  char Destination[8]; // [esp+0h] [ebp-8h] BYREF

  if ( this[2334] )
  {
    result = &dword_5FE158;
    do
    {
      v4 = *(_BYTE *)result;
      *((_BYTE *)result + Buffer - (char *)&dword_5FE158) = *(_BYTE *)result;
      result = (int *)((char *)result + 1);
    }
    while ( v4 );
  }
  else
  {
    v5 = (const char *)this[126];
    if ( !v5 )
      v5 = &byte_629120;
    v6 = &v5[strlen(v5)];
    if ( v6 > v5 )
    {
      while ( *v6 != 92 )
      {
        if ( --v6 <= v5 )
          goto LABEL_12;
      }
      ++v6;
    }
LABEL_12:
    strncpy(Destination, v6, 4u);
    Destination[4] = 0;
    return (int *)sprintf(Buffer, "%s\\%s", (const char *)&dword_5FE158, Destination);
  }
  return result;
}
