void __stdcall sub_41B190(int a1)
{
  float v1[8]; // [esp+0h] [ebp-20h] BYREF

  if ( dword_7D0308 && flt_7CF3C8 != 0.0 && *(_DWORD *)(dword_7C54E8 + 18580) == *(_DWORD *)(a1 + 18580) )
  {
    CommentaryEventQueue(v1, 77, -1, -1, -1, -1, -2.0, -2.0);
    InsertDriverTableEntry(flt_5EA618, v1);
  }
}

