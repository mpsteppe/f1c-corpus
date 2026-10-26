int __thiscall sub_5A36B0(int this, HGDIOBJ h)
{
  int v3; // eax
  bool v4; // cc
  int v5; // eax
  HDC CompatibleDC; // edi
  HBITMAP v7; // ebx
  HGDIOBJ v8; // eax
  unsigned __int16 v9; // dx
  unsigned __int16 v10; // cx
  _DWORD *v11; // eax
  _DWORD *v12; // eax
  UINT v14; // ebx
  int v15; // ebp
  LONG v16; // eax
  LONG cx; // edx
  LONG cy; // ecx
  LONG v19; // eax
  __int16 v20; // ax
  __int16 v21; // cx
  UINT abcB; // eax
  int abcA; // ecx
  int abcC; // edx
  int v25; // ebx
  UINT v26; // edx
  int v27; // edx
  bool v28; // cf
  _DWORD *v29; // ecx
  int v30; // eax
  int v31; // eax
  int v32; // ebp
  int v33; // ebx
  _WORD *v34; // edx
  unsigned __int8 v35; // cl
  bool v36; // zf
  int v37; // [esp-10h] [ebp-8Ch]
  int v38; // [esp-Ch] [ebp-88h]
  CHAR String[2]; // [esp+12h] [ebp-6Ah] BYREF
  int x; // [esp+14h] [ebp-68h]
  int v41; // [esp+18h] [ebp-64h]
  int v42; // [esp+1Ch] [ebp-60h]
  int y; // [esp+20h] [ebp-5Ch]
  int v44; // [esp+24h] [ebp-58h]
  int Buffer; // [esp+28h] [ebp-54h] BYREF
  void *ppvBits; // [esp+2Ch] [ebp-50h] BYREF
  HGDIOBJ v47; // [esp+30h] [ebp-4Ch]
  HGDIOBJ v48; // [esp+34h] [ebp-48h]
  HGDIOBJ ho; // [esp+38h] [ebp-44h]
  tagSIZE psizl; // [esp+3Ch] [ebp-40h] BYREF
  _ABC ABC; // [esp+44h] [ebp-38h] BYREF
  BITMAPINFO pbmi; // [esp+50h] [ebp-2Ch] BYREF
  CHAR ha; // [esp+80h] [ebp+4h]
  char *hb; // [esp+80h] [ebp+4h]

  v3 = *(_DWORD *)(this + 144);
  if ( v3 <= 40 )
  {
    v4 = v3 <= 20;
    v5 = 512;
    if ( v4 )
      v5 = 256;
    v41 = v5;
    v42 = v5;
  }
  else
  {
    v41 = 1024;
    v42 = 512;
  }
  memset(&pbmi, 0, 0x28u);
  pbmi.bmiHeader.biSize = 40;
  pbmi.bmiHeader.biWidth = v41;
  pbmi.bmiHeader.biHeight = -v42;
  pbmi.bmiHeader.biPlanes = 1;
  pbmi.bmiHeader.biCompression = 0;
  pbmi.bmiHeader.biBitCount = 32;
  CompatibleDC = CreateCompatibleDC(0);
  v7 = CreateDIBSection(CompatibleDC, &pbmi, 0, &ppvBits, 0, 0);
  ho = v7;
  SetMapMode(CompatibleDC, 1);
  v47 = SelectObject(CompatibleDC, v7);
  v8 = SelectObject(CompatibleDC, h);
  LOBYTE(v9) = *(_BYTE *)(this + 153);
  v48 = v8;
  HIBYTE(v9) = *(_BYTE *)(this + 152);
  SetTextColor(CompatibleDC, *(unsigned __int8 *)(this + 154) | (v9 << 8));
  LOBYTE(v10) = *(_BYTE *)(this + 109);
  HIBYTE(v10) = *(_BYTE *)(this + 108);
  SetBkColor(CompatibleDC, *(unsigned __int8 *)(this + 110) | (v10 << 8));
  SetTextAlign(CompatibleDC, 0);
  v11 = operator new(0x60u);
  if ( v11 )
    v12 = sub_5A1D10(v11);
  else
    v12 = 0;
  v38 = v42;
  v37 = v41;
  *(_DWORD *)(this + 4280) = v12;
  if ( sub_5A1DC0((int)v12, aFonttex, v37, v38, 3, 4) )
    return -1;
  *(_DWORD *)(this + 180) = *(_DWORD *)(*(_DWORD *)(this + 4280) + 16);
  v14 = 32;
  x = 0;
  y = 0;
  strcpy(String, "x");
  ha = 32;
  v44 = 32;
  v15 = this + 184;
  do
  {
    String[0] = ha;
    if ( GetTextExtentPoint32A(CompatibleDC, String, 1, &psizl) )
    {
      v16 = *(_DWORD *)(this + 116);
      cx = psizl.cx;
      if ( v16 <= psizl.cx )
        v16 = psizl.cx;
      cy = psizl.cy;
      *(_DWORD *)(this + 116) = v16;
      v19 = *(_DWORD *)(this + 120);
      if ( v19 <= cy )
        v19 = cy;
      *(_DWORD *)(this + 120) = v19;
      if ( cx + x + 1 > v41 )
      {
        x = 0;
        y += cy + 1;
      }
      ExtTextOutA(CompatibleDC, x, y, 2u, 0, String, 1u, 0);
      v20 = x;
      v21 = y;
      *(_BYTE *)(v15 + 5) = psizl.cy;
      *(_WORD *)v15 = v20;
      *(_WORD *)(v15 + 2) = v21;
      if ( GetCharABCWidthsA(CompatibleDC, v14, v14, &ABC) )
      {
        abcC = ABC.abcC;
        abcB = ABC.abcB;
        abcA = ABC.abcA;
      }
      else
      {
        GetCharWidth32A(CompatibleDC, v14, v14, &Buffer);
        abcB = Buffer;
        abcA = 1;
        abcC = 1;
        ABC.abcA = 1;
        ABC.abcB = Buffer;
        ABC.abcC = 1;
      }
      v25 = x;
      *(_BYTE *)(v15 + 6) = abcA;
      *(_BYTE *)(v15 + 7) = abcC;
      if ( abcC >= 0 )
        v26 = abcA + abcB + abcC;
      else
        v26 = abcB + abcA;
      v27 = v25 + v26 + 1;
      v14 = v44;
      x = v27;
      if ( ABC.abcC >= 0 )
        LOBYTE(abcB) = LOBYTE(ABC.abcC) + abcB;
      *(_BYTE *)(v15 + 4) = abcA + abcB;
    }
    ++v14;
    v15 += 16;
    v28 = (unsigned __int8)++ha < 0x7Fu;
    v44 = v14;
  }
  while ( v28 );
  v29 = *(_DWORD **)(this + 180);
  *(_DWORD *)(this + 132) = v29[7] / *(_DWORD *)(this + 116);
  v30 = v29[8] / *(_DWORD *)(this + 120);
  *(_DWORD *)(this + 140) = 127;
  *(_DWORD *)(this + 136) = v30;
  v31 = sub_59FD80(v29, 0, 0);
  if ( v42 > 0 )
  {
    v32 = v41;
    v33 = 0;
    v44 = 0;
    y = v42;
    do
    {
      v34 = (_WORD *)v31;
      if ( v32 > 0 )
      {
        hb = (char *)v32;
        do
        {
          v35 = *((_BYTE *)ppvBits + v33) >> 4;
          if ( v35 )
          {
            *v34 = v35 | (unsigned __int16)(16 * (v35 | (unsigned __int16)(16 * (v35 | (unsigned __int16)(16 * v35)))));
            v32 = v41;
          }
          else
          {
            *v34 = *(_WORD *)(this + 108);
          }
          ++v34;
          v33 += 4;
          --hb;
        }
        while ( hb );
      }
      v31 += *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 4280) + 16) + 40);
      v33 = 4 * v32 + v44;
      v36 = y == 1;
      v44 = v33;
      --y;
    }
    while ( !v36 );
  }
  sub_59FDA0(*(void **)(this + 180), 0, 0);
  SelectObject(CompatibleDC, v47);
  SelectObject(CompatibleDC, v48);
  DeleteObject(ho);
  DeleteDC(CompatibleDC);
  return 0;
}
