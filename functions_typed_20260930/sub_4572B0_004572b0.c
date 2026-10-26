int __thiscall sub_4572B0(int this, int a2, int a3)
{
  int v4; // eax
  int v5; // eax
  int v6; // ecx
  double v7; // st7
  int v8; // eax
  double v9; // st7
  double v10; // st7
  int v11; // edx
  int v12; // eax
  double v13; // st7
  int v14; // eax
  double v15; // st7
  int v16; // ecx
  double v17; // st7
  int v18; // edx
  double v19; // st7
  char v21; // [esp+13h] [ebp-4EDh]
  float v22; // [esp+14h] [ebp-4ECh] BYREF
  float v23; // [esp+18h] [ebp-4E8h] BYREF
  int v24; // [esp+1Ch] [ebp-4E4h] BYREF
  int v25; // [esp+20h] [ebp-4E0h] BYREF
  int v26; // [esp+24h] [ebp-4DCh] BYREF
  float v27; // [esp+28h] [ebp-4D8h] BYREF
  int v28; // [esp+2Ch] [ebp-4D4h] BYREF
  float v29; // [esp+30h] [ebp-4D0h] BYREF
  int v30; // [esp+34h] [ebp-4CCh] BYREF
  float v31; // [esp+38h] [ebp-4C8h] BYREF
  int v32; // [esp+3Ch] [ebp-4C4h] BYREF
  float v33; // [esp+40h] [ebp-4C0h] BYREF
  int v34; // [esp+44h] [ebp-4BCh] BYREF
  int v35; // [esp+48h] [ebp-4B8h] BYREF
  float v36; // [esp+4Ch] [ebp-4B4h] BYREF
  float v37; // [esp+50h] [ebp-4B0h] BYREF
  float v38; // [esp+54h] [ebp-4ACh] BYREF
  float v39; // [esp+58h] [ebp-4A8h] BYREF
  int v40; // [esp+5Ch] [ebp-4A4h] BYREF
  int v41; // [esp+60h] [ebp-4A0h] BYREF
  int v42; // [esp+64h] [ebp-49Ch] BYREF
  _BYTE v43[384]; // [esp+68h] [ebp-498h] BYREF
  int v44; // [esp+1E8h] [ebp-318h]
  char v45; // [esp+1ECh] [ebp-314h]
  int v46; // [esp+1F4h] [ebp-30Ch]
  int v47; // [esp+1F8h] [ebp-308h]
  int v48; // [esp+1FCh] [ebp-304h]
  _BYTE v49[384]; // [esp+200h] [ebp-300h] BYREF
  char v50[384]; // [esp+380h] [ebp-180h] BYREF

  memset(v49, 0, sizeof(v49));
  v40 = 0;
  v41 = 0;
  v42 = 0;
  v24 = 0;
  v25 = 0;
  v26 = 0;
  v27 = 0.0;
  v37 = 0.0;
  v31 = 0.0;
  v38 = 0.0;
  v36 = 0.0;
  v33 = 0.0;
  v23 = 0.0;
  v22 = 0.0;
  v39 = 0.0;
  v44 = 0;
  v48 = 0;
  v46 = 0;
  v47 = 0;
  v45 = 1;
  v21 = 1;
  v34 = 0;
  v32 = 0;
  v30 = 0;
  v28 = 0;
  v35 = 0;
  v29 = 1.0;
  if ( !ConditionalDispatchBasedOnFlag(v49, 384) )
  {
LABEL_10:
    StringCopyWithBufferRealloc(a3);
    F_3VectorCopyToStruct((_DWORD *)this, &v40);
    VectorCopy((_DWORD *)this, &v24);
    v5 = v24;
    *(float *)(this + 48) = v22;
    v6 = v25;
    *(float *)(this + 52) = v23;
    *(float *)(this + 56) = v22;
    v7 = v23;
    *(_DWORD *)(this + 144) = v5;
    v8 = v26;
    *(float *)(this + 60) = v7;
    v9 = v33;
    *(_DWORD *)(this + 148) = v6;
    *(float *)(this + 64) = v9;
    v10 = v36;
    *(_DWORD *)(this + 152) = v8;
    v11 = v35;
    v12 = v28;
    *(float *)(this + 68) = v10;
    v13 = v29;
    *(_DWORD *)(this + 104) = v12;
    v14 = v34;
    *(float *)(this + 72) = v13;
    *(float *)(this + 76) = v38;
    v15 = v31;
    *(_BYTE *)(this + 96) = v21;
    v16 = v30;
    *(float *)(this + 80) = v15;
    v17 = v37;
    *(_DWORD *)(this + 100) = v11;
    v18 = v32;
    *(float *)(this + 84) = v17;
    *(float *)(this + 88) = v27;
    v19 = v39;
    *(_DWORD *)(this + 120) = v14;
    *(float *)(this + 92) = v19;
    *(_DWORD *)(this + 108) = v16;
    *(_DWORD *)(this + 112) = 1;
    *(_DWORD *)(this + 116) = v18;
    return 0;
  }
  while ( 1 )
  {
    v4 = sub_5651B0(v43);
    if ( v4 )
      break;
    sub_565870(aPosition, &v40, &v41, &v42, 0, 0, 0, 0, 0);
    sub_565870(aOrientation, &v24, &v25, &v26, 0, 0, 0, 0, 0);
    sub_565870(&off_5C57FC, &v22, &v23, 0, 0, 0, 0, 0, 0);
    sub_565760(aColor, &v35, &v28, &v30, 0);
    sub_565870(aClipplanes, &v33, &v36, 0, 0, 0, 0, 0, 0);
    sub_565870(aLodmultiplier, &v29, 0, 0, 0, 0, 0, 0, 0);
    sub_565870(aSize, &v38, &v31, 0, 0, 0, 0, 0, 0);
    sub_565870(aCenter, &v37, &v27, 0, 0, 0, 0, 0, 0);
    sub_565870(aMipmaplodbias, &v39, 0, 0, 0, 0, 0, 0, 0);
    sub_565760(aFlags1, &v32, 0, 0, 0);
    sub_565760(aFlags2, &v34, 0, 0, 0);
    if ( sub_565520(aClear, v50, 0) )
    {
      if ( !strcmp(v50, aFalse) )
        v21 = 0;
    }
    sub_565870(aActivationloca, this + 124, this + 128, this + 132, 0, 0, 0, 0, 0);
    sub_565870(aActivationradi, this + 136, 0, 0, 0, 0, 0, 0, 0);
LABEL_9:
    if ( !ConditionalDispatchBasedOnFlag(v49, 384) )
      goto LABEL_10;
  }
  if ( v4 == 2 )
    goto LABEL_10;
  if ( v4 != 4 )
    goto LABEL_9;
  return 1;
}

