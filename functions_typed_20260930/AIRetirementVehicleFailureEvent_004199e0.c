void __stdcall sub_4199E0(int a1)
{
  int *v1; // edi
  int v2; // esi
  int v3; // eax
  int *v4; // esi
  int v5; // eax
  int v6; // eax
  float v7; // [esp+4h] [ebp-24h] BYREF
  float v8[8]; // [esp+8h] [ebp-20h] BYREF

  if ( dword_7D0308 )
  {
    if ( flt_7CF3C8 != 0.0 && dword_7C56A8 != 8 && dword_7C56A4 == 7 )
    {
      v1 = (int *)a1;
      if ( *(_DWORD *)(dword_7C54E8 + 18580) == *(_DWORD *)(a1 + 18580) )
      {
        StructInitWithSentinelValues(v8);
        CommentaryEventQueue(v8, 41, v1[4120], -1, -1, -1, -2.0, -2.0);
        InsertDriverTableEntry(flt_5EA618, v8);
        v2 = v1[4148];
        if ( v2 && !LapTimeGapCalculation(v2, v1, &v7, &a1) )
        {
          if ( a1 <= 0 )
            v3 = CRTFtol(v7);
          else
            v3 = 9999;
          CommentaryEventQueue(v8, 1, *(_DWORD *)(v2 + 18588), *(_DWORD *)(v2 + 16480), v3, -1, -2.0, -2.0);
          InsertDriverTableEntry(flt_5EA618, v8);
        }
        v4 = (int *)v1[4149];
        if ( v4 && v4[4121] != 2 && !LapTimeGapCalculation(v1, v4, &v7, &a1) )
        {
          if ( a1 <= 0 )
            v5 = CRTFtol(v7);
          else
            v5 = 9999;
          CommentaryEventQueue(v8, 2, v4[4647], v4[4120], v5, -1, -2.0, -2.0);
          InsertDriverTableEntry(flt_5EA618, v8);
        }
        v6 = dword_8ACF8C - *(_DWORD *)(dword_7C54E0 + 16444);
        switch ( v6 )
        {
          case 1:
            CommentaryEventQueue(v8, 273, -1, -1, -1, -1, -2.0, -2.0);
            InsertDriverTableEntry(flt_5EA618, v8);
            break;
          case 2:
          case 3:
          case 4:
          case 5:
          case 6:
          case 7:
          case 8:
          case 9:
          case 10:
          case 11:
          case 12:
          case 15:
          case 20:
          case 25:
          case 30:
          case 35:
          case 40:
          case 50:
            CommentaryEventQueue(v8, 272, v6, -1, -1, -1, -2.0, -2.0);
            InsertDriverTableEntry(flt_5EA618, v8);
            break;
          default:
            return;
        }
      }
    }
  }
}

