int __thiscall sub_4024D0(float *this, float *a2, int a3, int a4)
{
  double v4; // st7
  double v5; // st7
  int result; // eax
  double v7; // st7
  double v8; // st7
  double v9; // st7
  float v10; // ecx
  double v11; // st7
  float *v12; // ebx
  double v13; // st7
  double v14; // st6
  double v15; // st7
  double v16; // st7
  double v17; // st7
  double v18; // st7
  double v19; // st7
  double v20; // st7
  double v21; // st7
  double v22; // st7
  double v23; // st7
  double v24; // st7
  double v25; // st7
  double v26; // st7
  double v27; // st7
  double v28; // st7
  double v29; // st7
  double v30; // st7
  double v31; // st7
  double v32; // st7
  double v33; // st7
  float v34; // [esp+10h] [ebp-68h]
  float v35; // [esp+14h] [ebp-64h]
  float v37; // [esp+1Ch] [ebp-5Ch]
  float v38; // [esp+20h] [ebp-58h]
  float v39; // [esp+20h] [ebp-58h]
  float v40; // [esp+20h] [ebp-58h]
  float v41; // [esp+20h] [ebp-58h]
  float v42; // [esp+20h] [ebp-58h]
  float v43; // [esp+20h] [ebp-58h]
  float v44; // [esp+20h] [ebp-58h]
  float v45; // [esp+24h] [ebp-54h]
  float v46; // [esp+24h] [ebp-54h]
  float v47; // [esp+24h] [ebp-54h]
  float v48; // [esp+24h] [ebp-54h]
  float v49; // [esp+24h] [ebp-54h]
  float v50; // [esp+24h] [ebp-54h]
  float v51; // [esp+24h] [ebp-54h]
  float v52; // [esp+28h] [ebp-50h]
  float v53; // [esp+28h] [ebp-50h]
  float v54; // [esp+28h] [ebp-50h]
  float v55; // [esp+28h] [ebp-50h]
  float v56; // [esp+28h] [ebp-50h]
  float v57; // [esp+28h] [ebp-50h]
  float v58; // [esp+28h] [ebp-50h]
  float v59; // [esp+2Ch] [ebp-4Ch]
  float v60; // [esp+2Ch] [ebp-4Ch]
  float v61; // [esp+30h] [ebp-48h]
  float v62; // [esp+30h] [ebp-48h]
  float v63; // [esp+30h] [ebp-48h]
  float v64; // [esp+34h] [ebp-44h]
  float v65; // [esp+34h] [ebp-44h]
  float v66; // [esp+34h] [ebp-44h]
  float v67; // [esp+34h] [ebp-44h]
  float v68; // [esp+34h] [ebp-44h]
  float v69; // [esp+40h] [ebp-38h]
  float v70; // [esp+40h] [ebp-38h]
  double v71; // [esp+44h] [ebp-34h] BYREF
  double v72; // [esp+4Ch] [ebp-2Ch]
  double v73; // [esp+54h] [ebp-24h]
  int v74; // [esp+5Ch] [ebp-1Ch]
  int v75; // [esp+60h] [ebp-18h]
  int v76; // [esp+64h] [ebp-14h]
  int v77; // [esp+68h] [ebp-10h]
  double v78; // [esp+6Ch] [ebp-Ch]
  int v79; // [esp+74h] [ebp-4h]

  *(_DWORD *)(a3 + 24) = 0;
  *(_DWORD *)(a3 + 28) = 1065353216;
  if ( this[14] <= 0.0 )
  {
    v4 = a2[78] + a2[6];
    v61 = v4 * a2[12];
    v64 = v4 * a2[13];
    v38 = v4 * a2[11] + *a2;
    v45 = v61 + a2[1];
    v5 = v64 + a2[2];
    *(float *)a3 = v38;
    *(float *)(a3 + 4) = v45;
    v52 = v5;
    *(float *)(a3 + 8) = v52;
    v39 = a2[11] * 0.0;
    v46 = a2[12] * 0.0;
    result = LODWORD(v39);
    v7 = a2[13] * 0.0;
    *(float *)(a3 + 12) = v39;
    *(float *)(a3 + 16) = v46;
    v53 = v7;
    *(float *)(a3 + 20) = v53;
    return result;
  }
  if ( a4 )
  {
    if ( a4 == 1 )
    {
      v34 = a2[10];
      v65 = v34 * a2[13];
      v40 = v34 * a2[11] + *a2;
      v47 = v34 * a2[12] + a2[1];
      v9 = v65 + a2[2];
      *(float *)a3 = v40;
      *(float *)(a3 + 4) = v47;
      v54 = v9;
      *(float *)(a3 + 8) = v54;
      v10 = this[15];
      goto LABEL_9;
    }
    v8 = a2[6];
  }
  else
  {
    v8 = a2[78] + a2[6];
  }
  v34 = v8;
  v66 = v34 * a2[13];
  v41 = v8 * a2[11] + *a2;
  v48 = v34 * a2[12] + a2[1];
  v11 = v66 + a2[2];
  *(float *)a3 = v41;
  *(float *)(a3 + 4) = v48;
  v55 = v11;
  *(float *)(a3 + 8) = v55;
  v10 = this[14];
LABEL_9:
  v35 = v10;
  v12 = (float *)(a3 + 12);
  v13 = v10 * 0.5;
  v79 = 0;
  v14 = v13 * a2[11];
  v74 = 0;
  v75 = 1072693248;
  v76 = 0x40000000;
  v42 = v14;
  v77 = 1201543096;
  v49 = v13 * a2[12];
  v15 = v13 * a2[13];
  *(float *)(a3 + 12) = v42;
  *(float *)(a3 + 16) = v49;
  v56 = v15;
  v16 = *(float *)a3;
  *(float *)(a3 + 20) = v56;
  v71 = v16;
  v72 = *(float *)(a3 + 4);
  v73 = *(float *)(a3 + 8);
  result = sub_44E900(&v71);
  if ( result )
  {
    while ( 1 )
    {
      v17 = *(float *)a3;
      v79 = result;
      v71 = v17 - *v12;
      v18 = *(float *)(a3 + 4);
      v74 = 0;
      v72 = v18;
      v19 = *(float *)(a3 + 8);
      v75 = 1075314688;
      v20 = v19 - *(float *)(a3 + 20);
      v76 = 0x40000000;
      v77 = 1201543096;
      v73 = v20;
      result = sub_44E900(&v71);
      if ( result )
        break;
      v35 = v35 - 0.25;
      v21 = v34 + 0.125;
      v34 = v21;
      v69 = v34 * a2[13];
      v43 = v21 * a2[11] + *a2;
      v50 = v34 * a2[12] + a2[1];
      v22 = v69 + a2[2];
      *(float *)a3 = v43;
      *(float *)(a3 + 4) = v50;
      v57 = v22;
      *(float *)(a3 + 8) = v57;
      v23 = v35 * 0.5;
      v59 = v23 * a2[11];
      v62 = v23 * a2[12];
      v24 = v23 * a2[13];
      *v12 = v59;
      *(float *)(a3 + 16) = v62;
      v67 = v24;
      *(float *)(a3 + 20) = v67;
      *(float *)(a3 + 24) = 1.0 - v35 / this[14] - (1.0 - *(float *)(a3 + 28));
    }
    v37 = v78;
    while ( 1 )
    {
      v25 = *v12 + *(float *)a3;
      v74 = 0;
      v71 = v25;
      v26 = *(float *)(a3 + 4);
      v75 = 1075314688;
      v72 = v26;
      v27 = *(float *)(a3 + 20);
      v76 = 0x40000000;
      v28 = v27 + *(float *)(a3 + 8);
      v77 = 1201543096;
      v79 = result;
      v73 = v28;
      result = sub_44E900(&v71);
      if ( result )
        break;
      v35 = v35 - 0.25;
      v29 = v34 - 0.125;
      v34 = v29;
      v70 = v34 * a2[13];
      v60 = v29 * a2[11] + *a2;
      v63 = v34 * a2[12] + a2[1];
      v30 = v70 + a2[2];
      *(float *)a3 = v60;
      *(float *)(a3 + 4) = v63;
      v68 = v30;
      *(float *)(a3 + 8) = v68;
      v31 = v35 * 0.5;
      v44 = v31 * a2[11];
      v51 = v31 * a2[12];
      v32 = v31 * a2[13];
      *v12 = v44;
      *(float *)(a3 + 16) = v51;
      v58 = v32;
      *(float *)(a3 + 20) = v58;
      *(float *)(a3 + 28) = v35 / this[14] - *(float *)(a3 + 24);
    }
    v33 = v78;
    *(float *)(a3 + 4) = (v37 + v78) * 0.5 + this[4];
    *(float *)(a3 + 16) = (v33 - v37) * 0.5;
  }
  return result;
}
