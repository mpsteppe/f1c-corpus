// positive sp value has been detected, the output may be wrong!
_DWORD *__usercall sub_49B4F6@<eax>(char a1@<al>, _DWORD *a2@<ecx>, int a3@<ebx>)
{
  *(_BYTE *)(a3 - 376765244) += a1;
  sub_49EC20(1, -1);
  *a2 = &off_5E6378;
  return a2;
}
