int __thiscall sub_5D2070(_DWORD *this, int a2, int a3, _BYTE *a4)
{
  char v5; // bl
  bool v6; // zf
  int v7; // eax
  int v8; // eax
  float v9; // ecx
  float v10; // edx
  int v11; // eax
  int v12; // ecx
  int v13; // edx
  int v14; // eax
  float v15; // ecx
  float v16; // edx
  float v17; // eax
  int v18; // eax
  int v19; // edx
  int v20; // ecx
  int v21; // edx
  float v22; // ecx
  float v23; // edx
  float v24; // ecx
  float v25; // edx
  float v26; // ecx
  float v27; // edx
  char v28; // al
  float v29; // ecx
  float v30; // edx
  int v31; // eax
  int v32; // ecx
  int v33; // edx
  float v34; // eax
  float v35; // ecx
  float v36; // edx
  int v37; // eax
  float *v38; // eax
  float *v39; // eax
  float v40; // edx
  float v41; // edx
  float v42; // eax
  float *v43; // eax
  float *v44; // eax
  double v45; // st7
  double v46; // st6
  int v47; // ecx
  double v48; // st5
  double v49; // st3
  double v50; // st4
  float *v51; // eax
  float *v52; // eax
  int result; // eax
  float v54; // edx
  float v55; // edx
  float v56; // ecx
  float v57; // edx
  float v58; // ecx
  float v59; // edx
  float v60; // ecx
  int v61; // edx
  int v62; // ecx
  int v63; // edx
  float v64; // ecx
  float v65; // edx
  float v66; // ecx
  float v67; // edx
  float v68; // ecx
  float v69; // edx
  int v70; // ecx
  int v71; // edx
  int v72; // ecx
  float v73; // edx
  float v74; // ecx
  float v75; // edx
  float v76; // ecx
  float v77; // edx
  float v78; // ecx
  int v79; // [esp+0h] [ebp-D8h]
  float v80; // [esp+0h] [ebp-D8h]
  float v81; // [esp+10h] [ebp-C8h]
  char v82; // [esp+17h] [ebp-C1h] BYREF
  float v83; // [esp+18h] [ebp-C0h] BYREF
  float v84; // [esp+1Ch] [ebp-BCh]
  float v85; // [esp+20h] [ebp-B8h]
  float v86; // [esp+28h] [ebp-B0h] BYREF
  int v87; // [esp+2Ch] [ebp-ACh]
  int v88; // [esp+30h] [ebp-A8h]
  int v89; // [esp+34h] [ebp-A4h]
  float v90; // [esp+38h] [ebp-A0h]
  float v91; // [esp+3Ch] [ebp-9Ch]
  float v92; // [esp+40h] [ebp-98h]
  float v93; // [esp+44h] [ebp-94h]
  float v94; // [esp+48h] [ebp-90h]
  float v95; // [esp+4Ch] [ebp-8Ch]
  int v96; // [esp+50h] [ebp-88h] BYREF
  int v97; // [esp+54h] [ebp-84h]
  int v98; // [esp+58h] [ebp-80h]
  int v99; // [esp+5Ch] [ebp-7Ch]
  float v100; // [esp+60h] [ebp-78h]
  float v101; // [esp+64h] [ebp-74h]
  float v102; // [esp+68h] [ebp-70h]
  float v103; // [esp+6Ch] [ebp-6Ch]
  float v104; // [esp+70h] [ebp-68h]
  float v105; // [esp+74h] [ebp-64h]
  float v106; // [esp+78h] [ebp-60h]
  float v107; // [esp+7Ch] [ebp-5Ch]
  float v108; // [esp+80h] [ebp-58h]
  _BYTE v109[12]; // [esp+84h] [ebp-54h] BYREF
  int v110; // [esp+90h] [ebp-48h]
  float v111; // [esp+94h] [ebp-44h]
  float v112; // [esp+98h] [ebp-40h]
  float v113; // [esp+9Ch] [ebp-3Ch]
  float v114; // [esp+A0h] [ebp-38h]
  float v115; // [esp+A4h] [ebp-34h]
  float v116; // [esp+A8h] [ebp-30h]
  float v117; // [esp+ACh] [ebp-2Ch]
  float v118; // [esp+B0h] [ebp-28h]
  float v119; // [esp+B4h] [ebp-24h]
  int v120[4]; // [esp+B8h] [ebp-20h] BYREF
  float v121[4]; // [esp+C8h] [ebp-10h] BYREF

  *a4 = 1;
  v79 = this[2];
  v5 = 0;
  *(float *)&v96 = 0.0;
  v97 = 0;
  v98 = 0;
  v99 = 1065353216;
  v82 = 0;
  v6 = sub_5BFDA0((_DWORD *)a3, v79) == 0;
  v7 = this[2];
  if ( v6 )
  {
    if ( *(_BYTE *)(v7 + 83)
      || !(*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)(v7 + 60) + 24))(*(_DWORD *)(v7 + 60)) )
    {
      goto LABEL_7;
    }
    v9 = *(float *)(a3 + 268);
    v10 = *(float *)(a3 + 272);
    v100 = *(float *)(a3 + 264);
    v11 = *(int *)(a3 + 196);
    v101 = v9;
    v12 = *(_DWORD *)(a3 + 200);
    v102 = v10;
    v13 = *(_DWORD *)(a3 + 204);
    v96 = v11;
    v14 = *(_DWORD *)(a3 + 208);
    v97 = v12;
    v15 = *(float *)(a3 + 276);
    v98 = v13;
    v16 = *(float *)(a3 + 280);
    v99 = v14;
    v17 = *(float *)(a3 + 284);
    v103 = v15;
    v104 = v16;
    v105 = v17;
  }
  else
  {
    v80 = *(double *)v7;
    v8 = (*(int (__stdcall **)(_BYTE *, _DWORD, int, _DWORD))(**(_DWORD **)(v7 + 60) + 12))(
           v109,
           *this,
           a3,
           LODWORD(v80));
    v96 = *(int *)v8;
    v97 = *(_DWORD *)(v8 + 4);
    v98 = *(_DWORD *)(v8 + 8);
    v99 = *(_DWORD *)(v8 + 12);
    v100 = *(float *)(v8 + 16);
    v101 = *(float *)(v8 + 20);
    v102 = *(float *)(v8 + 24);
    v103 = *(float *)(v8 + 28);
    v104 = *(float *)(v8 + 32);
    v105 = *(float *)(v8 + 36);
  }
  v5 = 1;
LABEL_7:
  sub_5D1530(&v96, this[2], (_DWORD *)a3);
  if ( this[4] )
  {
    v18 = sub_5D2070(v109, a3, &v82);
    v19 = *(_DWORD *)(v18 + 4);
    v86 = *(float *)v18;
    v20 = *(_DWORD *)(v18 + 8);
    v87 = v19;
    v21 = *(_DWORD *)(v18 + 12);
    v88 = v20;
    v22 = *(float *)(v18 + 16);
    v89 = v21;
    v23 = *(float *)(v18 + 20);
    v90 = v22;
    v24 = *(float *)(v18 + 24);
    v91 = v23;
    v25 = *(float *)(v18 + 28);
    v92 = v24;
    v26 = *(float *)(v18 + 32);
    v93 = v25;
    v27 = *(float *)(v18 + 36);
    v28 = v82;
    v94 = v26;
    v95 = v27;
  }
  else
  {
    v29 = *(float *)(a3 + 268);
    v30 = *(float *)(a3 + 272);
    v90 = *(float *)(a3 + 264);
    v86 = *(float *)(a3 + 196);
    v31 = *(_DWORD *)(a3 + 208);
    v91 = v29;
    v32 = *(_DWORD *)(a3 + 200);
    v92 = v30;
    v33 = *(_DWORD *)(a3 + 204);
    v89 = v31;
    v34 = *(float *)(a3 + 284);
    v87 = v32;
    v35 = *(float *)(a3 + 276);
    v88 = v33;
    v36 = *(float *)(a3 + 280);
    v95 = v34;
    v93 = v35;
    v94 = v36;
    v28 = 1;
  }
  if ( v5 )
  {
    if ( v28 )
    {
      v37 = this[2];
      v81 = *(float *)(v37 + 32);
      if ( this[4] && *(_DWORD *)(v37 + 72) == 1 )
      {
        v117 = v100 - *(float *)(a3 + 264);
        v118 = v101 - *(float *)(a3 + 268);
        v119 = v102 - *(float *)(a3 + 272);
        v106 = v103 - *(float *)(a3 + 276);
        v107 = v104 - *(float *)(a3 + 280);
        v108 = v105 - *(float *)(a3 + 284);
        v38 = sub_5C6D50((float *)(a3 + 196), (float *)v120, (float *)&v96, v81);
        v39 = sub_5D1DF0(v38);
        v40 = *v39;
        v121[1] = v39[1];
        v121[0] = v40;
        v41 = v39[2];
        v42 = v39[3];
        v121[2] = v41;
        v121[3] = v42;
        sub_5D1E60((float *)(a3 + 196), (float *)v120);
        v84 = v118 * v81;
        v85 = v119 * v81;
        v85 = v85 + v92;
        v113 = v85;
        v111 = v117 * v81 + v90;
        v112 = v84 + v91;
        v43 = sub_5D1CD0(&v83, (float *)v120, v121);
        v44 = sub_5D1CD0((float *)v120, &v86, v43);
        v45 = *v44;
        v46 = v44[1];
        v47 = *((_DWORD *)v44 + 3);
        v48 = v44[2];
        v84 = v107 * v81;
        v85 = v108 * v81;
        v85 = v85 + v95;
        v49 = v106 * v81 + v93;
        v50 = v84 + v94;
      }
      else
      {
        v108 = v102 - v92;
        v83 = (v100 - v90) * v81;
        v84 = (v101 - v91) * v81;
        v85 = v108 * v81 + v92;
        v113 = v85;
        v111 = v83 + v90;
        v112 = v84 + v91;
        v51 = sub_5C6D50(&v86, (float *)v120, (float *)&v96, v81);
        v52 = sub_5D1DF0(v51);
        v45 = *v52;
        v46 = v52[1];
        v47 = *((_DWORD *)v52 + 3);
        v48 = v52[2];
        v108 = v105 - v95;
        v83 = (v103 - v93) * v81;
        v84 = (v104 - v94) * v81;
        v49 = v83 + v93;
        v50 = v84 + v94;
        v85 = v108 * v81 + v95;
      }
      result = a2;
      v114 = v49;
      v54 = v85;
      v115 = v50;
      *(_DWORD *)(a2 + 12) = v47;
      v116 = v54;
      v55 = v111;
      *(float *)a2 = v45;
      v110 = v47;
      v56 = v112;
      *(float *)(a2 + 4) = v46;
      *(float *)(a2 + 8) = v48;
      *(float *)(a2 + 16) = v55;
      v57 = v113;
      *(float *)(a2 + 20) = v56;
      v58 = v114;
      *(float *)(a2 + 24) = v57;
      v59 = v115;
      *(float *)(a2 + 28) = v58;
      v60 = v116;
      *(float *)(a2 + 32) = v59;
      *(float *)(a2 + 36) = v60;
    }
    else
    {
      result = a2;
      v61 = v97;
      *(float *)a2 = *(float *)&v96;
      v62 = v98;
      *(_DWORD *)(a2 + 4) = v61;
      v63 = v99;
      *(_DWORD *)(a2 + 8) = v62;
      v64 = v100;
      *(_DWORD *)(a2 + 12) = v63;
      v65 = v101;
      *(float *)(a2 + 16) = v64;
      v66 = v102;
      *(float *)(a2 + 20) = v65;
      v67 = v103;
      *(float *)(a2 + 24) = v66;
      v68 = v104;
      *(float *)(a2 + 28) = v67;
      v69 = v105;
      *(float *)(a2 + 32) = v68;
      *(float *)(a2 + 36) = v69;
    }
  }
  else
  {
    result = a2;
    v70 = v87;
    *(float *)a2 = v86;
    v71 = v88;
    *(_DWORD *)(a2 + 4) = v70;
    v72 = v89;
    *(_DWORD *)(a2 + 8) = v71;
    v73 = v90;
    *(_DWORD *)(a2 + 12) = v72;
    v74 = v91;
    *(float *)(a2 + 16) = v73;
    v75 = v92;
    *(float *)(a2 + 20) = v74;
    v76 = v93;
    *(float *)(a2 + 24) = v75;
    v77 = v94;
    *(float *)(a2 + 28) = v76;
    v78 = v95;
    *(float *)(a2 + 32) = v77;
    *(float *)(a2 + 36) = v78;
  }
  return result;
}
