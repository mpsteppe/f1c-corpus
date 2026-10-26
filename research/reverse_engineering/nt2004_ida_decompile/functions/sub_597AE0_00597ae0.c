int __thiscall sub_597AE0(_DWORD *this, int a2)
{
  int v2; // edx
  int result; // eax

  v2 = a2;
  if ( a2 < 0 || a2 >= this[72] )
    return 0;
  result = this[73];
  if ( a2 > 0 )
  {
    do
    {
      --v2;
      result = *(_DWORD *)(result + 204);
    }
    while ( v2 );
  }
  return result;
}
