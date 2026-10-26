int __thiscall sub_6A3C8C(_DWORD *this)
{
  _DWORD *v1; // ebx
  int *v2; // esi
  int v3; // ecx
  unsigned int v4; // edi
  int v5; // eax
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  _DWORD *v9; // esi
  _DWORD *v10; // edi
  int v11; // ecx
  int v12; // edx
  int v13; // edi
  int v14; // esi
  int v15; // eax
  unsigned int v16; // esi
  bool v17; // zf
  _DWORD *v18; // edi
  int v19; // ecx
  unsigned int v20; // edx
  _DWORD *v21; // esi
  int v22; // edi
  int v23; // eax
  int result; // eax
  unsigned int i; // eax
  unsigned int k; // esi
  int v27; // edx
  int v28; // edi
  unsigned int v29; // edi
  int v30; // esi
  int v31; // ecx
  unsigned int v32; // [esp-8h] [ebp-BCh]
  unsigned int v33; // [esp-4h] [ebp-B8h]
  _DWORD v34[12]; // [esp+Ch] [ebp-A8h] BYREF
  int v35; // [esp+3Ch] [ebp-78h] BYREF
  int v36; // [esp+40h] [ebp-74h]
  int v37; // [esp+44h] [ebp-70h]
  int v38; // [esp+48h] [ebp-6Ch]
  int v39; // [esp+4Ch] [ebp-68h] BYREF
  int v40; // [esp+50h] [ebp-64h]
  int v41; // [esp+54h] [ebp-60h]
  int v42; // [esp+58h] [ebp-5Ch]
  _DWORD v43[4]; // [esp+5Ch] [ebp-58h] BYREF
  _DWORD v44[4]; // [esp+6Ch] [ebp-48h] BYREF
  _DWORD v45[4]; // [esp+7Ch] [ebp-38h] BYREF
  int v46; // [esp+8Ch] [ebp-28h]
  int v47; // [esp+90h] [ebp-24h]
  unsigned int v48; // [esp+94h] [ebp-20h]
  int v49; // [esp+98h] [ebp-1Ch]
  unsigned int v50; // [esp+9Ch] [ebp-18h]
  unsigned int v51; // [esp+A0h] [ebp-14h]
  unsigned int v52; // [esp+A4h] [ebp-10h]
  unsigned int j; // [esp+A8h] [ebp-Ch]
  unsigned int v54; // [esp+ACh] [ebp-8h]
  int v55; // [esp+B0h] [ebp-4h]

  v1 = this;
  v2 = (int *)this[64];
  v3 = *v2;
  v4 = *v2 & 0xFFFFF;
  v49 = (int)v1;
  v50 = v4;
  if ( !v2 || !v3 )
    return 0;
  v5 = v2[1] / v4;
  v51 = 0;
  v54 = v5;
  if ( (v3 & 0xFFF00000) == 0x50000000 || v2[3] != v4 )
  {
    result = sub_681C03(v1, v2);
    if ( result < 0 )
      return result;
    *(_DWORD *)v1[64] = 0;
    return 0;
  }
  v6 = v1[50];
  v46 = 0;
  if ( (unsigned __int16)v6 != 260 )
  {
    if ( sub_6A32C7(v1, (int)v2) )
    {
      v7 = v2[3];
      if ( v7 )
      {
        v8 = v1[5];
        v9 = (_DWORD *)v2[4];
        do
        {
          if ( *(_DWORD *)(*(_DWORD *)(v8 + 4 * *v9) + 16) == 3 )
          {
            v51 = 1;
            v46 = 1;
          }
          ++v9;
          --v7;
        }
        while ( v7 );
      }
    }
  }
  v52 = 0;
  if ( v54 )
  {
    v48 = 0;
    v55 = (int)v34;
    do
    {
      v10 = (_DWORD *)v55;
      *(_DWORD *)v55 = -1;
      ++v10;
      j = 0;
      *v10++ = -1;
      *v10 = -1;
      v10[1] = -1;
      v35 = -1;
      v36 = -1;
      v37 = -1;
      v38 = -1;
      if ( v50 )
      {
        v11 = v1[64];
        v12 = v1[5];
        v13 = v1[4];
        v47 = v48;
        do
        {
          v14 = *(_DWORD *)(v12 + 4 * *(_DWORD *)(v47 + *(_DWORD *)(v11 + 8)));
          v15 = *(_DWORD *)(*(_DWORD *)(v12 + 4 * *(_DWORD *)(*(_DWORD *)(v11 + 16) + 4 * j)) + 16);
          if ( (*(_BYTE *)(*(_DWORD *)(v13 + 4 * *(_DWORD *)(v14 + 4)) + 5) & 1) != 0 )
            v34[4 * v52 + v15] = v15;
          else
            v34[4 * v52 + v15] = *(_DWORD *)(v14 + 16);
          *(&v35 + v15) = 0;
          ++j;
          v47 += 4;
        }
        while ( j < v50 );
        v1 = (_DWORD *)v49;
      }
      if ( !sub_6A326C(v55, &v35, 5u) )
        v51 = 1;
      ++v52;
      v55 += 16;
      v48 += 4 * v50;
    }
    while ( v52 < v54 );
  }
  v16 = 0;
  if ( !v51 )
  {
    result = sub_681C03(v1, (_DWORD *)v1[64]);
    goto LABEL_105;
  }
  v52 = 0;
  v49 = 0;
  if ( v50 != 4 )
  {
    if ( v50 == 3 )
    {
      v49 = -1;
      for ( i = 0; i < 4; ++i )
      {
        if ( v34[i] == -1 )
          v49 = i;
      }
      for ( j = 0; j < 4; ++j )
      {
        if ( v52 )
          goto LABEL_96;
        for ( k = 0; k < 4; ++k )
        {
          if ( v52 )
            break;
          if ( k != j )
          {
            v27 = v49;
            if ( k != v49 && j != v49 )
            {
              v35 = -1;
              v36 = -1;
              v37 = -1;
              v38 = -1;
              v39 = 0;
              v40 = 0;
              v41 = 0;
              v42 = 0;
              v28 = 4 * j;
              *(int *)((char *)&v35 + v28) = 0;
              *(&v35 + k) = 0;
              *(int *)((char *)&v39 + v28) = -1;
              *(&v39 + k) = -1;
              *(&v39 + v27) = -1;
              v29 = 0;
              v55 = 0;
              if ( v54 )
              {
                v51 = (unsigned int)v34;
                do
                {
                  if ( v55 )
                    break;
                  v55 = sub_6A326C(v51, &v35, 5u) == 0;
                  v51 += 16;
                  ++v29;
                }
                while ( v29 < v54 );
              }
              if ( !v38 && (!v35 || !v36 || !v37) && v46 )
                v55 = 1;
              if ( !v55 )
                v52 = 1;
            }
          }
        }
      }
      if ( v52 )
      {
LABEL_96:
        result = sub_6C5456(&v35, v54, 3);
        if ( result < 0 )
          return result;
        result = sub_6C5456(&v39, v54, 3);
        goto LABEL_98;
      }
    }
LABEL_100:
    v30 = 0;
    if ( v50 )
    {
      do
      {
        v31 = v1[5];
        v33 = v50;
        v32 = v54;
        v35 = -1;
        v36 = -1;
        v37 = -1;
        v38 = -1;
        *(&v35 + *(_DWORD *)(*(_DWORD *)(v31 + 4 * *(_DWORD *)(*(_DWORD *)(v1[64] + 16) + 4 * v30)) + 16)) = 0;
        result = sub_6C5456(&v35, v32, v33);
        if ( result < 0 )
          return result;
      }
      while ( ++v30 < v50 );
    }
LABEL_106:
    result = 0;
    *(_DWORD *)v1[64] = 0;
    return result;
  }
  v55 = 1;
  do
  {
    v35 = 0;
    v36 = 0;
    v37 = 0;
    v38 = 0;
    v39 = -1;
    v40 = -1;
    v41 = -1;
    v42 = -1;
    *(&v35 + v16) = -1;
    v17 = v54 == 0;
    *(&v39 + v16) = 0;
    v55 = 0;
    if ( !v17 )
    {
      v18 = v34;
      v51 = v54;
      do
      {
        if ( !sub_6A326C((int)v18, &v35, 5u) || !sub_6A326C((int)v18, &v35, 5u) )
          v55 = 1;
        v18 += 4;
        --v51;
      }
      while ( v51 );
    }
    if ( v46 && v16 != 3 )
      v55 = 1;
    if ( !v55 )
    {
      result = sub_6C5456(&v35, v54, 4);
      if ( result < 0 )
        return result;
      result = sub_6C5456(&v39, v54, 4);
LABEL_105:
      if ( result < 0 )
        return result;
      goto LABEL_106;
    }
    ++v16;
  }
  while ( v16 < 4 );
  v55 = 1;
  for ( j = 0; j < 4; ++j )
  {
    if ( !v55 )
      break;
    v19 = 0;
    v51 = 0;
    while ( 1 )
    {
      v20 = j;
      if ( v19 != j )
        break;
LABEL_58:
      v19 = ++v51;
      if ( v51 >= 4 )
        goto LABEL_61;
    }
    v35 = 0;
    v36 = 0;
    v37 = 0;
    v38 = 0;
    v39 = -1;
    v40 = -1;
    v41 = -1;
    v42 = -1;
    *(&v35 + j) = -1;
    *(&v35 + v19) = -1;
    v17 = v54 == 0;
    *(&v39 + v20) = 0;
    *(&v39 + v19) = 0;
    v55 = 0;
    v47 = 0;
    if ( !v17 )
    {
      v21 = v34;
      v48 = v54;
      while ( 1 )
      {
        v22 = sub_6A326C((int)v21, &v35, 5u);
        v23 = sub_6A326C((int)v21, &v39, 5u);
        if ( !v22 )
          break;
        if ( !v23 )
          goto LABEL_49;
LABEL_50:
        v21 += 4;
        if ( !--v48 )
          goto LABEL_51;
      }
      v47 = 1;
LABEL_49:
      v55 = 1;
      goto LABEL_50;
    }
LABEL_51:
    if ( v46 )
      v55 = 1;
    if ( v55 )
    {
      if ( !v47 && (!v46 || v38) )
      {
        v43[0] = v35;
        v43[1] = v36;
        v43[2] = v37;
        v43[3] = v38;
        memset(v44, 255, sizeof(v44));
        memset(v45, 255, sizeof(v45));
        v44[j] = 0;
        v45[v51] = 0;
        v49 = 1;
      }
      goto LABEL_58;
    }
    v52 = 1;
LABEL_61:
    ;
  }
  if ( !v52 )
  {
    if ( v49 )
    {
      v52 = 1;
      result = sub_6C5456(v43, v54, 4);
      if ( result < 0 )
        return result;
      result = sub_6C5456(v44, v54, 4);
      if ( result < 0 )
        return result;
      result = sub_6C5456(v45, v54, 4);
LABEL_98:
      if ( result < 0 )
        return result;
      if ( v52 )
        goto LABEL_106;
      goto LABEL_100;
    }
    goto LABEL_100;
  }
  result = sub_6C5456(&v35, v54, 4);
  if ( result >= 0 )
  {
    result = sub_6C5456(&v39, v54, 4);
    goto LABEL_98;
  }
  return result;
}
