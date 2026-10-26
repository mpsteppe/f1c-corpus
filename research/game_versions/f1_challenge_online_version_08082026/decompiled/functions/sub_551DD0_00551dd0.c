int __thiscall sub_551DD0(_DWORD *this, _DWORD *a2, int a3, int a4, char a5)
{
  int v6; // edi
  int result; // eax

  if ( !BinkWait(*this) )
  {
    BinkDoFrame(*this);
    BinkNextFrame(*this);
    this[1] = (unsigned int)(this[1] + 1) % *(_DWORD *)(*this + 8);
  }
  switch ( a2[12] )
  {
    case 5:
      v6 = 9;
      break;
    case 6:
      v6 = 10;
      break;
    case 7:
      v6 = 1;
      break;
    case 8:
      v6 = 5;
      break;
    default:
      v6 = (int)a2;
      break;
  }
  if ( (a5 & 0x20) != 0 )
    v6 |= 0x80000000;
  if ( (a5 & 0x10) != 0 )
    v6 |= 0x60000000u;
  result = sub_543210(a2, 4, 0);
  if ( result )
  {
    BinkCopyToBuffer(*this, result, a2[10], a2[8], a3, a4, v6);
    result = sub_543230(a2, 4, 0);
    a2[6] &= ~0x400u;
  }
  return result;
}
