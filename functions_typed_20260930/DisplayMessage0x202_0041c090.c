void sub_41C090()
{
  float v0[8]; // [esp+0h] [ebp-20h] BYREF

  if ( dword_7D0308 )
  {
    if ( flt_7CF3C8 != 0.0 )
    {
      CommentaryEventQueue(v0, 514, -1, -1, -1, -1, -2.0, -2.0);
      InsertDriverTableEntry(flt_5EA618, v0);
    }
  }
}

