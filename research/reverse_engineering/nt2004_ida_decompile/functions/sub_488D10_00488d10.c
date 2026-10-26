int __stdcall sub_488D10(int a1)
{
  double v1; // st7
  double v2; // st7
  char Buffer[32]; // [esp+Ch] [ebp-20h] BYREF

  v1 = *(float *)&dword_76782C;
  if ( a1 == 1 )
    v2 = v1 + 0.1;
  else
    v2 = v1 - 0.1;
  if ( v2 >= 0.0 )
  {
    if ( v2 > 1.0 )
      v2 = 1.0;
  }
  else
  {
    v2 = 0.0;
  }
  *(float *)&dword_76782C = v2;
  if ( v2 >= flt_767834 )
  {
    if ( v2 > *(float *)&dword_767838 )
      dword_76782C = dword_767838;
  }
  else
  {
    *(float *)&dword_76782C = flt_767834;
  }
  sprintf(Buffer, "%.1f", v2);
  return sub_4A1AC0(Buffer);
}
