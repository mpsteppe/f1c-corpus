int __usercall sub_5159F5@<eax>(int a1@<esi>)
{
  int v1; // ebx
  bool v2; // cc
  int v3; // edi
  int *v4; // edi
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // ebx
  int v10; // edi
  int v11; // eax
  int result; // eax

  if ( *(int *)(a1 + 28) > 65500 || *(int *)(a1 + 24) > 65500 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 40;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = 65500;
    (**(void (__cdecl ***)(int))a1)(a1);
  }
  if ( *(_DWORD *)(a1 + 192) != 8 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 13;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = *(_DWORD *)(a1 + 192);
    (**(void (__cdecl ***)(int))a1)(a1);
  }
  if ( *(int *)(a1 + 32) > 10 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 24;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = *(_DWORD *)(a1 + 32);
    *(_DWORD *)(*(_DWORD *)a1 + 28) = 10;
    (**(void (__cdecl ***)(int))a1)(a1);
  }
  v1 = 0;
  v2 = *(_DWORD *)(a1 + 32) <= 0;
  v3 = *(_DWORD *)(a1 + 196);
  *(_DWORD *)(a1 + 268) = 1;
  *(_DWORD *)(a1 + 272) = 1;
  if ( !v2 )
  {
    v4 = (int *)(v3 + 12);
    do
    {
      v5 = *(v4 - 1);
      if ( v5 <= 0 || v5 > 4 || *v4 <= 0 || *v4 > 4 )
      {
        *(_DWORD *)(*(_DWORD *)a1 + 20) = 16;
        (**(void (__cdecl ***)(int))a1)(a1);
      }
      v6 = *(_DWORD *)(a1 + 268);
      if ( v6 <= *(v4 - 1) )
        v6 = *(v4 - 1);
      *(_DWORD *)(a1 + 268) = v6;
      v7 = *(_DWORD *)(a1 + 272);
      if ( v7 <= *v4 )
        v7 = *v4;
      ++v1;
      *(_DWORD *)(a1 + 272) = v7;
      v4 += 21;
    }
    while ( v1 < *(_DWORD *)(a1 + 32) );
  }
  v8 = *(_DWORD *)(a1 + 196);
  v9 = 0;
  v2 = *(_DWORD *)(a1 + 32) <= 0;
  *(_DWORD *)(a1 + 276) = 8;
  if ( !v2 )
  {
    v10 = v8 + 28;
    do
    {
      *(_DWORD *)(v10 + 8) = 8;
      *(_DWORD *)v10 = CeilingDivision(*(_DWORD *)(a1 + 24) * *(_DWORD *)(v10 - 20), 8 * *(_DWORD *)(a1 + 268));
      *(_DWORD *)(v10 + 4) = CeilingDivision(*(_DWORD *)(a1 + 28) * *(_DWORD *)(v10 - 16), 8 * *(_DWORD *)(a1 + 272));
      *(_DWORD *)(v10 + 12) = CeilingDivision(*(_DWORD *)(a1 + 24) * *(_DWORD *)(v10 - 20), *(_DWORD *)(a1 + 268));
      v11 = CeilingDivision(*(_DWORD *)(a1 + 28) * *(_DWORD *)(v10 - 16), *(_DWORD *)(a1 + 272));
      *(_DWORD *)(v10 + 48) = 0;
      *(_DWORD *)(v10 + 16) = v11;
      *(_BYTE *)(v10 + 20) = 1;
      ++v9;
      v10 += 84;
    }
    while ( v9 < *(_DWORD *)(a1 + 32) );
  }
  *(_DWORD *)(a1 + 280) = CeilingDivision(*(_DWORD *)(a1 + 28), 8 * *(_DWORD *)(a1 + 272));
  if ( *(_DWORD *)(a1 + 288) < *(_DWORD *)(a1 + 32) || *(_BYTE *)(a1 + 200) )
  {
    result = *(_DWORD *)(a1 + 396);
    *(_BYTE *)(result + 16) = 1;
  }
  else
  {
    result = *(_DWORD *)(a1 + 396);
    *(_BYTE *)(result + 16) = 0;
  }
  return result;
}
