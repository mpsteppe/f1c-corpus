int __thiscall sub_593B00(char *String2, char *String2a)
{
  int v4; // edi
  int v5; // ecx
  char *v6; // eax
  int v7; // ebp
  char *i; // edi
  const char *v9; // eax
  char *v10; // eax
  int v11; // eax
  _DWORD *v13; // eax
  char *v14; // eax
  _DWORD *v15; // eax
  char *v16; // eax
  double v17; // st7
  _DWORD *v18; // eax
  char *v19; // eax
  _DWORD *v20; // eax
  char *v21; // eax
  _DWORD *v22; // eax
  char *v23; // eax
  double v24; // st7
  _DWORD *v25; // eax
  char *v26; // eax
  _DWORD *v27; // eax
  int v28; // eax
  _DWORD *v29; // edi
  _DWORD *v30; // ecx
  char *v31; // eax
  double j; // st7
  _DWORD *v33; // eax
  float *v34; // eax
  _DWORD *v35; // eax
  char *v36; // eax
  _DWORD *v37; // eax
  char *v38; // eax
  int v39; // eax
  const char *v40; // eax
  int v41; // eax
  char *v42; // eax
  const char *v43; // eax
  float v44; // [esp+10h] [ebp-18h]
  float v45; // [esp+10h] [ebp-18h]
  int v46; // [esp+14h] [ebp-14h]
  int v47; // [esp+18h] [ebp-10h]
  int v48; // [esp+1Ch] [ebp-Ch]
  int v49; // [esp+20h] [ebp-8h]
  int v50; // [esp+24h] [ebp-4h]
  char *String2b; // [esp+2Ch] [ebp+4h]
  float String2c; // [esp+2Ch] [ebp+4h]

  v47 = *(_DWORD *)dword_B640C8;
  v44 = 0.2;
  v48 = 1;
  v49 = 3;
  v50 = 6;
  switch ( *(_DWORD *)dword_B640C8 )
  {
    case 1:
    case 6:
      v48 = 3;
      goto LABEL_6;
    case 2:
      v48 = 1;
      v49 = 3;
      break;
    case 3:
    case 4:
      v48 = 1;
LABEL_6:
      v49 = 0;
      break;
    case 5:
      v48 = 6;
      v49 = 3;
      break;
    default:
      break;
  }
  v4 = 0;
  while ( 1 )
  {
    v5 = *(&v47 + v4);
    if ( v5 )
    {
      String2b = sub_42FEC0(v5, 0, 1);
      String2a = (char *)sub_616630(String2b);
      if ( String2a )
        break;
    }
    if ( ++v4 >= 4 )
      goto LABEL_22;
  }
  v46 = (unsigned __int64)(100.0 / flt_FADE28 + 0.5);
  v6 = sub_48D380(String2a);
  v7 = atol(v6);
  if ( v7 <= 0 )
    v7 = 100;
  for ( i = (char *)sub_5C3D80(String2a); i; i = (char *)sub_5C3D80(i) )
  {
    v9 = (const char *)sub_6165E0(i);
    if ( !_stricmp(v9, String2b) )
    {
      v10 = sub_48D380(i);
      v11 = atol(v10);
      if ( v11 <= 0 )
        v11 = 100;
      if ( v11 >= v46 && v11 < v7 )
      {
        String2a = i;
        v7 = v11;
      }
    }
  }
LABEL_22:
  if ( !String2a )
    return -1;
  *((_DWORD *)String2 + 9) = 0;
  *((_DWORD *)String2 + 10) = 0;
  *((_DWORD *)String2 + 11) = 0;
  *((_DWORD *)String2 + 124) = 0;
  *((_DWORD *)String2 + 12) = 0;
  *((_DWORD *)String2 + 13) = 1101004800;
  *((_DWORD *)String2 + 14) = 1102053376;
  v13 = (_DWORD *)sub_616630("Conditions");
  if ( v13 )
  {
    v14 = sub_48D380(v13);
    v44 = sub_593940(v14);
    sub_592B20((int)String2, v44);
  }
  v15 = (_DWORD *)sub_616630("TrackWetness");
  if ( v15 )
  {
    v16 = sub_48D380(v15);
    v17 = sub_593A30(v16);
    *((float *)String2 + 11) = v17;
    *((float *)String2 + 12) = v17;
  }
  v18 = (_DWORD *)sub_616630("OnPathWetness");
  if ( v18 )
  {
    v19 = sub_48D380(v18);
    *((float *)String2 + 11) = sub_593A30(v19);
  }
  v20 = (_DWORD *)sub_616630("OffPathWetness");
  if ( v20 )
  {
    v21 = sub_48D380(v20);
    *((float *)String2 + 12) = sub_593A30(v21);
  }
  if ( *((float *)String2 + 12) < (double)*((float *)String2 + 11) )
    *((_DWORD *)String2 + 12) = *((_DWORD *)String2 + 11);
  v22 = (_DWORD *)sub_616630("AmbientTemp");
  if ( v22 )
  {
    v23 = sub_48D380(v22);
    v24 = sub_592BD0(String2, v23);
    *((float *)String2 + 13) = v24;
    *((float *)String2 + 14) = v24 + 2.0;
  }
  v25 = (_DWORD *)sub_616630("TrackTemp");
  if ( v25 )
  {
    v26 = sub_48D380(v25);
    *((float *)String2 + 14) = sub_592BD0(String2, v26);
  }
  v27 = operator new(0x10u);
  if ( v27 )
  {
    *v27 = 0;
    v27[1] = 1101004800;
    v27[2] = 1045220557;
    v27[3] = 0;
  }
  else
  {
    v27 = 0;
  }
  *((_DWORD *)String2 + 16) = v27;
  *v27 = 0;
  *(_DWORD *)(*((_DWORD *)String2 + 16) + 4) = *((_DWORD *)String2 + 13);
  *(float *)(*((_DWORD *)String2 + 16) + 8) = v44;
  *((_DWORD *)String2 + 15) = *((_DWORD *)String2 + 16);
  String2c = flt_91BDF0;
  if ( flt_91BDF0 < 16.0 || flt_91BDF0 > 1024.0 )
    String2c = 92.0;
  v28 = sub_616630("Minute");
  v29 = (_DWORD *)v28;
  if ( v28 )
  {
    v30 = (_DWORD *)v28;
LABEL_57:
    v42 = sub_48D380(v30);
    for ( j = atof(v42) * 60.0; ; j = atof(v31) * String2c )
    {
      v33 = operator new(0x10u);
      if ( v33 )
      {
        *v33 = 0;
        v33[1] = 1101004800;
        v33[2] = 1045220557;
        v33[3] = 0;
      }
      else
      {
        v33 = 0;
      }
      *(_DWORD *)(*((_DWORD *)String2 + 15) + 12) = v33;
      *(_DWORD *)(*(_DWORD *)(*((_DWORD *)String2 + 15) + 12) + 4) = *(_DWORD *)(*((_DWORD *)String2 + 15) + 4);
      *(_DWORD *)(*(_DWORD *)(*((_DWORD *)String2 + 15) + 12) + 8) = *(_DWORD *)(*((_DWORD *)String2 + 15) + 8);
      v34 = *(float **)(*((_DWORD *)String2 + 15) + 12);
      *((_DWORD *)String2 + 15) = v34;
      v45 = j;
      *v34 = v45;
      *(_DWORD *)(*((_DWORD *)String2 + 15) + 12) = 0;
      v35 = (_DWORD *)sub_616630("Conditions");
      if ( v35 )
      {
        v36 = sub_48D380(v35);
        *(float *)(*((_DWORD *)String2 + 15) + 8) = sub_593940(v36);
      }
      v37 = (_DWORD *)sub_616630("AmbientTemp");
      if ( v37 )
      {
        v38 = sub_48D380(v37);
        *(float *)(*((_DWORD *)String2 + 15) + 4) = sub_592BD0(String2, v38);
      }
      v39 = sub_5C3D80(v29);
      v29 = (_DWORD *)v39;
      if ( !v39 )
        break;
      v40 = (const char *)sub_6165E0(v39);
      v41 = _stricmp(v40, "Minute");
      v30 = v29;
      if ( !v41 )
        goto LABEL_57;
      v43 = (const char *)sub_6165E0(v29);
      if ( _stricmp(v43, off_6F3860) )
        break;
LABEL_47:
      v31 = sub_48D380(v29);
    }
  }
  else
  {
    v29 = (_DWORD *)sub_616630((char *)off_6F3860);
    if ( v29 )
      goto LABEL_47;
  }
  return 0;
}
