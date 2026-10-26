float *__stdcall sub_50D9A5(float *a1, float a2, float *a3, int a4, float *a5)
{
  a1[14] = 0.0;
  a1[13] = 0.0;
  a1[12] = 0.0;
  a1[11] = 0.0;
  a1[9] = 0.0;
  a1[8] = 0.0;
  a1[7] = 0.0;
  a1[6] = 0.0;
  a1[4] = 0.0;
  a1[3] = 0.0;
  a1[2] = 0.0;
  a1[1] = 0.0;
  *a1 = a2;
  a1[5] = a2;
  a1[10] = a2;
  a1[15] = 1.0;
  if ( a4 )
  {
    ThunkToIndirectCallViaDAT005d7860();
    if ( a3 )
    {
      a1[12] = a1[12] - *a3;
      a1[13] = a1[13] - a3[1];
      a1[14] = a1[14] - a3[2];
      ThunkToFUN0050cba3();
      a1[12] = *a3 + a1[12];
      a1[13] = a1[13] + a3[1];
      a1[14] = a3[2] + a1[14];
    }
    else
    {
      ThunkToFUN0050cba3();
    }
  }
  if ( a5 )
  {
    a1[12] = *a5 + a1[12];
    a1[13] = a5[1] + a1[13];
    a1[14] = a5[2] + a1[14];
  }
  return a1;
}
