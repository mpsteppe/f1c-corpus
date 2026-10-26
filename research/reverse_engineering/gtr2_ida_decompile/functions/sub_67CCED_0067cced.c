int __usercall sub_67CCED@<eax>(float *a1@<eax>, float *a2@<ecx>)
{
  int v2; // edx
  double v3; // st7

  v2 = 16;
  do
  {
    v3 = a1[3] * *a1;
    a1 += 4;
    *a2 = v3;
    a2 += 4;
    --v2;
    *(a2 - 3) = *(a1 - 3) * *(a1 - 1);
    *(a2 - 2) = *(a1 - 2) * *(a1 - 1);
    *(a2 - 1) = *(a1 - 1);
  }
  while ( v2 );
  return 0;
}
