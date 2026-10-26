void __usercall sub_60CAA0(_DWORD *a1@<ecx>, int a2@<ebp>)
{
  int v3; // eax

  v3 = a1[2387];
  if ( v3 )
  {
    a1[2411] = 0;
    a1[2412] = 0;
    (*(void (__stdcall **)(int, _DWORD))(*(_DWORD *)v3 + 368))(v3, 0);
    (*(void (__stdcall **)(_DWORD, _DWORD))(*(_DWORD *)a1[2387] + 428))(a1[2387], 0);
    if ( dword_FB40CC )
      (*(void (__stdcall **)(int))(*(_DWORD *)dword_FB40CC + 8))(dword_FB40CC);
    if ( dword_FB40D0 )
      (*(void (__stdcall **)(int))(*(_DWORD *)dword_FB40D0 + 8))(dword_FB40D0);
    if ( dword_FB40D4 )
      (*(void (__stdcall **)(int))(*(_DWORD *)dword_FB40D4 + 8))(dword_FB40D4);
    if ( dword_FB40D8 )
      (*(void (__stdcall **)(int))(*(_DWORD *)dword_FB40D8 + 8))(dword_FB40D8);
    if ( dword_FB40DC )
      (*(void (__stdcall **)(int))(*(_DWORD *)dword_FB40DC + 8))(dword_FB40DC);
    if ( dword_FB40E0 )
      (*(void (__stdcall **)(int))(*(_DWORD *)dword_FB40E0 + 8))(dword_FB40E0);
    if ( dword_FB40E4 )
      (*(void (__stdcall **)(int))(*(_DWORD *)dword_FB40E4 + 8))(dword_FB40E4);
    if ( dword_FB40E8 )
      (*(void (__stdcall **)(int))(*(_DWORD *)dword_FB40E8 + 8))(dword_FB40E8);
    if ( dword_FB40EC )
      (*(void (__stdcall **)(int))(*(_DWORD *)dword_FB40EC + 8))(dword_FB40EC);
    if ( dword_FB40F0 )
      (*(void (__stdcall **)(int))(*(_DWORD *)dword_FB40F0 + 8))(dword_FB40F0);
    if ( dword_FB40F4 )
      (*(void (__stdcall **)(int))(*(_DWORD *)dword_FB40F4 + 8))(dword_FB40F4);
    if ( dword_FB40F8 )
      (*(void (__stdcall **)(int))(*(_DWORD *)dword_FB40F8 + 8))(dword_FB40F8);
  }
  sub_60C8D0(a1 + 2285);
  sub_5FAE80(a1, a2);
}
