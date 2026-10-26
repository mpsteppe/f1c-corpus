int __thiscall sub_5457F0(_DWORD *this, int a2)
{
  int v2; // edx
  int result; // eax

  v2 = a2;
  if ( a2 < 0 || a2 >= this[73] )
    return 0;
  result = this[74];
  if ( a2 > 0 )
  {
    do
    {
      --v2;
      result = *(_DWORD *)(result + 108);
    }
    while ( v2 );
  }
  return result;
}

