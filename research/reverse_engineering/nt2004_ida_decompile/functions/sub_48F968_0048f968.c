int __usercall sub_48F968@<eax>(int a1@<eax>, char a2@<dh>, _BYTE *a3@<ebx>, int _ESI@<esi>)
{
  *a3 += a2;
  __asm { rcr     byte ptr [esi-7Dh], 0C4h }
  return a1 + 1;
}
