// f1c  0x0051227f  size=51
int __cdecl sub_51227F(int a1, int a2, _DWORD *a3, _DWORD *a4)
{
  if ( !a1 || !a2 || (*(_BYTE *)(a2 + 8) & 8) == 0 || !a3 )
    return 0;
  *a3 = *(_DWORD *)(a2 + 16);
  *a4 = *(unsigned __int16 *)(a2 + 20);
  return 8;
}
