int __thiscall sub_5D7280(char *this, int a2, float *a3)
{
  int result; // eax
  float *v4; // ecx
  int v5; // esi
  double v6; // st7

  result = a2 + 12;
  v4 = (float *)(this + 8);
  v5 = 4;
  do
  {
    v6 = *(float *)(result + 4);
    result += 16;
    v4 += 4;
    --v5;
    *(v4 - 5) = v6 * a3[13]
              + a3[9] * *(float *)(result - 16)
              + *(float *)(result - 20) * a3[5]
              + *(float *)(result - 24) * a3[1];
    *(v4 - 4) = *(float *)(result - 24) * a3[2]
              + *(float *)(result - 12) * a3[14]
              + *(float *)(result - 16) * a3[10]
              + *(float *)(result - 20) * a3[6];
    *(v4 - 3) = *(float *)(result - 24) * a3[3]
              + a3[15] * *(float *)(result - 12)
              + a3[7] * *(float *)(result - 20)
              + a3[11] * *(float *)(result - 16);
    *(v4 - 2) = *(float *)(result - 24) * a3[4]
              + *(float *)(result - 12) * a3[16]
              + *(float *)(result - 16) * a3[12]
              + *(float *)(result - 20) * a3[8];
  }
  while ( v5 );
  return result;
}
