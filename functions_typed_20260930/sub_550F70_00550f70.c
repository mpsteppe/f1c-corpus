int __thiscall sub_550F70(_DWORD *this)
{
  int v2; // esi
  int v3; // eax
  int v4; // esi
  int v5; // edi
  int v6; // esi
  int v7; // eax
  void *v8; // ebp
  LPVOID *v9; // esi
  int v10; // eax
  int v11; // edi
  bool v12; // cc
  int v13; // ecx
  int v14; // eax
  void *v15; // ebx
  int v16; // edx
  int v17; // eax
  _DWORD *v18; // esi
  int v19; // edi
  int v21; // eax
  void *v22; // ebp
  int v23; // esi
  int v24; // edi
  int v25; // ecx
  int v26; // esi
  int v27; // edi
  int v28; // [esp+10h] [ebp-8h]
  int v29; // [esp+10h] [ebp-8h]
  int v30; // [esp+14h] [ebp-4h]
  int v31; // [esp+14h] [ebp-4h]

  if ( (*this & 2) == 0 )
  {
    if ( (*this & 1) == 0 )
      return 0;
    v29 = 0;
    if ( (int)this[3] > 0 )
    {
      v31 = 0;
      do
      {
        v21 = *(_DWORD *)(v31 + this[4] + 40);
        if ( v21 )
        {
          v22 = (void *)(v21 - 4);
          v23 = v21 + 32 * *(_DWORD *)(v21 - 4);
          if ( *(_DWORD *)(v21 - 4) - 1 >= 0 )
          {
            v24 = *(_DWORD *)(v21 - 4);
            do
            {
              v23 -= 32;
              RefcountDecrement();
              --v24;
            }
            while ( v24 );
          }
          FreeWrapper_7bcf(v22);
        }
        v12 = ++v29 < this[3];
        v31 += 44;
      }
      while ( v12 );
    }
    v25 = this[4];
    if ( !v25 )
      return 0;
    v15 = (void *)(v25 - 4);
    v26 = v25 + 44 * *(_DWORD *)(v25 - 4);
    if ( *(_DWORD *)(v25 - 4) - 1 >= 0 )
    {
      v27 = *(_DWORD *)(v25 - 4);
      do
      {
        v26 -= 44;
        EmptyStub_7470(v26);
        --v27;
      }
      while ( v27 );
    }
    goto LABEL_30;
  }
  v28 = 0;
  if ( (int)this[5] > 0 )
  {
    v30 = 0;
    do
    {
      v2 = this[6];
      v3 = *(_DWORD *)(v2 + v30 + 4);
      v4 = v30 + v2;
      v5 = 0;
      if ( v3 > 0 )
      {
        do
          FreeWrapper_7bcf(*(LPVOID *)(*(_DWORD *)(v4 + 8) + 8 * v5++ + 4));
        while ( v5 < *(_DWORD *)(v4 + 4) );
      }
      v6 = *(_DWORD *)(v4 + 8);
      if ( v6 )
      {
        v7 = *(_DWORD *)(v6 - 4);
        v8 = (void *)(v6 - 4);
        v9 = (LPVOID *)(v6 + 8 * v7);
        v10 = v7 - 1;
        if ( v10 >= 0 )
        {
          v11 = v10 + 1;
          do
          {
            v9 -= 2;
            sub_550810(v9);
            --v11;
          }
          while ( v11 );
        }
        FreeWrapper_7bcf(v8);
      }
      v12 = ++v28 < this[5];
      v30 += 12;
    }
    while ( v12 );
  }
  v13 = this[6];
  if ( !v13 )
    return 0;
  v14 = *(_DWORD *)(v13 - 4);
  v15 = (void *)(v13 - 4);
  v16 = 3 * v14;
  v17 = v14 - 1;
  v18 = (_DWORD *)(v13 + 4 * v16);
  if ( v17 < 0 )
  {
LABEL_30:
    FreeWrapper_7bcf(v15);
    return 0;
  }
  v19 = v17 + 1;
  do
  {
    v18 -= 3;
    ArrayOfStructDestructorWithCountdown(v18);
    --v19;
  }
  while ( v19 );
  FreeWrapper_7bcf(v15);
  return 0;
}

