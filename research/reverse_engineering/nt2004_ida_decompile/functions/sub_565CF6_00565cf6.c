int __cdecl sub_565CF6(int a1, int a2, int a3, int a4, int a5)
{
  int v6; // [esp-10h] [ebp-A0h]
  int v7; // [esp-4h] [ebp-94h]
  _BYTE v8[136]; // [esp+8h] [ebp-88h] BYREF

  v7 = *(_DWORD *)(a1 + 284) + 128;
  v6 = *(_DWORD *)(a2 + 80);
  if ( byte_61765C )
    return sub_568C41(a3, v8, v6, a4, a5, v7);
  else
    return sub_5688E6(a3, v8, v6, a4, a5, v7);
}
