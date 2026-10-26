int __thiscall sub_685948(int this, int a2, int a3, int a4, int a5, int *a6, unsigned int a7)
{
  int v7; // ebx
  int v8; // esi
  bool v9; // zf
  unsigned int v10; // eax
  bool v11; // cc
  int v12; // esi
  unsigned int v13; // edi
  int v14; // esi
  unsigned int v15; // eax
  int v16; // eax
  int v17; // ecx
  int v18; // edi
  unsigned int v19; // ecx
  int v20; // eax
  int v21; // ebx
  int v22; // esi
  int v23; // eax
  int v25; // [esp+Ch] [ebp-48h]
  int v26; // [esp+10h] [ebp-44h]
  int v27; // [esp+14h] [ebp-40h]
  int v28; // [esp+18h] [ebp-3Ch]
  _DWORD v29[4]; // [esp+1Ch] [ebp-38h] BYREF
  unsigned int v30; // [esp+2Ch] [ebp-28h]
  int v31; // [esp+30h] [ebp-24h]
  unsigned int v32; // [esp+34h] [ebp-20h]
  int v33; // [esp+38h] [ebp-1Ch]
  int v34; // [esp+3Ch] [ebp-18h]
  _DWORD *v35; // [esp+40h] [ebp-14h]
  unsigned int v36; // [esp+44h] [ebp-10h]
  int *v37; // [esp+48h] [ebp-Ch]
  unsigned int v38; // [esp+4Ch] [ebp-8h]
  int v39; // [esp+50h] [ebp-4h]
  unsigned int v40; // [esp+60h] [ebp+Ch]
  int v41; // [esp+60h] [ebp+Ch]
  unsigned int v42; // [esp+68h] [ebp+14h]

  v7 = a2;
  v8 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * a3);
  v9 = *(_BYTE *)(v8 + 3) >= 0;
  v10 = *(_DWORD *)(*(_DWORD *)(a2 + 8) + 4 * *(_DWORD *)(v8 + 12));
  v35 = (_DWORD *)this;
  v33 = v8;
  v32 = v10;
  v38 = 4;
  if ( v9 )
  {
    v11 = v10 <= 1;
    if ( v10 != 1 )
      goto LABEL_5;
    if ( (*(_BYTE *)(this + 108) & 4) == 0 )
    {
      v11 = 1;
LABEL_5:
      if ( (v11 || (*(_BYTE *)(this + 108) & 2) == 0)
        && !sub_680D7E(*(_DWORD **)(*(_DWORD *)(this + 24) + 4 * *(_DWORD *)(v8 + 72))) )
      {
        goto LABEL_9;
      }
    }
  }
  v38 = 1;
LABEL_9:
  v12 = *(_DWORD *)(v8 + 12);
  memset(v29, 255, sizeof(v29));
  v25 = -1;
  v26 = -1;
  v27 = -1;
  v28 = -1;
  v13 = 0;
  v39 = 4;
  v40 = 0;
  v14 = 16 * v12;
  do
  {
    v31 = *(_DWORD *)(v14 + *(_DWORD *)(a2 + 24));
    v34 = 0;
    if ( v31 == -1 )
      goto LABEL_25;
    v15 = *(_DWORD *)(v14 + *(_DWORD *)(a2 + 48));
    v36 = 0;
    v30 = v15;
    if ( !v15 )
      goto LABEL_25;
    v37 = (int *)(*(_DWORD *)(a2 + 56) + 4 * *(_DWORD *)(v14 + *(_DWORD *)(a2 + 52)));
    while ( 1 )
    {
      v16 = *v37;
      v17 = *(_DWORD *)(*(_DWORD *)(a2 + 16) + 4 * ((unsigned int)*v37 >> 2));
      if ( v17 != -1 )
        v34 = 1;
      if ( a4 == v17 )
      {
        v18 = *(_DWORD *)(*(_DWORD *)(a2 + 20) + 4 * v16);
        if ( v18 != -1
          && v29[v18] == -1
          && (v38 != 1 || v40 == v18)
          && sub_68584A(v35, (_DWORD *)a2, v31, a4, v18) == -1 )
        {
          break;
        }
      }
      ++v36;
      ++v37;
      if ( v36 >= v30 )
        goto LABEL_24;
    }
    --v39;
    v29[v18] = v40;
    *(&v25 + v40) = v18;
LABEL_24:
    v13 = 0;
    if ( !v34 )
LABEL_25:
      --v39;
    ++v40;
    v14 += 4;
  }
  while ( v40 < 4 );
  v19 = v39 << 29;
  if ( v39 << 29 < a7 )
  {
    v20 = 0;
    if ( a5 >= 0 )
    {
      if ( a5 <= 0 || (a4 & 1) != 0 )
      {
LABEL_34:
        v19 |= v20 << 28;
        v42 = v19;
        if ( v19 < a7 )
        {
          do
          {
            if ( *(&v25 + v13) == -1 )
            {
              v41 = *(_DWORD *)(*(_DWORD *)(v7 + 24) + 4 * (v13 + 4 * *(_DWORD *)(v33 + 12)));
              if ( v41 != -1 )
              {
                v21 = 0;
                if ( v38 )
                {
                  while ( 1 )
                  {
                    v22 = ((_BYTE)v21 + (_BYTE)v13) & 3;
                    if ( v32 == 1 )
                    {
                      if ( (v35[28] & 2) == 0
                        || (v23 = **(_DWORD **)(v35[6] + 4 * *(_DWORD *)(v33 + 72)), (v23 & 0xFFF00000) != 0x50000000)
                        || (v23 & 0xFFFFFu) >= 4 )
                      {
                        v22 = 3 - v22;
                      }
                    }
                    if ( v29[v22] == -1 && sub_68584A(v35, (_DWORD *)a2, v41, a4, v22) == -1 )
                      break;
                    if ( ++v21 >= v38 )
                      goto LABEL_48;
                  }
                  v29[v22] = v13;
                  *(&v25 + v13) = v22;
                }
LABEL_48:
                if ( v38 == v21 )
                  return -1;
                if ( (*(_BYTE *)(a2 + 96) & 1) != 0 && v32 <= 1 )
                {
                  v19 = v42;
                }
                else
                {
                  v19 = (v21 << 24) + v42;
                  v42 = v19;
                  if ( v19 >= a7 )
                    return v19;
                }
                v7 = a2;
              }
            }
            ++v13;
          }
          while ( v13 < 4 );
          if ( a6 )
          {
            *a6 = v25;
            a6[1] = v26;
            a6[2] = v27;
            a6[3] = v28;
          }
        }
        return v19;
      }
    }
    else if ( (a4 & 1) == 0 )
    {
      goto LABEL_34;
    }
    v20 = 1;
    goto LABEL_34;
  }
  return v19;
}
