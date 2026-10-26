int __fastcall sub_41EF40(int a1, int a2)
{
  int result; // eax
  int v5; // ecx
  int v6; // edx
  int v7; // esi
  int v8; // ebp
  int v9; // ebp

  result = 0;
  if ( !a1 )
    return a2;
  if ( !a2 )
    return a1;
  v5 = *(_DWORD *)(a1 + 412);
  v6 = *(_DWORD *)(a2 + 412);
  if ( v6 > v5 )
    return a1;
  if ( v6 < v5 )
    return a2;
  v7 = 1;
  if ( dword_5C329C >= 1 )
  {
    while ( 1 )
    {
      v8 = sub_41EFE0(a1, v7);
      if ( v8 > sub_41EFE0(a2, v7) )
        break;
      v9 = sub_41EFE0(a1, v7);
      if ( v9 < sub_41EFE0(a2, v7) )
        return a2;
      if ( v7 == dword_5C329C )
        break;
      if ( ++v7 > dword_5C329C )
        return 0;
    }
    return a1;
  }
  return result;
}
