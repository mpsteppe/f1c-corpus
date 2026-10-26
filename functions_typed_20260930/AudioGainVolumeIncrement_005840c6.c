int __usercall sub_5840C6@<eax>(char a1@<al>, int a2@<ecx>)
{
  *(_BYTE *)(a2 + 46276) += a1;
  return MutexWaitWith1msTimeoutRelease(a2);
}

