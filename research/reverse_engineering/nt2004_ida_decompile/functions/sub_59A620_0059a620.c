int __thiscall sub_59A620(int *this, unsigned __int16 a2)
{
  int v2; // edx
  int result; // eax

  v2 = 0;
  if ( a2 >= this[4] )
    return 0;
  for ( result = this[9]; result; ++v2 )
  {
    if ( v2 == a2 )
      break;
    result = *(_DWORD *)(result + 168);
  }
  return result;
}
