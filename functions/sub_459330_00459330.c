int __thiscall sub_459330(int this, float a2)
{
  float v2; // edi
  char *v4; // eax
  float v5; // edx
  int v6; // ecx
  double v7; // st7
  float v9; // [esp+Ch] [ebp-8h] BYREF
  int v10; // [esp+10h] [ebp-4h] BYREF

  v2 = a2;
  v4 = NullSafePointerDereference((char **)(LODWORD(a2) + 4));
  StringCopyWithBufferRealloc(v4);
  F_3VectorCopyToStruct((_DWORD *)this, (_DWORD *)(LODWORD(v2) + 12));
  VectorCopy((_DWORD *)this, (_DWORD *)(LODWORD(v2) + 144));
  *(_DWORD *)(this + 144) = *(_DWORD *)(LODWORD(v2) + 144);
  *(_DWORD *)(this + 148) = *(_DWORD *)(LODWORD(v2) + 148);
  *(_DWORD *)(this + 152) = *(_DWORD *)(LODWORD(v2) + 152);
  DoubleFieldGetterAt0x300x34((_DWORD *)LODWORD(v2), &a2, &v9);
  *(float *)(this + 48) = a2;
  *(float *)(this + 52) = v9;
  DualFieldGetter((_DWORD *)LODWORD(v2), &a2, &v9);
  *(float *)(this + 56) = a2;
  *(float *)(this + 60) = v9;
  ShortComputation_6080((_DWORD *)LODWORD(v2), &a2, &v9);
  *(float *)(this + 64) = a2;
  *(float *)(this + 68) = v9;
  *(float *)(this + 72) = *(float *)(LODWORD(v2) + 72);
  DualFieldGetter_60a0((_DWORD *)LODWORD(v2), &a2, &v9);
  *(float *)(this + 76) = a2;
  *(float *)(this + 80) = v9;
  RectViewportDimensionGetter((_DWORD *)LODWORD(v2), &a2, &v9);
  *(float *)(this + 84) = a2;
  *(float *)(this + 88) = v9;
  *(float *)(this + 92) = *(float *)(LODWORD(v2) + 92);
  *(_BYTE *)(this + 96) = *(_BYTE *)(LODWORD(v2) + 96);
  MultiFieldGetter((_DWORD *)LODWORD(v2), &a2, &v9, &v10);
  v5 = a2;
  v6 = v10;
  *(float *)(this + 104) = v9;
  *(float *)(this + 100) = v5;
  *(_DWORD *)(this + 108) = v6;
  *(_DWORD *)(this + 112) = *(_DWORD *)(LODWORD(v2) + 112);
  *(_DWORD *)(this + 116) = *(_DWORD *)(LODWORD(v2) + 116);
  *(_DWORD *)(this + 120) = *(_DWORD *)(LODWORD(v2) + 120);
  *(_DWORD *)(this + 124) = *(_DWORD *)(LODWORD(v2) + 124);
  *(_DWORD *)(this + 128) = *(_DWORD *)(LODWORD(v2) + 128);
  *(_DWORD *)(this + 132) = *(_DWORD *)(LODWORD(v2) + 132);
  v7 = *(float *)(LODWORD(v2) + 136);
  *(float *)(this + 136) = *(float *)(LODWORD(v2) + 136);
  *(float *)(this + 140) = v7 * v7;
  *(float *)(this + 164) = *(float *)(LODWORD(v2) + 164);
  *(float *)(this + 168) = *(float *)(LODWORD(v2) + 168);
  BufferAllocCopy((int *)(this + 176), (_DWORD *)(LODWORD(v2) + 176));
  return this;
}
