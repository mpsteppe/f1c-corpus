// f1c  0x004b3d70  size=55
int __cdecl sub_4B3D70(float *a1, float *a2)
{
  if ( *a1 > (double)*a2 )
    return 1;
  if ( *a1 >= (double)*a2 )
    return 0;
  return -1;
}
