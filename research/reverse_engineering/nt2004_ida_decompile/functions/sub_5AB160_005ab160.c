int __thiscall sub_5AB160(int *this, int a2)
{
  int v2; // ebp
  int v3; // esi
  int v6; // ecx
  int v7; // eax

  v2 = a2;
  v3 = *(_DWORD *)(a2 + 16);
  if ( *(_DWORD *)(v3 + 24) )
    return -2;
  *this = (*(int (__stdcall **)(_DWORD, _DWORD))(**(_DWORD **)(v3 + 20) + 72))(*(_DWORD *)(v3 + 20), 0);
  if ( *(char *)(v3 + 56) >= 0 )
  {
    sub_5B43F0(&a2, *(_DWORD *)(v3 + 48), 0);
  }
  else
  {
    switch ( *(_DWORD *)(v3 + 48) )
    {
      case 9:
        a2 = 827611204;
        break;
      case 0xA:
        a2 = 844388420;
        break;
      case 0xB:
        a2 = 861165636;
        break;
      case 0xC:
        a2 = 877942852;
        break;
      case 0xD:
        a2 = 894720068;
        break;
      default:
        break;
    }
  }
  v6 = *(_DWORD *)(v2 + 92);
  if ( !v6 )
    v6 = 1;
  v7 = (*(int (__stdcall **)(int, _DWORD, _DWORD, int, _DWORD, int, _DWORD, int))(*(_DWORD *)this[1112] + 80))(
         this[1112],
         *(_DWORD *)(v3 + 28),
         *(_DWORD *)(v3 + 32),
         v6,
         0,
         a2,
         0,
         v3 + 24);
  *this = v7;
  if ( v7 )
    return -1;
  *(_DWORD *)(v3 + 56) |= 8u;
  return 0;
}
