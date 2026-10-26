int __cdecl sub_5FC620(int a1, int a2)
{
  if ( *(float *)(*(_DWORD *)a1 + 16) > (double)*(float *)(*(_DWORD *)a2 + 16) )
    return 1;
  if ( *(float *)(*(_DWORD *)a1 + 16) >= (double)*(float *)(*(_DWORD *)a2 + 16) )
    return 0;
  return -1;
}
