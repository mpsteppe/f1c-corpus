void __usercall sub_598E39(int a1@<ebp>)
{
  int v1; // ecx
  _DWORD *v2; // esi
  bool v3; // zf
  void *v4; // edi

  SEHHandlerInit();
  v2 = (_DWORD *)v1;
  *(_DWORD *)(a1 - 16) = v1;
  *(_DWORD *)v1 = &off_5B9BCC;
  v3 = *(_BYTE *)(v1 + 72) == 0;
  *(_DWORD *)(a1 - 4) = 1;
  if ( !v3 )
    FileCloseWrapperWithStatus();
  v4 = (void *)v2[17];
  if ( v4 )
  {
    ReferenceCountDecrementWithConditionalFree(1);
    FreeWrapper_7bcf(v4);
  }
  NullCheckWithVirtualDispatch(v2 + 19);
  *v2 = &std::streambuf::`vftable';
  NullCheckWithVirtualDispatch(v2 + 13);
}
