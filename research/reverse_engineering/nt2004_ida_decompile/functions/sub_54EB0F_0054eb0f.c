int (__cdecl *__cdecl sub_54EB0F(jmp_buf Buf, int a2, int a3))(jmp_buf, int, _DWORD)
{
  int *__attribute__((__org_typedef(jmp_buf))) v3; // esi
  int (__cdecl *result)(int *__attribute__((__org_typedef(jmp_buf))), int, _DWORD); // eax
  int v5; // eax
  bool v6; // zf
  int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // edx
  int v10; // ecx
  int v11; // eax
  const char *v12; // eax
  char v13; // al
  unsigned __int8 v14; // cl
  int v15; // eax
  unsigned int v16; // ecx
  unsigned __int8 *v17; // eax
  unsigned __int8 v18; // cl

  v3 = Buf;
  if ( (Buf[23] & 0x40) == 0 )
    sub_55561A(Buf);
  if ( !*((_BYTE *)v3 + 275) || (v3[24] & 2) == 0 )
    goto LABEL_36;
  switch ( *((_BYTE *)v3 + 276) )
  {
    case 0:
      if ( (v3[53] & 7) == 0 )
        break;
      v6 = a3 == 0;
      goto LABEL_34;
    case 1:
      if ( (v3[53] & 7) != 0 || (unsigned int)v3[46] < 5 )
      {
        if ( a3 )
          sub_554FC0(v3, a3, 15);
        return (int (__cdecl *)(int *__attribute__((__org_typedef(jmp_buf))), int, _DWORD))sub_555FA7(v3);
      }
      break;
    case 2:
      v7 = v3[53];
      if ( (v7 & 7) == 4 )
        break;
      if ( !a3 )
        return (int (__cdecl *)(int *__attribute__((__org_typedef(jmp_buf))), int, _DWORD))sub_555FA7(v3);
      v6 = (v7 & 4) == 0;
LABEL_34:
      if ( !v6 )
        sub_554FC0(v3, a3, 255);
      return (int (__cdecl *)(int *__attribute__((__org_typedef(jmp_buf))), int, _DWORD))sub_555FA7(v3);
    case 3:
      if ( (v3[53] & 3) != 0 || (unsigned int)v3[46] < 3 )
      {
        if ( a3 )
          sub_554FC0(v3, a3, 51);
        return (int (__cdecl *)(int *__attribute__((__org_typedef(jmp_buf))), int, _DWORD))sub_555FA7(v3);
      }
      break;
    case 4:
      v5 = v3[53];
      if ( (v5 & 3) == 2 )
        break;
      if ( a3 )
      {
        v6 = (v5 & 2) == 0;
        goto LABEL_34;
      }
      return (int (__cdecl *)(int *__attribute__((__org_typedef(jmp_buf))), int, _DWORD))sub_555FA7(v3);
    case 5:
      if ( (v3[53] & 1) != 0 || (unsigned int)v3[46] < 2 )
      {
        if ( a3 )
          sub_554FC0(v3, a3, 85);
        return (int (__cdecl *)(int *__attribute__((__org_typedef(jmp_buf))), int, _DWORD))sub_555FA7(v3);
      }
      break;
    default:
      if ( *((_BYTE *)v3 + 276) == 6 && (v3[53] & 1) == 0 )
        return (int (__cdecl *)(int *__attribute__((__org_typedef(jmp_buf))), int, _DWORD))sub_555FA7(v3);
      break;
  }
LABEL_36:
  if ( (v3[22] & 4) == 0 )
    sub_54E7FC(v3, (int)"Invalid attempt to read row data");
  v3[28] = v3[55];
  v3[29] = v3[51];
  while ( 1 )
  {
    if ( !v3[26] )
    {
      while ( !v3[63] )
      {
        sub_5557B6(v3, 0);
        sub_550B64(v3, (int)&Buf, 4);
        v3[63] = sub_554EC3(&Buf);
        sub_550C6B(v3);
        sub_554EE6(v3, (int)(v3 + 67), 4);
        if ( v3[67] != *(_DWORD *)"IDAT" )
          sub_54E7FC(v3, (int)"Not enough image data");
      }
      v8 = v3[40];
      v9 = v3[63];
      v10 = v3[39];
      v3[26] = v8;
      v3[25] = v10;
      if ( v8 > v9 )
        v3[26] = v9;
      sub_554EE6(v3, v10, v3[26]);
      v3[63] -= v3[26];
    }
    v11 = sub_554A6A(v3 + 25, 1);
    if ( v11 == 1 )
      break;
    if ( v11 )
    {
      v12 = (const char *)v3[31];
      if ( !v12 )
        v12 = "Decompression error";
      sub_54E7FC(v3, (int)v12);
    }
    if ( !v3[29] )
      goto LABEL_59;
  }
  if ( v3[29] || v3[26] || v3[63] )
    sub_54E7FC(v3, (int)"Extra compressed data");
  v3[22] |= 8u;
  v3[23] |= 0x20u;
LABEL_59:
  v13 = *((_BYTE *)v3 + 278);
  *((_BYTE *)v3 + 250) = *((_BYTE *)v3 + 282);
  *((_BYTE *)v3 + 249) = *((_BYTE *)v3 + 279);
  v14 = *((_BYTE *)v3 + 281);
  *((_BYTE *)v3 + 251) = v14;
  *((_BYTE *)v3 + 248) = v13;
  v15 = v3[52];
  v16 = v15 * v14 + 7;
  v3[60] = v15;
  v17 = (unsigned __int8 *)v3[55];
  v3[61] = v16 >> 3;
  sub_55549F(v3, v3 + 60, v17 + 1, v3[54] + 1, *v17);
  sub_554E6F(v3, v3[54], v3[55], v3[50] + 1);
  if ( v3[24] )
    sub_550831(v3);
  if ( *((_BYTE *)v3 + 275) && (v3[24] & 2) != 0 )
  {
    v18 = *((_BYTE *)v3 + 276);
    if ( v18 < 6u )
      sub_5551D6(v3 + 60, v3[55] + 1, v18);
    if ( a3 )
      sub_554FC0(v3, a3, dword_5F47F0[*((unsigned __int8 *)v3 + 276)]);
    if ( a2 )
      sub_554FC0(v3, a2, dword_5F47D4[*((unsigned __int8 *)v3 + 276)]);
  }
  else
  {
    if ( a2 )
      sub_554FC0(v3, a2, 255);
    if ( a3 )
      sub_554FC0(v3, a3, 255);
  }
  sub_555FA7(v3);
  result = (int (__cdecl *)(int *__attribute__((__org_typedef(jmp_buf))), int, _DWORD))v3[91];
  if ( result )
    return (int (__cdecl *)(int *__attribute__((__org_typedef(jmp_buf))), int, _DWORD))result(
                                                                                         v3,
                                                                                         v3[53],
                                                                                         *((unsigned __int8 *)v3 + 276));
  return result;
}
