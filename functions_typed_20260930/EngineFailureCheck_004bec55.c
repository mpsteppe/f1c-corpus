// positive sp value has been detected, the output may be wrong!
BOOL __userpurge sub_4BEC55@<eax>(
        bool a1@<zf>,
        int a2@<ebx>,
        int a3@<ebp>,
        float *a4@<edi>,
        int a5@<esi>,
        int a6,
        float a7)
{
  int v7; // eax
  int v8; // edx
  int v9; // eax
  int v10; // ebx
  double v11; // st7
  double v12; // st6
  int v14; // [esp-1D4h] [ebp-1DCh]
  char v15; // [esp-1BAh] [ebp-1C2h]
  char v16; // [esp-1B9h] [ebp-1C1h]
  float v17; // [esp-1B8h] [ebp-1C0h]
  char v18; // [esp-1B4h] [ebp-1BCh]
  int v19; // [esp-1B0h] [ebp-1B8h]
  int v20; // [esp-1ACh] [ebp-1B4h]
  _DWORD v21[2]; // [esp-1A8h] [ebp-1B0h] BYREF
  char v22; // [esp-1A0h] [ebp-1A8h]

EngineFailureCheck:
  if ( a1 || a2 <= StateFlagsLookup((_DWORD *)a5) )
  {
    v8 = *(_DWORD *)((char *)a4 + v20);
    if ( *(_DWORD *)(v8 + 16484) != 1 )
    {
      v9 = *(_DWORD *)(a5 + 16484);
      if ( v9 != 3 && v9 != 2 )
      {
        v16 = 1;
        if ( *a4 < 0.0 )
          *a4 = RandomVariationScaler(a3, v8, a5, *(float *)(a3 + 844));
        if ( *a4 < (double)a4[104] )
        {
          v10 = AICollision(a5, 1.0);
          if ( v10 )
          {
            *(float *)&v14 = dbl_8AFEA0;
            ProgressBarEventEncode(v21, 4, 26, 1, *(_DWORD *)(a5 + 18580), v14, 0);
            if ( v10 == 1 )
            {
              v22 = 6;
            }
            else
            {
              v17 = flt_8AAE74[(unsigned __int8)dword_8AAE70++];
              if ( v17 >= 0.30000001 )
              {
                if ( v17 >= 0.44999999 )
                {
                  if ( v17 >= 0.60000002 )
                  {
                    if ( v17 >= 0.75 )
                    {
                      if ( v17 >= 0.88999999 )
                      {
                        if ( v17 >= 0.91000003 )
                        {
                          if ( v17 >= 0.93000001 )
                          {
                            v22 = 9;
                            if ( v17 >= 0.95999998 )
                              v22 = 0;
                          }
                          else
                          {
                            v22 = 8;
                          }
                        }
                        else
                        {
                          v22 = 7;
                        }
                      }
                      else
                      {
                        v22 = 5;
                      }
                    }
                    else
                    {
                      v22 = 4;
                    }
                  }
                  else
                  {
                    v22 = 3;
                  }
                }
                else
                {
                  v22 = 2;
                }
              }
              else
              {
                v22 = 1;
              }
            }
            PitCrewStateMachine((_BYTE **)(a5 + 16436), (int)v21);
          }
          else
          {
            v11 = a4[104] - *a4;
            ++*(_DWORD *)(a5 + 16444);
            v12 = *(float *)(a3 + 852) - v11;
            if ( v12 < 0.0 )
              v12 = 0.0;
            *(float *)(a5 + 16536) = v12;
            if ( *(float *)(a5 + 16540) <= 0.0 || *(float *)(a5 + 16540) > (double)*a4 )
              *(float *)(a5 + 16540) = *a4;
            *(float *)(a5 + 16568) = *(float *)(a3 + 852) - flt_8ACF90 - v11;
            AIDriverSorting(a5);
            if ( *(_DWORD *)(a5 + 16444) >= *(_DWORD *)(a3 + 860) || v18 )
            {
              if ( *(_DWORD *)(a5 + 16484) != 3 )
                *(_DWORD *)(a5 + 16484) = 1;
              if ( dword_7C56A4 == 7 )
                v15 = 0;
            }
            a4[104] = a4[104] - *a4;
          }
          *a4 = -1.0;
        }
      }
    }
  }
  while ( 1 )
  {
    ++a4;
    if ( !--v19 )
      break;
    a4[104] = *(float *)(a3 + 848) + a4[104];
    a5 = *(_DWORD *)((char *)a4 + v20);
    v7 = *(_DWORD *)(a5 + 13000);
    if ( v7 != -1 )
    {
      if ( v7 )
      {
        a2 = *(_DWORD *)(a5 + 16444);
        if ( a2 < *(_DWORD *)(a3 + 860) )
        {
          a1 = dword_7C56A4 == 7;
          goto EngineFailureCheck;
        }
      }
    }
  }
  dbl_8AFEA0 = dbl_8AFEA0 + *(float *)(a3 + 848);
  if ( !v15 || !v16 )
  {
    ((void (__thiscall *)(int))AITickUpdate)(a3);
    dbl_8AFEA0 = flt_8ACF90 + a7;
  }
  return v15 && v16;
}

