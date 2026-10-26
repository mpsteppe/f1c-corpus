int __thiscall sub_457B60(int this, float a2)
{
  float v2; // edi
  char *v4; // eax
  float v5; // edx
  int v6; // ecx
  double v7; // st7
  int result; // eax
  float v9; // [esp+Ch] [ebp-8h] BYREF
  int v10; // [esp+10h] [ebp-4h] BYREF

  v2 = a2;
  v4 = sub_415C30((char **)(LODWORD(a2) + 4));
  sub_566650(v4);
  sub_456110((_DWORD *)this, (_DWORD *)(LODWORD(v2) + 12));
  sub_456130((_DWORD *)this, (_DWORD *)(LODWORD(v2) + 144));
  *(_DWORD *)(this + 144) = *(_DWORD *)(LODWORD(v2) + 144);
  *(_DWORD *)(this + 148) = *(_DWORD *)(LODWORD(v2) + 148);
  *(_DWORD *)(this + 152) = *(_DWORD *)(LODWORD(v2) + 152);
  sub_456040((_DWORD *)LODWORD(v2), &a2, &v9);
  *(float *)(this + 48) = a2;
  *(float *)(this + 52) = v9;
  sub_456060((_DWORD *)LODWORD(v2), &a2, &v9);
  *(float *)(this + 56) = a2;
  *(float *)(this + 60) = v9;
  sub_456080((_DWORD *)LODWORD(v2), &a2, &v9);
  *(float *)(this + 64) = a2;
  *(float *)(this + 68) = v9;
  *(float *)(this + 72) = *(float *)(LODWORD(v2) + 72);
  sub_4560A0((_DWORD *)LODWORD(v2), &a2, &v9);
  *(float *)(this + 76) = a2;
  *(float *)(this + 80) = v9;
  sub_4560C0((_DWORD *)LODWORD(v2), &a2, &v9);
  *(float *)(this + 84) = a2;
  *(float *)(this + 88) = v9;
  *(float *)(this + 92) = *(float *)(LODWORD(v2) + 92);
  *(_BYTE *)(this + 96) = *(_BYTE *)(LODWORD(v2) + 96);
  sub_4560E0((_DWORD *)LODWORD(v2), &a2, &v9, &v10);
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
  result = this;
  *(float *)(this + 140) = v7 * v7;
  return result;
}
