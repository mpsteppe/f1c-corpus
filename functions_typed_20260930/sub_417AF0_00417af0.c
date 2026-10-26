int __stdcall sub_417AF0(int a1, int a2, unsigned int a3, char a4)
{
  int v4; // edi
  int v5; // ebp
  int v6; // eax
  int v7; // esi
  int v8; // eax

  v4 = -1;
  v5 = ShortComputation_41a0(a3);
  if ( v5 < 0 )
    return 1;
  if ( a2 >= 0 )
  {
    v6 = dword_8AC394 + 1060 * a2;
    if ( v6 )
    {
      v7 = v6 + 124;
      if ( a3 )
      {
        if ( a3 == 1 )
        {
          if ( sub_566810(v6 + 124, aMclaren) )
          {
            v4 = a4 != 0 ? 121 : 131;
          }
          else
          {
            if ( sub_566810(v7, aFerrari) )
            {
              v8 = a4 != 0 ? 122 : 132;
              goto LABEL_62;
            }
            if ( sub_566810(v7, aWilliams) )
            {
              v4 = a4 != 0 ? 123 : 133;
            }
            else if ( sub_566810(v7, aJordan) )
            {
              v4 = a4 != 0 ? 124 : 134;
            }
            else
            {
              if ( sub_566810(v7, aSauber) )
              {
                v8 = a4 != 0 ? 125 : 135;
                goto LABEL_62;
              }
              if ( sub_566810(v7, aArrows) )
              {
                v4 = a4 != 0 ? 126 : 136;
              }
              else if ( sub_566810(v7, aProst) )
              {
                v4 = a4 != 0 ? 127 : 137;
              }
              else
              {
                if ( sub_566810(v7, aMinardi) )
                {
                  v8 = a4 != 0 ? 128 : 138;
                  goto LABEL_62;
                }
                if ( sub_566810(v7, &off_5C25E0) )
                {
                  v4 = a4 != 0 ? 129 : 139;
                }
                else if ( sub_566810(v7, aJaguar) )
                {
                  v4 = a4 != 0 ? 130 : 140;
                }
                else
                {
                  if ( sub_566810(v7, aRenault) )
                  {
                    v8 = 328 - (a4 != 0);
                    goto LABEL_62;
                  }
                  if ( sub_566810(v7, aToyota) )
                  {
                    v4 = 452 - (a4 != 0);
                  }
                  else if ( sub_566810(v7, aBenetton) )
                  {
                    v4 = 20 - (a4 != 0);
                  }
                  else if ( sub_566810(v7, aStewart) )
                  {
                    v8 = 416 - (a4 != 0);
                    goto LABEL_62;
                  }
                }
              }
            }
          }
        }
      }
      else
      {
        if ( sub_566810(v6 + 124, aMclaren) )
        {
          v8 = 66 - (a4 != 0);
LABEL_62:
          v4 = v8;
          goto LABEL_63;
        }
        if ( sub_566810(v7, aFerrari) )
        {
          v4 = 68 - (a4 != 0);
        }
        else if ( sub_566810(v7, aWilliams) )
        {
          v4 = 70 - (a4 != 0);
        }
        else
        {
          if ( sub_566810(v7, aJordan) )
          {
            v8 = 72 - (a4 != 0);
            goto LABEL_62;
          }
          if ( sub_566810(v7, aSauber) )
          {
            v4 = 74 - (a4 != 0);
          }
          else if ( sub_566810(v7, aArrows) )
          {
            v4 = 76 - (a4 != 0);
          }
          else
          {
            if ( sub_566810(v7, aProst) )
            {
              v8 = 78 - (a4 != 0);
              goto LABEL_62;
            }
            if ( sub_566810(v7, aMinardi) )
            {
              v4 = 80 - (a4 != 0);
            }
            else if ( sub_566810(v7, &off_5C25E0) )
            {
              v4 = 82 - (a4 != 0);
            }
            else
            {
              if ( sub_566810(v7, aJaguar) )
              {
                v8 = 84 - (a4 != 0);
                goto LABEL_62;
              }
              if ( sub_566810(v7, aRenault) )
              {
                v4 = 472 - (a4 != 0);
              }
              else if ( sub_566810(v7, aToyota) )
              {
                v4 = 488 - (a4 != 0);
              }
              else
              {
                if ( sub_566810(v7, aBenetton) )
                {
                  v8 = 458 - (a4 != 0);
                  goto LABEL_62;
                }
                if ( sub_566810(v7, aStewart) )
                  v4 = 478 - (a4 != 0);
              }
            }
          }
        }
      }
    }
  }
LABEL_63:
  if ( v5 > 0 && v4 > 0 )
  {
    StringCopyWithBufferRealloc(&byte_5EA438);
    *(_DWORD *)(a1 + 8) = v4;
    *(_DWORD *)(a1 + 12) = v5;
    *(_BYTE *)(a1 + 16) = 0;
    return 0;
  }
  return 1;
}

