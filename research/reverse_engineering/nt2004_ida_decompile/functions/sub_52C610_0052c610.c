int __thiscall sub_52C610(float *this, int a2)
{
  int v3; // ecx
  int v4; // ecx
  int v6; // ebp
  const char *v7; // eax
  const char *v8; // ebp
  int v9; // edi
  int v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  const char *v13; // eax
  int v14; // eax
  int v16; // eax
  char *v17; // eax
  int v18; // eax
  char *v19; // eax
  double v20; // st7
  int v21; // eax
  char *v22; // eax
  int v23; // eax
  char *v24; // eax
  int v25; // eax
  char *v26; // eax
  double v27; // st7
  int v28; // eax
  char *v29; // eax
  _DWORD *v30; // eax
  _DWORD *v31; // eax
  int v32; // eax
  int v33; // edi
  int v34; // ecx
  const char *v35; // eax
  double i; // st7
  _DWORD *v37; // eax
  _DWORD *v38; // eax
  float *v39; // eax
  int v40; // eax
  char *v41; // eax
  int v42; // eax
  char *v43; // eax
  int v44; // eax
  const char *v45; // eax
  int v46; // eax
  const char *v47; // eax
  const char *v48; // eax
  const char *v49; // [esp-4h] [ebp-30h]
  float v50; // [esp+10h] [ebp-1Ch]
  float v51; // [esp+10h] [ebp-1Ch]
  int v52; // [esp+14h] [ebp-18h]
  int v53; // [esp+18h] [ebp-14h]
  char *String2; // [esp+1Ch] [ebp-10h]
  char *v55; // [esp+20h] [ebp-Ch]
  char *v56; // [esp+24h] [ebp-8h]
  char *v57; // [esp+28h] [ebp-4h]
  int v58; // [esp+30h] [ebp+4h]
  float v59; // [esp+30h] [ebp+4h]

  v50 = 0.34999999;
  String2 = sub_42F570(dword_75CBB0, 0);
  v55 = 0;
  v56 = 0;
  v57 = sub_42F570(7, 0);
  switch ( dword_75CBB0 )
  {
    case 1:
    case 7:
      v4 = 5;
      goto LABEL_8;
    case 2:
      v3 = 1;
      goto LABEL_6;
    case 3:
    case 4:
      v55 = sub_42F570(5, 0);
      v56 = sub_42F570(1, 0);
      break;
    case 5:
      v4 = 1;
LABEL_8:
      v55 = sub_42F570(v4, 0);
      break;
    case 6:
      v3 = 7;
LABEL_6:
      v55 = sub_42F570(v3, 0);
      v56 = sub_42F570(5, 0);
      break;
    default:
      break;
  }
  v6 = 0;
  while ( 1 )
  {
    if ( (&String2)[v6] )
    {
      a2 = sub_57A720((&String2)[v6]);
      if ( a2 )
        break;
    }
    if ( ++v6 >= 4 )
      goto LABEL_25;
  }
  v53 = (__int64)(100.0 / flt_7D74C4 + 0.5);
  v7 = (const char *)sub_57A6D0(a2);
  v58 = atol(v7);
  if ( v58 <= 0 )
    v58 = 100;
  v8 = (&String2)[v6];
  v9 = a2;
  v52 = a2;
  while ( 1 )
  {
    v10 = sub_5A97F0(v9);
    v9 = v10;
    if ( !v10 )
      break;
    v49 = (const char *)sub_57A6C0(v10);
    v11 = (const char *)sub_57A6C0(v52);
    if ( !_strcmpi(v11, v49) )
    {
      v12 = (const char *)sub_57A6C0(v9);
      if ( !_strcmpi(v12, v8) )
      {
        v13 = (const char *)sub_57A6D0(v9);
        v14 = atol(v13);
        if ( v14 <= 0 )
          v14 = 100;
        if ( v14 >= v53 && v14 < v58 )
        {
          a2 = v9;
          v58 = v14;
        }
      }
    }
  }
LABEL_25:
  if ( !a2 )
    return -1;
  this[7] = 0.0;
  this[8] = 0.0;
  this[9] = 0.0;
  this[10] = 0.0;
  this[11] = 20.0;
  this[12] = 22.0;
  v16 = sub_57A720(aConditions);
  if ( v16 )
  {
    v17 = (char *)sub_57A6D0(v16);
    v50 = sub_52C390(v17);
    sub_52C0C0((int)this, v50);
  }
  v18 = sub_57A720(aTrackwetness);
  if ( v18 )
  {
    v19 = (char *)sub_57A6D0(v18);
    v20 = sub_52C4A0(v19);
    this[9] = v20;
    this[10] = v20;
  }
  v21 = sub_57A720(aOnpathwetness);
  if ( v21 )
  {
    v22 = (char *)sub_57A6D0(v21);
    this[9] = sub_52C4A0(v22);
  }
  v23 = sub_57A720(aOffpathwetness);
  if ( v23 )
  {
    v24 = (char *)sub_57A6D0(v23);
    this[10] = sub_52C4A0(v24);
  }
  if ( this[10] < (double)this[9] )
    this[10] = this[9];
  v25 = sub_57A720(aAmbienttemp);
  if ( v25 )
  {
    v26 = (char *)sub_57A6D0(v25);
    v27 = sub_52C570(v26);
    this[11] = v27;
    this[12] = v27 + 2.0;
  }
  v28 = sub_57A720(aTracktemp);
  if ( v28 )
  {
    v29 = (char *)sub_57A6D0(v28);
    this[12] = sub_52C570(v29);
  }
  v30 = operator new(0x10u);
  if ( v30 )
    v31 = sub_52AC20(v30);
  else
    v31 = 0;
  *((_DWORD *)this + 14) = v31;
  *v31 = 0;
  *(float *)(*((_DWORD *)this + 14) + 4) = this[11];
  *(float *)(*((_DWORD *)this + 14) + 8) = v50;
  this[13] = this[14];
  v59 = flt_6290DC;
  if ( flt_6290DC < 16.0 || flt_6290DC > 1024.0 )
    v59 = 92.0;
  v32 = sub_57A720(aMinute);
  v33 = v32;
  if ( v32 )
  {
    v34 = v32;
LABEL_60:
    v47 = (const char *)sub_57A6D0(v34);
    for ( i = atof(v47) * 60.0; ; i = atof(v35) * v59 )
    {
      v37 = operator new(0x10u);
      if ( v37 )
        v38 = sub_52AC20(v37);
      else
        v38 = 0;
      *(_DWORD *)(*((_DWORD *)this + 13) + 12) = v38;
      *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 13) + 12) + 4) = *(_DWORD *)(*((_DWORD *)this + 13) + 4);
      *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 13) + 12) + 8) = *(_DWORD *)(*((_DWORD *)this + 13) + 8);
      v39 = *(float **)(*((_DWORD *)this + 13) + 12);
      *((_DWORD *)this + 13) = v39;
      v51 = i;
      *v39 = v51;
      *(_DWORD *)(*((_DWORD *)this + 13) + 12) = 0;
      v40 = sub_57A720(aConditions);
      if ( v40 )
      {
        v41 = (char *)sub_57A6D0(v40);
        *(float *)(*((_DWORD *)this + 13) + 8) = sub_52C390(v41);
      }
      v42 = sub_57A720(aAmbienttemp);
      if ( v42 )
      {
        v43 = (char *)sub_57A6D0(v42);
        *(float *)(*((_DWORD *)this + 13) + 4) = sub_52C570(v43);
      }
      v44 = sub_5A97F0(v33);
      v33 = v44;
      if ( !v44 )
        break;
      v45 = (const char *)sub_57A6C0(v44);
      v46 = _strcmpi(v45, aMinute);
      v34 = v33;
      if ( !v46 )
        goto LABEL_60;
      v48 = (const char *)sub_57A6C0(v33);
      if ( _strcmpi(v48, off_5FD3B4) )
        break;
LABEL_50:
      v35 = (const char *)sub_57A6D0(v33);
    }
  }
  else
  {
    v33 = sub_57A720(off_5FD3B4);
    if ( v33 )
      goto LABEL_50;
  }
  return 0;
}
