int __stdcall sub_553980(unsigned int **a1, int a2, int a3, int a4, int a5)
{
  _DWORD *v5; // eax
  unsigned int *v6; // esi

  v5 = (_DWORD *)OperatorNewNhMallocWrapper(36);
  if ( v5 )
    v6 = ObjectAllocationWithZeroInit(v5);
  else
    v6 = 0;
  if ( a2 )
    sub_553370(v6, a2);
  if ( a3 )
    SetterWrites0x10Returns0(v6, a3);
  TwoFieldSetter_3630(v6, a4, a5);
  sub_55C2A0(v6);
  if ( a1 )
    *a1 = v6;
  return 0;
}
