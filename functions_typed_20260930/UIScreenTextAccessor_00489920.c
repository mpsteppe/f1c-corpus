char *__thiscall sub_489920(_DWORD *this)
{
  int v1; // eax
  char *result; // eax

  v1 = LinkedListTraversalByIndex(this);
  if ( !v1 )
    return 0;
  result = *(char **)(v1 + 176);
  if ( !result )
    return byte_5EA438;
  return result;
}

