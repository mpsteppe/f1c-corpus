int __thiscall sub_4585E0(int this, int a2, int a3)
{
  int v4; // eax
  int v5; // ecx
  int v6; // edx
  double v7; // st7
  int v8; // ecx
  double v9; // st7
  double v10; // st7
  int v11; // eax
  int v12; // ecx
  double v13; // st7
  int v14; // edx
  double v15; // st7
  int v16; // eax
  double v17; // st7
  int v18; // ecx
  double v19; // st7
  double v20; // st7
  int v21; // eax
  double v22; // st7
  int v23; // eax
  double v24; // st7
  double v25; // st7
  float v26; // ecx
  char v28; // [esp+13h] [ebp-4FDh]
  float v29; // [esp+14h] [ebp-4FCh] BYREF
  float v30; // [esp+18h] [ebp-4F8h] BYREF
  float v31; // [esp+1Ch] [ebp-4F4h] BYREF
  int v32; // [esp+20h] [ebp-4F0h] BYREF
  int v33; // [esp+24h] [ebp-4ECh] BYREF
  int v34; // [esp+28h] [ebp-4E8h] BYREF
  float v35; // [esp+2Ch] [ebp-4E4h] BYREF
  int v36; // [esp+30h] [ebp-4E0h] BYREF
  int v37; // [esp+34h] [ebp-4DCh] BYREF
  float v38; // [esp+38h] [ebp-4D8h] BYREF
  int v39; // [esp+3Ch] [ebp-4D4h] BYREF
  float v40; // [esp+40h] [ebp-4D0h] BYREF
  int v41; // [esp+44h] [ebp-4CCh] BYREF
  float v42; // [esp+48h] [ebp-4C8h] BYREF
  float v43; // [esp+4Ch] [ebp-4C4h] BYREF
  float v44; // [esp+50h] [ebp-4C0h] BYREF
  int v45; // [esp+54h] [ebp-4BCh] BYREF
  int v46; // [esp+58h] [ebp-4B8h] BYREF
  int v47; // [esp+5Ch] [ebp-4B4h] BYREF
  float v48; // [esp+60h] [ebp-4B0h] BYREF
  float v49; // [esp+64h] [ebp-4ACh] BYREF
  int v50; // [esp+68h] [ebp-4A8h] BYREF
  int v51; // [esp+6Ch] [ebp-4A4h] BYREF
  int v52; // [esp+70h] [ebp-4A0h] BYREF
  int v53; // [esp+74h] [ebp-49Ch] BYREF
  _BYTE v54[384]; // [esp+78h] [ebp-498h] BYREF
  int v55; // [esp+1F8h] [ebp-318h]
  char v56; // [esp+1FCh] [ebp-314h]
  int v57; // [esp+204h] [ebp-30Ch]
  int v58; // [esp+208h] [ebp-308h]
  int v59; // [esp+20Ch] [ebp-304h]
  _BYTE v60[384]; // [esp+210h] [ebp-300h] BYREF
  char v61[384]; // [esp+390h] [ebp-180h] BYREF

  memset(v60, 0, sizeof(v60));
  v51 = 0;
  v52 = 0;
  v53 = 0;
  v32 = 0;
  v33 = 0;
  v34 = 0;
  v35 = 0.0;
  v40 = 0.0;
  v49 = 0.0;
  v38 = 0.0;
  v43 = 0.0;
  v48 = 0.0;
  v31 = 0.0;
  v30 = 0.0;
  v42 = 0.0;
  v45 = 0;
  v46 = 0;
  v47 = 0;
  v55 = 0;
  v59 = 0;
  v57 = 0;
  v58 = 0;
  v56 = 1;
  v28 = 1;
  v41 = 0;
  v39 = 0;
  v37 = 0;
  v36 = 0;
  v50 = 0;
  v44 = 1.0;
  v29 = 100.0;
  if ( !ConditionalDispatchBasedOnFlag(v60, 384) )
  {
LABEL_11:
    StringCopyWithBufferRealloc(a3);
    F_3VectorCopyToStruct((_DWORD *)this, &v51);
    VectorCopy((_DWORD *)this, &v32);
    v5 = v32;
    v6 = v33;
    *(float *)(this + 48) = v30;
    *(float *)(this + 52) = v31;
    v7 = v30;
    *(_DWORD *)(this + 144) = v5;
    v8 = v34;
    *(float *)(this + 56) = v7;
    v9 = v31;
    *(_DWORD *)(this + 148) = v6;
    *(float *)(this + 60) = v9;
    v10 = v48;
    *(_DWORD *)(this + 152) = v8;
    v11 = v50;
    v12 = v36;
    *(float *)(this + 64) = v10;
    v13 = v43;
    *(_BYTE *)(this + 96) = v28;
    v14 = v37;
    *(float *)(this + 68) = v13;
    v15 = v44;
    *(_DWORD *)(this + 100) = v11;
    v16 = v39;
    *(float *)(this + 72) = v15;
    v17 = v38;
    *(_DWORD *)(this + 104) = v12;
    v18 = v41;
    *(float *)(this + 76) = v17;
    v19 = v49;
    *(_DWORD *)(this + 108) = v14;
    *(float *)(this + 80) = v19;
    v20 = v40;
    *(_DWORD *)(this + 116) = v16;
    v21 = v45;
    *(float *)(this + 84) = v20;
    *(float *)(this + 88) = v35;
    v22 = v42;
    *(_DWORD *)(this + 124) = v21;
    v23 = v47;
    *(float *)(this + 92) = v22;
    v24 = v29;
    *(_DWORD *)(this + 120) = v18;
    v25 = v24 * v29;
    *(_DWORD *)(this + 128) = v46;
    v26 = v29;
    *(_DWORD *)(this + 132) = v23;
    *(float *)(this + 140) = v25;
    *(_DWORD *)(this + 112) = 2;
    *(float *)(this + 136) = v26;
    return 0;
  }
  while ( 1 )
  {
    v4 = sub_5651B0(v54);
    if ( v4 )
      break;
    sub_565870(aPosition, &v51, &v52, &v53, 0, 0, 0, 0, 0);
    sub_565870(aOrientation, &v32, &v33, &v34, 0, 0, 0, 0, 0);
    sub_565870(&off_5C57FC, &v30, &v31, 0, 0, 0, 0, 0, 0);
    sub_565760(aColor, &v50, &v36, &v37, 0);
    sub_565870(aClipplanes, &v48, &v43, 0, 0, 0, 0, 0, 0);
    sub_565870(aLodmultiplier, &v44, 0, 0, 0, 0, 0, 0, 0);
    sub_565870(aSize, &v38, &v49, 0, 0, 0, 0, 0, 0);
    sub_565870(aCenter, &v40, &v35, 0, 0, 0, 0, 0, 0);
    sub_565870(aMipmaplodbias, &v42, 0, 0, 0, 0, 0, 0, 0);
    sub_565760(aFlags1, &v39, 0, 0, 0);
    sub_565760(aFlags2, &v41, 0, 0, 0);
    if ( sub_565520(aClear, v61, 0) && !strcmp(v61, aFalse) )
      v28 = 0;
    sub_565870(aActivationloca, &v45, &v46, &v47, 0, 0, 0, 0, 0);
    sub_565870(aActivationradi, &v29, 0, 0, 0, 0, 0, 0, 0);
    sub_565870(aTrackingrate, this + 164, 0, 0, 0, 0, 0, 0, 0);
    sub_565870(aMovementrate, this + 168, 0, 0, 0, 0, 0, 0, 0);
    if ( !sub_588410(v60, aMovementpath_0) )
      sub_458050((void *)(this + 176), a2);
LABEL_10:
    if ( !ConditionalDispatchBasedOnFlag(v60, 384) )
      goto LABEL_11;
  }
  if ( v4 == 2 )
    goto LABEL_11;
  if ( v4 != 4 )
    goto LABEL_10;
  return 1;
}

