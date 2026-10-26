DWORD __stdcall sub_591DE0(_BYTE *a1)
{
  DWORD result; // eax
  CHAR v2; // cl
  int v3; // edx
  int v4; // ebp
  const char *v5; // edi
  int *v6; // ecx
  int v7; // edi
  int *v8; // esi
  char v9; // cl
  CHAR FileName[256]; // [esp+10h] [ebp-100h] BYREF

  result = (DWORD)a1;
  if ( *a1 && dword_7E8D58 < 32 )
  {
    do
    {
      v2 = *(_BYTE *)result;
      *(_BYTE *)(FileName - a1 + result) = *(_BYTE *)result;
      ++result;
    }
    while ( v2 );
    _strupr(FileName);
    result = GetFileAttributesA(FileName);
    if ( result != -1 && (result & 0x10) != 0 )
    {
      v3 = dword_7E8D58;
      v4 = 0;
      if ( dword_7E8D58 <= 0 )
      {
LABEL_14:
        result = 0;
        do
        {
          v9 = FileName[result];
          byte_7E4CCC[result++] = v9;
        }
        while ( v9 );
        dword_7E4CC8[0] |= 0x4000u;
        dword_7E8D58 = v3 + 1;
      }
      else
      {
        v5 = byte_7E4CCC;
        while ( 1 )
        {
          result = strcmp(FileName, v5);
          if ( !result )
            break;
          ++v4;
          v5 += 132;
          if ( v4 >= dword_7E8D58 )
          {
            if ( dword_7E8D58 > 0 )
            {
              v6 = &dword_7E4CC8[33 * dword_7E8D58];
              v7 = dword_7E8D58;
              do
              {
                v8 = v6 - 33;
                sub_591DA0(v6, v6 - 33);
                --v7;
                v6 = v8;
              }
              while ( v7 );
              v3 = dword_7E8D58;
            }
            goto LABEL_14;
          }
        }
      }
    }
  }
  return result;
}
