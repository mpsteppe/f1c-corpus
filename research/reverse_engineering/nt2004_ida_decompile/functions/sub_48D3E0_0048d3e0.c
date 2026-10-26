int __thiscall sub_48D3E0(int this)
{
  float *v1; // edx
  double v2; // st7
  float v4; // [esp+0h] [ebp-4h]

  *(_BYTE *)(this + 304) = 0;
  v1 = (float *)&unk_76A220;
  do
  {
    v2 = v1[2];
    *v1 = *(float *)(this + 308);
    v4 = v1[3];
    if ( v2 <= *v1 )
    {
      if ( *v1 > (double)v4 )
        *v1 = v4;
    }
    else
    {
      *v1 = v2;
    }
    v1 += 27;
  }
  while ( (int)v1 < (int)&flt_76A580 );
  return 0;
}
