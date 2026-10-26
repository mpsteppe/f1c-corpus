int __thiscall sub_554E90(int *this, int a2)
{
  int v2; // ebp
  int v3; // esi
  int v6; // ecx
  int v7; // eax

  v2 = a2;
  v3 = *(_DWORD *)(a2 + 84);
  if ( *(_DWORD *)(v3 + 20) )
    return -2;
  *this = (*(int (__stdcall **)(_DWORD, _DWORD))(**(_DWORD **)(v3 + 16) + 72))(*(_DWORD *)(v3 + 16), 0);
  if ( *(char *)(v3 + 24) >= 0 )
  {
    sub_55C650(&a2, *(_DWORD *)(v3 + 48), 0);
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
  v6 = *(_DWORD *)(v2 + 80);
  if ( !v6 )
    v6 = 1;
  v7 = (*(int (__stdcall **)(int, _DWORD, _DWORD, int, _DWORD, int, _DWORD, int))(*(_DWORD *)this[1088] + 80))(
         this[1088],
         *(_DWORD *)(v3 + 28),
         *(_DWORD *)(v3 + 32),
         v6,
         0,
         a2,
         0,
         v3 + 20);
  *this = v7;
  if ( v7 )
    return -1;
  *(_DWORD *)(v3 + 24) |= 8u;
  return 0;
}

