char __cdecl sub_516A1D(int a1)
{
  int v2; // eax
  unsigned int v3; // ecx
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  bool v8; // cc
  _DWORD *v9; // eax
  int v10; // edx
  int v11; // ebx
  _DWORD *v12; // edi
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // eax
  int v18; // [esp-18h] [ebp-20h]
  int v19; // [esp-18h] [ebp-20h]
  int v20; // [esp-18h] [ebp-20h]
  int v21; // [esp+4h] [ebp-4h]
  int i; // [esp+10h] [ebp+8h]

  if ( *(_DWORD *)(a1 + 16) != 202 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 18;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = *(_DWORD *)(a1 + 16);
    (**(void (__cdecl ***)(int))a1)(a1);
  }
  v2 = *(_DWORD *)(a1 + 44);
  v3 = *(_DWORD *)(a1 + 48);
  if ( 8 * v2 > v3 )
  {
    if ( 4 * v2 > v3 )
    {
      if ( 2 * v2 > v3 )
      {
        *(_DWORD *)(a1 + 92) = *(_DWORD *)(a1 + 24);
        v5 = *(_DWORD *)(a1 + 28);
        *(_DWORD *)(a1 + 276) = 8;
      }
      else
      {
        v7 = CeilingDivision(*(_DWORD *)(a1 + 24), 2);
        v20 = *(_DWORD *)(a1 + 28);
        *(_DWORD *)(a1 + 92) = v7;
        v5 = CeilingDivision(v20, 2);
        *(_DWORD *)(a1 + 276) = 4;
      }
    }
    else
    {
      v6 = CeilingDivision(*(_DWORD *)(a1 + 24), 4);
      v19 = *(_DWORD *)(a1 + 28);
      *(_DWORD *)(a1 + 92) = v6;
      v5 = CeilingDivision(v19, 4);
      *(_DWORD *)(a1 + 276) = 2;
    }
  }
  else
  {
    v4 = CeilingDivision(*(_DWORD *)(a1 + 24), 8);
    v18 = *(_DWORD *)(a1 + 28);
    *(_DWORD *)(a1 + 92) = v4;
    v5 = CeilingDivision(v18, 8);
    *(_DWORD *)(a1 + 276) = 1;
  }
  v21 = 0;
  v8 = *(_DWORD *)(a1 + 32) <= 0;
  *(_DWORD *)(a1 + 96) = v5;
  if ( !v8 )
  {
    v9 = (_DWORD *)(*(_DWORD *)(a1 + 196) + 12);
    do
    {
      v10 = *(_DWORD *)(a1 + 276);
      for ( i = v10; i < 8; i *= 2 )
      {
        if ( 2 * i * *(v9 - 1) > v10 * *(_DWORD *)(a1 + 268) )
          break;
        if ( 2 * i * *v9 > v10 * *(_DWORD *)(a1 + 272) )
          break;
      }
      ++v21;
      v9[6] = i;
      v9 += 21;
    }
    while ( v21 < *(_DWORD *)(a1 + 32) );
  }
  v11 = 0;
  if ( *(int *)(a1 + 32) > 0 )
  {
    v12 = (_DWORD *)(*(_DWORD *)(a1 + 196) + 36);
    do
    {
      v12[1] = CeilingDivision(*(_DWORD *)(a1 + 24) * *v12 * *(v12 - 7), 8 * *(_DWORD *)(a1 + 268));
      v12[2] = CeilingDivision(*v12 * *(_DWORD *)(a1 + 28) * *(v12 - 6), 8 * *(_DWORD *)(a1 + 272));
      ++v11;
      v12 += 21;
    }
    while ( v11 < *(_DWORD *)(a1 + 32) );
  }
  v13 = *(_DWORD *)(a1 + 40);
  v14 = 1;
  if ( v13 != 1 )
  {
    if ( v13 <= 1 )
    {
LABEL_25:
      *(_DWORD *)(a1 + 100) = *(_DWORD *)(a1 + 32);
      goto LABEL_27;
    }
    v14 = 3;
    if ( v13 > 3 )
    {
      if ( v13 <= 5 )
      {
        *(_DWORD *)(a1 + 100) = 4;
        goto LABEL_27;
      }
      goto LABEL_25;
    }
  }
  *(_DWORD *)(a1 + 100) = v14;
LABEL_27:
  if ( *(_BYTE *)(a1 + 74) )
    v15 = 1;
  else
    v15 = *(_DWORD *)(a1 + 100);
  *(_DWORD *)(a1 + 104) = v15;
  LOBYTE(v16) = ComplexStateValidator(v14, a1);
  if ( (_BYTE)v16 )
  {
    v16 = *(_DWORD *)(a1 + 272);
    *(_DWORD *)(a1 + 108) = v16;
  }
  else
  {
    *(_DWORD *)(a1 + 108) = 1;
  }
  return v16;
}
