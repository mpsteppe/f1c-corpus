int __thiscall sub_5EF3E0(int this, HGDIOBJ h)
{
  int v3; // eax
  int v4; // eax
  bool v5; // cc
  HDC CompatibleDC; // ebp
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // ecx
  LONG v12; // ebx
  int cx_low; // eax
  LONG cy; // ecx
  LONG v15; // eax
  UINT v16; // eax
  _BYTE *v17; // esi
  double abcfC; // st7
  int v19; // ecx
  LONG v20; // edx
  double v21; // st7
  __int16 left; // bx
  unsigned __int64 v23; // rax
  char bottom; // cl
  unsigned __int8 v25; // cl
  UINT v26; // ebx
  double v27; // st7
  bool v28; // cf
  _DWORD *v29; // ecx
  void **v30; // esi
  int v31; // ebx
  int v32; // eax
  UINT v33; // edx
  int v34; // eax
  int v35; // eax
  int v36; // ecx
  _DWORD *v37; // esi
  unsigned int v38; // eax
  double v39; // st7
  unsigned __int8 v40; // cl
  unsigned __int16 v41; // dx
  bool v42; // zf
  int v43; // ecx
  _DWORD *v44; // esi
  unsigned int v45; // ebx
  double v46; // st7
  CHAR i; // [esp+1Bh] [ebp-85h]
  CHAR v48; // [esp+1Bh] [ebp-85h]
  unsigned int v49; // [esp+20h] [ebp-80h]
  int top_low; // [esp+20h] [ebp-80h]
  int v51; // [esp+20h] [ebp-80h]
  CHAR String[4]; // [esp+24h] [ebp-7Ch] BYREF
  int v53; // [esp+28h] [ebp-78h]
  int v54; // [esp+2Ch] [ebp-74h]
  LONG v55; // [esp+30h] [ebp-70h]
  int v56; // [esp+34h] [ebp-6Ch]
  UINT iFirst; // [esp+38h] [ebp-68h]
  int Buffer; // [esp+3Ch] [ebp-64h] BYREF
  struct tagSIZE psizl; // [esp+40h] [ebp-60h] BYREF
  void *ppvBits; // [esp+48h] [ebp-58h] BYREF
  HGDIOBJ v61; // [esp+4Ch] [ebp-54h]
  HGDIOBJ ho; // [esp+50h] [ebp-50h]
  HGDIOBJ v63; // [esp+54h] [ebp-4Ch]
  struct tagRECT rc; // [esp+58h] [ebp-48h] BYREF
  _ABCFLOAT ABC; // [esp+68h] [ebp-38h] BYREF
  BITMAPINFO pbmi; // [esp+74h] [ebp-2Ch] BYREF

  v3 = *(_DWORD *)(this + 128);
  if ( v3 <= 56 )
  {
    if ( v3 <= 28 )
    {
      v5 = v3 <= 20;
      v4 = 512;
      if ( v5 )
        v4 = 256;
    }
    else
    {
      v4 = 1024;
    }
  }
  else
  {
    v4 = 2048;
  }
  v56 = v4;
  v53 = v4;
  pbmi.bmiHeader.biSize = 40;
  pbmi.bmiHeader.biWidth = v4;
  pbmi.bmiHeader.biHeight = -v4;
  pbmi.bmiHeader.biPlanes = 1;
  memset(&pbmi.bmiHeader.biCompression, 0, 24);
  pbmi.bmiHeader.biBitCount = 32;
  CompatibleDC = CreateCompatibleDC(0);
  ho = CreateDIBSection(CompatibleDC, &pbmi, 0, &ppvBits, 0, 0);
  v63 = SelectObject(CompatibleDC, ho);
  v61 = SelectObject(CompatibleDC, h);
  SetMapMode(CompatibleDC, 1);
  v7 = *(_DWORD *)(this + 84);
  v8 = BYTE1(v7);
  BYTE1(v8) = v7;
  SetTextColor(CompatibleDC, BYTE2(v7) | (v8 << 8));
  v9 = *(_DWORD *)(this + 92);
  v10 = BYTE1(v9);
  BYTE1(v10) = v9;
  SetBkColor(CompatibleDC, BYTE2(v9) | (v10 << 8));
  SetTextAlign(CompatibleDC, 0);
  if ( sub_5E47E0((void *)this, (_DWORD *)(this + 176), (const char *)(this + 20), v56, v53, 8, 1, 4, 0) )
  {
    SelectObject(CompatibleDC, v63);
    SelectObject(CompatibleDC, v61);
    DeleteObject(ho);
    DeleteDC(CompatibleDC);
    sub_5D8C80(this, (char *)0xFFFFFFFF, "Error creating scanning texture for font %s", this + 20);
    return -1;
  }
  else
  {
    v12 = 0;
    v55 = 0;
    strcpy(String, "x");
    for ( i = 32; (unsigned __int8)i < 0x7Fu; ++i )
    {
      String[0] = i;
      GetTextExtentPoint32A(CompatibleDC, String, 1, &psizl);
      cx_low = LOBYTE(psizl.cx);
      if ( *(_DWORD *)(this + 100) > (int)LOBYTE(psizl.cx) )
        cx_low = *(_DWORD *)(this + 100);
      cy = psizl.cy;
      *(_DWORD *)(this + 100) = cx_low;
      v15 = *(_DWORD *)(this + 104);
      if ( v15 <= cy )
        v15 = cy;
      *(_DWORD *)(this + 104) = v15;
    }
    v16 = 32;
    v48 = 32;
    iFirst = 32;
    v17 = (_BYTE *)(this + 191);
    while ( 1 )
    {
      String[0] = v48;
      if ( !GetCharABCWidthsFloatA(CompatibleDC, v16, v16, &ABC) )
      {
        GetCharWidth32A(CompatibleDC, iFirst, iFirst, &Buffer);
        ABC.abcfA = 1.0;
        ABC.abcfC = 1.0;
        ABC.abcfB = (float)Buffer;
      }
      GetTextExtentPoint32A(CompatibleDC, String, 1, &psizl);
      v49 = (unsigned __int64)ceil((double)psizl.cy * 0.30000001);
      abcfC = ABC.abcfC;
      *(v17 - 1) = (unsigned __int64)ABC.abcfA;
      v19 = v56;
      *v17 = (unsigned __int64)abcfC;
      if ( v12 + *(_DWORD *)(this + 100) > v19 )
      {
        v54 = 0;
        v12 = 0;
        v55 += psizl.cy + 1;
      }
      v20 = v55 + *(_DWORD *)(this + 104);
      rc.top = v55;
      rc.right = v12 + psizl.cx;
      rc.left = v12;
      rc.bottom = v20;
      DrawTextA(CompatibleDC, String, 1, &rc, 0x520u);
      DrawTextA(CompatibleDC, String, 1, &rc, 0x120u);
      v54 = psizl.cx - (unsigned __int64)((double)v49 * -2.0) + v12;
      v21 = ABC.abcfC <= 0.0 ? ABC.abcfC : 0.0;
      left = rc.left;
      v23 = (unsigned __int64)((double)(rc.right - rc.left) - v21);
      BYTE4(v23) = rc.top;
      bottom = rc.bottom;
      *(_WORD *)(v17 - 5) = rc.top;
      v25 = bottom - BYTE4(v23);
      *(v17 - 3) = v23;
      HIDWORD(v23) = left;
      *(_WORD *)(v17 - 7) = left;
      *(v17 - 2) = v25;
      top_low = SLOWORD(rc.top);
      v17 += 24;
      *(float *)(v17 - 23) = (double)left / (double)*(int *)(*(_DWORD *)(this + 176) + 4);
      v26 = iFirst;
      *(float *)(v17 - 19) = (double)top_low / (double)*(int *)(*(_DWORD *)(this + 176) + 8);
      v27 = (double)(HIDWORD(v23) + (unsigned __int8)v23) / (double)*(int *)(*(_DWORD *)(this + 176) + 4);
      v28 = (unsigned __int8)++v48 < 0x7Fu;
      iFirst = v26 + 1;
      *(float *)(v17 - 15) = v27;
      *(float *)(v17 - 11) = (double)(top_low + v25) / (double)*(int *)(*(_DWORD *)(this + 176) + 8);
      if ( !v28 )
        break;
      v12 = v54;
      v16 = iFirst;
    }
    v29 = *(_DWORD **)(this + 176);
    v30 = (void **)(this + 176);
    v31 = 0;
    *(_DWORD *)(this + 116) = v29[1] / *(_DWORD *)(this + 100);
    v32 = v29[2] / *(_DWORD *)(this + 104);
    *(_DWORD *)(this + 124) = 127;
    *(_DWORD *)(this + 120) = v32;
    v33 = sub_5E6E70(v29, 0, 0, 2);
    iFirst = v33;
    if ( v33 )
    {
      v34 = *(_DWORD *)(this + 16);
      if ( (v34 & 0x18000) != 0 )
      {
        if ( (v34 & 0x8000) == 0 )
        {
          if ( (v34 & 0x10000) != 0 )
          {
            v54 = -16777216;
            top_low = (int)byte_FFFFFF;
          }
        }
        else
        {
          v54 = -1;
          top_low = 0;
        }
        v35 = v53;
        if ( v53 > 0 )
        {
          v36 = v56;
          v53 = 0;
          Buffer = v35;
          do
          {
            v37 = (_DWORD *)v33;
            if ( v36 > 0 )
            {
              v55 = v36;
              do
              {
                v38 = (unsigned int)byte_FFFFFF & *(_DWORD *)((_BYTE *)ppvBits + v31);
                if ( v38 == ((unsigned int)byte_FFFFFF & *(_DWORD *)(this + 92)) )
                {
                  *v37 = top_low;
                }
                else if ( v38 == ((unsigned int)byte_FFFFFF & *(_DWORD *)(this + 84)) )
                {
                  *v37 = v54;
                }
                else
                {
                  v39 = (double)BYTE1(v38) * 0.58999997
                      + (double)BYTE2(v38) * 0.30000001
                      + (double)(unsigned __int8)v38 * 0.11;
                  if ( v39 > 255.0 )
                    v39 = 255.0;
                  v40 = (unsigned __int64)v39;
                  if ( (*(_DWORD *)(this + 16) & 0x10000) != 0 )
                    v40 = (unsigned __int8)(unsigned __int64)v39 == 0;
                  LOBYTE(v41) = 0;
                  HIBYTE(v41) = (unsigned __int64)v39;
                  *v37 = v40 | ((v40 | ((v40 | v41) << 8)) << 8);
                  v33 = iFirst;
                }
                ++v37;
                v31 += 4;
                --v55;
              }
              while ( v55 );
              v36 = v56;
            }
            v30 = (void **)(this + 176);
            v33 += *(_DWORD *)(*(_DWORD *)(this + 176) + 16);
            v31 = 4 * v36 + v53;
            v42 = Buffer == 1;
            iFirst = v33;
            v53 = v31;
            --Buffer;
          }
          while ( !v42 );
        }
      }
      else if ( v53 > 0 )
      {
        v43 = v56;
        v55 = 0;
        v51 = v53;
        do
        {
          v44 = (_DWORD *)v33;
          if ( v43 > 0 )
          {
            v54 = v55;
            Buffer = v43;
            do
            {
              v45 = (unsigned int)byte_FFFFFF & *(_DWORD *)((_BYTE *)ppvBits + v54);
              if ( v45 == ((unsigned int)byte_FFFFFF & *(_DWORD *)(this + 92)) )
              {
                *v44 = v45;
              }
              else if ( v45 == ((unsigned int)byte_FFFFFF & *(_DWORD *)(this + 84)) )
              {
                *v44 = v45 | 0xFF000000;
              }
              else
              {
                v46 = (double)BYTE1(v45) * 0.58999997
                    + (double)BYTE2(v45) * 0.30000001
                    + (double)(unsigned __int8)v45 * 0.11;
                if ( v46 > 255.0 )
                  v46 = 255.0;
                v43 = v56;
                v33 = iFirst;
                *v44 = v45 | ((unsigned int)(unsigned __int64)v46 << 24);
              }
              ++v44;
              v42 = Buffer == 1;
              v54 += 4;
              --Buffer;
            }
            while ( !v42 );
          }
          v30 = (void **)(this + 176);
          v33 += *(_DWORD *)(*(_DWORD *)(this + 176) + 16);
          v42 = v51 == 1;
          iFirst = v33;
          v55 += 4 * v43;
          --v51;
        }
        while ( !v42 );
      }
      sub_5E6EA0(*v30, 0, 0, 2);
      SelectObject(CompatibleDC, v63);
      SelectObject(CompatibleDC, v61);
      DeleteObject(ho);
      DeleteDC(CompatibleDC);
    }
    return 0;
  }
}
