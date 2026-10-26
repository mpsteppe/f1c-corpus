int __usercall sub_4AEAB0@<eax>(int a1@<ecx>, __int32 a2@<ebp>)
{
  int v3; // eax
  int v4; // eax

  v3 = *(_DWORD *)(a1 + 596);
  if ( v3 > 0 )
  {
    v4 = v3 - 1;
    *(_DWORD *)(a1 + 596) = v4;
    if ( !v4 )
      sub_49A6B0(a2, 1);
  }
  if ( dword_75B17C == 1 )
    return 0;
  if ( *(int *)(a1 + 600) >= 0 )
  {
    sub_49A2A0((_DWORD *)a1);
    return 0;
  }
  sub_4AE810(a1, 0);
  if ( !*(_BYTE *)(a1 + 608) )
    return 0;
  if ( byte_B722E4 )
    sub_4D41C0(2, 7);
  else
    sub_4D41C0(2, 6);
  return 0;
}
