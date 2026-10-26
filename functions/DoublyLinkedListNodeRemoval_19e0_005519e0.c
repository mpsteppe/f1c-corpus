int __thiscall sub_5519E0(_DWORD *this, _DWORD *a2)
{
  int v2; // eax
  int v3; // eax

  v2 = a2[11];
  if ( v2 )
    *(_DWORD *)(v2 + 48) = a2[12];
  v3 = a2[12];
  if ( v3 )
    *(_DWORD *)(v3 + 44) = a2[11];
  if ( a2 == (_DWORD *)this[70] )
    this[70] = a2[12];
  CallWrapperReturning0();
  EmptyStub_7470(a2);
  FreeWrapper_7bcf(a2);
  return 0;
}
