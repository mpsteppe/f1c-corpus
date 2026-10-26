int __thiscall sub_6CD4DC(int this, unsigned int a2)
{
  int v3; // edx
  int v4; // ecx
  int v5; // esi
  int v6; // eax
  int v7; // esi
  int v8; // ecx
  int v9; // esi
  int v10; // ecx
  void *v11; // edi
  int v12; // esi
  const void *v13; // esi
  unsigned int i; // eax
  _DWORD *v15; // eax
  unsigned int j; // ecx
  int v17; // esi
  unsigned int k; // ecx
  int v19; // esi
  int v20; // esi
  _DWORD *v21; // eax
  bool v22; // cf
  unsigned int v23; // esi
  unsigned int v24; // edx
  int v25; // ecx
  int v26; // eax
  int v27; // ecx
  int v28; // edi
  int v29; // edx
  int v30; // edi
  int v31; // edx
  int v32; // edi
  _DWORD *v33; // esi
  int v34; // esi
  int v35; // ecx
  int v36; // edi
  _DWORD *v37; // esi
  int v38; // ecx
  unsigned int v39; // esi
  int v40; // ecx
  _DWORD *v41; // eax
  unsigned int v42; // esi
  unsigned int v43; // esi
  int v44; // eax
  int v45; // ecx
  _DWORD *v46; // eax
  int v47; // edi
  int v48; // esi
  unsigned int v49; // esi
  int v50; // eax
  int v51; // eax
  unsigned int v52; // edi
  const void *v53; // esi
  unsigned int v54; // edx
  _DWORD *v55; // eax
  unsigned int n; // ecx
  int v57; // esi
  unsigned int ii; // ecx
  int v59; // esi
  _DWORD *v60; // ecx
  _DWORD *v61; // ecx
  _DWORD *v62; // ecx
  unsigned int v63; // eax
  bool v64; // cc
  unsigned int v65; // eax
  int v67; // [esp+Ch] [ebp-54h]
  unsigned int v68; // [esp+10h] [ebp-50h] BYREF
  int v69; // [esp+14h] [ebp-4Ch]
  _DWORD *v70; // [esp+18h] [ebp-48h]
  int v71; // [esp+1Ch] [ebp-44h]
  int v72; // [esp+20h] [ebp-40h]
  unsigned int v73; // [esp+24h] [ebp-3Ch] BYREF
  unsigned int v74; // [esp+28h] [ebp-38h]
  int v75; // [esp+2Ch] [ebp-34h]
  unsigned int v76; // [esp+30h] [ebp-30h]
  unsigned int v77; // [esp+34h] [ebp-2Ch]
  int v78; // [esp+38h] [ebp-28h]
  int v79; // [esp+3Ch] [ebp-24h]
  unsigned int v80; // [esp+40h] [ebp-20h] BYREF
  int v81; // [esp+44h] [ebp-1Ch]
  int v82; // [esp+48h] [ebp-18h]
  unsigned int v83; // [esp+4Ch] [ebp-14h] BYREF
  unsigned int m; // [esp+50h] [ebp-10h]
  unsigned int v85; // [esp+54h] [ebp-Ch]
  unsigned int v86; // [esp+58h] [ebp-8h]
  int v87; // [esp+5Ch] [ebp-4h]
  unsigned int v88; // [esp+68h] [ebp+8h]
  unsigned int v89; // [esp+68h] [ebp+8h]

  v72 = 0;
  v85 = a2 + 1;
  v3 = *(_DWORD *)(*(_DWORD *)(this + 60) + 4 * a2);
  v4 = *(_DWORD *)(this + 4);
  v5 = *(_DWORD *)(v4 + 24);
  m = a2;
  v6 = 4 * v3;
  v7 = *(_DWORD *)(4 * v3 + v5);
  v67 = v3;
  if ( !*(_DWORD *)(4 * v3 + *(_DWORD *)(this + 52)) )
  {
    v8 = *(_DWORD *)(*(_DWORD *)(v4 + 20) + 4 * **(_DWORD **)(v7 + 16));
    v9 = *(_DWORD *)(v8 + 20);
    v10 = *(_DWORD *)(v8 + 24);
    v11 = *(void **)(this + 20);
    v79 = v9;
    v12 = *(_DWORD *)(this + 12);
    v75 = v10;
    v13 = (const void *)(*(_DWORD *)(this + 16) + 4 * *(_DWORD *)(v6 + v12));
    v83 = *(_DWORD *)(v6 + *(_DWORD *)(this + 8));
    qmemcpy(v11, v13, 4 * v83);
LABEL_3:
    v87 = 0;
    ++*(_DWORD *)(this + 72);
    for ( i = m; ; i = v88 + 1 )
    {
      v88 = i;
      if ( i >= v85 )
        break;
      v15 = *(_DWORD **)(*(_DWORD *)(*(_DWORD *)(this + 4) + 24) + 4 * *(_DWORD *)(*(_DWORD *)(this + 60) + 4 * i));
      for ( j = 0; j < v15[5]; *(_DWORD *)(v17 + 36) = *(_DWORD *)(this + 72) )
        v17 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 4) + 24) + 4 * *(_DWORD *)(v15[6] + 4 * j++));
      for ( k = 0; k < v15[7]; *(_DWORD *)(v19 + 36) = *(_DWORD *)(this + 72) )
        v19 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 4) + 24) + 4 * *(_DWORD *)(v15[8] + 4 * k++));
      v87 += *(_DWORD *)(*(_DWORD *)(this + 40) + 4 * *(_DWORD *)(*(_DWORD *)(this + 60) + 4 * v88));
    }
    v20 = 0;
    if ( v83 )
    {
      do
      {
        v21 = *(_DWORD **)(*(_DWORD *)(*(_DWORD *)(this + 4) + 20) + 4 * v20);
        v21[12] = *(_DWORD *)(this + 72);
        v22 = ++v20 < v83;
        v21[21] = v3 == v21[29];
      }
      while ( v22 );
    }
    while ( 1 )
    {
      if ( v87 >= 0 )
      {
        if ( v87 <= 0 )
          goto LABEL_84;
        v23 = v85 - 1;
        v86 = v85;
        v89 = v85;
        v78 = 1;
      }
      else
      {
        v23 = m;
        v78 = -1;
        v86 = m;
        v89 = m;
      }
      v24 = 0;
      v80 = 0;
      v81 = 0;
      v82 = 0;
      while ( 1 )
      {
        v39 = v78 + v23;
        v22 = v39 < *(_DWORD *)(this + 56);
        v74 = v39;
        if ( !v22 )
          break;
        v25 = *(_DWORD *)(this + 52);
        v71 = *(_DWORD *)(*(_DWORD *)(this + 60) + 4 * v39);
        v26 = 4 * v71;
        if ( !*(_DWORD *)(4 * v71 + v25) )
        {
          v27 = *(_DWORD *)(this + 4);
          v28 = *(_DWORD *)(*(_DWORD *)(v27 + 20) + 4 * **(_DWORD **)(*(_DWORD *)(*(_DWORD *)(v27 + 24) + 4 * v71) + 16));
          v29 = *(_DWORD *)(v28 + 20);
          v69 = v28;
          v30 = *(_DWORD *)(v28 + 24);
          while ( v29 != -1 )
          {
            if ( v79 == v29 )
              goto LABEL_23;
            v31 = *(_DWORD *)(*(_DWORD *)(v27 + 20) + 4 * v29);
            v30 = *(_DWORD *)(v31 + 24);
            v29 = *(_DWORD *)(v31 + 20);
          }
          if ( v79 != -1 )
            goto LABEL_84;
LABEL_23:
          if ( v75 != v30 )
            goto LABEL_84;
          v24 = v80;
        }
        if ( v86 > v39 )
          v86 = v39;
        if ( v89 <= v39 )
          v89 = v39 + 1;
        v32 = *(_DWORD *)(this + 24);
        v33 = (_DWORD *)(*(_DWORD *)(this + 16) + 4 * *(_DWORD *)(v26 + *(_DWORD *)(this + 12)));
        v76 = *(_DWORD *)(v26 + *(_DWORD *)(this + 8));
        v70 = v33;
        qmemcpy((void *)(v32 + 4 * v24), v33, 4 * v76);
        v24 += *(_DWORD *)(v26 + *(_DWORD *)(this + 8));
        v81 += *(_DWORD *)(*(_DWORD *)(this + 40) + v26);
        v34 = *(_DWORD *)(this + 72) - *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 4) + 24) + v26) + 36);
        v80 = v24;
        v82 |= v34 == 0;
        v35 = 0;
        v77 = 0;
        if ( v76 )
        {
          v36 = v71;
          do
          {
            v37 = *(_DWORD **)(*(_DWORD *)(*(_DWORD *)(this + 4) + 20) + 4 * v70[v35]);
            v38 = *(_DWORD *)(this + 72);
            if ( v37[12] != v38 || v36 == v37[29] )
            {
              v37[12] = v38;
              v37[21] = (v36 != v37[29]) - 1;
            }
            v35 = ++v77;
          }
          while ( v77 < v76 );
        }
        if ( !*(_DWORD *)(v26 + *(_DWORD *)(this + 52)) && v79 == *(_DWORD *)(v69 + 20) && v75 == *(_DWORD *)(v69 + 24) )
          break;
        v23 = v74;
      }
      if ( v86 >= v89 )
      {
LABEL_84:
        if ( v72 )
        {
          qmemcpy(*(void **)(this + 60), *(const void **)(this + 64), 4 * *(_DWORD *)(this + 56));
          sub_6CD3BF((_DWORD *)this, 0, 0);
        }
        return 1;
      }
      if ( v86 + 1 < v89 )
      {
        sub_6CD379(*(int **)(this + 24), &v80);
        v24 = v80;
      }
      if ( !v82 )
      {
        if ( v87 >= 0 )
        {
          v43 = v83;
          v44 = v87;
          v78 = v87;
          if ( v83 )
          {
            v45 = *(_DWORD *)(*(_DWORD *)(this + 4) + 20);
            v46 = *(_DWORD **)(this + 20);
            do
            {
              if ( *(_DWORD *)(*(_DWORD *)(v45 + 4 * *v46) + 84) == -1 )
                --v78;
              ++v46;
              --v43;
            }
            while ( v43 );
            v44 = v78;
          }
          if ( v44 < v81 )
LABEL_59:
            v82 = 1;
        }
        else
        {
          v78 = v81;
          if ( v24 )
          {
            v40 = *(_DWORD *)(*(_DWORD *)(this + 4) + 20);
            v41 = *(_DWORD **)(this + 24);
            v42 = v24;
            do
            {
              if ( *(_DWORD *)(*(_DWORD *)(v40 + 4 * *v41) + 84) == 1 )
                --v78;
              ++v41;
              --v42;
            }
            while ( v42 );
          }
          if ( v87 > v78 )
            goto LABEL_59;
        }
      }
      v47 = m;
      if ( m >= v86 )
        v47 = v86;
      v48 = v85;
      if ( v85 <= v89 )
        v48 = v89;
      if ( !v82 )
      {
        sub_6CD2CE((_DWORD *)this, m, v85);
        sub_6CD2CE(v60, v86, v89);
        sub_6CD2CE(v61, v47, v48);
        sub_6CD3BF(v62, &v73, &v68);
        v63 = *(_DWORD *)(this + 80);
        v64 = v73 <= v63;
        if ( v73 < v63 )
        {
          if ( v68 > *(_DWORD *)(this + 76) )
          {
            v64 = v73 <= v63;
            goto LABEL_77;
          }
          return 0;
        }
LABEL_77:
        if ( v64 && v68 < *(_DWORD *)(this + 76) )
          return 0;
        if ( v87 >= 0 )
          v65 = v89 - v86;
        else
          v65 = v86 - v89;
        m += v65;
        v85 += v65;
        v3 = v67;
        v72 = 1;
        goto LABEL_3;
      }
      v85 = v48;
      v49 = 0;
      for ( m = v47; v49 < v24; *(_DWORD *)(v50 + 84) = *(_DWORD *)(v50 + 84) != 0 )
        v50 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 4) + 20) + 4 * *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v49++));
      v51 = *(_DWORD *)(this + 20);
      v52 = v83;
      v53 = *(const void **)(this + 24);
      v83 += v24;
      v87 += v81;
      qmemcpy((void *)(v51 + 4 * v52), v53, 4 * v24);
      sub_6CD379(*(int **)(this + 20), &v83);
      v54 = v86;
      do
      {
        v55 = *(_DWORD **)(*(_DWORD *)(*(_DWORD *)(this + 4) + 24) + 4 * *(_DWORD *)(*(_DWORD *)(this + 60) + 4 * v54));
        for ( n = 0; n < v55[5]; *(_DWORD *)(v57 + 36) = *(_DWORD *)(this + 72) )
          v57 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 4) + 24) + 4 * *(_DWORD *)(v55[6] + 4 * n++));
        for ( ii = 0; ii < v55[7]; *(_DWORD *)(v59 + 36) = *(_DWORD *)(this + 72) )
          v59 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 4) + 24) + 4 * *(_DWORD *)(v55[8] + 4 * ii++));
        ++v54;
      }
      while ( v54 < v89 );
    }
  }
  return 1;
}
