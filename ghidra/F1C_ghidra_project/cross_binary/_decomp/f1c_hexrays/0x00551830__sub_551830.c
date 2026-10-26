// f1c  0x00551830  size=106
int __thiscall sub_551830(_DWORD *this, const char *a2)
{
  int v2; // edi

  v2 = this[79];
  if ( !v2 )
    return 0;
  while ( strcmp(a2, (const char *)(*(_DWORD *)(v2 + 28) + 28)) )
  {
    v2 = *(_DWORD *)(v2 + 36);
    if ( !v2 )
      return 0;
  }
  return v2;
}
