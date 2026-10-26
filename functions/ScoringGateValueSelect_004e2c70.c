void __usercall sub_4E2C70(int a1@<ecx>, double a2@<st0>)
{
  if ( dword_8AB6E4 == 2 )
  {
    Delegation(&dword_8AB6EC);
    *(float *)(a1 + 2436) = a2;
  }
  else
  {
    *(float *)(a1 + 2436) = dbl_8AFEA0;
  }
}
