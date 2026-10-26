UINT __cdecl getSystemCP(UINT a1)
{
  UINT result; // eax

  result = a1;
  dword_7FF484 = 0;
  switch ( a1 )
  {
    case 0xFFFFFFFE:
      dword_7FF484 = 1;
      return GetOEMCP();
    case 0xFFFFFFFD:
      dword_7FF484 = 1;
      return GetACP();
    case 0xFFFFFFFC:
      result = CodePage;
      dword_7FF484 = 1;
      break;
  }
  return result;
}
