int __thiscall sub_59B3B0(int this, int a2)
{
  int v3; // esi
  int v4; // eax
  _WORD *v5; // ecx
  int v6; // edx

  if ( *(_DWORD *)(this + 4) < *(_DWORD *)(a2 + 4) )
  {
    FreeWrapper_7bcf(*(LPVOID *)this);
    *(_DWORD *)this = OperatorNewNhMallocWrapper(*(_DWORD *)(a2 + 4));
    *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
  }
  if ( *(_DWORD *)(this + 12) < *(_DWORD *)(a2 + 12) )
  {
    FreeWrapper_7bcf(*(LPVOID *)(this + 8));
    v3 = *(_DWORD *)(a2 + 12);
    v4 = OperatorNewNhMallocWrapper(4 * v3);
    if ( v4 )
    {
      v5 = (_WORD *)v4;
      if ( v3 - 1 >= 0 )
      {
        v6 = v3;
        do
        {
          v5[1] = 0;
          *v5 = 0;
          v5 += 2;
          --v6;
        }
        while ( v6 );
      }
    }
    else
    {
      v4 = 0;
    }
    *(_DWORD *)(this + 8) = v4;
    *(_DWORD *)(this + 12) = *(_DWORD *)(a2 + 12);
  }
  qmemcpy(*(void **)this, *(const void **)a2, *(_DWORD *)(a2 + 4));
  qmemcpy(*(void **)(this + 8), *(const void **)(a2 + 8), 4 * *(_DWORD *)(a2 + 20));
  *(_DWORD *)(this + 16) = *(_DWORD *)(a2 + 16);
  *(_DWORD *)(this + 20) = *(_DWORD *)(a2 + 20);
  *(_DWORD *)(this + 24) = *(_DWORD *)(a2 + 24);
  *(_DWORD *)(this + 28) = *(_DWORD *)(a2 + 28);
  return this;
}
