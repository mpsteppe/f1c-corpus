int sub_4C4240()
{
  int v0; // eax
  int v1; // ebp
  int v2; // ebx
  int v3; // edi
  int v4; // esi
  int v5; // edi
  char *v6; // eax
  char *v7; // eax
  char *v8; // eax
  char *v9; // eax
  char *v10; // eax
  int v11; // esi
  char *v12; // eax
  int v13; // ecx
  char *v14; // eax
  int v15; // ecx
  char *v16; // eax
  int v17; // ecx
  char *v18; // eax
  int v19; // ecx
  char *v20; // eax
  int v21; // ecx
  char *v22; // eax
  int v23; // ecx
  char *v24; // eax
  int v25; // ecx
  char *v26; // eax
  int v27; // ecx
  char *v28; // eax
  int v29; // ecx
  char *v30; // eax
  int v31; // ecx
  char *v32; // eax
  int v33; // ecx
  char *v34; // eax
  int v35; // ecx
  char *v36; // eax
  int v37; // ecx
  char *v38; // eax
  int v39; // ecx
  char *v40; // eax
  int v41; // ecx
  char *v42; // eax
  char *v43; // eax
  char *v44; // eax
  int v45; // ecx
  int v47; // [esp+4h] [ebp-430h]
  int v48; // [esp+8h] [ebp-42Ch]
  _DWORD v49[2]; // [esp+10h] [ebp-424h] BYREF
  char v50; // [esp+38h] [ebp-3FCh] BYREF
  int v51; // [esp+48h] [ebp-3ECh]
  int v52; // [esp+4Ch] [ebp-3E8h]
  int v53; // [esp+50h] [ebp-3E4h]
  int v54; // [esp+54h] [ebp-3E0h]
  int v55; // [esp+58h] [ebp-3DCh]
  int v56; // [esp+5Ch] [ebp-3D8h]
  int v57; // [esp+60h] [ebp-3D4h]
  int v58; // [esp+64h] [ebp-3D0h]
  int v59; // [esp+68h] [ebp-3CCh]
  int v60; // [esp+6Ch] [ebp-3C8h]
  int v61; // [esp+70h] [ebp-3C4h]
  int v62; // [esp+74h] [ebp-3C0h]
  int v63; // [esp+78h] [ebp-3BCh]
  int v64; // [esp+7Ch] [ebp-3B8h]
  int v65; // [esp+80h] [ebp-3B4h]
  char v66; // [esp+84h] [ebp-3B0h] BYREF
  char v67; // [esp+8Ch] [ebp-3A8h] BYREF
  char v68; // [esp+CCh] [ebp-368h] BYREF
  char v69; // [esp+10Ch] [ebp-328h] BYREF
  char v70; // [esp+14Ch] [ebp-2E8h] BYREF
  char v71; // [esp+18Ch] [ebp-2A8h] BYREF
  char v72; // [esp+1CCh] [ebp-268h] BYREF
  char v73; // [esp+2CCh] [ebp-168h] BYREF
  char v74; // [esp+34Ch] [ebp-E8h] BYREF
  char v75; // [esp+35Ch] [ebp-D8h] BYREF
  char v76; // [esp+39Ch] [ebp-98h] BYREF
  char v77; // [esp+3ACh] [ebp-88h] BYREF
  char v78; // [esp+3BCh] [ebp-78h] BYREF
  char v79; // [esp+3CCh] [ebp-68h] BYREF
  int v80; // [esp+3E4h] [ebp-50h]
  char v81; // [esp+3F0h] [ebp-44h] BYREF
  int v82; // [esp+430h] [ebp-4h]

  sub_4C3050(v49);
  v0 = dword_8AC390;
  v1 = 0;
  if ( dword_8AC390 > 0 )
  {
    v2 = 0;
    v47 = 0;
    do
    {
      v3 = v1 + 1;
      v48 = v1;
      if ( v1 + 1 < v0 )
      {
        v4 = v2 + 1060;
        do
        {
          if ( sub_4C3890((char *)(v4 + dword_8AC394), v2 + dword_8AC394) )
          {
            v48 = v3;
            v2 = v4;
          }
          v0 = dword_8AC390;
          ++v3;
          v4 += 1060;
        }
        while ( v3 < dword_8AC390 );
        if ( v48 != v1 )
        {
          v5 = dword_8AC394 + v47;
          v6 = sub_415C30((char **)(dword_8AC394 + v47));
          sub_566650(v6);
          v7 = sub_415C30((char **)(v5 + 8));
          sub_566650(v7);
          v8 = sub_415C30((char **)(v5 + 16));
          sub_566650(v8);
          v9 = sub_415C30((char **)(v5 + 24));
          sub_566650(v9);
          v10 = sub_415C30((char **)(v5 + 32));
          sub_566650(v10);
          v11 = v5 - (_DWORD)v49;
          v12 = &v50;
          v13 = 16;
          do
          {
            *v12 = v12[v11];
            ++v12;
            --v13;
          }
          while ( v13 );
          v51 = *(_DWORD *)(v5 + 56);
          v52 = *(_DWORD *)(v5 + 60);
          v53 = *(_DWORD *)(v5 + 64);
          v54 = *(_DWORD *)(v5 + 68);
          v55 = *(_DWORD *)(v5 + 72);
          v56 = *(_DWORD *)(v5 + 76);
          v57 = *(_DWORD *)(v5 + 80);
          v58 = *(_DWORD *)(v5 + 84);
          v59 = *(_DWORD *)(v5 + 88);
          v60 = *(_DWORD *)(v5 + 92);
          v61 = *(_DWORD *)(v5 + 96);
          v62 = *(_DWORD *)(v5 + 100);
          v63 = *(_DWORD *)(v5 + 104);
          v64 = *(_DWORD *)(v5 + 108);
          v65 = *(_DWORD *)(v5 + 112);
          v14 = &v66;
          v15 = 8;
          do
          {
            *v14 = v14[v11];
            ++v14;
            --v15;
          }
          while ( v15 );
          v16 = &v67;
          v17 = 64;
          do
          {
            *v16 = v16[v11];
            ++v16;
            --v17;
          }
          while ( v17 );
          v18 = &v68;
          v19 = 64;
          do
          {
            *v18 = v18[v11];
            ++v18;
            --v19;
          }
          while ( v19 );
          v20 = &v69;
          v21 = 64;
          do
          {
            *v20 = v20[v11];
            ++v20;
            --v21;
          }
          while ( v21 );
          v22 = &v70;
          v23 = 64;
          do
          {
            *v22 = v22[v11];
            ++v22;
            --v23;
          }
          while ( v23 );
          v24 = &v71;
          v25 = 64;
          do
          {
            *v24 = v24[v11];
            ++v24;
            --v25;
          }
          while ( v25 );
          v26 = &v72;
          v27 = 256;
          do
          {
            *v26 = v26[v11];
            ++v26;
            --v27;
          }
          while ( v27 );
          v28 = &v73;
          v29 = 128;
          do
          {
            *v28 = v28[v11];
            ++v28;
            --v29;
          }
          while ( v29 );
          v30 = &v74;
          v31 = 16;
          do
          {
            *v30 = v30[v11];
            ++v30;
            --v31;
          }
          while ( v31 );
          v32 = &v75;
          v33 = 64;
          do
          {
            *v32 = v32[v11];
            ++v32;
            --v33;
          }
          while ( v33 );
          v34 = &v76;
          v35 = 16;
          do
          {
            *v34 = v34[v11];
            ++v34;
            --v35;
          }
          while ( v35 );
          v36 = &v77;
          v37 = 16;
          do
          {
            *v36 = v36[v11];
            ++v36;
            --v37;
          }
          while ( v37 );
          v38 = &v78;
          v39 = 16;
          do
          {
            *v38 = v38[v11];
            ++v38;
            --v39;
          }
          while ( v39 );
          v40 = &v79;
          v41 = 16;
          do
          {
            *v40 = v40[v11];
            ++v40;
            --v41;
          }
          while ( v41 );
          v42 = sub_415C30((char **)(v5 + 972));
          sub_566650(v42);
          v80 = *(_DWORD *)(v5 + 980);
          v43 = sub_415C30((char **)(v5 + 984));
          sub_566650(v43);
          v44 = &v81;
          v45 = 64;
          do
          {
            *v44 = v44[v11];
            ++v44;
            --v45;
          }
          while ( v45 );
          v82 = *(_DWORD *)(v5 + 1056);
          sub_4C45D0(1060 * v48 + dword_8AC394);
          sub_4C45D0(v49);
          v0 = dword_8AC390;
        }
        v3 = v1 + 1;
      }
      v1 = v3;
      v2 = v47 + 1060;
      v47 += 1060;
    }
    while ( v3 < v0 );
  }
  return sub_4C3130(v49);
}
