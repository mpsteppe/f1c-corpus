int __cdecl sub_567B06(_DWORD *a1, unsigned int *a2, _DWORD *a3, int a4, int a5)
{
  unsigned int *v6; // eax
  int v8; // eax
  int v9; // ebx
  unsigned int v10; // [esp+4h] [ebp-4h] BYREF
  unsigned int *v11; // [esp+20h] [ebp+18h]

  v10 = 0;
  v6 = (unsigned int *)(*(int (__cdecl **)(_DWORD, int, int))(a5 + 32))(*(_DWORD *)(a5 + 40), 19, 4);
  v11 = v6;
  if ( !v6 )
    return -4;
  v8 = sub_567781(a2, a1, 0x13u, 0x13u, 0, 0, a3, a4, &v10, v6);
  v9 = v8;
  if ( v8 == -3 )
  {
    *(_DWORD *)(a5 + 24) = "oversubscribed dynamic bit lengths tree";
  }
  else if ( v8 == -5 || !*a2 )
  {
    *(_DWORD *)(a5 + 24) = "incomplete dynamic bit lengths tree";
    v9 = -3;
  }
  (*(void (__cdecl **)(_DWORD, unsigned int *))(a5 + 36))(*(_DWORD *)(a5 + 40), v11);
  return v9;
}
