char __userpurge sub_48909D@<al>(char a1@<zf>, int a2@<eax>, int a3@<ecx>, int a4)
{
  _DWORD *v4; // ecx

  v4 = (_DWORD *)(a3 - 1);
  if ( !a1 && v4 )
    JUMPOUT(0x48902A);
  LOBYTE(a2) = a2 & 4;
  *v4 = a2;
  return 1;
}
