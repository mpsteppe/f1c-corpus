LRESULT __usercall sub_480250@<eax>(int a1@<edi>)
{
  signed int v1; // ebp
  LPARAM v2; // ebx
  LRESULT result; // eax
  const char *v4; // edi
  char *v5; // eax
  LRESULT v6; // edi
  LRESULT v7; // eax
  char *v8; // eax
  LRESULT v9; // edi
  int v10; // [esp-4h] [ebp-24h]
  LRESULT v11; // [esp+4h] [ebp-1Ch]
  LPARAM lParam[2]; // [esp+8h] [ebp-18h] BYREF
  int v13; // [esp+10h] [ebp-10h]

  SendDlgItemMessageA(dword_B6CE6C, 1000, 0x184u, 0, 0);
  SendDlgItemMessageA(dword_B6CE6C, 1003, 0x184u, 0, 0);
  v1 = 0;
  v2 = 0;
  result = sub_5387C0(&unk_BE1CFC) - 1;
  lParam[1] = result;
  if ( result >= 0 )
  {
    v10 = a1;
    do
    {
      v4 = (const char *)sub_5387F0(&unk_BE1CFC, v2, v10);
      if ( (unsigned __int8)sub_53A120() )
      {
        v8 = sub_41D840(&byte_91CC38, v4);
        v9 = SendDlgItemMessageA(dword_B6CE6C, 1003, 0x180u, 0, (LPARAM)v8);
        SendDlgItemMessageA(dword_B6CE6C, 1003, 0x19Au, v9, v2);
        v7 = SendDlgItemMessageA(dword_B6CE6C, 1003, 0x198u, v9, (LPARAM)lParam);
      }
      else
      {
        v5 = sub_41D840(&byte_91CC38, v4);
        v6 = SendDlgItemMessageA(dword_B6CE6C, 1000, 0x180u, 0, (LPARAM)v5);
        SendDlgItemMessageA(dword_B6CE6C, 1000, 0x19Au, v6, v2);
        v7 = SendDlgItemMessageA(dword_B6CE6C, 1000, 0x198u, v6, (LPARAM)lParam);
      }
      if ( v7 != -1 && v1 <= v13 - lParam[0] )
        v1 = v13 - lParam[0];
      result = v11;
      ++v2;
    }
    while ( v2 <= v11 );
    if ( v1 > 0 )
    {
      SendDlgItemMessageA(dword_B6CE6C, 1000, 0x194u, v1, 0);
      return SendDlgItemMessageA(dword_B6CE6C, 1003, 0x194u, v1, 0);
    }
  }
  return result;
}
