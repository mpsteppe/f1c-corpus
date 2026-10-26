int __thiscall sub_6A6F97(int this, int a2, int a3)
{
  int v3; // eax
  unsigned int i; // ecx
  int v6; // eax
  _DWORD *v7; // eax
  unsigned int v8; // edi
  unsigned int v9; // ecx
  int v10; // ecx
  unsigned int v11; // ecx
  unsigned int j; // edi
  _DWORD *v13; // edx
  unsigned int v14; // ecx
  _DWORD *v15; // eax
  int v16; // edx
  int v17; // ebx
  int v18; // eax
  unsigned int v19; // ecx
  double *v20; // ecx
  int v21; // ebx
  unsigned int v22; // eax
  bool v23; // zf
  unsigned int k; // eax
  int v25; // ecx
  int v26; // ecx
  _DWORD v28[6]; // [esp+14h] [ebp-58h] BYREF
  _DWORD v29[6]; // [esp+2Ch] [ebp-40h] BYREF
  _DWORD v30[6]; // [esp+44h] [ebp-28h] BYREF
  double *v31; // [esp+5Ch] [ebp-10h]
  unsigned int v32; // [esp+60h] [ebp-Ch]
  double *v33; // [esp+64h] [ebp-8h]
  unsigned int v34; // [esp+68h] [ebp-4h]
  int v35; // [esp+74h] [ebp+8h]
  int v36; // [esp+78h] [ebp+Ch]

  v3 = a2;
  for ( i = 0; i < 7; ++i )
  {
    if ( !v3 )
      break;
    v3 &= v3 - 1;
  }
  if ( i > 6 )
    return 0;
  v6 = *(_DWORD *)(this + 1152);
  if ( v6 - i > 6 )
    return 0;
  v34 = 0;
  v33 = 0;
  v32 = 0;
  if ( v6 )
  {
    v31 = (double *)(this + 1104);
    do
    {
      v7 = *(_DWORD **)(*(_DWORD *)(this + 24) + 4 * *(_DWORD *)v31);
      v8 = *v7 & 0xFFF00000;
      if ( ((1 << v32) & a2) != 0 )
      {
        if ( v7[9] == 1 )
          return 0;
        v9 = (unsigned int)v33;
        v33 = (double *)((char *)v33 + 1);
        v28[v9] = v7;
      }
      else
      {
        if ( v8 == 285212672 )
          return 0;
        if ( v8 != 1913651200 )
        {
          v10 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * *(_DWORD *)(v7[2] + 4 * (*v7 & 0xFFFFF)));
          if ( *(_BYTE *)(v10 + 108) != 3 || *(_DWORD *)(v10 + 60) )
            return 0;
        }
        v11 = v34++;
        v29[v11] = v7;
      }
      ++v32;
      v31 = (double *)((char *)v31 + 4);
    }
    while ( v32 < *(_DWORD *)(this + 1152) );
  }
  memset(v30, 0xFFu, sizeof(v30));
  if ( !sub_6A6DC1((_DWORD *)this, *(_DWORD *)(this + 556), v30, (int)v29, v34, 0)
    || !sub_6A6DC1((_DWORD *)this, *(_DWORD *)(this + 560), v30, (int)v28, (unsigned int)v33, 0)
    || !sub_6A6DC1((_DWORD *)this, *(_DWORD *)(this + 556), v30, (int)v29, v34, 1)
    || !sub_6A6DC1((_DWORD *)this, *(_DWORD *)(this + 560), v30, (int)v28, (unsigned int)v33, 1)
    || !sub_6A6DC1((_DWORD *)this, *(_DWORD *)(this + 556), v30, (int)v29, v34, 2)
    || !sub_6A6DC1((_DWORD *)this, *(_DWORD *)(this + 560), v30, (int)v28, (unsigned int)v33, 2) )
  {
    return 0;
  }
  if ( !a3 )
  {
    memset(v28, 0, sizeof(v28));
    memset(v29, 0, sizeof(v29));
    v36 = 0;
    for ( j = 0; j < 0x18; j += 4 )
    {
      v13 = *(_DWORD **)(j + *(_DWORD *)(this + 556));
      if ( v13 || *(_DWORD *)(j + *(_DWORD *)(this + 560)) )
      {
        v14 = 0;
        v31 = 0;
        if ( v13 )
          v14 = *v13 & 0xFFF00000;
        v15 = *(_DWORD **)(j + *(_DWORD *)(this + 560));
        if ( v15 )
          v31 = (double *)(*v15 & 0xFFF00000);
        v32 = sub_6A2293(v14);
        if ( v32 || sub_6A2293((int)v31) )
        {
          v35 = -1;
          if ( v32 )
          {
            v17 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * **(_DWORD **)(v16 + 8));
            v18 = sub_681AAA(
                    (void *)this,
                    *(_DWORD *)(v17 + 4),
                    *(_DWORD *)(v17 + 12),
                    *(_DWORD *)(v17 + 16),
                    *(double *)(v17 + 32));
            v35 = v18;
            if ( v18 == -1 )
              return 0;
            v19 = 0;
            if ( (**(_DWORD **)(j + *(_DWORD *)(this + 556)) & 0xFFFFF) != 0 )
            {
              do
                *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(j + *(_DWORD *)(this + 556)) + 8) + 4 * v19++) = v18;
              while ( v19 < (**(_DWORD **)(j + *(_DWORD *)(this + 556)) & 0xFFFFFu) );
            }
            v20 = *(double **)(*(_DWORD *)(this + 20) + 4 * v18);
            v28[j / 4] = v17;
            v33 = v20;
            sub_6815D6(v20, v17);
            *((_DWORD *)v33 + 3) = v36;
          }
          if ( sub_6A2293((int)v31) )
          {
            v21 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * **(_DWORD **)(*(_DWORD *)(j + *(_DWORD *)(this + 560)) + 8));
            if ( v35 == -1 )
            {
              v35 = sub_681AAA(
                      (void *)this,
                      *(_DWORD *)(v21 + 4),
                      *(_DWORD *)(v21 + 12),
                      *(_DWORD *)(v21 + 16),
                      *(double *)(v21 + 32));
              if ( v35 == -1 )
                return 0;
            }
            v22 = 0;
            if ( (**(_DWORD **)(j + *(_DWORD *)(this + 560)) & 0xFFFFF) != 0 )
            {
              do
                *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(j + *(_DWORD *)(this + 560)) + 8) + 4 * v22++) = v35;
              while ( v22 < (**(_DWORD **)(j + *(_DWORD *)(this + 560)) & 0xFFFFFu) );
            }
            v23 = v32 == 0;
            v29[j / 4] = v21;
            if ( v23 )
            {
              v31 = *(double **)(*(_DWORD *)(this + 20) + 4 * v35);
              sub_6815D6(v31, v21);
              *((_DWORD *)v31 + 3) = v36;
            }
          }
          if ( v35 == -1 )
            return 0;
        }
      }
      ++v36;
    }
    for ( k = 0; k < 6; ++k )
    {
      v25 = v28[k];
      if ( v25 )
        *(_DWORD *)(v25 + 4) = *(_DWORD *)(this + 116);
      v26 = v29[k];
      if ( v26 )
        *(_DWORD *)(v26 + 4) = *(_DWORD *)(this + 116);
    }
  }
  *(_DWORD *)(this + 544) = 6;
  *(_DWORD *)(this + 548) = 6;
  return 1;
}
