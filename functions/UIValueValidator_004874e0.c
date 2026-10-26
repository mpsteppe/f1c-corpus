int __thiscall sub_4874E0(_BYTE *this)
{
  int v1; // ecx
  int result; // eax
  const CHAR *v3; // eax
  const char *v4; // eax
  const char *v5; // edi

  if ( ByteFieldGetterAt100(this) )
    return 0;
  if ( !*(_BYTE *)(v1 + 225) )
    return 1;
  v3 = *(const CHAR **)(v1 + 160);
  if ( !v3 )
    v3 = byte_5EA438;
  v4 = (const char *)StringNormalizeLookup_a460(v3);
  if ( !v4 )
    return 1;
  v5 = v4;
  result = 0;
  if ( strlen(v5) )
    return 1;
  return result;
}
