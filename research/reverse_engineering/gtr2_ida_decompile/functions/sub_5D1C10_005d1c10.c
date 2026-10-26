int __userpurge sub_5D1C10@<eax>(int a1@<ecx>, int a2@<ebx>, int a3@<esi>, int a4)
{
  int result; // eax
  int v6; // esi
  int v7; // [esp-8h] [ebp-Ch]
  int v8; // [esp-4h] [ebp-8h]

  result = *(_DWORD *)(a1 + 16);
  if ( result )
  {
    v8 = a3;
    do
    {
      v6 = result;
      result = *(_DWORD *)(result + 16);
    }
    while ( result );
    if ( v6 != a1 )
    {
      v7 = a2;
      do
      {
        result = (*(int (__thiscall **)(_DWORD, int, int))(**(_DWORD **)(*(_DWORD *)(v6 + 8) + 60) + 4))(
                   *(_DWORD *)(*(_DWORD *)(v6 + 8) + 60),
                   v7,
                   v8);
        v6 = *(_DWORD *)(v6 + 12);
        if ( result == a4 )
          result = sub_5C40C0();
      }
      while ( v6 != a1 );
    }
  }
  return result;
}
