// positive sp value has been detected, the output may be wrong!
int __userpurge sub_4330FA@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>, int a4, int a5)
{
  double v5; // st7

  v5 = 0.0;
  if ( a1 == 1 )
    return sub_432FC0(a2, a3, -0.5);
  if ( a1 == 2 )
    v5 = 0.5;
  return sub_432FC0(a2, a3, v5);
}
