int __cdecl sub_556F29(_DWORD *a1, int a2)
{
  int v3; // eax
  bool v4; // cc
  int v5; // esi
  unsigned int v6; // ebx
  unsigned int v7; // ecx
  int v8; // eax
  int v10; // eax
  _DWORD *v11; // eax
  unsigned __int16 *v12; // eax
  int v13; // ecx
  int v14; // eax
  __int16 **v15; // edx
  __int16 *v16; // ecx
  __int16 *v17; // eax
  int v18; // edx
  int v19; // ecx
  int v20; // eax
  int v21; // edx
  int v22; // eax
  int v23; // ecx
  int v24; // eax
  int v25; // ecx
  int v26; // ecx
  int v27; // ebx
  int v28; // eax
  int v29; // edx
  int v30; // eax
  int v31; // eax
  int v32; // edx
  int v33; // ecx
  int v34; // eax
  int v35; // eax
  int v36; // ecx
  int v37; // eax
  int v38; // ecx
  int v39; // edx
  int v40; // ecx
  int v41; // eax
  int v42; // eax
  int v43; // ecx
  int v44; // eax
  int v45; // ecx
  int v46; // edx
  int v47; // ecx
  int v48; // eax
  int v49; // eax
  int v50; // ecx
  int v51; // eax
  int v52; // ecx
  int v53; // eax
  _BYTE v54[2]; // [esp+8h] [ebp-98h] BYREF
  __int16 v55; // [esp+Ah] [ebp-96h]
  __int16 v56; // [esp+Ch] [ebp-94h]
  __int16 v57; // [esp+18h] [ebp-88h]
  __int16 v58; // [esp+1Ah] [ebp-86h]
  __int16 v59; // [esp+28h] [ebp-78h]
  void (__cdecl *v60)(_DWORD *, int, _BYTE *, int, int); // [esp+88h] [ebp-18h]
  unsigned int v61; // [esp+8Ch] [ebp-14h]
  int v62; // [esp+90h] [ebp-10h]
  int v63; // [esp+94h] [ebp-Ch]
  int v64; // [esp+98h] [ebp-8h]
  unsigned int v65; // [esp+9Ch] [ebp-4h]
  int v66; // [esp+A0h] [ebp+0h]
  int v67; // [esp+A4h] [ebp+4h]
  int v68; // [esp+A8h] [ebp+8h]
  int i; // [esp+ACh] [ebp+Ch]
  __int16 *v70; // [esp+B0h] [ebp+10h]
  int v71; // [esp+B4h] [ebp+14h]
  __int16 *v72; // [esp+B8h] [ebp+18h]
  int v73; // [esp+BCh] [ebp+1Ch]
  int v74; // [esp+C0h] [ebp+20h]
  int v75; // [esp+C4h] [ebp+24h]
  unsigned int v76; // [esp+C8h] [ebp+28h]
  int v77; // [esp+CCh] [ebp+2Ch]
  int v78; // [esp+D0h] [ebp+30h]
  int v79; // [esp+D4h] [ebp+34h]
  int v80; // [esp+D8h] [ebp+38h]
  int v81; // [esp+DCh] [ebp+3Ch]
  int v82; // [esp+E0h] [ebp+40h]
  int v83; // [esp+E4h] [ebp+44h]
  int v84; // [esp+E8h] [ebp+48h]
  int v85; // [esp+ECh] [ebp+4Ch]
  _DWORD *v86; // [esp+F0h] [ebp+50h]
  int v87; // [esp+F4h] [ebp+54h]
  int v88; // [esp+F8h] [ebp+58h]
  int v89; // [esp+FCh] [ebp+5Ch]
  int v90; // [esp+100h] [ebp+60h]
  __int16 *v91; // [esp+104h] [ebp+64h]
  char v92; // [esp+10Bh] [ebp+6Bh]
  _DWORD *v93; // [esp+10Ch] [ebp+6Ch]
  char v94; // [esp+11Bh] [ebp+7Bh]

  v66 = a1[97];
  v61 = a1[70] - 1;
  while ( a1[31] <= a1[33] )
  {
    v3 = a1[99];
    if ( *(_BYTE *)(v3 + 17) || a1[31] == a1[33] && a1[32] > a1[34] + (unsigned int)(a1[90] == 0) )
      break;
    if ( !(*(int (__cdecl **)(_DWORD *))v3)(a1) )
      return 0;
  }
  v4 = a1[8] <= 0;
  v5 = a1[49];
  v74 = 0;
  if ( !v4 )
  {
    v67 = 0;
    v68 = -72 - v66;
    v86 = (_DWORD *)(v66 + 72);
    do
    {
      if ( *(_BYTE *)(v5 + 48) )
      {
        v6 = a1[34];
        v7 = *(_DWORD *)(v5 + 12);
        if ( v6 >= v61 )
        {
          v90 = *(_DWORD *)(v5 + 32) % v7;
          if ( !v90 )
            v90 = v7;
          v8 = v90;
          v92 = 1;
        }
        else
        {
          v90 = *(_DWORD *)(v5 + 12);
          v8 = 2 * v7;
          v92 = 0;
        }
        if ( v6 )
        {
          v94 = 0;
          v10 = (*(int (__cdecl **)(_DWORD *, _DWORD, unsigned int, unsigned int, _DWORD))(a1[1] + 32))(
                  a1,
                  *v86,
                  v7 * (v6 - 1),
                  v7 + v8,
                  0)
              + 4 * *(_DWORD *)(v5 + 12);
        }
        else
        {
          v10 = (*(int (__cdecl **)(_DWORD *, _DWORD, _DWORD, int, _DWORD))(a1[1] + 32))(a1, *v86, 0, v8, 0);
          v94 = 1;
        }
        v64 = v10;
        v11 = (_DWORD *)(v67 + *(_DWORD *)(v66 + 112));
        v88 = 0;
        v93 = v11;
        v12 = *(unsigned __int16 **)(v5 + 76);
        v87 = *v12;
        v78 = v12[1];
        v83 = v12[8];
        v75 = v12[16];
        v13 = v12[9];
        v77 = v12[2];
        v14 = v68 + a1[102];
        v81 = v13;
        v60 = *(void (__cdecl **)(_DWORD *, int, _BYTE *, int, int))((char *)v86 + v14 + 4);
        for ( i = *(_DWORD *)(a2 + 4 * v74); v88 < v90; i += 4 * v53 )
        {
          v15 = (__int16 **)(v64 + 4 * v88);
          v16 = *v15;
          v91 = *v15;
          if ( !v94 || v88 )
            v16 = *(v15 - 1);
          if ( !v92 || (v17 = v91, v88 != v90 - 1) )
            v17 = v15[1];
          v18 = *v16;
          v71 = 0;
          v76 = 0;
          v79 = v18;
          v84 = v18;
          v62 = v18;
          v89 = *v91;
          v82 = v89;
          v73 = v89;
          v80 = *v17;
          v85 = v80;
          v63 = v80;
          v65 = *(_DWORD *)(v5 + 28) - 1;
          v72 = v17 + 64;
          v70 = v16 + 64;
          do
          {
            sub_552919(v91, v54, 1);
            if ( v76 < v65 )
            {
              v79 = *v70;
              v89 = v91[64];
              v80 = *v72;
            }
            if ( v93[1] && !v55 )
            {
              v19 = v78 << 8;
              v20 = v78 << 7;
              v21 = 36 * v87 * (v73 - v89);
              if ( v21 < 0 )
              {
                v24 = (v20 - v21) / v19;
                v25 = v93[1];
                if ( v25 > 0 && v24 >= 1 << v25 )
                  v24 = (1 << v25) - 1;
                v22 = -v24;
              }
              else
              {
                v22 = (v21 + v20) / v19;
                v23 = v93[1];
                if ( v23 > 0 && v22 >= 1 << v23 )
                  LOWORD(v22) = (1 << v23) - 1;
              }
              v55 = v22;
            }
            v26 = v93[2];
            if ( v26 && !v57 )
            {
              v27 = v83 << 8;
              v28 = v83 << 7;
              v29 = 36 * v87 * (v84 - v85);
              if ( v29 < 0 )
              {
                v31 = (v28 - v29) / v27;
                if ( v26 > 0 && v31 >= 1 << v26 )
                  v31 = (1 << v26) - 1;
                v30 = -v31;
              }
              else
              {
                v30 = (v29 + v28) / v27;
                if ( v26 > 0 && v30 >= 1 << v26 )
                  LOWORD(v30) = (1 << v26) - 1;
              }
              v57 = v30;
            }
            if ( v93[3] && !v59 )
            {
              v32 = 9 * v87 * (v84 + v85 - 2 * v82);
              v33 = v75 << 8;
              v34 = v75 << 7;
              if ( v32 < 0 )
              {
                v37 = (v34 - v32) / v33;
                v38 = v93[3];
                if ( v38 > 0 && v37 >= 1 << v38 )
                  v37 = (1 << v38) - 1;
                v35 = -v37;
              }
              else
              {
                v35 = (v32 + v34) / v33;
                v36 = v93[3];
                if ( v36 > 0 && v35 >= 1 << v36 )
                  LOWORD(v35) = (1 << v36) - 1;
              }
              v59 = v35;
            }
            if ( v93[4] && !v58 )
            {
              v39 = 5 * v87 * (v62 + v80 - v63 - v79);
              v40 = v81 << 8;
              v41 = v81 << 7;
              if ( v39 < 0 )
              {
                v44 = (v41 - v39) / v40;
                v45 = v93[4];
                if ( v45 > 0 && v44 >= 1 << v45 )
                  v44 = (1 << v45) - 1;
                v42 = -v44;
              }
              else
              {
                v42 = (v39 + v41) / v40;
                v43 = v93[4];
                if ( v43 > 0 && v42 >= 1 << v43 )
                  LOWORD(v42) = (1 << v43) - 1;
              }
              v58 = v42;
            }
            if ( v93[5] && !v56 )
            {
              v46 = 9 * v87 * (v73 + v89 - 2 * v82);
              v47 = v77 << 8;
              v48 = v77 << 7;
              if ( v46 < 0 )
              {
                v51 = (v48 - v46) / v47;
                v52 = v93[5];
                if ( v52 > 0 && v51 >= 1 << v52 )
                  v51 = (1 << v52) - 1;
                v49 = -v51;
              }
              else
              {
                v49 = (v46 + v48) / v47;
                v50 = v93[5];
                if ( v50 > 0 && v49 >= 1 << v50 )
                  LOWORD(v49) = (1 << v50) - 1;
              }
              v56 = v49;
            }
            v60(a1, v5, v54, i, v71);
            v91 += 64;
            v70 += 64;
            v72 += 64;
            v62 = v84;
            v84 = v79;
            v73 = v82;
            v82 = v89;
            v63 = v85;
            v85 = v80;
            v71 += *(_DWORD *)(v5 + 36);
            ++v76;
          }
          while ( v76 <= v65 );
          v53 = *(_DWORD *)(v5 + 36);
          ++v88;
        }
      }
      ++v74;
      v67 += 24;
      ++v86;
      v5 += 84;
    }
    while ( v74 < a1[8] );
  }
  return 4 - (++a1[34] < a1[70]);
}
