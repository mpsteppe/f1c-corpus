char *__thiscall sub_489950(_DWORD *this)
{
  int v1; // eax
  char *result; // eax

  v1 = LinkedListTraversalByIndex(this);
  if ( !v1 )
    return 0;
  result = *(char **)(v1 + 168);
  if ( !result )
    return byte_5EA438;
  return result;
}
