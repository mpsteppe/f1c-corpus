int __usercall sub_62DE50@<eax>(int result@<eax>)
{
  int v1; // edx
  char v2; // bl
  int v3; // edx

  v1 = *(_DWORD *)(result + 5805);
  if ( v1 <= 8 )
  {
    if ( v1 > 0 )
      *(_BYTE *)(*(_DWORD *)(result + 8) + (*(_DWORD *)(result + 20))++) = *(_BYTE *)(result + 5803);
    *(_WORD *)(result + 5803) = 0;
    *(_DWORD *)(result + 5805) = 0;
  }
  else
  {
    *(_BYTE *)(*(_DWORD *)(result + 8) + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5803);
    v2 = *(_BYTE *)(result + 5804);
    v3 = *(_DWORD *)(result + 20) + 1;
    *(_DWORD *)(result + 20) = v3;
    *(_BYTE *)(v3 + *(_DWORD *)(result + 8)) = v2;
    ++*(_DWORD *)(result + 20);
    *(_WORD *)(result + 5803) = 0;
    *(_DWORD *)(result + 5805) = 0;
  }
  return result;
}
