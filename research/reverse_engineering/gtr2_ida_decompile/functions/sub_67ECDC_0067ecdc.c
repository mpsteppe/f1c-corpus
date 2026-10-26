int __stdcall sub_67ECDC(int a1, int a2)
{
  int *v3; // eax

  if ( !a1 )
    return a2;
  v3 = &a1;
  do
    v3 = (int *)(*v3 + 12);
  while ( *v3 );
  *v3 = a2;
  return a1;
}
