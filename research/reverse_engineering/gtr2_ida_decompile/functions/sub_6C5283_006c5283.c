int __thiscall sub_6C5283(_DWORD *this, int a2, _DWORD *a3, _DWORD *a4, int a5)
{
  _DWORD *v5; // ebx
  unsigned int v6; // esi
  unsigned int v7; // edx
  _DWORD *v8; // edi
  int v9; // edx
  unsigned int v10; // ebx
  unsigned int v11; // edx
  int v12; // ebx
  int v13; // ecx
  _DWORD *v14; // esi
  unsigned int v15; // eax
  int v16; // eax
  int v17; // edx
  unsigned int v18; // eax
  unsigned int v19; // esi
  _DWORD *v20; // edx
  unsigned int v21; // edx
  unsigned int v22; // eax
  int v23; // edx
  int v24; // eax
  unsigned int v26; // [esp+8h] [ebp-1Ch]
  unsigned int v27; // [esp+Ch] [ebp-18h]
  int v28; // [esp+10h] [ebp-14h]
  unsigned int v29; // [esp+14h] [ebp-10h]
  unsigned int v30; // [esp+14h] [ebp-10h]
  int v31; // [esp+18h] [ebp-Ch]
  unsigned int v32; // [esp+1Ch] [ebp-8h]
  _DWORD *v33; // [esp+20h] [ebp-4h]

  v5 = a3;
  v6 = *a3 & 0xFFFFF;
  v33 = this;
  v32 = v6;
  if ( !v6 )
    return 1;
  v7 = a3[1] / v6;
  v26 = v7;
  if ( !v7 )
    goto LABEL_46;
  v31 = 0;
  v8 = a4;
  v28 = a3[1] / v6;
  while ( 1 )
  {
    v9 = *(_DWORD *)(this[5] + 4 * *(_DWORD *)(v31 + v5[2]));
    v10 = *(_DWORD *)(v9 + 84);
    v11 = *(_DWORD *)(v9 + 72);
    v27 = v10;
    if ( v11 == -1 )
    {
LABEL_43:
      *v8 = 0;
      goto LABEL_44;
    }
    v12 = *(_DWORD *)(this[6] + 4 * v11);
    *v8 = v12;
    if ( v6 )
    {
      v13 = v31;
      v29 = v6;
      do
      {
        v14 = *(_DWORD **)(v33[5] + 4 * *(_DWORD *)(v13 + a3[2]));
        if ( v33[34] != v14[1] )
          *v8 = 0;
        if ( v14[15] )
          *v8 = 0;
        v15 = v14[20];
        if ( v15 > v11 && v15 < v27 )
          *v8 = 0;
        if ( v14[21] != v14[22] )
          *v8 = 0;
        v13 += 4;
        --v29;
      }
      while ( v29 );
    }
    if ( *v8 )
    {
      if ( a2 != *(_DWORD *)v12 )
        goto LABEL_43;
      if ( v32 )
      {
        v16 = v31;
        v30 = v32;
        do
        {
          if ( *(_DWORD *)(*(_DWORD *)(v33[5] + 4 * *(_DWORD *)(v16 + a3[2])) + 72) != v11 )
            *v8 = 0;
          v16 += 4;
          --v30;
        }
        while ( v30 );
      }
      if ( *v8 )
      {
        v17 = *(_DWORD *)v12 & 0xFFFFF;
        if ( *(_DWORD *)(v12 + 12) != v17 || *(_DWORD *)(v12 + 4) > (unsigned int)(a5 * v17) )
          goto LABEL_43;
        v18 = a3[1];
        v19 = 0;
        if ( v18 )
        {
          v20 = (_DWORD *)a3[2];
          do
          {
            if ( *v20 == **(_DWORD **)(v12 + 16) )
              break;
            ++v19;
            ++v20;
          }
          while ( v19 < v18 );
        }
        if ( v19 == v18 )
          goto LABEL_43;
        v21 = *(_DWORD *)(v12 + 12);
        if ( v21 > 1 )
        {
          if ( v21 != v32 || v19 + v32 > v18 )
            *v8 = 0;
          v22 = 0;
          if ( v32 )
          {
            v23 = 4 * v19;
            do
            {
              if ( *(_DWORD *)(*(_DWORD *)(v12 + 16) + 4 * v22) != *(_DWORD *)(v23 + a3[2]) )
                *v8 = 0;
              ++v22;
              v23 += 4;
            }
            while ( v22 < v32 );
          }
        }
      }
    }
LABEL_44:
    v6 = v32;
    v31 += 4 * v32;
    ++v8;
    if ( !--v28 )
      break;
    this = v33;
    v5 = a3;
  }
  v7 = v26;
LABEL_46:
  v24 = 0;
  if ( !v7 )
    return 1;
  while ( !a4[v24] )
  {
    if ( ++v24 >= v7 )
      return 1;
  }
  return 0;
}
