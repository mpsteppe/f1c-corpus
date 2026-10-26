int __stdcall sub_40C540(int a1, int a2)
{
  int v2; // ecx
  int result; // eax
  int v4; // edx
  int v5; // ecx

  v2 = dword_5F0738[4656 * a1];
  result = 0;
  v4 = v2 - 1;
  if ( a2 >= 0 )
    v4 = v2 + 1;
  if ( v4 >= 1 )
  {
    if ( v4 > dword_5C329C )
      v4 = 1;
  }
  else
  {
    v4 = dword_5C329C;
  }
  v5 = 0;
  if ( dword_5C329C > 0 )
  {
    while ( v4 != *(_DWORD *)(dword_7C54F0[v5] + 16480) )
    {
      if ( ++v5 >= dword_5C329C )
        return result;
    }
    return *(_DWORD *)(dword_7C54F0[v5] + 18580);
  }
  return result;
}
