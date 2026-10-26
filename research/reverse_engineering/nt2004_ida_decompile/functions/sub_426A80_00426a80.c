int __thiscall sub_426A80(int this)
{
  int result; // eax
  double v3; // st7
  double v4; // st7
  double v5; // st7
  char *v6; // ecx
  int v7; // eax
  const char *v8; // eax
  int v9; // ebx
  _DWORD *v10; // eax
  int v11; // ecx
  double v12; // st7
  double v13; // st7
  char *v14; // ecx
  int v15; // eax
  int v16; // ebp
  int *v17; // edi
  int i; // ecx
  _DWORD *v19; // edx
  int v20; // eax
  int v21; // ecx
  float *v22; // eax
  double v23; // st7
  int v24; // edx
  int v25; // ecx
  int v26; // eax
  int v27; // edx
  double v28; // st7
  int v29; // ecx
  float *v30; // eax
  int v31; // eax
  int v32; // ebp
  _DWORD *v33; // edi
  double v34; // st7
  int v35; // ecx
  float *v36; // eax
  char v37; // al
  float v38; // [esp+14h] [ebp-28h]
  float v39; // [esp+14h] [ebp-28h]
  float v40; // [esp+14h] [ebp-28h]
  int v41; // [esp+14h] [ebp-28h]
  int v42; // [esp+14h] [ebp-28h]
  float v43; // [esp+14h] [ebp-28h]
  int v44; // [esp+18h] [ebp-24h]
  char v45[3]; // [esp+1Ch] [ebp-20h] BYREF
  char Buffer[29]; // [esp+1Fh] [ebp-1Dh] BYREF

  result = dword_75CBB0;
  if ( dword_75CBB0 == 8 )
  {
    v3 = *(float *)(this + 18804);
    *(_DWORD *)(this + 24496) = 0;
    *(_DWORD *)(this + 24504) = 999;
    v4 = v3 * flt_6290E0;
    *(_DWORD *)(this + 24584) = 0;
    *(float *)(this + 24592) = v4;
    v5 = *(float *)(this + 24592) * 5.0;
    if ( v5 < 1.0 )
      v5 = 1.0;
    v38 = v5;
    *(float *)(this + 24600) = v5;
    return sub_51E4A0(LODWORD(v38));
  }
  else if ( *(_DWORD *)(*(_DWORD *)(this + 80) + 16584) == 1 )
  {
    *(_DWORD *)(this + 24608) = -1;
    *(_DWORD *)(this + 24604) = 0;
    if ( sub_57AE50(aSeasonraces) )
    {
      v6 = dword_766594;
      if ( !dword_766594 )
        v6 = &byte_629120;
      if ( sub_57A720(v6) )
      {
        v7 = sub_57A720(aPitwindow);
        if ( v7 )
        {
          v8 = (const char *)sub_57A6D0(v7);
          v9 = atol(v8);
          *(_DWORD *)(this + 24608) = v9 + rand() % 3 - 1;
        }
      }
    }
    if ( *(_DWORD *)dword_76926C != 1 || *(_DWORD *)dword_7693B0 != 1 )
      *(_DWORD *)(this + 24608) = -1;
    v10 = (_DWORD *)(this + 24512);
    v11 = 5;
    do
    {
      *(v10 - 2) = dword_7D74B8;
      *v10 = 1;
      *(v10 - 1) = 1176256410;
      v10[1] = 0;
      v10 += 4;
      --v11;
    }
    while ( v11 );
    *(float *)(this + 24592) = (double)*(int *)dword_76926C * *(float *)(this + 24592) * 1.05;
    v12 = *(float *)(this + 18804) * flt_6290E0;
    if ( v12 < 1.0 )
      v12 = 1.0;
    *(float *)(this + 24592) = v12;
    v39 = (double)*(int *)dword_76926C * 1.2;
    if ( v12 < v39 )
    {
      if ( v39 >= 1.0 )
        v13 = v39;
      else
        v13 = 1.0;
      *(float *)(this + 24592) = v13;
    }
    *(_DWORD *)(this + 24584) = 0;
    *(_DWORD *)(this + 24600) = 1176255488;
    if ( dword_75CBB0 == 7 )
    {
      if ( sub_57AE50(aSeasonraces) )
      {
        v14 = dword_766594;
        if ( !dword_766594 )
          v14 = &byte_629120;
        if ( sub_57A720(v14) )
        {
          if ( sub_57A720(aPitstopstrateg) )
          {
            v15 = sub_57A720((char *)(*(_DWORD *)(this + 80) + 24772));
            if ( v15 )
            {
              strcpy(v45, (const char *)sub_57A6D0(v15));
              v40 = (float)*(int *)dword_76926C;
              switch ( v45[0] )
              {
                case '1':
                  *(_DWORD *)(this + 24496) = v45[0] - 48;
                  sscanf(Buffer, "%d", this + 24504);
                  *(_DWORD *)(this + 24520) = dword_7D74B8;
                  break;
                case '2':
                  *(_DWORD *)(this + 24496) = 2;
                  sscanf(Buffer, "%d,%d", this + 24504, this + 24520);
                  *(_DWORD *)(this + 24536) = dword_7D74B8;
                  break;
                case '3':
                  *(_DWORD *)(this + 24496) = 3;
                  sscanf(Buffer, "%d,%d,%d", this + 24504, this + 24520, this + 24536);
                  *(_DWORD *)(this + 24552) = dword_7D74B8;
                  break;
                default:
                  *(_DWORD *)(this + 24496) = 4;
                  sscanf(Buffer, "%d,%d,%d,%d", this + 24504, this + 24520, this + 24536, this + 24552);
                  *(_DWORD *)(this + 24568) = dword_7D74B8;
                  break;
              }
              v16 = 0;
              if ( *(int *)(this + 24496) > 0 )
              {
                v17 = (int *)(this + 24504);
                do
                {
                  *v17 = (__int64)((double)*v17 * (1.0 / v40));
                  ++v16;
                  v17 += 4;
                }
                while ( v16 < *(_DWORD *)(this + 24496) );
              }
              for ( i = 0; i < *(_DWORD *)(this + 24496); ++i )
              {
                v19 = (_DWORD *)(16 * i + this + 24504);
                if ( *v19 > dword_7D74B8 - 5 )
                {
                  *(_DWORD *)(this + 24496) = i;
                  if ( i < 5 )
                  {
                    v20 = 5 - i;
                    i = 5;
                    do
                    {
                      *v19 = dword_7D74B8;
                      v19 += 4;
                      --v20;
                    }
                    while ( v20 );
                  }
                }
              }
              v21 = 0;
              if ( *(int *)(this + 24496) > 0 )
              {
                v22 = (float *)(this + 24504);
                do
                {
                  v41 = *((_DWORD *)v22 + 4) - *(_DWORD *)v22;
                  ++v21;
                  v22 += 4;
                  *(v22 - 3) = (double)v41 * *(float *)(this + 24592);
                }
                while ( v21 < *(_DWORD *)(this + 24496) );
              }
            }
          }
        }
      }
      if ( !*(_DWORD *)dword_76926C && !*(_DWORD *)dword_7693B0 )
      {
        *(_DWORD *)(this + 24496) = 0;
        *(_DWORD *)(this + 24504) = dword_7D74B8;
      }
      *(_DWORD *)(16 * *(_DWORD *)(this + 24496) + this + 24516) = 8;
    }
    else
    {
      switch ( dword_75CBB0 )
      {
        case 0:
        case 1:
        case 2:
        case 6:
          v31 = (rand() % 2 != 0) + 3;
          v32 = 0;
          *(_DWORD *)(this + 24496) = v31;
          v43 = 0.0;
          if ( v31 > 0 )
          {
            v33 = (_DWORD *)(this + 24516);
            do
            {
              v34 = (double)(rand() % 5 + 3) + v43;
              v43 = v34;
              *(v33 - 3) = (__int64)v34;
              *v33 = 8;
              ++v32;
              v33 += 4;
            }
            while ( v32 < *(_DWORD *)(this + 24496) );
          }
          v35 = 0;
          if ( *(int *)(this + 24496) > 0 )
          {
            v36 = (float *)(this + 24504);
            do
            {
              v44 = *((_DWORD *)v36 + 4) - *(_DWORD *)v36;
              ++v35;
              v36 += 4;
              *(v36 - 3) = ((double)v44 + 2.0) * *(float *)(this + 24592);
            }
            while ( v35 < *(_DWORD *)(this + 24496) );
          }
          break;
        case 3:
        case 4:
          v24 = (rand() % 25 != 0) + 3;
          v25 = 0;
          *(_DWORD *)(this + 24496) = v24;
          if ( v24 > 0 )
          {
            v26 = this + 24508;
            v27 = 11;
            do
            {
              *(_DWORD *)(v26 - 4) = v27;
              v28 = *(float *)(this + 24592) * 14.0;
              *(_DWORD *)(v26 + 8) = 8;
              ++v25;
              v27 += 12;
              *(float *)v26 = v28;
              v26 += 16;
            }
            while ( v25 < *(_DWORD *)(this + 24496) );
          }
          v29 = 0;
          if ( *(int *)(this + 24496) > 0 )
          {
            v30 = (float *)(this + 24504);
            do
            {
              v42 = *((_DWORD *)v30 + 4) - *(_DWORD *)v30;
              ++v29;
              v30 += 4;
              *(v30 - 3) = ((double)v42 + 2.0) * *(float *)(this + 24592);
            }
            while ( v29 < *(_DWORD *)(this + 24496) );
          }
          break;
        case 5:
          v23 = *(float *)(this + 24592);
          *(_DWORD *)(this + 24496) = 0;
          *(_DWORD *)(this + 24504) = 3;
          *(_DWORD *)(this + 24516) = 8;
          *(float *)(this + 24508) = v23 * 5.0;
          break;
        default:
          break;
      }
    }
    if ( *(int *)(this + 24504) < 1 )
      *(_DWORD *)(this + 24504) = 1;
    *(float *)(this + 24600) = ((double)*(int *)(this + 24504) + 2.0) * *(float *)(this + 24592);
    if ( !*(_DWORD *)dword_76926C )
      *(_DWORD *)(this + 24600) = 1065353216;
    if ( *(float *)(this + 18796) < (double)*(float *)(this + 24600) )
      *(float *)(this + 24600) = *(float *)(this + 18796);
    if ( dword_75CBB0 == 7 )
      sub_51E4A0(*(float *)(this + 18796));
    else
      sub_51E4A0(*(_DWORD *)(this + 24600));
    *(_DWORD *)(this + 24500) = 7;
    v37 = sub_427140(this);
    return sub_51E670(v37, 1);
  }
  return result;
}
