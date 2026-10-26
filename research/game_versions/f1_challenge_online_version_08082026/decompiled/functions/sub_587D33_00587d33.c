int __cdecl sub_587D33(int a1)
{
  int v1; // edi

  v1 = -1;
  if ( (*(_BYTE *)(a1 + 12) & 0x83) != 0 )
  {
    v1 = sub_58A05A(a1);
    sub_58C411(a1);
    if ( (int)sub_58C331(*(_DWORD *)(a1 + 16)) >= 0 )
    {
      if ( *(_DWORD *)(a1 + 28) )
      {
        sub_58AA6F(*(LPVOID *)(a1 + 28));
        *(_DWORD *)(a1 + 28) = 0;
      }
    }
    else
    {
      v1 = -1;
    }
  }
  *(_DWORD *)(a1 + 12) = 0;
  return v1;
}
