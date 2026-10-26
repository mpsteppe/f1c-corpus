int __thiscall sub_486460(_DWORD *this, int a2)
{
  int v2; // ecx
  int result; // eax
  int v4; // edx

  v2 = this[50];
  if ( !v2 )
    return 0;
  v4 = a2;
  result = *(_DWORD *)(v2 + 8);
  if ( a2 > *(_DWORD *)(v2 + 12) )
    return 0;
  if ( a2 > 0 )
  {
    do
    {
      if ( result )
        result = *(_DWORD *)(result + 36);
      --v4;
    }
    while ( v4 );
  }
  return result;
}

