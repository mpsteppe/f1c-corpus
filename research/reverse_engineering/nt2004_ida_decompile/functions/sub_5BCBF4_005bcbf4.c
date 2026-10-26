// positive sp value has been detected, the output may be wrong!
void __usercall __noreturn sub_5BCBF4(char a1@<bl>, int a2@<edi>, int _ESI@<esi>)
{
  *(_BYTE *)(a2 + 51) += a1;
  __asm { rcr     byte ptr [esi-7Fh], 0C4h }
  while ( 1 )
    ;
}
