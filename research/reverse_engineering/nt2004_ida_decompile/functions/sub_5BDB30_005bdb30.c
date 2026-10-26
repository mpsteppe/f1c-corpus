int __fastcall sub_5BDB30(int a1, int a2)
{
  int v2; // eax
  int result; // eax
  int v4; // ecx
  int v5; // eax
  _DWORD v6[2]; // [esp+4h] [ebp-8h] BYREF

  v6[0] = a2;
  v2 = sub_5B9FF0();
  result = sub_5BE0C0(v2, v6);
  if ( result )
  {
    v4 = *(_DWORD *)(result + 4) - 1;
    *(_DWORD *)(result + 4) = v4;
    if ( !v4 )
    {
      v5 = sub_5B9FF0();
      return sub_5BE070(v5, v6);
    }
  }
  return result;
}
