char __thiscall sub_40AA00(int this)
{
  int v2; // eax
  int v3; // edi
  __int16 *v4; // ebx
  int v5; // eax
  int v6; // ecx
  int v7; // edi
  __int16 *v8; // ebx
  double v9; // st7
  int v10; // ecx
  int v11; // edi
  int v12; // ebp
  int v13; // edx
  double v14; // st7
  double v15; // st6
  double v16; // st6
  int v17; // ecx
  double v18; // st7
  double v19; // st6
  int v20; // ecx
  __int16 *v21; // edx
  double v22; // st6
  double v23; // st6
  double v24; // st6
  double v25; // st7
  double v26; // st7
  double v27; // st7
  double v29; // st7
  unsigned __int8 v30; // c0
  unsigned __int8 v31; // c3
  double v32; // st7
  int v33; // ecx
  bool v34; // bl
  const char *v35; // eax
  int v36; // ecx
  const char *v37; // eax
  float v39; // [esp+0h] [ebp-2Ch]
  float v40; // [esp+0h] [ebp-2Ch]
  float v41; // [esp+0h] [ebp-2Ch]
  float v42; // [esp+14h] [ebp-18h] BYREF
  int v43; // [esp+18h] [ebp-14h]
  int v44; // [esp+1Ch] [ebp-10h]
  int v45; // [esp+20h] [ebp-Ch] BYREF
  int v46; // [esp+24h] [ebp-8h]
  int v47; // [esp+28h] [ebp-4h]

  v2 = *(_DWORD *)(this + 24);
  if ( v2 == 2 )
    return v2;
  v3 = 0;
  v4 = &word_762A08;
  while ( v3 < ((dword_761FF8 & 1) != 0 ? dword_762A04 : 0) )
  {
    switch ( *v4 )
    {
      case 59:
        if ( !*(_DWORD *)(this + 44) || (dword_761FF8 & 1) != 0 && ((byte_762119 & 2) != 0 || (byte_762199 & 2) != 0) )
          goto LABEL_31;
        v5 = dword_767A9C == 0;
        dword_767A9C = v5;
        if ( v5 >= dword_767AA4 )
        {
          if ( v5 <= dword_767AA8 )
            goto LABEL_31;
          ++v3;
          dword_767A9C = dword_767AA8;
          ++v4;
        }
        else
        {
          ++v3;
          dword_767A9C = dword_767AA4;
          ++v4;
        }
        continue;
      case 74:
        sub_409490((_DWORD *)this, 1);
        ++v3;
        ++v4;
        continue;
      case 78:
        sub_409490((_DWORD *)this, 0);
        ++v3;
        ++v4;
        continue;
      case 156:
        sub_409490((_DWORD *)this, 2);
        goto LABEL_31;
      case 181:
        if ( !dword_768948 )
          goto LABEL_31;
        if ( dword_75CBA8 != 5 || byte_76617C && dword_7D5DA4 != 2 || *(_BYTE *)(this + 73) )
        {
          *(_BYTE *)(this + 73) = 0;
          byte_762AF8 = 0;
          *(_DWORD *)(this + 80) = 0;
          *(_DWORD *)(this + 88) = 0;
          if ( dword_7D5DA4 == 2 )
          {
            sub_451B50(&unk_762A38);
            ++v3;
            ++v4;
            continue;
          }
        }
        else
        {
          *(_BYTE *)(this + 73) = 1;
          byte_762AF8 = 1;
          *(_DWORD *)(this + 80) = 0;
          *(_DWORD *)(this + 88) = 0;
          if ( dword_7D5DA4 == 2 )
          {
            sub_451B70(&unk_762A38);
            ++v3;
            ++v4;
            continue;
          }
        }
LABEL_31:
        ++v3;
        ++v4;
        break;
      case 199:
        sub_40A280(this, aOnboard, 0);
        ++v3;
        ++v4;
        continue;
      case 201:
        sub_40A280(this, aTrackside, 0);
        ++v3;
        ++v4;
        continue;
      case 207:
        sub_40A280(this, aOnboard, 1);
        ++v3;
        ++v4;
        continue;
      case 209:
        sub_40A280(this, aSwingman, 0);
        ++v3;
        ++v4;
        continue;
      case 210:
        sub_40A280(this, aDrivable, 0);
        ++v3;
        ++v4;
        continue;
      case 211:
        sub_40A280(this, aDrivable, 1);
        ++v3;
        ++v4;
        continue;
      default:
        goto LABEL_31;
    }
  }
  v6 = *(_DWORD *)(this + 16);
  if ( v6 && sub_459B90(v6) == 1 )
  {
    v7 = 0;
    v8 = &word_762A08;
    while ( v7 < ((dword_761FF8 & 1) != 0 ? dword_762A04 : 0) )
    {
      switch ( *v8 )
      {
        case 'G':
          v9 = sub_40BEB0(this);
          v10 = *(_DWORD *)(this + 16);
          v42 = v9 * 1.5;
          v42 = sub_459C50(v10) + v42;
          sub_459D30(LODWORD(v42));
          ++v7;
          ++v8;
          continue;
        case 'H':
          v45 = -1082130432;
          v46 = 0;
          goto LABEL_41;
        case 'I':
          v42 = sub_459C50(*(_DWORD *)(this + 16));
          v42 = v42 - sub_40BEB0(this) * 1.5;
          sub_459D30(LODWORD(v42));
          goto LABEL_45;
        case 'K':
          v45 = 0;
          v46 = 1065353216;
LABEL_41:
          v47 = 0;
          v41 = sub_40BEB0(this);
          sub_459D40((int)&v45, 1.0, v41);
          ++v7;
          ++v8;
          continue;
        case 'L':
          sub_459B30(*(_DWORD *)(this + 16));
          ++v7;
          ++v8;
          continue;
        case 'M':
          v45 = 0;
          v46 = -1082130432;
          v47 = 0;
          v40 = sub_40BEB0(this);
          sub_459D40((int)&v45, 1.0, v40);
          ++v7;
          ++v8;
          continue;
        case 'P':
          v45 = 1065353216;
          v46 = 0;
          v47 = 0;
          v39 = sub_40BEB0(this);
          sub_459D40((int)&v45, 1.0, v39);
          ++v7;
          ++v8;
          continue;
        default:
LABEL_45:
          ++v7;
          ++v8;
          break;
      }
    }
  }
  if ( dword_768948 )
  {
    v11 = dword_762A50;
    v12 = dword_762A54;
    if ( (dword_761FF8 & 1) != 0 && (byte_762133 & 2) != 0 )
    {
      *(_DWORD *)(this + 76) = 0;
      *(_DWORD *)(this + 80) = 0;
      *(_DWORD *)(this + 84) = 0;
      *(_DWORD *)(this + 88) = 0;
LABEL_100:
      *(_DWORD *)(this + 96) = v12;
      *(_DWORD *)(this + 92) = v11;
      goto LABEL_101;
    }
    if ( *(_BYTE *)(this + 73) != 1 )
      goto LABEL_100;
    v13 = dword_762A54 - *(_DWORD *)(this + 96);
    v43 = dword_762A50 - *(_DWORD *)(this + 92);
    v44 = v13;
    sub_459BF0(&v42, 0);
    v14 = v42 * 0.013333334;
    v15 = (double)v43;
    if ( v15 != 0.0 )
      *(float *)(this + 88) = v15 * flt_76A580 * v14 + *(float *)(this + 88);
    v16 = (double)v44;
    if ( v16 != 0.0 )
      *(float *)(this + 80) = *(float *)(this + 80) - v16 * flt_76A55C * v14;
    v17 = *(_DWORD *)(this + 16);
    if ( !v17 || *(_BYTE *)(this + 73) != 1 || sub_459B90(v17) == 1 )
    {
LABEL_90:
      v29 = *(float *)(this + 88);
      if ( v30 | v31 )
      {
        if ( v29 >= 0.0 )
          goto LABEL_95;
        v32 = *(float *)(this + 88) + 6.2831855;
      }
      else
      {
        v32 = v29 - 6.2831855;
      }
      *(float *)(this + 88) = v32;
LABEL_95:
      if ( *(float *)(this + 80) <= 0.94247788 )
      {
        if ( *(float *)(this + 80) >= -1.5707964 )
          goto LABEL_100;
        *(_DWORD *)(this + 80) = -1077342245;
      }
      else
      {
        *(_DWORD *)(this + 80) = 1064388155;
      }
      *(_DWORD *)(this + 76) = 0;
      goto LABEL_100;
    }
    v18 = 0.0;
    v44 = 0;
    v19 = 0.0;
    v20 = 0;
    v21 = &word_762A08;
    while ( v20 < ((dword_761FF8 & 1) != 0 ? dword_762A04 : 0) )
    {
      switch ( *v21 )
      {
        case 'H':
          ++v20;
          ++v21;
          v19 = v19 - dbl_7DA9C0 * flt_76A5C8;
          break;
        case 'K':
          ++v20;
          ++v21;
          v18 = v18 - dbl_7DA9C0 * flt_76A634;
          break;
        case 'L':
          *(_DWORD *)(this + 76) = 0;
          *(_DWORD *)(this + 80) = 0;
          *(_DWORD *)(this + 84) = 0;
          *(_DWORD *)(this + 88) = 0;
          goto LABEL_66;
        case 'M':
          ++v20;
          ++v21;
          v18 = v18 + dbl_7DA9C0 * flt_76A634;
          break;
        case 'P':
          ++v20;
          ++v21;
          v19 = v19 + dbl_7DA9C0 * flt_76A5C8;
          break;
        default:
LABEL_66:
          ++v20;
          ++v21;
          break;
      }
    }
    if ( v19 != 0.0 )
    {
      *(float *)(this + 76) = v19 + *(float *)(this + 76);
      v42 = *(float *)&dword_76A5A4;
      v22 = -*(float *)&dword_76A5A4;
      if ( v22 <= *(float *)(this + 76) )
      {
        if ( *(float *)(this + 76) > (double)v42 )
          *(float *)(this + 76) = v42;
      }
      else
      {
        *(float *)(this + 76) = v22;
      }
LABEL_78:
      if ( v18 != 0.0 )
      {
        *(float *)(this + 84) = v18 + *(float *)(this + 84);
        v42 = *(float *)&dword_76A610;
        v25 = -*(float *)&dword_76A610;
        if ( v25 <= *(float *)(this + 84) )
        {
          if ( *(float *)(this + 84) > (double)v42 )
            *(float *)(this + 84) = v42;
        }
        else
        {
          *(float *)(this + 84) = v25;
        }
        goto LABEL_89;
      }
      if ( *(float *)(this + 84) <= 0.0 )
      {
        if ( *(float *)(this + 84) >= 0.0 )
          goto LABEL_89;
        v27 = dbl_7DA9C0 * flt_76A658 + *(float *)(this + 84);
        *(float *)(this + 84) = v27;
        if ( v27 <= 0.0 )
          goto LABEL_89;
      }
      else
      {
        v26 = *(float *)(this + 84) - dbl_7DA9C0 * flt_76A658;
        *(float *)(this + 84) = v26;
        if ( v26 >= 0.0 )
        {
LABEL_89:
          *(float *)(this + 80) = dbl_7DA9C0 * *(float *)(this + 76) + *(float *)(this + 80);
          *(float *)(this + 88) = dbl_7DA9C0 * *(float *)(this + 84) + *(float *)(this + 88);
          goto LABEL_90;
        }
      }
      *(_DWORD *)(this + 84) = 0;
      goto LABEL_89;
    }
    if ( *(float *)(this + 76) <= 0.0 )
    {
      if ( *(float *)(this + 76) >= 0.0 )
        goto LABEL_78;
      v24 = dbl_7DA9C0 * flt_76A5EC + *(float *)(this + 76);
      *(float *)(this + 76) = v24;
      if ( v24 <= 0.0 )
        goto LABEL_78;
    }
    else
    {
      v23 = *(float *)(this + 76) - dbl_7DA9C0 * flt_76A5EC;
      *(float *)(this + 76) = v23;
      if ( v23 >= 0.0 )
        goto LABEL_78;
    }
    *(_DWORD *)(this + 76) = 0;
    goto LABEL_78;
  }
LABEL_101:
  v33 = *(_DWORD *)(this + 16);
  if ( v33 )
  {
    v35 = (const char *)sub_459BA0(v33);
    v34 = _strcmpi(v35, aDrivable) == 0;
  }
  else
  {
    v34 = 0;
  }
  v36 = *(_DWORD *)(this + 16);
  if ( v36 )
  {
    v37 = (const char *)sub_459BA0(v36);
    LOBYTE(v2) = _strcmpi(v37, aSwingman) == 0;
  }
  else
  {
    LOBYTE(v2) = 0;
  }
  if ( *(_DWORD *)(this + 16) && (v34 || (_BYTE)v2) && (LOBYTE(v2) = byte_76617C) == 0 )
  {
    if ( dword_763B2C || byte_769DDC && dword_763AD4 && dword_763B00 )
    {
      LOBYTE(v2) = 1;
      *(_BYTE *)(this + 52) = 1;
    }
    else
    {
      LOBYTE(v2) = 0;
      *(_BYTE *)(this + 52) = 0;
    }
  }
  else
  {
    *(_BYTE *)(this + 52) = 0;
  }
  return v2;
}
