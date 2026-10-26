float *__thiscall sub_5E6120(int *this)
{
  int *v2; // eax
  _DWORD *v3; // ecx
  float *result; // eax
  int v5; // [esp+4h] [ebp-18h] BYREF
  int v6; // [esp+8h] [ebp-14h] BYREF
  int v7; // [esp+Ch] [ebp-10h] BYREF
  int v8; // [esp+10h] [ebp-Ch] BYREF
  int v9; // [esp+14h] [ebp-8h] BYREF
  int v10; // [esp+18h] [ebp-4h] BYREF

  if ( (BYTE1(*this) & 0x80u) != 0 )
  {
    sub_5E5C70(this, &v5, &v6, &v7);
    v2 = this + 4;
LABEL_5:
    sub_5FEEB0((int)v2, 0.0);
    sub_5FEE10(&v5);
    sub_5FF040(*(float *)(this[12] + 20));
    result = sub_5E5050(*(char **)(this[11] + 272), 46);
    goto LABEL_6;
  }
  v3 = (_DWORD *)this[13];
  result = (float *)(v3[5] - 2);
  if ( v3[5] == 2 )
  {
    sub_5DCE20(v3, &v8, &v9, &v10);
    sub_5E5C70(this, &v5, &v6, &v7);
    v2 = &v8;
    goto LABEL_5;
  }
LABEL_6:
  *this |= 0x40u;
  return result;
}
