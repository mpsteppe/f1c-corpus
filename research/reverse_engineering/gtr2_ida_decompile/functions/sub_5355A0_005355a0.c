int __thiscall sub_5355A0(int this, _BYTE *a2, int a3)
{
  double v4; // st7
  int v5; // ebx
  int i; // eax
  char *v7; // eax
  float *v8; // edi
  int v9; // esi
  int v10; // ebx
  int v11; // eax
  int v12; // ebx
  double v13; // st7
  double v14; // st6
  int j; // esi
  int k; // esi
  int v18; // [esp+0h] [ebp-380h]
  float v19; // [esp+8h] [ebp-378h]
  float v20; // [esp+8h] [ebp-378h]
  char v21; // [esp+1Ah] [ebp-366h]
  char v22; // [esp+1Bh] [ebp-365h]
  float v23; // [esp+1Ch] [ebp-364h]
  char v24; // [esp+20h] [ebp-360h]
  int v25; // [esp+24h] [ebp-35Ch]
  int v26; // [esp+2Ch] [ebp-354h]
  _DWORD v27[2]; // [esp+30h] [ebp-350h] BYREF
  char v28; // [esp+38h] [ebp-348h]

  *a2 = 0;
  v4 = *(float *)(this + 856);
  *(_DWORD *)(this + 860) = dword_FADE18;
  v5 = dword_757C10;
  v21 = 1;
  v22 = 0;
  v25 = dword_757C10;
  *(_DWORD *)(this + 864) = *(_DWORD *)dword_B640C8;
  v24 = 0;
  if ( v4 <= 0.0 || *(float *)(this + 852) < (double)*(float *)(this + 856) )
  {
    if ( *(_DWORD *)dword_B640C8 == 6 )
    {
      if ( dword_B64134 == 8 )
        v24 = 1;
      for ( i = 0; i < v5; ++i )
      {
        if ( *(_DWORD *)(*(&dword_91E088 + i) + 19380) == 1 )
          v24 = 1;
      }
    }
  }
  else
  {
    v24 = 1;
    v21 = 0;
  }
  if ( !*(_BYTE *)(this + 834) )
  {
    if ( dbl_FB1D18 < flt_FADE20 || *(_DWORD *)(this + 864) == 6 )
      sub_533A90(this, a3, v24);
    else
      v21 = 0;
  }
  *(float *)(this + 852) = *(float *)(this + 848) + *(float *)(this + 852);
  if ( !v21 )
  {
LABEL_68:
    sub_530E40((float *)this);
    dbl_FB1D18 = flt_FADE1C + *(float *)&a3;
LABEL_69:
    for ( j = 0; j < v5; ++j )
    {
      v19 = dbl_FB1D18;
      sub_552BC0(*(&dword_91E088 + j), v19);
    }
    if ( v21 )
    {
      if ( v22 )
        return 1;
    }
    else
    {
      for ( k = 0; k < v5; ++k )
      {
        v20 = dbl_FB1D18;
        sub_552BC0(*(&dword_91E088 + k), v20);
      }
    }
    return 0;
  }
  if ( v5 <= 0 )
  {
LABEL_67:
    dbl_FB1D18 = dbl_FB1D18 + *(float *)(this + 848);
    if ( v22 )
      goto LABEL_69;
    goto LABEL_68;
  }
  v7 = (char *)&dword_91E088 - this;
  v8 = (float *)this;
  v26 = v5;
  while ( 1 )
  {
    v8[104] = *(float *)(this + 848) + v8[104];
    v9 = *(_DWORD *)((char *)v8 + (_DWORD)v7);
    if ( *(_DWORD *)(v9 + 14820) != 1 )
      goto LABEL_66;
    v10 = *(_DWORD *)(v9 + 19284);
    if ( v10 < *(_DWORD *)(this + 860)
      && (*(_DWORD *)dword_B640C8 == 6 || v10 <= sub_41FCB0(*(_DWORD **)((char *)v8 + (_DWORD)v7)))
      && *(_DWORD *)(*(_DWORD *)((char *)v8 + (_DWORD)&dword_91E088 - this) + 19380) != 1 )
    {
      v11 = *(_DWORD *)(v9 + 19380);
      if ( v11 != 3 && v11 != 2 )
      {
        v22 = 1;
        if ( *v8 < 0.0 )
          *v8 = sub_530A70((_DWORD *)this, v9, *(float *)(this + 844));
        if ( *v8 < (double)v8[104] )
          break;
      }
    }
    v5 = v25;
LABEL_66:
    ++v8;
    if ( !--v26 )
      goto LABEL_67;
    v7 = (char *)&dword_91E088 - this;
  }
  v12 = sub_530BB0(this, v9, 1.0);
  if ( v12 )
  {
    *(float *)&v18 = dbl_FB1D18;
    sub_51B2A0(v27, 4, 24, 1, *(_DWORD *)(v9 + 22468), v18, 0);
    if ( v12 == 1 )
    {
      v28 = 6;
      sub_52BE90((_DWORD *)(v9 + 19272), (int)v27);
    }
    else
    {
      v23 = flt_BE08A4[(unsigned __int8)dword_BE08A0++];
      if ( v23 >= 0.30000001 )
      {
        if ( v23 >= 0.44999999 )
        {
          if ( v23 >= 0.60000002 )
          {
            if ( v23 >= 0.75 )
            {
              if ( v23 >= 0.88999999 )
              {
                if ( v23 >= 0.91000003 )
                {
                  if ( v23 >= 0.93000001 )
                  {
                    v28 = 9;
                    if ( v23 >= 0.95999998 )
                      v28 = 0;
                    sub_52BE90((_DWORD *)(v9 + 19272), (int)v27);
                  }
                  else
                  {
                    v28 = 8;
                    sub_52BE90((_DWORD *)(v9 + 19272), (int)v27);
                  }
                }
                else
                {
                  v28 = 7;
                  sub_52BE90((_DWORD *)(v9 + 19272), (int)v27);
                }
              }
              else
              {
                v28 = 5;
                sub_52BE90((_DWORD *)(v9 + 19272), (int)v27);
              }
            }
            else
            {
              v28 = 4;
              sub_52BE90((_DWORD *)(v9 + 19272), (int)v27);
            }
          }
          else
          {
            v28 = 3;
            sub_52BE90((_DWORD *)(v9 + 19272), (int)v27);
          }
        }
        else
        {
          v28 = 2;
          sub_52BE90((_DWORD *)(v9 + 19272), (int)v27);
        }
      }
      else
      {
        v28 = 1;
        sub_52BE90((_DWORD *)(v9 + 19272), (int)v27);
      }
    }
  }
  else
  {
    v13 = v8[104] - *v8;
    ++*(_DWORD *)(v9 + 19284);
    v14 = *(float *)(this + 852) - v13;
    if ( v14 < 0.0 )
      v14 = 0.0;
    *(float *)(v9 + 19432) = v14;
    if ( *(float *)(v9 + 19436) <= 0.0 || *v8 < (double)*(float *)(v9 + 19436) )
      *(float *)(v9 + 19436) = *v8;
    if ( *(float *)(v9 + 19436) <= 0.0 || *v8 < (double)*(float *)(v9 + 19448) )
      *(float *)(v9 + 19448) = *v8;
    *(float *)(v9 + 19464) = *(float *)(this + 852) - flt_FADE1C - v13;
    sub_530CE0(v9);
    if ( *(_DWORD *)(v9 + 19284) >= *(_DWORD *)(this + 860) && !byte_B722E4 || v24 || dbl_FB1D18 >= flt_FADE20 )
      sub_52D900((_DWORD *)(v9 + 19272));
    v8[104] = v8[104] - *v8;
  }
  return off_16C9230(a2, a3);
}
