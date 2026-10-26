// f1c  0x0043e6a0  size=200
int __thiscall sub_43E6A0(_DWORD *this, double *a2)
{
  int v3; // eax
  int v4; // esi
  int v5; // ebx
  double v6; // st7
  long double v7; // st7
  long double v8; // st6
  int result; // eax
  double v10; // [esp+10h] [ebp-30h] BYREF
  long double v11; // [esp+18h] [ebp-28h]
  long double v12; // [esp+20h] [ebp-20h]
  double v13[3]; // [esp+28h] [ebp-18h] BYREF

  v3 = sub_567740(512);
  v4 = this[1404];
  v5 = v3;
  v13[0] = *a2 + *(double *)(v4 + 4);
  v13[1] = *(double *)(v4 + 12) + a2[1];
  v13[2] = *(double *)(v4 + 20) + a2[2];
  v6 = *(double *)(v4 + 68);
  sub_588570();
  v10 = -v6;
  if ( fabs(*(double *)(v4 + 68)) == 1.0 )
  {
    v7 = -*(double *)(v4 + 76);
    v8 = *(double *)(v4 + 28);
    v12 = 0.0;
    v11 = atan2(v7, v8);
  }
  else
  {
    v11 = atan2(*(double *)(v4 + 44), *(double *)(v4 + 92));
    v12 = atan2(*(double *)(v4 + 52), *(double *)(v4 + 60));
  }
  result = sub_56F100(v4, v13, &v10, 0);
  if ( v5 != 512 )
    return sub_567780(v5);
  return result;
}
