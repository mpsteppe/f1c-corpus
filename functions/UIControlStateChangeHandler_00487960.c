int __thiscall UIControlStateChangeHandler(int this)
{
  bool v2; // bl
  const CHAR *v3; // eax
  char *v4; // eax
  char *v5; // ecx
  int v6; // eax

  if ( *(_BYTE *)(this + 224) )
  {
    v2 = ShortComputation_7720((_DWORD *)this);
    v3 = *(const CHAR **)(this + 160);
    if ( !v3 )
      v3 = byte_5EA438;
    v4 = StringNormalizeLookup_a460((_DWORD *)(*(_DWORD *)(this + 64) + 5772), v3);
    if ( v4 )
    {
      v5 = *(char **)(this + 168);
      if ( !v5 )
        v5 = byte_5EA438;
      v6 = sub_588410(v4, v5);
      StateDependentVTableDispatch_7760((_DWORD *)this, v6 == 0);
    }
    if ( ShortComputation_7720((_DWORD *)this) != v2 )
      (*(void (__stdcall **)(int))(*(_DWORD *)this + 44))(1);
  }
  return 0;
}
