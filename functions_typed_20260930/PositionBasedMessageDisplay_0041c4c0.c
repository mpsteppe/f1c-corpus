void __stdcall sub_41C4C0(char a1)
{
  int v1; // eax
  int v2; // eax
  int v3; // [esp-18h] [ebp-38h]
  float v4; // [esp-8h] [ebp-28h]
  float v5; // [esp-4h] [ebp-24h]
  float v6[8]; // [esp+0h] [ebp-20h] BYREF

  if ( dword_7D0308 && flt_7CF3C8 != 0.0 )
  {
    StructInitWithSentinelValues(v6);
    v1 = sub_4C2990(&dword_7D2DB0) + 2;
    if ( a1 )
    {
      v5 = -1.0;
      v4 = 0.0;
    }
    else
    {
      v5 = -2.0;
      v4 = -2.0;
    }
    v3 = v1;
    v2 = ThunkToFUN004201e0();
    CommentaryEventQueue(v6, v2, v3, -1, -1, -1, v4, v5);
    InsertDriverTableEntry(flt_5EA618, v6);
  }
}

