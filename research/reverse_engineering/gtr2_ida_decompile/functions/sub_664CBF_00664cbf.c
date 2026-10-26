int __thiscall sub_664CBF(_DWORD *this, unsigned int a2, int *a3, void *a4, void *a5, unsigned int a6)
{
  unsigned int v7; // ecx
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  int v13; // ecx
  int v14; // eax
  int v15; // ecx
  unsigned int v16; // edi
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  char *v25; // eax
  unsigned int v26; // ecx
  int v27; // edx
  unsigned int v28; // edx
  int v29; // edx
  _DWORD *v30; // eax
  int v31; // ecx
  unsigned int v32; // edx
  int v33; // ecx
  int v34; // ecx
  int v36; // [esp-Ch] [ebp-13Ch]
  int v37; // [esp-Ch] [ebp-13Ch]
  int v38; // [esp-Ch] [ebp-13Ch]
  int v39; // [esp-Ch] [ebp-13Ch]
  int v40; // [esp-Ch] [ebp-13Ch]
  int v41; // [esp-Ch] [ebp-13Ch]
  int v42; // [esp-Ch] [ebp-13Ch]
  int v43; // [esp-Ch] [ebp-13Ch]
  int v44; // [esp-Ch] [ebp-13Ch]
  __int64 v45; // [esp+0h] [ebp-130h]
  _DWORD v46[4]; // [esp+14h] [ebp-11Ch] BYREF
  double v47[2]; // [esp+24h] [ebp-10Ch] BYREF
  int v48; // [esp+34h] [ebp-FCh] BYREF
  int v49; // [esp+38h] [ebp-F8h]
  int v50; // [esp+3Ch] [ebp-F4h]
  int v51; // [esp+40h] [ebp-F0h]
  int v52; // [esp+44h] [ebp-ECh]
  int v53; // [esp+48h] [ebp-E8h]
  int v54; // [esp+4Ch] [ebp-E4h]
  int v55; // [esp+50h] [ebp-E0h]
  int v56; // [esp+54h] [ebp-DCh]
  int v57; // [esp+58h] [ebp-D8h]
  int v58; // [esp+5Ch] [ebp-D4h]
  unsigned int v59; // [esp+60h] [ebp-D0h]
  unsigned int v60; // [esp+64h] [ebp-CCh]
  int v61; // [esp+68h] [ebp-C8h]
  unsigned int v62; // [esp+6Ch] [ebp-C4h]
  unsigned int v63; // [esp+70h] [ebp-C0h]
  unsigned int v64; // [esp+74h] [ebp-BCh]
  unsigned int v65; // [esp+78h] [ebp-B8h]
  unsigned int v66; // [esp+7Ch] [ebp-B4h]
  int v67; // [esp+80h] [ebp-B0h]
  unsigned int v68; // [esp+84h] [ebp-ACh]
  unsigned int v69; // [esp+88h] [ebp-A8h]
  unsigned int v70; // [esp+8Ch] [ebp-A4h]
  int v71; // [esp+90h] [ebp-A0h]
  unsigned int v72; // [esp+94h] [ebp-9Ch]
  _DWORD *v73; // [esp+98h] [ebp-98h]
  _DWORD *v74; // [esp+9Ch] [ebp-94h]
  _DWORD *v75; // [esp+A0h] [ebp-90h]
  _DWORD *v76; // [esp+A4h] [ebp-8Ch]
  int v77; // [esp+A8h] [ebp-88h]
  _DWORD *v78; // [esp+ACh] [ebp-84h]
  _DWORD *v79; // [esp+B0h] [ebp-80h]
  int v80; // [esp+B4h] [ebp-7Ch]
  _DWORD *v81; // [esp+B8h] [ebp-78h]
  int v82; // [esp+BCh] [ebp-74h]
  _DWORD *v83; // [esp+C0h] [ebp-70h]
  int v84; // [esp+C4h] [ebp-6Ch]
  _DWORD *v85; // [esp+C8h] [ebp-68h]
  int v86; // [esp+CCh] [ebp-64h]
  _DWORD *v87; // [esp+D0h] [ebp-60h]
  _BYTE *v88; // [esp+D4h] [ebp-5Ch]
  unsigned int v89; // [esp+D8h] [ebp-58h]
  unsigned int v90; // [esp+DCh] [ebp-54h]
  unsigned int v91; // [esp+E0h] [ebp-50h]
  unsigned int v92; // [esp+E4h] [ebp-4Ch]
  unsigned int v93; // [esp+E8h] [ebp-48h]
  unsigned int v94; // [esp+ECh] [ebp-44h]
  unsigned int v95; // [esp+F0h] [ebp-40h]
  unsigned int v96; // [esp+F4h] [ebp-3Ch]
  unsigned int v97; // [esp+F8h] [ebp-38h]
  unsigned int v98; // [esp+FCh] [ebp-34h]
  char *v99; // [esp+100h] [ebp-30h]
  int v100; // [esp+104h] [ebp-2Ch] BYREF
  int v101; // [esp+108h] [ebp-28h] BYREF
  int v102; // [esp+10Ch] [ebp-24h] BYREF
  int v103; // [esp+110h] [ebp-20h] BYREF
  int v104; // [esp+114h] [ebp-1Ch] BYREF
  void *Block; // [esp+118h] [ebp-18h]
  int v106; // [esp+11Ch] [ebp-14h] BYREF
  int v107; // [esp+120h] [ebp-10h] BYREF
  int v108; // [esp+124h] [ebp-Ch] BYREF
  unsigned int v109; // [esp+128h] [ebp-8h] BYREF
  int v110; // [esp+12Ch] [ebp-4h]
  int v111; // [esp+13Ch] [ebp+Ch]
  int v112; // [esp+13Ch] [ebp+Ch]
  unsigned int v113; // [esp+148h] [ebp+18h]
  int v114; // [esp+148h] [ebp+18h]

  v7 = a6;
  v8 = 1;
  Block = 0;
  v109 = 1;
  if ( a6 > 1 )
  {
    while ( a3[v8] == *a3 )
    {
      if ( ++v8 >= a6 )
        goto LABEL_6;
    }
    v109 = 0;
  }
LABEL_6:
  v9 = *(_DWORD *)(this[2] + 108);
  if ( (v9 & 0x200) != 0 )
  {
    if ( a4 )
    {
      v110 = sub_6641F3(this, a2, a6 & 0xFFFFF | 0x10800000, (int)a4, a3, 0x1000000000LL);
      if ( v110 < 0 )
        goto LABEL_67;
      v7 = a6;
    }
    if ( !a5 || (v110 = sub_6641F3(this, a2, v7 & 0xFFFFF | 0x10900000, (int)a5, a3, 0x1000000000LL), v110 >= 0) )
LABEL_66:
      v110 = 0;
  }
  else if ( (v9 & 0x100) != 0 && v109 )
  {
    v10 = sub_681AAA(*(_DWORD *)(this[2] + 120), 0, 0, 0.1591549386630057);
    v11 = this[2];
    v109 = v10;
    v12 = sub_681AAA(*(_DWORD *)(v11 + 120), 0, 0, 0.5);
    v13 = this[2];
    v108 = v12;
    v14 = sub_681AAA(*(_DWORD *)(v13 + 120), 0, 0, 6.283185482025146);
    v15 = this[2];
    v106 = v14;
    v107 = sub_681AAA(*(_DWORD *)(v15 + 120), 0, 0, -3.141592741012573);
    v110 = sub_662830((int)this, *a3, v47);
    if ( v110 < 0 )
      goto LABEL_67;
    if ( v47[0] < -3.141592741012573 || v47[1] > 3.141592741012573 )
    {
      v100 = -1;
      v101 = -1;
      v102 = -1;
      v103 = -1;
      v104 = -1;
      v110 = sub_6641F3(this, a2, 542113793, (int)&v100, a3, (unsigned int)&v109);
      if ( v110 < 0 )
        goto LABEL_67;
      v110 = sub_6641F3(this, a2, 541065217, (int)&v101, &v100, (unsigned int)&v108);
      if ( v110 < 0 )
        goto LABEL_67;
      v110 = sub_6641F3(this, a2, 272629761, (int)&v102, &v101, 0x1400000000LL);
      if ( v110 < 0 )
        goto LABEL_67;
      HIDWORD(v45) = 4;
      LODWORD(v45) = &v106;
      v110 = sub_6641F3(this, a2, 542113793, (int)&v103, &v102, v45);
      if ( v110 < 0 )
        goto LABEL_67;
      v110 = sub_6641F3(this, a2, 541065217, (int)&v104, &v103, (unsigned int)&v107);
      if ( v110 < 0 )
        goto LABEL_67;
    }
    else
    {
      v104 = *a3;
    }
    v48 = -1;
    v49 = -1;
    v50 = -1;
    v51 = -1;
    v46[0] = v104;
    v46[1] = v104;
    v46[2] = v104;
    v46[3] = v104;
    v110 = sub_6641F3(this, a2, 1345323012, (int)&v48, v46, 0x1000000000LL);
    if ( v110 >= 0 )
    {
      if ( a5 && a6 )
        memset32(a5, v48, a6);
      if ( a4 && a6 )
        memset32(a4, v49, a6);
      goto LABEL_66;
    }
  }
  else
  {
    v16 = a4 != 0 ? a6 : 0;
    v36 = *(_DWORD *)(this[2] + 120);
    v59 = a5 != 0 ? a6 : 0;
    v109 = v16 + v59;
    v17 = sub_681AAA(v36, 0, 0, 0.1591549386630057);
    v37 = *(_DWORD *)(this[2] + 120);
    v108 = v17;
    v18 = sub_681AAA(v37, 0, 0, 0.25);
    v38 = *(_DWORD *)(this[2] + 120);
    v52 = v18;
    v19 = sub_681AAA(v38, 0, 0, 0.5);
    v39 = *(_DWORD *)(this[2] + 120);
    v53 = v19;
    v20 = sub_681AAA(v39, 0, 0, 6.283185482025146);
    v40 = *(_DWORD *)(this[2] + 120);
    v57 = v20;
    v21 = sub_681AAA(v40, 0, 0, -3.141592741012573);
    v41 = *(_DWORD *)(this[2] + 120);
    v58 = v21;
    v22 = sub_681AAA(v41, 0, 0, -0.0000002523985176899309);
    v42 = *(_DWORD *)(this[2] + 120);
    v56 = v22;
    v54 = sub_681AAA(v42, 0, 0, 0.0000247609);
    v23 = sub_681AAA(*(_DWORD *)(this[2] + 120), 0, 0, -0.0013888397);
    v43 = *(_DWORD *)(this[2] + 120);
    v55 = v23;
    v24 = sub_681AAA(v43, 0, 0, 0.0416666418);
    v44 = *(_DWORD *)(this[2] + 120);
    v71 = v24;
    v67 = sub_681AAA(v44, 0, 0, -0.4999999963);
    v25 = (char *)operator new(108 * (v16 + v59));
    Block = v25;
    if ( v25 )
    {
      v26 = 0;
      v27 = 4 * v109;
      do
      {
        (&v73)[v26++] = v25;
        v25 += v27;
      }
      while ( v26 < 0x1B );
      v28 = 0;
      while ( 1 )
      {
        v110 = sub_6624CC((&v73)[v28], v109);
        if ( v110 < 0 )
          break;
        v28 = v29 + 1;
        if ( v28 >= 0xF )
        {
          v113 = 0;
          if ( v109 )
          {
            v30 = v88;
            v110 = (int)&a3[-v16];
            v106 = (_BYTE *)a5 - (_BYTE *)a3;
            v107 = (_BYTE *)a4 - v88;
            v64 = v89 - (_DWORD)v88;
            v70 = v90 - (_DWORD)v88;
            v68 = v91 - (_DWORD)v88;
            v66 = v92 - (_DWORD)v88;
            v72 = v93 - (_DWORD)v88;
            v62 = v94 - (_DWORD)v88;
            v60 = v95 - (_DWORD)v88;
            v69 = v96 - (_DWORD)v88;
            v65 = v97 - (_DWORD)v88;
            v63 = v98 - (_DWORD)v88;
            v111 = (char *)a3 - v88;
            v61 = v99 - v88;
            do
            {
              if ( v113 >= v16 )
                v31 = *(_DWORD *)(v106 + v110);
              else
                v31 = *(_DWORD *)((char *)v30 + v107);
              v32 = v64;
              *v30 = v31;
              *(_DWORD *)((char *)v30 + v32) = v108;
              v33 = v52;
              if ( v113 >= v16 )
                v33 = v53;
              *(_DWORD *)((char *)v30 + v70) = v33;
              *(_DWORD *)((char *)v30 + v68) = v57;
              *(_DWORD *)((char *)v30 + v66) = v58;
              *(_DWORD *)((char *)v30 + v72) = v56;
              *(_DWORD *)((char *)v30 + v62) = v54;
              *(_DWORD *)((char *)v30 + v60) = v55;
              *(_DWORD *)((char *)v30 + v69) = v71;
              *(_DWORD *)((char *)v30 + v65) = v67;
              *(_DWORD *)((char *)v30 + v63) = this[8];
              if ( v113 >= v16 )
                v34 = *(_DWORD *)v110;
              else
                v34 = *(_DWORD *)((char *)v30 + v111);
              ++v113;
              v110 += 4;
              *(_DWORD *)((char *)v30++ + v61) = v34;
            }
            while ( v113 < v109 );
          }
          v112 = v109 & 0xFFFFF | 0x20500000;
          v109 &= 0xFFFFFu;
          v110 = sub_6641F3(this, a2, v112, (int)v73, v99, v89);
          if ( v110 >= 0 )
          {
            v114 = v109 | 0x20400000;
            v110 = sub_6641F3(this, a2, v109 | 0x20400000, (int)v74, v73, v90);
            if ( v110 >= 0 )
            {
              v110 = sub_6641F3(this, a2, v109 | 0x10400000, (int)v75, v74, 0x1400000000LL);
              if ( v110 >= 0 )
              {
                v110 = sub_6641F3(this, a2, v112, (int)v76, v75, v91 | 0x400000000LL);
                if ( v110 >= 0 )
                {
                  v110 = sub_6641F3(this, a2, v114, v77, v76, v92);
                  if ( v110 >= 0 )
                  {
                    v110 = sub_6641F3(this, a2, v112, (int)v78, (_DWORD *)v77, (unsigned int)v77 | 0x400000000LL);
                    if ( v110 >= 0 )
                    {
                      v110 = sub_6641F3(this, a2, v112, (int)v79, v78, v93);
                      if ( v110 >= 0 )
                      {
                        v110 = sub_6641F3(this, a2, v114, v80, v79, v94);
                        if ( v110 >= 0 )
                        {
                          v110 = sub_6641F3(this, a2, v112, (int)v81, v78, (unsigned int)v80);
                          if ( v110 >= 0 )
                          {
                            v110 = sub_6641F3(this, a2, v114, v82, v81, v95);
                            if ( v110 >= 0 )
                            {
                              v110 = sub_6641F3(this, a2, v112, (int)v83, v78, (unsigned int)v82);
                              if ( v110 >= 0 )
                              {
                                v110 = sub_6641F3(this, a2, v114, v84, v83, v96);
                                if ( v110 >= 0 )
                                {
                                  v110 = sub_6641F3(this, a2, v112, (int)v85, v78, (unsigned int)v84);
                                  if ( v110 >= 0 )
                                  {
                                    v110 = sub_6641F3(this, a2, v114, v86, v85, v97);
                                    if ( v110 >= 0 )
                                    {
                                      v110 = sub_6641F3(this, a2, v112, (int)v87, v78, (unsigned int)v86);
                                      if ( v110 >= 0 )
                                      {
                                        v110 = sub_6641F3(this, a2, v114, (int)v88, v87, v98 | 0x1000000000LL);
                                        if ( v110 >= 0 )
                                        {
                                          qmemcpy(a4, v88, 4 * v16);
                                          qmemcpy(a5, &v88[4 * v16], 4 * v59);
                                          goto LABEL_66;
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          break;
        }
      }
    }
    else
    {
      v110 = -2147024882;
    }
  }
LABEL_67:
  j__free(Block);
  return v110;
}
