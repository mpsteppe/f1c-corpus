// f1c  0x004e2c70  size=44
void __usercall sub_4E2C70(int a1@<ecx>, double a2@<st0>)
{
  if ( dword_8AB6E4 == 2 )
  {
    sub_4B9CE0(&dword_8AB6EC);
    *(float *)(a1 + 2436) = a2;
  }
  else
  {
    *(float *)(a1 + 2436) = dbl_8AFEA0;
  }
}
