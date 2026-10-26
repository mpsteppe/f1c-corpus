int (__cdecl *__cdecl sub_511B7C(int a1, int a2, int a3))(int, _DWORD, _DWORD)
{
  int v3; // esi
  int (__cdecl *result)(int, _DWORD, _DWORD); // eax
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

  v3 = a1;
  if ( (*(_BYTE *)(a1 + 92) & 0x40) == 0 )
    AudioBufferSizeCalc(a1);
  if ( !*(_BYTE *)(v3 + 275) || (*(_BYTE *)(v3 + 96) & 2) == 0 )
    goto LABEL_36;
  switch ( *(_BYTE *)(v3 + 276) )
  {
    case 0:
      if ( (*(_BYTE *)(v3 + 212) & 7) == 0 )
        break;
      v6 = a3 == 0;
      goto LABEL_34;
    case 1:
      if ( (*(_BYTE *)(v3 + 212) & 7) != 0 || *(_DWORD *)(v3 + 184) < 5u )
      {
        if ( a3 )
          JPEGHuffmanDecoder(v3, a3, 15);
        return (int (__cdecl *)(int, _DWORD, _DWORD))sub_519019(v3);
      }
      break;
    case 2:
      v7 = *(_DWORD *)(v3 + 212);
      if ( (v7 & 7) == 4 )
        break;
      if ( !a3 )
        return (int (__cdecl *)(int, _DWORD, _DWORD))sub_519019(v3);
      v6 = (v7 & 4) == 0;
LABEL_34:
      if ( !v6 )
        JPEGHuffmanDecoder(v3, a3, 255);
      return (int (__cdecl *)(int, _DWORD, _DWORD))sub_519019(v3);
    case 3:
      if ( (*(_BYTE *)(v3 + 212) & 3) != 0 || *(_DWORD *)(v3 + 184) < 3u )
      {
        if ( a3 )
          JPEGHuffmanDecoder(v3, a3, 51);
        return (int (__cdecl *)(int, _DWORD, _DWORD))sub_519019(v3);
      }
      break;
    case 4:
      v5 = *(_DWORD *)(v3 + 212);
      if ( (v5 & 3) == 2 )
        break;
      if ( a3 )
      {
        v6 = (v5 & 2) == 0;
        goto LABEL_34;
      }
      return (int (__cdecl *)(int, _DWORD, _DWORD))sub_519019(v3);
    case 5:
      if ( (*(_BYTE *)(v3 + 212) & 1) != 0 || *(_DWORD *)(v3 + 184) < 2u )
      {
        if ( a3 )
          JPEGHuffmanDecoder(v3, a3, 85);
        return (int (__cdecl *)(int, _DWORD, _DWORD))sub_519019(v3);
      }
      break;
    default:
      if ( *(_BYTE *)(v3 + 276) == 6 && (*(_BYTE *)(v3 + 212) & 1) == 0 )
        return (int (__cdecl *)(int, _DWORD, _DWORD))sub_519019(v3);
      break;
  }
LABEL_36:
  if ( (*(_BYTE *)(v3 + 88) & 4) == 0 )
    GuardedCallWithLongjmp(v3, (int)"Invalid attempt to read row data");
  *(_DWORD *)(v3 + 112) = *(_DWORD *)(v3 + 220);
  *(_DWORD *)(v3 + 116) = *(_DWORD *)(v3 + 204);
  while ( 1 )
  {
    if ( !*(_DWORD *)(v3 + 104) )
    {
      while ( !*(_DWORD *)(v3 + 252) )
      {
        sub_518828(v3, 0);
        CallbackDispatchWithNullGuard(v3, &a1, 4);
        *(_DWORD *)(v3 + 252) = ByteArrayToInt(&a1);
        AnimationHandleAlloc(v3);
        sub_517F58(v3, v3 + 268, 4);
        if ( *(_DWORD *)(v3 + 268) != *(_DWORD *)"IDAT" )
          GuardedCallWithLongjmp(v3, (int)"Not enough image data");
      }
      v8 = *(_DWORD *)(v3 + 160);
      v9 = *(_DWORD *)(v3 + 252);
      v10 = *(_DWORD *)(v3 + 156);
      *(_DWORD *)(v3 + 104) = v8;
      *(_DWORD *)(v3 + 100) = v10;
      if ( v8 > v9 )
        *(_DWORD *)(v3 + 104) = v9;
      sub_517F58(v3, v10, *(_DWORD *)(v3 + 104));
      *(_DWORD *)(v3 + 252) -= *(_DWORD *)(v3 + 104);
    }
    v11 = sub_517ADC(v3 + 100, 1);
    if ( v11 == 1 )
      break;
    if ( v11 )
    {
      v12 = *(const char **)(v3 + 124);
      if ( !v12 )
        v12 = "Decompression error";
      GuardedCallWithLongjmp(v3, (int)v12);
    }
    if ( !*(_DWORD *)(v3 + 116) )
      goto LABEL_59;
  }
  if ( *(_DWORD *)(v3 + 116) || *(_DWORD *)(v3 + 104) || *(_DWORD *)(v3 + 252) )
    GuardedCallWithLongjmp(v3, (int)"Extra compressed data");
  *(_DWORD *)(v3 + 88) |= 8u;
  *(_DWORD *)(v3 + 92) |= 0x20u;
LABEL_59:
  v13 = *(_BYTE *)(v3 + 278);
  *(_BYTE *)(v3 + 250) = *(_BYTE *)(v3 + 282);
  *(_BYTE *)(v3 + 249) = *(_BYTE *)(v3 + 279);
  v14 = *(_BYTE *)(v3 + 281);
  *(_BYTE *)(v3 + 251) = v14;
  *(_BYTE *)(v3 + 248) = v13;
  v15 = *(_DWORD *)(v3 + 208);
  v16 = v15 * v14 + 7;
  *(_DWORD *)(v3 + 240) = v15;
  v17 = *(unsigned __int8 **)(v3 + 220);
  *(_DWORD *)(v3 + 244) = v16 >> 3;
  sub_518511(v3, v3 + 240, v17 + 1, *(_DWORD *)(v3 + 216) + 1, *v17);
  MemoryCopy(v3, *(_DWORD *)(v3 + 216), *(_DWORD *)(v3 + 220), *(_DWORD *)(v3 + 200) + 1);
  if ( *(_DWORD *)(v3 + 96) )
    sub_51389E(v3);
  if ( *(_BYTE *)(v3 + 275) && (*(_DWORD *)(v3 + 96) & 2) != 0 )
  {
    v18 = *(_BYTE *)(v3 + 276);
    if ( v18 < 6u )
      TextureHorizontalStretch(v3 + 240, *(_DWORD *)(v3 + 220) + 1, v18);
    if ( a3 )
      JPEGHuffmanDecoder(v3, a3, dword_5AF248[*(unsigned __int8 *)(v3 + 276)]);
    if ( a2 )
      JPEGHuffmanDecoder(v3, a2, dword_5AF22C[*(unsigned __int8 *)(v3 + 276)]);
  }
  else
  {
    if ( a2 )
      JPEGHuffmanDecoder(v3, a2, 255);
    if ( a3 )
      JPEGHuffmanDecoder(v3, a3, 255);
  }
  sub_519019(v3);
  result = *(int (__cdecl **)(int, _DWORD, _DWORD))(v3 + 364);
  if ( result )
    return (int (__cdecl *)(int, _DWORD, _DWORD))result(v3, *(_DWORD *)(v3 + 212), *(unsigned __int8 *)(v3 + 276));
  return result;
}

