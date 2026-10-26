int __fastcall sub_534F90(int a1, int a2, int a3)
{
  int v4; // esi
  int v5; // eax
  unsigned int v8; // eax
  int v9; // eax
  int v10; // edx
  int v11; // eax
  int v12; // eax
  int v13; // edx
  int v14; // esi
  int v15; // edi
  int v16; // eax
  int v17; // ecx
  int v18; // esi
  int v19; // edx
  unsigned int v20; // ecx
  int v21; // eax
  int v22; // ebx
  int v23; // ecx
  int v24; // [esp+10h] [ebp-8h]
  int v26; // [esp+1Ch] [ebp+4h]

  v4 = a2;
  if ( !a1 || *(_BYTE *)(a1 + 92) != 114 )
    return -2;
  v5 = *(_DWORD *)(a1 + 56);
  if ( v5 == -3 || v5 == -1 )
    return -1;
  if ( v5 == 1 )
    return 0;
  v24 = a2;
  *(_DWORD *)(a1 + 12) = a2;
  *(_DWORD *)(a1 + 16) = a3;
  if ( a3 )
  {
    while ( 1 )
    {
      v8 = *(_DWORD *)(a1 + 4);
      if ( *(_DWORD *)(a1 + 88) )
        break;
      if ( !v8 && !*(_DWORD *)(a1 + 60) )
      {
        *(_DWORD *)TLSOffsetGetter() = 0;
        v9 = ThreadSafeReadWrapper_803f(*(_DWORD *)(a1 + 68), 1, 0x4000, *(_DWORD *)(a1 + 64));
        *(_DWORD *)(a1 + 4) = v9;
        if ( !v9 )
        {
          v10 = *(_DWORD *)(a1 + 64);
          *(_DWORD *)(a1 + 60) = 1;
          if ( (*(_BYTE *)(v10 + 12) & 0x20) != 0 )
          {
            *(_DWORD *)(a1 + 56) = -1;
            goto LABEL_24;
          }
        }
        *(_DWORD *)a1 = *(_DWORD *)(a1 + 68);
      }
      v11 = sub_5357E0(a1, 0);
      *(_DWORD *)(a1 + 56) = v11;
      if ( v11 == 1 )
      {
        v12 = sub_536E90(*(_DWORD *)(a1 + 12) - v4);
        v13 = *(_DWORD *)(a1 + 12);
        *(_DWORD *)(a1 + 76) = v12;
        v26 = v13;
        if ( F_4BitFieldPack(a1) != *(_DWORD *)(a1 + 76) )
        {
          *(_DWORD *)(a1 + 56) = -3;
LABEL_23:
          v4 = v26;
          goto LABEL_24;
        }
        F_4BitFieldPack(a1);
        sub_534D50((int *)a1);
        if ( *(_DWORD *)(a1 + 56) )
          goto LABEL_23;
        v14 = *(_DWORD *)(a1 + 8);
        v15 = *(_DWORD *)(a1 + 20);
        ArithmeticComparison_5620(a1);
        *(_DWORD *)(a1 + 8) = v14;
        *(_DWORD *)(a1 + 20) = v15;
        *(_DWORD *)(a1 + 76) = sub_536E90(0);
        v4 = v26;
      }
      if ( *(_DWORD *)(a1 + 56) || *(_DWORD *)(a1 + 60) || !*(_DWORD *)(a1 + 16) )
        goto LABEL_24;
    }
    if ( v8 > *(_DWORD *)(a1 + 16) )
      v8 = *(_DWORD *)(a1 + 16);
    if ( v8 )
    {
      qmemcpy(*(void **)(a1 + 12), *(const void **)a1, v8);
      v18 = *(_DWORD *)a1;
      v19 = *(_DWORD *)(a1 + 16);
      v24 = v8 + a2;
      *(_DWORD *)(a1 + 12) = v8 + a2;
      v20 = *(_DWORD *)(a1 + 4) - v8;
      *(_DWORD *)a1 = v8 + v18;
      *(_DWORD *)(a1 + 16) = v19 - v8;
      *(_DWORD *)(a1 + 4) = v20;
    }
    v21 = *(_DWORD *)(a1 + 16);
    if ( v21 )
      *(_DWORD *)(a1 + 16) -= ThreadSafeReadWrapper_803f(v24, 1, v21, *(_DWORD *)(a1 + 64));
    v22 = a3 - *(_DWORD *)(a1 + 16);
    v23 = v22 + *(_DWORD *)(a1 + 20);
    *(_DWORD *)(a1 + 8) += v22;
    *(_DWORD *)(a1 + 20) = v23;
    if ( !v22 )
      *(_DWORD *)(a1 + 60) = 1;
    return v22;
  }
  else
  {
LABEL_24:
    v16 = sub_536E90(*(_DWORD *)(a1 + 12) - v4);
    v17 = *(_DWORD *)(a1 + 16);
    *(_DWORD *)(a1 + 76) = v16;
    return a3 - v17;
  }
}

