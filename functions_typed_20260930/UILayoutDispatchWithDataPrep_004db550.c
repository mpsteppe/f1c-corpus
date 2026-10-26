int __stdcall sub_4DB550(int a1)
{
  double v1; // st7
  int v2; // eax
  int v3; // eax
  float v5; // [esp+8h] [ebp-4h]

  if ( byte_7D0474 )
    v1 = (double)SpeedMagnitude();
  else
    v1 = (double)SpeedMagnitude_b950();
  v5 = v1;
  v2 = EngineRevValueAccessor();
  PositionOrderNameDisplay(v2, a1, 20);
  UtilityFunction_b9a0(v5, a1, 68);
  v3 = sub_49B7A0(&unk_7CE234);
  return sub_4DB7F0(v3, a1, 10);
}

