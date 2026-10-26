int __thiscall sub_560FE0(int this, int a2, int a3)
{
  _DWORD *v4; // edi
  int v5; // ebp
  int v6; // eax
  int v8; // eax
  _DWORD *v9; // eax
  int v10; // eax
  int v11; // ecx
  long double v12; // st7
  double v13; // st7
  double v14; // st7
  double v15; // st7
  _DWORD *v16; // eax
  int v17; // eax
  int v18; // ecx
  long double v19; // st7
  double v20; // st7
  double v21; // st7
  double v22; // st7
  int v23; // eax
  float v24; // [esp+0h] [ebp-34h]
  float v25; // [esp+0h] [ebp-34h]
  int v26; // [esp+4h] [ebp-30h]
  int v27; // [esp+4h] [ebp-30h]
  float v28; // [esp+4h] [ebp-30h]
  int v29; // [esp+4h] [ebp-30h]
  int v30; // [esp+4h] [ebp-30h]
  float v31; // [esp+4h] [ebp-30h]
  int v32; // [esp+8h] [ebp-2Ch]
  int v33; // [esp+8h] [ebp-2Ch]
  float v34; // [esp+8h] [ebp-2Ch]
  int v35; // [esp+8h] [ebp-2Ch]
  int v36; // [esp+8h] [ebp-2Ch]
  float v37; // [esp+8h] [ebp-2Ch]
  float v38; // [esp+18h] [ebp-1Ch]
  float v39; // [esp+18h] [ebp-1Ch]
  float v40; // [esp+1Ch] [ebp-18h] BYREF
  float v41; // [esp+20h] [ebp-14h] BYREF
  float v42; // [esp+24h] [ebp-10h] BYREF
  float v43; // [esp+28h] [ebp-Ch] BYREF
  float v44; // [esp+2Ch] [ebp-8h] BYREF
  float v45; // [esp+30h] [ebp-4h] BYREF

  v4 = **(_DWORD ***)(this + 12);
  v5 = 0;
  if ( sub_55C9B0(dword_8B78A0) )
  {
    if ( (*(_BYTE *)(this + 36) & 4) != 0 )
      *(_DWORD *)(this + 16) = v4[89]
                             + 96
                             * *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 24) + 312) + 64) + 560)
                                         + 40);
    else
      *(_DWORD *)(this + 16) = v4[89] + 96 * *(_DWORD *)(this + 40);
  }
  else
  {
    *(_DWORD *)(this + 16) = v4[89];
  }
  sub_542560(*(int **)(this + 12), *(_DWORD *)(*(_DWORD *)(this + 16) + 84));
  v6 = *(_DWORD *)(*(_DWORD *)(this + 12) + 412);
  if ( !v6 )
    return -2;
  if ( (*(_DWORD *)(v6 + 24) & 0x40000) == 0 )
    return -2;
  v8 = *(_DWORD *)(this + 24);
  if ( (*(_BYTE *)(*(_DWORD *)(v8 + 312) + 60) & 2) == 0 )
  {
    if ( (*(_BYTE *)(v8 + 20) & 5) != 0 )
    {
      if ( (*(_BYTE *)(this + 36) & 4) != 0 )
      {
        sub_55C070(dword_8B78A0, this, 0);
        goto LABEL_24;
      }
      v9 = (_DWORD *)sub_5457C0(v4, 0);
      sub_55D590(v9, &v43, &v44, &v45);
      v10 = *(_DWORD *)(this + 24);
      v11 = *(_DWORD *)(this + 12);
      v12 = fabs(atan2(*(float *)(v10 + 24) * 1.2, flt_5DD848));
      v38 = v12 + v12;
      if ( *(_DWORD *)(v10 + 316) )
      {
        sub_542050(v11, v38, v38, 1);
        v13 = *(float *)(*(_DWORD *)(this + 24) + 24) + *(float *)(*(_DWORD *)(this + 24) + 24);
        *(float *)&v32 = flt_5DD848 + v13;
        *(float *)&v26 = flt_5DD848 - v13;
        sub_5423C0(*(_DWORD *)(this + 12), v26, v32);
        sub_54B950(*(_DWORD **)(*(_DWORD *)(this + 24) + 312), &v40, &v41, &v42);
      }
      else
      {
        sub_542050(v11, v38, v38, 1);
        v14 = *(float *)(*(_DWORD *)(this + 24) + 24);
        v15 = v14 + v14;
        *(float *)&v33 = flt_5DD848 + v15;
        *(float *)&v27 = flt_5DD848 - v15;
        sub_5423C0(*(_DWORD *)(this + 12), v27, v33);
        sub_54B420(*(_DWORD **)(*(_DWORD *)(this + 24) + 312), &v40, &v41, &v42);
      }
      v34 = flt_5DD848 * v45 - v42;
      v28 = flt_5DD848 * v44 - v41;
      v24 = flt_5DD848 * v43 - v40;
      sub_541D10(*(_DWORD *)(this + 12), v24, v28, v34);
      sub_541B70(*(_DWORD *)(this + 12), 14);
      sub_541A70(*(float **)(this + 12));
      sub_55C070(dword_8B78A0, this, 0);
    }
    else
    {
      if ( !*(_DWORD *)(this + 44) )
        goto LABEL_24;
      v16 = (_DWORD *)sub_5457C0(v4, 0);
      sub_55D590(v16, &v43, &v44, &v45);
      v17 = *(_DWORD *)(this + 24);
      v18 = *(_DWORD *)(this + 12);
      v19 = fabs(atan2(*(float *)(v17 + 24) * 1.2, flt_5DD848));
      v39 = v19 + v19;
      if ( *(_DWORD *)(v17 + 316) )
      {
        sub_542050(v18, v39, v39, 1);
        v20 = *(float *)(*(_DWORD *)(this + 24) + 24) + *(float *)(*(_DWORD *)(this + 24) + 24);
        *(float *)&v35 = flt_5DD848 + v20;
        *(float *)&v29 = flt_5DD848 - v20;
        sub_5423C0(*(_DWORD *)(this + 12), v29, v35);
        sub_54B950(*(_DWORD **)(*(_DWORD *)(this + 24) + 312), &v40, &v41, &v42);
      }
      else
      {
        sub_542050(v18, v39, v39, 1);
        v21 = *(float *)(*(_DWORD *)(this + 24) + 24);
        v22 = v21 + v21;
        *(float *)&v36 = flt_5DD848 + v22;
        *(float *)&v30 = flt_5DD848 - v22;
        sub_5423C0(*(_DWORD *)(this + 12), v30, v36);
        sub_54B420(*(_DWORD **)(*(_DWORD *)(this + 24) + 312), &v40, &v41, &v42);
      }
      v37 = flt_5DD848 * v45 - v42;
      v31 = flt_5DD848 * v44 - v41;
      v25 = flt_5DD848 * v43 - v40;
      sub_541D10(*(_DWORD *)(this + 12), v25, v31, v37);
      sub_541B70(*(_DWORD *)(this + 12), 14);
      sub_541A70(*(float **)(this + 12));
      sub_55C070(dword_8B78A0, this, 16);
      v5 = -2;
    }
    *(_DWORD *)(this + 36) |= 8u;
LABEL_24:
    v23 = *(_DWORD *)(*(_DWORD *)(this + 12) + 412);
    if ( (*(_BYTE *)(v23 + 24) & 2) != 0 )
    {
      sub_540240(v23, 2, 4);
      *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 12) + 412) + 24) &= ~0x400u;
    }
    goto LABEL_27;
  }
  v5 = -2;
LABEL_27:
  if ( *(_DWORD *)(this + 44) )
    sub_560FE0(a2, 1);
  if ( *(_DWORD *)(this + 52) )
  {
    if ( a3 )
      sub_560FE0(a2, 1);
  }
  return v5;
}
