void __thiscall sub_61A2A0(int this)
{
  int v1; // edi
  int v2; // ebx
  int v3; // eax
  double v4; // st7
  int v5; // eax
  unsigned __int8 v6; // dl
  int v7; // esi
  int v8; // ebp
  int v9; // eax
  double v10; // st7
  int v11; // eax
  double v12; // st7
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // edi
  double v20; // st6
  double v21; // st5
  double v22; // st4
  bool v23; // zf
  int v24; // eax
  int v25; // eax
  double *v26; // eax
  int v27; // eax
  int v28; // eax
  double *v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // eax
  double v33; // st7
  double *v34; // eax
  double v35; // st7
  int v36; // eax
  int v37; // eax
  int v38; // eax
  double *v39; // eax
  double *v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // eax
  int v44; // eax
  int v45; // eax
  int v46; // eax
  int v47; // eax
  int v48; // eax
  int v49; // eax
  int v50; // eax
  int v51; // eax
  int v52; // eax
  int v53; // eax
  int v54; // eax
  int v55; // eax
  int v56; // eax
  int v57; // eax
  int v58; // edx
  int v59; // ebp
  int v60; // eax
  double v61; // st7
  int v62; // eax
  int v63; // edi
  double v64; // st7
  int v65; // eax
  double *v66; // eax
  int v67; // eax
  int v68; // eax
  int v69; // eax
  int v70; // eax
  double v71; // st7
  double *v72; // eax
  double v73; // st7
  double *v74; // eax
  int v75; // eax
  int v76; // eax
  int v77; // eax
  int v78; // eax
  int v79; // eax
  int v80; // eax
  int v81; // eax
  int v82; // eax
  int v83; // eax
  int v84; // eax
  int v85; // eax
  int v86; // eax
  int v87; // edx
  int v88; // ebp
  int v89; // eax
  double v90; // st7
  int v91; // eax
  int v92; // edi
  double v93; // st7
  double v94; // st6
  double v95; // st5
  int v96; // eax
  double *v97; // eax
  int v98; // eax
  double v99; // st7
  double *v100; // eax
  double v101; // st7
  double *v102; // eax
  int v103; // eax
  int v104; // eax
  int v105; // eax
  unsigned __int8 v106; // [esp+13h] [ebp-9Dh]
  int i; // [esp+14h] [ebp-9Ch]
  double v108; // [esp+18h] [ebp-98h]
  double v109; // [esp+20h] [ebp-90h]
  double v110; // [esp+20h] [ebp-90h]
  double v111; // [esp+28h] [ebp-88h]
  double v112; // [esp+28h] [ebp-88h]
  double v113; // [esp+28h] [ebp-88h]
  double v114; // [esp+30h] [ebp-80h]
  double v115; // [esp+30h] [ebp-80h]
  double v116; // [esp+38h] [ebp-78h]
  double v117; // [esp+40h] [ebp-70h]
  double v118; // [esp+40h] [ebp-70h]
  double v119; // [esp+48h] [ebp-68h]
  double v120; // [esp+50h] [ebp-60h]
  double v121; // [esp+58h] [ebp-58h]
  int v122; // [esp+60h] [ebp-50h]
  int v123; // [esp+64h] [ebp-4Ch]
  double v124; // [esp+68h] [ebp-48h]
  double v125; // [esp+70h] [ebp-40h]
  double v126; // [esp+78h] [ebp-38h]
  double v127; // [esp+80h] [ebp-30h]
  double v128; // [esp+88h] [ebp-28h]
  double v129; // [esp+90h] [ebp-20h]
  double v130; // [esp+98h] [ebp-18h]
  double v131; // [esp+A0h] [ebp-10h]
  double v132; // [esp+A8h] [ebp-8h]

  v1 = *(_DWORD *)(this + 560);
  v2 = 0;
  v123 = 0;
  if ( v1 > 0 )
  {
    for ( i = 0; ; i += 56 )
    {
      v3 = *(_DWORD *)(this + 564);
      v4 = *(double *)(v3 + i + 40);
      v5 = i + v3;
      v6 = *(_BYTE *)(v5 + 52);
      v7 = *(_DWORD *)(v5 + 48);
      v106 = v6;
      v8 = v2;
      v124 = v4 * *(double *)(this + 264) - *(double *)(v5 + 32) * *(double *)(this + 288);
      v125 = *(double *)(this + 272) * *(double *)(v5 + 40) - *(double *)(this + 296) * *(double *)(v5 + 32);
      v126 = *(double *)(v5 + 40) * *(double *)(this + 280) - *(double *)(this + 304) * *(double *)(v5 + 32);
      v127 = *(double *)(v5 + 24) * *(double *)(this + 288) - *(double *)(this + 240) * *(double *)(v5 + 40);
      v128 = *(double *)(this + 296) * *(double *)(v5 + 24) - *(double *)(this + 248) * *(double *)(v5 + 40);
      v129 = *(double *)(v5 + 24) * *(double *)(this + 304) - *(double *)(this + 256) * *(double *)(v5 + 40);
      v130 = *(double *)(this + 240) * *(double *)(v5 + 32) - *(double *)(v5 + 24) * *(double *)(this + 264);
      v131 = *(double *)(this + 248) * *(double *)(v5 + 32) - *(double *)(v5 + 24) * *(double *)(this + 272);
      v132 = *(double *)(this + 256) * *(double *)(v5 + 32) - *(double *)(v5 + 24) * *(double *)(this + 280);
      if ( v2 < v1 )
        break;
LABEL_18:
      v58 = 0;
      if ( *(int *)(this + 568) > 0 )
      {
        v59 = 0;
        do
        {
          v60 = *(_DWORD *)(this + 572);
          v61 = v126 * *(double *)(v60 + v59 + 88);
          v62 = v59 + v60;
          v63 = *(_DWORD *)(v62 + 124);
          v64 = v61 + v125 * *(double *)(v62 + 80) + v124 * *(double *)(v62 + 72);
          v109 = v129 * *(double *)(v62 + 88) + v128 * *(double *)(v62 + 80) + v127 * *(double *)(v62 + 72);
          v112 = v132 * *(double *)(v62 + 88) + v131 * *(double *)(v62 + 80) + v130 * *(double *)(v62 + 72);
          v115 = v124 * *(double *)(v62 + 96) + v126 * *(double *)(v62 + 112) + v125 * *(double *)(v62 + 104);
          v116 = v127 * *(double *)(v62 + 96) + v129 * *(double *)(v62 + 112) + v128 * *(double *)(v62 + 104);
          v118 = v130 * *(double *)(v62 + 96) + v132 * *(double *)(v62 + 112) + v131 * *(double *)(v62 + 104);
          v23 = v106 == *(_BYTE *)(v62 + 128);
          v65 = *(_DWORD *)(this + 556);
          if ( v23 )
          {
            if ( v7 <= v63 )
            {
              *(double *)(*(_DWORD *)(v65 + 4 * v63) + 8 * v7) = v64 + *(double *)(*(_DWORD *)(v65 + 4 * v63) + 8 * v7);
              v83 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v63);
              *(double *)(v83 + 8 * v7 + 8) = v109 + *(double *)(v83 + 8 * v7 + 8);
              v84 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v63);
              *(double *)(v84 + 8 * v7 + 16) = v112 + *(double *)(v84 + 8 * v7 + 16);
              v85 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v63 + 4);
              *(double *)(v85 + 8 * v7) = v115 + *(double *)(v85 + 8 * v7);
              v86 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v63 + 4);
              *(double *)(v86 + 8 * v7 + 8) = v116 + *(double *)(v86 + 8 * v7 + 8);
              v72 = (double *)(*(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v63 + 4) + 8 * v7 + 16);
            }
            else
            {
              *(double *)(*(_DWORD *)(v65 + 4 * v7) + 8 * v63) = v64 + *(double *)(*(_DWORD *)(v65 + 4 * v7) + 8 * v63);
              v79 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7);
              *(double *)(v79 + 8 * v63 + 8) = v115 + *(double *)(v79 + 8 * v63 + 8);
              v80 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7 + 4);
              *(double *)(v80 + 8 * v63) = v109 + *(double *)(v80 + 8 * v63);
              v81 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7 + 4);
              *(double *)(v81 + 8 * v63 + 8) = v116 + *(double *)(v81 + 8 * v63 + 8);
              v82 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7 + 8);
              *(double *)(v82 + 8 * v63) = v112 + *(double *)(v82 + 8 * v63);
              v72 = (double *)(*(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7 + 8) + 8 * v63 + 8);
            }
            v73 = v118 + *v72;
          }
          else
          {
            if ( v7 <= v63 )
            {
              *(double *)(*(_DWORD *)(v65 + 4 * v63) + 8 * v7) = *(double *)(*(_DWORD *)(v65 + 4 * v63) + 8 * v7) - v64;
              v74 = (double *)(*(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v63) + 8 * v7 + 8);
              *v74 = *v74 - v109;
              v75 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v63);
              *(double *)(v75 + 8 * v7 + 16) = *(double *)(v75 + 8 * v7 + 16) - v112;
              v76 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v63 + 4);
              *(double *)(v76 + 8 * v7) = *(double *)(v76 + 8 * v7) - v115;
              v77 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v63 + 4);
              *(double *)(v77 + 8 * v7 + 8) = *(double *)(v77 + 8 * v7 + 8) - v116;
              v78 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v63 + 4);
              v71 = *(double *)(v78 + 8 * v7 + 16);
              v72 = (double *)(v78 + 8 * v7 + 16);
            }
            else
            {
              *(double *)(*(_DWORD *)(v65 + 4 * v7) + 8 * v63) = *(double *)(*(_DWORD *)(v65 + 4 * v7) + 8 * v63) - v64;
              v66 = (double *)(*(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7) + 8 * v63 + 8);
              *v66 = *v66 - v115;
              v67 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7 + 4);
              *(double *)(v67 + 8 * v63) = *(double *)(v67 + 8 * v63) - v109;
              v68 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7 + 4);
              *(double *)(v68 + 8 * v63 + 8) = *(double *)(v68 + 8 * v63 + 8) - v116;
              v69 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7 + 8);
              *(double *)(v69 + 8 * v63) = *(double *)(v69 + 8 * v63) - v112;
              v70 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7 + 8);
              v71 = *(double *)(v70 + 8 * v63 + 8);
              v72 = (double *)(v70 + 8 * v63 + 8);
            }
            v73 = v71 - v118;
          }
          *v72 = v73;
          ++v58;
          v59 += 136;
        }
        while ( v58 < *(_DWORD *)(this + 568) );
        v2 = v123;
      }
      v87 = 0;
      if ( *(int *)(this + 576) > 0 )
      {
        v88 = 0;
        do
        {
          v89 = *(_DWORD *)(this + 580);
          v90 = v125 * *(double *)(v89 + v88 + 40);
          v91 = v88 + v89;
          v92 = *(_DWORD *)(v91 + 48);
          v93 = (v126 * *(double *)(v91 + 24) - v124 * *(double *)(v91 + 40)) * *(double *)(v91 + 72)
              + (v90 - v126 * *(double *)(v91 + 32) + *(double *)(this + 184)) * *(double *)(v91 + 64)
              + (v124 * *(double *)(v91 + 32) - v125 * *(double *)(v91 + 24)) * *(double *)(v91 + 80);
          v110 = (v129 * *(double *)(v91 + 24) - v127 * *(double *)(v91 + 40) + *(double *)(this + 184))
               * *(double *)(v91 + 72)
               + (v128 * *(double *)(v91 + 40) - v129 * *(double *)(v91 + 32)) * *(double *)(v91 + 64)
               + (v127 * *(double *)(v91 + 32) - v128 * *(double *)(v91 + 24)) * *(double *)(v91 + 80);
          v94 = (v132 * *(double *)(v91 + 24) - v130 * *(double *)(v91 + 40)) * *(double *)(v91 + 72)
              + (v131 * *(double *)(v91 + 40) - v132 * *(double *)(v91 + 32)) * *(double *)(v91 + 64);
          v95 = (v130 * *(double *)(v91 + 32) - v131 * *(double *)(v91 + 24) + *(double *)(this + 184))
              * *(double *)(v91 + 80);
          v23 = v106 == *(_BYTE *)(v91 + 52);
          v96 = *(_DWORD *)(this + 556);
          v113 = v94 + v95;
          if ( v23 )
          {
            if ( v7 <= v92 )
            {
              *(double *)(*(_DWORD *)(v96 + 4 * v92) + 8 * v7) = v93 + *(double *)(*(_DWORD *)(v96 + 4 * v92) + 8 * v7);
              v105 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v92);
              *(double *)(v105 + 8 * v7 + 8) = v110 + *(double *)(v105 + 8 * v7 + 8);
              v100 = (double *)(*(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v92) + 8 * v7 + 16);
            }
            else
            {
              *(double *)(*(_DWORD *)(v96 + 4 * v7) + 8 * v92) = v93 + *(double *)(*(_DWORD *)(v96 + 4 * v7) + 8 * v92);
              v104 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7 + 4);
              *(double *)(v104 + 8 * v92) = v110 + *(double *)(v104 + 8 * v92);
              v100 = (double *)(*(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7 + 8) + 8 * v92);
            }
            v101 = v113 + *v100;
          }
          else
          {
            if ( v7 <= v92 )
            {
              *(double *)(*(_DWORD *)(v96 + 4 * v92) + 8 * v7) = *(double *)(*(_DWORD *)(v96 + 4 * v92) + 8 * v7) - v93;
              v102 = (double *)(*(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v92) + 8 * v7 + 8);
              *v102 = *v102 - v110;
              v103 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v92);
              v99 = *(double *)(v103 + 8 * v7 + 16);
              v100 = (double *)(v103 + 8 * v7 + 16);
            }
            else
            {
              *(double *)(*(_DWORD *)(v96 + 4 * v7) + 8 * v92) = *(double *)(*(_DWORD *)(v96 + 4 * v7) + 8 * v92) - v93;
              v97 = (double *)(*(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7 + 4) + 8 * v92);
              *v97 = *v97 - v110;
              v98 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7 + 8);
              v99 = *(double *)(v98 + 8 * v92);
              v100 = (double *)(v98 + 8 * v92);
            }
            v101 = v99 - v113;
          }
          *v100 = v101;
          ++v87;
          v88 += 88;
        }
        while ( v87 < *(_DWORD *)(this + 576) );
        v2 = v123;
      }
      v1 = *(_DWORD *)(this + 560);
      v123 = ++v2;
      if ( v2 >= v1 )
        return;
    }
    v122 = i;
    while ( 1 )
    {
      v9 = *(_DWORD *)(this + 564);
      v10 = v125 * *(double *)(v9 + v122 + 40);
      v11 = v122 + v9;
      v108 = v10 - v126 * *(double *)(v11 + 32) + *(double *)(this + 184);
      v114 = v128 * *(double *)(v11 + 40) - v129 * *(double *)(v11 + 32);
      v12 = v129 * *(double *)(v11 + 24) - v127 * *(double *)(v11 + 40) + *(double *)(this + 184);
      v119 = v131 * *(double *)(v11 + 40) - v132 * *(double *)(v11 + 32);
      v120 = v132 * *(double *)(v11 + 24) - v130 * *(double *)(v11 + 40);
      v121 = v130 * *(double *)(v11 + 32) - v131 * *(double *)(v11 + 24) + *(double *)(this + 184);
      if ( v2 == v8 )
        break;
      v19 = *(_DWORD *)(v11 + 48);
      v20 = v126 * *(double *)(v11 + 24) - v124 * *(double *)(v11 + 40);
      v111 = v124 * *(double *)(v11 + 32) - v125 * *(double *)(v11 + 24);
      v21 = v127 * *(double *)(v11 + 32);
      v22 = v128 * *(double *)(v11 + 24);
      v23 = v6 == *(_BYTE *)(v11 + 52);
      v24 = *(_DWORD *)(this + 556);
      v117 = v21 - v22;
      if ( !v23 )
      {
        if ( v7 <= v19 )
        {
          *(double *)(*(_DWORD *)(v24 + 4 * v19) + 8 * v7) = *(double *)(*(_DWORD *)(v24 + 4 * v19) + 8 * v7) - v108;
          v36 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v19);
          *(double *)(v36 + 8 * v7 + 8) = *(double *)(v36 + 8 * v7 + 8) - v114;
          v37 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v19);
          *(double *)(v37 + 8 * v7 + 16) = *(double *)(v37 + 8 * v7 + 16) - v119;
          v38 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v19 + 4);
          *(double *)(v38 + 8 * v7) = *(double *)(v38 + 8 * v7) - v20;
          v39 = (double *)(*(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v19 + 4) + 8 * v7 + 8);
          *v39 = *v39 - v12;
          v40 = (double *)(*(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v19 + 4) + 8 * v7 + 16);
          *v40 = *v40 - v120;
          v41 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v19 + 8);
          *(double *)(v41 + 8 * v7) = *(double *)(v41 + 8 * v7) - v111;
          v42 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v19 + 8);
          *(double *)(v42 + 8 * v7 + 8) = *(double *)(v42 + 8 * v7 + 8) - v117;
          v43 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v19 + 8);
          v33 = *(double *)(v43 + 8 * v7 + 16);
          v34 = (double *)(v43 + 8 * v7 + 16);
        }
        else
        {
          *(double *)(*(_DWORD *)(v24 + 4 * v7) + 8 * v19) = *(double *)(*(_DWORD *)(v24 + 4 * v7) + 8 * v19) - v108;
          v25 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7);
          *(double *)(v25 + 8 * v19 + 8) = *(double *)(v25 + 8 * v19 + 8) - v20;
          v26 = (double *)(*(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7) + 8 * v19 + 16);
          *v26 = *v26 - v111;
          v27 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7 + 4);
          *(double *)(v27 + 8 * v19) = *(double *)(v27 + 8 * v19) - v114;
          v28 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7 + 4);
          *(double *)(v28 + 8 * v19 + 8) = *(double *)(v28 + 8 * v19 + 8) - v12;
          v29 = (double *)(*(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7 + 4) + 8 * v19 + 16);
          *v29 = *v29 - v117;
          v30 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7 + 8);
          *(double *)(v30 + 8 * v19) = *(double *)(v30 + 8 * v19) - v119;
          v31 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7 + 8);
          *(double *)(v31 + 8 * v19 + 8) = *(double *)(v31 + 8 * v19 + 8) - v120;
          v32 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7 + 8);
          v33 = *(double *)(v32 + 8 * v19 + 16);
          v34 = (double *)(v32 + 8 * v19 + 16);
        }
        v35 = v33 - v121;
        goto LABEL_17;
      }
      if ( v7 <= v19 )
      {
        *(double *)(*(_DWORD *)(v24 + 4 * v19) + 8 * v7) = v108 + *(double *)(*(_DWORD *)(v24 + 4 * v19) + 8 * v7);
        v51 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v19);
        *(double *)(v51 + 8 * v7 + 8) = v114 + *(double *)(v51 + 8 * v7 + 8);
        v52 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v19);
        *(double *)(v52 + 8 * v7 + 16) = v119 + *(double *)(v52 + 8 * v7 + 16);
        v53 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v19 + 4);
        *(double *)(v53 + 8 * v7) = v20 + *(double *)(v53 + 8 * v7);
        v54 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v19 + 4);
        *(double *)(v54 + 8 * v7 + 8) = v12 + *(double *)(v54 + 8 * v7 + 8);
        v55 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v19 + 4);
        *(double *)(v55 + 8 * v7 + 16) = v120 + *(double *)(v55 + 8 * v7 + 16);
        v56 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v19 + 8);
        *(double *)(v56 + 8 * v7) = v111 + *(double *)(v56 + 8 * v7);
        v57 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v19 + 8);
        *(double *)(v57 + 8 * v7 + 8) = v117 + *(double *)(v57 + 8 * v7 + 8);
        v18 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v19 + 8);
        goto LABEL_15;
      }
      *(double *)(*(_DWORD *)(v24 + 4 * v7) + 8 * v19) = v108 + *(double *)(*(_DWORD *)(v24 + 4 * v7) + 8 * v19);
      v44 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7);
      *(double *)(v44 + 8 * v19 + 8) = v20 + *(double *)(v44 + 8 * v19 + 8);
      v45 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7);
      *(double *)(v45 + 8 * v19 + 16) = v111 + *(double *)(v45 + 8 * v19 + 16);
      v46 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7 + 4);
      *(double *)(v46 + 8 * v19) = v114 + *(double *)(v46 + 8 * v19);
      v47 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7 + 4);
      *(double *)(v47 + 8 * v19 + 8) = v12 + *(double *)(v47 + 8 * v19 + 8);
      v48 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7 + 4);
      *(double *)(v48 + 8 * v19 + 16) = v117 + *(double *)(v48 + 8 * v19 + 16);
      v49 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7 + 8);
      *(double *)(v49 + 8 * v19) = v119 + *(double *)(v49 + 8 * v19);
      v50 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7 + 8);
      *(double *)(v50 + 8 * v19 + 8) = v120 + *(double *)(v50 + 8 * v19 + 8);
      v34 = (double *)(*(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7 + 8) + 8 * v19 + 16);
LABEL_16:
      v35 = v121 + *v34;
LABEL_17:
      *v34 = v35;
      ++v8;
      v122 += 56;
      if ( v8 >= *(_DWORD *)(this + 560) )
        goto LABEL_18;
    }
    v13 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7);
    *(double *)(v13 + 8 * v7) = v108 + *(double *)(v13 + 8 * v7);
    v14 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7 + 4);
    *(double *)(v14 + 8 * v7) = v114 + *(double *)(v14 + 8 * v7);
    v15 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7 + 4);
    *(double *)(v15 + 8 * v7 + 8) = v12 + *(double *)(v15 + 8 * v7 + 8);
    v16 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7 + 8);
    *(double *)(v16 + 8 * v7) = v119 + *(double *)(v16 + 8 * v7);
    v17 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7 + 8);
    *(double *)(v17 + 8 * v7 + 8) = v120 + *(double *)(v17 + 8 * v7 + 8);
    v18 = *(_DWORD *)(*(_DWORD *)(this + 556) + 4 * v7 + 8);
LABEL_15:
    v34 = (double *)(v18 + 8 * v7 + 16);
    goto LABEL_16;
  }
}
