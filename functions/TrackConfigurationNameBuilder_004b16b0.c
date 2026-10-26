int __thiscall sub_4B16B0(int this)
{
  const char *v2; // eax
  const char **v3; // ebx
  const char *v4; // eax
  char *v5; // eax
  const char *v6; // edi
  int result; // eax
  char *v8; // eax
  char *v9; // eax
  char *v10; // esi

  v2 = *(const char **)(this + 11600);
  v3 = (const char **)(this + 11600);
  if ( !v2 )
    v2 = byte_5EA438;
  if ( strlen(v2) )
  {
    v4 = *v3;
    if ( !*v3 )
      v4 = byte_5EA438;
    NameCompareAndFormat((const char **)this, v4);
    StringCopyWithBufferRealloc(byte_5EA438);
  }
  v5 = *(char **)(this + 11628);
  if ( !v5 )
    v5 = byte_5EA438;
  v6 = v5;
  result = 0;
  if ( strlen(v6) )
  {
    v8 = *(char **)(this + 11612);
    if ( !v8 )
      v8 = byte_5EA438;
    StringCopyWithBufferRealloc(v8);
    v9 = *(char **)(this + 11620);
    if ( !v9 )
      v9 = byte_5EA438;
    StringCopyWithBufferRealloc(v9);
    v10 = *(char **)(this + 11628);
    if ( !v10 )
      v10 = byte_5EA438;
    StringCopyWithBufferRealloc(v10);
    return StringCopyWithBufferRealloc(byte_5EA438);
  }
  return result;
}
