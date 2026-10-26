int __stdcall sub_5A1A60(unsigned int **a1, int a2, int a3, int a4, int a5)
{
  _DWORD *v5; // eax
  unsigned int *v6; // esi

  v5 = operator new(0x24u);
  if ( v5 )
    v6 = sub_5A1340(v5);
  else
    v6 = 0;
  if ( a2 )
    sub_5A1410(v6, a2);
  if ( a3 )
    sub_5A16B0(v6, a3);
  sub_5A16C0(v6, a4, a5);
  sub_5B4020(v6);
  if ( a1 )
    *a1 = v6;
  return 0;
}
