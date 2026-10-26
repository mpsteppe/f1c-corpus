void __thiscall sub_43BA20(int this, double a2)
{
  int v2; // ebx
  int v3; // edi
  int v4; // ebp
  _DWORD *v5; // esi
  int v6; // eax
  double *v7; // eax
  int v8; // edx
  double v9; // st7
  double *v10; // ecx
  double v11; // st7

  v2 = *(_DWORD *)(this + 5572);
  v3 = 0;
  if ( v2 > 0 )
  {
    v4 = *(_DWORD *)(this + 5616);
    v5 = *(_DWORD **)(this + 5576);
    do
    {
      v6 = v5[1];
      if ( v6 == v4 && v5[3] == *(_DWORD *)(this + 5148) )
      {
        v7 = (double *)v5[2];
        v8 = v5[4];
      }
      else
      {
        if ( v5[3] != v4 || v6 != *(_DWORD *)(this + 5148) )
          goto LABEL_11;
        v7 = (double *)v5[4];
        v8 = v5[2];
      }
      if ( v7 && v8 )
      {
        v9 = a2 + *(double *)(this + 5152);
        v7[1] = v9;
        v10 = *(double **)(this + 5616);
        v11 = v9 * *(double *)((char *)v10 + 52);
        v10 = (double *)((char *)v10 + 28);
        v7[3] = v11 + v10[6] * v7[2] + *v7 * *v10;
        v7[4] = v10[4] * v7[1] + v10[1] * *v7 + v10[7] * v7[2];
        v7[5] = v10[5] * v7[1] + v10[2] * *v7 + v10[8] * v7[2];
        RelativeVelocityCompute(v5);
        sub_56D2D0(v5);
        return;
      }
LABEL_11:
      ++v3;
      v5 += 18;
    }
    while ( v3 < v2 );
  }
}
