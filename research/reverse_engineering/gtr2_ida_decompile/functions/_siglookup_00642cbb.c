unsigned int __usercall siglookup@<eax>(unsigned int a1@<edx>, int a2@<esi>)
{
  unsigned int result; // eax

  result = a1;
  do
  {
    if ( *(_DWORD *)(result + 4) == a2 )
      break;
    result += 12;
  }
  while ( result < a1 + 12 * dword_91369C );
  if ( result >= a1 + 12 * dword_91369C || *(_DWORD *)(result + 4) != a2 )
    return 0;
  return result;
}
