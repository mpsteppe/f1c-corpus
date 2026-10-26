char __thiscall sub_51CDC0(char *this, float a2)
{
  char v3; // al
  double v4; // st7
  double v5; // st7
  double v6; // st6
  double v7; // st5
  double v8; // st6
  double v9; // st6
  double v10; // st7
  double v11; // st7
  float v12; // eax
  double v13; // st7
  double v14; // st6
  float *v15; // esi
  double v16; // st7
  int v17; // edi
  int v18; // edi
  float *v19; // esi
  float v20; // eax
  double v21; // st7
  double v22; // st6
  double v23; // st5
  double v24; // st6
  double v25; // st6
  double v26; // st7
  double v27; // st6
  double v28; // st7
  bool v29; // zf
  double v30; // st7
  double v31; // st7
  float v32; // edx
  float v33; // ecx
  float v34; // ecx
  float v35; // eax
  int v36; // esi
  int v37; // eax
  double v38; // st7
  int i; // eax
  double v40; // st7
  float *v41; // ecx
  float v42; // eax
  float v43; // edx
  float v44; // ecx
  int v45; // esi
  char result; // al
  float v47; // [esp+0h] [ebp-24Ch]
  float v48; // [esp+10h] [ebp-23Ch]
  _BYTE *v49; // [esp+10h] [ebp-23Ch]
  float v50; // [esp+10h] [ebp-23Ch]
  float *v51; // [esp+10h] [ebp-23Ch]
  char v52; // [esp+17h] [ebp-235h]
  float v53; // [esp+18h] [ebp-234h]
  float v54; // [esp+18h] [ebp-234h]
  float v55; // [esp+18h] [ebp-234h]
  float v56; // [esp+18h] [ebp-234h]
  float v57; // [esp+1Ch] [ebp-230h]
  float v58; // [esp+1Ch] [ebp-230h]
  float v59; // [esp+1Ch] [ebp-230h]
  float v60; // [esp+1Ch] [ebp-230h]
  float v61; // [esp+20h] [ebp-22Ch]
  float v62; // [esp+20h] [ebp-22Ch]
  float v63; // [esp+20h] [ebp-22Ch]
  float v64; // [esp+20h] [ebp-22Ch]
  _DWORD *v65; // [esp+24h] [ebp-228h]
  _BYTE *v66; // [esp+24h] [ebp-228h]
  float v67; // [esp+28h] [ebp-224h] BYREF
  float v68; // [esp+2Ch] [ebp-220h]
  float v69; // [esp+30h] [ebp-21Ch]
  float *v70; // [esp+34h] [ebp-218h]
  float v71; // [esp+38h] [ebp-214h] BYREF
  float v72; // [esp+3Ch] [ebp-210h]
  float v73; // [esp+40h] [ebp-20Ch]
  float v74; // [esp+44h] [ebp-208h] BYREF
  float v75; // [esp+48h] [ebp-204h]
  float v76; // [esp+4Ch] [ebp-200h]
  double v77; // [esp+50h] [ebp-1FCh] BYREF
  double v78[2]; // [esp+58h] [ebp-1F4h]
  _DWORD v79[3]; // [esp+68h] [ebp-1E4h] BYREF
  float v80[3]; // [esp+74h] [ebp-1D8h] BYREF
  float v81[9]; // [esp+80h] [ebp-1CCh] BYREF
  _BYTE v82[36]; // [esp+A4h] [ebp-1A8h] BYREF
  char v83[36]; // [esp+C8h] [ebp-184h] BYREF
  double v84[9]; // [esp+ECh] [ebp-160h] BYREF
  double v85[9]; // [esp+134h] [ebp-118h] BYREF
  int v86[52]; // [esp+17Ch] [ebp-D0h] BYREF

  v52 = 1;
  switch ( *((_DWORD *)this + 4125) )
  {
    case 0:
      v21 = a2 - *((float *)this + 4370);
      v22 = v21 * *((float *)this + 4386);
      v23 = v21 * *((float *)this + 4387);
      *(float *)v78 = v21 * *((float *)this + 4388);
      v55 = v22 + *((float *)this + 4380);
      v67 = v55;
      v24 = v23 + *((float *)this + 4381);
      qmemcpy(v81, this + 17484, sizeof(v81));
      v59 = v24;
      v63 = *(float *)v78 + *((float *)this + 4382);
      v56 = v21 * *((float *)this + 4392);
      v68 = v59;
      v74 = v56;
      v25 = v21 * *((float *)this + 4393);
      v69 = v63;
      v60 = v25;
      v75 = v60;
      v64 = v21 * *((float *)this + 4394);
      v76 = v64;
      sub_579930(&v74, v79);
      sub_50CAA0((_DWORD *)this + 452, &v67, v79, v81);
      sub_50CA00((int)(this + 1808), *((float *)this + 4391));
      if ( *((float *)this + 4677) <= 0.0 )
        v26 = 0.0;
      else
        v26 = *((float *)this + 4684);
      v27 = v26;
      v28 = *((float *)this + 4419);
      *((float *)this + 4) = v67;
      *((float *)this + 5) = v68;
      *((float *)this + 6) = v69;
      qmemcpy(this + 40, v81, 0x24u);
      *((_DWORD *)this + 19) = *((_DWORD *)this + 4386);
      *((_DWORD *)this + 20) = *((_DWORD *)this + 4387);
      *((_DWORD *)this + 21) = *((_DWORD *)this + 4388);
      *((float *)this + 37) = v27;
      *((float *)this + 38) = v28;
      v29 = dword_764104 == 0;
      this[20728] = dword_764104 != 0;
      if ( !v29 )
        sub_526050(44, 1, 1.0, 1065353216);
      v30 = *((float *)this + 4421);
      this[4696] = byte_76082D & byte_76082C;
      this[4693] = v30 > 0.0099999998;
      v50 = dbl_75E930;
      if ( v50 < -1.0 )
        goto LABEL_30;
      if ( v50 <= 1.0 )
      {
        if ( v50 >= -1.0 )
          v31 = v50;
        else
LABEL_30:
          v31 = -1.0;
      }
      else
      {
        v31 = 1.0;
      }
      *((float *)this + 1157) = v31;
      sub_449750((int)&dbl_75E930, &v71, v80);
      v32 = v72;
      *((float *)this + 1138) = v71;
      v33 = v73;
      *((float *)this + 1139) = v32;
      *((float *)this + 1140) = v33;
      v34 = v80[1];
      *((float *)this + 1141) = v80[0];
      v35 = v80[2];
      *((float *)this + 1142) = v34;
      *((float *)this + 1143) = v35;
      v36 = 0;
      v70 = (float *)(this + 88);
      v51 = (float *)(this + 17740);
      v66 = this + 2212;
      do
      {
        sub_449620((int)&dbl_75E930, v36, &v77, (int)v84, (int)v85);
        v71 = v77;
        v37 = 0;
        v72 = v78[0];
        v73 = v78[1];
        do
        {
          v38 = v84[v37++];
          v81[v37 + 8] = v38;
        }
        while ( v37 < 9 );
        for ( i = 0; i < 9; *(float *)&v82[4 * i + 32] = v40 )
          v40 = v85[i++];
        if ( *v66 )
        {
          sub_50CCE0((float *)this + 452, v36, &v71, v82, v83);
          sub_50C860((_DWORD *)this + 452, v36, *v51);
          v41 = v70;
          v42 = v72;
          *v70 = v71;
          v43 = v73;
          v41[1] = v42;
          v41[2] = v43;
        }
        ++v36;
        v66 += 304;
        v51 += 62;
        v70 += 3;
      }
      while ( v36 < 4 );
      v44 = dword_75AAD0[dword_75AAC0];
      dword_760270 = 0;
      dword_760274 = 0;
      LOBYTE(v44) = *(_DWORD *)(LODWORD(v44) + 25248) == *(_DWORD *)(*(_DWORD *)this + 25248);
      sub_51DEC0(v44);
      break;
    case 1:
      v3 = sub_51E6B0(this);
      v4 = *((float *)this + 4421);
      this[4696] = v3;
      this[4693] = v4 > 0.0099999998;
      goto LABEL_3;
    case 2:
LABEL_3:
      v5 = a2 - *((float *)this + 4370);
      v6 = v5 * *((float *)this + 4386);
      v7 = v5 * *((float *)this + 4387);
      *(float *)v78 = v5 * *((float *)this + 4388);
      v53 = v6 + *((float *)this + 4380);
      v67 = v53;
      v57 = v7 + *((float *)this + 4381);
      v68 = v57;
      v8 = *(float *)v78 + *((float *)this + 4382);
      qmemcpy(v81, this + 17484, sizeof(v81));
      v61 = v8;
      v54 = v5 * *((float *)this + 4392);
      v9 = v5 * *((float *)this + 4393);
      v74 = v54;
      v58 = v9;
      v75 = v58;
      v10 = v5 * *((float *)this + 4394);
      v69 = v61;
      v62 = v10;
      v76 = v62;
      sub_579930(&v74, v79);
      sub_50CAA0((_DWORD *)this + 452, &v67, v79, v81);
      v48 = *((float *)this + 4420);
      if ( v48 < -1.0 )
        goto LABEL_7;
      if ( v48 <= 1.0 )
      {
        if ( v48 >= -1.0 )
          v11 = v48;
        else
LABEL_7:
          v11 = -1.0;
      }
      else
      {
        v11 = 1.0;
      }
      v12 = *((float *)this + 4391);
      *((float *)this + 1157) = v11;
      sub_50CA00((int)(this + 1808), v12);
      v13 = *((float *)this + 4419);
      v14 = *((float *)this + 4684);
      *((float *)this + 4) = v67;
      *((float *)this + 5) = v68;
      *((float *)this + 6) = v69;
      qmemcpy(this + 40, v81, 0x24u);
      *((_DWORD *)this + 19) = *((_DWORD *)this + 4386);
      *((_DWORD *)this + 20) = *((_DWORD *)this + 4387);
      *((_DWORD *)this + 21) = *((_DWORD *)this + 4388);
      *((float *)this + 37) = v14;
      *((float *)this + 38) = v13;
      if ( this[20728] )
        sub_526050(44, 1, 1.0, 1065353216);
      if ( *((_DWORD *)this + 4125) == 2 )
      {
        v15 = (float *)(this + 17728);
        v16 = *((float *)this + 4671) * *((float *)this + 4420);
        v17 = 4;
        *((float *)this + 4433) = v16;
        *((float *)this + 4495) = v16;
        do
        {
          *v15 = dbl_7DA9C8 * v15[3] + *v15;
          if ( fabs(*v15) > 50.265484 )
            *v15 = fmod(*v15, 6.283185307179586);
          v15 += 62;
          --v17;
        }
        while ( v17 );
      }
      v18 = 0;
      v65 = this + 88;
      v49 = this + 2212;
      v19 = (float *)(this + 17728);
      do
      {
        if ( *v49 )
        {
          sub_50CB70((float *)this + 452, v18, *(v19 - 5), *v19, v19[1]);
          sub_50C860((_DWORD *)this + 452, v18, v19[3]);
          *v65 = *((_DWORD *)v19 - 6);
          v65[1] = *((_DWORD *)v19 - 5);
          v65[2] = *((_DWORD *)v19 - 4);
        }
        ++v18;
        v19 += 62;
        v49 += 304;
        v65 += 3;
      }
      while ( v18 < 4 );
      v20 = dword_75AAD0[dword_75AAC0];
      LOBYTE(v20) = *(_DWORD *)(LODWORD(v20) + 25248) == *(_DWORD *)(*(_DWORD *)this + 25248);
      sub_51DEC0(v20);
      break;
    case 3:
      if ( sub_4D9BA0(&dword_7D5DAC, *((_DWORD *)this + 1), (int)v86, -9.9999997e37) )
      {
        v45 = *((_DWORD *)this + 1);
        v47 = sub_4D9E20(&dword_7D5DAC);
        sub_4EE5C0((int)&unk_62BF68 + 25304 * v45, (int)v86, v47);
        *(float *)v78 = *((float *)this + 21) * *((float *)this + 468)
                      + *((float *)this + 20) * *((float *)this + 465)
                      + *((float *)this + 19) * *((float *)this + 462);
        sub_50CA00((int)(this + 1808), *(float *)v78);
        if ( this[20728] )
          sub_526050(44, 1, 1.0, 1065353216);
      }
      break;
    default:
      v52 = 0;
      break;
  }
  sub_51D720(this);
  result = v52;
  if ( v52 )
  {
    sub_50BFD0(this + 1808);
    result = this[20736] + 1;
    ++*((_DWORD *)this + 5184);
    if ( (result & 0xF) == 0 )
      return sub_51D5A0(this);
  }
  return result;
}
