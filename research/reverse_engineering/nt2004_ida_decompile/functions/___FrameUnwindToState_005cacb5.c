void __cdecl __FrameUnwindToState(int a1, int a2, int a3, int a4)
{
  int i; // esi
  int v5; // eax

  for ( i = *(_DWORD *)(a1 + 8); i != a4; i = *(_DWORD *)(*(_DWORD *)(a3 + 8) + 8 * i) )
  {
    if ( i <= -1 || i >= *(_DWORD *)(a3 + 4) )
      sub_5CB21D();
    v5 = *(_DWORD *)(*(_DWORD *)(a3 + 8) + 8 * i + 4);
    if ( v5 )
      _CallSettingFrame(v5, a1, 259);
  }
  *(_DWORD *)(a1 + 8) = i;
}
