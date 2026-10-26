char sub_4FB240()
{
  int v0; // ecx
  char result; // al

  v0 = 0;
  result = 1;
  if ( (int)NumOfElements > 0 )
  {
    while ( *(_DWORD *)(dword_75AAD0[v0] + 20892) )
    {
      if ( ++v0 >= (int)NumOfElements )
        return result;
    }
    return 0;
  }
  return result;
}
