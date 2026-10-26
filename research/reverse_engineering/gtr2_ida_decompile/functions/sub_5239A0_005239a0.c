int __thiscall sub_5239A0(int *this)
{
  int v2; // ecx
  double v3; // st7
  int result; // eax
  int v5; // [esp+0h] [ebp-Ch]
  int v6; // [esp+0h] [ebp-Ch]
  int v7; // [esp+0h] [ebp-Ch]
  int v8; // [esp+0h] [ebp-Ch]
  int v9; // [esp+0h] [ebp-Ch]
  int v10; // [esp+0h] [ebp-Ch]
  int v11; // [esp+0h] [ebp-Ch]
  int v12; // [esp+0h] [ebp-Ch]
  float v13; // [esp+8h] [ebp-4h]

  v2 = *this;
  if ( *(_DWORD *)(v2 + 2892916) )
    v3 = dbl_FB1D10;
  else
    v3 = dbl_FB1D08;
  result = *(_DWORD *)(v2 + 2892972);
  v13 = v3;
  switch ( result )
  {
    case 0:
      *(float *)&v5 = *(float *)(v2 + 2892844) + 0.001;
      sub_520FF0((_DWORD *)v2, v5);
      result = *this;
      *(_DWORD *)(*this + 2892972) = 5;
      break;
    case 1:
      *(float *)&v6 = *(float *)(v2 + 2892848) - 0.001;
      result = sub_520FF0((_DWORD *)v2, v6);
      *(_DWORD *)(*this + 2892972) = 5;
      break;
    case 2:
      *(float *)&v7 = *(float *)(v2 + 2892852) - v13 * 3.3333333;
      result = sub_522980((void *)v2, v7);
      break;
    case 3:
      *(float *)&v8 = *(float *)(v2 + 2892852) - v13 * 1.6666666;
      result = sub_522980((void *)v2, v8);
      break;
    case 4:
      *(float *)&v9 = *(float *)(v2 + 2892852) - v13;
      result = sub_522980((void *)v2, v9);
      break;
    case 6:
      *(float *)&v10 = v13 + *(float *)(v2 + 2892852);
      result = sub_522980((void *)v2, v10);
      break;
    case 7:
      *(float *)&v11 = v13 * 1.6666666 + *(float *)(v2 + 2892852);
      result = sub_522980((void *)v2, v11);
      break;
    case 8:
      *(float *)&v12 = v13 * 3.3333333 + *(float *)(v2 + 2892852);
      result = sub_522980((void *)v2, v12);
      break;
    default:
      return result;
  }
  return result;
}
