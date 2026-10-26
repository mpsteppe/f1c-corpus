int __thiscall sub_415FB0(_DWORD *this, float *a2)
{
  int result; // eax
  double v3; // [esp+8h] [ebp-38h]
  double v4; // [esp+10h] [ebp-30h]
  double v5; // [esp+18h] [ebp-28h]
  double v6; // [esp+20h] [ebp-20h]
  int v7[2]; // [esp+28h] [ebp-18h] BYREF
  double v8; // [esp+30h] [ebp-10h]
  double v9; // [esp+38h] [ebp-8h]

  v3 = *a2;
  *(double *)v7 = a2[1];
  v8 = a2[2];
  v9 = a2[3];
  v6 = a2[4];
  v5 = a2[5];
  result = this[8];
  v4 = a2[6];
  switch ( result )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      sub_45AA70(v3, (int)v7);
      result = sub_45AAB0(LODWORD(v6), HIDWORD(v6), LODWORD(v5), HIDWORD(v5), LODWORD(v4), HIDWORD(v4));
      break;
    default:
      return result;
  }
  return result;
}
