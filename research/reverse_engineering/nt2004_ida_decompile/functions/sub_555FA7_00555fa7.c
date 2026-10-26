int __usercall sub_555FA7@<eax>(int a1@<ebx>, jmp_buf Buf)
{
  int *__attribute__((__org_typedef(jmp_buf))) v2; // esi
  int result; // eax
  unsigned __int8 v4; // bl
  unsigned int v5; // edx
  bool v6; // zf
  unsigned int v7; // eax
  unsigned int v8; // edx
  int v9; // ecx
  int v10; // eax
  const char *v11; // eax
  int v12; // [esp+4h] [ebp-4h] BYREF

  v2 = Buf;
  result = (int)(Buf + 53);
  ++Buf[53];
  if ( *(_DWORD *)result >= (unsigned int)v2[48] )
  {
    if ( *((_BYTE *)v2 + 275) )
    {
      *(_DWORD *)result = 0;
      sub_554E92(a1, (int)v2, (char *)v2[54], 0, v2[50] + 1);
      while ( 1 )
      {
        v4 = ++*((_BYTE *)v2 + 276);
        if ( v4 >= 7u )
          break;
        result = (v2[46] - dword_5F5040[v4] + dword_5F505C[v4] - 1) / (unsigned int)dword_5F505C[v4];
        v5 = ((result * (unsigned int)*((unsigned __int8 *)v2 + 281) + 7) >> 3) + 1;
        v6 = (v2[24] & 2) == 0;
        v2[52] = result;
        v2[51] = v5;
        if ( v6 )
        {
          result = (v2[47] - dword_5F5078[v4] + dword_5F5094[v4] - 1) / (unsigned int)dword_5F5094[v4];
          v6 = v2[52] == 0;
          v2[48] = result;
          if ( v6 )
            continue;
        }
        return result;
      }
    }
    if ( (v2[23] & 0x20) == 0 )
    {
      v2[28] = (int)&Buf;
      v2[29] = 1;
      while ( 1 )
      {
        if ( !v2[26] )
        {
          while ( !v2[63] )
          {
            sub_5557B6(v2, 0);
            sub_550B64(v2, (int)&v12, 4);
            v2[63] = sub_554EC3((unsigned __int8 *)&v12);
            sub_550C6B((int)v2);
            sub_554EE6(v2, (int)(v2 + 67), 4);
            if ( v2[67] != *(_DWORD *)"IDAT" )
              sub_54E7FC(v2, (int)"Not enough image data");
          }
          v7 = v2[40];
          v8 = v2[63];
          v9 = v2[39];
          v2[26] = v7;
          v2[25] = v9;
          if ( v7 > v8 )
            v2[26] = v8;
          sub_554EE6(v2, v9, v2[26]);
          v2[63] -= v2[26];
        }
        v10 = sub_554A6A((unsigned __int8 **)v2 + 25, 1);
        if ( v10 == 1 )
          break;
        if ( v10 )
        {
          v11 = (const char *)v2[31];
          if ( !v11 )
            v11 = "Decompression Error";
          sub_54E7FC(v2, (int)v11);
        }
        if ( !v2[29] )
          sub_54E7FC(v2, (int)"Extra compressed data");
      }
      if ( !v2[29] || v2[26] || v2[63] )
        sub_54E7FC(v2, (int)"Extra compressed data");
      v2[22] |= 8u;
      v2[23] |= 0x20u;
      v2[29] = 0;
    }
    if ( v2[63] || v2[26] )
      sub_54E7FC(v2, (int)"Extra compression data");
    result = sub_5548F1(v2 + 25);
    v2[22] |= 8u;
  }
  return result;
}
