int __thiscall sub_4BEA40(_DWORD *this, _DWORD *a2, int a3)
{
  int result; // eax
  float v5; // [esp+4h] [ebp-30h] BYREF
  float v6; // [esp+8h] [ebp-2Ch]
  float v7; // [esp+Ch] [ebp-28h]
  float v8[5]; // [esp+10h] [ebp-24h] BYREF
  float v9; // [esp+24h] [ebp-10h]
  float v10; // [esp+28h] [ebp-Ch]
  float v11; // [esp+30h] [ebp-4h]

  result = this[51];
  if ( result )
  {
    sub_579100(a3, v8);
    if ( sub_404F90(&flt_628F60) )
    {
      sub_579C10(3.1415927, (int)&v5);
    }
    else
    {
      v5 = -asin(v9);
      if ( fabs(v9) == 1.0 )
      {
        v7 = 0.0;
        v6 = atan2(-v10, v8[0]);
      }
      else
      {
        v6 = atan2(v8[2], v11);
        v7 = atan2(v8[3], v8[4]);
      }
    }
    sub_59E050(*a2, a2[1], a2[2]);
    result = sub_59E0F0(v5, v6, v7);
    this[45] = 2;
  }
  return result;
}
