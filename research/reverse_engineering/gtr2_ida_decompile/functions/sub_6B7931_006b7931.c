int __stdcall sub_6B7931(int a1, int a2, int a3, int a4, int a5, int a6, int a7, unsigned int a8)
{
  int v8; // esi
  char v9; // dl
  bool v10; // zf
  int v11; // eax
  int result; // eax
  _BYTE v13[4]; // [esp+Ch] [ebp-10h] BYREF
  _BYTE v14[12]; // [esp+10h] [ebp-Ch] BYREF

  if ( !a5 )
  {
    if ( a4 <= 0 || a4 > 2 && a4 != 4 && a4 != 8 && a4 != 16 )
      sub_679F05(a1, (int)"Invalid bit depth for grayscale image");
    goto LABEL_19;
  }
  if ( a5 != 2 )
  {
    if ( a5 != 3 )
    {
      v8 = a1;
      if ( a5 == 4 )
      {
        if ( a4 != 8 && a4 != 16 )
          sub_679F05(a1, (int)"Invalid bit depth for grayscale+alpha image");
        *(_BYTE *)(a1 + 282) = 2;
      }
      else
      {
        if ( a5 != 6 )
          sub_679F05(a1, (int)"Invalid image color type specified");
        if ( a4 != 8 && a4 != 16 )
          sub_679F05(a1, (int)"Invalid bit depth for RGBA image");
        *(_BYTE *)(a1 + 282) = 4;
      }
      goto LABEL_31;
    }
    if ( a4 <= 0 || a4 > 2 && a4 != 4 && a4 != 8 )
      sub_679F05(a1, (int)"Invalid bit depth for paletted image");
LABEL_19:
    v8 = a1;
    *(_BYTE *)(a1 + 282) = 1;
    goto LABEL_31;
  }
  v8 = a1;
  if ( a4 != 8 && a4 != 16 )
    sub_679F05(a1, (int)"Invalid bit depth for RGB image");
  *(_BYTE *)(a1 + 282) = 3;
LABEL_31:
  if ( a6 )
  {
    sub_679F26(v8, (int)"Invalid compression type specified");
    LOBYTE(a6) = 0;
  }
  if ( a7 )
  {
    sub_679F26(v8, (int)"Invalid filter type specified");
    LOBYTE(a7) = 0;
  }
  if ( a8 >= 2 )
  {
    sub_679F26(v8, (int)"Invalid interlace type specified");
    LOBYTE(a8) = 1;
  }
  v9 = *(_BYTE *)(v8 + 282);
  *(_BYTE *)(v8 + 278) = a5;
  *(_BYTE *)(v8 + 275) = a8;
  *(_BYTE *)(v8 + 281) = a4 * v9;
  *(_DWORD *)(v8 + 200) = (a2 * ((unsigned int)(unsigned __int8)(a4 * v9) + 7)) >> 3;
  *(_BYTE *)(v8 + 279) = a4;
  *(_DWORD *)(v8 + 184) = a2;
  *(_DWORD *)(v8 + 188) = a3;
  *(_DWORD *)(v8 + 196) = a2;
  *(_BYTE *)(v8 + 280) = a4;
  *(_BYTE *)(v8 + 283) = v9;
  sub_6B7413(v13, a2);
  sub_6B7413(v14, a3);
  v14[5] = a5;
  v14[6] = a6;
  v14[7] = a7;
  v14[8] = a8;
  v14[4] = a4;
  sub_6B7904(v8, (int)"IHDR", (int)v13, 13);
  v10 = *(_BYTE *)(v8 + 277) == 0;
  *(_DWORD *)(v8 + 132) = sub_679FD8;
  *(_DWORD *)(v8 + 136) = sub_67A02E;
  *(_DWORD *)(v8 + 140) = v8;
  if ( v10 )
  {
    if ( *(_BYTE *)(v8 + 278) == 3 || *(_BYTE *)(v8 + 279) < 8u )
      *(_BYTE *)(v8 + 277) = 8;
    else
      *(_BYTE *)(v8 + 277) = -8;
  }
  v11 = *(_DWORD *)(v8 + 92);
  if ( (v11 & 1) == 0 )
    *(_DWORD *)(v8 + 180) = *(_BYTE *)(v8 + 277) != 8;
  if ( (v11 & 2) == 0 )
    *(_DWORD *)(v8 + 164) = -1;
  if ( (v11 & 4) == 0 )
    *(_DWORD *)(v8 + 176) = 8;
  if ( (v11 & 8) == 0 )
    *(_DWORD *)(v8 + 172) = 15;
  if ( (v11 & 0x10) == 0 )
    *(_DWORD *)(v8 + 168) = 8;
  sub_6B96C8(
    v8 + 100,
    *(_DWORD *)(v8 + 164),
    *(_DWORD *)(v8 + 168),
    *(_DWORD *)(v8 + 172),
    *(_DWORD *)(v8 + 176),
    *(_DWORD *)(v8 + 180),
    "1.1.4",
    56);
  *(_DWORD *)(v8 + 112) = *(_DWORD *)(v8 + 156);
  result = *(_DWORD *)(v8 + 160);
  *(_DWORD *)(v8 + 116) = result;
  *(_DWORD *)(v8 + 88) = 1;
  return result;
}
