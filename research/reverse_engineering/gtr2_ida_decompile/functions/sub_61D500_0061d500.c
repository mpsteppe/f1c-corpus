int __thiscall sub_61D500(_DWORD *this)
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
  int v10; // ecx
  int *v11; // ebx
  int v12; // edx
  int v13; // edx
  int v14; // eax
  int v15; // esi
  int v16; // eax
  int v17; // eax
  int v18; // edx
  int v19; // eax
  int v20; // eax
  int v21; // edx
  int v22; // ecx
  int v23; // ecx
  int j; // edx
  int v25; // edi
  int v26; // esi
  int v27; // edi
  _DWORD *v28; // ecx
  int v29; // eax
  int v30; // edi
  int v31; // ebx
  int v32; // ecx
  int v33; // eax
  int v34; // ecx
  _DWORD *v35; // eax
  int v36; // eax
  int v37; // eax
  int v38; // edx
  int v39; // ecx
  int v40; // edx
  int v41; // esi
  int v42; // esi
  _DWORD *v43; // ecx
  int v44; // edi
  int v45; // eax
  int v46; // eax
  int v47; // ecx
  int result; // eax
  int k; // ebx
  int v50; // edx
  int v51; // esi
  int v52; // edi
  int v53; // [esp+10h] [ebp-A30h]
  int i; // [esp+14h] [ebp-A2Ch]
  int v55; // [esp+14h] [ebp-A2Ch]
  int v56; // [esp+18h] [ebp-A28h]
  int v57; // [esp+18h] [ebp-A28h]
  int v58; // [esp+1Ch] [ebp-A24h]
  int v59; // [esp+1Ch] [ebp-A24h]
  int v60; // [esp+20h] [ebp-A20h]
  _BYTE *v61; // [esp+24h] [ebp-A1Ch]
  _BYTE *Block; // [esp+28h] [ebp-A18h]
  int v63; // [esp+30h] [ebp-A10h]
  int v64; // [esp+34h] [ebp-A0Ch]
  _DWORD v66[512]; // [esp+40h] [ebp-A00h] BYREF
  _DWORD v67[128]; // [esp+840h] [ebp-200h] BYREF

  v1 = this;
  v2 = this[2] + this[4] + this[6];
  v53 = v2;
  for ( i = 0; i < 2; ++i )
  {
    if ( i == 1 )
    {
      Block = operator new(4 * v60);
      v61 = operator new(4 * v60);
    }
    v3 = 0;
    v60 = 0;
    if ( v2 > 0 )
    {
      v4 = 0;
      v64 = 0;
      while ( 1 )
      {
        v5 = v1[2];
        if ( v3 < v5 )
          break;
        v7 = v1[4];
        if ( v3 >= v5 + v7 )
        {
          v6 = 80 * (v3 - v5 - v7) + v1[7];
          goto LABEL_11;
        }
        v8 = v3 - v5;
        v9 = v1[5];
        v8 *= 56;
        v63 = *(_DWORD *)(v8 + v9 + 4);
        v58 = *(_DWORD *)(v9 + v8 + 12);
LABEL_12:
        v10 = v3 + 1;
        if ( v3 + 1 < v2 )
        {
          v11 = (int *)&v61[4 * v60];
          v56 = v4 + 56;
          do
          {
            v12 = v1[2];
            if ( v10 >= v12 )
            {
              v15 = v1[4];
              v16 = v10 - v12;
              if ( v10 >= v12 + v15 )
              {
                v13 = v1[7];
                v14 = 80 * (v16 - v15);
              }
              else
              {
                v13 = v1[5];
                v14 = 56 * v16;
              }
            }
            else
            {
              v13 = v1[3];
              v14 = v56;
            }
            v17 = v13 + v14;
            v18 = *(_DWORD *)(v17 + 4);
            v19 = *(_DWORD *)(v17 + 12);
            if ( v63 == v18 || v63 == v19 || v58 == v18 || v58 == v19 )
            {
              if ( i == 1 )
              {
                *(int *)((char *)v11 + Block - v61) = v3;
                *v11 = v10;
              }
              ++v60;
              ++v11;
            }
            ++v10;
            v56 += 56;
          }
          while ( v10 < v53 );
          v10 = v3 + 1;
          v4 = v64;
          v2 = v53;
        }
        v3 = v10;
        v4 += 56;
        v64 = v4;
        if ( v10 >= v2 )
          goto LABEL_29;
      }
      v6 = v4 + v1[3];
LABEL_11:
      v63 = *(_DWORD *)(v6 + 4);
      v58 = *(_DWORD *)(v6 + 12);
      goto LABEL_12;
    }
LABEL_29:
    ;
  }
  v20 = 0;
  if ( v2 > 0 )
  {
    v21 = v1[2];
    do
    {
      v66[v20] = v20;
      v67[v20] = v20;
      v66[v20 + 128] = v20;
      if ( v20 >= v21 )
        v22 = (v20 < v21 + v1[4]) + 1;
      else
        v22 = 3;
      v66[v20++ + 384] = v22;
    }
    while ( v20 < v2 );
  }
  v23 = 0;
  for ( j = 0; j < v2; ++j )
  {
    v25 = v66[v66[j + 128] + 384];
    v66[v66[j + 128] + 256] = v23;
    v23 += v25;
  }
  v26 = v60;
  v27 = 0;
  v57 = 0;
  if ( v60 > 0 )
  {
    v28 = Block;
    do
    {
      v29 = v66[*v28 + 256] - v66[*(_DWORD *)((char *)v28 + v61 - Block) + 256];
      ++v28;
      v27 += v29 * v29;
      --v26;
    }
    while ( v26 );
    v57 = v27;
  }
  do
  {
    v30 = v53;
    v31 = 0;
    v59 = 0;
    if ( v53 <= 0 )
      goto LABEL_65;
    do
    {
      v32 = 0;
      v55 = 0;
      do
      {
        while ( !v32 )
        {
          v33 = v66[v31];
          if ( v33 <= 0 )
            goto LABEL_61;
          v34 = v66[v33 + 127];
          v35 = &v66[v33 + 128];
          *v35 = v34;
          *(v35 - 1) = v31;
          ++v66[v34];
          v36 = v66[v31] - 1;
LABEL_50:
          v39 = 0;
          v66[v31] = v36;
          v40 = 0;
          do
          {
            v41 = v66[v66[v40 + 128] + 384];
            v66[v66[v40 + 128] + 256] = v39;
            v39 += v41;
            ++v40;
          }
          while ( v40 < v30 );
          v42 = 0;
          if ( v60 > 0 )
          {
            v43 = Block;
            v44 = v60;
            do
            {
              v45 = v66[*v43 + 256] - v66[*(_DWORD *)((char *)v43 + v61 - Block) + 256];
              ++v43;
              v42 += v45 * v45;
              --v44;
            }
            while ( v44 );
            v1 = this;
            v30 = v53;
          }
          if ( v42 >= v57 )
          {
            v46 = 0;
            do
            {
              v47 = v67[v46];
              v66[v46] = v47;
              v66[v47 + 128] = v46++;
            }
            while ( v46 < v30 );
            v32 = v55;
            goto LABEL_61;
          }
          v57 = v42;
          qmemcpy(v67, v66, 4 * v30);
          v30 = v53;
          v32 = v55;
          ++v59;
        }
        if ( v32 == 1 )
        {
          v37 = v66[v31];
          if ( v37 < v30 - 1 )
          {
            v38 = v66[v37 + 129];
            v66[v37 + 128] = v38;
            v66[v37 + 129] = v31;
            --v66[v38];
            v36 = v66[v31] + 1;
            goto LABEL_50;
          }
        }
LABEL_61:
        v55 = ++v32;
      }
      while ( v32 < 2 );
      ++v31;
    }
    while ( v31 < v30 );
  }
  while ( v59 > 0 );
  v30 = v53;
LABEL_65:
  j__free(Block);
  j__free(v61);
  result = 0;
  for ( k = 0; k < v30; ++k )
  {
    v50 = v66[k + 128];
    v51 = v1[2];
    if ( v50 >= v51 )
    {
      v52 = v1[4];
      if ( v50 >= v51 + v52 )
        *(_DWORD *)(80 * (v50 - v51 - v52) + v1[7] + 72) = result;
      else
        *(_DWORD *)(56 * (v50 - v51) + v1[5] + 48) = result;
      v30 = v53;
    }
    else
    {
      *(_DWORD *)(56 * v50 + v1[3] + 48) = result;
    }
    result += v66[v50 + 384];
  }
  return result;
}
