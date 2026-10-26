int __thiscall sub_456670(_DWORD *this, int a2, signed int a3)
{
  signed int v3; // eax
  int v6; // [esp+24h] [ebp-134h] BYREF
  int v7; // [esp+28h] [ebp-130h] BYREF
  int v8; // [esp+2Ch] [ebp-12Ch] BYREF
  int v9; // [esp+30h] [ebp-128h] BYREF
  int v10; // [esp+34h] [ebp-124h] BYREF
  int v11; // [esp+38h] [ebp-120h] BYREF
  int v12; // [esp+3Ch] [ebp-11Ch] BYREF
  int v13; // [esp+40h] [ebp-118h] BYREF
  int v14; // [esp+44h] [ebp-114h] BYREF
  int v15; // [esp+48h] [ebp-110h] BYREF
  _DWORD v16[3]; // [esp+4Ch] [ebp-10Ch] BYREF
  _BYTE v17[256]; // [esp+58h] [ebp-100h] BYREF

  v3 = 0;
  v11 = 0;
  v13 = 0;
  v7 = 0;
  v9 = 0;
  v12 = 0;
  v6 = 0;
  v15 = 0;
  v8 = 0;
  v14 = 0;
  v10 = 0;
  v16[0] = 0;
  if ( a3 > 0 )
  {
    memset(v17, 0x20u, a3);
    v3 = a3;
  }
  v17[v3] = 0;
  DualFieldGetter(this, &v8, &v15);
  MultiFieldGetter(this, v16, &v10, &v14);
  ShortComputation_6080(this, &v6, &v12);
  v16[1] = this[18];
  DualFieldGetter_60a0(this, &v9, &v7);
  RectViewportDimensionGetter(this, &v13, &v11);
  v16[2] = this[23];
  BufferWriteWithStringLengthCheck(a2, aSlocalcamS);
  BufferWriteWithStringLengthCheck(a2, aS_0);
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
  BufferWriteWithStringLengthCheck(a2, aSRadiuslimitsF);
  BufferWriteWithStringLengthCheck(a2, aSOrientationra);
  BufferWriteWithStringLengthCheck(a2, aSPositionoffse);
  BufferWriteWithStringLengthCheck(a2, aSOrientationof);
  BufferWriteWithStringLengthCheck(a2, aSRadiusF);
  BufferWriteWithStringLengthCheck(a2, aS_1);
  return 0;
}
