int __thiscall sub_684750(_DWORD *this, unsigned int a2, _DWORD *a3, unsigned int a4, int *a5)
{
  int v6; // eax
  int v7; // ecx
  int v8; // edx
  _DWORD *v9; // eax
  bool v10; // zf
  unsigned int v11; // ecx
  int v12; // ecx
  int i; // esi
  int v14; // ecx
  _DWORD *v15; // esi
  int v16; // edi
  _DWORD *v17; // edx
  unsigned int v18; // ecx
  int v19; // esi
  int j; // ecx
  int v21; // esi
  _DWORD *v22; // esi
  unsigned int v23; // edi
  unsigned int k; // ecx
  int v25; // edx
  unsigned int v26; // edx
  unsigned int v27; // esi
  int v28; // eax
  _DWORD *v29; // edi
  int v30; // ecx
  int v31; // edx
  int v32; // esi
  int v33; // eax
  int v34; // eax
  int v35; // ecx
  int v36; // eax
  int v37; // ecx
  int v39; // eax
  _BYTE v40[16]; // [esp+14h] [ebp-3Ch] BYREF
  _DWORD v41[4]; // [esp+24h] [ebp-2Ch] BYREF
  _DWORD *v42; // [esp+34h] [ebp-1Ch]
  int v43; // [esp+38h] [ebp-18h]
  int v44; // [esp+3Ch] [ebp-14h]
  unsigned int v45; // [esp+40h] [ebp-10h]
  _DWORD *v46; // [esp+44h] [ebp-Ch]
  _DWORD *v47; // [esp+48h] [ebp-8h]
  int v48; // [esp+4Ch] [ebp-4h]

  v45 = -1;
  v6 = *(_DWORD *)(this[5] + 4 * **(_DWORD **)(*(_DWORD *)(this[6] + 4 * a2) + 16));
  v7 = *(_DWORD *)(v6 + 24);
  v43 = *(_DWORD *)(v6 + 20);
  v8 = *a3;
  v44 = v7;
  do
  {
    v9 = *(_DWORD **)(this[5] + 4 * v8);
    v10 = v9[4] == 0;
    v46 = v9;
    if ( v10 )
    {
      v11 = v9[18];
      if ( v11 == -1 || a2 > v11 )
      {
        v12 = v43;
        for ( i = v44; v12 != -1; v12 = *(_DWORD *)(v14 + 20) )
        {
          if ( v12 == v9[5] )
            break;
          v14 = *(_DWORD *)(this[5] + 4 * v12);
          i = *(_DWORD *)(v14 + 24);
        }
        if ( v12 == v9[5] && i == v9[6] )
        {
          v41[0] = v8;
          v48 = 1;
          if ( a4 > 1 )
          {
            v15 = a3 + 1;
            v47 = a3 + 1;
            v42 = (_DWORD *)((char *)v41 - (char *)a3);
            do
            {
              v16 = *v15;
              while ( 1 )
              {
                v17 = *(_DWORD **)(this[5] + 4 * v16);
                if ( v17[4] != v48 )
                  goto LABEL_25;
                v18 = v17[18];
                if ( v18 != -1 && a2 <= v18 )
                  goto LABEL_25;
                if ( v17[1] != v9[1] || v17[3] != v9[3] || v17[2] != v9[2] )
                  goto LABEL_25;
                v19 = v43;
                for ( j = v44; v19 != -1; v19 = *(_DWORD *)(v21 + 20) )
                {
                  if ( v19 == v17[5] )
                    break;
                  v21 = *(_DWORD *)(this[5] + 4 * v19);
                  j = *(_DWORD *)(v21 + 24);
                }
                if ( v19 == v17[5] && j == v17[6] )
                  break;
                v9 = v46;
                v15 = v47;
LABEL_25:
                v16 = v17[13];
                if ( v16 == *v15 )
                  goto LABEL_28;
              }
              v22 = v47;
              ++v48;
              *(_DWORD *)((char *)v47 + (_DWORD)v42) = v16;
              v15 = v22 + 1;
              v9 = v46;
              v47 = v15;
            }
            while ( v48 < a4 );
          }
LABEL_28:
          if ( v48 == a4 )
          {
            v23 = 0;
            for ( k = 0; k < a4; ++k )
            {
              v25 = 4 * v41[k];
              if ( *(_DWORD *)(*(_DWORD *)(v25 + this[5]) + 72) )
              {
                v26 = a2 - *(_DWORD *)(*(_DWORD *)(v25 + this[5]) + 72);
                v23 += v26 * v26;
              }
            }
            if ( v45 > v23 )
            {
              v45 = v23;
              qmemcpy(v40, v41, 4 * a4);
            }
          }
        }
      }
    }
    v8 = v9[13];
  }
  while ( v8 != *a3 );
  if ( v45 != -1 )
  {
    qmemcpy(a3, v40, 4 * a4);
    return 0;
  }
  v27 = sub_681B0A(this, a4 & 0xFFFFF | 0x10000000, -1, -1);
  v45 = v27;
  if ( v27 == -1 )
    return -2147024882;
  v28 = this[6];
  v29 = *(_DWORD **)(v28 + 4 * v27);
  sub_680D22(v29, *(_DWORD *)(v28 + 4 * a2));
  v48 = 0;
  if ( a4 )
  {
    while ( 1 )
    {
      v30 = v48;
      v31 = v29[2];
      v32 = 4 * v48;
      v42 = &a3[v48];
      *(_DWORD *)(4 * v48 + v31) = *v42;
      *(_DWORD *)(v32 + v29[4]) = sub_681AAA(this, this[34], *a5, v30, 0.0);
      v33 = v29[4];
      if ( *(_DWORD *)(v32 + v33) == -1 )
        return -2147024882;
      *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)(v32 + v33)) + 24) = v44;
      *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)(v32 + v29[4])) + 20) = v43;
      **(_DWORD **)(this[5] + 4 * *(_DWORD *)(v32 + v29[4])) = **(_DWORD **)(this[5] + 4 * *(_DWORD *)(v32 + v29[2]));
      v34 = this[5];
      v35 = *(_DWORD *)(v34 + 4 * *(_DWORD *)(v32 + v29[2]));
      v36 = *(_DWORD *)(v34 + 4 * *(_DWORD *)(v32 + v29[4]));
      v37 = *(_DWORD *)(v35 + 52);
      ++v48;
      *(_DWORD *)(v36 + 52) = v37;
      *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)(v32 + v29[2])) + 52) = *(_DWORD *)(v32 + v29[4]);
      *v42 = *(_DWORD *)(v32 + v29[4]);
      if ( v48 >= a4 )
      {
        v27 = v45;
        break;
      }
    }
  }
  while ( 1 )
  {
    v39 = this[6];
    if ( v27 <= a2 )
      break;
    *(_DWORD *)(v39 + 4 * v27) = *(_DWORD *)(v39 + 4 * v27 - 4);
    --v27;
  }
  *(_DWORD *)(v39 + 4 * v27) = v29;
  ++*a5;
  return 0;
}
