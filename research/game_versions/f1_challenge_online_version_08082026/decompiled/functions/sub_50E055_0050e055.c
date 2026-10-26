float *__stdcall sub_50E055(float *a1, float *a2)
{
  long double v3; // st7
  bool v4; // zf
  float *result; // eax
  double v6; // st7
  float v7; // [esp+Ch] [ebp-4h]
  float v8; // [esp+1Ch] [ebp+Ch]

  if ( a2[3] >= 1.0 )
  {
    result = a1;
    goto LABEL_5;
  }
  v3 = a2[3];
  sub_5894A0();
  v7 = sin(v3);
  v4 = !sub_50C042(v7, 0.0);
  result = a1;
  if ( !v4 )
  {
LABEL_5:
    *result = *a2;
    result[1] = a2[1];
    result[2] = a2[2];
    goto LABEL_6;
  }
  v8 = v3;
  v6 = v8 / v7;
  *a1 = v6 * *a2;
  a1[1] = v6 * a2[1];
  a1[2] = v6 * a2[2];
LABEL_6:
  result[3] = 0.0;
  return result;
}
