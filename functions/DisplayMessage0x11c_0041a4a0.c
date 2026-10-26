void sub_41A4A0()
{
  float v0[8]; // [esp+0h] [ebp-20h] BYREF

  if ( dword_7D0308 )
  {
    if ( flt_7CF3C8 != 0.0 )
    {
      DriverDataTableLookupAndTimeConversion(v0, 284, -1, -1, -1, -1, -2.0, -2.0);
      InsertDriverTableEntry(flt_5EA618, v0);
    }
  }
}
