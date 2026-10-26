char __thiscall sub_525BB0(_BYTE *this, _DWORD *a2, int a3)
{
  char result; // al
  int v5; // esi
  _DWORD *v6; // edi
  int v7; // ecx

  if ( !*this )
    return 0;
  switch ( *a2 >> 29 )
  {
    case 1:
      v5 = 0;
      if ( (*a2 & 0xFC0000) != 0 || (unsigned __int8)*a2 >= 0x69u || !sub_521380() )
        goto LABEL_9;
      return 0;
    case 2:
    case 3:
      v5 = 1;
      goto LABEL_9;
    case 4:
      v5 = 2;
      goto LABEL_9;
    case 6:
      v5 = 3;
      goto LABEL_9;
    default:
      v5 = -1;
LABEL_9:
      v6 = (_DWORD *)sub_5257A0();
      sub_51BFA0(v6, a2);
      if ( (unsigned __int8)sub_5FDFB0(v6, 0) )
      {
        v7 = (unsigned __int8)*v6;
        if ( v7 != 255 )
          this[14 * v5 + 1 + v7 / 8] |= 1 << (v7 % 8);
        result = 1;
      }
      else
      {
        sub_5E5780(v6, 0);
        result = 0;
      }
      break;
  }
  return result;
}
