void __thiscall sub_4193A0(_DWORD *this, float a2, int a3)
{
  int v4; // eax
  int v5; // esi
  float v6[8]; // [esp+8h] [ebp-20h] BYREF

  if ( dword_7D0308 && flt_7CF3C8 != 0.0 && *(_DWORD *)(dword_7C54E8 + 18580) == *(_DWORD *)(LODWORD(a2) + 18580) )
  {
    v4 = a3;
    if ( a3 == -1 )
      v4 = FloatRangeIndexLookup(*(float *)(LODWORD(a2) + 16456));
    v5 = ThreeWayEnumConverter(v4);
    if ( ScoringGateSelector(v5) == 2 && this[v5 + 316] != 2 )
    {
      StructInitWithSentinelValues(v6);
      if ( v5 )
      {
        if ( v5 == 1 )
        {
          if ( dword_7C56A8 != 8 )
          {
            BooleanOROfTwoChecks(flt_5EA618, 133);
            CommentaryEventQueue(v6, 134, -1, -1, -1, -1, -2.0, -2.0);
          }
        }
        else if ( v5 == 2 )
        {
          BooleanOROfTwoChecks(flt_5EA618, 135);
          CommentaryEventQueue(v6, 136, -1, -1, -1, -1, -2.0, -2.0);
        }
      }
      else
      {
        BooleanOROfTwoChecks(flt_5EA618, 137);
        CommentaryEventQueue(v6, 138, -1, -1, -1, -1, -2.0, -2.0);
      }
      InsertDriverTableEntry(flt_5EA618, v6);
      this[v5 + 316] = 2;
    }
  }
}

