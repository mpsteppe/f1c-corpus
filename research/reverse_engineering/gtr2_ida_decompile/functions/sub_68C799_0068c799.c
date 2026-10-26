int __thiscall sub_68C799(int this)
{
  int v1; // edi
  int v3; // esi
  unsigned int i; // eax
  int v5; // ecx
  int v6; // edi
  int *v7; // eax
  int v8; // ecx
  unsigned int v9; // esi
  unsigned int v10; // edx
  unsigned int v11; // esi
  int v12; // ecx
  bool v13; // zf
  int v14; // eax
  int v15; // ecx
  int v16; // edx
  int v17; // edi
  int v18; // ecx
  unsigned int j; // eax
  unsigned int v21; // edx
  _DWORD *v22; // eax
  int v23; // ecx
  int v24; // edx
  unsigned int k; // ecx
  int v26; // eax
  unsigned int v27; // edx
  _DWORD *v28; // eax
  int v29; // ecx
  size_t v30; // [esp-4h] [ebp-80h]
  int v31; // [esp+60h] [ebp-1Ch] BYREF
  int v32; // [esp+64h] [ebp-18h]
  unsigned int v33; // [esp+68h] [ebp-14h]
  void *Block; // [esp+6Ch] [ebp-10h]
  unsigned int v35; // [esp+70h] [ebp-Ch]
  void *v36; // [esp+74h] [ebp-8h]
  void *v37; // [esp+78h] [ebp-4h]

  v1 = 0;
  Block = 0;
  v37 = 0;
  v36 = 0;
  v3 = sub_6825A9((_DWORD *)this);
  if ( v3 < 0 )
    goto LABEL_61;
  v3 = sub_6863CE((_DWORD *)this);
  if ( v3 < 0 )
    goto LABEL_61;
  if ( (*(_DWORD *)(this + 108) & 0xC000000) != 0 )
  {
    for ( i = 0; i < *(_DWORD *)(this + 12); *(_DWORD *)(v5 + 44) = 0 )
      v5 = *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * i++);
    v6 = *(_DWORD *)(this + 12);
    while ( v6 )
    {
      --v6;
      v7 = *(int **)(*(_DWORD *)(this + 24) + 4 * v6);
      v8 = *v7;
      v9 = *v7 & 0xFFF00000;
      v32 = v6;
      if ( v9 )
      {
        v10 = v7[11];
        if ( (v8 & 0xF0000000) == 0x60000000 || v9 == 285212672 )
        {
          v7[11] = v10 + 1;
          v10 += 2;
        }
        v11 = 0;
        if ( v7[5] )
        {
          do
          {
            v12 = *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * *(_DWORD *)(v7[6] + 4 * v11));
            if ( *(_DWORD *)(v12 + 44) < v10 )
              *(_DWORD *)(v12 + 44) = v10;
            ++v11;
          }
          while ( v11 < v7[5] );
          v6 = v32;
        }
      }
    }
    v1 = 0;
  }
  v13 = *(_DWORD *)(this + 12) == 0;
  v32 = 0;
  v35 = 0;
  if ( !v13 )
  {
    do
    {
      v14 = *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * v35);
      v33 = *(_DWORD *)v14 & 0xFFF00000;
      if ( v33 )
      {
        v15 = **(_DWORD **)(v14 + 16);
        v16 = *(_DWORD *)(this + 20);
        v17 = *(_DWORD *)(this + 16);
        v31 = *(_DWORD *)(v16 + 4 * v15);
        if ( (*(_BYTE *)(*(_DWORD *)(v17 + 4 * *(_DWORD *)(v31 + 4)) + 4) & 8) == 0 )
        {
          if ( v33 == 544210944 || v33 == 545259520 || v33 == 290455552 )
            v18 = *(_DWORD *)(v16 + 4 * **(_DWORD **)(v14 + 8));
          else
            v18 = v31;
          v15 = *(_DWORD *)(v18 + 20);
        }
        v1 = 0;
        *(_DWORD *)(v14 + 52) = v15;
        if ( v15 != -1 )
          v32 = 1;
      }
      ++v35;
    }
    while ( v35 < *(_DWORD *)(this + 12) );
  }
  if ( (*(_BYTE *)(this + 204) & 4) != 0 )
    return 1;
  v30 = 4 * *(_DWORD *)(this + 12);
  if ( v32 )
  {
    v37 = operator new(v30);
    if ( v37 )
    {
      v36 = operator new(4 * *(_DWORD *)(this + 12));
      if ( v36 )
      {
        v3 = sub_686074(this);
        if ( v3 < 0 )
          goto LABEL_61;
        for ( j = 0; j < *(_DWORD *)(this + 12); ++j )
          *((_DWORD *)v37 + j) = j;
        sub_682274((int (__stdcall *)(int, int, int))sub_681F6F, (int *)v37, *(_DWORD *)(this + 12), this);
        v21 = 0;
        if ( *(_DWORD *)(this + 12) )
        {
          v22 = v36;
          v23 = (_BYTE *)v37 - (_BYTE *)v36;
          do
          {
            *v22 = *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * *(_DWORD *)((char *)v22 + v23));
            ++v21;
            ++v22;
          }
          while ( v21 < *(_DWORD *)(this + 12) );
        }
        qmemcpy(*(void **)(this + 24), v36, 4 * *(_DWORD *)(this + 12));
        v3 = sub_6863CE((_DWORD *)this);
        if ( v3 < 0 )
          goto LABEL_61;
        v3 = sub_6CD9DB(1);
        if ( v3 < 0 )
          goto LABEL_61;
        goto LABEL_59;
      }
    }
LABEL_60:
    v3 = -2147024882;
    goto LABEL_61;
  }
  v35 = 0;
  Block = operator new(v30);
  if ( !Block )
    goto LABEL_60;
  v37 = operator new(4 * *(_DWORD *)(this + 12));
  if ( !v37 )
    goto LABEL_60;
  v36 = operator new(4 * *(_DWORD *)(this + 12));
  if ( !v36 )
    goto LABEL_60;
  for ( k = 0; k < *(_DWORD *)(this + 12); ++k )
  {
    v26 = *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * k);
    *(_DWORD *)(v26 + 56) = -1;
    v13 = (*(_WORD *)(v26 + 2) & 0xFFF0) == 0;
    *(_DWORD *)(v26 + 36) = 0;
    if ( !v13 && !*(_DWORD *)(v26 + 28) )
    {
      v24 = v35++;
      *((_DWORD *)Block + v24) = k;
    }
  }
  v31 = 0;
  if ( v35 )
  {
    do
    {
      v3 = sub_684EC5((_DWORD *)this, v24, *((_DWORD *)Block + v1), (int)v37, &v31);
      if ( v3 < 0 )
        goto LABEL_61;
    }
    while ( ++v1 < v35 );
  }
  v27 = 0;
  if ( *(_DWORD *)(this + 12) )
  {
    v28 = v36;
    v29 = (_BYTE *)v37 - (_BYTE *)v36;
    do
    {
      *v28 = *(_DWORD *)(*(_DWORD *)(this + 24) + 4 * *(_DWORD *)((char *)v28 + v29));
      ++v27;
      ++v28;
    }
    while ( v27 < *(_DWORD *)(this + 12) );
  }
  qmemcpy(*(void **)(this + 24), v36, 4 * *(_DWORD *)(this + 12));
LABEL_59:
  v3 = 0;
LABEL_61:
  j__free(Block);
  j__free(v37);
  j__free(v36);
  return v3;
}
