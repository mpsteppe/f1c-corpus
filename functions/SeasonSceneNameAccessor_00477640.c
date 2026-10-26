int sub_477640()
{
  int result; // eax
  char **v1; // esi
  char *v2; // eax

  result = LinkedListIndexedAccessor_f590();
  if ( result )
  {
    v1 = *(char ***)(result + 60);
    if ( v1 )
    {
      v2 = *v1;
      if ( !*v1 )
        v2 = byte_5EA438;
      StringCopyWithBufferRealloc(v2);
      return StringCopyWithBufferRealloc(v1 + 47);
    }
  }
  return result;
}
