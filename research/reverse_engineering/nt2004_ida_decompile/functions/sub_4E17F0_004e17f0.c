BOOL __thiscall sub_4E17F0(int this, int a2, float a3)
{
  char v4; // al
  int v5; // edi
  double v6; // st7
  int i; // eax
  int v8; // esi
  float *v9; // edi
  int v10; // esi
  int v11; // eax
  int v12; // ebp
  int v13; // eax
  int v14; // ebp
  double v15; // st7
  int v16; // esi
  int v18; // [esp+0h] [ebp-100h]
  char v19; // [esp+19h] [ebp-E7h]
  char v20; // [esp+1Ah] [ebp-E6h]
  char v21; // [esp+1Bh] [ebp-E5h]
  float v22; // [esp+1Ch] [ebp-E4h]
  float v23; // [esp+1Ch] [ebp-E4h]
  int v24; // [esp+20h] [ebp-E0h]
  int v25; // [esp+24h] [ebp-DCh]
  char *v26; // [esp+28h] [ebp-D8h]
  float v27; // [esp+2Ch] [ebp-D4h]
  _DWORD v28[2]; // [esp+30h] [ebp-D0h] BYREF
  char v29; // [esp+38h] [ebp-C8h]

  *(_DWORD *)(this + 416) = dword_7D74B8;
  v4 = *(_BYTE *)(this + 386);
  v5 = NumOfElements;
  v19 = 1;
  v20 = 0;
  v24 = NumOfElements;
  *(_DWORD *)(this + 420) = dword_75CBB0;
  if ( !v4 )
    sub_4E1E60(LODWORD(a3));
  v21 = 0;
  v6 = *(float *)(this + 404) + *(float *)(this + 408);
  *(float *)(this + 408) = v6;
  if ( *(float *)(this + 412) > 0.0 && v6 >= *(float *)(this + 412) )
  {
    v19 = 0;
LABEL_77:
    sub_4E22F0(this);
    dbl_7DA9D0 = flt_7D74BC + a3;
    return v19 && v20;
  }
  v27 = ((double)(rand() % 6) + 85.0) * 0.0099999998;
  if ( dword_75CBB0 == 7 )
  {
    for ( i = 0; i < v5; ++i )
    {
      if ( *(_DWORD *)(dword_75AAD0[i] + 20892) == 1 )
        v21 = 1;
    }
  }
  if ( *(_DWORD *)(this + 424) == -1 )
  {
    v8 = 0;
    if ( v5 <= 0 )
      goto LABEL_62;
    do
    {
      if ( *(_DWORD *)(this + 428) + sub_4DEBD0((_DWORD *)(dword_75AAD0[v8] + 20836)) <= *(_DWORD *)(this + 416) )
        *(_DWORD *)(this + 428) += sub_4DEBD0((_DWORD *)(dword_75AAD0[v8] + 20836));
      ++v8;
    }
    while ( v8 < v5 );
  }
  if ( v5 > 0 )
  {
    v26 = (char *)dword_75AAD0 - this;
    v9 = (float *)this;
    v25 = v24;
    do
    {
      v10 = *(_DWORD *)((char *)v9 + (_DWORD)v26);
      v11 = *(_DWORD *)(v10 + 16584);
      if ( v11 != -1 )
      {
        if ( v11 )
        {
          v12 = *(_DWORD *)(v10 + 20848);
          if ( v12 < *(_DWORD *)(this + 416)
            && (dword_75CBB0 == 7 || v12 <= sub_428070(*(_DWORD **)((char *)v9 + (_DWORD)v26)))
            && *(_DWORD *)(*(_DWORD *)((char *)v9 + (_DWORD)v26) + 20892) != 1 )
          {
            v13 = *(_DWORD *)(v10 + 20892);
            if ( v13 != 3 && v13 != 2 )
            {
              v20 = 1;
              v9[48] = v9[48] + *(float *)(this + 404);
              if ( *v9 < 0.0 )
                *v9 = sub_4E1500(this, v10, *(float *)(this + 396));
              if ( *v9 < (double)v9[48] )
              {
                v14 = sub_4E1D40(v10, 1.0);
                if ( v14 )
                {
                  *(float *)&v18 = dbl_7DA9D0;
                  sub_4D0D00(v28, 4, 26, 1, *(_DWORD *)(v10 + 25248), v18, 0);
                  if ( v14 == 1 )
                  {
                    v29 = 6;
                  }
                  else
                  {
                    v22 = flt_7D3C54[(unsigned __int8)dword_7D3C50++];
                    if ( v22 >= 0.30000001 )
                    {
                      if ( v22 >= 0.44999999 )
                      {
                        if ( v22 >= 0.60000002 )
                        {
                          if ( v22 >= 0.75 )
                          {
                            if ( v22 >= 0.89999998 )
                            {
                              v29 = 8;
                              if ( v22 >= 0.94 )
                                v29 = 0;
                            }
                            else
                            {
                              v29 = 5;
                            }
                          }
                          else
                          {
                            v29 = 4;
                          }
                        }
                        else
                        {
                          v29 = 3;
                        }
                      }
                      else
                      {
                        v29 = 2;
                      }
                    }
                    else
                    {
                      v29 = 1;
                    }
                  }
                  sub_4DCA90((_DWORD *)(v10 + 20836), (int)v28);
                }
                else
                {
                  v23 = v9[48] - *v9;
                  if ( dword_75CBB0 == 7
                    && *(_DWORD *)(v10 + 20848) == *(_DWORD *)(this + 416) - 1
                    && (double)v24 * v27 <= (double)*(int *)(v10 + 20884) )
                  {
                    sub_4DC390((_DWORD *)(v10 + 20836));
                  }
                  else
                  {
                    ++*(_DWORD *)(v10 + 20848);
                  }
                  v15 = *(float *)(this + 408) - v23;
                  if ( v15 < 0.0 )
                    v15 = 0.0;
                  *(float *)(v10 + 20956) = v15;
                  if ( *(float *)(v10 + 20960) <= 0.0 || *(float *)(v10 + 20960) > (double)*v9 )
                    *(float *)(v10 + 20960) = *v9;
                  *(float *)(v10 + 20988) = *(float *)(this + 408) - v23;
                  sub_4E2190(v10);
                  if ( *(_DWORD *)(v10 + 20848) > *(_DWORD *)(this + 416) || v21 )
                  {
                    sub_4DC390((_DWORD *)(v10 + 20836));
                    if ( dword_75CBB0 == 7 )
                      v19 = 0;
                  }
                  v9[48] = v9[48] - *v9;
                }
                *v9 = -1.0;
              }
            }
          }
        }
      }
      ++v9;
      --v25;
    }
    while ( v25 );
  }
LABEL_62:
  if ( dword_75CBB0 == 7 )
  {
    v16 = 0;
    if ( *(_DWORD *)(this + 424) == -1 )
    {
      if ( v24 > 0 )
      {
        do
        {
          if ( *(_DWORD *)(dword_75AAD0[v16] + 20884) == 1 && (unsigned __int8)sub_4FAE50(dword_75AAD0[v16]) )
            ++*(_DWORD *)(dword_75AAD0[v16] + 21008);
          ++v16;
        }
        while ( v16 < v24 );
      }
    }
    else if ( v24 > 0 )
    {
      do
      {
        if ( *(_DWORD *)(dword_75AAD0[v16] + 20884) == 1 && (unsigned __int8)sub_4FAE50(dword_75AAD0[v16]) )
          ++*(_DWORD *)(dword_75AAD0[v16] + 21008);
        ++v16;
      }
      while ( v16 < v24 );
    }
  }
  dbl_7DA9D0 = dbl_7DA9D0 + *(float *)(this + 404);
  if ( !v19 || !v20 )
    goto LABEL_77;
  return v19 && v20;
}
