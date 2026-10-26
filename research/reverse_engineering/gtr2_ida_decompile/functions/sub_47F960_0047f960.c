int sub_47F960()
{
  int i; // esi
  int v1; // edi
  int v2; // esi

  for ( i = 0; i < 104; ++i )
    sub_552190(i, 0, 0);
  sub_552090(&unk_FADD40);
  v1 = *(_DWORD *)dword_B640C8;
  v2 = 7;
  switch ( *(_DWORD *)dword_B640C8 )
  {
    case 1:
      if ( !byte_B6CE97 )
        goto LABEL_6;
      v2 = 2;
      break;
    case 2:
LABEL_6:
      if ( !byte_B6CE98 )
        goto LABEL_8;
      v2 = 3;
      break;
    case 3:
LABEL_8:
      if ( !byte_B6CE99 )
        goto LABEL_10;
      v2 = 4;
      break;
    case 4:
LABEL_10:
      if ( !byte_B6CE9A )
        goto LABEL_12;
      v2 = 5;
      break;
    case 5:
LABEL_12:
      if ( byte_B6CE9B )
        goto LABEL_13;
      break;
    case 6:
LABEL_13:
      v2 = 6;
      break;
    default:
      break;
  }
  sub_4786A0();
  if ( v1 == 3 && v2 == 4 )
    return sub_4309C0(&dword_B640C0, 0);
  else
    return sub_4309C0(&dword_B640C0, 1);
}
