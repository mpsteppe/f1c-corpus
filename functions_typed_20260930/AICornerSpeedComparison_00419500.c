void __stdcall sub_419500(int a1, int a2)
{
  unsigned int v2; // eax
  double v3; // st7
  float v4[8]; // [esp+8h] [ebp-20h] BYREF

  if ( dword_7D0308 && flt_7CF3C8 != 0.0 && dword_7C56A8 != 8 )
  {
    StructInitWithSentinelValues(v4);
    if ( dword_7C56A4 == 5 && *(_DWORD *)(dword_7C54E8 + 18580) == *(_DWORD *)(a1 + 18580) )
    {
      v2 = sub_4D1B50(0);
      if ( v2 < 0x68 )
      {
        v3 = MEMORY[0x5F0780][4656 * v2 + a2];
        if ( v3 > 0.0 )
        {
          if ( *(float *)(a1 + 4 * a2 + 16460) > v3 )
          {
            if ( a2 == 1 )
            {
              CommentaryEventQueue(v4, 13, -1, -1, -1, -1, -2.0, -2.0);
            }
            else if ( a2 == 2 )
            {
              CommentaryEventQueue(v4, 14, -1, -1, -1, -1, -2.0, -2.0);
            }
          }
          else if ( a2 == 1 )
          {
            CommentaryEventQueue(v4, 19, -1, -1, -1, -1, -2.0, -2.0);
          }
          else if ( a2 == 2 )
          {
            CommentaryEventQueue(v4, 20, -1, -1, -1, -1, -2.0, -2.0);
          }
        }
      }
      if ( LODWORD(v4[0]) != -1 )
        InsertDriverTableEntry(flt_5EA618, v4);
    }
    if ( a2 == 2 && *(_DWORD *)(a1 + 13392) == 1 )
      AIVehicleDamageEvent(a1);
  }
}

