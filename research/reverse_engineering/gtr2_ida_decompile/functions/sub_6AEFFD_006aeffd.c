int __thiscall sub_6AEFFD(_DWORD *this, int a2, unsigned int *a3, _DWORD *a4)
{
  int v5; // ebx
  unsigned int v6; // eax

  v5 = (*(int (__thiscall **)(_DWORD *, _DWORD))(*this + 84))(this, *(_DWORD *)(a2 + 108));
  v6 = (*(int (__thiscall **)(_DWORD *, _DWORD))(*this + 88))(this, *(_DWORD *)(a2 + 108));
  *a3 = v6;
  switch ( v5 )
  {
    case 0xB:
      if ( v6 < this[10] )
      {
        *a4 = 1;
        return 0;
      }
      break;
    case 6:
      if ( v6 < 8 )
      {
        *a4 = 3;
        return 0;
      }
      break;
    case 0xFFFF:
      *a4 = 0;
      return 0;
  }
  return -2147467259;
}
