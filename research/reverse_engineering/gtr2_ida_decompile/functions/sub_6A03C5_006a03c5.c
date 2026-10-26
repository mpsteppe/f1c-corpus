int __thiscall sub_6A03C5(void *this, int a2, int *a3, _DWORD *a4)
{
  int v5; // eax
  int v6; // eax

  v5 = (*(int (__thiscall **)(void *, _DWORD))(*(_DWORD *)this + 84))(this, *(_DWORD *)(a2 + 108));
  switch ( v5 )
  {
    case 0xFFFF:
      *a4 = 0;
      v6 = (*(int (__thiscall **)(void *, _DWORD))(*(_DWORD *)this + 88))(this, *(_DWORD *)(a2 + 108));
LABEL_8:
      *a3 = v6;
      return 0;
    case 0x11:
      *a4 = 17;
      *a3 = 1;
      break;
    case 0x12:
      *a4 = 17;
      *a3 = 0;
      break;
    default:
      *a4 = 1;
      v6 = *(_DWORD *)(a2 + 12);
      goto LABEL_8;
  }
  return 0;
}
