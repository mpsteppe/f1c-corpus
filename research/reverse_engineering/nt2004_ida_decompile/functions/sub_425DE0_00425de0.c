void __thiscall sub_425DE0(int this)
{
  int v2; // eax
  double v3; // st7
  double v4; // st7
  double v5; // st7
  double v6; // st7
  double v7; // st7
  double v8; // st7
  double v9; // st7
  float v10; // eax
  double v11; // st7
  double v12; // st7
  double v13; // st7
  double v14; // st7
  int v15; // edx
  int v16; // ecx
  float v17; // [esp+0h] [ebp-10h]
  float v18; // [esp+0h] [ebp-10h]
  float v19; // [esp+Ch] [ebp-4h]
  float v20; // [esp+Ch] [ebp-4h]

  v2 = *(_DWORD *)(this + 52);
  if ( v2 <= 0 )
  {
    if ( v2 < 0 )
      *(_DWORD *)(this + 24056) = 1084751872;
  }
  else
  {
    *(_DWORD *)(this + 24060) = 1084751872;
  }
  *(_DWORD *)(this + 23624) = *(_DWORD *)(this + 23716);
  if ( *(int *)(this + 23820) > 4 || !*(_BYTE *)(this + 24208) || *(_DWORD *)(*(_DWORD *)(this + 23432) + 328) )
  {
    v10 = *(float *)(this + 23636);
    *(_DWORD *)(this + 23632) = *(_DWORD *)(this + 23640);
    goto LABEL_43;
  }
  if ( *(float *)(this + 23632) >= 0.0
    || *(float *)(this + 23640) <= 0.0
    || (v3 = *(float *)(this + 23632) + 0.1, v3 >= *(float *)(this + 23640)) )
  {
    v4 = *(float *)(this + 23632) + 0.1;
    if ( v4 >= *(float *)(this + 23640) || *(float *)(this + 24732) >= (double)*(float *)(this + 24736) )
    {
      v5 = *(float *)(this + 23632) + 0.050000001;
      if ( v5 >= *(float *)(this + 23640) )
      {
        v6 = *(float *)(this + 23632) - 0.1;
        if ( v6 <= *(float *)(this + 23640) || *(float *)(this + 23628) >= 0.0 )
        {
          v7 = *(float *)(this + 23632) - 0.025;
          if ( v7 <= *(float *)(this + 23640) )
            *(_DWORD *)(this + 23632) = *(_DWORD *)(this + 23640);
          else
            *(float *)(this + 23632) = v7;
        }
        else
        {
          *(float *)(this + 23632) = v6;
        }
      }
      else
      {
        *(float *)(this + 23632) = v5;
      }
    }
    else
    {
      *(float *)(this + 23632) = v4;
    }
  }
  else
  {
    if ( v3 > 0.0 )
      v3 = 0.0;
    *(float *)(this + 23632) = v3;
  }
  if ( *(float *)(this + 23628) <= 0.0
    || *(float *)(this + 23636) >= 0.0
    || (v8 = *(float *)(this + 23628) - 0.1, v8 <= *(float *)(this + 23636)) )
  {
    v19 = *(float *)(this + 23628) + 0.1;
    if ( *(float *)(this + 23636) < (double)v19 && *(float *)(this + 24732) < (double)*(float *)(this + 24736) )
    {
      *(float *)(this + 23628) = *(float *)(this + 23628) - 0.1;
      goto LABEL_44;
    }
    v9 = *(float *)(this + 23628) - 0.050000001;
    if ( v9 > *(float *)(this + 23636) )
    {
      *(float *)(this + 23628) = v9;
      goto LABEL_44;
    }
    if ( *(float *)(this + 23636) <= (double)v19 || *(float *)(this + 23632) <= 0.0 )
    {
      v11 = *(float *)(this + 23628) + 0.025;
      if ( v11 >= *(float *)(this + 23636) )
        *(_DWORD *)(this + 23628) = *(_DWORD *)(this + 23636);
      else
        *(float *)(this + 23628) = v11;
      goto LABEL_44;
    }
    v10 = *(float *)(this + 23628) + 0.1;
LABEL_43:
    *(float *)(this + 23628) = v10;
    goto LABEL_44;
  }
  if ( v8 < 0.0 )
    v8 = 0.0;
  *(float *)(this + 23628) = v8;
LABEL_44:
  v17 = *(float *)(this + 23716) + *(float *)(this + 23632);
  sub_427C20(v17, 1);
  v18 = *(float *)(this + 23628) + *(float *)(this + 23716);
  sub_427B90(v18, 1);
  if ( *(float *)(this + 23644) >= (double)*(float *)(this + 23624) )
  {
    if ( *(float *)(this + 23648) <= (double)*(float *)(this + 23624) )
    {
      *(_DWORD *)(this + 23704) = 0;
    }
    else
    {
      *(_DWORD *)(this + 23704) = *(int *)(this + 24684) < 0;
      if ( *(_DWORD *)(this + 23820) )
        goto LABEL_63;
      v13 = 0.5 - (*(float *)(this + 23648) - *(float *)(this + 23624)) * 0.1;
      if ( v13 < 0.0 )
        v13 = 0.0;
      if ( *(float *)(this + 23764) <= 15.0 )
      {
LABEL_63:
        *(_DWORD *)(this + 23624) = *(_DWORD *)(this + 23648);
      }
      else
      {
        *(_DWORD *)(this + 23624) = *(_DWORD *)(this + 23648);
        *(float *)(this + 23740) = (v13 + 0.5) * *(float *)(this + 23740);
      }
    }
  }
  else
  {
    *(_DWORD *)(this + 23704) = *(int *)(this + 24684) > 0;
    if ( *(_DWORD *)(this + 23820) )
      goto LABEL_53;
    v12 = 0.5 - (*(float *)(this + 23624) - *(float *)(this + 23644)) * 0.1;
    if ( v12 < 0.0 )
      v12 = 0.0;
    if ( *(float *)(this + 23764) <= 15.0 )
    {
LABEL_53:
      *(_DWORD *)(this + 23624) = *(_DWORD *)(this + 23644);
    }
    else
    {
      *(_DWORD *)(this + 23624) = *(_DWORD *)(this + 23644);
      *(float *)(this + 23740) = (v12 + 0.5) * *(float *)(this + 23740);
    }
  }
  *(_DWORD *)(this + 23620) = *(_DWORD *)(this + 23624);
  if ( *(_BYTE *)(this + 24236) )
    *(_DWORD *)(this + 23620) = *(_DWORD *)(this + 23728);
  if ( *(float *)(this + 23724) != 0.0 )
  {
    v14 = *(float *)(this + 23724);
    v15 = *(_DWORD *)(this + 23828);
    *(float *)(this + 23620) = *(float *)(this + 23724);
    v20 = -*(float *)(*(_DWORD *)(this + 4 * v15 + 23432) + 156);
    if ( v14 < v20 )
      *(float *)(this + 23620) = v20;
    v16 = *(_DWORD *)(this + 4 * v15 + 23432);
    if ( *(float *)(this + 23620) > (double)*(float *)(v16 + 160) )
      *(_DWORD *)(this + 23620) = *(_DWORD *)(v16 + 160);
  }
  if ( *(float *)(this + 24132) > (double)*(float *)(this + 23852) )
    *(float *)(this + 23620) = *(float *)(this + 23620) + 0.5;
  if ( *(float *)(this + 23620) >= (double)*(float *)(this + 23676)
    || *(float *)(this + 23620) <= (double)*(float *)(this + 23680) )
  {
    *(_BYTE *)(this + 76) = 1;
  }
  *(_BYTE *)(this + 23872) = 0;
}
