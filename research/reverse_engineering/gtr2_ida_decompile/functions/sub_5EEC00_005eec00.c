int __thiscall sub_5EEC00(_DWORD *this, HGDIOBJ h, const char *a3, int a4)
{
  int cx_low; // edi
  HDC CompatibleDC; // esi
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // ecx
  LONG v11; // edi
  int v13; // ebx
  int v14; // edi
  LONG v15; // ebx
  unsigned __int8 v16; // al
  LONG v17; // edi
  bool v18; // zf
  void (__stdcall *v19)(HDC, HGDIOBJ); // edi
  signed int v20; // ebx
  int v21; // eax
  int v22; // ecx
  _DWORD *v23; // edx
  int v24; // eax
  _DWORD *v25; // edi
  unsigned int v26; // eax
  double v27; // st7
  unsigned __int8 v28; // cl
  unsigned __int16 v29; // dx
  int v30; // edx
  int v31; // eax
  unsigned int *v32; // edi
  unsigned int v33; // ebx
  double v34; // st7
  int v35; // eax
  CHAR i; // [esp+1Bh] [ebp-1ADh]
  char v37; // [esp+1Bh] [ebp-1ADh]
  LONG cy; // [esp+1Ch] [ebp-1ACh]
  _DWORD *v39; // [esp+1Ch] [ebp-1ACh]
  int v40; // [esp+20h] [ebp-1A8h]
  int j; // [esp+20h] [ebp-1A8h]
  int v42; // [esp+20h] [ebp-1A8h]
  int v43; // [esp+20h] [ebp-1A8h]
  CHAR String[4]; // [esp+24h] [ebp-1A4h] BYREF
  int v45; // [esp+28h] [ebp-1A0h]
  char v46; // [esp+2Fh] [ebp-199h]
  int v47; // [esp+30h] [ebp-198h]
  int Buffer; // [esp+34h] [ebp-194h] BYREF
  UINT iFirst; // [esp+38h] [ebp-190h]
  int v50; // [esp+3Ch] [ebp-18Ch] BYREF
  POINT apt; // [esp+40h] [ebp-188h] BYREF
  LONG x; // [esp+48h] [ebp-180h]
  LONG y; // [esp+4Ch] [ebp-17Ch]
  LONG v54; // [esp+50h] [ebp-178h]
  int v55; // [esp+54h] [ebp-174h]
  char *v56; // [esp+58h] [ebp-170h]
  HGDIOBJ Pen; // [esp+5Ch] [ebp-16Ch]
  HGDIOBJ ho; // [esp+60h] [ebp-168h]
  HGDIOBJ v59; // [esp+64h] [ebp-164h]
  HGDIOBJ v60; // [esp+68h] [ebp-160h]
  void *ppvBits; // [esp+6Ch] [ebp-15Ch] BYREF
  HGDIOBJ v62; // [esp+70h] [ebp-158h]
  tagSIZE psizl; // [esp+74h] [ebp-154h] BYREF
  _ABC ABC; // [esp+7Ch] [ebp-14Ch] BYREF
  HGDIOBJ v65; // [esp+88h] [ebp-140h]
  BITMAPINFO pbmi; // [esp+8Ch] [ebp-13Ch] BYREF
  RECT rect; // [esp+B8h] [ebp-110h] BYREF
  WCHAR WideCharStr[128]; // [esp+C8h] [ebp-100h] BYREF

  cx_low = 0;
  v55 = (int)this;
  cy = 0;
  strcpy(String, "x");
  CompatibleDC = CreateCompatibleDC(0);
  GetDeviceCaps(CompatibleDC, 90);
  v62 = SelectObject(CompatibleDC, h);
  SetMapMode(CompatibleDC, 1);
  v7 = this[21];
  v8 = BYTE1(v7);
  BYTE1(v8) = v7;
  SetTextColor(CompatibleDC, BYTE2(v7) | (v8 << 8));
  v9 = this[23];
  v10 = BYTE1(v9);
  BYTE1(v10) = v9;
  SetBkColor(CompatibleDC, BYTE2(v9) | (v10 << 8));
  SetTextAlign(CompatibleDC, 0);
  for ( i = 32; (unsigned __int8)i < 0x7Fu; ++i )
  {
    String[0] = i;
    GetTextExtentPoint32A(CompatibleDC, String, 1, &psizl);
    if ( cx_low <= LOBYTE(psizl.cx) )
      cx_low = LOBYTE(psizl.cx);
    if ( cy <= psizl.cy )
      cy = psizl.cy;
  }
  if ( cx_low <= cy )
    cx_low = cy;
  else
    cy = cx_low;
  v11 = 10 * cx_low + 11;
  v54 = v11;
  pbmi.bmiHeader.biSize = 40;
  pbmi.bmiHeader.biWidth = v11;
  pbmi.bmiHeader.biHeight = -v11;
  pbmi.bmiHeader.biPlanes = 1;
  memset(&pbmi.bmiHeader.biCompression, 0, 24);
  pbmi.bmiHeader.biBitCount = 32;
  Pen = CreatePen(0, 0, (COLORREF)&byte_FF00FF);
  v59 = CreatePen(0, 0, 0xFFFFu);
  ho = CreateDIBSection(CompatibleDC, &pbmi, 0, &ppvBits, 0, 0);
  v65 = SelectObject(CompatibleDC, Pen);
  v60 = SelectObject(CompatibleDC, ho);
  if ( sub_5E7D70(this, (void **)&v50, v11, v11, 8, 1) )
  {
    SelectObject(CompatibleDC, v60);
    SelectObject(CompatibleDC, v62);
    DeleteObject(ho);
    DeleteDC(CompatibleDC);
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error creating scanning texture for font %s", (_BYTE)this + 20);
    return -1;
  }
  apt.x = 0;
  x = v11;
  y = 0;
  apt.y = 0;
  v13 = cy + 1;
  v40 = 11;
  do
  {
    Polyline(CompatibleDC, &apt, 2);
    apt.y += v13;
    y = apt.y;
    --v40;
  }
  while ( v40 );
  y = v11;
  apt.y = 0;
  x = 0;
  apt.x = 0;
  v14 = 11;
  do
  {
    Polyline(CompatibleDC, &apt, 2);
    --v14;
    apt.x += v13;
    x = apt.x;
  }
  while ( v14 );
  v15 = 1;
  v16 = 32;
  v37 = 32;
  v47 = 10;
  v17 = 1;
  for ( j = 10; ; j = 10 )
  {
    while ( 1 )
    {
      if ( v16 <= 0x7Fu )
      {
        String[0] = v16;
        v46 = 1;
      }
      else
      {
        String[0] = 32;
        v46 = 0;
      }
      iFirst = v16;
      if ( !GetCharABCWidthsA(CompatibleDC, v16, v16, &ABC) )
      {
        GetCharWidth32A(CompatibleDC, iFirst, iFirst, &Buffer);
        ABC.abcA = 1;
        ABC.abcB = Buffer;
        ABC.abcC = 1;
      }
      GetTextExtentPoint32A(CompatibleDC, String, 1, &psizl);
      ceil((double)psizl.cy * 0.30000001);
      rect.left = v17;
      rect.top = v15;
      rect.right = v17 + cy;
      rect.bottom = v15 + cy;
      SelectObject(CompatibleDC, Pen);
      ExtTextOutA(CompatibleDC, v17, v15, 2u, &rect, String, 1u, 0);
      if ( v46 )
      {
        SelectObject(CompatibleDC, v59);
        apt.x = v17 + ABC.abcA + ABC.abcC + ABC.abcB;
        x = apt.x + 1;
        y = v15;
        apt.y = v15;
        Polyline(CompatibleDC, &apt, 2);
      }
      v17 += cy + 1;
      v18 = j == 1;
      ++v37;
      --j;
      if ( v18 )
        break;
      v16 = v37;
    }
    v15 += cy + 1;
    if ( !--v47 )
      break;
    v16 = v37;
    v17 = 1;
  }
  v19 = (void (__stdcall *)(HDC, HGDIOBJ))SelectObject;
  SelectObject(CompatibleDC, v59);
  v20 = v54;
  apt.x = v54 - 3;
  x = v54 - 3 + 1;
  y = v54 - 2;
  apt.y = v54 - 2;
  Polyline(CompatibleDC, &apt, 2);
  v21 = sub_5E6E70((void *)v50, 0, 0, 2);
  v22 = v55;
  v23 = (_DWORD *)v21;
  v24 = *(_DWORD *)(v55 + 16);
  v39 = v23;
  if ( (v24 & 0x18000) != 0 )
  {
    if ( (v24 & 0x8000) == 0 )
    {
      if ( (v24 & 0x10000) != 0 )
      {
        Buffer = -16777216;
        v56 = byte_FFFFFF;
      }
    }
    else
    {
      Buffer = -1;
      v56 = 0;
    }
    if ( v20 <= 0 )
      goto LABEL_63;
    v42 = 0;
    iFirst = v20;
    do
    {
      v25 = v23;
      v47 = v42;
      v54 = v20;
      do
      {
        v26 = (unsigned int)byte_FFFFFF & *(_DWORD *)((_BYTE *)ppvBits + v47);
        if ( v26 == ((unsigned int)byte_FFFFFF & *(_DWORD *)(v22 + 92)) )
        {
          *v25 = v56;
        }
        else if ( v26 == ((unsigned int)byte_FFFFFF & *(_DWORD *)(v22 + 84)) )
        {
          *v25 = Buffer;
        }
        else
        {
          v45 = (unsigned __int8)v26;
          v27 = (double)BYTE1(v26) * 0.58999997 + (double)BYTE2(v26) * 0.30000001 + (double)(unsigned __int8)v26 * 0.11;
          if ( v27 > 255.0 )
            v27 = 255.0;
          v28 = (unsigned __int64)v27;
          if ( (*(_BYTE *)(v55 + 18) & 1) != 0 )
            v28 = (unsigned __int8)(unsigned __int64)v27 == 0;
          LOBYTE(v29) = 0;
          HIBYTE(v29) = (unsigned __int64)v27;
          v30 = v28 | ((v28 | ((v28 | v29) << 8)) << 8);
          v22 = v55;
          *v25 = v30;
        }
        ++v25;
        v18 = v54 == 1;
        v47 += 4;
        --v54;
      }
      while ( !v18 );
      v23 = (_DWORD *)((char *)v39 + *(_DWORD *)(v50 + 16));
      v18 = iFirst == 1;
      v39 = v23;
      v42 += 4 * v20;
      --iFirst;
    }
    while ( !v18 );
    goto LABEL_62;
  }
  if ( v20 > 0 )
  {
    v31 = 0;
    Buffer = 0;
    v47 = 4 * v20;
    v56 = (char *)v20;
    do
    {
      v32 = v23;
      if ( v20 > 0 )
      {
        v43 = v31;
        iFirst = v20;
        do
        {
          v33 = (unsigned int)byte_FFFFFF & *(_DWORD *)((_BYTE *)ppvBits + v43);
          if ( v33 == ((unsigned int)byte_FFFFFF & *(_DWORD *)(v55 + 92)) )
          {
            *v32 = v33;
          }
          else if ( v33 == ((unsigned int)byte_FFFFFF & *(_DWORD *)(v55 + 84)) )
          {
            *v32 = v33 | 0xFF000000;
          }
          else
          {
            v45 = (unsigned __int8)v33;
            v34 = (double)BYTE1(v33) * 0.58999997
                + (double)BYTE2(v33) * 0.30000001
                + (double)(unsigned __int8)v33 * 0.11;
            if ( v34 > 255.0 )
              v34 = 255.0;
            *v32 = v33 | ((unsigned int)(unsigned __int64)v34 << 24);
          }
          ++v32;
          v18 = iFirst == 1;
          v43 += 4;
          --iFirst;
        }
        while ( !v18 );
        v20 = v54;
        v23 = v39;
      }
      v23 = (_DWORD *)((char *)v23 + *(_DWORD *)(v50 + 16));
      v31 = v47 + Buffer;
      v18 = v56 == (char *)1;
      v39 = v23;
      Buffer += v47;
      --v56;
    }
    while ( !v18 );
LABEL_62:
    v19 = (void (__stdcall *)(HDC, HGDIOBJ))SelectObject;
  }
LABEL_63:
  sub_5E6EA0((void *)v50, 0, 0, 2);
  v19(CompatibleDC, v60);
  v19(CompatibleDC, v62);
  v19(CompatibleDC, v65);
  DeleteObject(ho);
  DeleteObject(Pen);
  DeleteObject(v59);
  DeleteDC(CompatibleDC);
  strcpy((char *)WideCharStr, a3);
  v35 = sub_5E7120((int *)v50, 0);
  sub_644996(WideCharStr, 4, v35, 0, 0);
  sub_5E7F70((void *)v55, v50);
  return 0;
}
