char __userpurge sub_4F91E0@<al>(int a1@<ecx>, int a2@<edi>, float *a3)
{
  int v4; // eax
  bool v5; // zf
  int v6; // eax
  int *v7; // eax
  int v8; // edx
  int v9; // eax
  int v10; // eax
  int v11; // ecx
  double v12; // st7
  float v13; // eax
  unsigned int v14; // eax
  _DWORD *v15; // eax
  unsigned int v16; // eax
  int v17; // eax
  double *v18; // edi
  double v19; // st7
  _DWORD *v20; // eax
  int *v21; // ecx
  float *v22; // edx
  int v23; // eax
  int *v24; // ecx
  int v25; // esi
  int v27; // [esp+10h] [ebp-2Ch] BYREF
  int v28; // [esp+14h] [ebp-28h]
  int v29; // [esp+18h] [ebp-24h]
  int v30; // [esp+1Ch] [ebp-20h] BYREF
  int v31; // [esp+20h] [ebp-1Ch]
  int v32; // [esp+24h] [ebp-18h]
  int v33; // [esp+28h] [ebp-14h]
  int v34; // [esp+2Ch] [ebp-10h] BYREF
  int v35; // [esp+30h] [ebp-Ch]
  int v36; // [esp+34h] [ebp-8h]
  int v37; // [esp+38h] [ebp-4h]

  sub_4F8BD0(a1);
  sub_4F56F0(a1);
  sub_4F3540(a1, a2);
  v4 = *(_DWORD *)a1;
  if ( *(_DWORD *)a1 != 9 )
  {
    if ( v4 == 7 || v4 == 8 || v4 == 6 || !v4 )
      goto LABEL_24;
    goto LABEL_17;
  }
  LOBYTE(v4) = *(_BYTE *)(a1 + 12);
  if ( (_BYTE)v4 )
    goto LABEL_24;
  v4 = *(_DWORD *)(a1 + 136);
  if ( !v4 || (*(_BYTE *)v4 & 4) != 0 )
    goto LABEL_24;
  if ( !*(_BYTE *)(a1 + 10) )
  {
    if ( *(_BYTE *)(a1 + 13) )
      goto LABEL_10;
LABEL_9:
    sub_4F1470();
    sub_4F0CF0();
    *(_DWORD *)(a1 + 104) = 0;
    LOBYTE(v4) = sub_4F44E0((int)&v27, 0);
    goto LABEL_24;
  }
  if ( *(_BYTE *)(a1 + 13) )
    goto LABEL_9;
LABEL_10:
  v5 = (*(_BYTE *)(a1 + 80) & 1) == 0;
  *(_DWORD *)(a1 + 100) = 0;
  *(_DWORD *)(a1 + 96) = 0;
  if ( v5 )
    *(float *)(a1 + 104) = 1.5708897;
  else
    *(float *)(a1 + 104) = -1.5708897;
LABEL_17:
  v4 = *(_DWORD *)(a1 + 136);
  if ( v4 )
  {
    v6 = *(_DWORD *)(a1 + 140);
    if ( v6 )
    {
      v7 = (int *)(*(_DWORD *)(v6 + 8) + 228);
      v27 = *v7;
      v28 = v7[1];
      v29 = v7[2];
    }
    else
    {
      v8 = *(_DWORD *)(a1 + 88);
      v9 = *(int *)(a1 + 92);
      v27 = *(_DWORD *)(a1 + 84);
      v28 = v8;
      v29 = v9;
    }
    sub_4F3470(a1, &v27, &v30);
    v10 = *(_DWORD *)(a1 + 140);
    if ( v10 )
    {
      v11 = v27;
      v4 = *(_DWORD *)(v10 + 8) + 228;
      v12 = *(float *)&v29;
      *(float *)(v4 + 4) = *(float *)&v31;
      *(_DWORD *)v4 = v11;
      *(float *)(v4 + 8) = v12;
    }
    else
    {
      LOBYTE(v4) = sub_5DB2B0(v27, v31, v29, *(float *)(a1 + 96), *(float *)(a1 + 100), *(float *)(a1 + 104));
    }
  }
LABEL_24:
  if ( a3 )
  {
    v13 = *a3;
    if ( *(_BYTE *)(a1 + 8) )
      v14 = LODWORD(v13) & 0xBFFFFFFF;
    else
      v14 = LODWORD(v13) | 0x40000000;
    *(_DWORD *)a3 = v14;
    v15 = *(_DWORD **)(a1 + 136);
    if ( !v15 || (*v15 & 4) != 0 )
      v16 = *(_DWORD *)a3 & 0x7FFFFFFF;
    else
      v16 = *(_DWORD *)a3 | 0x80000000;
    *(_DWORD *)a3 = v16;
    if ( *(_DWORD *)(a1 + 160) )
      v17 = *(_DWORD *)(a1 + 164) + 1;
    else
      v17 = 0;
    *(_DWORD *)a3 = (32 * v17) | *(_DWORD *)a3 & 0xFFFFF81F;
    v18 = *(double **)(a1 + 168);
    if ( v18 && (unsigned __int8)sub_405250() )
      v19 = *v18;
    else
      v19 = 0.0;
    a3[3] = v19;
    if ( (*(_DWORD *)a1 == 7 || *(_DWORD *)a1 == 8) && (v20 = *(_DWORD **)(a1 + 232), *v20) )
    {
      v21 = (int *)(*v20 + 52);
      v27 = *v21;
      v28 = v21[1];
      v29 = v21[2];
      v22 = (float *)(*v20 + 4);
    }
    else
    {
      v23 = *(_DWORD *)(a1 + 140);
      if ( !v23 )
      {
        v25 = *(_DWORD *)(a1 + 136);
        if ( v25 )
        {
          v27 = *(_DWORD *)(v25 + 124);
          v28 = *(_DWORD *)(v25 + 128);
          v29 = *(int *)(v25 + 132);
          sub_4F1560((float *)&v34, (float *)(v25 + 76));
          v31 = v34;
          v32 = v35;
          v33 = v36;
          v30 = v37;
        }
        else
        {
          v27 = 0;
          v28 = 0;
          *(float *)&v29 = 0.0;
          v33 = 0;
          v32 = 0;
          *(float *)&v31 = 0.0;
          v30 = 1065353216;
        }
        goto LABEL_49;
      }
      v24 = (int *)(*(_DWORD *)(v23 + 8) + 116);
      v27 = *v24;
      v28 = v24[1];
      v29 = v24[2];
      v22 = (float *)(*(_DWORD *)(v23 + 8) + 68);
    }
    sub_4F1560((float *)&v34, v22);
    v31 = v34;
    v32 = v35;
    v33 = v36;
    v30 = v37;
LABEL_49:
    LOBYTE(v4) = sub_51B1C0(&v27, &v30);
  }
  return v4;
}
