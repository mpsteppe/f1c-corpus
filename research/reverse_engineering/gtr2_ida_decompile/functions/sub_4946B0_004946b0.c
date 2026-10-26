int __thiscall sub_4946B0(_DWORD *this)
{
  char v2; // al
  char v4; // [esp+0h] [ebp-8h]

  switch ( this[69] )
  {
    case 0x10B:
      v2 = sub_501D80(&byte_B6F530, 4);
      goto LABEL_11;
    case 0x10C:
      v2 = sub_501D80(&byte_B6F530, 10);
      goto LABEL_11;
    case 0x10E:
      v2 = sub_501D80(&byte_B6F530, 8);
      goto LABEL_11;
    case 0x10F:
      v2 = sub_501D80(&byte_B6F530, 5);
      goto LABEL_11;
    case 0x110:
      v2 = sub_501D80(&byte_B6F530, 6);
      goto LABEL_11;
    case 0x111:
      v2 = sub_501D80(&byte_B6F530, 9);
      goto LABEL_11;
    case 0x112:
      v2 = sub_501D80(&byte_B6F530, 2);
      goto LABEL_11;
    case 0x113:
      v2 = sub_501D80(&byte_B6F530, 7);
      goto LABEL_11;
    case 0x114:
      v2 = sub_501D80(&byte_B6F530, 3);
LABEL_11:
      if ( !v2 )
        v4 = 1;
      break;
    default:
      break;
  }
  (*(void (__thiscall **)(_DWORD *, char))(*this + 36))(this, v4);
  sub_494640();
  return 0;
}
