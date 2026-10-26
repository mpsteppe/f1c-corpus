int sub_437550()
{
  _DWORD *v0; // eax
  int v1; // ecx
  int v2; // esi
  float *v3; // edi
  float *v4; // edx
  double v5; // st7
  double v6; // st7
  int v7; // ecx
  float *v8; // eax
  double v9; // st7
  float *v10; // esi
  int v11; // edi
  double v12; // st7
  double v13; // st7
  float v14; // ecx
  float *v15; // edx
  float v16; // eax
  void *v17; // eax
  void *v18; // esi
  float v20; // [esp+Ch] [ebp-544h] BYREF
  float v21; // [esp+10h] [ebp-540h]
  float v22; // [esp+14h] [ebp-53Ch]
  float v23; // [esp+18h] [ebp-538h]
  float v24; // [esp+1Ch] [ebp-534h]
  float v25; // [esp+20h] [ebp-530h]
  float v26; // [esp+2Ch] [ebp-524h]
  float v27; // [esp+30h] [ebp-520h] BYREF
  float v28; // [esp+34h] [ebp-51Ch]
  float v29; // [esp+38h] [ebp-518h]
  size_t v30; // [esp+3Ch] [ebp-514h]
  int v31; // [esp+40h] [ebp-510h]
  int v32; // [esp+44h] [ebp-50Ch]
  int v33; // [esp+48h] [ebp-508h]
  _DWORD v34[3]; // [esp+4Ch] [ebp-504h] BYREF
  float v35; // [esp+58h] [ebp-4F8h] BYREF
  float v36; // [esp+5Ch] [ebp-4F4h] BYREF
  _DWORD v37[5]; // [esp+60h] [ebp-4F0h] BYREF
  float v38; // [esp+74h] [ebp-4DCh]
  float v39; // [esp+78h] [ebp-4D8h]
  float v40; // [esp+88h] [ebp-4C8h]
  float v41; // [esp+8Ch] [ebp-4C4h]
  float v42; // [esp+90h] [ebp-4C0h]
  float v43; // [esp+A0h] [ebp-4B0h] BYREF
  float v44; // [esp+A4h] [ebp-4ACh]
  float v45; // [esp+A8h] [ebp-4A8h]
  float v46; // [esp+B8h] [ebp-498h]
  float v47; // [esp+BCh] [ebp-494h]
  float v48; // [esp+C0h] [ebp-490h]
  float v49; // [esp+4D8h] [ebp-78h]
  float v50; // [esp+4DCh] [ebp-74h]
  float v51; // [esp+4E0h] [ebp-70h]
  float v52; // [esp+4F0h] [ebp-60h]
  float v53; // [esp+4F4h] [ebp-5Ch]
  float v54; // [esp+4F8h] [ebp-58h]
  float v55; // [esp+508h] [ebp-48h]
  float v56; // [esp+50Ch] [ebp-44h]
  float v57; // [esp+510h] [ebp-40h]
  float v58; // [esp+520h] [ebp-30h]
  float v59; // [esp+524h] [ebp-2Ch]
  float v60; // [esp+528h] [ebp-28h]
  float v61; // [esp+538h] [ebp-18h]
  float v62; // [esp+53Ch] [ebp-14h]
  float v63; // [esp+540h] [ebp-10h]

  v30 = NumOfElements;
  v0 = v37;
  v1 = 53;
  do
  {
    *(v0 - 2) = 0;
    *(v0 - 1) = 0;
    *v0 = 0;
    v0[1] = 0;
    v0[2] = 0;
    v0[3] = 0;
    v0 += 6;
    --v1;
  }
  while ( v1 );
  v2 = 0;
  v3 = &v43;
  do
  {
    sub_4042F0(&flt_628F60, v2++, &v27, v34);
    sub_4042F0(&flt_628F60, v2, &v20, v34);
    v4 = v3;
    v3 += 6;
    v26 = v22 + v29;
    v5 = v21 + v28;
    v23 = (v20 + v27) * 0.5;
    *v4 = v23;
    v24 = v5 * 0.5;
    v6 = v26;
    v4[1] = v24;
    v25 = v6 * 0.5;
    v4[2] = v25;
  }
  while ( v2 < 47 );
  v26 = v45 - v48;
  v20 = v43 + v43 - v46;
  v40 = v20;
  v21 = v44 + v44 - v47;
  v41 = v21;
  v22 = v45 + v26;
  v42 = v22;
  v26 = v22 - v45;
  v23 = v20 - v43 + v20;
  *(float *)&v37[4] = v23;
  v24 = v21 - v44 + v21;
  v38 = v24;
  v25 = v26 + v22;
  v39 = v25;
  v26 = v25 - v22;
  v20 = v23 - v20 + v23;
  v35 = v20;
  v21 = v24 - v21 + v24;
  v36 = v21;
  v22 = v26 + v25;
  *(float *)v37 = v22;
  v26 = v54 - v51;
  v20 = v52 + v52 - v49;
  v21 = v53 + v53 - v50;
  v55 = v20;
  v56 = v21;
  v22 = v54 + v26;
  v57 = v22;
  v26 = v22 - v54;
  v23 = v20 - v52 + v20;
  v58 = v23;
  v24 = v21 - v53 + v21;
  v59 = v24;
  v25 = v26 + v22;
  v60 = v25;
  v26 = v25 - v22;
  v20 = v23 - v20 + v23;
  v61 = v20;
  v7 = 53;
  v21 = v24 - v21 + v24;
  v62 = v21;
  v22 = v26 + v25;
  v63 = v22;
  v8 = &v36;
  do
  {
    v9 = *v8;
    v8 += 6;
    --v7;
    *(v8 - 6) = v9 + 1.1;
  }
  while ( v7 );
  v31 = 0;
  v32 = 1065353216;
  v33 = 0;
  v10 = &v36;
  v41 = v41 + 0.25;
  v11 = 46;
  v38 = v38 + 0.60000002;
  v36 = v36 + 1.2;
  do
  {
    v23 = v10[5] - *(v10 - 1);
    v12 = v10[6];
    v27 = v23;
    v24 = v12 - *v10;
    v13 = v10[7];
    v28 = v24;
    v25 = v13 - v10[1];
    v29 = v25;
    sub_5795E0(&v20);
    v14 = v21;
    v15 = v10 + 2;
    v10[2] = v20;
    v16 = v22;
    v10[3] = v14;
    v10 += 6;
    --v11;
    v15[2] = v16;
  }
  while ( v11 );
  v17 = operator new(4u);
  if ( v17 )
    v18 = (void *)sub_45A520(v17);
  else
    v18 = 0;
  if ( (unsigned __int8)sub_45A5B0(&v35, v30 + 5) )
  {
    sub_459D60(v18);
    return 0;
  }
  else
  {
    if ( v18 )
    {
      sub_45A550(v18);
      sub_5BE8AE(v18);
    }
    return 1;
  }
}
