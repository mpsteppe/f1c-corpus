void __thiscall sub_462A30(int this)
{
  int v2; // eax
  double v3; // st7
  double ArgList; // [esp+0h] [ebp-18h]
  int v5; // [esp+Ch] [ebp-Ch]
  float v6; // [esp+14h] [ebp-4h]

  v2 = *(_DWORD *)(this + 6720);
  if ( v2 != 2 && v2 != 1 && *(float *)(this + 36) >= 0.0 )
  {
    if ( *(float *)(this + 36) == 5.0 )
    {
      *(float *)&v5 = dbl_7DA9D0;
      sub_45FD90(this, v5);
    }
    v6 = dbl_7DA9C0;
    if ( dword_75CBA8 != 5 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 2, (int)aDDevNascar2004_6, 5595) )
    {
      ArgList = v6;
      sub_500FE0((int)&unk_7D7920, aApplyingFrameT, SLOBYTE(ArgList));
    }
    if ( v6 >= 0.0099999998 )
    {
      if ( v6 > 0.5 )
        v6 = 0.5;
    }
    else
    {
      v6 = 0.0099999998;
    }
    v3 = *(float *)(this + 36) - v6;
    *(float *)(this + 36) = v3;
    if ( v3 <= 0.0 )
    {
      *(_BYTE *)(this + 33) = 1;
      *(_DWORD *)(this + 36) = -1082130432;
    }
  }
}
