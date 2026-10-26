int __usercall sub_62AA40@<eax>(unsigned int a1@<eax>, FILE *a2@<ebx>)
{
  int v3; // edi
  int result; // eax

  v3 = 4;
  do
  {
    result = fputc((unsigned __int8)a1, a2);
    a1 >>= 8;
    --v3;
  }
  while ( v3 );
  return result;
}
