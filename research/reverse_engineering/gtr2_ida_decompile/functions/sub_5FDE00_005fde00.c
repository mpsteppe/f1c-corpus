void __stdcall sub_5FDE00(int *a1)
{
  int v1; // esi
  int v2; // ebx
  int *v3; // eax
  int i; // eax
  int v5; // edx
  int v6; // eax
  int *v7; // eax
  int v8; // eax

  v1 = a1[2];
  v2 = *a1;
  if ( v1 )
  {
    v3 = *(int **)(v1 + 552);
    *(_DWORD *)(v1 + 560) = v3;
    if ( v3 )
    {
      for ( i = *v3; i; i = *v7 )
      {
        if ( *(_DWORD *)(i + 20) == *(_DWORD *)(v2 + 548) )
        {
          v5 = *(_DWORD *)(i + 24);
          if ( *(_DWORD *)(v5 + 20) )
          {
            a1[8] = *(_DWORD *)(v5 + 24);
            (*(void (__thiscall **)(int *))(*(_DWORD *)(i + 24) + 20))(a1);
          }
        }
        v6 = *(_DWORD *)(v1 + 560);
        if ( !v6 )
          break;
        v7 = *(int **)(v6 + 4);
        *(_DWORD *)(v1 + 560) = v7;
        if ( !v7 )
          break;
      }
    }
  }
  if ( v2 )
  {
    v8 = *(_DWORD *)(v2 + 548);
    if ( v8 )
    {
      if ( *(_DWORD *)(v8 + 32) )
      {
        a1[8] = *(_DWORD *)(v8 + 36);
        (*(void (__thiscall **)(int *))(*(_DWORD *)(v2 + 548) + 32))(a1);
      }
    }
  }
}
