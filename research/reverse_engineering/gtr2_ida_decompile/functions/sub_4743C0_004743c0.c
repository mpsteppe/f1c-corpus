void __thiscall sub_4743C0(int this)
{
  int v2; // eax
  double v3; // st7
  double ArgList; // [esp+0h] [ebp-18h]
  float v5; // [esp+14h] [ebp-4h]

  v2 = *(_DWORD *)(this + 113328);
  if ( v2 != 2 && v2 != 1 && *(float *)(this + 1188) >= 0.0 )
  {
    if ( *(_DWORD *)(this + 1188) == 1084227584 && !*(_BYTE *)(this + 24) )
      sub_59B780(*(_DWORD *)(this + 113316));
    v5 = dbl_FB1D08;
    if ( dword_B640C0 != 5
      && (unsigned __int8)sub_5612D0((int)byte_FAE910, 2, "\\Dev\\Src\\Copperhead\\App\\Source\\netcomm.cpp", 5675) )
    {
      ArgList = v5;
      sub_561210((int)byte_FAE910, "Applying frame time %.3f toward opening track (%.3f)", SLOBYTE(ArgList));
    }
    if ( v5 >= 0.0099999998 )
    {
      if ( v5 > 0.5 )
        v5 = 0.5;
    }
    else
    {
      v5 = 0.0099999998;
    }
    v3 = *(float *)(this + 1188) - v5;
    *(float *)(this + 1188) = v3;
    if ( v3 <= 0.0 )
    {
      *(_BYTE *)(this + 1185) = 1;
      *(_DWORD *)(this + 1188) = -1082130432;
    }
  }
}
