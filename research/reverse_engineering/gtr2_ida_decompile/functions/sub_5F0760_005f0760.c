int __thiscall sub_5F0760(int this, char *a2, int nNumber, LONG a4, int a5, int a6, unsigned int a7)
{
  char *v8; // eax
  char *v9; // eax
  int v10; // ecx
  HDC CompatibleDC; // edi
  unsigned __int64 v12; // rax
  char *v13; // eax
  char v14; // cl
  HFONT v15; // ebp
  int v17; // edx
  unsigned int v18; // ebx
  int v19; // edi
  int v20; // eax
  int v21; // eax
  int v22; // ebp
  int v23; // edi
  int *v24; // ebx
  char *v25; // eax
  char v26; // cl
  char *v27; // edi
  int v29; // edx
  int *v30; // edi
  int v31; // [esp-Ch] [ebp-26Ch]
  __int16 v32; // [esp+18h] [ebp-248h]
  __int16 v33; // [esp+18h] [ebp-248h]
  int v34; // [esp+1Ch] [ebp-244h] BYREF
  int v35; // [esp+20h] [ebp-240h] BYREF
  LOGFONTA lf; // [esp+24h] [ebp-23Ch] BYREF
  char Str[255]; // [esp+60h] [ebp-200h] BYREF
  char v38; // [esp+15Fh] [ebp-101h] BYREF
  char ArgList[256]; // [esp+160h] [ebp-100h] BYREF

  v8 = strrchr(a2, 92);
  if ( v8 )
    v9 = v8 + 1;
  else
    v9 = a2;
  v10 = 0;
  if ( *v9 != 46 )
  {
    do
    {
      *(_BYTE *)(this + v10 + 20) = v9[v10];
      ++v10;
    }
    while ( v10 < 63 && v9[v10] != 46 );
  }
  *(_BYTE *)(v10 + this + 20) = 0;
  _strupr((char *)(this + 20));
  strcpy(Str, a2);
  _strupr(Str);
  *(_DWORD *)(this + 180) = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)dword_FB27A4 + 632))(
                              dword_FB27A4,
                              "L0SCREENT0",
                              0);
  if ( strstr(Str, ".BMP") || strstr(Str, ".TGA") )
  {
    v18 = a7;
    v32 = 4096;
    if ( (a7 & 0x10) != 0 )
      v32 = 4608;
    if ( (a7 & 0x20) != 0 )
      v33 = v32 | 2;
    else
      v33 = 1;
    v19 = *(_DWORD *)dword_FB27A4;
    v20 = (*(int (__thiscall **)(int))(*(_DWORD *)dword_FB27A4 + 192))(dword_FB27A4);
    v21 = (*(int (__thiscall **)(int, int))(v19 + 196))(dword_FB27A4, v20);
    if ( v21 && (*(int *)(v21 + 288) <= 256 || *(int *)(v21 + 292) <= 256) )
    {
      v18 = a7 & 0xFFFFFFFE;
      LOBYTE(a7) = a7 & 0xFE;
    }
    if ( (v18 & 1) != 0 )
      v22 = 8;
    else
      v22 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_FB27A4 + 292))(dword_FB27A4, 1);
    v23 = v18 | *(_DWORD *)(this + 16);
    v24 = (int *)(this + 172);
    *(_DWORD *)(this + 16) = v23;
    if ( sub_5E7E80(this, this + 172, v22, (int **)(this + 172), Str, v22, v33) || sub_5F0670((_DWORD *)this) )
      return -1;
    if ( (*(_BYTE *)(this + 16) & 1) != 0 )
    {
      v34 = *(_DWORD *)(*v24 + 4);
      (*(void (__thiscall **)(int, int *))(*(_DWORD *)dword_FB27A4 + 280))(dword_FB27A4, &v34);
      v35 = *(_DWORD *)(*v24 + 8);
      (*(void (__thiscall **)(int, int *))(*(_DWORD *)dword_FB27A4 + 280))(dword_FB27A4, &v35);
      v25 = (char *)(this + 20);
      do
      {
        v26 = *v25;
        ArgList[(_DWORD)v25 - 20 - this] = *v25;
        ++v25;
      }
      while ( v26 );
      v27 = &v38;
      while ( *++v27 )
        ;
      v29 = v34;
      v31 = v35;
      *(_DWORD *)v27 = 5784916;
      v30 = (int *)(this + 176);
      if ( sub_5E47E0((void *)this, (_DWORD *)(this + 176), ArgList, v29, v31, v22, 1, 4, 0) )
        return -1;
      sub_5E7540(
        (_DWORD *)*v24,
        0,
        0,
        (_DWORD *)*v30,
        0,
        0,
        *(_DWORD *)(*v24 + 4),
        *(_DWORD *)(*v24 + 8),
        *(_DWORD *)(this + 92),
        0,
        0);
      sub_5E7F70((void *)this, *v24);
      *v24 = *v30;
      if ( (v33 & 0x200) == 0 )
        *(_DWORD *)(this + 140) &= ~0x80u;
      *(_DWORD *)(this + 84) = a5;
      *(_DWORD *)(this + 136) = *(_BYTE *)(this + 87) != 0 ? 0x20 : 0;
      return 0;
    }
    else
    {
      if ( (a7 & 0x10) == 0 )
        *(_DWORD *)(this + 92) = -1;
      return 0;
    }
  }
  else
  {
    CompatibleDC = CreateCompatibleDC(0);
    SetMapMode(CompatibleDC, 1);
    SetMapperFlags(CompatibleDC, 1u);
    v12 = (unsigned __int64)((double)GetDeviceCaps(CompatibleDC, 90) * *(float *)(this + 156));
    lf.lfHeight = -MulDiv(nNumber, v12, 72);
    lf.lfWeight = a4;
    lf.lfStrikeOut = (a7 & 0x400) != 0;
    memset(&lf.lfWidth, 0, 12);
    lf.lfItalic = BYTE1(a7) & 1;
    lf.lfOutPrecision = 4;
    lf.lfQuality = 4;
    lf.lfUnderline = (a7 & 0x200) != 0;
    lf.lfCharSet = 1;
    lf.lfClipPrecision = 0;
    lf.lfPitchAndFamily = 0;
    v13 = (char *)(this + 20);
    do
    {
      v14 = *v13;
      *((_BYTE *)&lf.lfEscapement + (_DWORD)v13 - this) = *v13;
      ++v13;
    }
    while ( v14 );
    v15 = CreateFontIndirectA(&lf);
    DeleteDC(CompatibleDC);
    if ( !v15 )
    {
      sub_5D8C80(this, (char *)0xFFFFFFFF, "Win32 error creating font %s", this + 20);
      return -1;
    }
    v17 = a7 | *(_DWORD *)(this + 16);
    *(_DWORD *)(this + 16) = v17;
    *(_DWORD *)(this + 16) = v17 | 3;
    *(_DWORD *)(this + 128) = nNumber;
    *(_DWORD *)(this + 84) = a5;
    *(_DWORD *)(this + 92) = a6;
    if ( (a7 & 0x40000) != 0 )
      sub_5EEC00((_DWORD *)this, v15, a2, 0);
    else
      sub_5EF3E0(this, v15);
    DeleteObject(v15);
    if ( (a7 & 0x10) != 0 && *(_BYTE *)(this + 87) )
      *(_DWORD *)(this + 136) |= 0x20u;
    if ( (a7 & 8) != 0 )
      *(_DWORD *)(this + 140) |= 0x40u;
    if ( (a7 & 0x10) != 0 )
      *(_DWORD *)(this + 140) |= 0x80u;
    if ( (a7 & 0x1000) != 0 )
    {
      *(_DWORD *)(this + 148) = 191;
    }
    else if ( (a7 & 0x2000) != 0 )
    {
      *(_DWORD *)(this + 148) = 127;
    }
    *(_DWORD *)(this + 148) = (a7 & 0x4000) != 0 ? 63 : 1;
    return 0;
  }
}
