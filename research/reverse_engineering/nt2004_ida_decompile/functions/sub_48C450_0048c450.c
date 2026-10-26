int __thiscall sub_48C450(_DWORD *this)
{
  unsigned int v2; // eax
  int v3; // eax
  char Buffer[253]; // [esp+8h] [ebp-100h] BYREF
  __int16 v6; // [esp+105h] [ebp-3h]
  char v7; // [esp+107h] [ebp-1h]

  Buffer[0] = byte_629120;
  memset(&Buffer[1], 0, 0xFCu);
  v6 = 0;
  v7 = 0;
  v2 = dword_767454[9 * *(_DWORD *)dword_7689CC];
  this[78] = v2;
  if ( v2 <= 1 )
    this[78] = sub_52D380(&unk_7DAAE0);
  switch ( this[78] )
  {
    case 2:
      sprintf(Buffer, aWeathersunBmp);
      break;
    case 3:
      sprintf(Buffer, aWeatherpartsun);
      break;
    case 4:
      sprintf(Buffer, aWeatherrainBmp);
      break;
    case 5:
      sprintf(Buffer, aWeathermonsoon);
      break;
    default:
      break;
  }
  v3 = sub_4AD970(Buffer, 0, 0, 1);
  return sub_4B0AC0(v3);
}
