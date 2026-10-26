int __thiscall sub_646667(int *this, int a2, unsigned int a3)
{
  unsigned int v3; // kr00_4
  __int32 v4; // edi
  unsigned int v5; // edi
  unsigned int *v8; // ebx
  unsigned int v9; // eax
  bool v10; // cf
  __int16 v11; // ax
  int v12; // eax
  unsigned int v13; // edi
  bool v14; // zf
  unsigned __int16 v15; // dx
  int v16; // eax
  unsigned int v17; // ecx
  unsigned int v18; // eax
  int *v19; // edx
  int *v20; // eax
  unsigned int v21; // edi
  unsigned int v22; // eax
  int v23; // edi
  void *v24; // eax
  char *v25; // eax
  unsigned int v26; // ecx
  int v27; // edx
  char v28; // bl
  int v29; // eax
  unsigned int v30; // eax
  unsigned int v31; // edx
  unsigned int v32; // ecx
  unsigned int v33; // edx
  unsigned int v34; // eax
  unsigned int v35; // eax
  int v36; // edi
  unsigned int v37; // ecx
  unsigned int v38; // eax
  unsigned int v39; // ecx
  unsigned int v40; // ecx
  char *v41; // edi
  int v42; // esi
  unsigned __int8 *v43; // eax
  bool v44; // sf
  char *v45; // edx
  unsigned int v46; // ecx
  _BYTE *v47; // edi
  unsigned __int8 v48; // cl
  int v49; // esi
  int v50; // ebx
  unsigned int v51; // ecx
  unsigned int v52; // ecx
  int v53; // ecx
  int v54; // ebx
  int v55; // ecx
  _BYTE *v56; // esi
  unsigned __int8 v57; // cl
  unsigned int v58; // ecx
  int v59; // ecx
  int v60; // ecx
  unsigned __int8 v61; // si
  unsigned int v62; // ecx
  int v63; // eax
  __int16 v64; // bx
  unsigned int j; // ebx
  unsigned int v66; // ecx
  const void *v67; // esi
  char *v68; // edi
  unsigned int k; // esi
  unsigned int *v70; // ecx
  int v71; // ebx
  __int32 v72; // ebx
  unsigned __int16 *v73; // edi
  int v74; // ecx
  int v75; // ecx
  unsigned int m; // esi
  double v77; // st7
  __int32 v78[8]; // [esp+0h] [ebp-A4h] BYREF
  _DWORD v79[3]; // [esp+20h] [ebp-84h] BYREF
  __int16 v80; // [esp+2Ch] [ebp-78h]
  __int16 v81; // [esp+2Eh] [ebp-76h]
  int v82; // [esp+30h] [ebp-74h]
  int v83; // [esp+34h] [ebp-70h]
  int v84; // [esp+38h] [ebp-6Ch]
  int v85; // [esp+3Ch] [ebp-68h]
  int v86; // [esp+40h] [ebp-64h]
  int v87; // [esp+44h] [ebp-60h]
  float v88[4]; // [esp+48h] [ebp-5Ch]
  int v89; // [esp+58h] [ebp-4Ch] BYREF
  int v90; // [esp+5Ch] [ebp-48h]
  int v91; // [esp+60h] [ebp-44h]
  unsigned int v92; // [esp+64h] [ebp-40h]
  unsigned int v93; // [esp+68h] [ebp-3Ch]
  unsigned __int8 *v94; // [esp+6Ch] [ebp-38h]
  unsigned int *v95; // [esp+70h] [ebp-34h]
  int *v96; // [esp+74h] [ebp-30h]
  int v97; // [esp+78h] [ebp-2Ch]
  unsigned int v98; // [esp+7Ch] [ebp-28h]
  unsigned int v99; // [esp+80h] [ebp-24h]
  unsigned int v100; // [esp+84h] [ebp-20h]
  unsigned int v101; // [esp+88h] [ebp-1Ch]
  char *v102; // [esp+8Ch] [ebp-18h]
  unsigned int v103; // [esp+90h] [ebp-14h]
  int *v104; // [esp+94h] [ebp-10h]
  int *v105; // [esp+98h] [ebp-Ch]
  int v106; // [esp+9Ch] [ebp-8h]
  int v107; // [esp+A0h] [ebp-4h]
  unsigned int v108; // [esp+ACh] [ebp+8h]
  unsigned int v109; // [esp+B0h] [ebp+Ch]
  unsigned int i; // [esp+B0h] [ebp+Ch]

  if ( a3 < 4 )
    return -2147467259;
  v8 = (unsigned int *)a2;
  v9 = *(_DWORD *)a2;
  v10 = a3 < *(_DWORD *)a2;
  v95 = (unsigned int *)a2;
  if ( v10 )
    return -2147467259;
  if ( v9 == 12 )
  {
    v79[1] = *(__int16 *)(a2 + 4);
    v79[2] = *(__int16 *)(a2 + 6);
    v80 = *(_WORD *)(a2 + 8);
    v11 = *(_WORD *)(a2 + 10);
    v8 = v79;
    v79[0] = 12;
    v81 = v11;
    v82 = 0;
    v83 = 0;
    v84 = 0;
    v85 = 0;
    v86 = 0;
    v87 = 0;
    v95 = v79;
  }
  else if ( v9 < 0x28 )
  {
    return -2147467259;
  }
  v101 = v8[1];
  v12 = v8[2];
  if ( v12 <= 0 )
    v12 = -v12;
  v13 = *v8;
  v14 = *v8 == 12;
  v15 = *((_WORD *)v8 + 7);
  v97 = v12;
  v16 = v8[8];
  v106 = !v14 + 3;
  if ( v15 <= 8u && !v16 )
    v16 = 1 << v15;
  v17 = v13 + v16 * v106;
  v100 = v17;
  if ( v17 > a3 || *((_WORD *)v8 + 6) != 1 )
    return -2147467259;
  v18 = v8[4];
  if ( v18 <= 2 )
  {
    v98 = v15;
    if ( v15 == 1 || v15 == 4 || v15 == 8 )
    {
      v107 = 41;
      goto LABEL_105;
    }
    if ( v15 != 16 )
    {
      if ( v15 != 24 )
      {
        if ( v15 == 32 )
        {
LABEL_28:
          v107 = 22;
          goto LABEL_105;
        }
        return -2147467259;
      }
LABEL_62:
      v107 = 20;
      goto LABEL_105;
    }
LABEL_76:
    v107 = 24;
    goto LABEL_105;
  }
  if ( v18 != 3 || v13 < 0x34 )
    return -2147467259;
  v19 = (int *)v8[12];
  v104 = (int *)v8[11];
  v20 = (int *)v8[10];
  v96 = v19;
  v105 = v20;
  if ( v13 < 0x38 )
  {
    v99 = 0;
    v21 = 0;
  }
  else
  {
    v21 = v8[13];
    v99 = v21;
  }
  v22 = *((unsigned __int16 *)v8 + 7);
  v107 = 116;
  v98 = v22;
  switch ( v22 )
  {
    case 0x10u:
      if ( v19 == (int *)255 )
      {
        if ( v104 == (int *)255 && v105 == (int *)255 && v21 == 65280 )
          v107 = 51;
        goto LABEL_105;
      }
      if ( v19 != (int *)31 )
      {
        if ( v19 == (int *)15 )
        {
          if ( v104 == (int *)240 && v105 == (int *)3840 )
          {
            if ( v21 == 61440 )
            {
              v107 = 26;
            }
            else if ( !v21 )
            {
              v107 = 30;
            }
          }
        }
        else if ( v19 == (int *)3 )
        {
          if ( v104 == (int *)28 && v105 == (int *)224 && v21 == 65280 )
            v107 = 29;
        }
        else if ( v19 == (int *)0xFFFF && v104 == (int *)0xFFFF && v105 == (int *)0xFFFF && !v21 )
        {
          v107 = 81;
        }
        goto LABEL_105;
      }
      if ( v104 == (int *)2016 )
      {
        if ( v105 == (int *)63488 && !v21 )
          v107 = 23;
        goto LABEL_105;
      }
      if ( v104 != (int *)992 || v105 != (int *)31744 )
        goto LABEL_105;
      if ( v21 )
      {
        if ( v21 == 0x8000 )
          v107 = 25;
        goto LABEL_105;
      }
      goto LABEL_76;
    case 0x18u:
      if ( v19 != (int *)255 || v104 != (int *)65280 || v105 != dword_FF0000 || v21 )
        goto LABEL_105;
      goto LABEL_62;
    case 0x20u:
      if ( v19 != (int *)255 )
      {
        if ( v19 == (int *)1072693248 )
        {
          if ( v104 == (int *)1047552 && v105 == (int *)1023 && v99 == -1073741824 )
            v107 = 31;
        }
        else if ( v19 == dword_FF0000 )
        {
          if ( v104 == (int *)65280 && v105 == (int *)255 )
          {
            if ( v99 == -16777216 )
            {
              v107 = 32;
            }
            else if ( !v99 )
            {
              v107 = 33;
            }
          }
        }
        else if ( v19 )
        {
          if ( v19 == (int *)1023 )
          {
            if ( v104 == (int *)1047552 && v105 == (int *)1072693248 && v99 == -1073741824 )
              v107 = 35;
          }
          else if ( v19 == (int *)65280 && v104 == dword_FF0000 && v105 == (int *)-16777216 && !v99 )
          {
            v107 = 22;
            v100 = v17 + 1;
          }
        }
        else if ( v104 == (int *)-65536 && v105 == (int *)0xFFFF && !v99 )
        {
          v107 = 34;
        }
        goto LABEL_105;
      }
      if ( v104 == (int *)65280 && v105 == dword_FF0000 )
      {
        if ( v21 )
        {
          if ( v21 == -16777216 )
            v107 = 21;
          goto LABEL_105;
        }
        goto LABEL_28;
      }
LABEL_105:
      if ( this[16] && v107 == 41 )
      {
        v23 = v8[8];
        if ( !v23 )
          v23 = 1 << v98;
        v78[0] = v23;
        v3 = __readeflags();
        v4 = dword_16C6DA8 - dword_16CF665;
        __writeeflags(v3);
        v5 = _InterlockedExchange(v78, v4);
        this[15] = 1;
        v24 = operator new(v78[0]);
        this[2] = (int)v24;
        if ( !v24 )
          return -2147024882;
        v25 = (char *)(a2 + *v8);
        v103 = 0;
        if ( v5 )
        {
          do
          {
            v26 = 4 * v103;
            *(_BYTE *)(v26 + this[2]) = v25[2];
            *(_BYTE *)(v26 + this[2] + 1) = v25[1];
            v27 = this[2];
            v28 = *v25;
            v25 += v106;
            v10 = ++v103 < v5;
            *(_BYTE *)(v26 + v27 + 2) = v28;
            *(_BYTE *)(v26 + this[2] + 3) = -1;
          }
          while ( v10 );
          v8 = v95;
        }
        while ( v5 < 0x100 )
        {
          v29 = 4 * v5;
          *(_BYTE *)(v29 + this[2]) = -1;
          *(_BYTE *)(v29 + this[2] + 1) = -1;
          *(_BYTE *)(v29 + this[2] + 2) = -1;
          *(_BYTE *)(v29 + this[2] + 3) = -1;
          ++v5;
        }
      }
      if ( *((_WORD *)v8 + 7) == 1 )
      {
        v103 = v101;
        v30 = (v101 + 7) >> 3;
      }
      else if ( *((_WORD *)v8 + 7) == 4 )
      {
        v103 = v101;
        v30 = (v101 + 1) >> 1;
      }
      else
      {
        v30 = v101 * (*((unsigned __int16 *)v8 + 7) >> 3);
        v103 = v30;
      }
      if ( v107 == 116 )
        v103 = 16 * v101;
      v31 = v8[4];
      v32 = (v30 + 3) & 0xFFFFFFFC;
      v98 = v32;
      if ( v31 && v31 != 3 )
      {
        v33 = v97;
      }
      else
      {
        v33 = v97;
        if ( v100 + v30 + v32 * (v97 - 1) > a3 )
          return -2147467259;
      }
      if ( !v8[4] && v107 == 22 )
      {
        v102 = 0;
        if ( v33 )
        {
          v106 = a2 + v100;
          do
          {
            v34 = 0;
            if ( v101 )
            {
              while ( !*(_BYTE *)(v106 + 4 * v34 + 3) )
              {
                if ( ++v34 >= v101 )
                  goto LABEL_138;
              }
              v107 = 21;
LABEL_138:
              if ( v34 < v101 )
                break;
            }
            ++v102;
            v106 += v32;
          }
          while ( (unsigned int)v102 < v33 );
        }
      }
      v35 = v103;
      v36 = v107;
      this[13] = 0;
      v37 = v101;
      v38 = (v35 + 3) & 0xFFFFFFFC;
      v14 = this[16] == 0;
      *this = v36;
      this[12] = v38;
      this[3] = v37;
      this[4] = v33;
      this[5] = 1;
      if ( v14 )
        return 0;
      v39 = v8[4];
      if ( (!v39 || v39 == 3) && (v8[2] & 0x80000000) != 0 && *((_WORD *)v8 + 7) >= 8u && v36 != 116 )
      {
        v40 = v100;
        this[14] = 0;
        this[1] = a2 + v40;
        return 0;
      }
      v78[0] = v97 * v38;
      this[14] = 1;
      v41 = (char *)operator new(v78[0]);
      v102 = v41;
      this[1] = (int)v41;
      if ( !v41 )
        return -2147024882;
      v42 = this[12];
      v43 = (unsigned __int8 *)(a2 + v100);
      v44 = (v8[2] & 0x80000000) != 0;
      v94 = (unsigned __int8 *)(a2 + v100);
      v93 = a2 + v100;
      v100 = a3 + a2;
      if ( v44 )
      {
        v106 = v42;
        v45 = v41;
      }
      else
      {
        v106 = -v42;
        v45 = &v41[v42 * (v97 - 1)];
      }
      v46 = v8[4];
      v108 = (unsigned int)&v41[v97 * v42];
      v109 = (unsigned int)v45;
      if ( v46 == 2 )
      {
        if ( v45 >= v41 )
        {
          while ( v109 < v108 )
          {
            if ( (unsigned int)v43 < v93 )
              return -2147467259;
            v47 = v43 + 1;
            if ( (unsigned int)(v43 + 1) >= v100 )
              return -2147467259;
            v48 = *v43;
            if ( *v43 )
            {
              if ( v45 < v102 || (unsigned int)&v45[v48] > v108 )
                return -2147467259;
              v54 = 0;
              if ( v48 )
              {
                do
                {
                  if ( (v54 & 1) != 0 )
                    LOBYTE(v55) = *v47 & 0xF;
                  else
                    v55 = (unsigned __int8)*v47 >> 4;
                  v45[v54++] = v55;
                }
                while ( v54 < *v43 );
              }
              v45 += *v43;
            }
            else
            {
              v49 = (unsigned __int8)*v47;
              if ( *v47 )
              {
                if ( *v47 == 1 )
                {
                  v109 = v108;
                }
                else if ( *v47 == 2 )
                {
                  if ( (unsigned int)(v43 + 3) >= v100 )
                    return -2147467259;
                  v53 = v106 * v43[3];
                  v43 += 2;
                  v45 += *v43 + v53;
                }
                else
                {
                  if ( v45 < v102
                    || (unsigned int)&v45[v49] > v108
                    || *v47 && (unsigned int)&v43[((v49 - 1) >> 1) + 2] >= v100 )
                  {
                    return -2147467259;
                  }
                  v50 = 0;
                  if ( *v47 )
                  {
                    do
                    {
                      v51 = v43[(v50 >> 1) + 2];
                      if ( (v50 & 1) != 0 )
                        LOBYTE(v51) = v51 & 0xF;
                      else
                        v51 >>= 4;
                      v45[v50++] = v51;
                    }
                    while ( v50 < (unsigned __int8)*v47 );
                  }
                  v52 = (unsigned __int8)*v47;
                  v45 += v52;
                  v43 += ((v52 >> 1) + 1) & 0xFFFFFFFE;
                }
              }
              else
              {
                v45 = (char *)(v106 + v109);
                v109 += v106;
              }
            }
            v43 += 2;
            if ( v109 < (unsigned int)v102 )
              return 0;
          }
        }
        return 0;
      }
      if ( v46 == 1 )
      {
        if ( v45 < v41 )
          return 0;
        while ( 1 )
        {
          if ( v109 >= v108 )
            return 0;
          if ( (unsigned int)v43 < v93 )
            return -2147467259;
          v56 = v43 + 1;
          if ( (unsigned int)(v43 + 1) >= v100 )
            return -2147467259;
          v57 = *v43;
          if ( *v43 )
            break;
          v58 = (unsigned __int8)*v56;
          if ( v58 )
          {
            if ( v58 != 1 )
            {
              if ( v58 == 2 )
              {
                if ( (unsigned int)(v43 + 3) >= v100 )
                  return -2147467259;
                v60 = v106 * v43[3];
                v43 += 2;
                v45 += *v43 + v60;
                goto LABEL_206;
              }
              if ( v45 < v41 || (unsigned int)&v45[v58] > v108 || (unsigned int)&v43[v58 + 2] > v100 )
                return -2147467259;
              HIWORD(v8) = HIWORD(v58);
              qmemcpy(v45, v43 + 2, v58);
              v59 = v43[1];
              v45 += v59;
              v43 += (v59 + 1) & 0xFFFFFFFE;
              goto LABEL_205;
            }
            v109 = v108;
          }
          else
          {
            v45 = (char *)(v106 + v109);
            v109 += v106;
          }
LABEL_206:
          v43 += 2;
          v94 = v43;
          if ( v109 < (unsigned int)v41 )
            return 0;
        }
        if ( v45 < v41 || (unsigned int)&v45[v57] > v108 )
          return -2147467259;
        LOBYTE(v8) = *v56;
        BYTE1(v8) = *v56;
        v61 = *v43;
        v62 = v57 >> 2;
        v63 = (_DWORD)v8 << 16;
        LOWORD(v63) = (_WORD)v8;
        memset32(v45, v63, v62);
        memset(&v45[4 * v62], (char)v8, v61 & 3);
        v43 = v94;
        v45 += *v94;
LABEL_205:
        v41 = v102;
        goto LABEL_206;
      }
      v64 = *((_WORD *)v8 + 7);
      if ( v64 == 1 )
      {
        if ( v45 >= v41 )
        {
          do
          {
            if ( (unsigned int)v45 >= v108 )
              break;
            for ( i = 0; i < v101; ++i )
              v45[i] = (v43[i >> 3] >> (7 - (i & 7))) & 1;
            v45 += v106;
            v43 += v98;
          }
          while ( v45 >= v102 );
        }
        return 0;
      }
      if ( v64 == 4 )
      {
        if ( v45 >= v41 )
        {
          do
          {
            if ( (unsigned int)v45 >= v108 )
              break;
            for ( j = 0; j < v101; ++j )
            {
              v66 = v43[j >> 1];
              if ( (j & 1) != 0 )
                LOBYTE(v66) = v66 & 0xF;
              else
                v66 >>= 4;
              v45[j] = v66;
            }
            v45 += v106;
            v43 += v98;
          }
          while ( v45 >= v102 );
        }
        return 0;
      }
      if ( v107 != 116 )
      {
        if ( v45 >= v41 )
        {
          do
          {
            if ( (unsigned int)v45 >= v108 )
              break;
            v67 = v43;
            v43 += v98;
            v68 = v45;
            v45 += v106;
            qmemcpy(v68, v67, v103);
          }
          while ( v45 >= v102 );
        }
        return 0;
      }
      v89 = (int)v105;
      v90 = (int)v104;
      v91 = (int)v96;
      v92 = v99;
      for ( k = 0; k < 4; ++k )
      {
        v70 = (unsigned int *)((char *)&v89 + k * 4);
        v71 = *(int *)((char *)&v89 + k * 4);
        v78[k + 4] = 0;
        if ( v71 )
        {
          if ( (v71 & 1) == 0 )
          {
            v72 = 0;
            do
            {
              *v70 >>= 1;
              ++v72;
            }
            while ( (*v70 & 1) == 0 );
            v78[k + 4] = v72;
          }
          v109 = *v70;
          v88[k] = 1.0 / (double)*v70;
        }
      }
      if ( !v105 && !v104 && !v96 )
      {
        v88[2] = 0.0;
        v91 = 1;
        v90 = 1;
        v88[1] = 0.0;
        v89 = 1;
        v88[0] = 0.0;
      }
      while ( 1 )
      {
        if ( v45 < v102 || (unsigned int)v45 >= v108 )
          return 0;
        v103 = (unsigned int)v45;
        v73 = (unsigned __int16 *)v43;
        if ( v101 )
          break;
LABEL_258:
        v45 += v106;
        v43 += v98;
      }
      v96 = (int *)v101;
      while ( 1 )
      {
        v74 = *((unsigned __int16 *)v95 + 7);
        switch ( v74 )
        {
          case 16:
            v75 = *v73++;
            break;
          case 24:
            v75 = *(unsigned __int8 *)v73 | (*(unsigned __int16 *)((char *)v73 + 1) << 8);
            v73 = (unsigned __int16 *)((char *)v73 + 3);
            break;
          case 32:
            v75 = *(_DWORD *)v73;
            v73 += 2;
            break;
          default:
            goto LABEL_252;
        }
        v109 = v75;
LABEL_252:
        for ( m = 0; m < 4; ++m )
        {
          if ( *(int *)((char *)&v89 + m * 4) )
          {
            v94 = (unsigned __int8 *)(*(int *)((char *)&v89 + m * 4) & (v109 >> v78[m + 4]));
            v77 = (double)(int)v94 * v88[m];
          }
          else
          {
            v77 = 1.0;
          }
          *(float *)(v103 + m * 4) = v77;
        }
        v103 += 16;
        v96 = (int *)((char *)v96 - 1);
        if ( !v96 )
          goto LABEL_258;
      }
  }
  return -2147467259;
}
