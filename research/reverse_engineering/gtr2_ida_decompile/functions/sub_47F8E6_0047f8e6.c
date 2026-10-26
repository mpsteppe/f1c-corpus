// positive sp value has been detected, the output may be wrong!
int __fastcall sub_47F8E6(const char *a1, int a2)
{
  int v4; // eax
  int v5; // esi
  float v7; // [esp-340h] [ebp-354h]
  _BYTE v8[804]; // [esp-324h] [ebp-338h] BYREF

  v4 = strlen(a1);
  v5 = v4;
  if ( v4 >= 0 )
  {
    if ( v4 > 159 )
      v5 = 159;
  }
  else
  {
    v5 = 0;
  }
  v7 = dbl_FB1D18;
  sub_51B2A0(4, 6, v5, a2, LODWORD(v7), 3);
  sub_630FE0(v8, a1, v5);
  v8[v5] = 0;
  return sub_4745E0();
}
