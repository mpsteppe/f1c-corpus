// f1c  0x00553980  size=104
int __stdcall sub_553980(unsigned int **a1, int a2, int a3, int a4, int a5)
{
  _DWORD *v5; // eax
  unsigned int *v6; // esi

  v5 = (_DWORD *)sub_587C03(36);
  if ( v5 )
    v6 = sub_5532A0(v5);
  else
    v6 = 0;
  if ( a2 )
    sub_553370(v6, a2);
  if ( a3 )
    sub_553620(v6, a3);
  sub_553630(v6, a4, a5);
  sub_55C2A0(v6);
  if ( a1 )
    *a1 = v6;
  return 0;
}
