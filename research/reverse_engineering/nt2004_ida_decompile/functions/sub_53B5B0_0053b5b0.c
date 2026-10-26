int __fastcall sub_53B5B0(int a1, _DWORD *a2, int a3, int a4, int a5)
{
  int v6; // ecx
  int v7; // edi
  int v9; // eax
  int v10; // esi
  int v11; // ecx
  int v12; // [esp+10h] [ebp-4h] BYREF

  v6 = *(_DWORD *)(a5 + 40);
  v12 = 0;
  v7 = (*(int (__fastcall **)(int, int, int))(a5 + 32))(v6, 19, 4);
  if ( !v7 )
    return -4;
  v9 = sub_53B660(19, 0, 0, a3, a2, a4, &v12, v7);
  v10 = v9;
  if ( v9 == -3 )
  {
    v11 = *(_DWORD *)(a5 + 40);
    *(_DWORD *)(a5 + 24) = aOversubscribed;
    (*(void (__fastcall **)(int, int))(a5 + 36))(v11, v7);
    return -3;
  }
  else
  {
    if ( v9 == -5 || !*a2 )
    {
      *(_DWORD *)(a5 + 24) = aIncompleteDyna;
      v10 = -3;
    }
    (*(void (__fastcall **)(_DWORD, int))(a5 + 36))(*(_DWORD *)(a5 + 40), v7);
    return v10;
  }
}
