int __cdecl sub_44A130(int a1, int a2)
{
  if ( *(float *)(a1 + 12) > (double)*(float *)(a2 + 12) )
    return 1;
  if ( *(float *)(a1 + 12) >= (double)*(float *)(a2 + 12) )
    return 0;
  return -1;
}
