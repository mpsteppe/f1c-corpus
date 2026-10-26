int __userpurge sub_46C74C@<eax>(char a1@<al>, int a2@<ebx>, int a3@<edi>, int a4, int a5)
{
  int *v5; // ebp
  int result; // eax

  *(_DWORD *)(a3 + 1149960185) |= a2;
  v5 = &dword_7CD2B8;
  if ( (a1 & 4) == 0 )
    v5 = &dword_7CD470;
  result = v5[a5];
  if ( a5 >= 103 )
  {
    v5[a5] = -1;
  }
  else
  {
    qmemcpy(&v5[a5], &v5[a5 + 1], 4 * (103 - a5));
    v5[103] = -1;
  }
  return result;
}
