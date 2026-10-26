int __fastcall sub_62F360(_DWORD *a1, int a2)
{
  int v4; // eax
  int (__stdcall *v5)(_DWORD); // eax
  int v6; // eax

  if ( *a1 == 4 || *a1 == 5 )
    (*(void (__fastcall **)(_DWORD, _DWORD))(a2 + 36))(*(_DWORD *)(a2 + 40), a1[3]);
  if ( *a1 == 6 )
    sub_62FB00(a1[1], a2);
  v4 = a1[10];
  a1[13] = v4;
  a1[12] = v4;
  v5 = (int (__stdcall *)(_DWORD))a1[14];
  *a1 = 0;
  a1[7] = 0;
  a1[8] = 0;
  if ( v5 )
  {
    v6 = v5(0);
    a1[15] = v6;
    *(_DWORD *)(a2 + 48) = v6;
  }
  (*(void (__fastcall **)(_DWORD, _DWORD))(a2 + 36))(*(_DWORD *)(a2 + 40), a1[10]);
  (*(void (__fastcall **)(_DWORD, _DWORD))(a2 + 36))(*(_DWORD *)(a2 + 40), a1[9]);
  (*(void (__fastcall **)(_DWORD, _DWORD *))(a2 + 36))(*(_DWORD *)(a2 + 40), a1);
  return 0;
}
