void __userpurge sub_59469C(unsigned int a1@<eax>, _BYTE *a2@<ecx>, int a3@<edi>, int a4)
{
  char v4; // cf

  *(_DWORD *)a1 += a1;
  LOBYTE(a2) = BYTE1(a2) + (_BYTE)a2;
  __writeeflags(a1);
  *(_BYTE *)(a3 + 1) = *a2 + v4 + a1;
  _disable();
  JUMPOUT(0x4075E2);
}
