double __thiscall sub_42C430(int this, int a2, int a3)
{
  int v5; // ebp
  float *v6; // ebx
  int v7; // ebp
  int v8; // eax
  double v9; // st6
  double v10; // st4
  double v11; // st7
  unsigned __int8 v13; // c0
  unsigned __int8 v14; // c2
  float *v15; // edi
  double v16; // st7
  double v17; // st7
  double v18; // st7
  double v19; // st6
  double v20; // st5
  double v21; // st4
  int v22; // eax
  float *v23; // eax
  int v24; // edi
  double v25; // st7
  double v26; // st7
  double v27; // st6
  double v28; // st5
  double v29; // st4
  double v30; // st7
  int v31; // eax
  int v32; // eax
  float v34; // [esp+0h] [ebp-3Ch]
  int v35; // [esp+0h] [ebp-3Ch]
  int v36; // [esp+0h] [ebp-3Ch]
  float v37; // [esp+14h] [ebp-28h]
  float v38; // [esp+14h] [ebp-28h]
  float v39; // [esp+14h] [ebp-28h]
  float v40; // [esp+14h] [ebp-28h]
  float v41; // [esp+18h] [ebp-24h]
  float v42; // [esp+18h] [ebp-24h]
  float v43; // [esp+1Ch] [ebp-20h]
  int v44; // [esp+20h] [ebp-1Ch]
  float v45; // [esp+24h] [ebp-18h]
  float v46; // [esp+24h] [ebp-18h]
  float v47; // [esp+24h] [ebp-18h]
  float v48; // [esp+24h] [ebp-18h]
  float v49; // [esp+28h] [ebp-14h]
  float v50; // [esp+28h] [ebp-14h]
  float v51; // [esp+28h] [ebp-14h]
  float v52; // [esp+2Ch] [ebp-10h]
  float v53; // [esp+2Ch] [ebp-10h]
  float v54; // [esp+2Ch] [ebp-10h]
  float v55; // [esp+38h] [ebp-4h]
  float v56; // [esp+40h] [ebp+4h]
  float v57; // [esp+40h] [ebp+4h]
  float v58; // [esp+44h] [ebp+8h]

  v37 = *(float *)(this + 23764);
  v5 = a2;
  v6 = 0;
  v56 = flt_7D74E0;
  v41 = 10.0;
  if ( dword_75CBB4 == 3 )
  {
    v7 = (unsigned __int8)sub_42DBA0(&unk_62BF64) != 0 ? dword_75AACC : 0;
    v44 = sub_4F8370(*(_DWORD *)(this + 80));
    v8 = sub_4F8370(v7);
    v5 = a2;
    if ( v8 < v44 )
      v41 = 2.0;
  }
  if ( a2 == -2 )
  {
    v5 = -2;
    if ( (unsigned __int8)sub_4BBF20(&unk_766220) )
    {
      v55 = *((float *)off_5FD348 + 4427) * 0.40000001;
      v45 = *((float *)off_5FD348 + 4425) * 0.40000001 + *((float *)off_5FD348 + 4407);
      v9 = v55 + *((float *)off_5FD348 + 4409);
      v10 = *((float *)off_5FD348 + 4426) * 0.40000001 + *((float *)off_5FD348 + 4408);
      v37 = sqrt(v9 * v9 + v10 * v10 + v45 * v45);
      if ( v37 >= 10.0 )
        v56 = v37;
      else
        v56 = 10.0;
      v46 = *((float *)off_5FD348 + 4401) - *(float *)(this + 17604);
      v49 = *((float *)off_5FD348 + 4402) - *(float *)(this + 17608);
      v52 = *((float *)off_5FD348 + 4403) - *(float *)(this + 17612);
      if ( *(_DWORD *)(sub_427FF0(this) + 328) || *(_DWORD *)(sub_427FF0((int)off_5FD348) + 328) )
        goto LABEL_16;
      v11 = sub_424BC0((float *)this, (int)off_5FD348);
      v43 = v11;
      if ( v13 | v14 && *(int *)(this + 21116) < 0 )
      {
        v11 = 500.0;
        goto LABEL_31;
      }
      if ( v11 < 50.0 && v11 > -50.0 )
      {
LABEL_16:
        v11 = v52 * *(float *)(*(_DWORD *)(this + 23432) + 220)
            + v49 * *(float *)(*(_DWORD *)(this + 23432) + 216)
            + v46 * *(float *)(*(_DWORD *)(this + 23432) + 212);
        v43 = v11;
      }
      if ( v11 < 10.0 )
      {
        if ( v11 < 0.0 )
          v11 = 0.0;
        v34 = v37 - (2.0 - v11 * 0.1);
        sub_427B50((float *)this, v34);
        v11 = v43;
      }
    }
    else
    {
      v11 = 100.0;
    }
  }
  else
  {
    v15 = (float *)((char *)&unk_62BF68 + 25304 * a2);
    v6 = v15;
    v16 = v15[5942] * 7.0;
    if ( v16 > 0.0 )
      v16 = 0.0;
    v37 = v15[5941] + v16;
    if ( v41 <= (double)v37 )
      v56 = v15[5941] + v16;
    else
      v56 = v41;
    v47 = v15[4401] - *(float *)(this + 17604);
    v50 = v15[4402] - *(float *)(this + 17608);
    v53 = v15[4403] - *(float *)(this + 17612);
    if ( *(_DWORD *)(sub_427FF0(this) + 328) || (v17 = sub_424BC0((float *)this, (int)v15), v17 < 50.0) )
      v17 = v53 * *(float *)(*(_DWORD *)(this + 23432) + 220)
          + v50 * *(float *)(*(_DWORD *)(this + 23432) + 216)
          + v47 * *(float *)(*(_DWORD *)(this + 23432) + 212);
    v11 = v17 - 6.0;
  }
LABEL_31:
  v42 = 0.44999999;
  if ( v11 < 30.0 )
    v42 = 0.5;
  if ( v11 < 0.0 )
  {
    v11 = v11 * 5.0;
    v37 = v37 + v11;
  }
  v18 = v11 + 50.0;
  if ( v18 < 0.0 || v18 <= 125.0 )
  {
    if ( v18 < 0.0 )
      v18 = 0.0;
  }
  else
  {
    v18 = 125.0;
  }
  v19 = flt_7D74E0 + v37 - *(float *)(this + 23764);
  if ( v19 >= 0.0 )
    v20 = v19;
  else
    v20 = 0.0;
  v21 = flt_7D74E0 + flt_7D74E0;
  if ( v21 >= v20 )
  {
    if ( v19 < 0.0 )
      v19 = 0.0;
  }
  else
  {
    v38 = v21;
    v19 = v38;
  }
  if ( v19 + 5.0 < *(float *)(this + 23764) )
    v18 = v18 - (*(float *)(this + 23764) - v19);
  v57 = ((1.0 - v42) * v19 / flt_7D74E0 + v42 * v18 * 0.02) * v56 * 0.94999999;
  if ( a3 >= 0 )
  {
    v22 = sub_4F82E0((char *)&unk_62BF68 + 25304 * a3);
    if ( v22 >= 0 )
    {
      v23 = (float *)((char *)&unk_62BF68 + 25304 * v22);
      v24 = (int)v23;
      if ( v5 < 0 )
        return v57;
      v39 = v23[5941];
      if ( v39 >= 10.0 )
        v58 = v23[5941];
      else
        v58 = 10.0;
      v48 = v23[4401] - *(float *)(this + 17604);
      v51 = v23[4402] - *(float *)(this + 17608);
      v54 = v23[4403] - *(float *)(this + 17612);
      if ( *(_DWORD *)(sub_427FF0(this) + 328) || (v25 = sub_424BC0((float *)this, v24), v25 < 50.0) )
        v25 = v54 * *(float *)(*(_DWORD *)(this + 23432) + 220)
            + v51 * *(float *)(*(_DWORD *)(this + 23432) + 216)
            + v48 * *(float *)(*(_DWORD *)(this + 23432) + 212);
      v26 = v25 - 8.0 + 50.0;
      if ( v26 < 0.0 || v26 <= 100.0 )
      {
        if ( v26 < 0.0 )
          v26 = 0.0;
      }
      else
      {
        v26 = 100.0;
      }
      v27 = flt_7D74E0 + v39 - *(float *)(this + 23764);
      if ( v27 >= 0.0 )
        v28 = v27;
      else
        v28 = 0.0;
      v29 = flt_7D74E0 + flt_7D74E0;
      if ( v29 >= v28 )
      {
        if ( v27 < 0.0 )
          v27 = 0.0;
      }
      else
      {
        v40 = v29;
        v27 = v40;
      }
      v30 = (v27 * 0.5 / flt_7D74E0 + v26 * 0.0099999998) * v58;
      if ( v57 >= v30 )
        v57 = v30;
    }
  }
  if ( v5 >= 0 && dword_75CBAC != 2 && (unsigned __int8)sub_4EED40((char *)&unk_62BF68 + 25304 * v5) )
  {
    if ( v6 )
    {
      v35 = sub_4F8320(v6);
      v31 = sub_4F82E0(v6);
      if ( sub_42C430(v31, v35) <= v57 )
      {
        v36 = sub_4F8320(v6);
        v32 = sub_4F82E0(v6);
        return sub_42C430(v32, v36);
      }
    }
    else if ( sub_42C430(-2, -2) <= v57 )
    {
      return sub_42C430(-2, -2);
    }
  }
  return v57;
}
