int __thiscall sub_4029C0(int this)
{
  int v2; // edx
  int v3; // ecx
  int v4; // eax
  int v5; // ecx
  void *v6; // eax
  void *v7; // eax
  int v8; // ecx
  int v9; // edx
  _DWORD *v10; // eax
  int v11; // ecx
  int v12; // edx
  _DWORD *v13; // eax
  int v14; // ecx
  int v15; // edx
  _DWORD *v16; // eax
  __int64 v17; // rax
  int i; // ecx
  _DWORD *v19; // eax
  size_t v21; // [esp-10h] [ebp-18h]
  size_t v22; // [esp-Ch] [ebp-14h]

  if ( *(_DWORD *)(this + 344) )
    j_j__free(*(void **)(this + 344));
  if ( *(_DWORD *)(this + 348) )
    j_j__free(*(void **)(this + 348));
  if ( *(_DWORD *)(this + 352) )
    j_j__free(*(void **)(this + 352));
  if ( *(_DWORD *)(this + 356) )
    j_j__free(*(void **)(this + 356));
  if ( *(_DWORD *)(this + 360) )
    j_j__free(*(void **)(this + 360));
  v2 = *(_DWORD *)(this + 372);
  v3 = *(_DWORD *)(this + 364) + 1;
  v4 = *(_DWORD *)(this + 368);
  *(_DWORD *)(this + 16) = v3;
  v5 = v4 + v3;
  *(_DWORD *)(this + 12) = 1;
  *(_DWORD *)(this + 20) = v5;
  *(_DWORD *)(this + 24) = v5 + v2;
  *(_DWORD *)(this + 344) = operator new(28 * v4);
  v6 = operator new(28 * *(_DWORD *)(this + 368));
  v22 = 28 * *(_DWORD *)(this + 372);
  *(_DWORD *)(this + 348) = v6;
  v7 = operator new(v22);
  v21 = 28 * *(_DWORD *)(this + 372) * *(_DWORD *)(this + 376);
  *(_DWORD *)(this + 352) = v7;
  *(_DWORD *)(this + 356) = operator new(v21);
  *(_DWORD *)(this + 360) = operator new(28 * *(_DWORD *)(this + 372) * *(_DWORD *)(this + 376));
  v8 = 0;
  if ( *(int *)(this + 368) > 0 )
  {
    v9 = 0;
    do
    {
      v10 = (_DWORD *)(v9 + *(_DWORD *)(this + 348));
      *v10 = 0;
      v10[1] = 0;
      v10[2] = 0;
      v10[3] = 0;
      v10[4] = 0;
      v10[5] = 0;
      v10[6] = 0;
      ++v8;
      v9 += 28;
    }
    while ( v8 < *(_DWORD *)(this + 368) );
  }
  v11 = 0;
  if ( *(int *)(this + 368) > 0 )
  {
    v12 = 0;
    do
    {
      v13 = (_DWORD *)(v12 + *(_DWORD *)(this + 344));
      *v13 = 0;
      v13[1] = 0;
      v13[2] = 0;
      v13[3] = 0;
      v13[4] = 0;
      v13[5] = 0;
      v13[6] = 0;
      ++v11;
      v12 += 28;
    }
    while ( v11 < *(_DWORD *)(this + 368) );
  }
  v14 = 0;
  if ( *(int *)(this + 372) > 0 )
  {
    v15 = 0;
    do
    {
      v16 = (_DWORD *)(v15 + *(_DWORD *)(this + 352));
      *v16 = 0;
      v16[1] = 0;
      v16[2] = 0;
      v16[3] = 0;
      v16[4] = 0;
      v16[5] = 0;
      v16[6] = 0;
      ++v14;
      v15 += 28;
    }
    while ( v14 < *(_DWORD *)(this + 372) );
  }
  v17 = *(unsigned int *)(this + 372);
  if ( (int)v17 > 0 )
  {
    do
    {
      for ( i = 0; i < *(_DWORD *)(this + 376); ++i )
      {
        LODWORD(v17) = *(_DWORD *)(this + 356) + 28 * (HIDWORD(v17) + i * *(_DWORD *)(this + 372));
        *(_DWORD *)v17 = 0;
        *(_DWORD *)(v17 + 4) = 0;
        *(_DWORD *)(v17 + 8) = 0;
        *(_DWORD *)(v17 + 12) = 0;
        *(_DWORD *)(v17 + 16) = 0;
        *(_DWORD *)(v17 + 20) = 0;
        *(_DWORD *)(v17 + 24) = 0;
        v19 = (_DWORD *)(*(_DWORD *)(this + 360) + 28 * (HIDWORD(v17) + i * *(_DWORD *)(this + 372)));
        *v19 = 0;
        v19[1] = 0;
        v19[2] = 0;
        v19[3] = 0;
        v19[4] = 0;
        v19[5] = 0;
        v19[6] = 0;
      }
      LODWORD(v17) = *(_DWORD *)(this + 372);
      ++HIDWORD(v17);
    }
    while ( SHIDWORD(v17) < (int)v17 );
  }
  return v17;
}
