void __stdcall sub_41AFD0(int a1, int a2)
{
  float v2[8]; // [esp+0h] [ebp-20h] BYREF

  if ( dword_7D0308 && flt_7CF3C8 != 0.0 )
  {
    StructInitWithSentinelValues(v2);
    if ( *(_DWORD *)(dword_7C54E8 + 18580) == *(_DWORD *)(a1 + 18580) )
    {
      switch ( a2 )
      {
        case 0:
          CommentaryEventQueue(v2, 106, -1, -1, -1, -1, -2.0, -2.0);
          break;
        case 1:
          CommentaryEventQueue(v2, 107, -1, -1, -1, -1, -2.0, -2.0);
          break;
        case 2:
          CommentaryEventQueue(v2, 109, -1, -1, -1, -1, -2.0, -2.0);
          break;
        case 3:
          CommentaryEventQueue(v2, 110, -1, -1, -1, -1, -2.0, -2.0);
          break;
        case 4:
          CommentaryEventQueue(v2, 108, -1, -1, -1, -1, -2.0, -2.0);
          break;
        case 5:
          CommentaryEventQueue(v2, 111, -1, -1, -1, -1, -2.0, -2.0);
          break;
        default:
          break;
      }
    }
    else if ( dword_7C56A8 != 8 )
    {
      switch ( a2 )
      {
        case 0:
        case 1:
        case 2:
        case 3:
          CommentaryEventQueue(v2, 221, *(_DWORD *)(a1 + 18588), -1, -1, -1, -2.0, -2.0);
          break;
        case 4:
          CommentaryEventQueue(v2, 222, *(_DWORD *)(a1 + 18588), -1, -1, -1, -2.0, -2.0);
          break;
        case 5:
          CommentaryEventQueue(v2, 223, *(_DWORD *)(a1 + 18588), -1, -1, -1, -2.0, -2.0);
          break;
        default:
          break;
      }
    }
    InsertDriverTableEntry(flt_5EA618, v2);
  }
}

