int __thiscall sub_488B40(_DWORD *this, const char *a2)
{
  const char *v4; // eax

  if ( !a2 )
    return -1;
  v4 = (const char *)this[44];
  if ( !v4 )
    v4 = byte_5EA438;
  if ( strcmp(a2, v4) )
  {
    StringCopyWithBufferRealloc(a2);
    (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 1);
  }
  return 0;
}

