void __fastcall sub_5BE770(_BYTE *a1, int a2, int a3)
{
  int i; // esi

  for ( i = 0; i < a3; ++i )
    *(_BYTE *)(i + a2) = sub_5BE660(a1, *(_BYTE *)(i + a2));
}
