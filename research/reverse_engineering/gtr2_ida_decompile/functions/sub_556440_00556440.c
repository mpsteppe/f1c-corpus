void __thiscall sub_556440(float *this)
{
  float *v1; // ebp
  _DWORD *v2; // eax
  _DWORD *v3; // esi
  int v4; // eax
  int i; // edi
  int v6; // eax
  _DWORD *v7; // ecx
  int v8; // eax
  _DWORD *v9; // ecx
  _DWORD *v10; // eax
  int v11; // ecx
  int v12; // edi
  int v13; // ecx
  double v15; // st7
  unsigned __int8 v16; // c0
  unsigned __int8 v17; // c2
  double v18; // st7
  double v19; // st7
  double v20; // st7
  _DWORD *v21; // ecx
  _DWORD *v22; // eax
  _DWORD *v23; // ecx
  _DWORD *v24; // esi
  int v25; // edx
  _DWORD *v26; // eax
  double v27; // st7
  double v28; // st7
  double v29; // st7
  bool v30; // bl
  _DWORD *v31; // eax
  _DWORD *v32; // esi
  _DWORD *v33; // eax
  _DWORD *v34; // edi
  char v35; // bl
  _DWORD *v36; // esi
  int v37; // ebp
  unsigned int *v38; // edi
  int v39; // eax
  int v40; // eax
  int v41; // eax
  _DWORD *v42; // eax
  _DWORD *v43; // ebx
  int v44; // esi
  int v45; // [esp+0h] [ebp-38h]
  int v46; // [esp+4h] [ebp-34h]
  int v47; // [esp+4h] [ebp-34h]
  int v48; // [esp+4h] [ebp-34h]
  int v49; // [esp+4h] [ebp-34h]
  float v50; // [esp+Ch] [ebp-2Ch]
  float v51; // [esp+1Ch] [ebp-1Ch]
  float v52; // [esp+20h] [ebp-18h]
  __int16 v53; // [esp+20h] [ebp-18h]
  int v54; // [esp+24h] [ebp-14h]
  char v55; // [esp+24h] [ebp-14h]
  float v56; // [esp+28h] [ebp-10h]
  float v57; // [esp+28h] [ebp-10h]
  float v58; // [esp+2Ch] [ebp-Ch]
  float v59; // [esp+2Ch] [ebp-Ch]
  float v60; // [esp+30h] [ebp-8h]
  float v61; // [esp+30h] [ebp-8h]
  int v62; // [esp+30h] [ebp-8h]

  v1 = this;
  if ( !*((_DWORD *)this + 85) )
    return;
  v2 = (_DWORD *)*((_DWORD *)this + 84);
  v3 = (_DWORD *)*v2;
  if ( (_DWORD *)*v2 != v2 )
  {
    do
    {
      sub_42F750((_DWORD *)v3[2], 0);
      v3 = (_DWORD *)*v3;
    }
    while ( v3 != *((_DWORD **)v1 + 84) );
  }
  v4 = dword_757C10;
  for ( i = 0; i < dword_757C10; ++i )
  {
    v6 = *(&dword_91E088 + i);
    if ( *(_BYTE *)(v6 + 19596) )
    {
      v60 = sub_577BC0(v6 + 16);
      if ( *((_DWORD *)v1 + 85) )
      {
        v8 = *((_DWORD *)v1 + 84);
        v9 = *(_DWORD **)v8;
        if ( *(_DWORD *)v8 == v8 )
        {
LABEL_11:
          v7 = *(_DWORD **)(*(_DWORD *)v8 + 8);
        }
        else
        {
          while ( v60 >= (double)*(float *)(v9[2] + 104) )
          {
            v9 = (_DWORD *)*v9;
            if ( v9 == *((_DWORD **)v1 + 84) )
              goto LABEL_11;
          }
          v7 = (_DWORD *)v9[2];
        }
      }
      else
      {
        v7 = 0;
      }
      sub_42F750(v7, 5);
    }
    v4 = dword_757C10;
  }
  if ( dword_B64134 == 8 )
  {
    v10 = (_DWORD *)*((_DWORD *)v1 + 84);
    v11 = *(_DWORD *)(v10[1] + 8);
    if ( flt_91BDE4 - *(float *)(v11 + 104) >= *(float *)(*(_DWORD *)(*v10 + 8) + 104) )
      v11 = *(_DWORD *)(*v10 + 8);
    sub_42F750((_DWORD *)v11, 8);
  }
  else if ( v4 > 0 )
  {
    v50 = v1[56] - dbl_FB1D18 + 0.5;
    sub_4015C0(v50);
    off_16C9734();
    return;
  }
  v52 = 0.0;
  v54 = 0;
  if ( dword_757C10 > 0 )
  {
    while ( 1 )
    {
      v12 = *(&dword_91E088 + v54);
      if ( *(_DWORD *)(v12 + 19380) != 2 )
      {
        v13 = *(_DWORD *)(v12 + 17492);
        if ( v13 )
          break;
      }
LABEL_64:
      if ( ++v54 >= dword_757C10 )
        goto LABEL_65;
    }
    if ( *(_DWORD *)(v13 + 304) )
    {
      if ( *(_BYTE *)(v12 + 15572) )
      {
        v51 = -1.0;
        goto LABEL_33;
      }
      v18 = v1[68] * 0.25;
    }
    else
    {
      v15 = *(float *)(v13 + 144);
      if ( v16 | v17 )
        v18 = v15 - 60.0;
      else
        v18 = v15 * 0.22499999;
    }
    v51 = v18;
LABEL_33:
    if ( *(_DWORD *)dword_B640C8 == 6 && dword_B64134 == 5 && dbl_FB1D18 < v1[55] + 20.0 )
    {
      v19 = (dbl_FB1D18 - v1[55]) * 6.0 - 10.0;
      if ( v51 > v19 )
        v51 = v19;
    }
    v20 = *(float *)(v12 + 16020) * *(float *)(v13 + 176)
        + *(float *)(v12 + 16016) * *(float *)(v13 + 172)
        + *(float *)(v12 + 16012) * *(float *)(v13 + 168);
    v56 = v20;
    if ( v20 < v51 )
    {
      v58 = sub_577BC0(v12 + 16);
      if ( *((_DWORD *)v1 + 85) )
      {
        v22 = (_DWORD *)*((_DWORD *)v1 + 84);
        v23 = (_DWORD *)*v22;
        v24 = *(_DWORD **)(v22[1] + 8);
        if ( (_DWORD *)*v22 != v22 )
        {
          do
          {
            v25 = v23[2];
            if ( v58 < (double)*(float *)(v25 + 104) )
              break;
            v23 = (_DWORD *)*v23;
            v24 = (_DWORD *)v25;
          }
          while ( v23 != *((_DWORD **)v1 + 84) );
        }
        v21 = v24;
      }
      else
      {
        v21 = 0;
      }
      if ( !*(_DWORD *)(v12 + 19284) )
      {
        v26 = (_DWORD *)*((_DWORD *)v1 + 84);
        if ( v21 == *(_DWORD **)(v26[1] + 8) )
          v21 = *(_DWORD **)(*v26 + 8);
      }
      sub_42F750(v21, 2);
      v61 = 0.050000001;
      if ( v51 >= 1.0 )
        v27 = v51;
      else
        v27 = 1.0;
      v28 = v56 / v27;
      if ( v28 >= 0.0 )
      {
        if ( v28 > 1.0 )
          v28 = 1.0;
      }
      else
      {
        v28 = 0.0;
      }
      v57 = 1.0 - v28;
      v29 = v57 * 0.1;
      v52 = v29 + v52;
      if ( !(unsigned __int8)sub_577B20(v12 + 16) )
      {
        v52 = v57 * 0.2 + v52;
        v59 = v29;
        v61 = v59 + 0.050000001;
      }
      if ( *(float *)(v12 + 19204) > 0.0
        || *(float *)(v12 + 17228) < 10.0
        || !*(_BYTE *)(v12 + 3232)
        || !*(_BYTE *)(v12 + 3528)
        || !*(_BYTE *)(v12 + 3824)
        || !*(_BYTE *)(v12 + 4120) )
      {
        v52 = v61 + v52;
      }
    }
    goto LABEL_64;
  }
LABEL_65:
  if ( *(_DWORD *)dword_B640C8 == 6 && dword_B704D4 == 2 )
  {
    v30 = 0;
    v55 = 0;
    if ( v52 > (double)flt_B70390
      && dword_924FF4[5654 * *((unsigned __int8 *)v1 + 368)] < *((_DWORD *)v1 + 54) - 1
      && v1[56] - 2.0 > dbl_FB1D18 )
    {
      v30 = byte_B702B8 == 1;
      v55 = byte_B702B8 == 1;
    }
    if ( (unsigned __int8)sub_4735A0() )
    {
      v55 = 0;
    }
    else if ( v30 )
    {
LABEL_75:
      sub_553980(v1, v55, -1);
      goto LABEL_76;
    }
    if ( !*((_DWORD *)v1 + 87) )
      goto LABEL_76;
    goto LABEL_75;
  }
LABEL_76:
  if ( dword_B64134 == 7 )
  {
    v31 = (_DWORD *)*((_DWORD *)v1 + 84);
    v32 = (_DWORD *)*v31;
    if ( (_DWORD *)*v31 != v31 )
    {
      do
      {
        sub_42F750((_DWORD *)v32[2], 3);
        v32 = (_DWORD *)*v32;
      }
      while ( v32 != *((_DWORD **)v1 + 84) );
    }
  }
  v33 = (_DWORD *)*((_DWORD *)v1 + 84);
  v34 = (_DWORD *)*v33;
  v35 = 0;
  if ( (_DWORD *)*v33 != v33 )
  {
    do
    {
      v36 = (_DWORD *)v34[2];
      v37 = sub_42F760(v36);
      if ( sub_42F670(v36) != v37 )
      {
        sub_42F670(v36);
        sub_42F760(v36);
        sub_42F770(v36);
        v35 = 1;
      }
      v1 = this;
      v34 = (_DWORD *)*v34;
    }
    while ( v34 != *((_DWORD **)this + 84) );
    if ( v35 )
      goto LABEL_85;
  }
  if ( dbl_FB1D18 - v1[86] > 5.0 )
  {
LABEL_85:
    v1[86] = dbl_FB1D18;
    v38 = (unsigned int *)off_9034A4;
    if ( dword_82F4A0 < 1023 )
    {
      ++dword_82F4A0;
      off_9034A4 += 848;
    }
    *(float *)&v46 = dbl_FB1D18;
    sub_51B2A0(v38, 4, 10, 0, 255, v46, 0);
    v39 = *(_DWORD *)(dword_91E084 + 19288);
    if ( v39 == 2 )
      v40 = 0;
    else
      v40 = v39 + 1;
    if ( v40 )
    {
      v41 = v40 - 1;
      if ( v41 )
      {
        if ( v41 == 1 )
        {
          v47 = sub_555590();
          sub_4EE4E0(dword_B6F1C8, 2, v47);
        }
      }
      else
      {
        v48 = sub_555590();
        sub_4EE4E0(dword_B6F1C8, 1, v48);
      }
    }
    else
    {
      v49 = sub_555590();
      sub_4EE4E0(dword_B6F1C8, 0, v49);
    }
    v42 = (_DWORD *)*((_DWORD *)v1 + 84);
    v43 = (_DWORD *)*v42;
    v44 = 0;
    v53 = 0;
    if ( (_DWORD *)*v42 != v42 )
    {
      do
      {
        v62 = sub_42F670((_DWORD *)v43[2]);
        if ( v62 )
        {
          if ( v44 >= 16 )
          {
            v38 = (unsigned int *)off_9034A4;
            if ( dword_82F4A0 < 1023 )
            {
              ++dword_82F4A0;
              off_9034A4 += 848;
            }
            *(float *)&v45 = dbl_FB1D18;
            sub_51B2A0(v38, 4, 11, 0, 255, v45, 0);
            v44 = 0;
          }
          *((_WORD *)v38 + v44++ + 4) = v62 + (v53 << 6);
          *v38 = (v44 << 9) | *v38 & 0xFFFC00FF;
        }
        v43 = (_DWORD *)*v43;
        ++v53;
      }
      while ( v43 != *((_DWORD **)v1 + 84) );
    }
  }
}
