int __thiscall sub_60F3B0(int *this)
{
  _DWORD *v2; // eax
  int v3; // eax
  int v4; // eax
  int *v5; // eax
  int v6; // ebp
  int v7; // esi
  int v8; // edi
  unsigned int *v9; // ecx
  _DWORD *v10; // ecx
  char *v11; // esi
  int *v12; // eax
  int i; // eax
  int v14; // eax
  int *v15; // eax
  _DWORD *v16; // esi
  _DWORD **v17; // eax
  _DWORD *j; // eax
  int v19; // eax
  _DWORD **v20; // eax
  _DWORD **v21; // eax
  _DWORD *k; // eax
  int v23; // eax
  _DWORD **v24; // eax
  _DWORD **v25; // eax
  _DWORD *m; // eax
  int v27; // eax
  _DWORD **v28; // eax
  int *v29; // eax
  int n; // eax
  int v31; // eax
  int *v32; // eax
  int *v33; // eax
  int ii; // eax
  int v35; // eax
  int *v36; // eax
  _DWORD **v37; // eax
  _DWORD *jj; // eax
  int v39; // eax
  _DWORD **v40; // eax
  _DWORD **v41; // eax
  _DWORD *kk; // eax
  int v43; // eax
  _DWORD **v44; // eax
  _DWORD **v45; // eax
  _DWORD *mm; // eax
  int v47; // eax
  _DWORD **v48; // eax
  _DWORD **v49; // eax
  _DWORD *nn; // eax
  int v51; // eax
  _DWORD **v52; // eax
  char *v53; // esi
  int v54; // eax
  int v55; // eax
  int v57; // edi
  int v58; // eax
  int v59; // eax
  int v60; // eax
  int v61; // eax
  int v62; // edx
  int v63; // eax
  int *v64; // esi
  int v65; // ebp
  int v66; // eax
  int v67; // eax
  int v68; // ebp
  int v69; // eax
  int v70; // edx
  _DWORD *v71; // eax
  _DWORD *v72; // esi
  _DWORD *v73; // eax
  _DWORD *v74; // ecx
  _DWORD *v75; // eax
  _DWORD **v76; // eax
  _DWORD *v77; // eax
  _DWORD *v78; // esi
  _DWORD **v79; // eax
  _DWORD *i1; // eax
  int v81; // eax
  _DWORD **v82; // eax
  _DWORD **v83; // eax
  _DWORD *i2; // eax
  int v85; // eax
  _DWORD **v86; // eax
  double v87; // st7
  double v88; // st7
  int v89; // edi
  unsigned __int16 *v90; // esi
  __int16 v91; // bp
  unsigned __int64 v92; // rax
  unsigned __int16 v93; // bp
  unsigned __int16 v94; // bp
  int v95; // [esp+6Ch] [ebp-618h]
  char v96; // [esp+70h] [ebp-614h]
  int v97; // [esp+7Ch] [ebp-608h] BYREF
  char *v98; // [esp+80h] [ebp-604h]
  _WORD v99[768]; // [esp+84h] [ebp-600h] BYREF

  v2 = (_DWORD *)*this;
  v98 = (char *)this;
  ((void (__stdcall *)(_DWORD))v2[116])(0);
  v3 = (*(int (__stdcall **)(int, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)this[2387] + 68))(this[2387], 0, 0, 0, 0);
  this[2] = v3;
  if ( v3 != -2005530520 )
    goto LABEL_134;
  if ( !*((_BYTE *)this + 4813) )
    *((_BYTE *)this + 4813) = 1;
  v4 = (*(int (__stdcall **)(int))(*(_DWORD *)this[2387] + 12))(this[2387]);
  this[2] = v4;
  if ( v4 != -2005530519 )
  {
LABEL_134:
    *((_BYTE *)this + 4814) = 0;
    if ( *((float *)this + 1476) != 0.0 )
    {
      v87 = sub_5F5900(this[1475]);
      if ( v87 < *((float *)this + 1476) )
      {
        v88 = v87 / *((float *)v98 + 1476);
        v89 = 0;
        v90 = (unsigned __int16 *)(v98 + 5908);
        do
        {
          v91 = *v90;
          v97 = v90[768] - *v90;
          v92 = (unsigned __int64)((double)v97 * v88);
          HIDWORD(v92) = v90[1024];
          LOWORD(v92) = v91 + v92;
          v93 = v90[256];
          v99[v89] = v92;
          v97 = HIDWORD(v92) - v93;
          LOWORD(v92) = v93 + (unsigned __int64)((double)v97 * v88);
          v94 = v90[512];
          v97 = v90[1280] - v94;
          v99[v89 + 256] = v92;
          ++v90;
          v99[v89++ + 512] = v94 + (unsigned __int64)((double)v97 * v88);
        }
        while ( v89 < 256 );
        (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD, _WORD *))(**((_DWORD **)v98 + 2387) + 84))(
          *((_DWORD *)v98 + 2387),
          0,
          0,
          v99);
        return 0;
      }
      (*(void (__stdcall **)(int, _DWORD, _DWORD, int *))(*(_DWORD *)this[2387] + 84))(this[2387], 0, 0, this + 1861);
      sub_5F5BC0(this[1475]);
      this[1476] = 0;
    }
    return 0;
  }
  (*(void (__thiscall **)(int *, void *))(*this + 248))(this, dword_FB2790);
  (*(void (__thiscall **)(int *))(*this + 240))(this);
  v5 = (int *)dword_FB2D78;
  dword_FB2D80 = (int)dword_FB2D78;
  if ( dword_FB2D78 )
  {
    v6 = *(_DWORD *)dword_FB2D78;
    if ( *(_DWORD *)dword_FB2D78 )
    {
      do
      {
        v7 = 0;
        if ( *(int *)(v6 + 212) > 0 )
        {
          v8 = v6;
          do
          {
            (*(void (__thiscall **)(char *, int, int))(*(_DWORD *)v98 + 336))(v98, v8, 1);
            ++v7;
            v8 += 216;
          }
          while ( v7 < *(_DWORD *)(v6 + 212) );
          v5 = (int *)dword_FB2D80;
        }
        if ( !v5 )
          break;
        v5 = (int *)v5[1];
        dword_FB2D80 = (int)v5;
        if ( !v5 )
          break;
        v6 = *v5;
      }
      while ( *v5 );
    }
  }
  dword_FB28B4 = (int)dword_FB28AC;
  if ( dword_FB28AC )
  {
    v9 = *(unsigned int **)dword_FB28AC;
    if ( *(_DWORD *)dword_FB28AC )
    {
      do
      {
        sub_5EDEE0(v9);
        if ( !dword_FB28B4 )
          break;
        dword_FB28B4 = *(_DWORD *)(dword_FB28B4 + 4);
        if ( !dword_FB28B4 )
          break;
        v9 = *(unsigned int **)dword_FB28B4;
      }
      while ( *(_DWORD *)dword_FB28B4 );
    }
  }
  dword_FB2884 = dword_FB287C;
  if ( dword_FB287C )
  {
    v10 = *(_DWORD **)dword_FB287C;
    if ( *(_DWORD *)dword_FB287C )
    {
      do
      {
        sub_5F0620(v10);
        if ( !dword_FB2884 )
          break;
        dword_FB2884 = *(_DWORD *)(dword_FB2884 + 4);
        if ( !dword_FB2884 )
          break;
        v10 = *(_DWORD **)dword_FB2884;
      }
      while ( *(_DWORD *)dword_FB2884 );
    }
  }
  v11 = v98;
  v12 = (int *)*((_DWORD *)v98 + 2348);
  *((_DWORD *)v98 + 2350) = v12;
  if ( v12 )
  {
    for ( i = *v12; i; i = *v15 )
    {
      sub_5F2BE0(i);
      v14 = *((_DWORD *)v11 + 2350);
      if ( !v14 )
        break;
      v15 = *(int **)(v14 + 4);
      *((_DWORD *)v11 + 2350) = v15;
      if ( !v15 )
        break;
    }
  }
  dword_FB28C4 = (int)dword_FB28BC;
  if ( dword_FB28BC )
  {
    v16 = *(_DWORD **)dword_FB28BC;
    if ( *(_DWORD *)dword_FB28BC )
    {
      do
      {
        v17 = (_DWORD **)v16[165];
        v16[167] = v17;
        if ( v17 )
        {
          for ( j = *v17; j; j = *v20 )
          {
            sub_5FDB10(j);
            v19 = v16[167];
            if ( !v19 )
              break;
            v20 = *(_DWORD ***)(v19 + 4);
            v16[167] = v20;
            if ( !v20 )
              break;
          }
        }
        v21 = (_DWORD **)v16[169];
        v16[171] = v21;
        if ( v21 )
        {
          for ( k = *v21; k; k = *v24 )
          {
            sub_5FDB10(k);
            v23 = v16[171];
            if ( !v23 )
              break;
            v24 = *(_DWORD ***)(v23 + 4);
            v16[171] = v24;
            if ( !v24 )
              break;
          }
        }
        v25 = (_DWORD **)v16[173];
        v16[175] = v25;
        if ( v25 )
        {
          for ( m = *v25; m; m = *v28 )
          {
            sub_5FDB10(m);
            v27 = v16[175];
            if ( !v27 )
              break;
            v28 = *(_DWORD ***)(v27 + 4);
            v16[175] = v28;
            if ( !v28 )
              break;
          }
        }
        v29 = (int *)v16[141];
        v16[143] = v29;
        if ( v29 )
        {
          for ( n = *v29; n; n = *v32 )
          {
            sub_600480(n);
            v31 = v16[143];
            if ( !v31 )
              break;
            v32 = *(int **)(v31 + 4);
            v16[143] = v32;
            if ( !v32 )
              break;
          }
        }
        v33 = (int *)v16[145];
        v16[147] = v33;
        if ( v33 )
        {
          for ( ii = *v33; ii; ii = *v36 )
          {
            sub_600480(ii);
            v35 = v16[147];
            if ( !v35 )
              break;
            v36 = *(int **)(v35 + 4);
            v16[147] = v36;
            if ( !v36 )
              break;
          }
        }
        v37 = (_DWORD **)v16[149];
        v16[151] = v37;
        if ( v37 )
        {
          for ( jj = *v37; jj; jj = *v40 )
          {
            sub_5E6030(jj);
            v39 = v16[151];
            if ( !v39 )
              break;
            v40 = *(_DWORD ***)(v39 + 4);
            v16[151] = v40;
            if ( !v40 )
              break;
          }
        }
        v41 = (_DWORD **)v16[153];
        v16[155] = v41;
        if ( v41 )
        {
          for ( kk = *v41; kk; kk = *v44 )
          {
            sub_5E6030(kk);
            v43 = v16[155];
            if ( !v43 )
              break;
            v44 = *(_DWORD ***)(v43 + 4);
            v16[155] = v44;
            if ( !v44 )
              break;
          }
        }
        v45 = (_DWORD **)v16[109];
        v16[111] = v45;
        if ( v45 )
        {
          for ( mm = *v45; mm; mm = *v48 )
          {
            sub_5DA710(mm);
            v47 = v16[111];
            if ( !v47 )
              break;
            v48 = *(_DWORD ***)(v47 + 4);
            v16[111] = v48;
            if ( !v48 )
              break;
          }
        }
        v49 = (_DWORD **)v16[113];
        v16[115] = v49;
        if ( v49 )
        {
          for ( nn = *v49; nn; nn = *v52 )
          {
            sub_5DA710(nn);
            v51 = v16[115];
            if ( !v51 )
              break;
            v52 = *(_DWORD ***)(v51 + 4);
            v16[115] = v52;
            if ( !v52 )
              break;
          }
        }
        if ( !dword_FB28C4 )
          break;
        dword_FB28C4 = *(_DWORD *)(dword_FB28C4 + 4);
        if ( !dword_FB28C4 )
          break;
        v16 = *(_DWORD **)dword_FB28C4;
      }
      while ( *(_DWORD *)dword_FB28C4 );
    }
  }
  v53 = v98;
  (*(void (__thiscall **)(char *))(*(_DWORD *)v98 + 364))(v98);
  memset(v98 + 4876, 0xFFu, 0x400u);
  v54 = (*(int (__stdcall **)(_DWORD, char *))(**((_DWORD **)v53 + 2387) + 64))(*((_DWORD *)v53 + 2387), v53 + 9552);
  *((_DWORD *)v98 + 2) = v54;
  if ( v54 )
  {
    if ( v54 == -2005530520 )
    {
      v55 = (*(int (__stdcall **)(_DWORD))(**((_DWORD **)v53 + 2387) + 12))(*((_DWORD *)v53 + 2387));
      *((_DWORD *)v53 + 2) = v55;
      if ( v55 != -2005530519 )
        return -1;
      sub_5D8C80((int)(v53 + 4), (char *)0xFFFFFFFE, "Cannot reset device ;( - error 0x%X", 105);
    }
    else
    {
      sub_5D8C80((int)(v53 + 4), (char *)0xFFFFFFFE, "Device lost ;o - error 0x%X", v54);
    }
    return -1;
  }
  else
  {
    v57 = (int)(v53 + 4);
    v58 = *((_DWORD *)v53 + 2387);
    if ( v53[4] >= 0 )
      (*(void (__stdcall **)(int, _DWORD))(*(_DWORD *)v58 + 308))(v58, 0);
    else
      (*(void (__stdcall **)(int, int))(*(_DWORD *)v58 + 308))(v58, 1);
    *((_DWORD *)v53 + 2) = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, int *))(**((_DWORD **)v53 + 2387) + 72))(
                             *((_DWORD *)v53 + 2387),
                             0,
                             0,
                             0,
                             &v97);
    v59 = v97;
    *((_DWORD *)v53 + 2431) = dword_FB2790;
    sub_5E7180(dword_FB2790, v59, 2);
    *(_DWORD *)dword_FB2790 |= 0x2042u;
    *((_DWORD *)v53 + 2) = (*(int (__stdcall **)(_DWORD, _DWORD, int))(**((_DWORD **)v53 + 2387) + 148))(
                             *((_DWORD *)v53 + 2387),
                             0,
                             v97);
    v60 = *((_DWORD *)v53 + 2387);
    if ( *((_DWORD *)v53 + 2392) )
      v61 = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)v60 + 228))(v60, 161, 1);
    else
      v61 = (*(int (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v60 + 228))(v60, 161, 0);
    v62 = *((_DWORD *)v53 + 2392);
    v95 = *((_DWORD *)v53 + 2393);
    *((_DWORD *)v53 + 2) = v61;
    if ( (*(int (__thiscall **)(char *, _DWORD, void *, int, int))(*(_DWORD *)v53 + 244))(
           v53,
           0,
           dword_FB2790,
           v62,
           v95) )
    {
      return -1;
    }
    else
    {
      v63 = sub_5E7120(*((int **)dword_FB2790 + 29), 2);
      sub_5E7180(dword_FB2794, v63, 2);
      v64 = (int *)*((_DWORD *)v53 + 2387);
      v65 = *v64;
      v66 = sub_5E7120((int *)dword_FB2794, 2);
      v67 = (*(int (__stdcall **)(int *, int))(v65 + 156))(v64, v66);
      v68 = (int)v98;
      *((_DWORD *)v98 + 2) = v67;
      if ( v67 )
      {
        sub_5D8C80(v57, (char *)0xFFFFFFFF, "Error attaching Z buffer to back buffer", v96);
        return -1;
      }
      else
      {
        v69 = (*(int (__stdcall **)(int))(*(_DWORD *)v97 + 8))(v97);
        v70 = *(_DWORD *)v68;
        *(_DWORD *)(v68 + 8) = v69;
        (*(void (__thiscall **)(int))(v70 + 236))(v68);
        v71 = dword_FB2D78;
        dword_FB2D80 = (int)dword_FB2D78;
        if ( dword_FB2D78 )
        {
          v72 = *(_DWORD **)dword_FB2D78;
          if ( *(_DWORD *)dword_FB2D78 )
          {
            while ( 1 )
            {
              if ( (*(_BYTE *)v72 & 0x40) != 0 )
              {
                if ( (*(int (__thiscall **)(int, _DWORD *, int))(*(_DWORD *)v68 + 216))(v68, v72, 1) )
                {
                  sub_5D8C80(v57, (char *)0xFFFFFFFF, "Error restoring render target for texture %s", (_BYTE)v72 - 116);
                  return -1;
                }
                sub_5E6F50(v72, 0, 0, v72[1], v72[2], 0);
                v71 = (_DWORD *)dword_FB2D80;
              }
              if ( v71 )
              {
                v71 = (_DWORD *)v71[1];
                dword_FB2D80 = (int)v71;
                if ( v71 )
                {
                  v72 = (_DWORD *)*v71;
                  if ( *v71 )
                    continue;
                }
              }
              break;
            }
          }
        }
        v73 = dword_FB28BC;
        dword_FB28C4 = (int)dword_FB28BC;
        if ( dword_FB28BC )
        {
          v74 = *(_DWORD **)dword_FB28BC;
          if ( *(_DWORD *)dword_FB28BC )
          {
            do
            {
              if ( (int)v74[191] > 0 )
              {
                v75 = (_DWORD *)v74[188];
                if ( v75 )
                {
                  if ( *v75 )
                  {
                    if ( (int)v74[191] > 0 && (v76 = (_DWORD **)v74[188]) != 0 )
                      v77 = *v76;
                    else
                      v77 = 0;
                    *v77 |= 0xF00u;
                  }
                }
              }
              sub_5DD0A0(v74, 1, 0);
              if ( !dword_FB28C4 )
                break;
              dword_FB28C4 = *(_DWORD *)(dword_FB28C4 + 4);
              if ( !dword_FB28C4 )
                break;
              v74 = *(_DWORD **)dword_FB28C4;
            }
            while ( *(_DWORD *)dword_FB28C4 );
            v73 = dword_FB28BC;
          }
        }
        dword_FB28C4 = (int)v73;
        if ( v73 )
        {
          v78 = (_DWORD *)*v73;
          if ( *v73 )
          {
            do
            {
              v79 = (_DWORD **)v78[165];
              v78[167] = v79;
              if ( v79 )
              {
                for ( i1 = *v79; i1; i1 = *v82 )
                {
                  sub_5FC840(i1, v68, v57, 0);
                  v81 = v78[167];
                  if ( !v81 )
                    break;
                  v82 = *(_DWORD ***)(v81 + 4);
                  v78[167] = v82;
                  if ( !v82 )
                    break;
                }
              }
              v83 = (_DWORD **)v78[169];
              v78[171] = v83;
              if ( v83 )
              {
                for ( i2 = *v83; i2; i2 = *v86 )
                {
                  sub_5FC840(i2, v68, v57, 0);
                  v85 = v78[171];
                  if ( !v85 )
                    break;
                  v86 = *(_DWORD ***)(v85 + 4);
                  v78[171] = v86;
                  if ( !v86 )
                    break;
                }
              }
              if ( !dword_FB28C4 )
                break;
              dword_FB28C4 = *(_DWORD *)(dword_FB28C4 + 4);
              if ( !dword_FB28C4 )
                break;
              v78 = *(_DWORD **)dword_FB28C4;
            }
            while ( *(_DWORD *)dword_FB28C4 );
          }
        }
        *(_BYTE *)(v68 + 4813) = 0;
        *(_BYTE *)(v68 + 4814) = 1;
        return -2;
      }
    }
  }
}
