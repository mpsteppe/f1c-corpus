int __stdcall sub_53CE10(_DWORD *a1, CHAR *a2)
{
  int result; // eax

  result = sub_53CBC0(a1, a2);
  if ( !result )
  {
    if ( a1 )
      *(_DWORD *)(*a1 + 276) |= 8u;
  }
  return result;
}

