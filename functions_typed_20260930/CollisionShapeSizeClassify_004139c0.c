int __stdcall sub_4139C0(int a1, int a2, int a3, char a4)
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
                                  v6 = (a3 >= 999) + 47;
                                else
                                  v6 = 46;
                              }
                              else
                              {
                                v6 = 45;
                              }
                            }
                            else
                            {
                              v6 = 44;
                            }
                          }
                          else
                          {
                            v6 = 43;
                          }
                        }
                        else
                        {
                          v6 = 42;
                        }
                      }
                      else
                      {
                        v6 = 41;
                      }
                    }
                    else
                    {
                      v6 = 40;
                    }
                  }
                  else
                  {
                    v6 = 39;
                  }
                }
                else
                {
                  v6 = 38;
                }
              }
              else
              {
                v6 = 37;
              }
            }
            else
            {
              v6 = 36;
            }
          }
          else
          {
            v6 = 35;
          }
        }
        else
        {
          v6 = 34;
        }
      }
      else
      {
        v6 = 33;
      }
    }
    else
    {
      v6 = 32;
    }
    *(_DWORD *)(a1 + 8) = v6;
    *(_DWORD *)(a1 + 12) = sub_414180(0);
    return 1;
  }
  return result;
}

