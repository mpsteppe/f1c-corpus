int __stdcall sub_417640(int a1, int a2, unsigned int a3, char a4)
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
            v4 = a4 != 0 ? 425 : 436;
          }
          else
          {
            if ( sub_566810(v7, aFerrari) )
            {
              v8 = a4 != 0 ? 426 : 437;
              goto LABEL_62;
            }
            if ( sub_566810(v7, aWilliams) )
            {
              v4 = a4 != 0 ? 427 : 438;
            }
            else if ( sub_566810(v7, aJordan) )
            {
              v4 = a4 != 0 ? 428 : 439;
            }
            else
            {
              if ( sub_566810(v7, aSauber) )
              {
                v8 = a4 != 0 ? 429 : 440;
                goto LABEL_62;
              }
              if ( sub_566810(v7, aArrows) )
              {
                v4 = a4 != 0 ? 430 : 441;
              }
              else if ( sub_566810(v7, aProst) )
              {
                v4 = a4 != 0 ? 431 : 442;
              }
              else
              {
                if ( sub_566810(v7, aMinardi) )
                {
                  v8 = a4 != 0 ? 432 : 443;
                  goto LABEL_62;
                }
                if ( sub_566810(v7, &off_5C25E0) )
                {
                  v4 = a4 != 0 ? 433 : 444;
                }
                else if ( sub_566810(v7, aJaguar) )
                {
                  v4 = a4 != 0 ? 435 : 446;
                }
                else
                {
                  if ( sub_566810(v7, aBenetton) )
                  {
                    v8 = 22 - (a4 != 0);
                    goto LABEL_62;
                  }
                  if ( sub_566810(v7, aRenault) )
                  {
                    v4 = 330 - (a4 != 0);
                  }
                  else if ( sub_566810(v7, aStewart) )
                  {
                    v4 = 418 - (a4 != 0);
                  }
                  else if ( sub_566810(v7, aToyota) )
                  {
                    v8 = 454 - (a4 != 0);
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
          v8 = a4 != 0 ? 408 : 419;
LABEL_62:
          v4 = v8;
          goto LABEL_63;
        }
        if ( sub_566810(v7, aFerrari) )
        {
          v4 = a4 != 0 ? 409 : 420;
        }
        else if ( sub_566810(v7, aWilliams) )
        {
          v4 = a4 != 0 ? 410 : 421;
        }
        else
        {
          if ( sub_566810(v7, aJordan) )
          {
            v8 = a4 != 0 ? 411 : 422;
            goto LABEL_62;
          }
          if ( sub_566810(v7, aSauber) )
          {
            v4 = a4 != 0 ? 412 : 423;
          }
          else if ( sub_566810(v7, aArrows) )
          {
            v4 = a4 != 0 ? 413 : 424;
          }
          else
          {
            if ( sub_566810(v7, aProst) )
            {
              v8 = a4 != 0 ? 414 : 425;
              goto LABEL_62;
            }
            if ( sub_566810(v7, aMinardi) )
            {
              v4 = a4 != 0 ? 415 : 426;
            }
            else if ( sub_566810(v7, &off_5C25E0) )
            {
              v4 = a4 != 0 ? 416 : 427;
            }
            else
            {
              if ( sub_566810(v7, aJaguar) )
              {
                v8 = a4 != 0 ? 418 : 429;
                goto LABEL_62;
              }
              if ( sub_566810(v7, aBenetton) )
              {
                v4 = 460 - (a4 != 0);
              }
              else if ( sub_566810(v7, aRenault) )
              {
                v4 = 474 - (a4 != 0);
              }
              else
              {
                if ( sub_566810(v7, aStewart) )
                {
                  v8 = 480 - (a4 != 0);
                  goto LABEL_62;
                }
                if ( sub_566810(v7, aToyota) )
                  v4 = 490 - (a4 != 0);
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

