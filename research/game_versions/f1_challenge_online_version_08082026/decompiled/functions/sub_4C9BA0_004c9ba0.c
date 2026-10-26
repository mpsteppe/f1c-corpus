int __cdecl sub_4C9BA0(int a1, int a2)
{
  double v2; // st7
  double v3; // st6

  v2 = *(float *)(*(_DWORD *)a1 + 1856) + *(float *)(*(_DWORD *)a1 + 1848);
  v3 = *(float *)(*(_DWORD *)a2 + 1856) + *(float *)(*(_DWORD *)a2 + 1848);
  if ( v2 > v3 )
    return 1;
  if ( v2 >= v3 )
    return 0;
  return -1;
}
