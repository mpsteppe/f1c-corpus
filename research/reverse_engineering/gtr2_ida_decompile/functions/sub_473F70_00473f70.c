char __stdcall sub_473F70(int a1, double *a2, _WORD *a3, _DWORD *a4)
{
  *a2 = sub_58F2F0(&unk_FB1E98);
  LOBYTE(a2) = dword_B640C8[0];
  if ( sub_42FEB0(&dword_B640C0, a1) )
  {
    BYTE1(a2) = 1;
    sub_42FEA0(&dword_B640C0, a1);
  }
  else
  {
    BYTE1(a2) = 0;
  }
  *a4 = 2;
  *a3 = (_WORD)a2;
  return 1;
}
