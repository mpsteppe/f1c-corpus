// f1c  0x0053f6e0  size=63
int __thiscall sub_53F6E0(int *this, int a2)
{
  int v2; // eax
  int v4; // eax

  v2 = *(_DWORD *)(a2 + 12);
  if ( v2 )
  {
    v4 = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)v2 + 8))(*(_DWORD *)(a2 + 12));
    *this = v4;
    if ( v4 )
    {
      sub_53C590(-1, aInvalidParamet);
      return -1;
    }
    *(_DWORD *)(a2 + 12) = 0;
  }
  return 0;
}
