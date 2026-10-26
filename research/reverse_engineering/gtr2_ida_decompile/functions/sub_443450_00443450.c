int __thiscall sub_443450(_DWORD *this, double *a2)
{
  int v3; // eax
  double *v4; // esi
  int v5; // ebx
  int result; // eax
  double v7[3]; // [esp+Ch] [ebp-30h] BYREF
  _BYTE v8[24]; // [esp+24h] [ebp-18h] BYREF

  v3 = sub_615460(512);
  v4 = (double *)this[1578];
  v5 = v3;
  v7[0] = *a2 + v4[1];
  v7[1] = v4[2] + a2[1];
  v7[2] = v4[3] + a2[2];
  sub_43A2B0((int)(v4 + 4), (int)v8);
  result = sub_61E140(v4, v7, v8, 0);
  if ( v5 != 512 )
    return sub_6154A0(v5);
  return result;
}
