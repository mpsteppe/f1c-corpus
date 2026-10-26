int __usercall sub_436D40@<eax>(char **a1@<ecx>, char a2@<dil>)
{
  char *v2; // eax
  char v3; // bl
  int result; // eax

  v2 = *a1;
  v3 = byte_75CBC8;
  if ( !*a1 )
    v2 = &byte_629120;
  result = sub_4329D0((int)&byte_75CBC8, a2, v2, 1);
  byte_75CBC8 = v3;
  return result;
}
