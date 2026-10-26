void __stdcall sub_409AD0(int a1)
{
  double v1; // st7
  float v2[3]; // [esp+8h] [ebp-Ch] BYREF
  float v3; // [esp+18h] [ebp+4h]

  if ( a1 && sub_459B90(a1) == 1 && !dword_768948 )
  {
    sub_459BD0(0, v2);
    if ( v2[0] >= -2.95 )
    {
      if ( v2[0] > -0.25 )
        v2[0] = -0.25;
    }
    else
    {
      v2[0] = -2.95;
    }
    sub_459CA0(0, v2, 0);
    v1 = sub_459C50(a1);
    v3 = v1;
    if ( v1 >= 4.5 )
    {
      if ( v3 > 5.75 )
        v3 = 5.75;
      sub_459D30(LODWORD(v3));
    }
    else
    {
      sub_459D30(1083179008);
    }
  }
}
