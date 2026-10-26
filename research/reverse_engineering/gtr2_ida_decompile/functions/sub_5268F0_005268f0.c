char __thiscall sub_5268F0(int this, int *a2)
{
  bool v4; // zf
  const char *v5; // edi
  const char *v6; // eax
  int v7; // edx
  int v8; // edx
  int v9; // edx
  int v10; // eax
  int v11; // edx
  bool v12; // c3
  int v13; // eax
  int *v14; // edi
  _BYTE *v15; // ebp
  int v16; // eax
  _DWORD *v17; // edi
  _DWORD *v18; // eax
  int v19; // ebp
  float v20; // eax
  _DWORD *v21; // ebp
  int v22; // edx
  _DWORD *v23; // eax
  void *v24; // edi
  _DWORD *v25; // eax
  _DWORD *v26; // edi
  _DWORD *v27; // ebp
  int v28; // eax
  char *v29; // eax
  char *v30; // edi
  int i; // ebx
  int v32; // edi
  int v33; // ecx
  _DWORD *v34; // ebp
  int *v35; // eax
  int v36; // ebx
  int v37; // edi
  int v38; // eax
  int v39; // edi
  int *v40; // eax
  int v41; // edi
  int v42; // eax
  _WORD *v43; // ebx
  _DWORD *v44; // eax
  _DWORD *v45; // ecx
  int v46; // edx
  int v47; // edi
  int v48; // eax
  float v49; // edx
  int v50; // eax
  float **v51; // ecx
  float *v52; // ecx
  double v53; // st7
  float v54; // [esp+94h] [ebp-4B4h] BYREF
  unsigned __int8 v55; // [esp+9Bh] [ebp-4ADh] BYREF
  unsigned __int8 v56; // [esp+9Ch] [ebp-4ACh] BYREF
  char v57; // [esp+9Dh] [ebp-4ABh]
  unsigned __int8 v58; // [esp+9Eh] [ebp-4AAh] BYREF
  unsigned __int8 v59; // [esp+9Fh] [ebp-4A9h] BYREF
  int v60; // [esp+A0h] [ebp-4A8h]
  int v61; // [esp+A4h] [ebp-4A4h] BYREF
  int v62; // [esp+A8h] [ebp-4A0h] BYREF
  int v63; // [esp+ACh] [ebp-49Ch] BYREF
  int v64[5]; // [esp+B0h] [ebp-498h] BYREF
  int v65[13]; // [esp+C4h] [ebp-484h] BYREF
  char v66[256]; // [esp+F8h] [ebp-450h] BYREF
  unsigned int v67[212]; // [esp+1F8h] [ebp-350h] BYREF

  v60 = this;
  v57 = 1;
  v54 = sub_520EB0((_DWORD *)this, *(float *)&a2);
  if ( v54 == 0.0 )
  {
    v57 = 0;
    return 0;
  }
  else
  {
    (*(void (__thiscall **)(int *, int *, int))(*a2 + 28))(a2, &v61, 4);
    (*(void (__thiscall **)(int *, char *, int))(*a2 + 28))(a2, v66, v61);
    v4 = *(_DWORD *)(this + 2892916) == 1;
    v66[v61] = 0;
    if ( !v4 )
      goto LABEL_13;
    v5 = dword_B6F68C;
    if ( !dword_B6F68C )
      v5 = WindowName;
    v6 = &v5[strlen(v5)];
    if ( v6 > v5 )
    {
      while ( *v6 != 92 )
      {
        if ( --v6 <= v5 )
          goto LABEL_11;
      }
      ++v6;
    }
LABEL_11:
    if ( !strcmp(v66, v6) )
    {
LABEL_13:
      sub_615860(v66);
      (*(void (__thiscall **)(int *, int *, int))(*a2 + 28))(a2, &v61, 4);
      (*(void (__thiscall **)(int *, char *, int))(*a2 + 28))(a2, v66, v61);
      v66[v61] = 0;
      sub_615860(v66);
      v7 = *a2;
      v59 = 0;
      (*(void (__thiscall **)(int *, unsigned __int8 *, int))(v7 + 28))(a2, &v59, 1);
      *(_DWORD *)(this + 2892816) = v59;
      v8 = *a2;
      v56 = 0;
      (*(void (__thiscall **)(int *, unsigned __int8 *, int))(v8 + 28))(a2, &v56, 1);
      *(_DWORD *)(this + 2892820) = v56;
      v9 = *a2;
      v63 = 0;
      (*(void (__thiscall **)(int *, int *, int))(v9 + 28))(a2, &v63, 4);
      v10 = *(_DWORD *)(this + 2892916);
      *(_DWORD *)(this + 2892824) = v63;
      if ( v10 || v54 < (double)flt_9034B8 )
      {
        *(_DWORD *)(this + 2892828) = 1;
      }
      else
      {
        v11 = *a2;
        v58 = 0;
        (*(void (__thiscall **)(int *, unsigned __int8 *, int))(v11 + 28))(a2, &v58, 1);
        v12 = v54 == flt_9034BC;
        *(_DWORD *)(this + 2892828) = v58;
        if ( v12 )
        {
          (*(void (__thiscall **)(int *, int *, int))(*a2 + 28))(a2, v64, 72);
          sub_4762A0(dword_B70604, v65);
          (*(void (__thiscall **)(int *, int))(*a2 + 56))(a2, v64[0] != v65[4] ? 288 : 252);
        }
        else if ( v54 >= (double)flt_9034C0 )
        {
          (*(void (__thiscall **)(int *, float *, int))(*a2 + 28))(a2, &v54, 4);
          sub_4762A0(dword_B70604, (int *)&v54);
        }
      }
      sub_526220();
      (*(void (__thiscall **)(int *, int *, int))(*a2 + 28))(a2, &v62, 4);
      v54 = 0.0;
      if ( v62 > 0 )
      {
        do
        {
          v13 = *(_DWORD *)(this + 16);
          v14 = (int *)(this + 16);
          v15 = 0;
          *(_DWORD *)(this + 24) = v13;
          if ( v13 )
          {
            v15 = *(_BYTE **)v13;
            *(_BYTE *)(v13 + 8) = 0;
            if ( !(unsigned __int8)sub_525820() )
              v15 = 0;
          }
          if ( !v15 )
          {
            sub_525080();
            v16 = *v14;
            v4 = *v14 == 0;
            *(_DWORD *)(this + 24) = *(_DWORD *)(this + 16);
            if ( !v4 )
            {
              v15 = *(_BYTE **)v16;
              *(_BYTE *)(v16 + 8) = 0;
              if ( !(unsigned __int8)sub_525820() )
                v15 = 0;
            }
          }
          sub_5209D0(v15, (int)a2);
          if ( *(_DWORD *)(this + 2892916) )
            *v15 = *(_BYTE *)(this + 2892924);
          v17 = (_DWORD *)(this + 16 * ((unsigned __int8)*v15 + 4));
          v18 = operator new(0xCu);
          if ( v18 )
          {
            *v18 = v15;
            v18[1] = 0;
            *((_BYTE *)v18 + 8) = 0;
          }
          else
          {
            v18 = 0;
          }
          if ( *v17 )
          {
            *(_DWORD *)(v17[1] + 4) = v18;
          }
          else
          {
            *v17 = v18;
            v17[2] = v18;
          }
          v19 = v17[3];
          v17[1] = v18;
          v20 = v54;
          v17[3] = v19 + 1;
          LODWORD(v54) = LODWORD(v20) + 1;
        }
        while ( LODWORD(v20) + 1 < v62 );
      }
      v21 = (_DWORD *)(this + 1744);
      sub_525950((int *)(this + 1744));
      v22 = *a2;
      v55 = 0;
      (*(void (__thiscall **)(int *, unsigned __int8 *, int))(v22 + 28))(a2, &v55, 1);
      v54 = 0.0;
      if ( v55 )
      {
        do
        {
          v23 = operator new(0xCu);
          if ( v23 )
          {
            v23[1] = 0;
            v23[2] = -1;
            v24 = v23;
          }
          else
          {
            v24 = 0;
          }
          sub_520850(v24, a2);
          if ( v24 )
          {
            v25 = operator new(0x10u);
            if ( v25 )
            {
              *v25 = v24;
              v25[1] = 0;
              v25[2] = 0;
              *((_BYTE *)v25 + 12) = 1;
            }
            else
            {
              v25 = 0;
            }
            if ( *v21 )
            {
              *(_DWORD *)(*(_DWORD *)(this + 1748) + 4) = v25;
              v25[2] = *(_DWORD *)(this + 1748);
            }
            else
            {
              *v21 = v25;
              *(_DWORD *)(this + 1752) = v25;
            }
            *(_DWORD *)(this + 1748) = v25;
            ++*(_DWORD *)(this + 1756);
          }
          ++LODWORD(v54);
        }
        while ( SLODWORD(v54) < v55 );
      }
      (*(void (__thiscall **)(int *, int, int))(*a2 + 28))(a2, this + 2892832, 4);
      (*(void (__thiscall **)(int *, int, int))(*a2 + 28))(a2, this + 2892836, 4);
      (*(void (__thiscall **)(int *, int, int))(*a2 + 28))(a2, this + 2892840, 4);
      if ( *(_DWORD *)(this + 2892916) == 1 )
      {
        v26 = (_DWORD *)v60;
        sub_520B80((char *)(v60 + 2892996), (int)a2);
        v27 = v26 + 723232;
        (*(void (__thiscall **)(int *, _DWORD *, int))(*a2 + 28))(a2, v26 + 723232, 4);
        v28 = v26[723232];
        if ( v28 )
        {
          v26[723233] = v28;
          v29 = (char *)operator new(24 * v28);
          v26[723234] = v29;
          v30 = v29;
          for ( i = 0; i < *v27; v30 += 24 )
          {
            (*(void (__thiscall **)(int *, char *, int))(*a2 + 28))(a2, v30, 12);
            (*(void (__thiscall **)(int *, char *, int))(*a2 + 28))(a2, v30 + 12, 4);
            (*(void (__thiscall **)(int *, char *, int))(*a2 + 28))(a2, v30 + 16, 4);
            (*(void (__thiscall **)(int *, char *, int))(*a2 + 28))(a2, v30 + 20, 4);
            ++i;
          }
        }
        else
        {
          v26[723233] = 0;
          v26[723234] = 0;
        }
      }
      v32 = v60;
      sub_526340();
      v33 = *(_DWORD *)(v32 + 2892832);
      v54 = 0.0;
      if ( v33 > 0 )
      {
        v34 = (_DWORD *)(v32 + 32);
        do
        {
          v35 = (int *)v34[4];
          v36 = 0;
          v34[6] = v35;
          if ( v35 )
          {
            *((_BYTE *)v35 + 8) = 0;
            v36 = *v35;
            if ( *v35 && (v37 = v34[4], v38 = 0, v37) )
            {
              while ( *(_DWORD *)v37 != v36 )
              {
                v38 = v37;
                v37 = *(_DWORD *)(v37 + 4);
                if ( !v37 )
                  goto LABEL_63;
              }
              if ( v37 == v34[6] )
                v34[6] = *(_DWORD *)(v37 + 4);
              if ( v38 )
                *(_DWORD *)(v38 + 4) = *(_DWORD *)(v37 + 4);
              else
                v34[4] = *(_DWORD *)(v37 + 4);
              if ( v34[5] == v37 )
                v34[5] = v38;
              --v34[7];
              if ( *(_BYTE *)(v37 + 8) )
                j__free(*(void **)v37);
              j__free((void *)v37);
            }
            else
            {
LABEL_63:
              v36 = 0;
            }
          }
          v39 = v36;
          if ( !v36 )
          {
            sub_525A60();
            v40 = (int *)v34[4];
            v34[6] = v40;
            if ( v40 )
            {
              *((_BYTE *)v40 + 8) = 0;
              v36 = *v40;
              if ( *v40 && (v41 = v34[4], v42 = 0, v41) )
              {
                while ( *(_DWORD *)v41 != v36 )
                {
                  v42 = v41;
                  v41 = *(_DWORD *)(v41 + 4);
                  if ( !v41 )
                    goto LABEL_70;
                }
                if ( v41 == v34[6] )
                  v34[6] = *(_DWORD *)(v41 + 4);
                if ( v42 )
                  *(_DWORD *)(v42 + 4) = *(_DWORD *)(v41 + 4);
                else
                  v34[4] = *(_DWORD *)(v41 + 4);
                if ( v34[5] == v41 )
                  v34[5] = v42;
                --v34[7];
                if ( *(_BYTE *)(v41 + 8) )
                  j__free(*(void **)v41);
                j__free((void *)v41);
              }
              else
              {
LABEL_70:
                v36 = 0;
              }
            }
            v39 = v36;
          }
          *(_DWORD *)(v39 + 4) = sub_614040(a2);
          (*(void (__thiscall **)(int *, int, int))(*a2 + 28))(a2, v39, 4);
          v43 = (_WORD *)(v39 + 8);
          (*(void (__thiscall **)(int *, int, int))(*a2 + 28))(a2, v39 + 8, 2);
          v44 = operator new(0x10u);
          if ( v44 )
          {
            *v44 = v39;
            v44[1] = 0;
            v44[2] = 0;
            *((_BYTE *)v44 + 12) = 0;
          }
          else
          {
            v44 = 0;
          }
          v45 = (_DWORD *)v60;
          if ( *(_DWORD *)(v60 + 1884) )
          {
            *(_DWORD *)(*(_DWORD *)(v60 + 1888) + 4) = v44;
            v44[2] = v45[472];
          }
          else
          {
            *(_DWORD *)(v60 + 1884) = v44;
            v45[473] = v44;
          }
          v46 = v45[474] + 1;
          v47 = 0;
          v45[472] = v44;
          v45[474] = v46;
          if ( *v43 )
          {
            do
            {
              (*(void (__thiscall **)(int *, unsigned int *, int))(*a2 + 28))(a2, v67, 4);
              if ( (v67[0] & 0xE0000000) != 0x20000000 || (v67[0] & 0xFC0000) != 0 )
                v48 = (v67[0] >> 8) & 0x3FF;
              else
                v48 = ((v67[0] >> 8) & 0x3FF) + 1;
              (*(void (__thiscall **)(int *, int))(*a2 + 56))(a2, v48);
              ++v47;
            }
            while ( v47 < (unsigned __int16)*v43 );
          }
          v49 = *(float *)(v60 + 2892832);
          ++LODWORD(v54);
        }
        while ( SLODWORD(v54) < SLODWORD(v49) );
      }
      v50 = v60;
      *(_DWORD *)(v60 + 2892844) = 0;
      *(_DWORD *)(v50 + 2892848) = 0;
      v51 = *(float ***)(v50 + 1884);
      *(_DWORD *)(v50 + 1892) = v51;
      if ( v51 )
      {
        v52 = *v51;
        if ( v52 )
        {
          v53 = *v52;
          *(float *)(v50 + 2892844) = *v52;
          *(float *)(v50 + 2892848) = v53 + *(float *)(v50 + 2892840);
        }
      }
      return v57;
    }
    else
    {
      return 0;
    }
  }
}
