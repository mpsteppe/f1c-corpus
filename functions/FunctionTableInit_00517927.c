float *(__stdcall **__cdecl FunctionTableInit(
        float *(__stdcall **a1)(float *a1, float *a2, float *a3)))(float *a1, float *a2, float *a3)
{
  float *(__stdcall **result)(float *, float *, float *); // eax

  result = a1;
  *a1 = Vec2AffineTransform;
  a1[1] = sub_517569;
  a1[2] = sub_517653;
  a1[3] = (float *(__stdcall *)(float *, float *, float *))F_44MatrixMultiply;
  a1[4] = (float *(__stdcall *)(float *, float *, float *))F_44MatrixMultiply_7899;
  a1[5] = Mat2x2Mul;
  a1[6] = sub_5175F4;
  a1[7] = (float *(__stdcall *)(float *, float *, float *))VectorNormalize;
  return result;
}
