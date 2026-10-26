int __stdcall sub_5D7870(int a1, float *a2, int a3)
{
  int v3; // esi
  int result; // eax
  int v5; // edx
  double v6; // st7

  result = a1 + 8;
  v5 = a3 + 8;
  v3 = dword_16C9A4C;
  do
  {
    v6 = *(float *)(result - 8);
    result += 16;
    v5 += 16;
    --v3;
    *(float *)(v5 - 24) = v6 * *a2
                        + a2[12] * *(float *)(result - 12)
                        + a2[4] * *(float *)(result - 20)
                        + a2[8] * *(float *)(result - 16);
    *(float *)(v5 - 20) = *(float *)(result - 12) * a2[13]
                        + a2[9] * *(float *)(result - 16)
                        + *(float *)(result - 20) * a2[5]
                        + *(float *)(result - 24) * a2[1];
    *(float *)(v5 - 16) = *(float *)(result - 12) * a2[14]
                        + a2[10] * *(float *)(result - 16)
                        + *(float *)(result - 20) * a2[6]
                        + a2[2] * *(float *)(result - 24);
    *(float *)(v5 - 12) = *(float *)(result - 12) * a2[15]
                        + *(float *)(result - 20) * a2[7]
                        + a2[11] * *(float *)(result - 16)
                        + *(float *)(result - 24) * a2[3];
  }
  while ( v3 );
  return result;
}
