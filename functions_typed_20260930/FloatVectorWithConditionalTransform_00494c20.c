int __stdcall sub_494C20(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int result; // eax
  float v7[8]; // [esp+0h] [ebp-20h] BYREF

  v7[0] = (float)a1;
  v7[2] = 0.0;
  v7[5] = 0.0;
  v7[1] = (float)a2;
  v7[3] = (float)a3;
  v7[4] = (float)a4;
  result = F_2DLineRectClipping(a6, v7);
  if ( (_BYTE)result )
    return FloatToIntConversionChain(v7, a5);
  return result;
}

