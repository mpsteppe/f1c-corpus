void __thiscall sub_4EF5B0(float *this)
{
  int v2; // esi
  int v3; // eax
  double v4; // st7
  int v5; // esi
  int v6; // eax
  int v7; // esi
  int v8; // eax
  int v9; // esi
  int v10; // eax
  int v11; // esi
  int v12; // eax
  int v13; // esi
  int v14; // eax
  double v15; // st7
  int v16; // esi
  int v17; // eax
  int v18; // ecx
  int v19; // eax
  int v20; // esi
  int v21; // eax
  int v22; // esi
  int v23; // eax
  double v24; // st7
  int v25; // esi
  int v26; // eax
  int v27; // ecx
  int v28; // esi
  int v29; // eax
  int v30; // edx
  int v31; // esi
  int v32; // eax
  float v33; // [esp+78h] [ebp-20h]
  float v34; // [esp+7Ch] [ebp-1Ch]
  int v35; // [esp+80h] [ebp-18h] BYREF
  int v36; // [esp+84h] [ebp-14h]
  int v37; // [esp+88h] [ebp-10h]
  int v38; // [esp+8Ch] [ebp-Ch] BYREF
  int v39; // [esp+90h] [ebp-8h]
  int v40; // [esp+94h] [ebp-4h]

  if ( flt_B70A44 != 0.0 )
  {
    if ( dword_B6B828 )
    {
      if ( !byte_B6F118 && *(_DWORD *)dword_B72314 != 7 && *(_DWORD *)dword_B72314 != 8 && flt_B6F370 == 3.4028235e38 )
      {
        v2 = 0;
        while ( 1 )
        {
          v3 = dword_B6F1C8[v2];
          if ( v3 )
          {
            if ( (*(int (**)(void))(*(_DWORD *)v3 + 28))() != 2 )
              break;
          }
          if ( ++v2 >= 81 )
          {
            if ( dword_B6F220 )
            {
              v38 = 0;
              v39 = 0;
              v40 = 0;
              v35 = 0;
              v36 = 0;
              v37 = 0;
              (*(void (__thiscall **)(int, int, int *, int *, _DWORD, int, _DWORD))(*(_DWORD *)dword_B6F220 + 4))(
                dword_B6F220,
                2,
                &v38,
                &v35,
                LODWORD(flt_B70A44),
                1065353216,
                0);
            }
            break;
          }
        }
      }
      v4 = flt_BE08A4[(unsigned __int8)dword_BE08A0++] * 4.0;
      this[95] = v4 + dbl_FB1D18;
    }
    if ( *((_DWORD *)this + 95) != 2139095039 && dbl_FB1D18 > this[95] )
    {
      if ( rand() % 10 == 5 )
      {
        if ( !byte_B6F118
          && flt_B70A44 != 0.0
          && *(_DWORD *)dword_B72314 != 7
          && *(_DWORD *)dword_B72314 != 8
          && flt_B6F370 == 3.4028235e38 )
        {
          v5 = 0;
          while ( 1 )
          {
            v6 = dword_B6F1C8[v5];
            if ( v6 )
            {
              if ( (*(int (**)(void))(*(_DWORD *)v6 + 28))() != 2 )
                break;
            }
            if ( ++v5 >= 81 )
            {
              if ( dword_B6F2E8 )
              {
                v35 = 0;
                v36 = 0;
                v37 = 0;
                v38 = 0;
                v39 = 0;
                v40 = 0;
                (*(void (__thiscall **)(int, int, int *, int *, _DWORD, int, _DWORD))(*(_DWORD *)dword_B6F2E8 + 4))(
                  dword_B6F2E8,
                  2,
                  &v35,
                  &v38,
                  LODWORD(flt_B70A44),
                  1065353216,
                  0);
              }
              break;
            }
          }
        }
      }
      else
      {
        v7 = *(_DWORD *)(dword_91E084 + 15576);
        sub_4FF740(dword_91E084 + 14824);
        v8 = *(_DWORD *)(dword_91E084 + 15576);
        if ( v7 != v8 )
        {
          if ( v8 == 1 )
          {
            if ( !byte_B6F118
              && flt_B70A44 != 0.0
              && *(_DWORD *)dword_B72314 != 7
              && *(_DWORD *)dword_B72314 != 8
              && flt_B6F370 == 3.4028235e38 )
            {
              v9 = 0;
              while ( 1 )
              {
                v10 = dword_B6F1C8[v9];
                if ( v10 )
                {
                  if ( (*(int (**)(void))(*(_DWORD *)v10 + 28))() != 2 )
                    break;
                }
                if ( ++v9 >= 81 )
                {
                  if ( dword_B6F1F8 )
                  {
                    v35 = 0;
                    v36 = 0;
                    v37 = 0;
                    v38 = 0;
                    v39 = 0;
                    v40 = 0;
                    (*(void (__thiscall **)(int, int, int *, int *, _DWORD, int, _DWORD))(*(_DWORD *)dword_B6F1F8 + 4))(
                      dword_B6F1F8,
                      2,
                      &v35,
                      &v38,
                      LODWORD(flt_B70A44),
                      1065353216,
                      0);
                  }
                  break;
                }
              }
            }
            sub_421A90((_DWORD *)dword_91E084);
          }
          else if ( !v8 )
          {
            if ( !byte_B6F118
              && flt_B70A44 != 0.0
              && *(_DWORD *)dword_B72314 != 7
              && *(_DWORD *)dword_B72314 != 8
              && flt_B6F370 == 3.4028235e38 )
            {
              v11 = 0;
              while ( 1 )
              {
                v12 = dword_B6F1C8[v11];
                if ( v12 )
                {
                  if ( (*(int (**)(void))(*(_DWORD *)v12 + 28))() != 2 )
                    break;
                }
                if ( ++v11 >= 81 )
                {
                  if ( dword_B6F25C )
                  {
                    v35 = 0;
                    v36 = 0;
                    v37 = 0;
                    v38 = 0;
                    v39 = 0;
                    v40 = 0;
                    (*(void (__thiscall **)(int, int, int *, int *, _DWORD, int, _DWORD))(*(_DWORD *)dword_B6F25C + 4))(
                      dword_B6F25C,
                      2,
                      &v35,
                      &v38,
                      LODWORD(flt_B70A44),
                      1065353216,
                      0);
                  }
                  break;
                }
              }
            }
            sub_421B30();
          }
        }
      }
      this[95] = 3.4028235e38;
    }
    if ( dword_B6B7D0 )
    {
      if ( !byte_B6F118
        && flt_B70A44 != 0.0
        && *(_DWORD *)dword_B72314 != 7
        && *(_DWORD *)dword_B72314 != 8
        && flt_B6F370 == 3.4028235e38 )
      {
        v13 = 0;
        while ( 1 )
        {
          v14 = dword_B6F1C8[v13];
          if ( v14 )
          {
            if ( (*(int (**)(void))(*(_DWORD *)v14 + 28))() != 2 )
              break;
          }
          if ( ++v13 >= 81 )
          {
            if ( dword_B6F220 )
            {
              v35 = 0;
              v36 = 0;
              v37 = 0;
              v38 = 0;
              v39 = 0;
              v40 = 0;
              (*(void (__thiscall **)(int, int, int *, int *, _DWORD, int, _DWORD))(*(_DWORD *)dword_B6F220 + 4))(
                dword_B6F220,
                2,
                &v35,
                &v38,
                LODWORD(flt_B70A44),
                1065353216,
                0);
            }
            break;
          }
        }
      }
      v15 = flt_BE08A4[(unsigned __int8)dword_BE08A0++] * 4.0;
      this[93] = v15 + dbl_FB1D18;
    }
    if ( *((_DWORD *)this + 93) != 2139095039 && dbl_FB1D18 > this[93] )
    {
      if ( *(_DWORD *)dword_B640C8 == 6 )
      {
        if ( rand() % 10 == 5 )
        {
          if ( !byte_B6F118
            && flt_B70A44 != 0.0
            && *(_DWORD *)dword_B72314 != 7
            && *(_DWORD *)dword_B72314 != 8
            && flt_B6F370 == 3.4028235e38 )
          {
            v16 = 0;
            while ( 1 )
            {
              v17 = dword_B6F1C8[v16];
              if ( v17 )
              {
                if ( (*(int (**)(void))(*(_DWORD *)v17 + 28))() != 2 )
                  break;
              }
              if ( ++v16 >= 81 )
              {
                v18 = dword_B6F2E8;
                goto LABEL_95;
              }
            }
          }
        }
        else
        {
          v19 = *(_DWORD *)(dword_91E084 + 19324);
          if ( v19 > 10 )
          {
            if ( !byte_B6F118
              && flt_B70A44 != 0.0
              && *(_DWORD *)dword_B72314 != 7
              && *(_DWORD *)dword_B72314 != 8
              && flt_B6F370 == 3.4028235e38 )
            {
              v20 = 0;
              while ( 1 )
              {
                v21 = dword_B6F1C8[v20];
                if ( v21 )
                {
                  if ( (*(int (**)(void))(*(_DWORD *)v21 + 28))() != 2 )
                    break;
                }
                if ( ++v20 >= 81 )
                {
                  v18 = dword_B6F218;
LABEL_95:
                  if ( v18 )
                  {
                    v40 = 0;
                    v39 = 0;
                    v38 = 0;
                    v37 = 0;
                    v36 = 0;
                    v35 = 0;
                    (*(void (__thiscall **)(int, int, int *, int *, _DWORD, int, _DWORD))(*(_DWORD *)v18 + 4))(
                      v18,
                      2,
                      &v35,
                      &v38,
                      LODWORD(flt_B70A44),
                      1065353216,
                      0);
                  }
                  break;
                }
              }
            }
          }
          else
          {
            sub_4EE320(v19 - 1, 0);
          }
        }
      }
      this[93] = 3.4028235e38;
    }
    if ( dword_B6B7FC )
    {
      if ( !byte_B6F118
        && flt_B70A44 != 0.0
        && *(_DWORD *)dword_B72314 != 7
        && *(_DWORD *)dword_B72314 != 8
        && flt_B6F370 == 3.4028235e38 )
      {
        v22 = 0;
        while ( 1 )
        {
          v23 = dword_B6F1C8[v22];
          if ( v23 )
          {
            if ( (*(int (**)(void))(*(_DWORD *)v23 + 28))() != 2 )
              break;
          }
          if ( ++v22 >= 81 )
          {
            if ( dword_B6F220 )
            {
              v35 = 0;
              v36 = 0;
              v37 = 0;
              v38 = 0;
              v39 = 0;
              v40 = 0;
              (*(void (__thiscall **)(int, int, int *, int *, _DWORD, int, _DWORD))(*(_DWORD *)dword_B6F220 + 4))(
                dword_B6F220,
                2,
                &v35,
                &v38,
                LODWORD(flt_B70A44),
                1065353216,
                0);
            }
            break;
          }
        }
      }
      v24 = flt_BE08A4[(unsigned __int8)dword_BE08A0++] * 4.0;
      this[94] = v24 + dbl_FB1D18;
    }
    if ( *((_DWORD *)this + 94) == 2139095039 || dbl_FB1D18 <= this[94] )
      goto LABEL_155;
    if ( rand() % 10 == 5 )
    {
      if ( !byte_B6F118
        && flt_B70A44 != 0.0
        && *(_DWORD *)dword_B72314 != 7
        && *(_DWORD *)dword_B72314 != 8
        && flt_B6F370 == 3.4028235e38 )
      {
        v25 = 0;
        while ( 1 )
        {
          v26 = dword_B6F1C8[v25];
          if ( v26 )
          {
            if ( (*(int (**)(void))(*(_DWORD *)v26 + 28))() != 2 )
              break;
          }
          if ( ++v25 >= 81 )
          {
            v27 = dword_B6F2E8;
            goto LABEL_152;
          }
        }
      }
LABEL_154:
      this[94] = 3.4028235e38;
LABEL_155:
      sub_4EEBD0(this);
      return;
    }
    if ( rand() % 10 == 5 )
    {
      if ( !byte_B6F118
        && flt_B70A44 != 0.0
        && *(_DWORD *)dword_B72314 != 7
        && *(_DWORD *)dword_B72314 != 8
        && flt_B6F370 == 3.4028235e38 )
      {
        v28 = 0;
        while ( 1 )
        {
          v29 = dword_B6F1C8[v28];
          if ( v29 )
          {
            if ( (*(int (**)(void))(*(_DWORD *)v29 + 28))() != 2 )
              break;
          }
          if ( ++v28 >= 81 )
          {
            v27 = dword_B6F21C;
            goto LABEL_152;
          }
        }
      }
      goto LABEL_154;
    }
    v33 = sub_439AD0(&dbl_B66040);
    v34 = sub_439AB0(&dbl_B66040);
    if ( v33 <= 0.0 )
    {
      if ( v34 <= 0.0 )
      {
LABEL_140:
        if ( v33 == 0.0
          && v34 == 0.0
          && !byte_B6F118
          && flt_B70A44 != 0.0
          && *(_DWORD *)dword_B72314 != 7
          && *(_DWORD *)dword_B72314 != 8
          && flt_B6F370 == 3.4028235e38 )
        {
          v31 = 0;
          while ( 1 )
          {
            v32 = dword_B6F1C8[v31];
            if ( v32 )
            {
              if ( (*(int (**)(void))(*(_DWORD *)v32 + 28))() != 2 )
                break;
            }
            if ( ++v31 >= 81 )
            {
              v27 = dword_B6F1F0;
LABEL_152:
              if ( v27 )
              {
                v35 = 0;
                v36 = 0;
                v37 = 0;
                v38 = 0;
                v39 = 0;
                v40 = 0;
                (*(void (__thiscall **)(int, int, int *, int *, _DWORD, int, _DWORD))(*(_DWORD *)v27 + 4))(
                  v27,
                  2,
                  &v35,
                  &v38,
                  LODWORD(flt_B70A44),
                  1065353216,
                  0);
              }
              goto LABEL_154;
            }
          }
        }
        goto LABEL_154;
      }
      v30 = rand() % 3 + 14;
    }
    else
    {
      v30 = rand() % 3 + 17;
    }
    sub_4EE320(v30, 0);
    goto LABEL_140;
  }
}
