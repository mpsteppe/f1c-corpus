int __thiscall sub_4562F0(int this, int a2, int a3)
{
  int v4; // eax
  int v5; // eax
  int v6; // ecx
  double v7; // st7
  int v8; // eax
  double v9; // st7
  int v10; // edx
  double v11; // st7
  int v12; // ecx
  double v13; // st7
  double v14; // st7
  double v15; // st7
  double v16; // st7
  char v18; // [esp+13h] [ebp-4D5h]
  float v19; // [esp+14h] [ebp-4D4h] BYREF
  float v20; // [esp+18h] [ebp-4D0h] BYREF
  float v21; // [esp+1Ch] [ebp-4CCh] BYREF
  float v22; // [esp+20h] [ebp-4C8h] BYREF
  int v23; // [esp+24h] [ebp-4C4h] BYREF
  float v24; // [esp+28h] [ebp-4C0h] BYREF
  int v25; // [esp+2Ch] [ebp-4BCh] BYREF
  float v26; // [esp+30h] [ebp-4B8h] BYREF
  int v27; // [esp+34h] [ebp-4B4h] BYREF
  float v28; // [esp+38h] [ebp-4B0h] BYREF
  int v29; // [esp+3Ch] [ebp-4ACh] BYREF
  float v30; // [esp+40h] [ebp-4A8h] BYREF
  int v31; // [esp+44h] [ebp-4A4h] BYREF
  float v32; // [esp+48h] [ebp-4A0h] BYREF
  float v33; // [esp+4Ch] [ebp-49Ch] BYREF
  _BYTE v34[384]; // [esp+50h] [ebp-498h] BYREF
  int v35; // [esp+1D0h] [ebp-318h]
  char v36; // [esp+1D4h] [ebp-314h]
  int v37; // [esp+1DCh] [ebp-30Ch]
  int v38; // [esp+1E0h] [ebp-308h]
  int v39; // [esp+1E4h] [ebp-304h]
  _BYTE v40[384]; // [esp+1E8h] [ebp-300h] BYREF
  char v41[384]; // [esp+368h] [ebp-180h] BYREF

  memset(v40, 0, sizeof(v40));
  v28 = 0.0;
  v21 = 0.0;
  v26 = 0.0;
  v30 = 0.0;
  v32 = 0.0;
  v33 = 0.0;
  v20 = 0.0;
  v19 = 0.0;
  v22 = 0.0;
  v35 = 0;
  v39 = 0;
  v37 = 0;
  v38 = 0;
  v36 = 1;
  v18 = 1;
  v31 = 0;
  v29 = 0;
  v27 = 0;
  v25 = 0;
  v23 = 0;
  v24 = 1.0;
  if ( !ConditionalDispatchBasedOnFlag(v40, 384) )
  {
LABEL_10:
    StringCopyWithBufferRealloc(a3);
    *(float *)(this + 48) = v19;
    *(float *)(this + 52) = v20;
    v5 = v23;
    v6 = v25;
    *(float *)(this + 56) = v19;
    v7 = v20;
    *(_DWORD *)(this + 100) = v5;
    v8 = v29;
    *(float *)(this + 60) = v7;
    *(float *)(this + 64) = v33;
    v9 = v32;
    *(_BYTE *)(this + 96) = v18;
    v10 = v27;
    *(float *)(this + 68) = v9;
    v11 = v24;
    *(_DWORD *)(this + 104) = v6;
    v12 = v31;
    *(float *)(this + 72) = v11;
    *(float *)(this + 76) = v30;
    v13 = v26;
    *(_DWORD *)(this + 112) = 0;
    *(float *)(this + 80) = v13;
    v14 = v21;
    *(_DWORD *)(this + 116) = v8;
    *(float *)(this + 84) = v14;
    v15 = v28;
    *(_DWORD *)(this + 108) = v10;
    *(float *)(this + 88) = v15;
    v16 = v22;
    *(_DWORD *)(this + 120) = v12;
    *(float *)(this + 92) = v16;
    return 0;
  }
  while ( 1 )
  {
    v4 = sub_5651B0(v34);
    if ( v4 )
      break;
    sub_565870(&off_5C57FC, &v19, &v20, 0, 0, 0, 0, 0, 0);
    sub_565760(aColor, &v23, &v25, &v27, 0);
    sub_565870(aClipplanes, &v33, &v32, 0, 0, 0, 0, 0, 0);
    sub_565870(aLodmultiplier, &v24, 0, 0, 0, 0, 0, 0, 0);
    sub_565870(aSize, &v30, &v26, 0, 0, 0, 0, 0, 0);
    sub_565870(aCenter, &v21, &v28, 0, 0, 0, 0, 0, 0);
    sub_565870(aMipmaplodbias, &v22, 0, 0, 0, 0, 0, 0, 0);
    sub_565760(aFlags1, &v29, 0, 0, 0);
    sub_565760(aFlags2, &v31, 0, 0, 0);
    if ( sub_565520(aClear, v41, 0) )
    {
      if ( !strcmp(v41, aFalse) )
        v18 = 0;
    }
    sub_565870(aRadiuslimits, this + 128, this + 132, 0, 0, 0, 0, 0, 0);
    sub_565870(aOrientationrat, this + 136, this + 140, this + 144, 0, 0, 0, 0, 0);
    sub_565870(aPositionoffset, this + 148, this + 152, this + 156, 0, 0, 0, 0, 0);
    sub_565870(aOrientationoff, this + 160, this + 164, this + 168, 0, 0, 0, 0, 0);
    sub_565870(aRadius_0, this + 172, 0, 0, 0, 0, 0, 0, 0);
LABEL_9:
    if ( !ConditionalDispatchBasedOnFlag(v40, 384) )
      goto LABEL_10;
  }
  if ( v4 == 2 )
    goto LABEL_10;
  if ( v4 != 4 )
    goto LABEL_9;
  return 1;
}
