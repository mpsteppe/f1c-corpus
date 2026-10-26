int __stdcall sub_6B98E8(_DWORD *a1)
{
  int v1; // eax

  if ( !a1 )
    return -2;
  v1 = a1[7];
  if ( !v1 || !a1[9] )
    return -2;
  if ( *(_DWORD *)(v1 + 20) )
    sub_6DB4D9(*(_DWORD *)(v1 + 20), a1);
  ((void (__stdcall *)(_DWORD, _DWORD))a1[9])(a1[10], a1[7]);
  a1[7] = 0;
  return 0;
}
