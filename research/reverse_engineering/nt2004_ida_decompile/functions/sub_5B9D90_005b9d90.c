int __fastcall sub_5B9D90(_DWORD *a1, int a2, int a3, int a4)
{
  int v6; // edi

  v6 = 0;
  sub_5B9F40();
  sub_5BC6D0(a1 + 18, a3, a4, *a1);
  if ( !a2 )
  {
    while ( !a1[18] || (int)a1[4] > 0 && !v6 )
    {
      sub_5BDB80(0xAu);
      v6 = sub_5B9F20(a1);
    }
  }
  return v6;
}
