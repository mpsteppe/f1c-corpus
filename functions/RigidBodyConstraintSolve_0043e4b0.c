_DWORD *__thiscall sub_43E4B0(int this, double *a2, int a3)
{
  int v4; // ebx
  int v5; // ecx
  double v6; // st7
  double v7; // st6
  _DWORD *result; // eax
  int v9; // ecx
  double v10[5]; // [esp+10h] [ebp-78h] BYREF
  double v11; // [esp+38h] [ebp-50h]
  double v12; // [esp+40h] [ebp-48h]
  double v13; // [esp+48h] [ebp-40h]
  double v14; // [esp+50h] [ebp-38h]
  double v15; // [esp+58h] [ebp-30h]
  double v16; // [esp+60h] [ebp-28h]
  double v17; // [esp+68h] [ebp-20h]
  double v18; // [esp+70h] [ebp-18h]
  double v19; // [esp+78h] [ebp-10h]
  double v20; // [esp+80h] [ebp-8h]

  v4 = FPUControlWordMaskExtract(512);
  EulerAnglesTo33RotationMatrix(a3);
  v5 = *(_DWORD *)(this + 5616);
  v6 = v12 * *(double *)(this + 5628) + v13 * *(double *)(this + 5636) + v14 * *(double *)(this + 5644);
  v7 = v15 * *(double *)(this + 5628) + v16 * *(double *)(this + 5636) + v17 * *(double *)(this + 5644);
  v11 = v18 * *(double *)(this + 5628) + v19 * *(double *)(this + 5636) + v20 * *(double *)(this + 5644);
  v10[0] = *a2 - v6;
  v10[1] = a2[1] - v7;
  v10[2] = a2[2] - v11;
  sub_56F100(v5, v10, a3, 0);
  *(_DWORD *)(this + 180) = 0;
  result = (_DWORD *)(this + 936);
  v9 = 4;
  do
  {
    *(result - 8) = -1;
    *(result - 7) = -1048577;
    *result = -1;
    result[1] = -1048577;
    result += 281;
    --v9;
  }
  while ( v9 );
  if ( v4 != 512 )
    return (_DWORD *)EmptyStub_7780(v4);
  return result;
}
