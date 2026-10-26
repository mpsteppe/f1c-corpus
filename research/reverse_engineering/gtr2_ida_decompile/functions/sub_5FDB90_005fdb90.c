int __userpurge sub_5FDB90@<eax>(int *a1@<ecx>, float a2@<ebx>, int a3@<ebp>, int a4@<edi>, int a5, _DWORD *a6)
{
  int result; // eax

  result = sub_5FC840(a1, a3, a4, 1);
  if ( !result )
  {
    if ( (*a1 & 0x200) != 0 )
      return sub_5FD150((int)a1, a5, (int)a6);
    else
      return sub_5FCE80(a1, a2, a4, (int)a1, a5, a6);
  }
  return result;
}
