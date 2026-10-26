// f1c  0x0051215a  size=41
int __cdecl sub_51215A(int a1, int a2, double *a3)
{
  if ( !a1 || !a2 || (*(_BYTE *)(a2 + 8) & 1) == 0 || !a3 )
    return 0;
  *a3 = *(float *)(a2 + 40);
  return 1;
}
