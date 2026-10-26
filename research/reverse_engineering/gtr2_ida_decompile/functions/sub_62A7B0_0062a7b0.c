int __usercall sub_62A7B0@<eax>(int a1@<esi>)
{
  int v1; // edi
  char v3; // al
  int v4; // eax

  v1 = 0;
  if ( !a1 )
    return -2;
  if ( *(_DWORD *)(a1 + 80) )
    free(*(void **)(a1 + 80));
  if ( *(_DWORD *)(a1 + 28) )
  {
    v3 = *(_BYTE *)(a1 + 92);
    if ( v3 == 119 )
    {
      v4 = sub_62B4F0(a1);
    }
    else
    {
      if ( v3 != 114 )
        goto LABEL_11;
      v4 = sub_62C540(a1);
    }
    v1 = v4;
  }
LABEL_11:
  if ( *(_DWORD *)(a1 + 64) && fclose(*(FILE **)(a1 + 64)) && *_errno() != 29 )
    v1 = -1;
  if ( *(int *)(a1 + 56) < 0 )
    v1 = *(_DWORD *)(a1 + 56);
  if ( *(_DWORD *)(a1 + 68) )
    free(*(void **)(a1 + 68));
  if ( *(_DWORD *)(a1 + 72) )
    free(*(void **)(a1 + 72));
  if ( *(_DWORD *)(a1 + 84) )
    free(*(void **)(a1 + 84));
  free((void *)a1);
  return v1;
}
