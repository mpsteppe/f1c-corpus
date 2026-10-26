void __stdcall sub_41A170(int a1)
{
  int v1; // esi
  float v2[8]; // [esp+8h] [ebp-20h] BYREF

  if ( dword_7D0308 && flt_7CF3C8 != 0.0 )
  {
    if ( (unsigned __int8)sub_4C7BD0(a1) )
    {
      v1 = 52;
    }
    else
    {
      if ( dword_7C56A4 != 7 )
        return;
      v1 = 196;
    }
    StructInitWithSentinelValues(v2);
    CommentaryEventQueue(v2, v1, *(_DWORD *)(a1 + 18592), -1, -1, -1, -2.0, -2.0);
    InsertDriverTableEntry(flt_5EA618, v2);
  }
}

