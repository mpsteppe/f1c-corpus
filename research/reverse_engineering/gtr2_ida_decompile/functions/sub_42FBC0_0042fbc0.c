void *__thiscall sub_42FBC0(char *this, void *a2, float *a3)
{
  float *v3; // esi
  _BYTE *v4; // edi
  float *v5; // eax
  _BYTE *v6; // ebx
  int v7; // ecx
  double v8; // st7
  void *result; // eax
  _BYTE v10[64]; // [esp+Ch] [ebp-40h] BYREF

  v3 = (float *)&v10[4];
  v4 = (_BYTE *)(v10 - this);
  v5 = (float *)(this + 8);
  v6 = (_BYTE *)(&v10[4] - this);
  v7 = 4;
  do
  {
    v8 = *(v5 - 2);
    v5 += 4;
    v3 += 4;
    --v7;
    *(v3 - 5) = v8 * *a3 + a3[8] * *(v5 - 4) + a3[4] * *(v5 - 5) + *(v5 - 3) * a3[12];
    *(v3 - 4) = a3[9] * *(v5 - 4) + a3[5] * *(v5 - 5) + *(v5 - 6) * a3[1] + a3[13] * *(v5 - 3);
    *(float *)((char *)v5 + (_DWORD)v4 - 16) = a3[2] * *(v5 - 6)
                                             + a3[10] * *(v5 - 4)
                                             + a3[14] * *(v5 - 3)
                                             + *(v5 - 5) * a3[6];
    *(float *)((char *)v5 + (_DWORD)v6 - 16) = *(v5 - 5) * a3[7]
                                             + *(v5 - 3) * a3[15]
                                             + *(v5 - 4) * a3[11]
                                             + a3[3] * *(v5 - 6);
  }
  while ( v7 );
  result = a2;
  qmemcpy(a2, v10, 0x40u);
  return result;
}
