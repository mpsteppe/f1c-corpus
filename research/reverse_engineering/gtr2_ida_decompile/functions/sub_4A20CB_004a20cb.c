// positive sp value has been detected, the output may be wrong!
int __usercall sub_4A20CB@<eax>(int a1@<ecx>, _DWORD *a2@<esi>)
{
  int result; // eax
  int v3; // ecx

  a2[79] = (a2[70] * a2[80] + a1 / 2) / a1;
  result = a2[79];
  v3 = a2[80];
  if ( result >= 0 )
  {
    if ( result > v3 )
      a2[79] = v3;
  }
  else
  {
    a2[79] = 0;
  }
  return result;
}
