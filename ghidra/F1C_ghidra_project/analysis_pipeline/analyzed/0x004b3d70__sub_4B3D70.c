// Address: 0x004b3d70
// Size: 55 bytes
// Name: sub_4B3D70
// Type: int __cdecl(float *, float *)
// Source: IDA Hex-Rays decompilation

int __cdecl sub_4B3D70(float *a1, float *a2)
{
  if ( *a1 > (double)*a2 )
    return 1;
  if ( *a1 >= (double)*a2 )
    return 0;
  return -1;
}
