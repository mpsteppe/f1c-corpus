unsigned int __fastcall sub_536560(int a1, void *a2, unsigned int a3)
{
  unsigned int v4; // ebp
  unsigned int result; // eax
  unsigned int v7; // ecx

  v4 = *(_DWORD *)(a1 + 4);
  if ( v4 > a3 )
    v4 = a3;
  if ( !v4 )
    return 0;
  *(_DWORD *)(a1 + 4) -= v4;
  if ( !*(_DWORD *)(*(_DWORD *)(a1 + 28) + 24) )
    *(_DWORD *)(a1 + 48) = sub_537D10(v4);
  qmemcpy(a2, *(const void **)a1, v4);
  v7 = v4 + *(_DWORD *)a1;
  *(_DWORD *)(a1 + 8) += v4;
  result = v4;
  *(_DWORD *)a1 = v7;
  return result;
}
