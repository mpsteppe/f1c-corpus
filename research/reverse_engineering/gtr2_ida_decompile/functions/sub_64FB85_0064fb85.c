double __stdcall sub_64FB85(float a1)
{
  float v2; // [esp+Ch] [ebp+8h]

  v2 = a1 * a1 * 254.0;
  return flt_7370D0[v2] + (flt_7370D4[v2] - flt_7370D0[v2]) * (v2 - (double)(unsigned int)(int)v2);
}
