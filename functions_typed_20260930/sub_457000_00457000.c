int __thiscall sub_457000(int this, float a2)
{
  float v2; // edi
  char *v4; // eax
  float v5; // edx
  int v6; // eax
  int result; // eax
  float v8; // [esp+8h] [ebp-8h] BYREF
  int v9; // [esp+Ch] [ebp-4h] BYREF

  v2 = a2;
  v4 = NullSafePointerDereference((char **)(LODWORD(a2) + 4));
  StringCopyWithBufferRealloc(v4);
  F_3VectorCopyToStruct((_DWORD *)this, (_DWORD *)(LODWORD(v2) + 12));
  VectorCopy((_DWORD *)this, (_DWORD *)(LODWORD(v2) + 24));
  DoubleFieldGetterAt0x300x34((_DWORD *)LODWORD(v2), &a2, &v8);
  *(float *)(this + 48) = a2;
  *(float *)(this + 52) = v8;
  DualFieldGetter((_DWORD *)LODWORD(v2), &a2, &v8);
  *(float *)(this + 56) = a2;
  *(float *)(this + 60) = v8;
  ShortComputation_6080((_DWORD *)LODWORD(v2), &a2, &v8);
  *(float *)(this + 64) = a2;
  *(float *)(this + 68) = v8;
  *(float *)(this + 72) = *(float *)(LODWORD(v2) + 72);
  DualFieldGetter_60a0((_DWORD *)LODWORD(v2), &a2, &v8);
  *(float *)(this + 76) = a2;
  *(float *)(this + 80) = v8;
  RectViewportDimensionGetter((_DWORD *)LODWORD(v2), &a2, &v8);
  *(float *)(this + 84) = a2;
  *(float *)(this + 88) = v8;
  *(float *)(this + 92) = *(float *)(LODWORD(v2) + 92);
  *(_BYTE *)(this + 96) = *(_BYTE *)(LODWORD(v2) + 96);
  MultiFieldGetter((_DWORD *)LODWORD(v2), &a2, &v8, &v9);
  v5 = v8;
  v6 = v9;
  *(float *)(this + 100) = a2;
  *(_DWORD *)(this + 108) = v6;
  *(float *)(this + 104) = v5;
  *(_DWORD *)(this + 112) = *(_DWORD *)(LODWORD(v2) + 112);
  *(_DWORD *)(this + 116) = *(_DWORD *)(LODWORD(v2) + 116);
  *(_DWORD *)(this + 120) = *(_DWORD *)(LODWORD(v2) + 120);
  *(_DWORD *)(this + 128) = *(_DWORD *)(LODWORD(v2) + 128);
  *(_DWORD *)(this + 132) = *(_DWORD *)(LODWORD(v2) + 132);
  *(_DWORD *)(this + 136) = *(_DWORD *)(LODWORD(v2) + 136);
  *(_DWORD *)(this + 140) = *(_DWORD *)(LODWORD(v2) + 140);
  *(_DWORD *)(this + 144) = *(_DWORD *)(LODWORD(v2) + 144);
  *(_DWORD *)(this + 148) = *(_DWORD *)(LODWORD(v2) + 148);
  *(_DWORD *)(this + 152) = *(_DWORD *)(LODWORD(v2) + 152);
  *(_DWORD *)(this + 156) = *(_DWORD *)(LODWORD(v2) + 156);
  *(_DWORD *)(this + 160) = *(_DWORD *)(LODWORD(v2) + 160);
  *(_DWORD *)(this + 164) = *(_DWORD *)(LODWORD(v2) + 164);
  *(_DWORD *)(this + 168) = *(_DWORD *)(LODWORD(v2) + 168);
  *(float *)(this + 172) = *(float *)(LODWORD(v2) + 172);
  *(_DWORD *)(this + 176) = *(_DWORD *)(LODWORD(v2) + 176);
  *(_DWORD *)(this + 180) = *(_DWORD *)(LODWORD(v2) + 180);
  *(_DWORD *)(this + 184) = *(_DWORD *)(LODWORD(v2) + 184);
  LODWORD(v2) += 188;
  *(_DWORD *)(this + 188) = *(_DWORD *)LODWORD(v2);
  *(_DWORD *)(this + 192) = *(_DWORD *)(LODWORD(v2) + 4);
  result = this;
  *(_DWORD *)(this + 196) = *(_DWORD *)(LODWORD(v2) + 8);
  return result;
}

