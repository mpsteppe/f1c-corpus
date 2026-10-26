char __thiscall sub_4DE9D0(_DWORD *this)
{
  char *v2; // eax
  int v3; // esi
  double v4; // st7
  char result; // al
  float v6; // [esp+8h] [ebp-4h]

  switch ( dword_7D7540 )
  {
    case 1:
    case 2:
    case 8:
      goto LABEL_6;
    case 3:
      v2 = (char *)&unk_62BF68 + 25304 * sub_4FA870(0);
      if ( !v2 )
        goto LABEL_7;
      v3 = *((_DWORD *)v2 + 5212) - this[3];
      v6 = sub_4DD0F0((_DWORD *)v2 + 5209);
      v4 = sub_4DD0F0(this);
      if ( v3 <= 1 && (v3 <= 0 || v4 >= v6) )
        goto LABEL_7;
LABEL_6:
      result = 0;
      break;
    default:
LABEL_7:
      result = 1;
      break;
  }
  return result;
}
