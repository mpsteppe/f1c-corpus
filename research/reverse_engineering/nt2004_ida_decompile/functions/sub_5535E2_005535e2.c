int __cdecl sub_5535E2(int a1, int a2, unsigned int a3, unsigned int a4, char a5)
{
  unsigned int v6; // edi
  unsigned int v7; // eax
  int v8; // eax
  unsigned int v9; // ebx
  int v10; // eax
  unsigned int v11; // edi
  unsigned int v12; // ebx
  unsigned int v14; // [esp+20h] [ebp+14h]
  unsigned int v15; // [esp+20h] [ebp+14h]

  v6 = a3 + a4;
  v14 = a3 + a4;
  if ( v14 > *(_DWORD *)(a2 + 4) || a4 > *(_DWORD *)(a2 + 12) || !*(_DWORD *)a2 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 20;
    (**(void (__cdecl ***)(int))a1)(a1);
  }
  v7 = *(_DWORD *)(a2 + 24);
  if ( a3 < v7 || v6 > v7 + *(_DWORD *)(a2 + 16) )
  {
    if ( !*(_BYTE *)(a2 + 34) )
    {
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 68;
      (**(void (__cdecl ***)(int))a1)(a1);
    }
    if ( *(_BYTE *)(a2 + 33) )
    {
      sub_553439(a2, a1, 1);
      *(_BYTE *)(a2 + 33) = 0;
    }
    if ( a3 <= *(_DWORD *)(a2 + 24) )
    {
      v8 = v6 - *(_DWORD *)(a2 + 16);
      if ( v8 < 0 )
        v8 = 0;
      *(_DWORD *)(a2 + 24) = v8;
    }
    else
    {
      *(_DWORD *)(a2 + 24) = a3;
    }
    sub_553439(a2, a1, 0);
  }
  v9 = *(_DWORD *)(a2 + 28);
  if ( v9 < v6 )
  {
    if ( v9 < a3 )
    {
      if ( a5 )
      {
        *(_DWORD *)(*(_DWORD *)a1 + 20) = 20;
        (**(void (__cdecl ***)(int))a1)(a1);
      }
      v9 = a3;
    }
    if ( a5 )
      *(_DWORD *)(a2 + 28) = v6;
    if ( *(_BYTE *)(a2 + 32) )
    {
      v10 = *(_DWORD *)(a2 + 24);
      v11 = *(_DWORD *)(a2 + 8) << 7;
      v12 = v9 - v10;
      v15 = v14 - v10;
      while ( v12 < v15 )
        sub_55293B(*(void **)(*(_DWORD *)a2 + 4 * v12++), v11);
    }
    else
    {
      if ( a5 )
      {
LABEL_32:
        *(_BYTE *)(a2 + 33) = 1;
        return *(_DWORD *)a2 + 4 * (a3 - *(_DWORD *)(a2 + 24));
      }
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 20;
      (**(void (__cdecl ***)(int))a1)(a1);
    }
  }
  if ( a5 )
    goto LABEL_32;
  return *(_DWORD *)a2 + 4 * (a3 - *(_DWORD *)(a2 + 24));
}
