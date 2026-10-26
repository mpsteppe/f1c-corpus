int __thiscall sub_49E3E0(void *this)
{
  int result; // eax
  int v3; // eax
  int v4; // esi
  float v5; // [esp+0h] [ebp-4A8h]
  _BYTE v6[61]; // [esp+8h] [ebp-4A0h] BYREF
  __int16 v7; // [esp+45h] [ebp-463h]
  char v8; // [esp+47h] [ebp-461h]
  char v9; // [esp+48h] [ebp-460h]
  _BYTE v10[252]; // [esp+49h] [ebp-45Fh] BYREF
  __int16 v11; // [esp+145h] [ebp-363h]
  char v12; // [esp+147h] [ebp-361h]

  result = *((_DWORD *)this + 204);
  switch ( result )
  {
    case 471:
      result = sub_630FE0(&byte_B6DC18, *((_DWORD *)this + 199), 25);
      byte_B6DC31 = 0;
      break;
    case 472:
      result = sub_630FE0(&byte_B6DC34, *((_DWORD *)this + 199), 25);
      byte_B6DC4D = 0;
      break;
    case 475:
      result = sub_630FE0(byte_B6DC70, *((_DWORD *)this + 199), 31);
      byte_B6DC8F = 0;
      break;
    case 476:
      if ( (unsigned __int8)sub_4735A0() )
      {
        if ( (void *)sub_4DE2F0(*((_DWORD *)this + 12)) == this )
        {
          if ( *((_DWORD *)this + 199) )
          {
            v3 = strlen(*((const char **)this + 199));
            v4 = v3;
            if ( v3 > 0 )
            {
              if ( v3 > 159 )
                v4 = 159;
              v5 = dbl_FB1D18;
              sub_51B2A0(4, 6, v4, 0, LODWORD(v5), 3);
              sub_4152E0();
              sub_4745E0();
              v9 = 0;
              memset(v10, 0, sizeof(v10));
              v11 = 0;
              v12 = 0;
              memset(v6, 0, sizeof(v6));
              v7 = 0;
              v8 = 0;
              sub_501490(v6, 64);
              sub_472FE0();
              sub_4EA920(&v10[15]);
            }
          }
        }
      }
      result = (*(int (__thiscall **)(void *, int))(*(_DWORD *)this + 160))(this, 1);
      break;
    case 479:
      result = sub_630FE0(&unk_B6DCF0, *((_DWORD *)this + 199), 254);
      byte_B6DDEE = 0;
      break;
    case 480:
      result = sub_630FE0(&unk_B6DDF0, *((_DWORD *)this + 199), 254);
      byte_B6DEEE = 0;
      break;
    case 486:
    case 487:
    case 488:
    case 489:
    case 490:
    case 491:
    case 492:
    case 493:
    case 494:
    case 495:
      result = sub_615860(*((_DWORD *)this + 199));
      break;
    case 501:
      if ( (void *)sub_4DE2F0(*((_DWORD *)this + 12)) == this
        && *((_DWORD *)this + 199)
        && (int)strlen(*((const char **)this + 199)) > 0 )
      {
        CINet::Chat((CINet *)dword_B6CBB0, *((char **)this + 199));
      }
      result = (*(int (__thiscall **)(void *, int))(*(_DWORD *)this + 160))(this, 1);
      break;
    default:
      return result;
  }
  return result;
}
