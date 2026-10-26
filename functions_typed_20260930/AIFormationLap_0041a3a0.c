void __stdcall sub_41A3A0(_DWORD *a1)
{
  int v1; // ecx
  int v2; // eax
  int v3; // eax
  float v4[8]; // [esp+0h] [ebp-20h] BYREF

  if ( dword_7D0308 )
  {
    if ( flt_7CF3C8 != 0.0 && dword_7C56A8 != 8 )
    {
      StructInitWithSentinelValues(v4);
      if ( *(_DWORD *)(dword_7C54E8 + 18580) != a1[4645] && dword_7C56A4 >= 0 )
      {
        if ( dword_7C56A4 <= 6 )
          goto LABEL_17;
        if ( dword_7C56A4 != 7 )
          return;
        if ( dword_7D0410 == 5 )
        {
LABEL_17:
          v3 = 6;
LABEL_18:
          CommentaryEventQueue(v4, v3, a1[4647], -1, -1, -1, -2.0, -2.0);
          InsertDriverTableEntry(flt_5EA618, v4);
          return;
        }
        v1 = a1[4111];
        v2 = a1[3340];
        if ( v2 >= v1 - 1 && v2 <= v1 + 1 )
        {
          switch ( a1[3339] )
          {
            case 1:
              v3 = 180;
              break;
            case 2:
              v3 = 181;
              break;
            case 3:
              v3 = 182;
              break;
            default:
              return;
          }
          goto LABEL_18;
        }
      }
    }
  }
}

