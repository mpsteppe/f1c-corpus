// f1_2002_full  0x00525120  size=243
int __stdcall sub_525120(_BYTE *a1)
{
  int result; // eax
  char v2; // cl
  int v3; // edx
  int v4; // ebp
  const char *v5; // edi
  int *v6; // ecx
  int v7; // edi
  int *v8; // esi
  char v9; // cl
  char String[256]; // [esp+10h] [ebp-100h] BYREF

  result = (int)a1;
  if ( *a1 && dword_6C8BFC < 32 )
  {
    do
    {
      v2 = *(_BYTE *)result;
      *(_BYTE *)(String - a1 + result) = *(_BYTE *)result;
      ++result;
    }
    while ( v2 );
    _strupr(String);
    v3 = dword_6C8BFC;
    v4 = 0;
    if ( dword_6C8BFC <= 0 )
    {
LABEL_12:
      result = 0;
      do
      {
        v9 = String[result];
        byte_6C5814[result++] = v9;
      }
      while ( v9 );
      dword_6C8BFC = v3 + 1;
    }
    else
    {
      v5 = byte_6C5814;
      while ( 1 )
      {
        result = strcmp(String, v5);
        if ( !result )
          break;
        ++v4;
        v5 += 132;
        if ( v4 >= dword_6C8BFC )
        {
          if ( dword_6C8BFC > 0 )
          {
            v6 = &dword_6C5810[33 * dword_6C8BFC];
            v7 = dword_6C8BFC;
            do
            {
              v8 = v6 - 33;
              sub_524FD0(v6 - 33);
              --v7;
              v6 = v8;
            }
            while ( v7 );
            v3 = dword_6C8BFC;
          }
          goto LABEL_12;
        }
      }
    }
  }
  return result;
}
