int __thiscall sub_487460(int this)
{
  char v2; // bl
  const CHAR *v3; // eax
  int v4; // eax
  char *v5; // ecx
  int v6; // eax

  if ( *(_BYTE *)(this + 224) )
  {
    v2 = ((int (*)(void))ShortComputation_7720)();
    v3 = *(const CHAR **)(this + 160);
    if ( !v3 )
      v3 = byte_5EA438;
    v4 = StringNormalizeLookup_a460(v3);
    if ( v4 )
    {
      v5 = *(char **)(this + 168);
      if ( !v5 )
        v5 = byte_5EA438;
      v6 = sub_588410(v4, v5);
      sub_487260((_DWORD *)this, v6 == 0);
    }
    if ( (unsigned __int8)ShortComputation_7720(this) != v2 )
      (*(void (__stdcall **)(int))(*(_DWORD *)this + 44))(1);
  }
  return 0;
}

