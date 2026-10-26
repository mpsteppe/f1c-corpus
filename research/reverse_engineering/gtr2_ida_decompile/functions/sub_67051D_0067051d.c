int __thiscall sub_67051D(int this, unsigned int a2, const void *a3)
{
  unsigned int v3; // esi
  unsigned int v5; // ecx
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // ecx
  int v10; // edx
  unsigned int v11; // edi
  int v12; // eax
  _DWORD *v13; // ecx
  int v14; // ecx
  int v15; // eax
  unsigned int v16; // eax
  int v17; // ecx
  _DWORD *v18; // ecx
  unsigned int v19; // edx
  int v20; // edi
  int result; // eax
  int v22; // eax
  unsigned int v23; // edi
  int v24; // eax
  unsigned int v25; // eax
  int v26; // ecx
  int v27; // eax
  unsigned int v28; // esi
  _DWORD *v29; // ecx
  int v30; // eax
  const void *v31; // esi
  unsigned int v32; // [esp+14h] [ebp-1Ch]
  int v33; // [esp+18h] [ebp-18h]
  unsigned int v34; // [esp+18h] [ebp-18h]
  _DWORD *v35; // [esp+1Ch] [ebp-14h]
  int v36; // [esp+1Ch] [ebp-14h]
  int v37; // [esp+20h] [ebp-10h]
  unsigned int v38; // [esp+20h] [ebp-10h]
  unsigned int v39; // [esp+24h] [ebp-Ch]
  int v40; // [esp+28h] [ebp-8h]
  int v41; // [esp+2Ch] [ebp-4h]

  v3 = a2;
  if ( !a2 || *(_DWORD *)(this + 80) || *(_DWORD *)(this + 84) )
    return 0;
  v5 = *(_DWORD *)(*(_DWORD *)(this + 8) + 12);
  v6 = *(_DWORD *)(a2 + 4);
  v32 = *(_DWORD *)(*(_DWORD *)(this + 8) + 12);
  if ( v6 == 6 )
  {
    v7 = *(_DWORD *)(a2 + 16);
    if ( v7 == 1 )
    {
      v8 = *(_DWORD *)(a2 + 24);
      a2 = *(_DWORD *)(v8 + 16);
      v39 = *(_DWORD *)(v8 + 20);
      v9 = *(_DWORD *)(v8 + 24);
      if ( v9 || (v40 = 1, (*(_BYTE *)(v8 + 28) & 0x40) == 0) )
        v40 = 0;
      if ( !v9 || (v37 = 1, (*(_BYTE *)(v8 + 28) & 2) == 0) )
        v37 = 0;
      v35 = *(_DWORD **)(v8 + 32);
      v10 = *(_DWORD *)(v8 + 28) & 0x80;
      v33 = *(_DWORD *)(v8 + 48);
      v11 = a2;
      *(_DWORD *)(v8 + 28) &= 0xFFFFF3FF;
LABEL_15:
      if ( v10 )
      {
        sub_6714D6(*(_DWORD *)(*(_DWORD *)(v3 + 24) + 40), *(_DWORD *)(this + 24) + 4 * v11, 0);
        goto LABEL_72;
      }
      a2 = 0;
      if ( v39 )
      {
        v41 = 4 * v11;
        do
        {
          if ( !v37 || *(_DWORD *)(v41 + *(_DWORD *)(this + 24)) == -1 )
          {
            v14 = *(_DWORD *)(this + 8);
            if ( v40 )
              v15 = *(_DWORD *)(v14 + 124);
            else
              v15 = *(_DWORD *)(v14 + 116);
            v16 = sub_681AAA(v15, 0, 0, 0.0);
            v17 = *(_DWORD *)(this + 8);
            if ( v16 >= *(_DWORD *)(v17 + 8) )
              v18 = 0;
            else
              v18 = *(_DWORD **)(*(_DWORD *)(v17 + 20) + 4 * v16);
            if ( v18 )
            {
              v18[12] = v11 + a2;
              v19 = a2;
              v18[24] = v3;
              v18[25] = v19;
            }
            *(_DWORD *)(v41 + *(_DWORD *)(this + 24)) = v16;
          }
          ++a2;
          v41 += 4;
        }
        while ( a2 < v39 );
      }
      if ( v40 )
      {
        v20 = 4 * v11;
        result = sub_664A09((_DWORD *)this, v35, v20 + *(_DWORD *)(this + 24), v39);
        if ( result < 0 )
          return result;
        result = sub_666E91(
                   (_DWORD *)this,
                   v35,
                   (unsigned int *)(v20 + *(_DWORD *)(this + 24)),
                   *(_DWORD *)(*(_DWORD *)(this + 8) + 124),
                   1,
                   0,
                   0,
                   v33);
        if ( result < 0 )
          return result;
        result = sub_66264A((_DWORD *)this, *(_DWORD *)(v3 + 24));
        goto LABEL_35;
      }
      goto LABEL_72;
    }
    if ( v7 == 2 )
    {
      v12 = *(_DWORD *)(a2 + 24);
      v11 = *(_DWORD *)(v12 + 16);
      v39 = *(_DWORD *)(v12 + 20);
      v13 = *(_DWORD **)(v12 + 32);
      v10 = 0;
      *(_BYTE *)(v12 + 25) &= 0xF3u;
      v35 = v13;
      v40 = 0;
      v37 = 0;
      v33 = *(_DWORD *)(v12 + 52);
      goto LABEL_15;
    }
    return 0;
  }
  if ( v6 != 12 )
  {
    if ( v6 != 1 )
    {
      sub_663C07((_DWORD *)this, 0, 0, "internal error: unrecognized statement");
      return -2147467259;
    }
    do
    {
      if ( *(_DWORD *)(this + 80) || *(_DWORD *)(this + 84) )
        break;
      result = sub_67051D(*(_DWORD *)(v3 + 8), 0);
      if ( result < 0 )
        return result;
      v3 = *(_DWORD *)(v3 + 12);
    }
    while ( v3 );
    goto LABEL_72;
  }
  v22 = *(_DWORD *)(a2 + 16);
  if ( v22 < 0 )
    goto LABEL_72;
  if ( v22 > 1 )
  {
    if ( v22 == 2 )
    {
      a2 = -1;
      result = sub_6714D6(*(_DWORD *)(v3 + 24), (int)&a2, 0);
      if ( result < 0 )
        return result;
      result = sub_667428(this, *(_DWORD **)(v3 + 24), a2, *(_DWORD *)(v3 + 28), *(_DWORD **)(v3 + 32));
    }
    else if ( v22 == 3 )
    {
      result = sub_6703EF(this, (_DWORD *)a2, *(_DWORD *)(a2 + 20), *(_DWORD **)(a2 + 24), *(_DWORD *)(a2 + 28));
    }
    else if ( v22 == 4 )
    {
      result = sub_6703EF(this, (_DWORD *)a2, 0, *(_DWORD **)(a2 + 24), *(_DWORD *)(a2 + 28));
    }
    else
    {
      if ( v22 != 5 )
      {
        if ( v22 == 6 )
        {
          result = sub_666ADA((_DWORD *)this, *(_DWORD *)(a2 + 24), (_DWORD *)(this + 40), 1u);
          if ( result < 0 )
            return result;
          *(_DWORD *)(this + 84) = 1;
        }
        goto LABEL_72;
      }
      result = sub_6703EF(this, (_DWORD *)a2, *(_DWORD *)(a2 + 28), *(_DWORD **)(a2 + 24), *(_DWORD *)(a2 + 28));
    }
LABEL_35:
    if ( result < 0 )
      return result;
    goto LABEL_72;
  }
  v23 = v5;
  result = sub_6714D6(*(_DWORD *)(a2 + 20), 0, 0);
  if ( result < 0 )
    return result;
  v24 = *(_DWORD *)(this + 8);
  v36 = 0;
  v34 = 0;
  v38 = *(_DWORD *)(v24 + 12);
  if ( v23 < v38 )
  {
    a2 = *(_DWORD *)(v24 + 24) + 4 * v23;
    v25 = *(_DWORD *)(*(_DWORD *)(this + 8) + 12) - v23;
    do
    {
      if ( *(_DWORD *)(*(_DWORD *)a2 + 56) == *(_DWORD *)(this + 56) )
      {
        v26 = *(_DWORD *)(*(_DWORD *)a2 + 60);
        if ( v26 )
        {
          if ( *(_DWORD *)(v26 + 4) == 13 && *(_DWORD *)(v26 + 68) >= v34 )
          {
            v36 = *(_DWORD *)(*(_DWORD *)a2 + 60);
            v34 = *(_DWORD *)(v26 + 68);
          }
        }
      }
      a2 += 4;
      --v25;
    }
    while ( v25 );
  }
  if ( v23 < v38 )
  {
    do
    {
      v27 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 24) + 4 * v23);
      if ( *(_DWORD *)(v27 + 56) == *(_DWORD *)(this + 56) )
        *(_DWORD *)(v27 + 60) = v36;
      ++v23;
    }
    while ( v23 < *(_DWORD *)(*(_DWORD *)(this + 8) + 12) );
  }
  *(_DWORD *)(this + 80) = *(_DWORD *)(v3 + 16) == 1;
LABEL_72:
  if ( !*(_DWORD *)(this + 84) || !a3 )
    return 0;
  v28 = v32;
  a2 = 0;
  while ( 1 )
  {
    v30 = *(_DWORD *)(this + 8);
    if ( v28 >= *(_DWORD *)(v30 + 12) )
      break;
    v29 = *(_DWORD **)(*(_DWORD *)(v30 + 24) + 4 * v28);
    if ( (*v29 & 0xFFF00000) == 0x11000000 )
      a2 = v29[15];
    sub_66238F(v29, 1);
    *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 8) + 24) + 4 * v28++) = 0;
  }
  v31 = a3;
  *(_DWORD *)(v30 + 12) = v32;
  qmemcpy(*(void **)(this + 24), v31, 4 * *(_DWORD *)(*(_DWORD *)(this + 4) + 24));
  result = sub_666ADA((_DWORD *)this, a2, (_DWORD *)(this + 40), 1u);
  if ( result >= 0 )
    return 0;
  return result;
}
