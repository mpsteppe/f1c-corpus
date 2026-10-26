int __fastcall sub_5B9EE0(int a1, int a2)
{
  int result; // eax

  result = 0;
  while ( *(_DWORD *)(a1 + 1552) )
  {
    if ( result )
      break;
    sub_5BDB80(0xAu);
    result = sub_5B9F20(a1);
    if ( a2 )
    {
      if ( !*(_DWORD *)(a1 + 72) )
        break;
    }
  }
  return result;
}
