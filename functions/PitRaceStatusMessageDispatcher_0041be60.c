void sub_41BE60()
{
  int v0; // esi
  int v1; // eax
  float v2[8]; // [esp+0h] [ebp-20h] BYREF

  if ( dword_7D0308 && flt_7CF3C8 != 0.0 )
  {
    StructInitWithSentinelValues(v2);
    v0 = sub_4FF130(&unk_8AFEC0);
    v1 = AudioFilterParameterCalculation(&unk_8AFEC0);
    switch ( v0 )
    {
      case 2:
        if ( v1 != 2 )
          goto LABEL_17;
        DriverDataTableLookupAndTimeConversion(v2, 506, -1, -1, -1, -1, -2.0, -2.0);
        InsertDriverTableEntry(flt_5EA618, v2);
        if ( flt_8AFEF0 > 30.0 )
        {
          DriverDataTableLookupAndTimeConversion(v2, 507, -1, -1, -1, -1, -2.0, -2.0);
          InsertDriverTableEntry(flt_5EA618, v2);
        }
        return;
      case 3:
        if ( v1 == 3 || v1 == 2 )
          DriverDataTableLookupAndTimeConversion(v2, 509, -1, -1, -1, -1, -2.0, -2.0);
        else
          DriverDataTableLookupAndTimeConversion(v2, 512, -1, -1, -1, -1, -2.0, -2.0);
        goto LABEL_21;
      case 4:
        if ( v1 != 4 && v1 != 5 )
          goto LABEL_17;
        DriverDataTableLookupAndTimeConversion(v2, 510, -1, -1, -1, -1, -2.0, -2.0);
        goto LABEL_19;
      case 5:
        if ( v1 == 4 || v1 == 5 )
        {
          DriverDataTableLookupAndTimeConversion(v2, 511, -1, -1, -1, -1, -2.0, -2.0);
LABEL_19:
          InsertDriverTableEntry(flt_5EA618, v2);
          if ( (flt_8AFEE8 + flt_8AFEEC) * 0.5 > 0.7 )
          {
            DriverDataTableLookupAndTimeConversion(v2, 513, -1, -1, -1, -1, -2.0, -2.0);
LABEL_21:
            InsertDriverTableEntry(flt_5EA618, v2);
          }
        }
        else
        {
LABEL_17:
          DriverDataTableLookupAndTimeConversion(v2, 512, -1, -1, -1, -1, -2.0, -2.0);
          InsertDriverTableEntry(flt_5EA618, v2);
        }
        break;
      default:
        return;
    }
  }
}
