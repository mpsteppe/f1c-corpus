double __stdcall sub_64FB33(unsigned int a1)
{
  float v2; // [esp+10h] [ebp+8h]

  v2 = sub_5AF263(a1) * *(float *)&a1 * 254.0;
  return flt_736CD0[v2] + (flt_736CD4[v2] - flt_736CD0[v2]) * (v2 - (double)(unsigned int)(int)v2);
}
