int __stdcall sub_4C58A0(int a1, int a2, int a3, int a4)
{
  int v4; // eax
  int v5; // eax

  if ( !sub_4C5840(a4) )
    return 1;
  v4 = sub_5679C0(a3);
  if ( !v4 )
    return 1;
  v5 = sub_567970(v4);
  sub_587DD0(a1, v5, a2 - 1);
  *(_BYTE *)(a2 - 1 + a1) = 0;
  return 0;
}
