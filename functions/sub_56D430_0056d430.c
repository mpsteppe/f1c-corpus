int __thiscall sub_56D430(_DWORD *this)
{
  _DWORD *v1; // ebp
  int v2; // ebx
  int v3; // edi
  int v4; // esi
  int v5; // ecx
  int v6; // eax
  int v7; // edx
  int v8; // eax
  int v9; // ecx
  int *v10; // ebx
  int v11; // edx
  int v12; // eax
  int v13; // esi
  int v14; // edx
  int v15; // eax
  int v16; // eax
  int v17; // edx
  int v18; // ecx
  int v19; // ecx
  int j; // edx
  int v21; // edi
  int v22; // esi
  int v23; // edi
  _DWORD *v24; // ecx
  int v25; // eax
  int v26; // edi
  int v27; // ebx
  int v28; // ecx
  int v29; // eax
  int v30; // ecx
  _DWORD *v31; // eax
  int v32; // edx
  int v33; // ecx
  int v34; // eax
  int v35; // eax
  int v36; // edx
  int v37; // ecx
  int v38; // edx
  int v39; // esi
  int v40; // esi
  _DWORD *v41; // ecx
  int v42; // edi
  int v43; // eax
  int v44; // eax
  int v45; // ecx
  int result; // eax
  int k; // ebx
  int v48; // edx
  int v49; // esi
  int v50; // edi
  int v51; // [esp+10h] [ebp-A30h]
  int i; // [esp+14h] [ebp-A2Ch]
  int v53; // [esp+14h] [ebp-A2Ch]
  int v54; // [esp+18h] [ebp-A28h]
  int v55; // [esp+18h] [ebp-A28h]
  int v56; // [esp+1Ch] [ebp-A24h]
  int v57; // [esp+1Ch] [ebp-A24h]
  int v58; // [esp+20h] [ebp-A20h]
  _BYTE *v59; // [esp+24h] [ebp-A1Ch]
  _BYTE *v60; // [esp+28h] [ebp-A18h]
  int v61; // [esp+30h] [ebp-A10h]
  int v62; // [esp+34h] [ebp-A0Ch]
  _DWORD v64[512]; // [esp+40h] [ebp-A00h] BYREF
  _DWORD v65[128]; // [esp+840h] [ebp-200h] BYREF

  v1 = this;
  v2 = this[4] + this[2] + this[6];
  v51 = v2;
  for ( i = 0; i < 2; ++i )
  {
    if ( i == 1 )
    {
      v60 = (_BYTE *)OperatorNewNhMallocWrapper(4 * v58);
      v59 = (_BYTE *)OperatorNewNhMallocWrapper(4 * v58);
    }
    v3 = 0;
    v58 = 0;
    if ( v2 > 0 )
    {
      v4 = 0;
      v62 = 0;
      while ( 1 )
      {
        v5 = v1[2];
        if ( v3 < v5 )
          break;
        v7 = v1[4];
        if ( v3 >= v5 + v7 )
        {
          v6 = v1[7] + 72 * (v3 - v5 - v7);
          goto LABEL_11;
        }
        v8 = 48 * (v3 - v5) + v1[5];
        v61 = *(_DWORD *)(v8 + 4);
        v56 = *(_DWORD *)(v8 + 12);
LABEL_12:
        v9 = v3 + 1;
        if ( v3 + 1 < v2 )
        {
          v10 = (int *)&v59[4 * v58];
          v54 = v4 + 48;
          do
          {
            v11 = v1[2];
            if ( v9 >= v11 )
            {
              v13 = v1[4];
              if ( v9 >= v11 + v13 )
                v12 = v1[7] + 72 * (v9 - v11 - v13);
              else
                v12 = 48 * (v9 - v11) + v1[5];
            }
            else
            {
              v12 = v1[3] + v54;
            }
            v14 = *(_DWORD *)(v12 + 4);
            v15 = *(_DWORD *)(v12 + 12);
            if ( v61 == v14 || v61 == v15 || v56 == v14 || v56 == v15 )
            {
              if ( i == 1 )
              {
                *(int *)((char *)v10 + v60 - v59) = v3;
                *v10 = v9;
              }
              ++v58;
              ++v10;
            }
            ++v9;
            v54 += 48;
          }
          while ( v9 < v51 );
          v9 = v3 + 1;
          v4 = v62;
          v2 = v51;
        }
        v3 = v9;
        v4 += 48;
        v62 = v4;
        if ( v9 >= v2 )
          goto LABEL_29;
      }
      v6 = v1[3] + v4;
LABEL_11:
      v61 = *(_DWORD *)(v6 + 4);
      v56 = *(_DWORD *)(v6 + 12);
      goto LABEL_12;
    }
LABEL_29:
    ;
  }
  v16 = 0;
  if ( v2 > 0 )
  {
    v17 = v1[2];
    do
    {
      v64[v16] = v16;
      v65[v16] = v16;
      v64[v16 + 128] = v16;
      if ( v16 >= v17 )
        v18 = (v16 < v17 + v1[4]) + 1;
      else
        v18 = 3;
      v64[v16++ + 384] = v18;
    }
    while ( v16 < v2 );
  }
  v19 = 0;
  for ( j = 0; j < v2; ++j )
  {
    v21 = v64[v64[j + 128] + 384];
    v64[v64[j + 128] + 256] = v19;
    v19 += v21;
  }
  v22 = v58;
  v23 = 0;
  v55 = 0;
  if ( v58 > 0 )
  {
    v24 = v60;
    do
    {
      v25 = v64[*v24 + 256] - v64[*(_DWORD *)((char *)v24 + v59 - v60) + 256];
      ++v24;
      v23 += v25 * v25;
      --v22;
    }
    while ( v22 );
    v55 = v23;
  }
  do
  {
    v26 = v51;
    v27 = 0;
    v57 = 0;
    if ( v51 <= 0 )
      goto LABEL_65;
    do
    {
      v28 = 0;
      v53 = 0;
      do
      {
        while ( !v28 )
        {
          v29 = v64[v27];
          if ( v29 <= 0 )
            goto LABEL_61;
          v30 = v64[v29 + 127];
          v31 = &v64[v29 + 128];
          *v31 = v30;
          v32 = v30;
          v33 = v64[v30];
          *(v31 - 1) = v27;
          v64[v32] = v33 + 1;
          v34 = v64[v27] - 1;
LABEL_50:
          v37 = 0;
          v64[v27] = v34;
          v38 = 0;
          do
          {
            v39 = v64[v64[v38 + 128] + 384];
            v64[v64[v38 + 128] + 256] = v37;
            v37 += v39;
            ++v38;
          }
          while ( v38 < v26 );
          v40 = 0;
          if ( v58 > 0 )
          {
            v41 = v60;
            v42 = v58;
            do
            {
              v43 = v64[*v41 + 256] - v64[*(_DWORD *)((char *)v41 + v59 - v60) + 256];
              ++v41;
              v40 += v43 * v43;
              --v42;
            }
            while ( v42 );
            v1 = this;
            v26 = v51;
          }
          if ( v40 >= v55 )
          {
            v44 = 0;
            do
            {
              v45 = v65[v44];
              v64[v44] = v45;
              v64[v45 + 128] = v44++;
            }
            while ( v44 < v26 );
            v28 = v53;
            goto LABEL_61;
          }
          v55 = v40;
          qmemcpy(v65, v64, 4 * v26);
          v26 = v51;
          v28 = v53;
          ++v57;
        }
        if ( v28 == 1 )
        {
          v35 = v64[v27];
          if ( v35 < v26 - 1 )
          {
            v36 = v64[v35 + 129];
            v64[v35 + 128] = v36;
            v64[v35 + 129] = v27;
            --v64[v36];
            v34 = v64[v27] + 1;
            goto LABEL_50;
          }
        }
LABEL_61:
        v53 = ++v28;
      }
      while ( v28 < 2 );
      ++v27;
    }
    while ( v27 < v26 );
  }
  while ( v57 > 0 );
  v26 = v51;
LABEL_65:
  FreeWrapper_7bcf(v60);
  FreeWrapper_7bcf(v59);
  result = 0;
  for ( k = 0; k < v26; ++k )
  {
    v48 = v64[k + 128];
    v49 = v1[2];
    if ( v48 >= v49 )
    {
      v50 = v1[4];
      if ( v48 >= v49 + v50 )
        *(_DWORD *)(v1[7] + 72 * (v48 - v49 - v50) + 68) = result;
      else
        *(_DWORD *)(48 * (v48 - v49) + v1[5] + 44) = result;
      v26 = v51;
    }
    else
    {
      *(_DWORD *)(48 * v48 + v1[3] + 44) = result;
    }
    result += v64[v48 + 384];
  }
  return result;
}
