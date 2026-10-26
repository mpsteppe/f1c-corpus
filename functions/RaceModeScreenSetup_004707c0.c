int __thiscall RaceModeScreenSetup(int this)
{
  char *v2; // eax
  char v4[32]; // [esp+Ch] [ebp-20h] BYREF

  *(float *)(this + 804) = (float)dword_7D0410;
  *(_DWORD *)(this + 800) = &flt_7D122C;
  if ( flt_7D122C == 0.0 )
  {
    v2 = UIListIndexedAccessor((_DWORD *)this, 0);
    StringFormatWithBufferOverflowCheck(v4, (int)v2);
  }
  else
  {
    StringFormatWithBufferOverflowCheck(v4, (int)"%.1f", flt_7D122C);
  }
  EditBufferStringUpdate((_DWORD *)this, v4);
  return 0;
}
