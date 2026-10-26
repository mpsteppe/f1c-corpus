void __userpurge sub_52C875(char a1@<al>, _DWORD *a2@<ecx>, float a3, int a4)
{
  int v5; // ecx
  char v6; // al
  bool v7; // dl
  char v8; // dl
  char v9; // al
  int v10; // eax
  int v11; // ebp
  float *v12; // edi
  double v13; // st7
  float v14; // eax
  float v15; // ecx
  float v16; // eax
  float v17; // ecx
  float v18; // edx
  int v19; // ebx
  double v20; // st7
  int v21; // edi
  float *v22; // eax
  float v23; // ecx
  float v24; // edx
  float *v25; // edi
  float v26; // eax
  double v27; // st7
  int v28; // eax
  double v30; // st7
  unsigned __int8 v31; // c0
  unsigned __int8 v32; // c2
  double v33; // st7
  double v34; // st7
  int v35; // eax
  char *v36; // eax
  double v37; // st6
  char *v38; // eax
  char *v39; // eax
  char *v40; // eax
  int v41; // edi
  float *v42; // ebp
  double v43; // st7
  char *v44; // eax
  unsigned int v45; // eax
  double v46; // st7
  char *v47; // eax
  double v48; // st7
  unsigned __int8 v50; // c0
  unsigned __int8 v51; // c3
  float v52; // [esp+24h] [ebp-104h]
  float v53; // [esp+28h] [ebp-100h]
  float v54; // [esp+28h] [ebp-100h]
  float v55; // [esp+28h] [ebp-100h]
  float v56; // [esp+2Ch] [ebp-FCh]
  float v57; // [esp+30h] [ebp-F8h]
  float v58; // [esp+34h] [ebp-F4h]
  float v59; // [esp+34h] [ebp-F4h]
  char v60; // [esp+3Ah] [ebp-EEh]
  char v61; // [esp+3Bh] [ebp-EDh]
  float v62; // [esp+3Ch] [ebp-ECh]
  float v63; // [esp+3Ch] [ebp-ECh]
  float v64; // [esp+3Ch] [ebp-ECh]
  float v65; // [esp+40h] [ebp-E8h] BYREF
  float v66; // [esp+44h] [ebp-E4h]
  float v67; // [esp+48h] [ebp-E0h]
  float v68; // [esp+4Ch] [ebp-DCh]
  float v69[3]; // [esp+50h] [ebp-D8h] BYREF
  char v70[61]; // [esp+5Ch] [ebp-CCh] BYREF
  __int16 v71; // [esp+99h] [ebp-8Fh]
  char v72; // [esp+9Bh] [ebp-8Dh]
  float v73[3]; // [esp+9Ch] [ebp-8Ch] BYREF
  char Buffer[128]; // [esp+A8h] [ebp-80h] BYREF

  if ( a1 )
    return;
  v61 = *((_BYTE *)a2 + 285);
  *((_BYTE *)a2 + 285) = 1;
  sub_472920((const char **)&dword_B6CB98, "Warning: Driving Too Slow", 0);
  sub_472920((const char **)&dword_B6CB98, "Warning: Driving Too Slow Under Yellow", 0);
  sub_472920((const char **)&dword_B6CB98, "Warning: Accelerating Too Early", 0);
  sub_472920((const char **)&dword_B6CB98, "Warning: You Are Ahead Of The Car You Should Be Following", 0);
  v68 = *((float *)a2 + 73);
  v5 = *a2;
  a2[73] = 0;
  v6 = *(_BYTE *)(v5 + 15572);
  v7 = v6 && dword_B64134 >= 5 || *(_DWORD *)dword_B640C8 != 6 || a2[27];
  if ( *(_DWORD *)(v5 + 14820) )
  {
    if ( !v7 )
      goto LABEL_140;
LABEL_138:
    if ( (unsigned __int8)sub_54F270(&byte_FADF20, v5) )
      sub_54F160(&byte_FADF20, *a2);
    goto LABEL_140;
  }
  if ( v7 )
    goto LABEL_138;
  if ( v6 )
    goto LABEL_140;
  if ( dword_B64134 == 5 && a2[2] == 9 )
  {
    v8 = 1;
  }
  else
  {
    v8 = 0;
    if ( dword_B64134 != 5 )
    {
LABEL_17:
      v9 = 0;
      goto LABEL_18;
    }
  }
  if ( a2[2] != 10 )
    goto LABEL_17;
  v9 = 1;
LABEL_18:
  if ( dword_FADE9C == 7 || v8 || (HIBYTE(v56) = 0, v9) )
    HIBYTE(v56) = 1;
  v62 = dbl_FB1D18 - 0.80000001;
  v57 = flt_91BDE4;
  v10 = sub_54F1F0(v5);
  v11 = v10;
  if ( v10 != a2[77] )
  {
    a2[77] = v10;
    *((float *)a2 + 78) = dbl_FB1D18;
  }
  if ( v10 >= 0 )
  {
    v12 = (float *)((char *)&unk_9204A0 + 22616 * v10);
    if ( *((_DWORD *)v12 + 3705) == 2 )
      v53 = v12[5643];
    else
      v53 = dbl_FB1D18;
    v13 = sub_577D40(v12 + 4);
    v60 = 0;
LABEL_31:
    v58 = v13;
    v14 = v12[3998];
    v15 = v12[3999];
    v65 = v12[3997];
    v66 = v14;
    v16 = v12[4003];
    v67 = v15;
    v17 = v12[4004];
    v18 = v12[4005];
    v69[0] = v16;
    v69[1] = v17;
    v69[2] = v18;
    if ( v53 <= (double)v62 )
      return;
    v19 = a2[70] - *((_DWORD *)v12 + 4888);
    v20 = sub_577D40(*a2 + 16);
    v54 = v20;
    if ( fabs(v20 - v58) < 20.0 )
    {
      v21 = *a2;
      v22 = sub_401290(&v65, (float *)(*a2 + 15988), v73);
      v23 = *v22;
      v24 = v22[1];
      v25 = *(float **)(v21 + 17492);
      v26 = v22[2];
      v65 = v23;
      v66 = v24;
      v67 = v26;
      if ( v25 )
        v58 = v67 * v25[44] + v66 * v25[43] + v65 * v25[42] + v54;
    }
    if ( v19 )
    {
      if ( v19 > 2 || v19 > 1 && v54 > (double)v58 )
      {
        sub_52C000(a2, "Lapped Field Multiple Times");
        return;
      }
      if ( v19 > 0 )
        goto LABEL_37;
    }
    else if ( v54 > (double)v58 )
    {
LABEL_37:
      if ( !HIBYTE(v56) )
      {
        *((_BYTE *)a2 + 285) = v61;
        if ( v19 > 0 )
          goto LABEL_94;
        v27 = v58 + 15.0;
        if ( v11 >= 0 )
        {
          v28 = sub_54F1F0((char *)&unk_9204A0 + 22616 * v11);
          if ( v28 < 0 )
          {
            if ( byte_9034D0 )
            {
              sub_52B390();
              v27 = v27 + 5.0;
            }
            else
            {
              v63 = v27;
              v27 = v63;
            }
          }
          else
          {
            v27 = sub_577BC0((char *)&unk_9204B0 + 22616 * v28) + 5.0;
          }
        }
        v37 = v57 * 0.5;
        if ( v27 <= v54 + v37 )
        {
          if ( v27 < v54 - v37 )
            v27 = v27 + v57;
        }
        else
        {
          v27 = v27 - v57;
        }
        if ( v54 > v27 )
LABEL_94:
          *((_BYTE *)a2 + 285) = 0;
        if ( !a4 || *((_BYTE *)a2 + 284) )
        {
          sub_52C800((float *)a2, v11);
          v38 = sub_41D840(&byte_91CC38, "Warning: You Are Ahead Of The Car You Should Be Following");
          sub_4730C0((int **)&dword_B6CB98, v38, 3, (int)&byte_1020304, 1084227584);
          if ( !*(_DWORD *)(*a2 + 14820) )
            sub_4EE320(68, 0);
          memset(v70, 0, sizeof(v70));
          v71 = 0;
          v72 = 0;
          if ( v11 < 0 )
          {
            if ( byte_9034D0 )
            {
              v40 = sub_41D840(&byte_91CC38, "Stay Behind The Safety Car");
              sub_41D810(v70, 0x3Fu, "%s", v40);
              sub_4730C0((int **)&dword_B6CB98, v70, 3, (int)&byte_1020304, 1084227584);
            }
          }
          else
          {
            v39 = sub_41D840(&byte_91CC38, "Stay Behind");
            sub_41D810(Buffer, 0x7Fu, v39);
            off_16C9370(LODWORD(a3), a4);
          }
        }
        else
        {
          *((_BYTE *)a2 + 284) = 1;
          if ( v19 <= 0 )
          {
            if ( a4 == 1 )
            {
              sub_52C830((float *)a2, (int)"Illegally Passed Before Green");
            }
            else if ( a4 == 2 )
            {
              sub_52C830((float *)a2, (int)"Illegally Passed Before Finish");
            }
            else if ( v58 + 15.0 < v54 )
            {
              sub_52C830((float *)a2, (int)"Illegally Passed Before Pit Entrance");
            }
          }
        }
      }
      return;
    }
    if ( a4 || HIBYTE(v56) )
      return;
    v55 = v58 - v54;
    v30 = v55;
    if ( v31 | v32 )
    {
      v33 = v30 + v57;
    }
    else
    {
      if ( v30 <= v57 )
      {
LABEL_53:
        if ( v55 <= 250.0
          || (sub_52C800((float *)a2, v11), v55 <= 1000.0)
          || flt_FADE54 + 15.0 <= sub_401220(v69)
          || fabs(*((float *)a2 + 78) - dbl_FB1D18) <= 3.0
          || v60 && dbl_FB1D18 <= flt_9034E4 + 10.0 )
        {
LABEL_85:
          *((float *)a2 + 75) = v55;
          return;
        }
        if ( v68 == 0.0 )
          *((float *)a2 + 74) = v55;
        v34 = v68 + a3;
        *((float *)a2 + 73) = v34;
        if ( v34 > 21.5 )
        {
          if ( v55 < (double)*((float *)a2 + 74) )
          {
            *((float *)a2 + 74) = v55;
LABEL_73:
            a2[73] = 0;
            goto LABEL_74;
          }
          if ( !(unsigned __int8)sub_54F2D0(&byte_FADF20, *a2) )
          {
            v36 = sub_41D840(&byte_91CC38, "Driving Too Slow: Moved To End Of Line");
            sub_4730C0((int **)&dword_B6CB98, v36, 3, (int)&byte_1020304, 1084227584);
            if ( !*(_DWORD *)(*a2 + 14820) )
              sub_4EE320(71, 0);
            sub_552F80(*a2);
            goto LABEL_73;
          }
          if ( dword_B64134 <= 3 && !a2[30] && v56 * 0.5 < v52 )
          {
            sub_52BC40();
            v35 = *a2;
            a2[73] = -1063256064;
            if ( !*(_DWORD *)(v35 + 14820) )
              sub_4EE320(38, 0);
          }
        }
LABEL_74:
        if ( !(unsigned __int8)sub_4735A0()
          && *((float *)a2 + 73) > 5.0
          && *((float *)a2 + 73) < 9.5
          && v55 > (double)*((float *)a2 + 74)
          && !*(_DWORD *)(*a2 + 14820) )
        {
          sub_4EE320(69, 0);
        }
        *((_BYTE *)a2 + 285) = v61;
        if ( v55 > 200.0
          && v55 > (double)*((float *)a2 + 74)
          && v55 > (double)*((float *)a2 + 75)
          && *((float *)a2 + 73) > 4.5 )
        {
          *((_BYTE *)a2 + 285) = 0;
          *((float *)a2 + 75) = v55;
          return;
        }
        goto LABEL_85;
      }
      v33 = v55 - v57;
    }
    v55 = v33;
    goto LABEL_53;
  }
  if ( byte_9034D0 )
  {
    v12 = (float *)off_757C18;
    v13 = sub_52B480();
    v53 = v13;
    sub_52B390();
    v60 = 1;
    goto LABEL_31;
  }
  v41 = *a2;
  v42 = (float *)(*a2 + 16);
  v59 = flt_FADE54;
  if ( v59 * 0.30000001 > sub_41FE50(v42) && dword_B64134 >= 3 )
  {
    v43 = a3 + *((float *)a2 + 72);
    *((float *)a2 + 72) = v43;
    if ( v43 <= 5.0 )
    {
      if ( !(unsigned __int8)sub_4735A0() && !*(_DWORD *)(*a2 + 14820) )
        sub_4EE320(69, 0);
    }
    else
    {
      a2[72] = 0;
      if ( !(unsigned __int8)sub_54F2D0(&byte_FADF20, v41) )
      {
        v44 = sub_41D840(&byte_91CC38, "Driving Too Slow: Moved To End Of Line");
        sub_4730C0((int **)&dword_B6CB98, v44, 3, (int)&byte_1020304, 1084227584);
        if ( !*(_DWORD *)(*a2 + 14820) )
          sub_4EE320(71, 0);
        sub_552F80(*a2);
      }
    }
    return;
  }
  if ( v59 * 1.25 >= sub_41FE50(v42) )
  {
LABEL_140:
    a2[72] = 0;
    return;
  }
  if ( !HIBYTE(v56) && dword_FADE9C != 1 && dword_FADE9C != 2 )
  {
    v45 = sub_54EC40(0);
    if ( v45 == a2[1] )
      goto LABEL_135;
    if ( v45 < 0x68 )
    {
      v64 = sub_577BC0((char *)&unk_9204B0 + 22616 * v45);
      v46 = v64 - sub_577BC0(*a2 + 16);
      if ( v46 >= v57 * -0.5 )
      {
        if ( v46 > v57 * 0.5 )
          v46 = v46 - v57;
      }
      else
      {
        v46 = v46 + v57;
      }
      if ( v46 < 1.0 )
      {
LABEL_135:
        if ( !(unsigned __int8)sub_4735A0() )
        {
          v47 = sub_41D840(&byte_91CC38, "Warning: Accelerating Too Early");
          sub_4730C0((int **)&dword_B6CB98, v47, 3, (int)&byte_1020304, 1084227584);
          v48 = a3 + *((float *)a2 + 72);
          *((float *)a2 + 72) = v48;
          if ( !(v50 | v51) || v48 > 1.5 && v59 * 1.75 < sub_41FE50((float *)(*a2 + 16)) )
          {
            a2[72] = -1063256064;
            sub_52BC40();
          }
        }
      }
    }
  }
}
