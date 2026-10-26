void sub_41D630()
{
  int v0; // ebp
  int v1; // eax
  int v2; // esi
  int v3; // edi
  int v4; // ebx
  int v5; // edi
  int v6; // edx
  int v7; // esi
  int v8; // eax
  int v9; // ecx
  int v10; // ecx
  int v11; // eax
  int v12; // eax
  int v13; // ecx
  int v14; // eax
  int v15; // [esp+10h] [ebp-34h]
  int v16; // [esp+14h] [ebp-30h]
  float v17; // [esp+18h] [ebp-2Ch]
  int v18; // [esp+1Ch] [ebp-28h]
  int v19; // [esp+20h] [ebp-24h]
  float v20[8]; // [esp+24h] [ebp-20h] BYREF

  if ( dword_7D0308 && flt_7CF3C8 != 0.0 )
  {
    StructInitWithSentinelValues(v20);
    v0 = -1;
    v1 = dword_8AC490 + 396 * dword_8AC48C;
    v17 = 1.0e16;
    v16 = -1;
    v15 = 0;
    v18 = -1;
    v2 = 477;
    if ( v1 )
    {
      v3 = v1 + 260;
      if ( sub_566810(v1 + 260, aAlbertPark) )
      {
        v2 = 447;
      }
      else if ( sub_566810(v3, aInterlagos) )
      {
        v2 = 450;
      }
      else if ( sub_566810(v3, aImola) )
      {
        v2 = 471;
      }
      else if ( sub_566810(v3, aMonaco_0) )
      {
        v2 = 467;
      }
      else if ( sub_566810(v3, aBarcelona) )
      {
        v2 = 472;
      }
      else if ( sub_566810(v3, aMontreal) )
      {
        v2 = 452;
      }
      else if ( sub_566810(v3, aMagnyCours) )
      {
        v2 = 457;
      }
      else if ( sub_566810(v3, aSilverstone) )
      {
        v2 = 451;
      }
      else if ( sub_566810(v3, aA1Ring) )
      {
        v2 = 448;
      }
      else if ( sub_566810(v3, aHockenheim) )
      {
        v2 = 458;
      }
      else if ( sub_566810(v3, aHungaroring) )
      {
        v2 = 462;
      }
      else if ( sub_566810(v3, aSpaFrancorcham) )
      {
        v2 = 449;
      }
      else if ( sub_566810(v3, aMonza) )
      {
        v2 = 463;
      }
      else if ( sub_566810(v3, aNurburgring) )
      {
        v2 = 453;
      }
      else if ( sub_566810(v3, aSepang) )
      {
        v2 = 466;
      }
      else if ( sub_566810(v3, aSuzuka) )
      {
        v2 = 464;
      }
      else if ( sub_566810(v3, aIndianapolis) )
      {
        v2 = 473;
      }
    }
    CommentaryEventQueue(v20, v2, -1, -1, -1, -1, -2.0, -2.0);
    InsertDriverTableEntry(flt_5EA618, v20);
    v4 = dword_5C329C;
    v5 = 1;
    v19 = dword_5C329C;
    if ( dword_5C329C >= 1 )
    {
      v6 = dword_7C54E8;
      do
      {
        v7 = 0;
        if ( v4 > 0 )
        {
          while ( 1 )
          {
            v8 = dword_7C54F0[v7];
            if ( *(_DWORD *)(v8 + 16480) == v5 )
            {
              v9 = *(_DWORD *)(v8 + 16484);
              if ( v9 == 2 )
              {
                ++v15;
                v0 = v16;
                v18 = v7;
              }
              if ( (v6 && v6 == v8 || v5 <= 6) && v9 != 2 )
                break;
            }
            if ( ++v7 >= v4 )
              goto LABEL_69;
          }
          v10 = dword_7C54F0[v7];
          if ( *(float *)(v10 + 16540) != -1.0 && *(float *)(v10 + 16540) < (double)v17 )
          {
            v0 = v7;
            v17 = *(float *)(v10 + 16540);
            v16 = v7;
          }
          v11 = 397;
          if ( v4 == 22 && *(_DWORD *)(v10 + 16480) == 22 )
            v11 = 465;
          CommentaryEventQueue(v20, v11, *(_DWORD *)(v10 + 18588), v5, -1, -1, -2.0, -2.0);
          InsertDriverTableEntry(flt_5EA618, v20);
          v6 = dword_7C54E8;
          if ( dword_7C54E8 )
          {
            v12 = dword_7C54F0[v7];
            if ( dword_7C54E8 == v12 && *(_DWORD *)(v12 + 16484) != 2 )
            {
              if ( v5 == 1 && !dword_7D2DE8 )
              {
                CommentaryEventQueue(v20, 474, -1, -1, -1, -1, -2.0, -2.0);
                InsertDriverTableEntry(flt_5EA618, v20);
              }
              v13 = *(_DWORD *)(dword_7C54F0[v7] + 16472);
              if ( v5 <= v13 )
              {
                if ( v5 > 6 )
                  v14 = 460;
                else
                  v14 = v5 >= v13 ? 397 : 461;
              }
              else
              {
                v14 = 459;
              }
              CommentaryEventQueue(v20, v14, v13, -1, -1, -1, -2.0, -2.0);
              InsertDriverTableEntry(flt_5EA618, v20);
              v6 = dword_7C54E8;
            }
          }
          v4 = dword_5C329C;
        }
LABEL_69:
        ++v5;
      }
      while ( v5 <= v19 );
      if ( v0 >= 0 )
      {
        if ( v15 <= 1 )
        {
          if ( v15 == 1 )
          {
            if ( v18 < 0 )
              CommentaryEventQueue(v20, 455, *(_DWORD *)(dword_7C54F0[v0] + 18588), -1, -1, -1, -2.0, -2.0);
            else
              CommentaryEventQueue(
                v20,
                456,
                *(_DWORD *)(dword_7C54F0[v18] + 18588),
                *(_DWORD *)(dword_7C54F0[v0] + 18588),
                -1,
                -1,
                -2.0,
                -2.0);
          }
          else
          {
            CommentaryEventQueue(v20, 476, *(_DWORD *)(dword_7C54F0[v0] + 18588), -1, -1, -1, -2.0, -2.0);
          }
        }
        else
        {
          CommentaryEventQueue(v20, 454, v15, *(_DWORD *)(dword_7C54F0[v0] + 18588), -1, -1, -2.0, -2.0);
        }
        InsertDriverTableEntry(flt_5EA618, v20);
      }
    }
  }
}

