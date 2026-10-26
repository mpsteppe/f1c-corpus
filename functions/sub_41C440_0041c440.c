void sub_41C440()
{
  int v0; // eax
  int v1; // eax
  int v2; // [esp-18h] [ebp-38h]
  float v3[8]; // [esp+0h] [ebp-20h] BYREF

  if ( dword_7D0308 && flt_7CF3C8 != 0.0 )
  {
    StructInitWithSentinelValues(v3);
    v0 = -1;
    if ( dword_7D0410 == 4 )
      v0 = sub_4C2990(&dword_7D2DB0) + 1;
    v2 = v0;
    v1 = sub_420000();
    DriverDataTableLookupAndTimeConversion(v3, v1, v2, -1, -1, -1, -2.0, -2.0);
    InsertDriverTableEntry(flt_5EA618, v3);
  }
}
