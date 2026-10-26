void __stdcall RecursiveTreeTraversalFree(_DWORD *a1)
{
  _DWORD *v1; // eax
  _DWORD *v2; // esi
  _DWORD *v3; // eax
  _DWORD *v4; // eax

  if ( a1 )
  {
    NullCheckWrapper(a1, 0);
    v2 = v1;
    while ( v2 )
    {
      v3 = v2;
      v2 = (_DWORD *)v2[1];
      RecursiveTreeTraversalFree(v3);
    }
    v4 = (_DWORD *)ShortComputation_adb0(a1);
    if ( v4 )
      RecursiveTreeTraversalFree(v4);
    DualPointerCleanup((int)a1);
    FreeWrapper_7bcf(a1);
  }
}

