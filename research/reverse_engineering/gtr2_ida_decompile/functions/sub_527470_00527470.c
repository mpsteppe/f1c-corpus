int __thiscall sub_527470(int this, float a2)
{
  int i; // edi
  int v4; // eax
  int v5; // esi
  float **v6; // eax
  float *v7; // eax
  float **v8; // eax
  int v9; // eax
  int *v10; // eax
  int v11; // esi
  int *v12; // eax
  int v13; // eax
  int *v14; // eax
  int j; // ecx
  int v16; // eax
  int v17; // eax
  int *v18; // eax
  int *v19; // edi
  int v20; // edx
  int v21; // eax
  int v22; // edx
  int v23; // ebx
  unsigned int v24; // eax
  int v25; // esi
  int v26; // eax
  int *v27; // eax
  int v28; // ecx
  int v29; // esi
  int v30; // eax
  int *v31; // eax
  int v32; // eax
  int *v33; // eax
  int *v34; // eax
  bool v35; // zf
  int v36; // esi
  int v37; // edx
  int v38; // eax
  int v39; // ecx
  int v40; // eax
  int *v41; // eax
  int *v42; // edi
  int v43; // eax
  int v44; // edx
  int v45; // ebx
  unsigned int v46; // eax
  int v47; // esi
  int v48; // eax
  int *v49; // eax
  int v50; // ecx
  int v51; // eax
  int *v52; // eax
  int v53; // eax
  int *v54; // eax
  int v56; // [esp+4h] [ebp-538h]
  int v57; // [esp+4h] [ebp-538h]
  int v58; // [esp+18h] [ebp-524h]
  int v59; // [esp+1Ch] [ebp-520h]
  int *v60; // [esp+20h] [ebp-51Ch] BYREF
  int v61; // [esp+24h] [ebp-518h]
  int v62; // [esp+28h] [ebp-514h]
  int v63; // [esp+30h] [ebp-50Ch]
  int v64; // [esp+34h] [ebp-508h]
  int v65; // [esp+38h] [ebp-504h] BYREF
  int v66; // [esp+3Ch] [ebp-500h]
  __int16 v67; // [esp+40h] [ebp-4FCh]
  int v68[94]; // [esp+48h] [ebp-4F4h]
  int v69[6]; // [esp+1C0h] [ebp-37Ch] BYREF
  int v70[217]; // [esp+1D8h] [ebp-364h] BYREF

  for ( i = 0; i < 105; ++i )
  {
    v4 = sub_5223B0((char *)this, i, a2, 0);
    v5 = v4;
    v68[i] = v4;
    if ( v4 )
    {
      if ( (unsigned __int8)sub_599CD0(v4 + 212)
        && a2 >= (double)*(float *)(v5 + 1072)
        && (unsigned __int8)sub_599CF0(v5 + 212)
        && a2 <= (double)*(float *)(v5 + 224) )
      {
        v68[i] = 0;
      }
      else
      {
        sub_59A9C0(v5 + 212);
      }
    }
  }
  v64 = this + 2892864;
  sub_521A20(this + 2892864, a2);
  v6 = *(float ***)(this + 1892);
  if ( v6 && (v7 = *v6) != 0
    || (*(float *)(this + 2892848) - *(float *)(this + 2892844) + *(float *)(this + 2892844) >= a2
      ? (v8 = *(float ***)(this + 1884))
      : (v8 = *(float ***)(this + 1888)),
        (*(_DWORD *)(this + 1892) = v8) != 0 && (v7 = *v8) != 0) )
  {
    if ( *v7 <= (double)a2 )
    {
      while ( 1 )
      {
        v13 = *(_DWORD *)(this + 1892);
        if ( !v13 )
          break;
        v14 = *(int **)(v13 + 4);
        *(_DWORD *)(this + 1892) = v14;
        if ( !v14 )
          break;
        v11 = *v14;
        if ( !*v14 )
          break;
        if ( *(float *)v11 >= (double)a2 )
          goto LABEL_33;
      }
      v12 = *(int **)(this + 1888);
    }
    else
    {
      while ( 1 )
      {
        v9 = *(_DWORD *)(this + 1892);
        if ( !v9 )
          break;
        v10 = *(int **)(v9 + 8);
        *(_DWORD *)(this + 1892) = v10;
        if ( !v10 )
          break;
        v11 = *v10;
        if ( !*v10 )
          break;
        if ( *(float *)v11 <= (double)a2 )
          goto LABEL_33;
      }
      v12 = *(int **)(this + 1884);
    }
    *(_DWORD *)(this + 1892) = v12;
    if ( v12 )
      v11 = *v12;
    else
      v11 = 0;
LABEL_33:
    j = -1;
    v65 = *(_DWORD *)(this + 1892);
    if ( v65 )
    {
      v16 = *(_DWORD *)(this + 1884);
      for ( j = 0; v16; ++j )
      {
        if ( v16 == v65 )
          break;
        v16 = *(_DWORD *)(v16 + 4);
      }
    }
    if ( j < *(_DWORD *)(this + 1896) - 1 && v11 )
    {
      while ( *(float *)v11 < (double)a2 )
      {
        v17 = *(_DWORD *)(this + 1892);
        if ( v17 )
          *(_DWORD *)(this + 1892) = *(_DWORD *)(v17 + 4);
        v18 = *(int **)(this + 1892);
        if ( !v18 )
        {
          v11 = 0;
          break;
        }
        v11 = *v18;
        if ( !*v18 )
          break;
      }
    }
    v63 = 0;
    if ( v11 )
    {
      v19 = (int *)(this + 1780);
      do
      {
        v20 = *v19;
        v59 = *(_DWORD *)(v11 + 4);
        (*(void (__thiscall **)(int))(v20 + 52))(this + 1780);
        v65 = 0;
        v66 = 0;
        v67 = 0;
        v21 = sub_614040(this + 1780);
        v22 = *v19;
        v66 = v21;
        v58 = 4;
        (*(void (__thiscall **)(int, int *))(v22 + 28))(this + 1780, &v65);
        (*(void (__thiscall **)(int, int *, int))(*v19 + 28))(this + 1780, &v65, 2);
        if ( ++v59 > 64 )
          break;
        v23 = 0;
        if ( *(_WORD *)(v11 + 8) )
        {
          do
          {
            sub_5212F0(this + 1780, *(float *)v11, (int)v70);
            v24 = v70[0];
            if ( *(_DWORD *)(this + 2892916) )
            {
              v24 = *(_DWORD *)(this + 2892924) | v70[0] & 0xFFFFFF00;
              v70[0] = v24;
            }
            if ( (v24 & 0xE0000000) == 0x20000000 )
            {
              if ( ((v24 >> 18) & 0x3F) != 0 )
              {
                if ( ((v24 >> 18) & 0x3F) <= 6 )
                  sub_526640();
              }
              else if ( (unsigned __int8)v24 < 0x69u && *(&v64 + (unsigned __int8)v24) )
              {
                sub_599BB0(*(float *)&v70[213], (int)v70);
              }
            }
            ++v23;
          }
          while ( v23 < *(unsigned __int16 *)(v11 + 8) );
        }
        v25 = 0;
        while ( 1 )
        {
          v26 = *(&v63 + v25);
          if ( v26 )
          {
            if ( !(unsigned __int8)sub_599CD0(v26 + 212) )
              break;
          }
          if ( ++v25 >= 105 )
          {
            v27 = *(int **)(v59 + 32);
            *(_DWORD *)(v59 + 40) = v27;
            if ( !v27 )
              goto LABEL_77;
            v28 = *v27;
            if ( !*v27 )
              goto LABEL_77;
            v29 = v59;
            while ( (unsigned __int8)sub_599CD0(v28) )
            {
              v30 = *(_DWORD *)(v29 + 40);
              if ( v30 )
                *(_DWORD *)(v29 + 40) = *(_DWORD *)(v30 + 4);
              v31 = *(int **)(v29 + 40);
              if ( v31 )
              {
                v28 = *v31;
                if ( *v31 )
                  continue;
              }
              goto LABEL_77;
            }
            break;
          }
        }
        v32 = *(_DWORD *)(this + 1892);
        if ( v32 )
          *(_DWORD *)(this + 1892) = *(_DWORD *)(v32 + 8);
        v33 = *(int **)(this + 1892);
        if ( !v33 )
          break;
        v11 = *v33;
      }
      while ( *v33 );
    }
LABEL_77:
    v34 = v60;
    v35 = v60 == 0;
    *(_DWORD *)(this + 1892) = v60;
    if ( v35 )
      v36 = 0;
    else
      v36 = *v34;
    v37 = *(_DWORD *)(this + 1892);
    if ( v37 )
    {
      v38 = *(_DWORD *)(this + 1884);
      v39 = 0;
      if ( v38 )
      {
        do
        {
          if ( v38 == v37 )
            break;
          v38 = *(_DWORD *)(v38 + 4);
          ++v39;
        }
        while ( v38 );
        if ( v39 > 0 && v36 )
        {
          while ( *(float *)v36 > (double)*(float *)&v70[212] )
          {
            v40 = *(_DWORD *)(this + 1892);
            if ( v40 )
              *(_DWORD *)(this + 1892) = *(_DWORD *)(v40 + 8);
            v41 = *(int **)(this + 1892);
            if ( !v41 )
            {
              v36 = 0;
              break;
            }
            v36 = *v41;
            if ( !*v41 )
              break;
          }
        }
      }
    }
    v58 = 0;
    if ( v36 )
    {
      v42 = (int *)(this + 1780);
      do
      {
        v57 = *(_DWORD *)(v36 + 4);
        (*(void (__thiscall **)(int))(*v42 + 52))(this + 1780);
        v60 = 0;
        v61 = 0;
        LOWORD(v62) = 0;
        v43 = sub_614040(this + 1780);
        v44 = *v42;
        v61 = v43;
        (*(void (__thiscall **)(int, int **))(v44 + 28))(this + 1780, &v60);
        (*(void (__thiscall **)(int, int **, int))(*v42 + 28))(this + 1780, &v60, 2);
        v56 = v57 + 1;
        if ( v56 > 64 )
          break;
        v45 = 0;
        if ( *(_WORD *)(v36 + 8) )
        {
          do
          {
            sub_5212F0(this + 1780, *(float *)v36, (int)v69);
            v46 = v69[0];
            if ( *(_DWORD *)(this + 2892916) )
            {
              v46 = *(_DWORD *)(this + 2892924) | v69[0] & 0xFFFFFF00;
              v69[0] = v46;
            }
            if ( (v46 & 0xE0000000) == 0x20000000 )
            {
              if ( ((v46 >> 18) & 0x3F) != 0 )
              {
                if ( ((v46 >> 18) & 0x3F) <= 6 )
                  sub_526640();
              }
              else if ( (unsigned __int8)v46 < 0x69u && *(&v59 + (unsigned __int8)v46) )
              {
                sub_599BB0(*(float *)&v70[207], (int)v69);
              }
            }
            ++v45;
          }
          while ( v45 < *(unsigned __int16 *)(v36 + 8) );
        }
        v47 = 0;
        while ( 1 )
        {
          v48 = *(&v58 + v47);
          if ( v48 )
          {
            if ( !(unsigned __int8)sub_599CF0(v48 + 212) )
              break;
          }
          if ( ++v47 >= 105 )
          {
            v49 = *(int **)(v56 + 32);
            *(_DWORD *)(v56 + 40) = v49;
            if ( !v49 )
              goto LABEL_123;
            v50 = *v49;
            if ( !*v49 )
              goto LABEL_123;
            while ( (unsigned __int8)sub_599CF0(v50) )
            {
              v51 = *(_DWORD *)(v56 + 40);
              if ( v51 )
                *(_DWORD *)(v56 + 40) = *(_DWORD *)(v51 + 4);
              v52 = *(int **)(v56 + 40);
              if ( v52 )
              {
                v50 = *v52;
                if ( *v52 )
                  continue;
              }
              goto LABEL_123;
            }
            break;
          }
        }
        v53 = *(_DWORD *)(this + 1892);
        if ( v53 )
          *(_DWORD *)(this + 1892) = *(_DWORD *)(v53 + 4);
        v54 = *(int **)(this + 1892);
        if ( !v54 )
          break;
        v36 = *v54;
      }
      while ( *v54 );
    }
  }
LABEL_123:
  sub_526120(v56);
  return sub_521B00();
}
