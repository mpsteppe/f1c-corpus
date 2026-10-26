int __thiscall sub_416240(_DWORD *this, float *a2)
{
  double v2; // st7
  int result; // eax
  double v4; // [esp+20h] [ebp-30h]
  double v5; // [esp+28h] [ebp-28h]
  double v6; // [esp+30h] [ebp-20h]
  int v7[2]; // [esp+38h] [ebp-18h] BYREF
  double v8; // [esp+40h] [ebp-10h]
  double v9; // [esp+48h] [ebp-8h]

  v2 = *a2;
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
      sub_470090(v2, (int)v7);
      result = sub_46FE40(v6, v5, v4);
      break;
    default:
      return result;
  }
  return result;
}
