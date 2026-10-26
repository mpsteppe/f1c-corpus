void __thiscall sub_56F1C0(int this, float *a2)
{
  double v3; // st7
  double v4; // st7
  long double v5; // st7
  double v6; // st7
  float v7; // ecx
  float v8; // edx
  float v9; // ebx
  float *v10; // edi
  double v11; // st7
  double v12; // st6
  double v13; // st6
  double v14; // st7
  double v15; // st6
  double v16; // st7
  double v17; // st6
  double v18; // st7
  double v19; // st6
  float *v20; // eax
  float v21; // ecx
  float v22; // edx
  float *v23; // eax
  float v24; // ecx
  float v25; // edx
  float v26; // eax
  double v27; // st7
  double v28; // st7
  double v29; // st7
  double v30; // st6
  long double v31; // st5
  long double v32; // st5
  double v33; // st7
  double v34; // st7
  double v35; // st7
  long double v36; // st7
  long double v37; // st7
  long double v38; // st7
  int v39; // ecx
  float v40; // ebx
  int v41; // edx
  float *v42; // eax
  float v43; // ecx
  float v44; // edx
  float v45; // eax
  float *v46; // eax
  double v47; // st7
  double v48; // st6
  long double v49; // st5
  long double v50; // st5
  double v51; // st7
  double v52; // st7
  double v53; // st7
  long double v54; // st7
  long double v55; // st7
  long double v56; // st7
  int v57; // edx
  double v58; // st7
  int v59; // edx
  int v60; // ecx
  float v61; // ebx
  float *v62; // eax
  float v63; // ecx
  float v64; // edx
  float v65; // eax
  float *v66; // eax
  int v67; // ecx
  int v68; // edx
  int v69; // eax
  float *v70; // eax
  float v71; // ecx
  float v72; // edx
  float v73; // eax
  float *v74; // eax
  float v75; // [esp+20h] [ebp-D0h] BYREF
  float v76; // [esp+24h] [ebp-CCh]
  float v77; // [esp+28h] [ebp-C8h]
  float v78; // [esp+2Ch] [ebp-C4h]
  float v79; // [esp+30h] [ebp-C0h]
  float v80; // [esp+34h] [ebp-BCh]
  float v81; // [esp+38h] [ebp-B8h]
  float v82; // [esp+3Ch] [ebp-B4h]
  float v83; // [esp+40h] [ebp-B0h] BYREF
  float v84; // [esp+44h] [ebp-ACh]
  float v85; // [esp+48h] [ebp-A8h]
  float v86; // [esp+4Ch] [ebp-A4h]
  int v87; // [esp+50h] [ebp-A0h] BYREF
  float v88; // [esp+54h] [ebp-9Ch]
  float v89; // [esp+58h] [ebp-98h]
  float v90; // [esp+5Ch] [ebp-94h]
  float v91; // [esp+60h] [ebp-90h]
  float v92; // [esp+64h] [ebp-8Ch]
  float v93; // [esp+68h] [ebp-88h]
  float v94; // [esp+6Ch] [ebp-84h] BYREF
  float v95; // [esp+70h] [ebp-80h]
  float v96; // [esp+74h] [ebp-7Ch]
  int v97; // [esp+78h] [ebp-78h] BYREF
  float v98; // [esp+7Ch] [ebp-74h]
  float v99; // [esp+80h] [ebp-70h]
  int v100; // [esp+84h] [ebp-6Ch] BYREF
  float v101; // [esp+88h] [ebp-68h]
  float v102; // [esp+8Ch] [ebp-64h]
  float v103; // [esp+90h] [ebp-60h]
  float v104; // [esp+94h] [ebp-5Ch]
  float v105; // [esp+98h] [ebp-58h]
  float v106; // [esp+9Ch] [ebp-54h]
  float v107; // [esp+A0h] [ebp-50h]
  float v108; // [esp+A4h] [ebp-4Ch]
  float v109; // [esp+A8h] [ebp-48h]
  float v110; // [esp+ACh] [ebp-44h]
  float v111; // [esp+B0h] [ebp-40h]
  float v112; // [esp+B4h] [ebp-3Ch]
  float v113; // [esp+B8h] [ebp-38h]
  float v114; // [esp+BCh] [ebp-34h]
  float v115; // [esp+C0h] [ebp-30h]
  float v116; // [esp+C4h] [ebp-2Ch]
  float v117; // [esp+C8h] [ebp-28h]
  float v118; // [esp+CCh] [ebp-24h]
  float v119; // [esp+D0h] [ebp-20h]
  float v120; // [esp+D4h] [ebp-1Ch]
  float v121; // [esp+D8h] [ebp-18h]
  float v122; // [esp+DCh] [ebp-14h]
  float v123; // [esp+E0h] [ebp-10h]
  float v124; // [esp+E4h] [ebp-Ch]
  float v125; // [esp+E8h] [ebp-8h]
  float v126; // [esp+ECh] [ebp-4h]

  v83 = *(float *)(this + 2832) + *a2;
  v84 = *(float *)(this + 2836) + a2[1];
  v3 = *(float *)(this + 2840);
  v92 = v84;
  v4 = v3 + a2[2];
  v91 = v83;
  v85 = v4;
  v93 = v85;
  v83 = v83 - *(float *)(this + 2868);
  v75 = v83;
  v84 = v84 - *(float *)(this + 2872);
  v76 = v84;
  v85 = v85 - *(float *)(this + 2876);
  v77 = v85;
  v5 = sqrt(v83 * v83 + v85 * v85 + v84 * v84);
  v78 = v5;
  if ( v5 > 0.0 )
  {
    v6 = 1.0 / v78;
    v83 = v75 * v6;
    v7 = v83;
    v75 = v83;
    v84 = v76 * v6;
    v8 = v84;
    v76 = v84;
    v85 = v77 * v6;
    v9 = v85;
    v77 = v85;
    if ( v85 != 0.0 )
    {
      v10 = (float *)(this + 2880);
      v83 = v91 + *(float *)(this + 2868);
      v94 = v83;
      v84 = v92 + *(float *)(this + 2872);
      v95 = v84;
      v85 = v93 + *(float *)(this + 2876);
      v96 = v85;
      v11 = v84 * v76;
      v12 = v85;
      *(_DWORD *)(this + 2880) = *(_DWORD *)(this + 2868);
      v13 = v12 * v77;
      *(_DWORD *)(this + 2884) = *(_DWORD *)(this + 2872);
      v14 = v11 + v13;
      v15 = v94 * v75;
      *(float *)(this + 2940) = v7;
      *(float *)(this + 2944) = v8;
      v16 = (v14 + v15) * 0.5;
      v17 = v75 * *(float *)(this + 2868);
      *(float *)(this + 2948) = v9;
      v94 = 0.0;
      v18 = v16 - v17;
      v95 = 1.0;
      v19 = v76 * *(float *)(this + 2872);
      v96 = 0.0;
      *(float *)(this + 2888) = (v18 - v19) / v77;
      v20 = sub_401320(&v94, &v75, (float *)&v87);
      v21 = v20[1];
      v83 = *v20;
      v22 = v20[2];
      v84 = v21;
      v85 = v22;
      sub_409390(&v83);
      v23 = sub_401320(&v75, &v83, (float *)&v87);
      v24 = *v23;
      v25 = v23[1];
      v26 = v23[2];
      v104 = flt_B70E88 * 0.01745433;
      v94 = v24;
      v95 = v25;
      v96 = v26;
      v103 = flt_B70EAC * 0.01745433;
      if ( v104 >= (double)v103 )
        v27 = v103;
      else
        v27 = v104;
      v28 = v27 * v78;
      v78 = 0.0;
      v86 = 0.0;
      v126 = v28 * 0.031830989;
      while ( 1 )
      {
        v79 = v78 + v126;
        v29 = v83 * v79;
        v117 = v29;
        v123 = v117;
        v30 = v84 * v79;
        v118 = v30;
        v124 = v118;
        v90 = v85 * v79;
        v119 = v90;
        v125 = v90;
        v114 = v117 + *v10;
        v105 = v114;
        v115 = v118 + *(float *)(this + 2884);
        v106 = v115;
        v116 = v90 + *(float *)(this + 2888);
        v107 = v116;
        v111 = v114 - v91;
        v75 = v111;
        v112 = v115 - v92;
        v76 = v112;
        v113 = v116 - v93;
        v77 = v113;
        v31 = v111 * v111 + v113 * v113 + v112 * v112;
        if ( v31 > 0.0 )
        {
          v32 = 1.0 / sqrt(v31);
          v75 = v75 * v32;
          v76 = v76 * v32;
          v77 = v77 * v32;
        }
        v110 = v90;
        v120 = v29;
        v108 = v120;
        v121 = v30;
        v33 = *v10;
        v109 = v121;
        v122 = v90;
        *(float *)&v100 = v33 - v120;
        v34 = *(float *)(this + 2884);
        v97 = v100;
        v101 = v34 - v121;
        v35 = *(float *)(this + 2888);
        v98 = v101;
        v102 = v35 - v90;
        v99 = v102;
        *(float *)&v87 = *(float *)&v100 - v91;
        v80 = *(float *)&v87;
        v88 = v101 - v92;
        v81 = v88;
        v89 = v102 - v93;
        v82 = v89;
        v36 = *(float *)&v87 * *(float *)&v87 + v89 * v89 + v88 * v88;
        if ( v36 > 0.0 )
        {
          v37 = 1.0 / sqrt(v36);
          v80 = v80 * v37;
          v81 = v81 * v37;
          v82 = v82 * v37;
        }
        v38 = acos(v80 * v75 + v82 * v77 + v81 * v76);
        if ( v38 <= v86 )
          break;
        if ( v38 >= v104 )
        {
          v90 = (v104 - v86) / (v38 - v86) * (v79 - v78) + v78;
          v42 = sub_4012D0(&v83, (float *)&v97, v90);
          v43 = *v42;
          v44 = v42[1];
          v45 = v42[2];
          *(float *)&v87 = v43;
          v88 = v44;
          v89 = v45;
          v46 = sub_401250((float *)(this + 2880), (float *)&v87, (float *)&v100);
          off_16C9604(*(_DWORD *)v46, *((_DWORD *)v46 + 1), a2);
          return;
        }
        v86 = v38;
        v78 = v79;
      }
      *(float *)(this + 2892) = *v10;
      v39 = *(_DWORD *)(this + 2888);
      *(_DWORD *)(this + 2896) = *(_DWORD *)(this + 2884);
      *(_DWORD *)(this + 2900) = v39;
      v40 = *v10;
      *(float *)(this + 2892) = *(float *)(this + 2892) + 0.1;
      *(float *)(this + 2904) = v40;
      v41 = *(_DWORD *)(this + 2888);
      *(_DWORD *)(this + 2908) = *(_DWORD *)(this + 2884);
      *(_DWORD *)(this + 2912) = v41;
      *(float *)(this + 2904) = *(float *)(this + 2904) - 0.1;
      v86 = 0.0;
      v78 = 0.0;
      while ( 1 )
      {
        v79 = v86 + v126;
        v47 = v94 * v79;
        *(float *)&v87 = v47;
        v97 = v87;
        v48 = v95 * v79;
        v88 = v48;
        v98 = v88;
        v90 = v96 * v79;
        v89 = v90;
        v99 = v90;
        *(float *)&v100 = *(float *)&v87 + *v10;
        v108 = *(float *)&v100;
        v101 = v88 + *(float *)(this + 2884);
        v109 = v101;
        v102 = v90 + *(float *)(this + 2888);
        v110 = v102;
        v120 = *(float *)&v100 - v91;
        v80 = v120;
        v121 = v101 - v92;
        v81 = v121;
        v122 = v102 - v93;
        v82 = v122;
        v49 = v122 * v122 + v121 * v121 + v120 * v120;
        if ( v49 > 0.0 )
        {
          v50 = 1.0 / sqrt(v49);
          v80 = v80 * v50;
          v81 = v81 * v50;
          v82 = v82 * v50;
        }
        v107 = v90;
        v111 = v47;
        v105 = v111;
        v112 = v48;
        v51 = *v10;
        v106 = v112;
        v113 = v90;
        v114 = v51 - v111;
        v52 = *(float *)(this + 2884);
        v123 = v114;
        v115 = v52 - v112;
        v53 = *(float *)(this + 2888);
        v124 = v115;
        v116 = v53 - v90;
        v125 = v116;
        v117 = v114 - v91;
        v75 = v117;
        v118 = v115 - v92;
        v76 = v118;
        v119 = v116 - v93;
        v77 = v119;
        v54 = v119 * v119 + v118 * v118 + v117 * v117;
        if ( v54 > 0.0 )
        {
          v55 = 1.0 / sqrt(v54);
          v75 = v75 * v55;
          v76 = v76 * v55;
          v77 = v77 * v55;
        }
        v56 = acos(v77 * v82 + v76 * v81 + v75 * v80);
        if ( v56 <= v78 )
        {
          *(float *)(this + 2916) = *v10;
          v57 = *(_DWORD *)(this + 2888);
          *(_DWORD *)(this + 2920) = *(_DWORD *)(this + 2884);
          *(_DWORD *)(this + 2924) = v57;
          v58 = *(float *)(this + 2920) + 0.1;
          v59 = *(_DWORD *)(this + 2884);
          *(float *)(this + 2928) = *v10;
          *(float *)(this + 2920) = v58;
          v60 = *(_DWORD *)(this + 2888);
          *(_DWORD *)(this + 2932) = v59;
          *(_DWORD *)(this + 2936) = v60;
          *(float *)(this + 2932) = *(float *)(this + 2932) - 0.1;
          return;
        }
        if ( v56 >= v103 )
          break;
        v78 = v56;
        v86 = v79;
      }
      v90 = (v103 - v78) / (v56 - v78) * (v79 - v86) + v86;
      v61 = v90;
      v62 = sub_4012D0(&v94, (float *)&v97, v90);
      v63 = *v62;
      v64 = v62[1];
      v65 = v62[2];
      *(float *)&v87 = v63;
      v88 = v64;
      v89 = v65;
      v66 = sub_401250((float *)(this + 2880), (float *)&v87, (float *)&v100);
      v67 = *(_DWORD *)v66;
      v68 = *((_DWORD *)v66 + 1);
      v69 = *((_DWORD *)v66 + 2);
      *(_DWORD *)(this + 2916) = v67;
      *(_DWORD *)(this + 2920) = v68;
      *(_DWORD *)(this + 2924) = v69;
      v70 = sub_4012D0(&v94, (float *)&v97, v61);
      v71 = *v70;
      v72 = v70[1];
      v73 = v70[2];
      *(float *)&v87 = v71;
      v88 = v72;
      v89 = v73;
      v74 = sub_401290((float *)(this + 2880), (float *)&v87, (float *)&v100);
      off_16C98A0(*(_DWORD *)v74, *((_DWORD *)v74 + 1), a2);
    }
  }
}
