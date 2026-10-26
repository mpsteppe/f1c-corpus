// f1c  0x00464f90  size=64
int __stdcall sub_464F90(int a1)
{
  if ( a1 <= 1487 )
    return 0;
  if ( a1 <= 2975 )
    return 1;
  if ( a1 > 7200 )
    return (a1 > 28800) + 3;
  return 2;
}
