void __stdcall sub_419C50(int *a1)
{
  int v1; // eax
  int v2; // edi
  int v3; // esi
  int v4; // esi
  int v5; // eax
  int v6; // esi
  int v7; // eax
  int v8; // ebx
  int v9; // edi
  int i; // esi
  int v11; // eax
  int v12; // eax
  float v13[8]; // [esp+Ch] [ebp-20h] BYREF

  if ( dword_7D0308 )
  {
    if ( flt_7CF3C8 != 0.0 )
    {
      sub_4144D0(v13);
      if ( a1[4121] == 1 && !a1[4124] )
      {
        v1 = a1[4120];
        if ( *(_DWORD *)(dword_7C54E8 + 18580) == a1[4645] )
        {
          if ( v1 == 1 )
          {
            v2 = 167;
            if ( dword_7D0410 >= 2 && dword_7D0410 <= 5 )
            {
              v3 = dword_8AC490 + 396 * dword_8AC48C;
              if ( v3 )
              {
                v4 = v3 + 260;
                if ( sub_566810(v4, aAlbertPark) )
                {
                  v2 = 161;
                }
                else if ( sub_566810(v4, aInterlagos) )
                {
                  v2 = 164;
                }
                else if ( sub_566810(v4, aImola) )
                {
                  v2 = 175;
                }
                else if ( sub_566810(v4, aMonaco_0) )
                {
                  v2 = 174;
                }
                else if ( sub_566810(v4, aBarcelona) )
                {
                  v2 = 176;
                }
                else if ( sub_566810(v4, aMontreal) )
                {
                  v2 = 165;
                }
                else if ( sub_566810(v4, aMagnyCours) )
                {
                  v2 = 166;
                }
                else if ( sub_566810(v4, aSilverstone) )
                {
                  v2 = 169;
                }
                else if ( sub_566810(v4, aA1Ring) )
                {
                  v2 = 162;
                }
                else if ( sub_566810(v4, aHockenheim) )
                {
                  v2 = 168;
                }
                else if ( sub_566810(v4, aHungaroring) )
                {
                  v2 = 170;
                }
                else if ( sub_566810(v4, aSpaFrancorcham) )
                {
                  v2 = 163;
                }
                else if ( sub_566810(v4, aMonza) )
                {
                  v2 = 171;
                }
                else if ( sub_566810(v4, aNurburgring) )
                {
                  v2 = 160;
                }
                else if ( sub_566810(v4, aSepang) )
                {
                  v2 = 173;
                }
                else if ( sub_566810(v4, aSuzuka) )
                {
                  v2 = 172;
                }
                else if ( sub_566810(v4, aIndianapolis) )
                {
                  v2 = 177;
                }
              }
            }
          }
          else
          {
            v2 = 158;
            if ( dword_7D0410 == 4 && v1 > 6 )
              v2 = 157;
          }
          sub_4144F0(v13, v2, a1[4120], -1, -1, -1, -2.0, -2.0);
          sub_418560(flt_5EA618, v13);
          if ( dword_7D0410 == 4 )
          {
            if ( sub_4C2850(&unk_7D2DB0) )
            {
              v5 = sub_4C2850(&unk_7D2DB0);
              v6 = sub_4C11D0(v5);
              v7 = sub_4C2850(&unk_7D2DB0);
              v8 = sub_4C1190(v7) - v6 - 1;
              if ( v8 > 1 )
              {
                v9 = 0;
                for ( i = 0; i < dword_5C329C - 1; ++i )
                {
                  sub_4C2850(&unk_7D2DB0);
                  if ( sub_4C13A0(i) )
                  {
                    sub_4C2850(&unk_7D2DB0);
                    if ( *(_BYTE *)(sub_4C13A0(i) + 432) )
                    {
                      sub_4C2850(&unk_7D2DB0);
                      if ( *(_DWORD *)(sub_4C13A0(i) + 408) > v9 )
                      {
                        sub_4C2850(&unk_7D2DB0);
                        v9 = *(_DWORD *)(sub_4C13A0(i) + 408);
                      }
                    }
                  }
                }
                v11 = sub_4C2850(&unk_7D2DB0);
                if ( sub_4C1390(v11) )
                {
                  v12 = sub_4C2850(&unk_7D2DB0);
                  if ( *(_DWORD *)(sub_4C1390(v12) + 408) > v9 + 10 * v8 )
                  {
                    sub_4144F0(v13, 159, v8, -1, -1, -1, -2.0, -2.0);
                    sub_418560(flt_5EA618, v13);
                  }
                }
              }
            }
          }
        }
        else if ( v1 == 1 )
        {
          sub_4144F0(v13, 261, a1[4647], -1, -1, -1, -2.0, -2.0);
          sub_418560(flt_5EA618, v13);
        }
        else if ( v1 < 6 )
        {
          sub_4144F0(v13, 260, a1[4647], v1, -1, -1, -2.0, -2.0);
          sub_418560(flt_5EA618, v13);
        }
      }
    }
  }
}
