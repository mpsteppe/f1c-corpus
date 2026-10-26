int __cdecl sub_516531(int a1, int a2, unsigned int a3, unsigned int a4, char a5)
{
  unsigned int v5; // ebx
  int v6; // edi
  unsigned int v7; // eax
  int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // edi
  int v11; // eax
  unsigned int v12; // edi
  unsigned int v13; // ebx
  unsigned int v15; // [esp+20h] [ebp+14h]

  v5 = a3 + a4;
  if ( a3 + a4 <= *(_DWORD *)(a2 + 4) && a4 <= *(_DWORD *)(a2 + 12) && *(_DWORD *)a2 )
  {
    v6 = a1;
  }
  else
  {
    v6 = a1;
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 20;
    (**(void (__cdecl ***)(int))a1)(a1);
  }
  v7 = *(_DWORD *)(a2 + 24);
  if ( a3 < v7 || v5 > v7 + *(_DWORD *)(a2 + 16) )
  {
    if ( !*(_BYTE *)(a2 + 34) )
    {
      *(_DWORD *)(*(_DWORD *)v6 + 20) = 68;
      (**(void (__cdecl ***)(int))v6)(v6);
    }
    if ( *(_BYTE *)(a2 + 33) )
    {
      sub_51641E(a2, v6, 1);
      *(_BYTE *)(a2 + 33) = 0;
    }
    v8 = a3;
    if ( a3 <= *(_DWORD *)(a2 + 24) )
    {
      v8 = v5 - *(_DWORD *)(a2 + 16);
      if ( v8 < 0 )
        v8 = 0;
    }
    *(_DWORD *)(a2 + 24) = v8;
    sub_51641E(a2, v6, 0);
  }
  v9 = *(_DWORD *)(a2 + 28);
  if ( v9 < v5 )
  {
    if ( v9 >= a3 )
    {
      v10 = *(_DWORD *)(a2 + 28);
    }
    else
    {
      if ( a5 )
      {
        *(_DWORD *)(*(_DWORD *)v6 + 20) = 20;
        (**(void (__cdecl ***)(int))v6)(v6);
      }
      v10 = a3;
    }
    if ( a5 )
      *(_DWORD *)(a2 + 28) = v5;
    if ( *(_BYTE *)(a2 + 32) )
    {
      v15 = *(_DWORD *)(a2 + 8);
      v11 = *(_DWORD *)(a2 + 24);
      v12 = v10 - v11;
      v13 = v5 - v11;
      while ( v12 < v13 )
        MemoryZeroFill(*(void **)(*(_DWORD *)a2 + 4 * v12++), v15);
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
