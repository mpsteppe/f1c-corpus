int __thiscall sub_665ADF(_DWORD *this, unsigned int a2, _DWORD *a3, char *a4, int a5, int a6)
{
  bool v7; // zf
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // edi
  char *v15; // edx
  int v16; // edi
  unsigned int i; // eax
  unsigned int v18; // edx
  int v19; // edx
  int *v20; // eax
  int v21; // edx
  unsigned int v22; // ecx
  int v24; // [esp-Ch] [ebp-124h]
  int v25; // [esp-Ch] [ebp-124h]
  int v26; // [esp-Ch] [ebp-124h]
  __int64 v27; // [esp+0h] [ebp-118h]
  int v28; // [esp+14h] [ebp-104h]
  int v29; // [esp+18h] [ebp-100h]
  unsigned int v30; // [esp+1Ch] [ebp-FCh]
  int v31; // [esp+20h] [ebp-F8h]
  unsigned int v32; // [esp+24h] [ebp-F4h]
  unsigned int v33; // [esp+28h] [ebp-F0h]
  int v34; // [esp+2Ch] [ebp-ECh]
  unsigned int v35; // [esp+30h] [ebp-E8h]
  unsigned int v36; // [esp+34h] [ebp-E4h]
  int v37; // [esp+38h] [ebp-E0h]
  int v38; // [esp+3Ch] [ebp-DCh]
  int v39; // [esp+40h] [ebp-D8h]
  int v40; // [esp+44h] [ebp-D4h]
  int v41; // [esp+48h] [ebp-D0h]
  _DWORD *v42; // [esp+4Ch] [ebp-CCh]
  _DWORD *v43; // [esp+50h] [ebp-C8h]
  int v44; // [esp+54h] [ebp-C4h]
  int v45; // [esp+58h] [ebp-C0h]
  _DWORD *v46; // [esp+5Ch] [ebp-BCh]
  _DWORD *v47; // [esp+60h] [ebp-B8h]
  int v48; // [esp+64h] [ebp-B4h]
  _DWORD *v49; // [esp+68h] [ebp-B0h]
  int v50; // [esp+6Ch] [ebp-ACh]
  _DWORD *v51; // [esp+70h] [ebp-A8h]
  int v52; // [esp+74h] [ebp-A4h]
  _DWORD *v53; // [esp+78h] [ebp-A0h]
  int v54; // [esp+7Ch] [ebp-9Ch]
  _DWORD *v55; // [esp+80h] [ebp-98h]
  int v56; // [esp+84h] [ebp-94h]
  _DWORD *v57; // [esp+88h] [ebp-90h]
  _DWORD *v58; // [esp+8Ch] [ebp-8Ch]
  _DWORD *v59; // [esp+90h] [ebp-88h]
  _DWORD *v60; // [esp+94h] [ebp-84h]
  _DWORD *v61; // [esp+A4h] [ebp-74h]
  int v62; // [esp+A8h] [ebp-70h]
  _DWORD *v63; // [esp+ACh] [ebp-6Ch]
  _DWORD *v64; // [esp+B0h] [ebp-68h]
  _DWORD *v65; // [esp+B4h] [ebp-64h]
  int v66; // [esp+B8h] [ebp-60h]
  _DWORD *v67; // [esp+BCh] [ebp-5Ch]
  int v68; // [esp+C0h] [ebp-58h]
  int v69; // [esp+C4h] [ebp-54h]
  _DWORD *v70; // [esp+C8h] [ebp-50h]
  _DWORD *v71; // [esp+CCh] [ebp-4Ch]
  int v72; // [esp+D0h] [ebp-48h]
  int v73; // [esp+D4h] [ebp-44h]
  unsigned int v74; // [esp+D8h] [ebp-40h]
  int *v75; // [esp+DCh] [ebp-3Ch]
  unsigned int v76; // [esp+E0h] [ebp-38h]
  unsigned int v77; // [esp+E4h] [ebp-34h]
  unsigned int v78; // [esp+E8h] [ebp-30h]
  unsigned int v79; // [esp+ECh] [ebp-2Ch]
  unsigned int v80; // [esp+F0h] [ebp-28h]
  unsigned int v81; // [esp+F4h] [ebp-24h]
  char *v82; // [esp+F8h] [ebp-20h]
  void *Block; // [esp+FCh] [ebp-1Ch]
  int v84; // [esp+100h] [ebp-18h]
  unsigned int v85; // [esp+104h] [ebp-14h]
  int v86; // [esp+108h] [ebp-10h]
  int v87; // [esp+10Ch] [ebp-Ch]
  int v88; // [esp+110h] [ebp-8h]
  int v89; // [esp+114h] [ebp-4h]
  int v90; // [esp+130h] [ebp+18h]

  v7 = (*(_BYTE *)(this[2] + 109) & 2) == 0;
  Block = 0;
  if ( v7 )
  {
    v11 = sub_681AAA(*(_DWORD *)(this[2] + 120), 0, 0, 0.0208351);
    v24 = *(_DWORD *)(this[2] + 120);
    v87 = v11;
    v12 = sub_681AAA(v24, 0, 0, -0.085133);
    v25 = *(_DWORD *)(this[2] + 120);
    v88 = v12;
    v13 = sub_681AAA(v25, 0, 0, 0.180141);
    v26 = *(_DWORD *)(this[2] + 120);
    v89 = v13;
    v28 = sub_681AAA(v26, 0, 0, -0.3302995);
    v37 = sub_681AAA(*(_DWORD *)(this[2] + 120), 0, 0, 0.999866);
    v31 = sub_681AAA(*(_DWORD *)(this[2] + 120), 0, 0, -2.0);
    v29 = sub_681AAA(*(_DWORD *)(this[2] + 120), 0, 0, 1.570796370506287);
    v14 = a6;
    v34 = sub_681AAA(*(_DWORD *)(this[2] + 120), 0, 0, -3.141592741012573);
    v15 = (char *)operator new(192 * a6);
    Block = v15;
    if ( v15 )
    {
      for ( i = 0; i < 0x30; ++i )
      {
        *(&v38 + i) = (int)v15;
        v15 += 4 * a6;
      }
      v18 = 0;
      while ( 1 )
      {
        v16 = sub_6624CC((void *)*(&v38 + v18), v14);
        if ( v16 < 0 )
          break;
        v18 = v19 + 1;
        if ( v18 >= 0x27 )
        {
          if ( a6 )
          {
            v20 = v75;
            v30 = v77 - (_DWORD)v75;
            v35 = v78 - (_DWORD)v75;
            v33 = v79 - (_DWORD)v75;
            v36 = v80 - (_DWORD)v75;
            v32 = v81 - (_DWORD)v75;
            v21 = v76 - (_DWORD)v75;
            v22 = v74 - (_DWORD)v75;
            v84 = v82 - (char *)v75;
            v85 = v76 - (_DWORD)v75;
            v86 = a6;
            while ( 1 )
            {
              *(int *)((char *)v20 + v22) = v87;
              *v20 = v88;
              *(int *)((char *)v20 + v21) = v89;
              *(int *)((char *)v20 + v30) = v28;
              *(int *)((char *)v20 + v35) = v37;
              *(int *)((char *)v20 + v33) = v31;
              *(int *)((char *)v20 + v36) = v29;
              *(int *)((char *)v20 + v32) = v34;
              *(int *)((char *)v20++ + v84) = this[8];
              if ( !--v86 )
                break;
              v21 = v85;
            }
          }
          if ( !a4 )
            a4 = v82;
          v87 = a6 & 0xFFFFF | 0x10100000;
          v88 = a6 & 0xFFFFF;
          v16 = sub_6641F3(this, a2, v87, v38, a3, 0);
          if ( v16 >= 0 )
          {
            v86 = v88 | 0x20100000;
            v16 = sub_6641F3(this, a2, v88 | 0x20100000, v39, a3, (unsigned int)v38 | 0x400000000LL);
            if ( v16 >= 0 )
            {
              v16 = sub_6641F3(this, a2, v87, v40, a4, 0);
              if ( v16 >= 0 )
              {
                v16 = sub_6641F3(this, a2, v86, v41, a4, (unsigned int)v40 | 0x400000000LL);
                if ( v16 >= 0 )
                {
                  v84 = v88 | 0x20000000;
                  v16 = sub_6641F3(
                          this,
                          a2,
                          v88 | 0x20000000,
                          (int)v42,
                          (_DWORD *)v39,
                          (unsigned int)v41 | 0x400000000LL);
                  if ( v16 >= 0 )
                  {
                    v16 = sub_6641F3(this, a2, v86, (int)v43, (_DWORD *)v39, (unsigned int)v41 | 0x400000000LL);
                    if ( v16 >= 0 )
                    {
                      v16 = sub_6641F3(this, a2, v88 | 0x10300000, v44, v43, 0x400000000LL);
                      if ( v16 >= 0 )
                      {
                        v90 = v88 | 0x20500000;
                        v16 = sub_6641F3(this, a2, v88 | 0x20500000, v45, v42, (unsigned int)v44 | 0x1400000000LL);
                        if ( v16 >= 0 )
                        {
                          v16 = sub_6641F3(this, a2, v90, (int)v46, (_DWORD *)v45, (unsigned int)v45 | 0x1400000000LL);
                          if ( v16 >= 0 )
                          {
                            v16 = sub_6641F3(this, a2, v90, (int)v47, v46, v74);
                            if ( v16 >= 0 )
                            {
                              v89 = v88 | 0x20400000;
                              v16 = sub_6641F3(this, a2, v88 | 0x20400000, v48, v47, (unsigned int)v75);
                              if ( v16 >= 0 )
                              {
                                v16 = sub_6641F3(this, a2, v90, (int)v49, v46, (unsigned int)v48);
                                if ( v16 >= 0 )
                                {
                                  v16 = sub_6641F3(this, a2, v89, v50, v49, v76);
                                  if ( v16 >= 0 )
                                  {
                                    v16 = sub_6641F3(this, a2, v90, (int)v51, v46, (unsigned int)v50);
                                    if ( v16 >= 0 )
                                    {
                                      v16 = sub_6641F3(this, a2, v89, v52, v51, v77);
                                      if ( v16 >= 0 )
                                      {
                                        v16 = sub_6641F3(this, a2, v90, (int)v53, v46, (unsigned int)v52);
                                        if ( v16 >= 0 )
                                        {
                                          v16 = sub_6641F3(this, a2, v89, v54, v53, v78);
                                          if ( v16 >= 0 )
                                          {
                                            v16 = sub_6641F3(this, a2, v90, (int)v55, (_DWORD *)v45, (unsigned int)v54);
                                            if ( v16 >= 0 )
                                            {
                                              v85 = v88 | 0x20200000;
                                              v16 = sub_6641F3(
                                                      this,
                                                      a2,
                                                      v88 | 0x20200000,
                                                      v56,
                                                      (_DWORD *)v41,
                                                      (unsigned int)v39 | 0x1700000000LL);
                                              if ( v16 >= 0 )
                                              {
                                                v16 = sub_6641F3(this, a2, v90, (int)v57, v55, v79);
                                                if ( v16 >= 0 )
                                                {
                                                  v16 = sub_6641F3(this, a2, v89, (int)v58, v57, v80);
                                                  if ( v16 >= 0 )
                                                  {
                                                    v16 = sub_6641F3(this, a2, v90, (int)v59, v58, (unsigned int)v56);
                                                    if ( v16 >= 0 )
                                                    {
                                                      v16 = sub_6641F3(this, a2, v89, (int)v60, v59, (unsigned int)v55);
                                                      if ( v16 >= 0 )
                                                      {
                                                        v16 = sub_6641F3(
                                                                this,
                                                                a2,
                                                                v85,
                                                                (int)v61,
                                                                a4,
                                                                (unsigned int)v40 | 0x1700000000LL);
                                                        if ( v16 >= 0 )
                                                        {
                                                          v16 = sub_6641F3(this, a2, v90, v62, v61, v81);
                                                          if ( v16 >= 0 )
                                                          {
                                                            v16 = sub_6641F3(
                                                                    this,
                                                                    a2,
                                                                    v89,
                                                                    (int)v63,
                                                                    v60,
                                                                    (unsigned int)v62);
                                                            if ( v16 >= 0 )
                                                            {
                                                              v16 = sub_6641F3(
                                                                      this,
                                                                      a2,
                                                                      v84,
                                                                      (int)v64,
                                                                      a3,
                                                                      (unsigned int)a4);
                                                              if ( v16 >= 0 )
                                                              {
                                                                v16 = sub_6641F3(
                                                                        this,
                                                                        a2,
                                                                        v86,
                                                                        (int)v65,
                                                                        a3,
                                                                        (unsigned int)a4);
                                                                if ( v16 >= 0 )
                                                                {
                                                                  v16 = sub_6641F3(this, a2, v87, v66, v64, 0);
                                                                  if ( v16 >= 0 )
                                                                  {
                                                                    v16 = sub_6641F3(
                                                                            this,
                                                                            a2,
                                                                            v85,
                                                                            (int)v67,
                                                                            v64,
                                                                            (unsigned int)v66 | 0x1700000000LL);
                                                                    if ( v16 >= 0 )
                                                                    {
                                                                      v16 = sub_6641F3(this, a2, v87, v68, v65, 0);
                                                                      if ( v16 >= 0 )
                                                                      {
                                                                        v16 = sub_6641F3(
                                                                                this,
                                                                                a2,
                                                                                v88 | 0x20300000,
                                                                                v69,
                                                                                v65,
                                                                                (unsigned int)v68 | 0x1700000000LL);
                                                                        if ( v16 >= 0 )
                                                                        {
                                                                          v16 = sub_6641F3(
                                                                                  this,
                                                                                  a2,
                                                                                  v90,
                                                                                  (int)v70,
                                                                                  v67,
                                                                                  (unsigned int)v69 | 0x1700000000LL);
                                                                          if ( v16 >= 0 )
                                                                          {
                                                                            v16 = sub_6641F3(
                                                                                    this,
                                                                                    a2,
                                                                                    v89,
                                                                                    (int)v71,
                                                                                    v63,
                                                                                    (unsigned int)v63);
                                                                            if ( v16 >= 0 )
                                                                            {
                                                                              v16 = sub_6641F3(
                                                                                      this,
                                                                                      a2,
                                                                                      v87,
                                                                                      v72,
                                                                                      v71,
                                                                                      0);
                                                                              if ( v16 >= 0 )
                                                                              {
                                                                                v16 = sub_6641F3(
                                                                                        this,
                                                                                        a2,
                                                                                        v90,
                                                                                        v73,
                                                                                        v70,
                                                                                        (unsigned int)v72);
                                                                                if ( v16 >= 0 )
                                                                                {
                                                                                  v10 = sub_6641F3(
                                                                                          this,
                                                                                          a2,
                                                                                          v89,
                                                                                          a5,
                                                                                          v63,
                                                                                          (unsigned int)v73);
                                                                                  goto LABEL_57;
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
                }
              }
            }
          }
          break;
        }
        v14 = a6;
      }
    }
    else
    {
      v16 = -2147024882;
    }
  }
  else
  {
    v8 = a6 & 0xFFFFF;
    HIDWORD(v27) = 0;
    if ( a4 )
    {
      LODWORD(v27) = a4;
      v9 = v8 | 0x20600000;
    }
    else
    {
      LODWORD(v27) = 0;
      v9 = v8 | 0x10C00000;
    }
    v10 = sub_6641F3(this, a2, v9, a5, a3, v27);
LABEL_57:
    v16 = v10;
    if ( v10 >= 0 )
      v16 = 0;
  }
  j__free(Block);
  return v16;
}
