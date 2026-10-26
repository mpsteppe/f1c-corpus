void __thiscall sub_446EB0(int this, int a2, int a3)
{
  int v4; // ecx
  int v5; // eax
  int v6; // eax
  double v7; // st7
  int v8; // edx
  double v9; // st7
  unsigned __int8 v11; // c0
  unsigned __int8 v12; // c3
  double v13; // st7
  double v14; // st7
  double v15; // st6
  double v16; // st6
  double v17; // st7
  double v18; // st6
  double v19; // st7
  int v20; // eax
  int v21; // ecx
  int v22; // ecx
  double v23; // st7
  long double v24; // st7
  double v25; // st6
  long double v26; // st7
  double v27; // st7
  double v28; // st7
  double v29; // st7
  int v30; // ecx
  long double v31; // st7
  double v32; // st6
  long double v33; // st7
  double v34; // [esp+8h] [ebp-8h]
  double v35; // [esp+8h] [ebp-8h]
  double v36; // [esp+8h] [ebp-8h]
  int v37; // [esp+8h] [ebp-8h]

  v4 = *(_DWORD *)(this + 8612);
  *(_DWORD *)(this + 24) = 0;
  *(_DWORD *)(this + 28) = 0;
  if ( !v4 )
    goto LABEL_20;
  v5 = *(_DWORD *)(this + 8376);
  if ( v5 )
  {
    v6 = v5 - 1;
    if ( v6 )
    {
      if ( v6 == 1 )
        v7 = (*(double *)(this + 2112) + *(double *)(this + 856)) * -0.5;
      else
        v7 = v34;
    }
    else
    {
      v7 = (*(double *)(this + 4624) + *(double *)(this + 3368) + *(double *)(this + 2112) + *(double *)(this + 856))
         * -0.25;
    }
  }
  else
  {
    v7 = (*(double *)(this + 4624) + *(double *)(this + 3368)) * -0.5;
  }
  v8 = *(_DWORD *)(this + 8608);
  v35 = v7 * *(double *)(this + 8 * (v8 == -1 ? 0 : v8) + 8540);
  v9 = *(double *)(this + 8480) - *(double *)(this + 136);
  *(double *)(this + 8480) = v9;
  if ( v11 | v12 )
    *(_DWORD *)(this + 8604) = v8;
  if ( *(double *)(this + 7936) != v35 )
  {
    if ( *(_BYTE *)(this + 8476) )
    {
      v15 = *(double *)(this + 7936);
      if ( v4 <= 0 )
      {
        if ( v15 < v35 )
        {
          if ( *(double *)(this + 8520) >= *(double *)(this + 8) )
            v16 = *(double *)(this + 8520);
          else
            v16 = *(double *)(this + 8);
          *(double *)(this + 8) = v16;
        }
        if ( v9 >= 0.0 )
          goto LABEL_14;
        if ( v9 > *(double *)(this + 8512) )
        {
          *(double *)(this + 24) = 1.0 - v9 / *(double *)(this + 8512);
          goto LABEL_14;
        }
      }
      else
      {
        if ( v15 > v35 )
        {
          *(_DWORD *)(this + 8) = 0;
          *(_DWORD *)(this + 12) = 0;
        }
        if ( v9 >= 0.0 )
          goto LABEL_14;
        if ( v9 > *(double *)(this + 8496) )
        {
          *(double *)(this + 24) = 1.0 - v9 / *(double *)(this + 8496);
          goto LABEL_14;
        }
      }
      if ( *(double *)(this + 8412) == v35 )
        *(_DWORD *)(this + 8612) = 0;
      goto LABEL_14;
    }
    if ( !a3 )
      goto LABEL_14;
    if ( v4 <= 0 )
    {
      if ( (a2 == 2 || a2 == 3 || (*(_BYTE *)(this + 160) & 2) != 0) && *(double *)(this + 7936) < v35 )
      {
        if ( *(double *)(this + 8520) >= *(double *)(this + 8) )
          v18 = *(double *)(this + 8520);
        else
          v18 = *(double *)(this + 8);
        *(double *)(this + 8) = v18;
      }
      if ( v9 >= 0.0 )
        goto LABEL_14;
      if ( v9 <= *(double *)(this + 8512) )
        goto LABEL_13;
      v17 = v9 / *(double *)(this + 8512);
    }
    else
    {
      if ( (a2 == 1 || a2 == 3 || (*(_BYTE *)(this + 160) & 1) != 0) && *(double *)(this + 7936) > v35 )
      {
        *(_DWORD *)(this + 8) = 0;
        *(_DWORD *)(this + 12) = 0;
      }
      if ( v9 >= 0.0 )
        goto LABEL_14;
      if ( v9 <= *(double *)(this + 8496) )
        goto LABEL_13;
      v17 = v9 / *(double *)(this + 8496);
    }
    v19 = 1.0 - v17;
    if ( v19 > *(double *)(this + 32) )
      *(double *)(this + 32) = v19;
    goto LABEL_14;
  }
  *(_DWORD *)(this + 8604) = v8;
LABEL_13:
  *(_DWORD *)(this + 8612) = 0;
LABEL_14:
  if ( *(int *)(this + 8612) < 0
    && v8 >= 1
    && *(double *)(this + 16) > 0.0
    && *(double *)(this + 428) > 0.0
    && *(double *)(this + 8064) * 0.5 < *(double *)(this + 7936) )
  {
    sub_51BB70(*(_DWORD *)(this + 8620) + 84);
  }
LABEL_20:
  v13 = (double)(*(double *)(this + 7936) > *(double *)(this + 8072));
  if ( v13 != 0.0 || *(_BYTE *)(this + 7933) )
  {
    v36 = *(double *)(this + 8);
    if ( v13 != 0.0 )
    {
      v14 = (*(double *)(this + 8080) - *(double *)(this + 7936))
          / (*(double *)(this + 8080) - *(double *)(this + 8072));
      if ( v14 < *(double *)(this + 8) )
      {
        if ( v14 < 0.0 )
          v14 = 0.0;
        *(double *)(this + 8) = v14;
      }
    }
    if ( *(_BYTE *)(this + 7933) )
    {
      v20 = *(_DWORD *)(this + 8604);
      if ( v20 )
      {
        v21 = *(_DWORD *)(this + 8376);
        if ( v21 )
        {
          v22 = v21 - 1;
          if ( v22 )
            v23 = v22 == 1 ? (*(double *)(this + 2448) + *(double *)(this + 1192)) * 0.5 : v36;
          else
            v23 = (*(double *)(this + 4960)
                 + *(double *)(this + 3704)
                 + *(double *)(this + 2448)
                 + *(double *)(this + 1192))
                * 0.25;
        }
        else
        {
          v23 = (*(double *)(this + 4960) + *(double *)(this + 3704)) * 0.5;
        }
        v24 = fabs(v23 / *(double *)(this + 8 * (v20 == -1 ? 0 : v20) + 8540) * *(double *)(this + 7936));
        v25 = *(_BYTE *)(this + 7932) ? 0.5 : 1.0;
        v26 = (flt_7D74DC - v24) / v25;
        if ( v26 < *(double *)(this + 8) )
        {
          if ( v26 < 0.0 )
            v26 = 0.0;
          *(long double *)(this + 8) = v26;
        }
      }
    }
    v27 = (v36 - *(double *)(this + 8)) * 0.166;
    if ( v27 > *(double *)(this + 384) )
      *(double *)(this + 384) = v27;
  }
  if ( *(double *)(this + 7936) < *(double *)(this + 7984) )
  {
    if ( *(double *)(this + 7936) <= *(double *)(this + 7976) )
      v28 = *(double *)(this + 7968);
    else
      v28 = (*(double *)(this + 7984) - *(double *)(this + 7936))
          * *(double *)(this + 7968)
          / (*(double *)(this + 7984) - *(double *)(this + 7976));
    if ( v28 > *(double *)(this + 8) )
      *(double *)(this + 8) = v28;
    if ( *(double *)(this + 7976) * 0.0078125 >= *(double *)(this + 7936)
      && *(double *)(this + 8116) <= 0.0
      && dword_75CBB4 != 2
      && !byte_76617C
      && !dword_764030
      && dword_764034 == 89
      && (unsigned __int8)sub_4497B0(this) )
    {
      sub_44A530(0, 4);
      sub_449840(0);
    }
  }
  if ( *(double *)(this + 8116) > 0.0 )
  {
    v29 = *(double *)(this + 8116) - *(double *)(this + 136);
    *(double *)(this + 8116) = v29;
    if ( v29 <= 0.0 && *(double *)(this + 7936) < *(double *)(this + 7976) )
    {
      v30 = *(_DWORD *)(this + 7980);
      *(_DWORD *)(this + 7936) = *(_DWORD *)(this + 7976);
      *(_DWORD *)(this + 7940) = v30;
    }
  }
  if ( *(double *)(this + 8272) > 0.0 )
  {
    v31 = fabs(fmod(11.5 / *(double *)(this + 8064) * dbl_7DA9D0 * *(double *)(this + 7936), 2147483647.0));
    v37 = (__int64)v31;
    v32 = flt_7D3C54[(unsigned __int8)v37];
    v33 = (flt_7D3C54[(unsigned __int8)(v37 + 1)] - v32) * (v31 - (double)v37) + v32;
    *(long double *)(this + 8) = (1.0 - v33 * *(double *)(this + 8272) * v33) * *(double *)(this + 8);
  }
  *(double *)(this + 8) = sub_44A230(this) * *(double *)(this + 8);
}
