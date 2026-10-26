int __stdcall sub_6C6925(int a1, int a2)
{
  int result; // eax
  int v3; // ecx

  for ( result = a1; ; result += 36 )
  {
    v3 = *(_DWORD *)(result + 16);
    if ( v3 == -1 || v3 == a2 )
      break;
  }
  return result;
}
