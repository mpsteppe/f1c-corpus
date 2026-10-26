char __thiscall sub_4A1F10(_DWORD *this, int a2)
{
  char *v3; // eax

  ResourceLookupWithDualPath(&word_5C30B4);
  v3 = (char *)this[1];
  if ( !v3 )
    v3 = byte_5EA438;
  ResourceLookupWithDualPath(v3);
  ResourceLookupWithDualPath(&word_5C30B4);
  return 1;
}

