void __thiscall sub_5A8170(_DWORD *this, int a2)
{
  int v3; // eax

  if ( a2 && *(_DWORD *)(a2 + 24) )
  {
    while ( *(int *)(a2 + 12) > 0 )
      sub_5A8220(a2);
    v3 = *(_DWORD *)(a2 + 24);
    *(_DWORD *)(a2 + 12) = 0;
    *this = (*(int (__stdcall **)(int))(*(_DWORD *)v3 + 8))(v3);
    *(_DWORD *)(a2 + 24) = 0;
  }
}
