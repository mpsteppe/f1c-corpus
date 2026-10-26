void __stdcall sub_41B250(int a1)
{
  int v1; // ecx
  int v2; // [esp-18h] [ebp-40h]
  int v3; // [esp-14h] [ebp-3Ch]
  float v4[8]; // [esp+8h] [ebp-20h] BYREF

  if ( dword_7D0308 && flt_7CF3C8 != 0.0 && dword_7C56A4 == 7 && dword_7C56A8 != 8 && dword_7D0410 != 5 )
  {
    StructInitWithSentinelValues(v4);
    if ( *(_DWORD *)(dword_7C54E8 + 18580) == *(_DWORD *)(a1 + 18580) )
    {
      if ( *(_DWORD *)(a1 + 16488) == 1 )
      {
        CommentaryEventQueue(v4, 119, -1, -1, -1, -1, -2.0, -2.0);
      }
      else if ( *(_DWORD *)(a1 + 16488) == 7 )
      {
        CommentaryEventQueue(v4, 118, -1, -1, -1, -1, -2.0, -2.0);
      }
      else
      {
        CommentaryEventQueue(v4, 117, -1, -1, -1, -1, -2.0, -2.0);
      }
    }
    else if ( dword_7C56A8 != 8 )
    {
      v1 = 3;
      if ( *(float *)(a1 + 16452) > 0.0 )
      {
        v1 = FloatRangeIndexLookup(*(float *)(a1 + 16452));
        if ( !v1 )
          v1 = 3;
      }
      if ( *(_DWORD *)(a1 + 16488) == 1 )
      {
        v3 = *(_DWORD *)(a1 + 18588);
        v2 = 235;
      }
      else
      {
        if ( *(_DWORD *)(a1 + 16488) != 4 )
        {
          if ( *(_DWORD *)(a1 + 16488) == 9 )
            CommentaryEventQueue(v4, 236, *(_DWORD *)(a1 + 18588), v1, -1, -1, -2.0, -2.0);
          else
            CommentaryEventQueue(v4, 237, *(_DWORD *)(a1 + 18588), v1, -1, -1, -2.0, -2.0);
          goto LABEL_24;
        }
        v3 = *(_DWORD *)(a1 + 18588);
        v2 = 238;
      }
      CommentaryEventQueue(v4, v2, v3, v1, -1, -1, -2.0, -2.0);
    }
LABEL_24:
    if ( LODWORD(v4[0]) != -1 )
      InsertDriverTableEntry(flt_5EA618, v4);
  }
}

