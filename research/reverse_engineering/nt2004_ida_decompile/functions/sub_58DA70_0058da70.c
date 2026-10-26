int __usercall sub_58DA70@<eax>(unsigned int a1@<ebx>, int a2, int a3)
{
  int v3; // edx
  int *v4; // eax
  int *v5; // ecx
  int v6; // esi
  int v8; // [esp+0h] [ebp-50h] BYREF
  char v9; // [esp+4h] [ebp-4Ch] BYREF

  v3 = a3;
  v8 = a2;
  if ( a3 >= 1 )
  {
    v4 = &a3;
    v5 = (int *)&v9;
    do
    {
      v6 = v4[1];
      ++v4;
      *v5++ = v6;
      --v3;
    }
    while ( v3 );
  }
  return sub_58D780(a1, &v8);
}
