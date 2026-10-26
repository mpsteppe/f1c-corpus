void __fastcall sub_42E040(int a1)
{
  double v1; // st7
  unsigned __int8 v3; // c0
  unsigned __int8 v4; // c2
  float v5; // [esp+0h] [ebp-4h] BYREF

  v5 = *(float *)&a1;
  if ( !dword_B6A3D8 || (dword_B698E8 & 1) == 0 )
  {
LABEL_13:
    byte_920484 = 0;
    return;
  }
  if ( (byte_B69A09 & 2) == 0 )
  {
    if ( (dword_B698E8 & 1) != 0 && (byte_B69A16 & 2) != 0 )
    {
      v5 = 1.0;
      sub_409B80(flt_B71144, &v5);
      return;
    }
    goto LABEL_13;
  }
  v1 = (double)dword_B6A33C;
  if ( byte_920484 )
  {
    *(float *)(a1 + 16) = v1;
    if ( v3 | v4 )
    {
      v5 = flt_B71158 - 0.0024999999;
      sub_409B80(flt_B71144, &v5);
    }
    else if ( v1 > *(float *)(a1 + 4) )
    {
      v5 = flt_B71158 + 0.0024999999;
      sub_409B80(flt_B71144, &v5);
    }
  }
  else
  {
    *(float *)(a1 + 4) = v1;
    byte_920484 = 1;
  }
}
