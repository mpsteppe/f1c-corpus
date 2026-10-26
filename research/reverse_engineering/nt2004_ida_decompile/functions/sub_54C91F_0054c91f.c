int __cdecl sub_54C91F(_DWORD *a1, char a2)
{
  int v2; // eax
  int result; // eax

  v2 = a1[4];
  if ( v2 != 200 && v2 != 201 )
  {
    *(_DWORD *)(*a1 + 20) = 18;
    *(_DWORD *)(*a1 + 24) = a1[4];
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
  }
  result = sub_54C7DE(a1);
  if ( result == 1 )
    return 1;
  if ( result == 2 )
  {
    if ( a2 )
    {
      *(_DWORD *)(*a1 + 20) = 50;
      (*(void (__cdecl **)(_DWORD *))*a1)(a1);
    }
    sub_5538CA(a1);
    return 2;
  }
  return result;
}
