int __cdecl sub_58D680(int a1, _DWORD *a2)
{
  if ( !sub_58D5A0(a1, &a1) )
    return 0;
  *a2 = ((2 * *(unsigned __int16 *)(*(_DWORD *)a1 + 16) + 3) & 0xFFFFFFFC) + *(_DWORD *)a1 + 24;
  return 1;
}
