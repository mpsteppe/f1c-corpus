int __thiscall sub_56D1C0(_DWORD *this)
{
  int v1; // eax
  double *v2; // edx
  double *v3; // esi
  double v4; // st7
  double v5; // st6
  int v6; // eax
  double v7; // st4
  double v8; // st7
  int result; // eax
  double v10; // [esp+8h] [ebp-48h]
  double v11; // [esp+20h] [ebp-30h]
  double v12; // [esp+48h] [ebp-8h]

  v1 = this[1];
  v2 = (double *)this[2];
  v3 = (double *)this[4];
  v10 = *(double *)(v1 + 44) * v2[2] + *(double *)(v1 + 36) * v2[1] + *(double *)(v1 + 28) * *v2 + *(double *)(v1 + 4);
  v4 = *(double *)(v1 + 68) * v2[2] + *(double *)(v1 + 60) * v2[1] + *(double *)(v1 + 52) * *v2 + *(double *)(v1 + 12);
  v5 = *(double *)(v1 + 92) * v2[2] + *(double *)(v1 + 84) * v2[1] + *(double *)(v1 + 76) * *v2 + *(double *)(v1 + 20);
  v6 = this[3];
  v7 = *(double *)(v6 + 68) * v3[2] + *(double *)(v6 + 60) * v3[1] + *(double *)(v6 + 52) * *v3;
  v12 = *(double *)(v6 + 92) * v3[2] + *(double *)(v6 + 84) * v3[1] + *(double *)(v6 + 76) * *v3;
  v11 = *(double *)(v6 + 44) * v3[2] + *(double *)(v6 + 36) * v3[1] + *v3 * *(double *)(v6 + 28) + *(double *)(v6 + 4);
  v8 = sqrt(
         (v5 - (v12 + *(double *)(v6 + 20))) * (v5 - (v12 + *(double *)(v6 + 20)))
       + (v4 - (v7 + *(double *)(v6 + 12))) * (v4 - (v7 + *(double *)(v6 + 12)))
       + (v10 - v11) * (v10 - v11));
  v2[7] = v8;
  result = this[4];
  *(double *)(result + 56) = v8;
  return result;
}
