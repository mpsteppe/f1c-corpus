// positive sp value has been detected, the output may be wrong!
void __usercall sub_4E3126(char a1@<cl>, int a2@<ebx>, int a3@<edi>, double a4@<st0>)
{
  *(_BYTE *)(a2 + 117) += a1;
  *(double *)(a3 + 94) = a4;
}
