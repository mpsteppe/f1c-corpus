int __thiscall sub_47DBE0(_DWORD *this)
{
  int v1; // eax
  int v2; // eax
  double v4; // st7
  double v5; // st7
  int v6; // eax
  const char *v7; // [esp+4h] [ebp-5Ch]
  float v8; // [esp+Ch] [ebp-54h]
  _BYTE v9[80]; // [esp+10h] [ebp-50h] BYREF

  switch ( this[59] )
  {
    case 0x1E0:
      v1 = VehicleDataAccessor(&dword_8AB6EC);
      v2 = UIListIndexedAccessor(v1);
      UIStringComparison(v2);
      return 0;
    case 0x1E1:
      v8 = Delegation(&dword_8AB6EC);
      v4 = VehicleLifetimeAverageAccessor(&dword_8AB6EC);
      StringFormatWithBufferOverflowCheck(v9, "%1.3f", v8 - v4);
      UIStringComparison(v9);
      return 0;
    case 0x1E2:
      v5 = RangeWidthGetter(&dword_8AB6EC);
      StringFormatWithBufferOverflowCheck(v9, "%1.3f", v5);
      UIStringComparison(v9);
      return 0;
    case 0x1E3:
      if ( !dword_7C54E0 )
      {
        v7 = asc_5C7370;
        goto LABEL_9;
      }
      v6 = *(_DWORD *)(dword_7C54E0 + 16480);
      v7 = (const char *)(dword_7C54E0 + 17952);
      if ( v6 <= 0 )
      {
LABEL_9:
        UIStringComparison(v7);
        return 0;
      }
      StringFormatWithBufferOverflowCheck(v9, "(%d) %s", v6, v7);
      UIStringComparison(v9);
      return 0;
    default:
      return 0;
  }
}

