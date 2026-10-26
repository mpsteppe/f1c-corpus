int __thiscall sub_684000(_DWORD *this, int a2)
{
  unsigned int v3; // eax
  int v6; // ecx
  int v7; // edx
  _DWORD *v8; // eax
  _DWORD *v9; // ecx
  int v10; // edx
  int v11; // eax
  int v12; // ebx
  unsigned int v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // eax
  int v17; // ebx
  unsigned int v18; // eax
  int v19; // [esp+14h] [ebp-4Ch]
  int v20; // [esp+14h] [ebp-4Ch]
  int v21; // [esp+18h] [ebp-48h]
  int v22; // [esp+1Ch] [ebp-44h]
  int v23; // [esp+20h] [ebp-40h]
  int v24; // [esp+24h] [ebp-3Ch]
  int v25; // [esp+28h] [ebp-38h]
  int v26; // [esp+2Ch] [ebp-34h]
  int v27; // [esp+30h] [ebp-30h]
  _DWORD *v28; // [esp+34h] [ebp-2Ch]
  _DWORD *v29; // [esp+34h] [ebp-2Ch]
  _DWORD *v30; // [esp+38h] [ebp-28h]
  _DWORD *v31; // [esp+38h] [ebp-28h]
  unsigned int v32; // [esp+3Ch] [ebp-24h]
  unsigned int v33; // [esp+3Ch] [ebp-24h]
  unsigned int v34; // [esp+3Ch] [ebp-24h]
  int v35; // [esp+40h] [ebp-20h]
  int v36; // [esp+40h] [ebp-20h]
  int v37; // [esp+40h] [ebp-20h]
  int v38; // [esp+44h] [ebp-1Ch]
  unsigned int v39; // [esp+44h] [ebp-1Ch]
  int v40; // [esp+44h] [ebp-1Ch]
  unsigned int v41; // [esp+48h] [ebp-18h]
  unsigned int v42; // [esp+48h] [ebp-18h]
  unsigned int v43; // [esp+4Ch] [ebp-14h]
  unsigned int v44; // [esp+4Ch] [ebp-14h]
  unsigned int v45; // [esp+50h] [ebp-10h]
  unsigned int v46; // [esp+50h] [ebp-10h]
  int v47; // [esp+54h] [ebp-Ch]
  int v48; // [esp+54h] [ebp-Ch]
  unsigned int v49; // [esp+58h] [ebp-8h]
  unsigned int v50; // [esp+58h] [ebp-8h]
  unsigned int v51; // [esp+5Ch] [ebp-4h]
  unsigned int v52; // [esp+68h] [ebp+8h]

  v3 = *(_DWORD *)a2 & 0xFFFFF;
  v49 = v3;
  v45 = v3;
  v52 = 0;
  if ( !v3 )
    return 0;
  while ( 1 )
  {
    v51 = 0;
    if ( v45 <= 4 )
    {
      v51 = v45;
    }
    else if ( v3 )
    {
      v38 = 0;
      v32 = 1;
      v35 = 4 * v3;
      do
      {
        v6 = *(_DWORD *)(a2 + 8);
        if ( *(_DWORD *)(v6 + v38) != -1 )
        {
          v7 = this[5];
          v8 = *(_DWORD **)(v7 + 4 * *(_DWORD *)(v6 + v38));
          v9 = *(_DWORD **)(v7 + 4 * *(_DWORD *)(v6 + v35));
          v41 = 1;
          v43 = v32;
          if ( v32 < v49 )
          {
            v47 = v35 + 4;
            do
            {
              v10 = *(_DWORD *)(a2 + 8);
              if ( *(_DWORD *)(v10 + v47) != -1 )
              {
                v30 = *(_DWORD **)(this[5] + 4 * *(_DWORD *)(v10 + 4 * v43));
                v28 = *(_DWORD **)(this[5] + 4 * *(_DWORD *)(*(_DWORD *)(a2 + 8) + v47));
                if ( v8[1] == v30[1]
                  && v8[2] == v30[2]
                  && v8[3] == v30[3]
                  && v8[18] == v30[18]
                  && v9[1] == v28[1]
                  && v9[2] == v28[2]
                  && v9[3] == v28[3]
                  && v9[18] == v28[18]
                  && ++v41 == 4 )
                {
                  break;
                }
              }
              ++v43;
              v47 += 4;
            }
            while ( v43 < v49 );
          }
          if ( v41 > v51 )
          {
            v51 = v41;
            v27 = v8[1];
            v23 = v9[1];
            v26 = v8[2];
            v22 = v9[2];
            v25 = v8[3];
            v24 = v8[18];
            v21 = v9[3];
            v19 = v9[18];
          }
          if ( v51 == 4 )
            break;
          v3 = v49;
        }
        v38 += 4;
        v35 += 4;
        ++v32;
      }
      while ( v32 - 1 < v3 );
    }
    v11 = sub_681B0A(this, v51 & 0xFFFFF | 0x50000000, -1, -1);
    if ( v11 == -1 )
      return -2147024882;
    v12 = *(_DWORD *)(this[6] + 4 * v11);
    sub_680D22((_DWORD *)v12, a2);
    v13 = 0;
    v33 = 0;
    v39 = 0;
    if ( v49 )
    {
      v48 = 4 * v49;
      v36 = 4 * v51;
      do
      {
        if ( v33 >= v51 )
          break;
        v14 = *(_DWORD *)(a2 + 8);
        if ( *(_DWORD *)(v14 + 4 * v13) != -1 )
        {
          v29 = *(_DWORD **)(this[5] + 4 * *(_DWORD *)(v14 + 4 * v13));
          v31 = *(_DWORD **)(this[5] + 4 * *(_DWORD *)(*(_DWORD *)(a2 + 8) + v48));
          if ( v45 <= 4
            || v27 == v29[1]
            && v26 == v29[2]
            && v25 == v29[3]
            && v24 == v29[18]
            && v23 == v31[1]
            && v22 == v31[2]
            && v21 == v31[3]
            && v19 == v31[18] )
          {
            *(_DWORD *)(*(_DWORD *)(v12 + 8) + 4 * v33) = *(_DWORD *)(*(_DWORD *)(a2 + 8) + 4 * v13);
            *(_DWORD *)(v36 + *(_DWORD *)(v12 + 8)) = *(_DWORD *)(v48 + *(_DWORD *)(a2 + 8));
            v13 = v39;
            *(_DWORD *)(*(_DWORD *)(a2 + 8) + 4 * v39) = -1;
            *(_DWORD *)(v48 + *(_DWORD *)(a2 + 8)) = -1;
            ++v33;
            v36 += 4;
          }
        }
        v48 += 4;
        v39 = ++v13;
      }
      while ( v13 < v49 );
    }
    if ( v49 <= 4 )
    {
      **(_DWORD **)(v12 + 16) = **(_DWORD **)(a2 + 16);
    }
    else
    {
      **(_DWORD **)(v12 + 16) = sub_681AAA(this, this[34], -1, -1, 0.0);
      if ( **(_DWORD **)(v12 + 16) == -1 )
        return -2147024882;
      *(_DWORD *)(*(_DWORD *)(this[5] + 4 * **(_DWORD **)(v12 + 16)) + 20) = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * **(_DWORD **)(a2 + 16))
                                                                                       + 20);
      *(_DWORD *)(*(_DWORD *)(this[5] + 4 * **(_DWORD **)(v12 + 16)) + 24) = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * **(_DWORD **)(a2 + 16))
                                                                                       + 24);
    }
    v45 -= v51;
    ++v52;
    if ( !v45 )
    {
      if ( v52 <= 1 )
        return 0;
      v20 = sub_681AAA(this, this[30], -1, 0, 1.0);
      if ( v20 != -1 )
      {
        while ( 1 )
        {
          v42 = this[3] - v52;
          v44 = 0;
          if ( v52 )
            break;
LABEL_71:
          v52 = v44;
          if ( v44 <= 1 )
            return 0;
        }
        v34 = 0;
        while ( 1 )
        {
          v15 = v52 - v34;
          v50 = v52 - v34;
          if ( v52 - v34 > 4 )
          {
            v50 = 4;
            v15 = 4;
          }
          if ( v15 == 1 )
            v16 = sub_681B0A(this, 268435457, -1, -1);
          else
            v16 = v15 == 2 ? sub_681B0A(this, 541065217, -1, -1) : sub_681B0A(this, v15 & 0xFFFFF | 0x50000000, -1, -1);
          if ( v16 == -1 )
            break;
          v17 = *(_DWORD *)(this[6] + 4 * v16);
          sub_680D22((_DWORD *)v17, a2);
          v18 = 0;
          v46 = 0;
          if ( v50 )
          {
            v40 = 4 * v50;
            v37 = 4 * v42;
            do
            {
              *(_DWORD *)(*(_DWORD *)(v17 + 8) + 4 * v18) = **(_DWORD **)(*(_DWORD *)(v37 + this[6]) + 16);
              if ( v50 > 2 )
                *(_DWORD *)(v40 + *(_DWORD *)(v17 + 8)) = v20;
              v37 += 4;
              v40 += 4;
              v18 = ++v46;
            }
            while ( v46 < v50 );
          }
          if ( v52 <= 4 )
          {
            **(_DWORD **)(v17 + 16) = **(_DWORD **)(a2 + 16);
          }
          else
          {
            **(_DWORD **)(v17 + 16) = sub_681AAA(this, this[34], -1, -1, 0.0);
            if ( **(_DWORD **)(v17 + 16) == -1 )
              return -2147024882;
            *(_DWORD *)(*(_DWORD *)(this[5] + 4 * **(_DWORD **)(v17 + 16)) + 20) = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * **(_DWORD **)(a2 + 16))
                                                                                             + 20);
            *(_DWORD *)(*(_DWORD *)(this[5] + 4 * **(_DWORD **)(v17 + 16)) + 24) = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * **(_DWORD **)(a2 + 16))
                                                                                             + 24);
          }
          v42 += v50;
          v34 += 4;
          ++v44;
          if ( v34 >= v52 )
            goto LABEL_71;
        }
      }
      return -2147024882;
    }
    v3 = v49;
  }
}
