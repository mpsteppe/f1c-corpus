// f1c  0x00596fed  size=74
UINT __cdecl sub_596FED(UINT a1)
{
  UINT result; // eax

  result = a1;
  dword_8D41D4 = 0;
  switch ( a1 )
  {
    case 0xFFFFFFFE:
      dword_8D41D4 = 1;
      return GetOEMCP();
    case 0xFFFFFFFD:
      dword_8D41D4 = 1;
      return GetACP();
    case 0xFFFFFFFC:
      result = CodePage;
      dword_8D41D4 = 1;
      break;
  }
  return result;
}
