int __thiscall sub_4816E0(_DWORD *this)
{
  const char *v1; // eax
  char Buffer[32]; // [esp+Ch] [ebp-20h] BYREF

  this[212] = *(_DWORD *)dword_7689CC;
  this[211] = &flt_769C80;
  if ( flt_769C80 == 0.0 )
  {
    v1 = (const char *)sub_49D690(0);
    sprintf(Buffer, v1);
  }
  else
  {
    sprintf(Buffer, "%.1f", flt_769C80);
  }
  sub_4A1AC0(Buffer);
  return 0;
}
