int __stdcall sub_612C30(int *a1)
{
  int result; // eax
  int v2; // ecx

  result = 1;
  v2 = 0;
  if ( *a1 > 1 )
  {
    do
      result = 1 << ++v2;
    while ( *a1 > 1 << v2 );
  }
  *a1 = result;
  return result;
}
