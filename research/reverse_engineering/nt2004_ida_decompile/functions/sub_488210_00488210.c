int __stdcall sub_488210(int a1)
{
  double v1; // st7
  double v2; // st7
  char Buffer[32]; // [esp+Ch] [ebp-20h] BYREF

  v1 = flt_767850;
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
  flt_767850 = v2;
  if ( v2 >= flt_767858 )
  {
    if ( v2 > *(float *)&dword_76785C )
      LODWORD(flt_767850) = dword_76785C;
  }
  else
  {
    flt_767850 = flt_767858;
  }
  sprintf(Buffer, "%.1f", v2);
  return sub_4A1AC0(Buffer);
}
