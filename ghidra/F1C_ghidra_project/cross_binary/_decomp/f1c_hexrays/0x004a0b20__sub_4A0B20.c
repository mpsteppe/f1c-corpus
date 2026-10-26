// f1c  0x004a0b20  size=118
int __stdcall sub_4A0B20(_DWORD *a1)
{
  int v1; // edi

  v1 = a1[4111];
  if ( a1[4645] == *(_DWORD *)(dword_7C54F0[dword_7C54DC] + 18580) && v1 % 5 == 1 )
    sub_4D8760(13, 0);
  if ( a1[4120] == 1 && v1 >= 2 && !((v1 + 3) % 5) )
    sub_4D8760(19, 0);
  return 0;
}
