int sub_4349A0()
{
  int v0; // ebp
  _DWORD *v1; // eax
  int v2; // ecx
  int v3; // esi
  float *v4; // edi
  float *v5; // ecx
  double v6; // st7
  double v7; // st7
  float *v8; // eax
  int v9; // ecx
  float *v10; // edx
  double v11; // st7
  double v12; // st7
  float v14; // [esp+Ch] [ebp-558h] BYREF
  float v15; // [esp+10h] [ebp-554h]
  float v16; // [esp+14h] [ebp-550h]
  float v17; // [esp+18h] [ebp-54Ch]
  float v18; // [esp+1Ch] [ebp-548h]
  float v19; // [esp+20h] [ebp-544h]
  float v20; // [esp+2Ch] [ebp-538h]
  float v21[3]; // [esp+30h] [ebp-534h] BYREF
  _DWORD v22[3]; // [esp+3Ch] [ebp-528h] BYREF
  float v23; // [esp+48h] [ebp-51Ch] BYREF
  float v24; // [esp+4Ch] [ebp-518h]
  _DWORD v25[2]; // [esp+50h] [ebp-514h] BYREF
  float v26; // [esp+58h] [ebp-50Ch]
  float v27; // [esp+5Ch] [ebp-508h]
  float v28; // [esp+60h] [ebp-504h]
  float v29; // [esp+64h] [ebp-500h]
  float v30; // [esp+68h] [ebp-4FCh]
  float v31; // [esp+6Ch] [ebp-4F8h] BYREF
  float v32; // [esp+70h] [ebp-4F4h]
  float v33; // [esp+74h] [ebp-4F0h]
  float v34; // [esp+78h] [ebp-4ECh]
  float v35; // [esp+7Ch] [ebp-4E8h]
  float v36; // [esp+80h] [ebp-4E4h]
  float v37; // [esp+528h] [ebp-3Ch]
  float v38; // [esp+52Ch] [ebp-38h]
  float v39; // [esp+530h] [ebp-34h]
  float v40; // [esp+534h] [ebp-30h]
  float v41; // [esp+538h] [ebp-2Ch]
  float v42; // [esp+53Ch] [ebp-28h]
  float v43; // [esp+540h] [ebp-24h]
  float v44; // [esp+544h] [ebp-20h]
  float v45; // [esp+548h] [ebp-1Ch]
  float v46; // [esp+54Ch] [ebp-18h]
  float v47; // [esp+550h] [ebp-14h]
  float v48; // [esp+554h] [ebp-10h]
  float v49; // [esp+558h] [ebp-Ch]
  float v50; // [esp+55Ch] [ebp-8h]
  float v51; // [esp+560h] [ebp-4h]

  v0 = dword_5C329C;
  v1 = v25;
  v2 = 109;
  v3 = 0;
  do
  {
    *(v1 - 2) = 0;
    *(v1 - 1) = 0;
    *v1 = 0;
    v1 += 3;
    --v2;
  }
  while ( v2 );
  v4 = &v31;
  do
  {
    sub_403CD0(dword_5EA2C0, v3++, v21, v22);
    sub_403CD0(dword_5EA2C0, v3, &v14, v22);
    v5 = v4;
    v4 += 3;
    v20 = v16 + v21[2];
    v6 = v15 + v21[1];
    v17 = (v14 + v21[0]) * 0.5;
    *v5 = v17;
    v18 = v6 * 0.5;
    v7 = v20;
    v5[1] = v18;
    v19 = v7 * 0.5;
    v5[2] = v19;
  }
  while ( v3 < 103 );
  v20 = v33 - v36;
  v14 = v31 + v31 - v34;
  v28 = v14;
  v15 = v32 + v32 - v35;
  v29 = v15;
  v16 = v33 + v20;
  v30 = v16;
  v20 = v16 - v33;
  v17 = v14 - v31 + v14;
  *(float *)&v25[1] = v17;
  v18 = v15 - v32 + v15;
  v26 = v18;
  v19 = v20 + v16;
  v27 = v19;
  v20 = v19 - v16;
  v14 = v17 - v14 + v17;
  v23 = v14;
  v15 = v18 - v15 + v18;
  v24 = v15;
  v16 = v20 + v19;
  *(float *)v25 = v16;
  v20 = v42 - v39;
  v14 = v40 + v40 - v37;
  v15 = v41 + v41 - v38;
  v43 = v14;
  v44 = v15;
  v16 = v42 + v20;
  v45 = v16;
  v20 = v16 - v42;
  v17 = v14 - v40 + v14;
  v46 = v17;
  v18 = v15 - v41 + v15;
  v47 = v18;
  v19 = v20 + v16;
  v48 = v19;
  v20 = v19 - v16;
  v14 = v17 - v14 + v17;
  v49 = v14;
  v8 = &v23;
  v15 = v18 - v15 + v18;
  v50 = v15;
  v9 = 109;
  v16 = v20 + v19;
  v51 = v16;
  do
  {
    v10 = v8;
    v11 = -*v8;
    v8 += 3;
    --v9;
    v17 = v11;
    v18 = -*(v8 - 2);
    v12 = *(v8 - 1);
    *v10 = v17;
    v19 = -v12;
    v10[1] = v18;
    v10[2] = v19;
    *(v8 - 2) = *(v8 - 2) - 0.64999998;
  }
  while ( v9 );
  v29 = v29 - 0.25;
  v26 = v26 - 0.75;
  v24 = v24 - 2.25;
  return sub_457F90(&v23, v0 + 5);
}

