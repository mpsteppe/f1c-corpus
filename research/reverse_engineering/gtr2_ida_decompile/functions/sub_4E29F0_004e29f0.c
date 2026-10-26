int __thiscall sub_4E29F0(_DWORD *this, int a2)
{
  int v2; // edx
  int result; // eax

  v2 = a2;
  result = this[2];
  if ( a2 > this[3] )
    return 0;
  if ( a2 > 0 )
  {
    do
    {
      if ( result )
        result = *(_DWORD *)(result + 32);
      --v2;
    }
    while ( v2 );
  }
  return result;
}
