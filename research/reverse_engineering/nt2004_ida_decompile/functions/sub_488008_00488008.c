_DWORD *__usercall sub_488008@<eax>(char a1@<dh>, _DWORD *a2@<ecx>, _BYTE *a3@<ebx>, int _ESI@<esi>)
{
  *a3 += a1;
  __asm { rcr     byte ptr [esi-7Dh], 0C4h }
  sub_46FAE0(a2, 0);
  *a2 = &off_5DC388;
  a2[210] = &dword_769848;
  a2[212] = 0;
  a2[211] = 1;
  a2[213] = 1;
  a2[214] = 1;
  a2[215] = 473;
  sub_49D5B0(off_600E2C, -1);
  sub_49D5B0(aInternet, -1);
  sub_46FB30(a2);
  return a2;
}
