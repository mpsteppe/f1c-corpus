char __thiscall sub_4F4510(int this)
{
  float v2; // ebx
  int v3; // eax
  float *v4; // eax
  int v5; // ecx
  int v6; // edx
  float *v7; // eax
  float *v8; // eax
  int v9; // ecx
  int v10; // edx
  float *v11; // eax
  double v12; // st7
  float v13; // edx
  double v14; // st7
  double v15; // st7
  int v16; // edx
  int v17; // ecx
  int *v18; // ecx
  int v19; // ebp
  int v20; // edi
  int v21; // eax
  float *v22; // ebp
  double v23; // st7
  double v24; // st6
  double v25; // st6
  int v26; // ecx
  double v27; // st7
  bool v28; // zf
  double v29; // st6
  int v30; // ebx
  float *v31; // edi
  float v32; // eax
  double v33; // st7
  float v35; // [esp+20h] [ebp-54h]
  float v36; // [esp+24h] [ebp-50h]
  int v37; // [esp+28h] [ebp-4Ch]
  float v38; // [esp+2Ch] [ebp-48h] BYREF
  float v39; // [esp+30h] [ebp-44h]
  float v40; // [esp+34h] [ebp-40h]
  char String2[4]; // [esp+38h] [ebp-3Ch] BYREF
  float v42; // [esp+40h] [ebp-34h]
  float v43[3]; // [esp+44h] [ebp-30h] BYREF
  float v44[3]; // [esp+50h] [ebp-24h] BYREF
  float v45[3]; // [esp+5Ch] [ebp-18h] BYREF
  float v46[3]; // [esp+68h] [ebp-Ch] BYREF

  v2 = *(float *)this;
  v3 = *(_DWORD *)this - 1;
  switch ( *(_DWORD *)this )
  {
    case 1:
      sub_5773F0(&v38);
      v4 = sub_401250(&v38, (float *)(this + 108), v43);
      v5 = *(_DWORD *)v4;
      v6 = *((_DWORD *)v4 + 1);
      v3 = *((_DWORD *)v4 + 2);
      *(_DWORD *)(this + 120) = v5;
      *(_DWORD *)(this + 124) = v6;
      *(_DWORD *)(this + 128) = v3;
      *(_DWORD *)(this + 132) = 1078530794;
      break;
    case 2:
    case 3:
      v7 = sub_4F1410((float *)(**(_DWORD **)(this + 4) + 2704), v44, LODWORD(v2) != 2);
      v38 = *v7;
      v39 = v7[1];
      v40 = v7[2];
      v8 = sub_401250(&v38, (float *)(this + 108), v45);
      v9 = *(_DWORD *)v8;
      v10 = *((_DWORD *)v8 + 1);
      v3 = *((_DWORD *)v8 + 2);
      *(_DWORD *)(this + 120) = v9;
      *(_DWORD *)(this + 124) = v10;
      *(_DWORD *)(this + 128) = v3;
      *(_DWORD *)(this + 132) = 0;
      break;
    case 4:
    case 5:
      *(_DWORD *)(this + 120) = *(_DWORD *)(this + 108);
      v16 = *(_DWORD *)(this + 112);
      v17 = *(_DWORD *)(this + 116);
      *(_DWORD *)(this + 124) = v16;
      *(_DWORD *)(this + 128) = v17;
      v18 = *(int **)(this + 4);
      v19 = *v18;
      v20 = dword_BE1BD8 + 2824 * *(_DWORD *)(*v18 + 22472);
      v21 = sub_4F2010(v18, LODWORD(v2) == 4);
      v37 = v21;
      v35 = 0.0;
      if ( v21 < 6 )
        v35 = flt_75B430[v21];
      if ( LODWORD(v2) == 4 )
        v22 = (float *)(v19 + 2840);
      else
        v22 = (float *)(v19 + 2828);
      v23 = 0.0;
      v38 = *v22;
      v39 = v22[1];
      v40 = v22[2];
      if ( *(_DWORD *)(this + 140) && *(int *)(this + 152) >= 4 )
      {
        sub_405E20(*(float **)(*(_DWORD *)(this + 156) + 352), String2);
        v36 = *(float *)String2;
        sub_405E20(*(float **)(*(_DWORD *)(this + 156) + 472), String2);
        v23 = *(float *)String2 + v36;
        v21 = v37;
      }
      v24 = v38 - v23;
      if ( *(_DWORD *)this == 4 )
        v25 = v24 + *(float *)(v20 + 276) + v35;
      else
        v25 = v24 - v35 - *(float *)(v20 + 276);
      *(float *)(this + 120) = v25;
      if ( v21 == 4 && *(_DWORD *)(this + 140) && *(int *)(this + 152) >= 5 )
      {
        sub_405E20(*(float **)(*(_DWORD *)(this + 156) + 352), String2);
        v26 = *(_DWORD *)(this + 156);
        *(float *)(this + 128) = *(float *)(this + 128) - v42;
        sub_405E20(*(float **)(v26 + 472), String2);
        v27 = *(float *)(this + 128) - v42;
        v28 = *(_DWORD *)this == 5;
        *(float *)(this + 128) = v27;
        if ( v28 )
          v29 = -0.1;
        else
          v29 = 0.1;
        *(float *)(this + 128) = v27 + v29;
      }
      v3 = *(_DWORD *)(this + 172);
      if ( v3 )
        *(float *)(this + 128) = *(float *)(v3 + 52) + *(float *)(this + 128);
      *(_DWORD *)(this + 132) = 0;
      break;
    case 6:
      v30 = *(_DWORD *)(this + 4);
      v38 = 0.0;
      v39 = 0.0;
      v40 = 0.0;
      v31 = (float *)(dword_BE1BD8 + 2824 * *(_DWORD *)(*(_DWORD *)v30 + 22472));
      if ( sub_4011C0(v31 + 59) )
      {
        if ( sub_4011C0(v31 + 59) )
          v40 = v31[65];
        else
          v40 = v31[61];
        v32 = *(float *)(this + 112);
        v38 = *(float *)(*(_DWORD *)v30 + 2780);
        v33 = v40 + *(float *)(*(_DWORD *)v30 + 2788);
        v38 = v38 + *(float *)(this + 108);
        v39 = v32;
        v40 = v33 + *(float *)(this + 116);
        sub_4F3470(this, &v38, (_DWORD *)(this + 84));
        LOBYTE(v3) = sub_4F4440();
      }
      else
      {
        LOBYTE(v3) = off_16C9404();
      }
      break;
    case 9:
      LOBYTE(v3) = *(_BYTE *)(this + 10);
      if ( (_BYTE)v3 )
      {
        v11 = sub_4F1410((float *)(**(_DWORD **)(this + 4) + 2704), v46, *(_DWORD *)(this + 80));
        v38 = *v11;
        v12 = v38 + *(float *)(this + 108);
        v39 = v11[1];
        v13 = v11[2];
        LOBYTE(v11) = *(_BYTE *)(this + 80);
        v38 = v12;
        v14 = v39 + *(float *)(this + 112);
        v40 = v13;
        v39 = v14;
        v40 = v13 + *(float *)(this + 116);
        if ( ((unsigned __int8)v11 & 1) != 0 )
          v15 = -1.5708897;
        else
          v15 = 1.5708897;
        *(float *)(this + 104) = v15;
        LOBYTE(v3) = sub_4F44E0((int)&v38, 0);
      }
      break;
    default:
      return v3;
  }
  return v3;
}
