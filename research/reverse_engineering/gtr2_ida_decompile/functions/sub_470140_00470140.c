int __thiscall sub_470140(int this, float *a2, float *a3)
{
  double v3; // st7
  double v4; // st5
  double v5; // rax
  float v7; // [esp+0h] [ebp-34h]
  double v8; // [esp+4h] [ebp-30h]
  double v9; // [esp+Ch] [ebp-28h]
  double v10; // [esp+14h] [ebp-20h]
  float v11; // [esp+38h] [ebp+4h]
  float v12; // [esp+3Ch] [ebp+8h]

  v3 = a2[2];
  v8 = a2[15] * v3 + *(double *)(this + 232);
  v9 = a2[16] * v3 + *(double *)(this + 240);
  v4 = a2[17] * v3 + *(double *)(this + 248);
  *(double *)(this + 232) = v8;
  v10 = v4;
  *(double *)(this + 240) = v9;
  v5 = v4;
  v11 = v8;
  *(_DWORD *)(this + 248) = LODWORD(v5);
  LODWORD(v5) = a3;
  *(_DWORD *)(this + 252) = HIDWORD(v10);
  *a3 = v11;
  v7 = v9;
  a3[1] = v7;
  v12 = v4;
  *(float *)(LODWORD(v5) + 8) = v12;
  return sub_5DB150(LODWORD(v11), LODWORD(v7), LODWORD(v12));
}
