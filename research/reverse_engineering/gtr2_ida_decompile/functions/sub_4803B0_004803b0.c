LRESULT sub_4803B0()
{
  LRESULT result; // eax
  LRESULT v1; // ebx
  LRESULT v2; // esi
  LPARAM lParam[256]; // [esp+Ch] [ebp-400h] BYREF

  result = SendDlgItemMessageA(dword_B6CE6C, 1003, 0x191u, 0x100u, (LPARAM)lParam);
  v1 = result;
  v2 = 0;
  if ( result <= 0 )
  {
    dword_759E50 = dword_B737D4;
  }
  else
  {
    do
    {
      SendDlgItemMessageA(dword_B6CE6C, 1003, 0x199u, lParam[v2], 0);
      sub_53A120();
      result = sub_53B1C0(&unk_BE1CFC);
      ++v2;
    }
    while ( v2 < v1 );
    dword_759E50 = dword_B737D4;
  }
  return result;
}
