int __thiscall sub_404250(int this)
{
  int v2; // eax
  int v3; // ebp
  int v4; // esi
  int v5; // ebx
  int v6; // esi
  int v7; // ebx
  int result; // eax
  bool v9; // cc
  int v10; // esi
  int v11; // ebx
  int v12; // esi
  int v13; // eax
  double v14; // st7
  double v15; // st6
  double v16; // st5
  double v17; // st4
  int v18; // ecx
  int v19; // eax
  int v20; // eax
  double v21; // st5
  int v22; // [esp+10h] [ebp-4h]

  v2 = *(_DWORD *)(this + 304);
  v3 = 0;
  v4 = 0;
  *(float *)(this + 368) = 1.0 - (flt_8AFEE8 + flt_8AFEEC) * 0.5;
  if ( v2 > 0 )
  {
    v5 = 0;
    do
    {
      sub_4FB260(*(float *)(this + 368));
      ++v4;
      v5 += 316;
    }
    while ( v4 < *(_DWORD *)(this + 304) );
  }
  v6 = 0;
  if ( *(int *)(this + 304) > 0 )
  {
    v7 = 0;
    do
    {
      sub_4FAF60(v7 + *(_DWORD *)(this + 308));
      ++v6;
      v7 += 316;
    }
    while ( v6 < *(_DWORD *)(this + 304) );
  }
  sub_4047D0(this);
  sub_4046B0(this);
  result = sub_404790(this);
  v9 = *(_DWORD *)(this + 304) <= 0;
  *(_DWORD *)(this + 372) = -1;
  v22 = 0;
  if ( !v9 )
  {
    do
    {
      v10 = *(_DWORD *)(this + 308);
      v11 = *(_DWORD *)(v10 + v3 + 300);
      v12 = v3 + v10;
      if ( v11 >= *(_DWORD *)(this + 16) )
      {
        v13 = sub_4038E0(dword_5EA2C0, (float *)v12, 1);
        if ( v13 )
        {
          v14 = *(float *)v12 - *(float *)v13;
          v15 = *(float *)(v12 + 8) - *(float *)(v13 + 8);
          v16 = *(float *)(v13 + 32);
          v17 = *(float *)(v13 + 40);
          *(_DWORD *)(v12 + 276) = v13;
          *(float *)(v12 + 24) = v17 * v15 + v16 * v14;
          v18 = *(_DWORD *)(v13 + 268);
          if ( v18 )
          {
            *(_DWORD *)(v12 + 296) = *(_DWORD *)(v18 + 292);
          }
          else
          {
            v19 = *(_DWORD *)(v13 + 272);
            if ( v19 )
              *(_DWORD *)(v12 + 296) = *(_DWORD *)(v19 + 288);
          }
        }
      }
      if ( v11 != 1 )
        goto LABEL_23;
      if ( *(_DWORD *)(v12 + 276) )
        goto LABEL_23;
      v20 = sub_4038E0(dword_5EA2C0, (float *)v12, 0);
      if ( !v20 )
        goto LABEL_23;
      v21 = *(float *)(v20 + 40) * (*(float *)(v12 + 8) - *(float *)(v20 + 8))
          + *(float *)(v20 + 32) * (*(float *)v12 - *(float *)v20);
      if ( v21 >= 0.0 )
      {
        if ( v21 >= *(float *)(v20 + 84) )
        {
LABEL_22:
          *(_DWORD *)(v12 + 276) = 0;
          *(_DWORD *)(v12 + 296) = -1;
          goto LABEL_23;
        }
        *(_DWORD *)(v12 + 276) = v20;
        *(_DWORD *)(v12 + 296) = *(_DWORD *)(*(_DWORD *)(v20 + 268) + 292);
      }
      else
      {
        if ( -v21 >= *(float *)(v20 + 80) )
          goto LABEL_22;
        *(_DWORD *)(v12 + 276) = v20;
        *(_DWORD *)(v12 + 296) = *(_DWORD *)(*(_DWORD *)(v20 + 268) + 292);
      }
LABEL_23:
      result = v22 + 1;
      v3 += 316;
      ++v22;
    }
    while ( v22 < *(_DWORD *)(this + 304) );
  }
  return result;
}
