int __thiscall sub_4F9480(void *this, int a2)
{
  char *v2; // eax
  char *v3; // edx
  char v4; // cl
  char *v5; // eax
  unsigned int v6; // ecx
  char v7; // al
  unsigned int v8; // ecx
  char v9; // al
  char v10; // dl
  char *v11; // edi
  int v12; // ecx
  int v13; // eax
  int v14; // eax
  unsigned int v15; // ecx
  char v16; // al
  unsigned int v17; // ecx
  char v18; // al
  __int16 v19; // dx
  char *v20; // edi
  int v21; // ecx
  char v22; // al
  int v23; // eax
  char v24; // cl
  int v25; // esi
  int v26; // eax
  char v27; // cl
  int v28; // eax
  int v29; // eax
  char v30; // cl
  int v31; // eax
  char v32; // cl
  int v33; // esi
  int v34; // eax
  char v35; // cl
  int v36; // eax
  double v37; // st7
  int v38; // eax
  double v39; // st7
  int v40; // esi
  int v41; // eax
  int v42; // eax
  int v44; // [esp-10h] [ebp-228h]
  int v45; // [esp-10h] [ebp-228h]
  int v46; // [esp-Ch] [ebp-224h]
  int v47; // [esp-Ch] [ebp-224h]
  int v48; // [esp-8h] [ebp-220h]
  int v49; // [esp-8h] [ebp-220h]
  int v50; // [esp-4h] [ebp-21Ch]
  int v51; // [esp-4h] [ebp-21Ch]
  float v52; // [esp+4h] [ebp-214h]
  float v53; // [esp+10h] [ebp-208h] BYREF
  int v54; // [esp+14h] [ebp-204h] BYREF
  char v55[256]; // [esp+18h] [ebp-200h] BYREF
  CHAR SrcStr[256]; // [esp+118h] [ebp-100h] BYREF

  if ( this )
  {
    v2 = (char *)dword_7CE5D0;
    if ( !dword_7CE5D0 )
      v2 = byte_5EA438;
    v3 = (char *)(v55 - v2);
    do
    {
      v4 = *v2;
      v2[(_DWORD)v3] = *v2;
      ++v2;
    }
    while ( v4 );
    v5 = &v55[strlen(v55)];
    if ( v5 > v55 )
    {
      while ( *v5 != 46 )
      {
        if ( --v5 <= v55 )
          goto LABEL_11;
      }
      *v5 = 0;
    }
LABEL_11:
    v6 = strlen(v55) + 1;
    v7 = v55[v6 - 1];
    v8 = v6 - 1;
    dword_8AFEBC = -999;
    if ( v7 != 92 )
    {
      do
        v9 = v55[--v8];
      while ( v9 != 92 );
    }
    v10 = byte_5D6E4C;
    v55[v8 + 5] = 0;
    v11 = &v55[strlen(v55) + 1];
    v12 = dword_5D6E48;
    *(_DWORD *)--v11 = dword_5D6E44;
    *((_DWORD *)v11 + 1) = v12;
    v11[8] = v10;
    if ( MemoryAllocation_cb20(&dword_8AFEB0, v55, 0, 1) && MemoryAllocation_cb20(&dword_8AFEB0, aDfLodBmp, 0, 1) )
    {
      dword_8AFEB0 = 0;
    }
    else if ( dword_8AFEB0 )
    {
      v46 = *(_DWORD *)(dword_8AFEB0 + 32);
      v44 = *(_DWORD *)(dword_8AFEB0 + 28);
      v13 = GlobalAccessor_5150();
      ClippedRenderRegion(0, 0, v13, 0, 0, v44, v46, -1, 0);
      GlobalAccessor_5150();
      RenderDrawOperationWithClipping(0, 0, 800, 102, 0);
      sub_495080();
      v47 = *(_DWORD *)(dword_8AFEB0 + 32);
      v45 = *(_DWORD *)(dword_8AFEB0 + 28);
      v14 = GlobalAccessor_5150();
      ClippedRenderRegion(0, 0, v14, 0, 0, v45, v47, -1, 0);
      GlobalAccessor_5150();
      RenderDrawOperationWithClipping(0, 0, 800, 102, 0);
    }
    v15 = strlen(v55) + 1;
    v16 = v55[v15 - 1];
    v17 = v15 - 1;
    if ( v16 != 92 )
    {
      do
        v18 = v55[--v17];
      while ( v18 != 92 );
    }
    v19 = word_5D6E34;
    v55[v17 + 5] = 0;
    v20 = &v55[strlen(v55) + 1];
    v21 = dword_5D6E30;
    *(_DWORD *)--v20 = dword_5D6E2C;
    v22 = byte_5D6E36;
    *((_DWORD *)v20 + 1) = v21;
    *((_WORD *)v20 + 4) = v19;
    v20[10] = v22;
    if ( MemoryAllocation_cb20(&dword_8AFEB4, v55, 0, 1) && MemoryAllocation_cb20(&dword_8AFEB4, aDfLod2Bmp, 0, 1) )
      dword_8AFEB4 = 0;
    if ( MemoryAllocation_cb20(&dword_8AFEB8, aLogoLodBmp, 0, 1) )
      dword_8AFEB8 = 0;
    if ( byte_7CF29C == 1 )
    {
      if ( dword_5EB10C )
        (*(void (__thiscall **)(int))(*(_DWORD *)dword_5EB10C + 12))(dword_5EB10C);
      BufferInitWith10fDefaults(flt_5EA618);
      PositionBasedMessageDisplay(1);
      TextOverlayDisplayTimer((int)flt_5EA618);
    }
    v54 = 0;
    v53 = 0.0;
    TrackNameReader((int)SrcStr, 255);
    sub_589901(SrcStr);
    if ( BinarySearchInStringTable(byte_5EC4C0, SrcStr, byte_5EC4CC) )
    {
      v23 = 0;
      do
      {
        v24 = SrcStr[v23];
        byte_5EC4CC[v23++] = v24;
      }
      while ( v24 );
    }
    ConditionalFontSurfaceCall(aFtim28wht, byte_5EC4CC, &v54, &v53);
    v25 = 780 - v54;
    if ( BinarySearchInStringTable(byte_5EC4C0, SrcStr, byte_5EC4CC) )
    {
      v26 = 0;
      do
      {
        v27 = SrcStr[v26];
        byte_5EC4CC[v26++] = v27;
      }
      while ( v27 );
    }
    v28 = GlobalAccessor_5150();
    sub_53D2E0(aFtim28wht, byte_5EC4CC, v25, 117, v28);
    v29 = 0;
    do
    {
      v30 = byte_5D6DF8[v29];
      SrcStr[v29++] = v30;
    }
    while ( v30 );
    if ( BinarySearchInStringTable(byte_5EC4C0, SrcStr, byte_5EC4CC) )
    {
      v31 = 0;
      do
      {
        v32 = SrcStr[v31];
        byte_5EC4CC[v31++] = v32;
      }
      while ( v32 );
    }
    ConditionalFontSurfaceCall(aFtim18wht, byte_5EC4CC, &v54, &v53);
    v33 = 780 - v54;
    if ( BinarySearchInStringTable(byte_5EC4C0, SrcStr, byte_5EC4CC) )
    {
      v34 = 0;
      do
      {
        v35 = SrcStr[v34];
        byte_5EC4CC[v34++] = v35;
      }
      while ( v35 );
    }
    v36 = GlobalAccessor_5150();
    sub_53D2E0(aFtim18wht, byte_5EC4CC, v33, 515, v36);
  }
  v37 = (double)dword_5C329C * 1.5 + 113.0;
  sub_5895A2(v37);
  if ( v37 > *(float *)&a2 )
  {
    sub_44F150(byte_7CA594, 0.0);
    if ( PackedFlagRead(byte_7CA594, 57) )
    {
      if ( dword_5EB10C )
        (*(void (__thiscall **)(int))(*(_DWORD *)dword_5EB10C + 12))(dword_5EB10C);
      BufferInitWith10fDefaults(flt_5EA618);
    }
    v53 = *(float *)&a2 * 800.0;
    v39 = (double)dword_5C329C * 1.5 + 113.0;
    sub_5895A2(v39);
    v40 = CRTFtol(v53 / v39);
    if ( v40 >= dword_8AFEBC + 3 )
    {
      dword_8AFEBC = v40;
      if ( dword_8AFEB0 )
      {
        v41 = GlobalAccessor_5150();
        ClippedRenderRegion(0, 0, v41, 0, 0, v40, 102, -1, 0);
        sub_4A1830();
      }
      GlobalAccessor_5150();
      RenderDrawOperationWithClipping(v40, 0, 800 - v40, 102, 0);
      if ( dword_8AFEB8 )
      {
        v51 = *(_DWORD *)(dword_8AFEB8 + 32);
        v49 = *(_DWORD *)(dword_8AFEB8 + 28);
        v42 = GlobalAccessor_5150();
        ClippedRenderRegion(0, 0, v42, 0, 0, v49, v51, 0, 0);
      }
      sub_495080();
    }
    ConditionalRatioCompute((int)&byte_8AC494, 1.0);
    v52 = sub_556730(0);
    SoundAudioPlayback(&byte_8AC494, v52);
  }
  else
  {
    if ( dword_8AFEB4 )
    {
      v50 = *(_DWORD *)(dword_8AFEB4 + 32);
      v48 = *(_DWORD *)(dword_8AFEB4 + 28);
      v38 = GlobalAccessor_5150();
      ClippedRenderRegion(0, 0, v38, 0, 0, v48, v50, -1, 0);
      sub_495080();
      sub_53CB90(dword_8AFEB4);
      dword_8AFEB4 = 0;
    }
    if ( dword_8AFEB0 )
    {
      sub_53CB90(dword_8AFEB0);
      dword_8AFEB0 = 0;
    }
    if ( dword_8AFEB8 )
    {
      sub_53CB90(dword_8AFEB8);
      dword_8AFEB8 = 0;
    }
    GlobalVTableDispatchByParam(0);
  }
  FieldSetterWithGuardedCall((_DWORD *)dword_7CD8C0, a2);
  return 0;
}
