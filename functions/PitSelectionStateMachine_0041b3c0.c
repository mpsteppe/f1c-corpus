void __thiscall sub_41B3C0(_DWORD *this, int a2, int a3, float a4, int a5, int a6)
{
  double v6; // st7
  int v7; // edi
  int v8; // esi
  bool v9; // bl
  int v10; // edi
  float v11; // [esp+10h] [ebp-28h]
  float v13[8]; // [esp+18h] [ebp-20h] BYREF

  if ( dword_7D0308 && flt_7CF3C8 != 0.0 && !*(_BYTE *)(dword_7C54E8 + 13388) && dword_7C56A8 != 8 )
  {
    if ( a4 >= 0.0 )
    {
      if ( a4 > (double)flt_5EA3FC )
        a4 = flt_5EA3FC;
    }
    else
    {
      a4 = 0.0;
    }
    StructInitWithSentinelValues(v13);
    v6 = DistanceProjectionCalc(dword_7C54E8 + 12);
    v11 = v6;
    v7 = FloatRangeIndexLookup(a4);
    v8 = FloatRangeIndexLookup(v11);
    v9 = v8 == v7;
    switch ( a2 )
    {
      case 0:
        if ( this[v7 + 316] != 2 )
          goto LABEL_67;
        if ( ScoringGateSelector(v7) )
          goto LABEL_67;
        this[v7 + 316] = 0;
        if ( dword_7C56A4 != 7 || dword_7C56A8 == 5 )
          goto LABEL_67;
        if ( !v7 )
        {
          if ( v8 == 1 )
            goto LABEL_67;
          if ( StateCheckedVirtualDispatch(flt_5EA618, 138) )
          {
            ArraySearchReturningIndex(flt_5EA618, 138);
            if ( !v8 )
              goto LABEL_37;
          }
          else
          {
            if ( (unsigned __int8)ArraySearchReturningIndex(flt_5EA618, 138) )
              goto LABEL_67;
            if ( !v8 )
              goto LABEL_37;
          }
          DriverDataTableLookupAndTimeConversion(v13, 137, -1, -1, -1, -1, -2.0, -2.0);
LABEL_67:
          if ( LODWORD(v13[0]) != -1 )
            InsertDriverTableEntry(flt_5EA618, v13);
          return;
        }
        v10 = v7 - 1;
        if ( v10 )
        {
          if ( v10 != 1 || !v8 )
            goto LABEL_67;
          if ( StateCheckedVirtualDispatch(flt_5EA618, 136) )
          {
            ArraySearchReturningIndex(flt_5EA618, 136);
            if ( v9 )
            {
LABEL_37:
              DriverDataTableLookupAndTimeConversion(v13, 126, -1, -1, -1, -1, -2.0, -2.0);
              goto LABEL_67;
            }
          }
          else
          {
            if ( (unsigned __int8)ArraySearchReturningIndex(flt_5EA618, 136) )
              goto LABEL_67;
            if ( v9 )
              goto LABEL_37;
          }
          DriverDataTableLookupAndTimeConversion(v13, 135, -1, -1, -1, -1, -2.0, -2.0);
          goto LABEL_67;
        }
        if ( v8 == 2 )
          goto LABEL_67;
        if ( StateCheckedVirtualDispatch(flt_5EA618, 134) )
        {
          ArraySearchReturningIndex(flt_5EA618, 134);
          if ( v9 )
            goto LABEL_37;
        }
        else
        {
          if ( (unsigned __int8)ArraySearchReturningIndex(flt_5EA618, 134) )
            goto LABEL_67;
          if ( v9 )
            goto LABEL_37;
        }
        DriverDataTableLookupAndTimeConversion(v13, 133, -1, -1, -1, -1, -2.0, -2.0);
        goto LABEL_67;
      case 2:
        if ( v8 != v7 || (v6 = v11 + 50.0, v6 < a4) )
        {
          if ( v7 )
          {
            if ( v7 == 1 )
            {
              if ( v8 != 2 )
              {
                if ( v8 || (FloatWrapTableInterpolation(v11, 0), v6 >= 0.89999998) )
                {
                  BooleanOROfTwoChecks(flt_5EA618, 133);
                  BooleanOROfTwoChecks(flt_5EA618, 136);
                  ArraySearchReturningIndex(flt_5EA618, 134);
                  DriverDataTableLookupAndTimeConversion(v13, 134, -1, -1, -1, -1, -2.0, -2.0);
                }
              }
            }
            else if ( v7 == 2 )
            {
              if ( v8 )
              {
                if ( v8 != 1 || (FloatWrapTableInterpolation(v11, 0), v6 >= 0.89999998) )
                {
                  BooleanOROfTwoChecks(flt_5EA618, 135);
                  BooleanOROfTwoChecks(flt_5EA618, 138);
                  ArraySearchReturningIndex(flt_5EA618, 136);
                  DriverDataTableLookupAndTimeConversion(v13, 136, -1, -1, -1, -1, -2.0, -2.0);
                }
              }
            }
          }
          else if ( v8 != 1 )
          {
            if ( v8 != 2 || (FloatWrapTableInterpolation(v11, 0), v6 >= 0.89999998) )
            {
              BooleanOROfTwoChecks(flt_5EA618, 137);
              BooleanOROfTwoChecks(flt_5EA618, 134);
              ArraySearchReturningIndex(flt_5EA618, 138);
              DriverDataTableLookupAndTimeConversion(v13, 138, -1, -1, -1, -1, -2.0, -2.0);
            }
          }
        }
        if ( LODWORD(v13[0]) == -1 )
          return;
        this[v7 + 316] = 2;
        goto LABEL_67;
      case 3:
        DriverDataTableLookupAndTimeConversion(v13, 131, -1, -1, -1, -1, -2.0, -2.0);
        goto LABEL_67;
      case 5:
        if ( dword_7C54E8 && dword_7C54E8 == a5 )
        {
          switch ( a6 )
          {
            case 1:
              DriverDataTableLookupAndTimeConversion(v13, 123, -1, -1, -1, -1, -2.0, -2.0);
              break;
            case 2:
              BooleanOROfTwoChecks(flt_5EA618, 123);
              DriverDataTableLookupAndTimeConversion(v13, 124, -1, -1, -1, -1, -2.0, -2.0);
              break;
            case 3:
              BooleanOROfTwoChecks(flt_5EA618, 123);
              BooleanOROfTwoChecks(flt_5EA618, 124);
              DriverDataTableLookupAndTimeConversion(v13, 125, -1, -1, -1, -1, -2.0, -2.0);
              break;
          }
        }
        goto LABEL_67;
      default:
        goto LABEL_67;
    }
  }
}
