void __stdcall sub_41A0C0(int a1)
{
  float v1[8]; // [esp+4h] [ebp-20h] BYREF

  if ( dword_7D0308 && flt_7CF3C8 != 0.0 )
  {
    BooleanOROfTwoChecks(flt_5EA618, 264);
    if ( a1 != *(_DWORD *)(dword_7C54F0[dword_7C54E4] + 18580) )
    {
      StructInitWithSentinelValues(v1);
      CommentaryEventQueue(v1, 264, MEMORY[0x5F0F74][4656 * a1], -1, -1, -1, -2.0, -2.0);
      InsertDriverTableEntry(flt_5EA618, v1);
    }
  }
}

