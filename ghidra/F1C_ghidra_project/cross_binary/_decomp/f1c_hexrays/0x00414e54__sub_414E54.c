// f1c  0x00414e54  size=12
// positive sp value has been detected, the output may be wrong!
void __usercall sub_414E54(char a1@<bl>, int a2@<edi>, int _ESI@<esi>)
{
  char v3; // cc

  v3 = ((char)(a1 + *(_BYTE *)(a2 + 51)) < 0) ^ __OFADD__(a1, *(_BYTE *)(a2 + 51)) | (a1 + *(_BYTE *)(a2 + 51) == 0);
  *(_BYTE *)(a2 + 51) += a1;
  __asm { rcr     byte ptr [esi-7Fh], 0C4h }
  if ( !v3 )
  {
    *(_DWORD *)(_ESI + 12) = a2;
    *(_BYTE *)(_ESI + 16) = a1;
  }
}
