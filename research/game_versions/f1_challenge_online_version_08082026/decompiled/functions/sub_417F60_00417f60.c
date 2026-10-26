int __stdcall sub_417F60(int a1, int a2, char a3, char a4)
{
  int v4; // edi
  int v5; // ebx
  int v6; // eax
  int v7; // esi
  int v8; // eax

  v4 = -1;
  v5 = sub_4141A0(1u);
  if ( v5 < 0 )
    return 1;
  if ( a2 >= 0 )
  {
    v6 = dword_8AC490 + 396 * a2;
    if ( v6 )
    {
      v7 = v6 + 260;
      if ( a3 )
      {
        if ( sub_566810(v7, aAlbertPark) )
        {
          v8 = a4 != 0 ? 29 : 50;
LABEL_73:
          v4 = v8;
          goto LABEL_74;
        }
        if ( sub_566810(v7, aInterlagos) )
        {
          v4 = a4 != 0 ? 30 : 51;
        }
        else if ( sub_566810(v7, aImola) )
        {
          v4 = a4 != 0 ? 49 : 70;
        }
        else
        {
          if ( sub_566810(v7, aMonaco_0) )
          {
            v8 = a4 != 0 ? 31 : 52;
            goto LABEL_73;
          }
          if ( sub_566810(v7, aBarcelona) )
          {
            v4 = a4 != 0 ? 34 : 55;
          }
          else if ( sub_566810(v7, aMontreal) )
          {
            v4 = a4 != 0 ? 37 : 58;
          }
          else
          {
            if ( sub_566810(v7, aMagnyCours) )
            {
              v8 = a4 != 0 ? 38 : 59;
              goto LABEL_73;
            }
            if ( sub_566810(v7, aSilverstone) )
            {
              v4 = a4 != 0 ? 39 : 60;
            }
            else if ( sub_566810(v7, aA1Ring) )
            {
              v4 = a4 != 0 ? 40 : 61;
            }
            else
            {
              if ( sub_566810(v7, aHockenheim) )
              {
                v8 = a4 != 0 ? 41 : 62;
                goto LABEL_73;
              }
              if ( sub_566810(v7, aHungaroring) )
              {
                v4 = a4 != 0 ? 42 : 63;
              }
              else if ( sub_566810(v7, aSpaFrancorcham) )
              {
                v4 = a4 != 0 ? 43 : 64;
              }
              else
              {
                if ( sub_566810(v7, aMonza) )
                {
                  v8 = a4 != 0 ? 44 : 65;
                  goto LABEL_73;
                }
                if ( sub_566810(v7, aNurburgring) )
                {
                  v4 = a4 != 0 ? 45 : 66;
                }
                else if ( sub_566810(v7, aSepang) )
                {
                  v4 = a4 != 0 ? 46 : 67;
                }
                else
                {
                  if ( sub_566810(v7, aSuzuka) )
                  {
                    v8 = a4 != 0 ? 47 : 68;
                    goto LABEL_73;
                  }
                  if ( sub_566810(v7, aIndianapolis) )
                    v4 = a4 != 0 ? 48 : 69;
                }
              }
            }
          }
        }
      }
      else if ( sub_566810(v7, aAlbertPark) )
      {
        v4 = a4 != 0 ? 73 : 92;
      }
      else
      {
        if ( sub_566810(v7, aInterlagos) )
        {
          v8 = a4 != 0 ? 74 : 93;
          goto LABEL_73;
        }
        if ( sub_566810(v7, aImola) )
        {
          v4 = a4 != 0 ? 75 : 94;
        }
        else if ( sub_566810(v7, aMonaco_0) )
        {
          v4 = a4 != 0 ? 76 : 95;
        }
        else
        {
          if ( sub_566810(v7, aBarcelona) )
          {
            v8 = a4 != 0 ? 77 : 96;
            goto LABEL_73;
          }
          if ( sub_566810(v7, aMontreal) )
          {
            v4 = a4 != 0 ? 78 : 97;
          }
          else if ( sub_566810(v7, aMagnyCours) )
          {
            v4 = a4 != 0 ? 79 : 98;
          }
          else
          {
            if ( sub_566810(v7, aSilverstone) )
            {
              v8 = a4 != 0 ? 80 : 99;
              goto LABEL_73;
            }
            if ( sub_566810(v7, aA1Ring) )
            {
              v4 = a4 != 0 ? 81 : 100;
            }
            else if ( sub_566810(v7, aHockenheim) )
            {
              v4 = a4 != 0 ? 82 : 101;
            }
            else
            {
              if ( sub_566810(v7, aHungaroring) )
              {
                v8 = a4 != 0 ? 83 : 102;
                goto LABEL_73;
              }
              if ( sub_566810(v7, aSpaFrancorcham) )
              {
                v4 = a4 != 0 ? 84 : 103;
              }
              else if ( sub_566810(v7, aMonza) )
              {
                v4 = a4 != 0 ? 85 : 104;
              }
              else
              {
                if ( sub_566810(v7, aNurburgring) )
                {
                  v8 = 148 - (a4 != 0);
                  goto LABEL_73;
                }
                if ( sub_566810(v7, aSepang) )
                {
                  v4 = a4 != 0 ? 86 : 105;
                }
                else if ( sub_566810(v7, aSuzuka) )
                {
                  v4 = a4 != 0 ? 87 : 106;
                }
                else if ( sub_566810(v7, aIndianapolis) )
                {
                  v8 = a4 != 0 ? 89 : 108;
                  goto LABEL_73;
                }
              }
            }
          }
        }
      }
    }
  }
LABEL_74:
  if ( v5 > 0 && v4 > 0 )
  {
    sub_566650(&byte_5EA438);
    *(_DWORD *)(a1 + 8) = v4;
    *(_DWORD *)(a1 + 12) = v5;
    *(_BYTE *)(a1 + 16) = 0;
    return 0;
  }
  return 1;
}
