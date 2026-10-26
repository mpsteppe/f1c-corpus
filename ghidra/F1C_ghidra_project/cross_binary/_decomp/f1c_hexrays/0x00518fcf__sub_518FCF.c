// f1c  0x00518fcf  size=74
int __cdecl sub_518FCF(int a1, int a2, unsigned int a3)
{
  int result; // eax
  int v4; // eax

  sub_517FD0(a1, (unsigned __int8 *)(a1 + 268));
  if ( (*(_BYTE *)(a1 + 268) & 0x20) != 0 || (result = sub_51189C(a1, "unknown critical chunk"), a2) )
  {
    v4 = *(_DWORD *)(a1 + 88);
    if ( (v4 & 4) != 0 )
      *(_DWORD *)(a1 + 88) = v4 | 8;
    return sub_518828(a1, a3);
  }
  return result;
}
