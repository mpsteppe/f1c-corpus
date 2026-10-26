int __thiscall sub_687F01(int this)
{
  _DWORD *v2; // ebx
  _DWORD *v3; // edi
  int v4; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // edx
  int v7; // edx
  int v8; // eax
  double v9; // st7
  int v10; // ecx
  unsigned int v11; // ecx
  unsigned int v12; // edi
  _DWORD *v13; // eax
  int v14; // eax
  int v16; // eax
  _DWORD *v17; // eax
  unsigned int v18; // ebx
  unsigned int v19; // edi
  _DWORD *v20; // ecx
  int v21; // eax
  int v22; // edx
  int v23; // ecx
  int v24; // edi
  int v25; // eax
  int v26; // edx
  int v27; // ecx
  int v28; // eax
  unsigned int v29; // edx
  int v30; // ecx
  int v31; // ecx
  int v32; // [esp+14h] [ebp-1Ch]
  int v33; // [esp+18h] [ebp-18h]
  int v34; // [esp+18h] [ebp-18h]
  int v35; // [esp+1Ch] [ebp-14h]
  int v36; // [esp+20h] [ebp-10h]
  int v37; // [esp+24h] [ebp-Ch]
  int v38; // [esp+24h] [ebp-Ch]
  int v39; // [esp+24h] [ebp-Ch]
  unsigned int v40; // [esp+28h] [ebp-8h]
  unsigned int v41; // [esp+2Ch] [ebp-4h]
  _DWORD *v42; // [esp+2Ch] [ebp-4h]
  unsigned int v43; // [esp+2Ch] [ebp-4h]

  v37 = 0;
  v36 = 0;
  v35 = 0;
  v40 = 0;
  if ( !*(_DWORD *)(this + 8) )
    return 1;
  do
  {
    v2 = *(_DWORD **)(*(_DWORD *)(this + 20) + 4 * v40);
    if ( *(_DWORD *)(this + 116) != v2[1] )
    {
      v3 = v2 + 2;
      if ( v2[2] != -1 )
      {
        if ( !v35 )
        {
          sub_686074(this);
          v35 = 1;
        }
        v4 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * *v3) + 72);
        v32 = *v3;
        if ( v4 != -1 )
        {
          v5 = *(_DWORD **)(*(_DWORD *)(this + 24) + 4 * v4);
          if ( (*v5 & 0xFFF00000) == 0x10000000 )
          {
            v41 = 0;
            if ( v5[3] )
            {
              v6 = (_DWORD *)v5[4];
              do
              {
                if ( *v6 == *v3 )
                  break;
                ++v41;
                ++v6;
              }
              while ( v41 < v5[3] );
            }
            v3 = (_DWORD *)(v5[2] + 4 * v41);
          }
        }
        v7 = *v3;
        v8 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * *v3);
        v42 = v3;
        if ( (*(_BYTE *)(this + 111) & 1) != 0 )
          v9 = 0.0;
        else
          v9 = 0.5;
        v10 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 16) + 4 * *(_DWORD *)(v8 + 4)) + 4);
        if ( (v10 & 0x100) != 0 && *(_DWORD *)(v8 + 8) == -1 )
        {
          v11 = *(_DWORD *)(this + 8);
          v43 = 0;
          v12 = v2[3] + (__int64)(v9 + *(double *)(v8 + 32));
          if ( v11 )
          {
            v38 = *(_DWORD *)(this + 20);
            while ( 1 )
            {
              if ( v43 != v40 )
              {
                v13 = *(_DWORD **)v38;
                if ( *(_DWORD *)(*(_DWORD *)v38 + 4) == v2[1]
                  && v13[2] == -1
                  && v13[3] == v12
                  && v13[4] == v2[4]
                  && v13[5] == v2[5]
                  && v13[6] == v2[6] )
                {
                  break;
                }
              }
              ++v43;
              v38 += 4;
              if ( v43 >= v11 )
                goto LABEL_32;
            }
            if ( !v36 )
            {
              sub_686606((_DWORD *)this);
              v36 = 1;
            }
            v2[12] = v43;
          }
LABEL_32:
          if ( v43 == *(_DWORD *)(this + 8) )
          {
            v2[2] = -1;
            v14 = v2[1];
            v2[3] = v12;
            if ( v12 >= *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 16) + 4 * v14) + 8) )
            {
              sub_686791(this, v2[24], 4007, "array index out of bounds");
              return -2147467259;
            }
          }
          goto LABEL_65;
        }
        if ( (v10 & 2) != 0 )
        {
          v16 = *(_DWORD *)(v8 + 72);
          if ( v16 != -1 )
          {
            v17 = *(_DWORD **)(*(_DWORD *)(this + 24) + 4 * v16);
            if ( (*v17 & 0xFFF00000) == 0x20400000 )
            {
              v18 = v17[3];
              v19 = 0;
              if ( v18 )
              {
                v20 = (_DWORD *)v17[4];
                do
                {
                  if ( *v20 == v7 )
                    break;
                  ++v19;
                  ++v20;
                }
                while ( v19 < v18 );
              }
              v21 = v17[2];
              v22 = *(_DWORD *)(v21 + 4 * v19);
              v23 = *(_DWORD *)(this + 20);
              v24 = *(_DWORD *)(v21 + 4 * (v19 + v18));
              v25 = *(_DWORD *)(this + 16);
              v33 = v22;
              v26 = *(_DWORD *)(v23 + 4 * v22);
              v27 = *(_DWORD *)(v23 + 4 * v24);
              if ( (*(_BYTE *)(*(_DWORD *)(v25 + 4 * *(_DWORD *)(v26 + 4)) + 5) & 1) != 0
                && *(_DWORD *)(v26 + 8) == -1
                && (*(_DWORD *)v26 & 4) != 0
                && ((*(_DWORD *)v26 & 2) != 0 || (*(_BYTE *)v27 & 2) != 0) )
              {
                v39 = (__int64)(v9 + *(double *)(v26 + 32));
                v28 = v24;
                goto LABEL_54;
              }
              if ( (*(_BYTE *)(*(_DWORD *)(v25 + 4 * *(_DWORD *)(v27 + 4)) + 5) & 1) != 0
                && *(_DWORD *)(v27 + 8) == -1
                && (*(_DWORD *)v27 & 4) != 0
                && ((*(_BYTE *)v26 & 2) != 0 || (*(_DWORD *)v27 & 2) != 0) )
              {
                v39 = (__int64)(v9 + *(double *)(v27 + 32));
                v28 = v33;
LABEL_54:
                v29 = 0;
                v34 = v28;
                if ( *v42 == v32 )
                {
                  if ( *(_DWORD *)(this + 8) )
                  {
                    do
                    {
                      v30 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * v29);
                      if ( v32 == *(_DWORD *)(v30 + 8) )
                      {
                        *(_DWORD *)(v30 + 12) += v39;
                        *(_DWORD *)(v30 + 8) = v28;
                      }
                      ++v29;
                    }
                    while ( v29 < *(_DWORD *)(this + 8) );
                  }
                }
                else
                {
                  if ( *(_DWORD *)(this + 8) )
                  {
                    do
                    {
                      v31 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * v29);
                      if ( v32 == *(_DWORD *)(v31 + 8) )
                      {
                        *(_DWORD *)(v31 + 12) += v39;
                        v28 = v34;
                      }
                      ++v29;
                    }
                    while ( v29 < *(_DWORD *)(this + 8) );
                  }
                  *v42 = v28;
                }
LABEL_65:
                v37 = 1;
              }
            }
          }
        }
      }
    }
    ++v40;
  }
  while ( v40 < *(_DWORD *)(this + 8) );
  if ( !v37 )
    return 1;
  if ( v36 )
    sub_68661F((_DWORD *)this);
  return 0;
}
