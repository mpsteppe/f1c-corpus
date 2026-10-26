char __thiscall sub_5251E0(_BYTE *this, _DWORD *a2)
{
  int v3; // esi
  int v4; // ecx

  switch ( *a2 >> 29 )
  {
    case 1:
      v3 = 0;
      break;
    case 2:
    case 3:
      v3 = 1;
      break;
    case 4:
      v3 = 2;
      break;
    case 6:
      v3 = 3;
      break;
    default:
      v3 = -1;
      break;
  }
  if ( !(unsigned __int8)sub_524660(&this[16 * v3 + 120], (int)a2, 1) )
    return 0;
  v4 = (unsigned __int8)*a2;
  if ( v4 != 255 )
    this[14 * v3 + 1 + v4 / 8] &= ~(1 << (v4 % 8));
  sub_5E5780(a2, 0);
  return 1;
}
