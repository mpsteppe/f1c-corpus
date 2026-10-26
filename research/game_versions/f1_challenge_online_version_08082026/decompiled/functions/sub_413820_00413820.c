int __stdcall sub_413820(int a1, int a2, int a3, char a4)
{
  int result; // eax
  double v5; // st7
  int v6; // eax

  result = -1;
  if ( !a2 && !a4 )
  {
    v5 = (double)a3;
    if ( v5 >= 1.0 )
    {
      if ( v5 >= 3.0 )
      {
        if ( v5 >= 4.0 )
        {
          if ( v5 >= 7.5 )
          {
            if ( v5 >= 12.5 )
            {
              if ( v5 >= 17.5 )
              {
                if ( v5 >= 22.5 )
                {
                  if ( v5 >= 27.5 )
                  {
                    if ( v5 >= 32.5 )
                    {
                      if ( v5 >= 37.5 )
                      {
                        if ( v5 >= 42.5 )
                        {
                          if ( v5 >= 47.5 )
                          {
                            if ( v5 >= 52.5 )
                            {
                              if ( a3 >= 75 )
                              {
                                if ( a3 >= 110 )
                                  v6 = (a3 >= 999) + 16;
                                else
                                  v6 = 15;
                              }
                              else
                              {
                                v6 = 14;
                              }
                            }
                            else
                            {
                              v6 = 13;
                            }
                          }
                          else
                          {
                            v6 = 12;
                          }
                        }
                        else
                        {
                          v6 = 11;
                        }
                      }
                      else
                      {
                        v6 = 10;
                      }
                    }
                    else
                    {
                      v6 = 9;
                    }
                  }
                  else
                  {
                    v6 = 8;
                  }
                }
                else
                {
                  v6 = 7;
                }
              }
              else
              {
                v6 = 6;
              }
            }
            else
            {
              v6 = 5;
            }
          }
          else
          {
            v6 = 4;
          }
        }
        else
        {
          v6 = 3;
        }
      }
      else
      {
        v6 = 2;
      }
    }
    else
    {
      v6 = 1;
    }
    *(_DWORD *)(a1 + 8) = v6;
    *(_DWORD *)(a1 + 12) = sub_414180(0);
    return 1;
  }
  return result;
}
