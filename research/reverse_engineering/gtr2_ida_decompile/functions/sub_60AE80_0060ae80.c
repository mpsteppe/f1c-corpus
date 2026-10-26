int __stdcall sub_60AE80(int *a1)
{
  int v1; // ecx
  int result; // eax

  v1 = *a1;
  result = (*a1 & 1) != 0;
  if ( (*a1 & 2) != 0 )
    result |= 2u;
  if ( (v1 & 4) != 0 )
    result |= 4u;
  if ( (v1 & 0x10) != 0 )
    result |= 0x10u;
  if ( (v1 & 0x20) != 0 )
    result |= 0x20u;
  if ( (v1 & 0x40) != 0 )
    result |= 0x1000u;
  if ( (v1 & 8) != 0 )
    return result | 0x8000;
  return result;
}
