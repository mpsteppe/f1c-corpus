int __thiscall sub_457670(_DWORD *this, int a2, signed int a3)
{
  signed int v3; // eax
  int v5; // edx
  int v6; // eax
  int v7; // edx
  int v8; // eax
  int v9; // ecx
  int v11; // [esp+24h] [ebp-14Ch] BYREF
  int v12; // [esp+28h] [ebp-148h] BYREF
  int v13; // [esp+2Ch] [ebp-144h] BYREF
  int v14; // [esp+30h] [ebp-140h] BYREF
  int v15; // [esp+34h] [ebp-13Ch] BYREF
  int v16; // [esp+38h] [ebp-138h] BYREF
  int v17; // [esp+3Ch] [ebp-134h] BYREF
  int v18; // [esp+40h] [ebp-130h] BYREF
  int v19; // [esp+44h] [ebp-12Ch] BYREF
  int v20; // [esp+48h] [ebp-128h] BYREF
  _DWORD v21[9]; // [esp+4Ch] [ebp-124h] BYREF
  _BYTE v22[256]; // [esp+70h] [ebp-100h] BYREF

  v3 = 0;
  v14 = 0;
  v16 = 0;
  v11 = 0;
  v12 = 0;
  v17 = 0;
  v21[0] = 0;
  v20 = 0;
  v13 = 0;
  v18 = 0;
  v15 = 0;
  v19 = 0;
  if ( a3 > 0 )
  {
    memset(v22, 0x20u, a3);
    v3 = a3;
  }
  v22[v3] = 0;
  v5 = this[4];
  v6 = this[5];
  v21[2] = this[3];
  v21[3] = v5;
  v7 = this[36];
  v21[4] = v6;
  v8 = this[37];
  v9 = this[38];
  v21[5] = v7;
  v21[6] = v8;
  v21[7] = v9;
  DualFieldGetter(this, &v13, &v20);
  MultiFieldGetter(this, &v19, &v15, &v18);
  ShortComputation_6080(this, v21, &v17);
  v21[1] = this[18];
  DualFieldGetter_60a0(this, &v12, &v11);
  RectViewportDimensionGetter(this, &v16, &v14);
  v21[8] = this[23];
  BufferWriteWithStringLengthCheck(a2, aSstaticcamS);
  BufferWriteWithStringLengthCheck(a2, aS_0);
  BufferWriteWithStringLengthCheck(a2, aSPositionFFF);
  BufferWriteWithStringLengthCheck(a2, aSOrientationFF);
  BufferWriteWithStringLengthCheck(a2, aSFovFF);
  BufferWriteWithStringLengthCheck(a2, aSClearS);
  BufferWriteWithStringLengthCheck(a2, aSColorDDD);
  BufferWriteWithStringLengthCheck(a2, aSClipplanesFF);
  BufferWriteWithStringLengthCheck(a2, aSLodmultiplier);
  BufferWriteWithStringLengthCheck(a2, aSSizeFF);
  BufferWriteWithStringLengthCheck(a2, aSCenterFF);
  BufferWriteWithStringLengthCheck(a2, aSMipmaplodbias);
  BufferWriteWithStringLengthCheck(a2, aSFlags1D);
  BufferWriteWithStringLengthCheck(a2, aSFlags2D);
  BufferWriteWithStringLengthCheck(a2, aSActivationloc);
  BufferWriteWithStringLengthCheck(a2, aSActivationrad);
  BufferWriteWithStringLengthCheck(a2, aS_1);
  return 0;
}
