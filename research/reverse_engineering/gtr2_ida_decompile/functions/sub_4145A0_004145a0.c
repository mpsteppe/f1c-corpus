int __thiscall sub_4145A0(int this)
{
  int v1; // ebx
  _DWORD *v4; // ecx
  int v5; // eax
  int v6; // eax
  int v7; // ecx
  bool v8; // zf
  int v9; // eax
  int v10; // eax
  int v11; // edi
  int v12; // eax
  _DWORD *v13; // ecx
  _DWORD *v14; // ecx
  _DWORD *v15; // ecx
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // ecx
  int v20; // ebp
  int v21; // edi
  double v22; // st7
  double v23; // st6
  double v24; // st6
  int v25; // eax
  double v26; // st7
  int v27; // ecx
  double v28; // st6
  float *v29; // ebp
  double v30; // st7
  double v31; // st7
  float *v32; // edi
  double v33; // st7
  double v34; // st7
  double v35; // st7
  double v36; // st7
  double v38; // st7
  unsigned __int8 v39; // c0
  unsigned __int8 v40; // c3
  double v41; // st7
  float v42; // [esp+8h] [ebp-2Ch]
  float v43; // [esp+8h] [ebp-2Ch]
  float v44; // [esp+8h] [ebp-2Ch]
  float v45; // [esp+Ch] [ebp-28h]
  int v46; // [esp+20h] [ebp-14h]
  float v47; // [esp+20h] [ebp-14h]
  float v48; // [esp+24h] [ebp-10h] BYREF
  int v49; // [esp+28h] [ebp-Ch]
  int v50; // [esp+2Ch] [ebp-8h]
  int v51; // [esp+30h] [ebp-4h]

  v1 = 0;
  if ( *(_DWORD *)dword_B72314 == 8 && byte_91DE29 == 1 )
    return 0;
  if ( !*(_BYTE *)(this + 48) )
  {
    if ( *(_DWORD *)dword_B72314 == 5 && byte_B73528 == 1 && !byte_B6F118 )
    {
      if ( sub_410B50((_DWORD *)this) != 1
        && !(unsigned __int8)sub_40DDC0()
        && sub_4109B0((_DWORD *)this, 1)
        && !sub_412EB0(v4, 1, 0) )
      {
        v1 = 1;
      }
    }
    else
    {
      v11 = 0;
      while ( v11 < ((dword_B698E8 & 1) != 0 ? dword_B6A2F4 : 0) )
      {
        switch ( word_B6A2F8[v11] )
        {
          case 74:
            v16 = sub_4108F0(*(_DWORD *)(*(&dword_91E088 + dword_91E078) + 22468), 1);
            sub_414450((_DWORD *)this, v16);
            v1 = 1;
            ++v11;
            continue;
          case 78:
            v17 = sub_4108F0(*(_DWORD *)(*(&dword_91E088 + dword_91E078) + 22468), -1);
            sub_414450((_DWORD *)this, v17);
            v1 = 1;
            ++v11;
            continue;
          case 156:
            sub_414450((_DWORD *)this, *(_DWORD *)(*(&dword_91E088 + dword_91E080) + 22468));
            goto LABEL_47;
          case 199:
            if ( !sub_4109B0((_DWORD *)this, 4) || sub_412EB0(v14, 4, 1) )
              goto LABEL_48;
            v1 = 1;
            ++v11;
            continue;
          case 201:
            if ( dword_91E07C[15572] && !sub_4109B0((_DWORD *)this, 3) || sub_412EB0((_DWORD *)this, 3, 1) )
            {
              if ( byte_B71B34 )
              {
                v1 = 1;
                ++v11;
                continue;
              }
            }
            else
            {
LABEL_47:
              v1 = 1;
            }
LABEL_48:
            ++v11;
            break;
          case 209:
            if ( !sub_4109B0((_DWORD *)this, 5) || sub_412EB0(v15, 5, 1) )
              goto LABEL_48;
            v1 = 1;
            ++v11;
            continue;
          case 210:
            v12 = *(_DWORD *)(this + 32);
            if ( *(_DWORD *)(this + 8) == v12 && *(_DWORD *)(v12 + 64)
              || !sub_4109B0((_DWORD *)this, 0)
              || sub_412EB0(v13, 0, 1) )
            {
              goto LABEL_48;
            }
            v1 = 1;
            ++v11;
            continue;
          default:
            goto LABEL_48;
        }
      }
    }
    if ( dword_B6BABC && !byte_B6F118 )
    {
      if ( *(_DWORD *)dword_B72314 != 8 || byte_91E048 )
        sub_414450((_DWORD *)this, *(_DWORD *)(*(&dword_91E088 + dword_91E080) + 22468));
      v5 = sub_410B50((_DWORD *)this);
      if ( v5 )
      {
        v6 = v5 - 2;
        v7 = *(_DWORD *)(this + 8);
        if ( v6 )
        {
          v8 = v6 == 1;
          v9 = *(_DWORD *)(this + 32);
          if ( v8 )
          {
            if ( v7 == v9 && *(_DWORD *)(v9 + 64) || !sub_4109B0((_DWORD *)this, 1) )
              goto LABEL_63;
            v10 = sub_412EB0((_DWORD *)this, 1, 0);
          }
          else
          {
            if ( v7 == v9 && *(_DWORD *)(v9 + 64) || !sub_4109B0((_DWORD *)this, 2) )
              goto LABEL_63;
            v10 = sub_412EB0((_DWORD *)this, 2, 0);
          }
        }
        else
        {
          v18 = *(_DWORD *)(this + 32);
          if ( v7 == v18 && *(_DWORD *)(v18 + 64) || !sub_4109B0((_DWORD *)this, 0) )
            goto LABEL_63;
          v10 = sub_412EB0((_DWORD *)this, 0, 0);
        }
      }
      else
      {
        v19 = *(_DWORD *)(this + 32);
        if ( *(_DWORD *)(this + 8) == v19 && *(_DWORD *)(v19 + 64) )
          goto LABEL_63;
        sub_40F2A0();
        if ( !sub_4109B0((_DWORD *)this, 3) )
          goto LABEL_63;
        v10 = sub_412EB0((_DWORD *)this, 3, 1);
      }
      if ( !v10 )
        v1 = dword_16C9B60;
    }
LABEL_63:
    if ( dword_B6BB6C )
    {
      if ( dword_B640C0 != 5 || byte_B6F118 && dword_BE1204 != 2 || *(_BYTE *)(this + 77) )
      {
        *(_BYTE *)(this + 77) = 0;
        byte_B6A3E8 = 0;
        *(_DWORD *)(this + 80) = 0;
        *(_DWORD *)(this + 84) = 0;
        *(_DWORD *)(this + 88) = 0;
        *(_DWORD *)(this + 92) = 0;
        if ( dword_BE1204 == 2 )
          sub_45DDE0(&unk_B6A328);
      }
      else
      {
        *(_BYTE *)(this + 77) = 1;
        byte_B6A3E8 = 1;
        *(_DWORD *)(this + 80) = 0;
        *(_DWORD *)(this + 84) = 0;
        *(_DWORD *)(this + 88) = 0;
        *(_DWORD *)(this + 92) = 0;
        if ( dword_BE1204 == 2 )
          sub_45DE00(&unk_B6A328);
      }
    }
    v20 = dword_B6A340;
    v21 = dword_B6A344;
    v51 = dword_B6A340;
    v50 = dword_B6A344;
    if ( dword_B6BB98 || dword_B6A3DC )
    {
      *(_DWORD *)(this + 80) = 0;
      *(_DWORD *)(this + 84) = 0;
      *(_DWORD *)(this + 88) = 0;
      *(_DWORD *)(this + 92) = 0;
      goto LABEL_120;
    }
    if ( *(_BYTE *)(this + 77) != 1 || dword_B6A3D8 || dword_B6A3E0 )
      goto LABEL_120;
    v46 = dword_B6A340 - *(_DWORD *)(this + 96);
    v49 = dword_B6A344 - *(_DWORD *)(this + 100);
    v8 = *(_DWORD *)this == 0;
    v48 = 1.309;
    if ( !v8 )
      sub_5E4DB0(&v48, 0);
    v22 = v48 * 0.76394194;
    v23 = (double)v46;
    if ( v23 != 0.0 )
      *(float *)(this + 92) = v23 * flt_B7450C * v22 + *(float *)(this + 92);
    v24 = (double)v49;
    if ( v24 != 0.0 )
      *(float *)(this + 84) = *(float *)(this + 84) - v24 * flt_B744E8 * v22;
    v25 = *(_DWORD *)(this + 32);
    if ( *(_DWORD *)(this + 8) == v25 && *(_DWORD *)(v25 + 52) == 3 )
    {
LABEL_111:
      if ( *(_DWORD *)(dword_91E084 + 5744) == 1 )
      {
        sub_401760((float *)(this + 92), -0.78539819, 0.78539819);
        v45 = flt_B74608 * 3.1415927;
        v44 = flt_B7462C * 3.1415927;
        sub_401760((float *)(this + 84), v44, v45);
LABEL_120:
        *(_DWORD *)(this + 100) = v21;
        *(_DWORD *)(this + 96) = v20;
        goto LABEL_121;
      }
      v38 = *(float *)(this + 92);
      if ( v39 | v40 )
      {
        if ( v38 >= 0.0 )
        {
LABEL_118:
          sub_401760((float *)(this + 84), -1.5707964, 1.5707964);
          goto LABEL_120;
        }
        v41 = *(float *)(this + 92) + 6.2831855;
      }
      else
      {
        v41 = v38 - 6.2831855;
      }
      *(float *)(this + 92) = v41;
      goto LABEL_118;
    }
    v26 = 0.0;
    v27 = 0;
    v28 = 0.0;
    while ( v27 < ((dword_B698E8 & 1) != 0 ? dword_B6A2F4 : 0) )
    {
      switch ( word_B6A2F8[v27] )
      {
        case 'H':
          ++v27;
          v26 = v26 + dbl_FB1D08 * flt_B74554;
          break;
        case 'K':
          ++v27;
          v28 = v28 - dbl_FB1D08 * flt_B745C0;
          break;
        case 'L':
          *(_DWORD *)(this + 80) = 0;
          *(_DWORD *)(this + 84) = 0;
          *(_DWORD *)(this + 88) = 0;
          *(_DWORD *)(this + 92) = 0;
          goto LABEL_93;
        case 'M':
          ++v27;
          v28 = v28 + dbl_FB1D08 * flt_B745C0;
          break;
        case 'P':
          ++v27;
          v26 = v26 - dbl_FB1D08 * flt_B74554;
          break;
        default:
LABEL_93:
          ++v27;
          break;
      }
    }
    v47 = v28;
    v29 = (float *)(this + 80);
    if ( v26 != 0.0 )
    {
      *v29 = v26 + *v29;
      v42 = -flt_B74530;
      sub_401760((float *)(this + 80), v42, flt_B74530);
      goto LABEL_102;
    }
    if ( *v29 <= 0.0 )
    {
      if ( *v29 >= 0.0 || (v31 = dbl_FB1D08 * flt_B74578 + *v29, *v29 = v31, v31 <= 0.0) )
      {
LABEL_102:
        v32 = (float *)(this + 88);
        if ( v47 != 0.0 )
        {
          *v32 = v47 + *v32;
          v43 = -flt_B7459C;
          sub_401760((float *)(this + 88), v43, flt_B7459C);
LABEL_110:
          v35 = dbl_FB1D08 * *v29;
          v20 = v51;
          *(float *)(this + 84) = v35 + *(float *)(this + 84);
          v36 = dbl_FB1D08 * *v32;
          v21 = v50;
          *(float *)(this + 92) = v36 + *(float *)(this + 92);
          goto LABEL_111;
        }
        if ( *v32 <= 0.0 )
        {
          if ( *v32 >= 0.0 )
            goto LABEL_110;
          v34 = dbl_FB1D08 * flt_B745E4 + *v32;
          *v32 = v34;
          if ( v34 <= 0.0 )
            goto LABEL_110;
        }
        else
        {
          v33 = *v32 - dbl_FB1D08 * flt_B745E4;
          *v32 = v33;
          if ( v33 >= 0.0 )
            goto LABEL_110;
        }
        *v32 = 0.0;
        goto LABEL_110;
      }
    }
    else
    {
      v30 = *v29 - dbl_FB1D08 * flt_B74578;
      *v29 = v30;
      if ( v30 >= 0.0 )
        goto LABEL_102;
    }
    *v29 = 0.0;
    goto LABEL_102;
  }
LABEL_121:
  if ( *(_BYTE *)(this + 56) )
  {
    *(_BYTE *)(this + 56) = 0;
    return 1;
  }
  return v1;
}
