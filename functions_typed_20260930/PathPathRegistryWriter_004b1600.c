int __thiscall sub_4B1600(_DWORD *this)
{
  char *v2; // eax
  char *v3; // eax
  char *v4; // eax
  char *v5; // eax
  char *v6; // eax
  char *v7; // esi

  v2 = (char *)this[2019];
  if ( !v2 )
    v2 = byte_5EA438;
  StringCopyWithBufferRealloc(v2);
  v3 = (char *)this[2021];
  if ( !v3 )
    v3 = byte_5EA438;
  StringCopyWithBufferRealloc(v3);
  v4 = (char *)this[2023];
  if ( !v4 )
    v4 = byte_5EA438;
  StringCopyWithBufferRealloc(v4);
  v5 = (char *)this[105];
  if ( !v5 )
    v5 = byte_5EA438;
  StringCopyWithBufferRealloc(v5);
  v6 = (char *)this[107];
  if ( !v6 )
    v6 = byte_5EA438;
  StringCopyWithBufferRealloc(v6);
  v7 = (char *)this[109];
  if ( !v7 )
    v7 = byte_5EA438;
  return StringCopyWithBufferRealloc(v7);
}

