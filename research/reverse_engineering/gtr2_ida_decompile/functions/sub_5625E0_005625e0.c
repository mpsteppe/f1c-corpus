int __thiscall sub_5625E0(int this)
{
  const char *v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // ecx
  int v6; // eax
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // eax
  int v17; // ecx
  int v18; // eax
  int v19; // eax
  int v20; // ecx
  int v21; // eax
  int v22; // eax
  int v23; // ecx
  int v24; // ebp
  int v25; // eax
  int v26; // eax
  int v27; // ecx
  void *Block; // [esp+Ch] [ebp-A4h] BYREF
  char v30[32]; // [esp+10h] [ebp-A0h] BYREF
  char Buffer[128]; // [esp+30h] [ebp-80h] BYREF

  if ( dword_FAE920 )
    sub_561D00();
  v2 = *(const char **)dword_91CAB0;
  Block = 0;
  if ( !*(_DWORD *)dword_91CAB0 )
    v2 = WindowName;
  sprintf(Buffer, "%s%s", v2, off_903B80[0]);
  sub_5EE940((int)&Block, (char)Buffer, 0);
  if ( !Block )
    return 1;
  sprintf(v30, "%s%s", off_903B6C[0], off_903B7C[0]);
  sub_5F0D70(dword_FB1CE0, v30, 17, &dword_FAE920);
  v3 = dword_FAE920;
  if ( dword_FAE920 )
  {
    *(_DWORD *)(dword_FAE920 + 136) = 0;
    *(_DWORD *)(v3 + 140) = 192;
    v4 = dword_FAE920;
    v5 = *(_DWORD *)(this + 256);
    *(float *)(dword_FAE920 + 156) = *(float *)(this + 260);
    *(_DWORD *)(v4 + 152) = v5;
  }
  sprintf(v30, "%s%s", off_903B70[0], off_903B7C[0]);
  sub_5F0D70(dword_FB1CE0, v30, 17, &dword_FAE924);
  v6 = dword_FAE924;
  if ( dword_FAE924 )
  {
    *(_DWORD *)(dword_FAE924 + 136) = 0;
    *(_DWORD *)(v6 + 140) = 192;
    v7 = dword_FAE924;
    v8 = *(_DWORD *)(this + 256);
    *(float *)(dword_FAE924 + 156) = *(float *)(this + 260);
    *(_DWORD *)(v7 + 152) = v8;
  }
  sprintf(v30, "%s%s", off_903B74[0], off_903B7C[0]);
  sub_5F0D70(dword_FB1CE0, v30, 17, &dword_FAE928);
  v9 = dword_FAE928;
  if ( dword_FAE928 )
  {
    *(_DWORD *)(dword_FAE928 + 136) = 0;
    *(_DWORD *)(v9 + 140) = 192;
    v10 = dword_FAE928;
    v11 = *(_DWORD *)(this + 256);
    *(float *)(dword_FAE928 + 156) = *(float *)(this + 260);
    *(_DWORD *)(v10 + 152) = v11;
  }
  sprintf(v30, "%s%s", off_903B84[0], off_903B94);
  sub_5F0D70(dword_FB1CE0, v30, 17, &dword_FAE978);
  v12 = dword_FAE978;
  if ( dword_FAE978 )
  {
    *(_DWORD *)(dword_FAE978 + 136) = 0;
    *(_DWORD *)(v12 + 140) = 192;
    v13 = dword_FAE978;
    v14 = *(_DWORD *)(this + 256);
    *(float *)(dword_FAE978 + 156) = *(float *)(this + 260);
    *(_DWORD *)(v13 + 152) = v14;
  }
  sprintf(v30, "%s%s", off_903B88[0], off_903B94);
  sub_5F0D70(dword_FB1CE0, v30, 17, &dword_FAE97C);
  v15 = dword_FAE97C;
  if ( dword_FAE97C )
  {
    *(_DWORD *)(dword_FAE97C + 136) = 0;
    *(_DWORD *)(v15 + 140) = 192;
    v16 = dword_FAE97C;
    v17 = *(_DWORD *)(this + 256);
    *(float *)(dword_FAE97C + 156) = *(float *)(this + 260);
    *(_DWORD *)(v16 + 152) = v17;
  }
  sprintf(v30, "%s%s", off_903B8C[0], off_903B7C[0]);
  sub_5F0D70(dword_FB1CE0, v30, 17, &dword_FAE980);
  v18 = dword_FAE980;
  if ( dword_FAE980 )
  {
    *(_DWORD *)(dword_FAE980 + 136) = 0;
    *(_DWORD *)(v18 + 140) = 192;
    v19 = dword_FAE980;
    v20 = *(_DWORD *)(this + 256);
    *(float *)(dword_FAE980 + 156) = *(float *)(this + 260);
    *(_DWORD *)(v19 + 152) = v20;
  }
  sprintf(v30, "%s%s", off_903B90[0], off_903B94);
  sub_5F0D70(dword_FB1CE0, v30, 17, &dword_FAE984);
  v21 = dword_FAE984;
  if ( dword_FAE984 )
  {
    *(_DWORD *)(dword_FAE984 + 136) = 0;
    *(_DWORD *)(v21 + 140) = 192;
    v22 = dword_FAE984;
    v23 = *(_DWORD *)(this + 256);
    *(float *)(dword_FAE984 + 156) = *(float *)(this + 260);
    *(_DWORD *)(v22 + 152) = v23;
  }
  sprintf(v30, "%s%s", off_903B78[0], off_903B7C[0]);
  v24 = sub_5F0D70(dword_FB1CE0, v30, 17, &dword_FAE92C);
  v25 = dword_FAE92C;
  if ( dword_FAE92C )
  {
    *(_DWORD *)(dword_FAE92C + 136) = 0;
    *(_DWORD *)(v25 + 140) = 192;
    v26 = dword_FAE92C;
    v27 = *(_DWORD *)(this + 256);
    *(float *)(dword_FAE92C + 156) = *(float *)(this + 260);
    *(_DWORD *)(v26 + 152) = v27;
  }
  sub_5EEA30(dword_FB1CE0, Block, 0);
  return v24;
}
