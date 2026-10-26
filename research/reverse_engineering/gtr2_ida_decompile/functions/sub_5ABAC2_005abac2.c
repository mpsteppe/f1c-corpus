float *__stdcall sub_5ABAC2(float *a1, float a2, float *a3, float a4, float *a5)
{
  _BYTE v6[72]; // [esp+14h] [ebp-48h] BYREF

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
  a1[10] = 1.0;
  a1[15] = 1.0;
  if ( 0.0 != a4 )
  {
    sub_5AB05C((int)v6, a4);
    if ( a3 )
    {
      a1[12] = a1[12] - *a3;
      a1[13] = a1[13] - a3[1];
      sub_5AA514((int)a1, (int)a1, (int)v6);
      a1[12] = *a3 + a1[12];
      a1[13] = a1[13] + a3[1];
    }
    else
    {
      sub_5AA514((int)a1, (int)a1, (int)v6);
    }
  }
  if ( a5 )
  {
    a1[12] = *a5 + a1[12];
    a1[13] = a5[1] + a1[13];
  }
  return a1;
}
