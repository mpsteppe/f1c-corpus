void __userpurge sub_52EB00(float *a1@<ecx>, int a2@<ebx>, int a3@<ebp>, float a4)
{
  int v5; // edi
  double v6; // st7
  int v7; // eax
  float *v8; // ebp
  float v9; // edx
  char v10; // al
  long double v11; // st7
  double v12; // st7
  double v13; // st7
  double v14; // st7
  double v15; // st7
  double v16; // st7
  int v17; // eax
  double v18; // st7
  int v19; // ecx
  int v20; // eax
  double v21; // st7
  double v22; // st7
  double v23; // st6
  double v24; // st6
  float v25; // edx
  double v26; // st7
  float v27; // eax
  double v28; // st7
  int v29; // eax
  int v30; // eax
  char *v31; // eax
  int v32; // eax
  float v34; // [esp+8h] [ebp-24h]
  float v35; // [esp+8h] [ebp-24h]
  float v36; // [esp+8h] [ebp-24h]
  float v37; // [esp+8h] [ebp-24h]
  float v38; // [esp+8h] [ebp-24h]
  int v39; // [esp+Ch] [ebp-20h] BYREF
  int v40; // [esp+10h] [ebp-1Ch]
  float v41; // [esp+14h] [ebp-18h] BYREF
  float v42; // [esp+18h] [ebp-14h]
  float v43; // [esp+1Ch] [ebp-10h]
  float v44; // [esp+20h] [ebp-Ch]
  float v45; // [esp+24h] [ebp-8h]
  float v46; // [esp+28h] [ebp-4h]

  v5 = *(_DWORD *)a1 + 16;
  if ( *(_DWORD *)a1 != -16 )
  {
    v6 = sub_577BC0(v5);
    v34 = v6;
    v7 = *((_DWORD *)a1 + 6);
    v8 = *(float **)(v5 + 17476);
    v39 = -1;
    if ( v7 != -1082130432 )
    {
      sub_561420(v34, (int)&v39);
      if ( v6 >= 0.666 )
        sub_561420(a1[6], 0);
    }
    v9 = *a1;
    a1[6] = v34;
    v10 = *((_BYTE *)a1 + 236);
    if ( *(_BYTE *)(LODWORD(v9) + 15572) )
    {
      if ( !v10 )
        a1[60] = 0.0;
      *((_BYTE *)a1 + 236) = 1;
      v11 = sqrt(
              *(float *)(v5 + 15996) * *(float *)(v5 + 15996)
            + *(float *)(v5 + 16000) * *(float *)(v5 + 16000)
            + *(float *)(v5 + 16004) * *(float *)(v5 + 16004))
          - *(float *)&dword_FADE50;
      if ( v11 > 0.0 )
        a1[60] = v11 * a4 + a1[60];
    }
    else if ( v10 )
    {
      v12 = a1[60];
      *((_BYTE *)a1 + 236) = 0;
      if ( v12 > 7.5 )
      {
        if ( dword_B704D4 )
        {
          if ( *(_DWORD *)dword_B640C8 == 6 )
          {
            sub_52BC40();
            if ( !*(_DWORD *)(*(_DWORD *)a1 + 14820) )
              sub_4EE320(34, 0);
          }
        }
      }
    }
    v41 = *(float *)(v5 + 15972) - v8[1];
    v13 = *(float *)(v5 + 15976);
    v44 = v41;
    v42 = v13 - v8[2];
    v14 = *(float *)(v5 + 15980);
    v45 = v42;
    v43 = v14 - v8[3];
    v46 = v43;
    v15 = v43 * v8[11] + v42 * v8[10] + v41 * v8[9];
    if ( v15 >= 0.0 )
      v16 = v15 - v8[28];
    else
      v16 = -(v15 + v8[27]);
    v17 = *((_DWORD *)a1 + 27);
    v35 = v16;
    if ( (v17 == 1
       || v17 == 3
       || dword_B704D4 < 1
       || dword_B640C0 != 5
       || dword_B64134 != 3 && dword_B64134 != 5 && dword_B64134 != 6 && dword_B64134 != 8
       || *(_DWORD *)(*(_DWORD *)a1 + 19280) == 10)
      && *(_DWORD *)dword_B72314 != 8
      && *(_DWORD *)dword_B72314 != 7 )
    {
      *((_BYTE *)a1 + 248) = 0;
      goto LABEL_73;
    }
    if ( !*((_BYTE *)a1 + 248) )
    {
      if ( v35 > 2.5 && !*(_DWORD *)(*(_DWORD *)a1 + 14820) )
      {
        v32 = *((_DWORD *)a1 + 3);
        a1[64] = a1[13];
        *((_BYTE *)a1 + 248) = 1;
        *((_DWORD *)a1 + 63) = v32;
        a1[65] = v8[76];
        a1[66] = sub_577EA0(v5, a3, a2);
        a1[67] = 0.0;
        a1[68] = sub_573560(v5);
      }
      goto LABEL_73;
    }
    if ( *(_DWORD *)dword_B72314 == 8 )
      sub_42A6B0(byte_91DC48);
    v18 = sub_573560(v5);
    if ( v18 < a1[68] )
      a1[68] = v18;
    a1[67] = a4 + a1[67];
    if ( v35 >= 1.0 )
      goto LABEL_73;
    *((_BYTE *)a1 + 248) = 0;
    v36 = 0.0;
    if ( *(_DWORD *)dword_B640C8 == 6 )
    {
      v19 = *((_DWORD *)a1 + 13);
      v20 = *((_DWORD *)a1 + 64);
      if ( v19 < v20 )
        v36 = (double)(v20 - v19) * 0.72500002;
    }
    if ( !*((_DWORD *)a1 + 65) && !*((_DWORD *)v8 + 76) )
    {
      v21 = sub_577EA0(v5, a3, a2) - a1[66];
      v40 = *((_DWORD *)a1 + 3) - *((_DWORD *)a1 + 63);
      v22 = v21 + (double)v40 * flt_91BDF0;
      v23 = v22 / a1[67] - 0.89999998;
      if ( v23 <= 0.0 )
        v24 = v36;
      else
        v24 = v23 * 0.375 + v36;
      v36 = (v22 - a1[67]) * 0.67500001 + v24;
    }
    v25 = *(float *)(v5 + 15996);
    v26 = v36 + a1[68];
    v27 = *(float *)(v5 + 16000);
    v43 = *(float *)(v5 + 16004);
    v41 = v25;
    v42 = v27;
    if ( !sub_4011C0(&v41) )
      sub_401380(&v41);
    v37 = v26;
    v28 = v43 * v8[44] + v42 * v8[43] + v41 * v8[42] - 1.0 + v37;
    if ( v28 <= 1.0 )
      goto LABEL_73;
    if ( *(_DWORD *)dword_B72314 == 7 )
    {
      v29 = *((_DWORD *)a1 + 39);
      ++*((_DWORD *)a1 + 69);
      if ( v29 )
        *((_DWORD *)a1 + 39) = 1;
      sub_52BB40();
      if ( !*(_DWORD *)(*(_DWORD *)a1 + 14820) )
      {
        if ( rand() % 2 == 1 )
          sub_4EE320(46, 0);
        else
          sub_4EE320(47, 0);
      }
      goto LABEL_73;
    }
    if ( dword_B704D4 < 1 )
    {
LABEL_73:
      off_16C9628(LODWORD(a4));
      return;
    }
    if ( *((int *)a1 + 69) > 1 || (v38 = v28, v38 > 2.75) )
    {
      if ( *(_DWORD *)dword_B640C8 == 6 )
      {
        sub_52BC40();
        goto LABEL_67;
      }
      if ( *(_DWORD *)(*(_DWORD *)a1 + 14820) )
        goto LABEL_67;
      if ( rand() % 2 == 1 )
        goto LABEL_61;
    }
    else
    {
      if ( *(_DWORD *)(*(_DWORD *)a1 + 14820) )
      {
LABEL_67:
        v30 = *((_DWORD *)a1 + 39);
        ++*((_DWORD *)a1 + 69);
        if ( v30 )
        {
          *((_DWORD *)a1 + 39) = 1;
          if ( *(_DWORD *)dword_B640C8 != 6 )
          {
            v31 = sub_41D840(&byte_91CC38, "Lap Will Not Count");
            sub_4730C0((int **)&dword_B6CB98, v31, 3, (int)&byte_1020304, 1084227584);
          }
        }
        goto LABEL_73;
      }
      if ( rand() % 2 == 1 )
      {
LABEL_61:
        sub_4EE320(46, 0);
        goto LABEL_67;
      }
    }
    sub_4EE320(47, 0);
    goto LABEL_67;
  }
}
