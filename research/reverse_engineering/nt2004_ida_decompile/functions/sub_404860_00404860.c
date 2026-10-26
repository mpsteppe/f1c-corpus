int __thiscall sub_404860(int this)
{
  double v1; // st7
  int v3; // eax
  int v4; // esi
  int v5; // ebx
  int v6; // ecx
  double v7; // st7
  int v8; // ecx
  int v9; // esi
  int v10; // ebx
  bool v11; // cc
  int v12; // esi
  int v13; // ebx
  int v14; // esi
  int v15; // eax
  double v16; // st7
  double v17; // st6
  double v18; // st5
  double v19; // st4
  int v20; // ecx
  int v21; // eax
  int v22; // eax
  double v23; // st5
  int v25; // [esp+10h] [ebp-8h]
  int v26; // [esp+14h] [ebp-4h]

  v1 = (double)dword_7D74B8 * (double)(int)NumOfElements;
  *(_DWORD *)(this + 32) = 0;
  *(_DWORD *)(this + 20) = 1061997773;
  *(float *)(this + 28) = v1;
  *(_DWORD *)(this + 24) = 1101004800;
  switch ( dword_7D7928 )
  {
    case 3:
      *(_DWORD *)(this + 20) = 1061997773;
LABEL_7:
      *(_DWORD *)(this + 24) = 1097859072;
      break;
    case 1:
      *(_DWORD *)(this + 20) = 1063675494;
      *(_DWORD *)(this + 24) = 1099956224;
      break;
    case 2:
      *(_DWORD *)(this + 20) = 1056964608;
      goto LABEL_7;
  }
  v3 = *(_DWORD *)(this + 356);
  v4 = 0;
  *(float *)(this + 440) = 1.0 - (flt_7DAB04 + flt_7DAB08) * 0.5;
  if ( v3 > 0 )
  {
    v5 = 0;
    do
    {
      v6 = *(_DWORD *)(this + 360);
      v7 = *(float *)(v6 + v5 + 96);
      v8 = v5 + v6;
      if ( v7 < 3.4028235e38 )
        *(_DWORD *)(v8 + 96) = -1082130432;
      sub_528FF0(*(float *)(this + 440));
      ++v4;
      v5 += 348;
    }
    while ( v4 < *(_DWORD *)(this + 356) );
  }
  v9 = 0;
  if ( *(int *)(this + 356) > 0 )
  {
    v10 = 0;
    do
    {
      sub_528C20(v10 + *(_DWORD *)(this + 360));
      ++v9;
      v10 += 348;
    }
    while ( v9 < *(_DWORD *)(this + 356) );
  }
  sub_404E90(this);
  sub_404D70(this);
  sub_404E50(this);
  v11 = *(_DWORD *)(this + 356) <= 0;
  *(_DWORD *)(this + 444) = -1;
  v26 = 0;
  if ( !v11 )
  {
    v25 = 0;
    do
    {
      v12 = *(_DWORD *)(this + 360);
      v13 = *(_DWORD *)(v12 + v25 + 328);
      v14 = v25 + v12;
      if ( v13 >= *(_DWORD *)(this + 72) )
      {
        v15 = sub_403FD0(&flt_628F60, (float *)v14, *(_DWORD *)(v14 + 100));
        if ( v15 )
        {
          v16 = *(float *)v14 - *(float *)v15;
          v17 = *(float *)(v14 + 8) - *(float *)(v15 + 8);
          v18 = *(float *)(v15 + 44);
          v19 = *(float *)(v15 + 52);
          *(_DWORD *)(v14 + 300) = v15;
          *(float *)(v14 + 24) = v19 * v17 + v18 * v16;
          v20 = *(_DWORD *)(v15 + 292);
          if ( v20 )
          {
            *(_DWORD *)(v14 + 324) = *(_DWORD *)(v20 + 320);
          }
          else
          {
            v21 = *(_DWORD *)(v15 + 296);
            if ( v21 )
              *(_DWORD *)(v14 + 324) = *(_DWORD *)(v21 + 316);
          }
        }
      }
      if ( v13 != 1 )
        goto LABEL_35;
      if ( *(_DWORD *)(v14 + 300) )
        goto LABEL_35;
      v22 = sub_403FD0(&flt_628F60, (float *)v14, 0);
      if ( !v22 )
        goto LABEL_35;
      v23 = *(float *)(v22 + 52) * (*(float *)(v14 + 8) - *(float *)(v22 + 8))
          + *(float *)(v22 + 44) * (*(float *)v14 - *(float *)v22);
      if ( v23 >= 0.0 )
      {
        if ( v23 >= *(float *)(v22 + 72) || !*(_DWORD *)(v22 + 292) )
        {
LABEL_34:
          *(_DWORD *)(v14 + 300) = 0;
          *(_DWORD *)(v14 + 324) = -1;
          goto LABEL_35;
        }
        *(_DWORD *)(v14 + 300) = v22;
        *(_DWORD *)(v14 + 324) = *(_DWORD *)(*(_DWORD *)(v22 + 292) + 320);
      }
      else
      {
        if ( -v23 >= *(float *)(v22 + 68) || !*(_DWORD *)(v22 + 292) )
          goto LABEL_34;
        *(_DWORD *)(v14 + 300) = v22;
        *(_DWORD *)(v14 + 324) = *(_DWORD *)(*(_DWORD *)(v22 + 292) + 320);
      }
LABEL_35:
      v11 = ++v26 < *(_DWORD *)(this + 356);
      v25 += 348;
    }
    while ( v11 );
  }
  return sub_405080(this);
}
