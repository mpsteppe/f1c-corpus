int __stdcall sub_53C800(_BYTE *a1)
{
  int result; // eax
  CHAR v2; // cl
  int v3; // edx
  int v4; // ebp
  const char *v5; // edi
  int *v6; // ecx
  int v7; // edi
  int *v8; // esi
  char v9; // cl
  CHAR SrcStr[256]; // [esp+10h] [ebp-100h] BYREF

  result = (int)a1;
  if ( *a1 && dword_8B8E30 < 32 )
  {
    do
    {
      v2 = *(_BYTE *)result;
      *(_BYTE *)(SrcStr - a1 + result) = *(_BYTE *)result;
      ++result;
    }
    while ( v2 );
    sub_589901(SrcStr);
    v3 = dword_8B8E30;
    v4 = 0;
    if ( dword_8B8E30 <= 0 )
    {
LABEL_12:
      result = 0;
      do
      {
        v9 = SrcStr[result];
        byte_8B5A3C[result++] = v9;
      }
      while ( v9 );
      dword_8B8E30 = v3 + 1;
    }
    else
    {
      v5 = byte_8B5A3C;
      while ( 1 )
      {
        result = strcmp(SrcStr, v5);
        if ( !result )
          break;
        ++v4;
        v5 += 132;
        if ( v4 >= dword_8B8E30 )
        {
          if ( dword_8B8E30 > 0 )
          {
            v6 = &dword_8B5A38[33 * dword_8B8E30];
            v7 = dword_8B8E30;
            do
            {
              v8 = v6 - 33;
              ArithmeticComparison_c6b0(v6, v6 - 33);
              --v7;
              v6 = v8;
            }
            while ( v7 );
            v3 = dword_8B8E30;
          }
          goto LABEL_12;
        }
      }
    }
  }
  return result;
}

