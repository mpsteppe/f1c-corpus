int __stdcall sub_592750(_DWORD *a1)
{
  size_t v1; // eax
  int v3; // ecx
  int v4; // ecx

  v1 = ElementCount;
  if ( ElementCount )
  {
    while ( a1 != (_DWORD *)v1 )
    {
      v1 = *(_DWORD *)(v1 + 304);
      if ( !v1 )
        goto LABEL_4;
    }
    v3 = *(_DWORD *)(v1 + 300);
    if ( v3 )
      *(_DWORD *)(v3 + 304) = *(_DWORD *)(v1 + 304);
    v4 = *(_DWORD *)(v1 + 304);
    if ( v4 )
      *(_DWORD *)(v4 + 300) = *(_DWORD *)(v1 + 300);
    if ( !a1[75] )
      ElementCount = a1[76];
    sub_5AED40(a1);
    j_nullsub_6(a1);
    sub_5BE8AE();
    --dword_7E5D54;
    return 0;
  }
  else
  {
LABEL_4:
    if ( a1 )
    {
      sub_5AED40(a1);
      j_nullsub_6(a1);
      sub_5BE8AE();
    }
    return 0;
  }
}
