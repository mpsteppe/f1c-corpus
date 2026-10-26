int __cdecl sub_4583A0(int a1, int a2)
{
  if ( *(float *)(a1 + 4) > (double)*(float *)(a2 + 4) )
    return 1;
  if ( *(float *)(a1 + 4) >= (double)*(float *)(a2 + 4) )
    return 0;
  return -1;
}
