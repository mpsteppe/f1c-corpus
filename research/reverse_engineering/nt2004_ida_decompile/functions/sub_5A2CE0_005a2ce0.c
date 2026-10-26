int __thiscall sub_5A2CE0(int this, char *Str, int nNumber, LONG a4, int a5, int a6, unsigned int a7)
{
  char *v8; // eax
  char *v9; // eax
  char v10; // dl
  int i; // ecx
  unsigned int v12; // ebx
  int v13; // ebp
  int v14; // ebp
  int v15; // eax
  int v16; // eax
  void **v17; // ebx
  int v19; // eax
  _DWORD *v20; // ebp
  int v21; // edx
  int v22; // eax
  int v23; // ecx
  int v24; // eax
  int v25; // edi
  int v26; // ecx
  _DWORD *v27; // eax
  _DWORD *v28; // eax
  int *v29; // edi
  int v30; // eax
  HDC CompatibleDC; // edi
  CHAR *v32; // eax
  CHAR v33; // dl
  HFONT v34; // ebp
  int v35; // [esp-10h] [ebp-164h]
  int v36; // [esp-8h] [ebp-15Ch]
  int DeviceCaps; // [esp+10h] [ebp-144h]
  int v38; // [esp+14h] [ebp-140h]
  LOGFONTA lf; // [esp+18h] [ebp-13Ch] BYREF
  char String[256]; // [esp+54h] [ebp-100h] BYREF

  v8 = strrchr(Str, 92);
  if ( v8 )
    v9 = v8 + 1;
  else
    v9 = Str;
  v10 = *v9;
  for ( i = 0; v10 != 46; ++i )
  {
    *(_BYTE *)(this + i + 36) = v10;
    v10 = v9[i + 1];
  }
  *(_BYTE *)(i + this + 36) = 0;
  if ( strstr(Str, aTtf) || strstr(Str, aTtf_0) )
  {
    v29 = (int *)operator new(8u);
    if ( v29 )
    {
      v30 = sub_5A4720(&unk_7E6B48);
      v29[1] = 0;
      *v29 = v30;
    }
    else
    {
      v29 = 0;
    }
    *(_DWORD *)(this + 24) = v29;
    CompatibleDC = CreateCompatibleDC(0);
    SetMapMode(CompatibleDC, 1);
    DeviceCaps = GetDeviceCaps(CompatibleDC, 90);
    lf.lfHeight = -MulDiv(nNumber, (__int64)((double)DeviceCaps * *(float *)(this + 176)), 72);
    lf.lfWeight = a4;
    memset(&lf.lfWidth, 0, 12);
    lf.lfItalic = (a7 & 0x40) != 0;
    lf.lfStrikeOut = BYTE1(a7) & 1;
    v32 = (CHAR *)(this + 36);
    lf.lfUnderline = (a7 & 0x80) != 0;
    lf.lfCharSet = 0;
    lf.lfOutPrecision = 0;
    lf.lfClipPrecision = 0;
    lf.lfQuality = 0;
    lf.lfPitchAndFamily = 2;
    do
    {
      v33 = *v32;
      lf.lfFaceName[(_DWORD)v32 - 36 - this] = *v32;
      ++v32;
    }
    while ( v33 );
    v34 = CreateFontIndirectA(&lf);
    if ( v34 )
    {
      DeleteDC(CompatibleDC);
      *(_DWORD *)(this + 108) = a6;
      *(_DWORD *)(this + 100) = 1179648;
      *(_DWORD *)(this + 152) = a5;
      *(_DWORD *)(this + 144) = nNumber;
      sub_5A36B0(v34);
      DeleteObject(v34);
      if ( *(_BYTE *)(this + 155) )
        *(_DWORD *)(this + 156) |= 0x20u;
      if ( (a7 & 0x10) != 0 )
        *(_DWORD *)(this + 160) |= 0x40u;
      if ( (a7 & 0x20) != 0 )
        *(_DWORD *)(this + 160) |= 0x80u;
      if ( (a7 & 0x200) != 0 )
      {
        *(_DWORD *)(this + 168) = 4;
      }
      else if ( (a7 & 0x400) != 0 )
      {
        *(_DWORD *)(this + 168) = 8;
      }
      if ( (a7 & 0x800) != 0 )
        *(_DWORD *)(this + 168) = 10;
      else
        *(_DWORD *)(this + 168) = 0;
      return -(sub_5A3200(this) != 0);
    }
    else
    {
      sub_5BE8AE();
      return -1;
    }
  }
  else
  {
    v12 = a7;
    v13 = 0x8000;
    if ( (a7 & 0x800) != 0 )
      v13 = 34816;
    if ( (a7 & 2) != 0 )
      v14 = v13 | 2;
    else
      v14 = 1;
    v15 = sub_5A4740(&unk_7E6B48);
    v16 = sub_5A4750(v15);
    if ( v16 && (*(int *)(v16 + 284) <= 256 || *(int *)(v16 + 288) <= 256) )
      v12 = a7 & 0xFFFCFFFF | 0x10000;
    if ( (v12 & 0x20000) != 0 )
      v38 = dword_7E8CF0 != 16 ? 8 : 5;
    else
      v38 = 0;
    *(_DWORD *)(this + 100) = v12;
    strcpy(String, Str);
    _strupr(String);
    v17 = (void **)(this + 180);
    if ( sub_5922A0((void **)(this + 180), (int)String, v38, v14) )
      return -1;
    if ( sub_5A3EA0(String) )
      return -1;
    v19 = *(_DWORD *)(this + 100);
    if ( (v19 & 0x20000) != 0 )
    {
      if ( sub_5A3200(this) )
        return -1;
      v20 = *v17;
      v21 = *((_DWORD *)*v17 + 7);
      v22 = 1;
      v23 = 0;
      if ( v21 > 1 )
      {
        do
          v22 = 1 << ++v23;
        while ( v21 > 1 << v23 );
      }
      DeviceCaps = v22;
      v24 = v20[8];
      v25 = 1;
      v26 = 0;
      if ( v24 > 1 )
      {
        do
          v25 = 1 << ++v26;
        while ( v24 > 1 << v26 );
      }
      v27 = operator new(0x60u);
      if ( v27 )
        v28 = sub_5A1D10(v27);
      else
        v28 = 0;
      v36 = v38;
      v35 = DeviceCaps;
      *(_DWORD *)(this + 4280) = v28;
      if ( sub_5A1DC0((int)v28, aFonttex, v35, v25, v36, 4) )
        return -1;
      sub_59FDC0(
        *v17,
        0,
        0,
        *(_DWORD *)(*(_DWORD *)(this + 4280) + 16),
        0,
        0,
        *((_DWORD *)*v17 + 7),
        *((_DWORD *)*v17 + 8),
        *(_DWORD *)(this + 108),
        0);
      sub_59FA90(*v17);
      if ( *v17 )
      {
        j_nullsub_6(*v17);
        sub_5BE8AE();
      }
      *v17 = *(void **)(*(_DWORD *)(this + 4280) + 16);
      if ( (a7 & 0x800) == 0 )
      {
        *(_DWORD *)(this + 160) &= ~0x80u;
        return 0;
      }
    }
    else if ( (v19 & 0x10000) != 0 && (a7 & 0x800) == 0 )
    {
      *(_DWORD *)(this + 108) = -1;
    }
    return 0;
  }
}
