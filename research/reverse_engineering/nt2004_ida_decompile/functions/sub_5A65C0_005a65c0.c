int __thiscall sub_5A65C0(int *this, int a2)
{
  int v2; // eax
  int v4; // eax

  v2 = *(_DWORD *)(a2 + 16);
  if ( v2 )
  {
    v4 = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)v2 + 8))(*(_DWORD *)(a2 + 16));
    *this = v4;
    if ( v4 )
    {
      sub_591C60((int)this, -1, aInvalidParamet);
      return -1;
    }
    *(_DWORD *)(a2 + 16) = 0;
  }
  return 0;
}
