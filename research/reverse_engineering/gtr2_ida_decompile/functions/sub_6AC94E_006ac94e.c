int __thiscall sub_6AC94E(_DWORD *this)
{
  unsigned int i; // eax
  unsigned int j; // edi
  int v4; // eax
  int v5; // eax
  unsigned int k; // edi
  int v7; // edx
  int v8; // ecx
  unsigned int v9; // ecx
  _DWORD *v10; // ecx
  int v11; // eax
  int result; // eax
  unsigned int v13; // edi
  unsigned int m; // ebx
  _DWORD *v15; // edx
  int v16; // eax
  int v17; // edx
  int v18; // ecx
  _DWORD *v19; // edi
  unsigned int v20; // edx
  int v21; // ecx
  bool v22; // zf
  _DWORD *v23; // eax
  unsigned int v24; // ecx
  bool v25; // zf
  _DWORD *v26; // eax
  _DWORD *v27; // ecx
  unsigned int v28; // eax
  int v29; // edi
  _DWORD *v30; // edx
  int v31; // eax
  int v32; // edx
  int v33; // ecx
  int v34; // ebx
  _DWORD *v35; // ecx
  unsigned int v36; // edi
  int v37; // edx
  int v38; // ecx
  unsigned int v39; // [esp+Ch] [ebp-14h] BYREF
  unsigned int v40; // [esp+10h] [ebp-10h] BYREF
  int v41; // [esp+14h] [ebp-Ch]
  int v42; // [esp+18h] [ebp-8h]
  int v43; // [esp+1Ch] [ebp-4h] BYREF

  for ( i = 0; i < this[3]; ++i )
    *(_DWORD *)(*(_DWORD *)(this[6] + 4 * i) + 40) = 0;
  for ( j = 0; j < 0x18; j += 4 )
  {
    v4 = *(_DWORD *)(j + this[140]);
    if ( v4 )
    {
      sub_6BB9EF(this[6], v4, 1);
      sub_6BBA35(this[6], *(_DWORD *)(j + this[140]), 2);
    }
    v5 = *(_DWORD *)(j + this[139]);
    if ( v5 )
      *(_DWORD *)(v5 + 40) = 1;
  }
  for ( k = 0; k < this[3]; ++k )
  {
    if ( !sub_6A2293(**(_DWORD **)(this[6] + 4 * k) & 0xFFF00000) && v8 != 1913651200 && v8 != 285212672 )
    {
      v9 = this[136];
      if ( v9 >= 0x200 )
        return -2147467259;
      if ( *(_DWORD *)(v7 + 40) == 1 )
      {
        *(_DWORD *)(this[139] + 4 * v9) = v7;
        ++this[136];
      }
    }
  }
  v10 = (_DWORD *)this[139];
  v41 = 1;
  if ( v10 && this[136] )
  {
    v11 = this[136];
    do
    {
      if ( *v10 )
        v41 = 0;
      ++v10;
      --v11;
    }
    while ( v11 );
  }
  v42 = 0;
LABEL_24:
  v43 = 0;
  result = sub_6A7376(this, &v43);
  if ( result < 0 )
    return result;
  sub_6AB8A9(this, this[139], 6u, this[136], &v40);
  v13 = 0;
  for ( m = 0; v13 < this[3]; ++v13 )
  {
    v15 = *(_DWORD **)(this[6] + 4 * v13);
    if ( v15 )
    {
      v16 = v15[10];
      if ( (v16 == 2 || !v16) && !sub_6A2293(*v15 & 0xFFF00000) && v18 != 285212672 && v18 != 1913651200 )
        dword_FBAA38[m++] = v17;
      if ( m >= 0x200 )
        return -2147024882;
    }
  }
  do
  {
LABEL_35:
    sub_6AB8A9(this, (int)dword_FBAA38, 0, m, &v39);
    if ( v39 + v43 < 8 && (v39 <= v40 || v42 || v41) )
    {
LABEL_77:
      if ( (unsigned int)++v42 >= 2 )
      {
        v34 = 0;
        if ( !this[3] )
          return 0;
        while ( 1 )
        {
          v35 = *(_DWORD **)(this[6] + 4 * v34);
          if ( !v35[10] )
            v35[10] = 2;
          v36 = this[137];
          if ( v36 >= 0x200 )
            break;
          if ( v35[10] == 2 && !sub_6A2293(*v35 & 0xFFF00000) && v37 != 285212672 && v37 != 1913651200 )
          {
            *(_DWORD *)(this[140] + 4 * v36) = v38;
            ++this[137];
          }
          if ( (unsigned int)++v34 >= this[3] )
            return 0;
        }
        return -2147467259;
      }
      goto LABEL_24;
    }
    v43 = 0;
    if ( !this[3] )
      goto LABEL_64;
    while ( 1 )
    {
      v19 = *(_DWORD **)(this[6] + 4 * v43);
      if ( v19[10] || sub_6A2293(*v19 & 0xFFF00000) || v21 == 1913651200 )
        goto LABEL_60;
      v22 = v20 == v19[1];
      if ( v20 < v19[1] )
      {
        v23 = (_DWORD *)v19[2];
        do
        {
          if ( *(_BYTE *)(*(_DWORD *)(this[5] + 4 * *v23) + 108) == 1 )
            break;
          ++v20;
          ++v23;
        }
        while ( v20 < v19[1] );
        v22 = v20 == v19[1];
      }
      if ( !v22 )
        goto LABEL_60;
      v24 = 0;
      if ( !v42 )
      {
        v25 = v19[3] == 0;
        if ( v19[3] )
        {
          v26 = (_DWORD *)v19[4];
          do
          {
            if ( *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v26) + 16) == 3 )
              break;
            ++v24;
            ++v26;
          }
          while ( v24 < v19[3] );
          v25 = v24 == v19[3];
        }
        if ( !v25 )
          goto LABEL_60;
      }
      if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)v19[4]) + 4)) + 4)
          & 0x20) != 0 )
        goto LABEL_60;
      v19[10] = 1;
      if ( !sub_6A7B78(this) && !sub_6A7CAC(v27, v19) )
        break;
      v19[10] = 0;
LABEL_60:
      if ( (unsigned int)++v43 >= this[3] )
        goto LABEL_64;
    }
    v28 = this[136];
    if ( v28 >= 0x200 )
      return -2147024882;
    *(_DWORD *)(this[139] + 4 * v28) = v19;
    ++this[136];
LABEL_64:
    if ( v43 == this[3] )
      goto LABEL_77;
    v43 = 0;
    result = sub_6A7376(this, &v43);
    if ( result < 0 )
      return result;
    sub_6AB8A9(this, this[139], 6u, this[136], &v40);
    v29 = 0;
    m = 0;
  }
  while ( !this[3] );
  while ( 1 )
  {
    v30 = *(_DWORD **)(this[6] + 4 * v29);
    if ( v30 )
    {
      v31 = v30[10];
      if ( (v31 == 2 || !v31) && !sub_6A2293(*v30 & 0xFFF00000) && v33 != 285212672 && v33 != 1913651200 )
        dword_FBAA38[m++] = v32;
      if ( m >= 0x200 )
        return -2147024882;
    }
    if ( (unsigned int)++v29 >= this[3] )
      goto LABEL_35;
  }
}
