int __usercall sub_6DA486@<eax>(int result@<eax>)
{
  int v1; // ecx

  v1 = *(_DWORD *)(result + 5812);
  if ( v1 > 8 )
  {
    *(_BYTE *)(*(_DWORD *)(result + 8) + (*(_DWORD *)(result + 20))++) = *(_BYTE *)(result + 5808);
    *(_BYTE *)(*(_DWORD *)(result + 20) + *(_DWORD *)(result + 8)) = *(_BYTE *)(result + 5809);
LABEL_5:
    ++*(_DWORD *)(result + 20);
    goto LABEL_6;
  }
  if ( v1 > 0 )
  {
    *(_BYTE *)(*(_DWORD *)(result + 8) + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
    goto LABEL_5;
  }
LABEL_6:
  *(_WORD *)(result + 5808) = 0;
  *(_DWORD *)(result + 5812) = 0;
  return result;
}
