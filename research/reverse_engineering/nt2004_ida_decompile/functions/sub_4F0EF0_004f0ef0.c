int __cdecl sub_4F0EF0(const void *a1, const void *a2)
{
  double v2; // st7
  double v3; // st6

  v2 = *(float *)(*(_DWORD *)a1 + 4672) + *(float *)(*(_DWORD *)a1 + 4664);
  v3 = *(float *)(*(_DWORD *)a2 + 4672) + *(float *)(*(_DWORD *)a2 + 4664);
  if ( v2 > v3 )
    return 1;
  if ( v2 >= v3 )
    return 0;
  return -1;
}
