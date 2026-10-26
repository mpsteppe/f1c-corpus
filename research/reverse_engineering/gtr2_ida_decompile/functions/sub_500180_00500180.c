// bad sp value at call has been detected, the output may be wrong!
char __userpurge sub_500180@<al>(float *a1@<ecx>, int a2@<edi>, float a3@<esi>, float a4)
{
  bool v5; // c0
  int v6; // edi
  int v7; // eax
  int v8; // eax
  char *v9; // eax
  int v10; // eax
  _BYTE *v11; // ecx
  bool v12; // zf
  float *v13; // ecx
  double v14; // st7
  float v15; // edi
  int v16; // edi
  long double v17; // st7
  double v18; // st7
  double v19; // st7
  double v20; // st7
  double v21; // st7
  double v22; // st7
  int v23; // ecx
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // eax
  double v28; // st7
  int v30; // [esp-4h] [ebp-50h]
  int v31; // [esp+0h] [ebp-4Ch]
  double v32; // [esp+4h] [ebp-48h]
  int v33; // [esp+4h] [ebp-48h]
  float v34; // [esp+10h] [ebp-3Ch]
  int Buffer; // [esp+1Ch] [ebp-30h] BYREF
  float v36; // [esp+20h] [ebp-2Ch]
  float v37; // [esp+24h] [ebp-28h]
  float v38; // [esp+28h] [ebp-24h]
  float retaddr; // [esp+4Ch] [ebp+0h]

  v36 = a3;
  v5 = a4 < (double)a1[197];
  Buffer = a2;
  if ( v5 )
  {
    if ( *((_BYTE *)a1 + 808) && a1[197] - 2.0 <= a4 )
    {
      v12 = *((_DWORD *)a1 + 231) == 1;
      *((_BYTE *)a1 + 808) = 0;
      if ( v12 )
        sub_413E70();
      else
        *((_BYTE *)a1 + 1096) = 1;
    }
    if ( *((_DWORD *)a1 + 209)
      && a4 > (double)a1[204]
      && *(float *)(*(_DWORD *)a1 + 17196) + 1.0 < a1[206]
      && !*(_DWORD *)(*(_DWORD *)a1 + 14820)
      && *((float *)dword_91E07C + 4307) > 0.0 )
    {
      v13 = (float *)*((_DWORD *)a1 + 2);
      v14 = a4 - a1[198];
      a1[204] = a4;
      v37 = v14;
      v15 = v37;
      a1[197] = v14 + a1[197];
      a1[205] = v37 + a1[205];
      a1[217] = v37 + a1[217];
      a1[218] = v37 + a1[218];
      a1[200] = v37 + a1[200];
      if ( v13 )
        sub_4F1120(v13, v15);
      if ( *((_DWORD *)a1 + 231) != 1 )
        sub_4152B0(a1 + 231, v15);
      v16 = *(_DWORD *)a1;
      a1[203] = *(float *)(*(_DWORD *)a1 + 17196);
      if ( dword_B74C9C == 89 )
      {
        if ( byte_B6820A )
          byte_B6820A = 0;
      }
      else
      {
        v17 = fmod(a1[205], 9.0);
        if ( v17 > 1.0 && v17 < 2.0 )
          sub_4EE320(60, v16);
      }
    }
    if ( (*((_DWORD *)a1 + 212)
       || *((_DWORD *)a1 + 213)
       || *((_DWORD *)a1 + 214)
       || *((_DWORD *)a1 + 215)
       || *((_DWORD *)a1 + 216))
      && a4 > (double)a1[200] )
    {
      if ( *(_DWORD *)a1 == ((_BYTE)dword_757C1C != 0 ? dword_91E084 : 0) )
      {
        if ( a1[201] >= 4.0 && a4 >= (double)a1[200] && a1[200] + 1.0 > a4 )
          sub_4EE320(76, *(_DWORD *)a1);
        if ( a1[201] >= 22.0 )
        {
          v18 = a1[200] + 19.0;
          if ( a4 >= v18 && a4 < v18 + 1.0 )
            sub_4EE320(77, *(_DWORD *)a1);
        }
        if ( a1[201] >= 47.0 )
        {
          v19 = a1[200] + 42.0;
          if ( a4 >= v19 && a4 < v19 + 1.0 )
            sub_4EE320(78, *(_DWORD *)a1);
        }
        if ( a1[201] >= 70.0 )
        {
          v20 = a1[200] + 67.0;
          if ( a4 >= v20 && a4 < v20 + 1.0 )
            sub_4EE320(77, *(_DWORD *)a1);
        }
        if ( a1[201] >= 5.0 && a1[201] - 5.0 > a1[219] )
        {
          v21 = a1[201] + a1[200];
          if ( v21 - 5.0 <= a4 && a4 < v21 && a4 > (double)a1[218] )
            sub_4EE320(79, *(_DWORD *)a1);
        }
      }
      if ( a1[201] + a1[200] > a4 )
      {
        if ( !((int)(unsigned __int64)a4 % 3) )
          sub_4EE320(86, *(_DWORD *)a1);
        sub_4EE320(88, *(_DWORD *)a1);
      }
    }
    if ( *((_DWORD *)a1 + 209) && a4 > (double)a1[204] )
    {
      v22 = (a4 - a1[204]) * 2.9000001 + a1[203];
      v38 = v22;
      if ( v22 <= a1[206] )
      {
        sub_4EE320(89, *(_DWORD *)a1);
      }
      else
      {
        v38 = a1[206];
        sub_4EE120(dword_B6F1C8, 89, 0);
      }
      sub_578550(LODWORD(v38));
    }
    else
    {
      sub_4EE120(dword_B6F1C8, 89, 0);
    }
    v23 = *((_DWORD *)a1 + 210);
    if ( v23 || (v10 = *((_DWORD *)a1 + 211)) != 0 )
    {
      if ( retaddr <= (double)a1[218] )
      {
        v36 = 0.0;
        v37 = 0.0;
        if ( v23 )
        {
          if ( a1[217] + 0.80000001 >= retaddr )
          {
            if ( a1[217] + 0.2 < retaddr )
            {
              v25 = *((_DWORD *)a1 + 2);
              if ( v25 && (*(_BYTE *)(v25 + 12) & 1) != 0 )
                sub_4EE320(81, *(_DWORD *)a1);
              else
                sub_4EE320(87, *(_DWORD *)a1);
              sub_4EE320(52, *(_DWORD *)a1);
              v36 = (retaddr - a1[217] - 0.2) * 0.16;
            }
          }
          else
          {
            v24 = *((_DWORD *)a1 + 2);
            if ( (!v24 || (*(_BYTE *)(v24 + 12) & 1) == 0)
              && (a1[217] + 5.8000002 > retaddr || a1[218] - 0.80000001 - 5.0 < retaddr) )
            {
              sub_4EE320(81, *(_DWORD *)a1);
              sub_4EE320(83, *(_DWORD *)a1);
            }
            v36 = 0.096000001;
          }
        }
        if ( *((_DWORD *)a1 + 211) )
        {
          if ( a1[217] + 2.0 >= retaddr )
          {
            if ( a1[217] + 1.4 < retaddr )
            {
              v27 = *((_DWORD *)a1 + 2);
              if ( v27 && (*(_BYTE *)(v27 + 12) & 1) != 0 )
                sub_4EE320(81, *(_DWORD *)a1);
              else
                sub_4EE320(83, *(_DWORD *)a1);
              sub_4EE320(52, *(_DWORD *)a1);
              v28 = (retaddr - a1[217] - 1.4) * 0.16;
              v37 = v28;
              if ( v28 < 0.0 )
                v37 = 0.0;
            }
          }
          else
          {
            v26 = *((_DWORD *)a1 + 2);
            if ( (!v26 || (*(_BYTE *)(v26 + 12) & 1) == 0) && (a1[217] + 7.0 > retaddr || a1[218] - 2.0 - 5.0 < retaddr) )
            {
              sub_4EE320(82, *(_DWORD *)a1);
              sub_4EE320(84, *(_DWORD *)a1);
            }
            v37 = 0.096000001;
          }
        }
        if ( v36 < 0.0 )
          v36 = 0.0;
        LOBYTE(v10) = sub_578710(*(_DWORD *)a1 + 16, LODWORD(v36), LODWORD(v36), LODWORD(v37), LODWORD(v37));
      }
      else
      {
        if ( a1[218] + 0.1 > retaddr )
          sub_4EE320(87, *(_DWORD *)a1);
        LOBYTE(v10) = sub_578710(*(_DWORD *)a1 + 16, 0, 0, 0, 0);
      }
    }
  }
  else
  {
    if ( *((_DWORD *)a1 + 209) )
    {
      sub_578550(*((_DWORD *)a1 + 206));
      if ( a1[206] > 0.0 && *(_DWORD *)(*(_DWORD *)a1 + 19384) == 9 )
        *(_DWORD *)(*(_DWORD *)a1 + 19384) = 0;
    }
    sub_56AE20(*(_DWORD *)a1 + 2704);
    if ( *((_DWORD *)a1 + 188) != 4 )
    {
      v6 = off_9034A4;
      if ( dword_82F4A0 < 1023 )
      {
        ++dword_82F4A0;
        off_9034A4 += 848;
      }
      v34 = dbl_FB1D18;
      sub_51B2A0(6, 5, 1, *((_DWORD *)a1 + 1), LODWORD(v34), 0);
      *(_BYTE *)(v6 + 8) = 4;
      sub_4FD580();
    }
    v7 = *(_DWORD *)a1;
    if ( *(_DWORD *)(*(_DWORD *)a1 + 14820) )
    {
      sub_577660(v7 + 16, 0);
    }
    else if ( dword_B74C9C == 89 )
    {
      if ( !byte_B6820A )
        byte_B6820A = 1;
      v8 = *((_DWORD *)a1 + 2);
      if ( v8 && (*(_BYTE *)(v8 + 12) & 1) != 0 )
        sub_4EE320(54, *(_DWORD *)a1);
    }
    else if ( !byte_B6820A )
    {
      sub_4EE320(80, v7);
    }
    sub_4EE120(dword_B6F1C8, 89, *(_DWORD *)a1);
    sub_4EE120(dword_B6F1C8, 86, *(_DWORD *)a1);
    sub_4EE120(dword_B6F1C8, 88, *(_DWORD *)a1);
    a1[199] = dbl_FB1D18 - a1[195];
    if ( *(_DWORD *)(*(&dword_91E088 + dword_91E078) + 22468) == *((_DWORD *)a1 + 1)
      && *(_DWORD *)(*(_DWORD *)a1 + 19380) != 1 )
    {
      sub_562430(&dword_FAE988, 6, 0);
    }
    if ( *(_DWORD *)(*(_DWORD *)a1 + 22468) == *(_DWORD *)(dword_91E084 + 22468) )
    {
      v32 = *((float *)dword_91E07C + 3905);
      v9 = sub_41D840(&byte_91CC38, "PIT STOP");
      sprintf((char *const)&Buffer, "%s %.1f", v9, v32);
      sub_4730C0((int **)&dword_B6CB98, (const char *)&Buffer, 3, (int)&byte_1020304, 1094713344);
    }
    if ( *(_DWORD *)(*(_DWORD *)a1 + 14820) == 1 )
    {
      sub_4220E0(*(_DWORD *)a1);
      sub_427C40(*(_DWORD *)a1, 15, 0);
    }
    sub_578710(*(_DWORD *)a1 + 16, 0, 0, 0, 0);
    LOBYTE(v10) = sub_578670(*(_DWORD *)a1 + 16, 0, v30, v31, v33);
    v11 = (_BYTE *)*((_DWORD *)a1 + 2);
    if ( v11 )
    {
      if ( (v11[12] & 1) != 0 )
      {
        LOBYTE(v10) = sub_4F1BF0(v11, 0);
        if ( (_BYTE)v10 )
          LOBYTE(v10) = sub_4F14A0();
      }
    }
  }
  return v10;
}
