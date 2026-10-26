void __thiscall sub_4DA130(float **this)
{
  float *v2; // edi
  double v3; // st7
  double v4; // st7
  float v5; // [esp+0h] [ebp-14h]
  float v6; // [esp+0h] [ebp-14h]
  float v7; // [esp+0h] [ebp-14h]
  float v8; // [esp+0h] [ebp-14h]
  float v9; // [esp+0h] [ebp-14h]
  float v10; // [esp+0h] [ebp-14h]
  float v11; // [esp+Ch] [ebp-8h] BYREF
  int v12; // [esp+10h] [ebp-4h] BYREF

  v2 = *this;
  switch ( *((_DWORD *)*this + 541) )
  {
    case 0:
      sub_4D8430(v2, &v11, &v12);
      v3 = v11 + 0.001;
      goto LABEL_4;
    case 1:
      sub_4D8430(v2, &v12, &v11);
      v3 = v11 - 0.001;
LABEL_4:
      v5 = v3;
      sub_4D82E0((int)v2, v5);
      *((_DWORD *)*this + 541) = 5;
      return;
    case 2:
      v4 = -dbl_7DA9C0;
      goto LABEL_11;
    case 3:
      v6 = -dbl_7DA9C0 * 1.6666666;
      sub_4D9E40(this, v6);
      return;
    case 4:
      v7 = -dbl_7DA9C0;
      sub_4D9E40(this, v7);
      return;
    case 6:
      v8 = dbl_7DA9C0;
      sub_4D9E40(this, v8);
      return;
    case 7:
      v9 = dbl_7DA9C0 * 1.6666666;
      sub_4D9E40(this, v9);
      return;
    case 8:
      v4 = dbl_7DA9C0;
LABEL_11:
      v10 = v4 * 3.3333333;
      sub_4D9E40(this, v10);
      break;
    default:
      return;
  }
}
