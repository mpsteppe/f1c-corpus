int __thiscall sub_535660(_DWORD *this)
{
  int v2; // eax
  int v3; // ecx

  if ( !this )
    return -2;
  v2 = this[7];
  if ( !v2 || !this[9] )
    return -2;
  v3 = *(_DWORD *)(v2 + 20);
  if ( v3 )
    TripleVTableCall(v3, this);
  ((void (__fastcall *)(_DWORD, _DWORD))this[9])(this[10], this[7]);
  this[7] = 0;
  return 0;
}

