int __thiscall sub_6B1037(void *this, int a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  int v6; // ebx

  v6 = (*(int (__thiscall **)(void *, _DWORD))(*(_DWORD *)this + 84))(this, *(_DWORD *)(a2 + 108));
  *a3 = (*(int (__thiscall **)(void *, _DWORD))(*(_DWORD *)this + 88))(this, *(_DWORD *)(a2 + 108));
  if ( a5 )
    *a5 = 0;
  switch ( v6 )
  {
    case 1:
      if ( !*a3 )
      {
        *a4 = 4;
        *a3 = 0;
        return 0;
      }
      return -2147467259;
    case 5:
      if ( *a3 )
        return -2147467259;
      *a4 = 4;
      *a3 = 2;
LABEL_9:
      if ( a5 )
        *a5 = 1;
      return 0;
    case 0xC:
      if ( *a3 )
        return -2147467259;
      *a4 = 4;
      *a3 = 1;
      goto LABEL_9;
    case 0xB:
      if ( *a3 < 2u )
      {
        *a4 = 5;
        return 0;
      }
      break;
    case 6:
      if ( *a3 < 8u )
      {
        *a4 = 6;
        return 0;
      }
      break;
    case 0xFFFF:
      *a4 = 0;
      return 0;
  }
  return -2147467259;
}
