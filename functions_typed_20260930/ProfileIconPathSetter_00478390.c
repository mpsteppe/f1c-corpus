void __thiscall ProfileIconPathSetter(_DWORD *this)
{
  _DWORD *v1; // ecx
  int v2; // eax
  const CHAR *v3; // eax

  v1 = (_DWORD *)this[56];
  if ( v1 )
  {
    v2 = LinkedListIndexedAccessor_f590(v1);
    if ( v2 )
    {
      v3 = *(const CHAR **)(v2 + 48);
      if ( !v3 )
        v3 = byte_5EA438;
      lpExistingFileName = v3;
    }
  }
}

