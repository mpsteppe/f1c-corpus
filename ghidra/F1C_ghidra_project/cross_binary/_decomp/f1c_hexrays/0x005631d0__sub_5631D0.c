// f1c  0x005631d0  size=91
int __fastcall sub_5631D0(int a1, int a2, int a3, int a4)
{
  int v4; // edi
  int v6; // esi

  v4 = 0;
  if ( a4 <= 0 )
    return -1;
  while ( 1 )
  {
    v6 = *(_DWORD *)sub_5648B0(*(_DWORD *)(a1 + 4), v4);
    if ( a3 == sub_5644A0(v6) && sub_563E70(v6) == a2 )
      break;
    if ( ++v4 >= a4 )
      return -1;
  }
  return v4;
}
