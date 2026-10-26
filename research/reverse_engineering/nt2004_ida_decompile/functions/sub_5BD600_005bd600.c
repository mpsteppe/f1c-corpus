int __fastcall sub_5BD600(int a1, _BYTE *a2, int a3)
{
  __int16 v6; // di
  int v7; // eax
  int v8; // ebx
  _DWORD *v9; // edi
  int v10; // [esp+10h] [ebp-8h] BYREF
  int v11; // [esp+14h] [ebp-4h] BYREF

  if ( a3 < 5 )
    return 4;
  sub_5BD1D0(a1, a2, a3, &v10, &v11);
  v6 = v11;
  v7 = sub_5BD940(v11);
  v8 = v7;
  if ( v7 == -1 )
  {
    v9 = sub_5BA500(a1, v10, v6);
    if ( sub_5BA600(v9) )
      return 5;
  }
  else
  {
    v9 = (_DWORD *)sub_5BDA10(a1, v7);
  }
  if ( sub_5BD220(__SPAIR64__((unsigned int)v9, a3), a1, a2, a3, 0) < 0 )
    return 4;
  if ( v8 == -1 )
    sub_5BD910(a1, v9);
  (*(void (__fastcall **)(int, int, _DWORD *, _DWORD))(a1 + 1152))(a1, 1, v9, *(_DWORD *)(a1 + 1156));
  return 0;
}
