void __usercall sub_59AC7F(int a1@<ebp>)
{
  _DWORD *v1; // ecx
  _DWORD *v2; // esi
  int v3; // edi
  int v4; // ecx
  void (__thiscall ***v5)(_DWORD, int); // eax

  sub_58A5D8();
  v2 = v1;
  *(_DWORD *)(a1 - 20) = v1;
  *v1 = &off_5B9D4C;
  *(_DWORD *)(a1 - 4) = 1;
  sub_59A54D((void *)(a1 - 16));
  v3 = v2[3];
  *(_BYTE *)(a1 - 4) = 2;
  while ( v3 )
  {
    --v3;
    v4 = *(_DWORD *)(v2[2] + 4 * v3);
    if ( v4 )
    {
      v5 = (void (__thiscall ***)(_DWORD, int))sub_598C88(v4);
      if ( v5 )
        (**v5)(v5, 1);
    }
  }
  sub_58AA6F((LPVOID)v2[2]);
  *(_BYTE *)(a1 - 4) = 1;
  sub_59A5E9();
  *(_BYTE *)(a1 - 4) = 0;
  sub_5993AF(v2 + 6, 1);
  *v2 = &std::locale::facet::`vftable';
}
