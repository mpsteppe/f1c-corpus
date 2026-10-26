int __usercall sub_6B88EE@<eax>(int result@<eax>)
{
  int v1; // esi
  unsigned int v2; // edx
  int v3; // ecx

  v1 = *(_DWORD *)(result + 28);
  v2 = *(_DWORD *)(v1 + 20);
  if ( v2 > *(_DWORD *)(result + 16) )
    v2 = *(_DWORD *)(result + 16);
  if ( v2 )
  {
    qmemcpy(*(void **)(result + 12), *(const void **)(v1 + 16), v2);
    v3 = *(_DWORD *)(result + 28);
    *(_DWORD *)(result + 12) += v2;
    *(_DWORD *)(v3 + 16) += v2;
    *(_DWORD *)(result + 20) += v2;
    *(_DWORD *)(result + 16) -= v2;
    *(_DWORD *)(*(_DWORD *)(result + 28) + 20) -= v2;
    result = *(_DWORD *)(result + 28);
    if ( !*(_DWORD *)(result + 20) )
      *(_DWORD *)(result + 16) = *(_DWORD *)(result + 8);
  }
  return result;
}
