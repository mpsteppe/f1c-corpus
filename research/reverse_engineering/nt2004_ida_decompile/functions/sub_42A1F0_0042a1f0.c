char __thiscall sub_42A1F0(int this)
{
  int v2; // ecx
  int v3; // ecx
  int v4; // eax
  int v5; // eax
  double v6; // st7
  int v7; // eax
  double v8; // st7
  double v9; // st7
  int v10; // ecx
  int v11; // eax
  int v12; // eax
  double v13; // st7
  int v14; // eax
  int v15; // edx
  double v16; // st7
  int v17; // eax
  long double v18; // st7
  int v19; // edi
  long double v20; // st7
  int v21; // edx
  int v22; // eax
  int v23; // eax
  double v24; // st7
  int v25; // eax
  int v26; // eax
  int v27; // edx
  int v28; // eax
  int v29; // eax
  double v30; // st7
  int v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // eax
  float *v35; // ecx
  char result; // al
  int v37; // eax
  int v38; // eax
  int v39; // eax
  int v40; // eax
  double v41; // st7
  int v42; // eax
  double v43; // st7
  double v44; // st6
  double v45; // st6
  int v46; // eax
  double v47; // st6
  int v48; // ecx
  double v49; // st6
  double v51; // st6
  unsigned __int8 v52; // c0
  unsigned __int8 v53; // c3
  double v54; // st6
  int v55; // [esp-4h] [ebp-34h]
  int v56; // [esp-4h] [ebp-34h]
  int v57; // [esp-4h] [ebp-34h]
  int v58; // [esp-4h] [ebp-34h]
  int v59; // [esp-4h] [ebp-34h]
  int v60; // [esp-4h] [ebp-34h]
  int v61; // [esp-4h] [ebp-34h]
  int v62; // [esp-4h] [ebp-34h]
  int v63; // [esp-4h] [ebp-34h]
  float v64; // [esp+10h] [ebp-20h]
  float v65; // [esp+10h] [ebp-20h]
  float v66; // [esp+14h] [ebp-1Ch]
  float v67; // [esp+14h] [ebp-1Ch]
  float v68; // [esp+14h] [ebp-1Ch]
  float v69; // [esp+14h] [ebp-1Ch]
  float v70; // [esp+14h] [ebp-1Ch]
  float v71; // [esp+14h] [ebp-1Ch]
  _DWORD v72[3]; // [esp+18h] [ebp-18h] BYREF
  _DWORD v73[3]; // [esp+24h] [ebp-Ch] BYREF

  if ( (*(_DWORD *)(this + 19804) == 2 || *(float *)(this + 18792) <= 0.001) && *(_DWORD *)(this + 24024) != 3 )
    *(_DWORD *)(this + 24024) = 4;
  if ( flt_5FD0F0 > (double)*(float *)(this + 23852) )
    sub_529AC0(this + 23764, 0.1, 1065353216, -1082130432);
  v2 = *(_DWORD *)(this + 24024);
  switch ( v2 )
  {
    case 5:
      sub_427F60(this, 500);
      *(_DWORD *)(this + 24028) = 1140457472;
      goto LABEL_127;
    case 6:
      sub_427F60(this, 500);
      v3 = *(_DWORD *)(this + 20844);
      *(_DWORD *)(this + 24028) = 1140457472;
      if ( v3 == 5 )
        *(_DWORD *)(this + 24024) = 5;
      goto LABEL_127;
    case 7:
      v32 = *(_DWORD *)(this + 23432);
      if ( !*(_DWORD *)(v32 + 328) )
        *(_DWORD *)(this + 23756) = 1;
      if ( *(_DWORD *)(this + 23756) && *(_DWORD *)(v32 + 328) == 1 )
        *(_DWORD *)(this + 23752) = 1;
      if ( *(_DWORD *)(this + 23608)
        && *(_DWORD *)(v32 + 328) == *(_DWORD *)(this + 23612)
        && !*(_DWORD *)(*(_DWORD *)(this + 80) + 25300) )
      {
        goto LABEL_127;
      }
      v61 = *(_DWORD *)(this + 23612);
      *(_DWORD *)(this + 23936) = 1077936128;
      *(_DWORD *)(this + 23944) = 0x40000000;
      *(_DWORD *)(this + 23932) = 1091567616;
      sub_427F50((_DWORD *)this, v61);
      if ( !*(_DWORD *)(*(_DWORD *)(this + 80) + 25300) )
      {
        v34 = *(_DWORD *)(this + 24020);
        if ( v34 == 15 )
        {
          sub_42D6E0(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 23828) + 23432));
          sub_42C150(7, 1000593162, COERCE_FLOAT(1));
        }
        else
        {
          if ( v34 != 17 )
          {
            if ( v34 != 7 && !(unsigned __int8)sub_42C150(7, 1000593162, 0.0) )
              *(float *)(this + 24676) = *(float *)(this + 23852) + 2.0;
            goto LABEL_127;
          }
          sub_42D6E0(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 23828) + 23432));
          sub_42C150(8, 1000593162, COERCE_FLOAT(1));
        }
        *(_DWORD *)(this + 24704) = 0;
        goto LABEL_127;
      }
      if ( *(_DWORD *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 23828) + 23432) + 340) != 6 )
      {
        v33 = *(_DWORD *)(this + 24020);
        if ( v33 == 16 )
        {
          sub_42C150(12, 1000593162, 0.0);
        }
        else if ( v33 != 12 )
        {
          sub_42C0F0(12);
        }
        if ( dword_7D7928 == 2 && dword_6290F4 >= 2 )
          sub_427F50((_DWORD *)this, 2);
        else
          sub_427F50((_DWORD *)this, 1);
      }
      goto LABEL_127;
    case 8:
      sub_427F60(this, 18);
      if ( !*(_DWORD *)(*(_DWORD *)(this + 23432) + 328) )
        *(_DWORD *)(this + 24024) = (*(_DWORD *)(this + 20844) != 5) + 5;
      goto LABEL_127;
    case 9:
      v10 = *(_DWORD *)(this + 80);
      *(_DWORD *)(this + 24060) = 1120403456;
      *(_DWORD *)(this + 24056) = 1120403456;
      if ( *(_DWORD *)(v10 + 25300) )
      {
        *(_DWORD *)(this + 24024) = 16;
        if ( dword_7663DC - 1 >= 0 )
          v11 = dword_7663DC - 2;
        else
          v11 = 0;
        dword_7663DC = v11;
      }
      v12 = *(_DWORD *)(this + 23608);
      if ( v12 && *(float *)(v12 + 24) > 0.0 )
      {
        v13 = *(float *)(this + 23680) - 10.0;
        *(float *)(this + 23680) = v13;
        *(float *)(this + 23676) = v13;
        if ( *(float *)(this + 24128) - 1.5 <= *(float *)(this + 23728) )
          goto LABEL_127;
        *(_DWORD *)(this + 24024) = 16;
        v14 = dword_7663DC - 1;
        if ( dword_7663DC - 1 < 0 )
        {
          dword_7663DC = 0;
          goto LABEL_127;
        }
        goto LABEL_42;
      }
      v15 = *(_DWORD *)(this + 80);
      v16 = *(float *)(this + 23676) + 10.0;
      *(float *)(this + 23676) = v16;
      *(float *)(this + 23680) = v16;
      v17 = *(_DWORD *)(v15 + 25264);
      if ( v17 > 0 )
        --v17;
      sub_4045E0(&flt_628F60, v17, v73, v72);
      v18 = *(float *)&v72[1] - *(float *)(this + 17620);
      if ( fabs(v18) >= 3.141592653589793 )
      {
        if ( v18 >= 0.0 )
          v18 = v18 - 6.283185307179586;
        else
          v18 = v18 + 6.283185307179586;
      }
      if ( fabs(v18) <= 0.550000011920929 )
        goto LABEL_127;
      *(_DWORD *)(this + 23732) = -1082130432;
      *(_DWORD *)(this + 24024) = 16;
      v14 = dword_7663DC - 1;
      if ( dword_7663DC - 1 >= 0 )
      {
LABEL_42:
        dword_7663DC = v14 - 1;
        goto LABEL_127;
      }
      dword_7663DC = 0;
LABEL_127:
      if ( *(_DWORD *)(this + 24024) == 4 )
      {
        v35 = *(float **)(this + 23432);
        v64 = -v35[31];
        if ( *(float *)(this + 23728) >= (double)v64 )
        {
          if ( *(float *)(this + 23728) <= (double)v35[32] )
          {
            if ( v35[32] + *(float *)(this + 23728) <= v64 - *(float *)(this + 23728) )
            {
              *(float *)(this + 23716) = v35[40];
              return 1;
            }
            else
            {
              result = 1;
              *(float *)(this + 23716) = -v35[39];
            }
          }
          else
          {
            *(float *)(this + 23716) = v35[40];
            return 1;
          }
        }
        else
        {
          result = 1;
          *(float *)(this + 23716) = -v35[39];
        }
      }
      else
      {
        *(float *)(this + 23716) = sub_42B090(*(_DWORD *)(this + 24020), 0);
        if ( *(float *)(this + 24712) <= 0.0 )
        {
          *(float *)(this + 23716) = sub_42B090(*(_DWORD *)(this + 24020), 0);
          *(_DWORD *)(this + 24684) = 0;
          return 1;
        }
        else
        {
          v65 = sub_42B090(*(_DWORD *)(this + 24708), 0);
          v43 = sub_42B090(*(_DWORD *)(this + 24020), 0);
          if ( *(_DWORD *)(this + 23704) )
          {
            if ( *(_DWORD *)(*(_DWORD *)(this + 23432) + 328) != 1 )
            {
              v45 = *(float *)(this + 23856) + *(float *)(this + 24716);
              *(float *)(this + 24716) = v45;
              if ( v45 > 2.0 )
              {
                v46 = *(_DWORD *)(this + 24708);
                if ( v46 != 14 )
                {
                  v47 = 1.0 - *(float *)(this + 24712);
                  v70 = v65;
                  *(_DWORD *)(this + 24708) = *(_DWORD *)(this + 24020);
                  *(float *)(this + 24712) = v47;
                  *(_DWORD *)(this + 24020) = v46;
                  *(_DWORD *)(this + 24716) = 0;
                  v65 = v43;
                  *(_DWORD *)(this + 36) = 1120403456;
                  v43 = v70;
                }
              }
            }
          }
          else
          {
            v44 = *(float *)(this + 24712) - *(float *)(this + 24700);
            *(float *)(this + 24712) = v44;
            if ( v44 < 0.0 )
              *(_DWORD *)(this + 24712) = 0;
          }
          v48 = *(_DWORD *)(this + 24020);
          v49 = (1.0 - *(float *)(this + 24712)) * v43 + v65 * *(float *)(this + 24712);
          *(float *)(this + 23716) = v49;
          v71 = fabs(v49 - v43);
          if ( v48 < 15 && *(int *)(this + 24708) < 15 )
          {
            if ( *(float *)(this + 36) >= (double)v71 )
            {
              *(float *)(this + 36) = v71;
            }
            else
            {
              v51 = v65;
              if ( v52 | v53 )
                v54 = v43 - v51;
              else
                v54 = v51 - v43;
              if ( v54 >= 0.1 )
                *(float *)(this + 24712) = *(float *)(this + 36) / v54;
              else
                *(_DWORD *)(this + 24712) = 0;
              *(float *)(this + 23716) = (1.0 - *(float *)(this + 24712)) * v43 + v65 * *(float *)(this + 24712);
            }
          }
          if ( v43 >= v65 + *(float *)(this + 24704) )
            *(_DWORD *)(this + 24684) = 1;
          else
            *(_DWORD *)(this + 24684) = -1;
          return 1;
        }
      }
      return result;
    case 10:
      if ( dword_75CBB0 == 5 )
        return 0;
      if ( *(float *)(this + 24228) < (double)*(float *)(this + 23852) || v2 == 10 )
      {
        if ( *(_DWORD *)(this + 24584) >= *(_DWORD *)(this + 24496) && dword_75CBB0 != 7 )
          *(_DWORD *)(this + 24024) = 0;
        if ( *(_DWORD *)(this + 20892) == 2 )
          *(_DWORD *)(this + 24024) = 0;
        if ( (unsigned __int8)sub_4BF270(this) && *(int *)(this + 24024) > 3 )
        {
          sub_42C000(this);
          sub_4EEC20(1);
          *(_DWORD *)(this + 24688) = 0;
        }
        else if ( dword_75CBB0 == 7 )
        {
          *(_DWORD *)(this + 24228) = *(_DWORD *)(this + 23852);
        }
        else
        {
          *(float *)(this + 24228) = *(float *)(this + 23852) + 4.0;
        }
      }
      *(_DWORD *)(this + 17764) = 0;
      *(_DWORD *)(this + 17760) = 0;
      *(_DWORD *)(this + 17768) = 1065353216;
      return 0;
    case 11:
      v37 = *(_DWORD *)(this + 23432);
      if ( !*(_DWORD *)(v37 + 328) )
        *(_DWORD *)(this + 23756) = 1;
      if ( *(_DWORD *)(this + 23756) && *(_DWORD *)(v37 + 328) == 1 )
        *(_DWORD *)(this + 23752) = 1;
      v38 = *(_DWORD *)(this + 24020);
      if ( v38 == 17 )
      {
        sub_42C150(8, 1000593162, COERCE_FLOAT(1));
      }
      else if ( v38 != 7 )
      {
        sub_42C150(7, 1000593162, COERCE_FLOAT(1));
      }
      v39 = *(_DWORD *)(this + 80);
      *(float *)(this + 24028) = flt_7D74E0;
      v69 = flt_7D74E0 * 0.80000001;
      v62 = sub_4F8320(v39);
      v40 = sub_4F82E0(*(_DWORD *)(this + 80));
      if ( sub_42C430(v40, v62) >= v69 )
      {
        v63 = sub_4F8320(*(_DWORD *)(this + 80));
        v42 = sub_4F82E0(*(_DWORD *)(this + 80));
        v41 = sub_42C430(v42, v63);
      }
      else
      {
        v41 = flt_7D74E0 * 0.80000001;
      }
      sub_427F60(this, (__int64)v41);
      sub_427F50((_DWORD *)this, *(_DWORD *)(this + 23612));
      goto LABEL_127;
    case 12:
      v6 = *(float *)(this + 23676) + 10.0;
      *(_DWORD *)(this + 24060) = 1120403456;
      *(_DWORD *)(this + 24056) = 1120403456;
      v7 = *(_DWORD *)(this + 23608);
      *(float *)(this + 23676) = v6;
      *(float *)(this + 23680) = v6;
      if ( v7 && *(float *)(v7 + 24) < 0.0 )
      {
        v8 = v6 - 10.0;
        *(float *)(this + 23680) = v8;
        *(float *)(this + 23676) = v8;
        if ( *(float *)(this + 24128) - 2.5 > *(float *)(this + 23728) )
          *(_DWORD *)(this + 24024) = 18;
      }
      else
      {
        v9 = v6 + 10.0;
        *(float *)(this + 23676) = v9;
        *(float *)(this + 23680) = v9;
        if ( *(float *)(this + 24128) + 2.5 < *(float *)(this + 23728) )
          *(_DWORD *)(this + 24024) = 18;
      }
      goto LABEL_127;
    case 13:
      sub_4BBDC0(0);
      goto LABEL_127;
    case 14:
      v4 = *(_DWORD *)(this + 24020);
      if ( v4 == 18 )
      {
        if ( *(_DWORD *)(this + 20876) % 2 )
          sub_42C150(7, 1000593162, 0.0);
        else
          sub_42C150(8, 1000593162, 0.0);
      }
      else if ( v4 == 15 )
      {
        if ( !*(_DWORD *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 23828) + 23432) + 328) )
          sub_42C0F0(7);
      }
      else if ( v4 == 17 && !*(_DWORD *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 23828) + 23432) + 328) )
      {
        sub_42C0F0(8);
      }
      v55 = sub_4F8320(*(_DWORD *)(this + 80));
      v5 = sub_4F82E0(*(_DWORD *)(this + 80));
      *(float *)(this + 24028) = sub_42C430(v5, v55);
      if ( *(_DWORD *)(this + 20844) == 9 )
        *(_DWORD *)(this + 24024) = 6;
      goto LABEL_127;
    case 15:
      sub_427F60(this, (__int64)flt_7D74E0);
      *(float *)(this + 24028) = flt_7D74E0;
      goto LABEL_127;
    case 16:
      if ( *(_DWORD *)(*(_DWORD *)(this + 80) + 25300) )
      {
        if ( byte_766221 )
          sub_42C0F0(5);
        else
          sub_42C0F0(12);
        *(_DWORD *)(this + 24024) = 15;
      }
      else
      {
        v19 = *(_DWORD *)(this + 23432);
        *(_DWORD *)(this + 23676) = *(_DWORD *)(v19 + 128);
        *(float *)(this + 23680) = -*(float *)(v19 + 124);
        if ( *(_DWORD *)(v19 + 328) )
        {
          if ( sub_42B090(dword_629108, 0) + 4.5 >= *(float *)(v19 + 128) )
            sub_42C0F0(7);
          else
            sub_42C0F0(dword_629108);
        }
        else
        {
          sub_42C0F0(6);
        }
        v20 = *(float *)(*(_DWORD *)(this + 23432) + 260) - *(float *)(this + 17620);
        if ( fabs(v20) >= 3.141592653589793 )
        {
          if ( v20 >= 0.0 )
            v20 = v20 - 6.283185307179586;
          else
            v20 = v20 + 6.283185307179586;
        }
        if ( fabs(v20) < 0.25 )
          *(_DWORD *)(this + 24024) = 8;
      }
      goto LABEL_127;
    case 17:
      sub_42D590(this);
      *(_DWORD *)(this + 24024) = 14;
      goto LABEL_127;
    case 18:
      v21 = *(_DWORD *)(this + 23432);
      *(_DWORD *)(this + 23744) = *(_DWORD *)(this + 23740);
      *(float *)(this + 24028) = flt_7D74E0 * 0.80000001;
      if ( !*(_DWORD *)(v21 + 328)
        && *(_DWORD *)(this + 24020) != 8
        && *(float *)(this + 24696) < (double)*(float *)(this + 23852)
        && !(unsigned __int8)sub_42C150(8, 1000593162, 0.0) )
      {
        v22 = *(_DWORD *)(this + 24064);
        if ( v22 == -1 || *(float *)((v22 << 7) + this + 21304) > 30.0 )
          *(float *)(this + 23708) = *(float *)(this + 23856) + *(float *)(this + 23708);
        if ( *(float *)(this + 23708) > 5.0 )
          sub_42C150(8, 1000593162, COERCE_FLOAT(1));
      }
      if ( flt_7D74E0 * 1.5 < *(float *)(this + 23764) )
        sub_529AC0(this + 23764, 0.5, 1065353216, -1082130432);
      if ( flt_5FD0F0 <= (double)*(float *)(this + 23852) )
      {
        v67 = *(float *)(this + 24028);
        v57 = sub_4F8320(*(_DWORD *)(this + 80));
        v25 = sub_4F82E0(*(_DWORD *)(this + 80));
        if ( sub_42C430(v25, v57) < v67 )
        {
          v24 = *(float *)(this + 24028);
          goto LABEL_88;
        }
      }
      else
      {
        v66 = flt_7D74E0;
        v56 = sub_4F8320(*(_DWORD *)(this + 80));
        v23 = sub_4F82E0(*(_DWORD *)(this + 80));
        if ( sub_42C430(v23, v56) < v66 )
        {
          v24 = flt_7D74E0;
          goto LABEL_88;
        }
      }
      v58 = sub_4F8320(*(_DWORD *)(this + 80));
      v26 = sub_4F82E0(*(_DWORD *)(this + 80));
      v24 = sub_42C430(v26, v58);
LABEL_88:
      v27 = *(_DWORD *)(this + 80);
      *(float *)(this + 24028) = v24;
      if ( !(unsigned __int8)sub_4F83B0(v27) )
        *(_DWORD *)(this + 24024) = 19;
LABEL_100:
      if ( (unsigned __int8)sub_4DEB10(this + 20836) == 1 && dword_7D7540 == 7 )
        *(_DWORD *)(this + 24024) = 6;
      if ( !dword_7D7540 )
        *(_DWORD *)(this + 24024) = 6;
      goto LABEL_127;
    case 19:
      v28 = *(_DWORD *)(this + 24020);
      *(float *)(this + 24028) = flt_7D74E0 * 0.80000001;
      if ( v28 != 7 && *(float *)(this + 24696) < (double)*(float *)(this + 23852) && !*(_DWORD *)(this + 24244) )
        sub_42C150(7, 1000593162, 0.0);
      v68 = *(float *)(this + 24028);
      v59 = sub_4F8320(*(_DWORD *)(this + 80));
      v29 = sub_4F82E0(*(_DWORD *)(this + 80));
      if ( sub_42C430(v29, v59) >= v68 )
      {
        v60 = sub_4F8320(*(_DWORD *)(this + 80));
        v31 = sub_4F82E0(*(_DWORD *)(this + 80));
        v30 = sub_42C430(v31, v60);
      }
      else
      {
        v30 = *(float *)(this + 24028);
      }
      *(float *)(this + 24028) = v30;
      if ( v30 <= flt_7D74E0 && (unsigned __int8)sub_4F83B0(*(_DWORD *)(this + 80)) )
        *(_DWORD *)(this + 24024) = 18;
      goto LABEL_100;
    default:
      goto LABEL_127;
  }
}
