int __stdcall sub_6DF685(int a1, _DWORD *a2, int a3, int a4, int a5)
{
  int v6; // eax
  int v7; // ebx

  if ( !(*(int (__stdcall **)(_DWORD, int, int))(a5 + 32))(*(_DWORD *)(a5 + 40), 19, 4) )
    return -4;
  v6 = sub_6DF306();
  v7 = v6;
  if ( v6 == -3 )
  {
    *(_DWORD *)(a5 + 24) = "oversubscribed dynamic bit lengths tree";
  }
  else if ( v6 == -5 || !*a2 )
  {
    *(_DWORD *)(a5 + 24) = "incomplete dynamic bit lengths tree";
    v7 = -3;
  }
  (*(void (__stdcall **)(_DWORD))(a5 + 36))(*(_DWORD *)(a5 + 40));
  return v7;
}
