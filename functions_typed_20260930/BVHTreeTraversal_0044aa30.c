void __thiscall sub_44AA30(double **this, double *a2)
{
  double **v2; // esi
  __int16 v3; // cx
  double v5; // st7
  double v6; // st6
  double v7; // st6
  float *v8; // ecx
  double *v9; // esi
  bool v10; // c0
  float v11; // [esp+Ch] [ebp+4h]

  v2 = this;
  v3 = *((_WORD *)this + 4);
  if ( v3 < 0 )
  {
LABEL_11:
    QuadraticSurfaceCollisionTest(v2[3], (int)a2);
    if ( *((_WORD *)v2 + 4) == 0xFFFE )
      QuadraticSurfaceCollisionTest((double *)((char *)v2[3] + 92), (int)a2);
  }
  else
  {
    while ( 1 )
    {
      v5 = dword_7CA388[*((__int16 *)v2 + 5)] * *a2;
      v6 = *((float *)&unk_7CA3A4 - *((__int16 *)v2 + 5)) * a2[2];
      v7 = v3 ? v5 - v6 : v6 + v5;
      v8 = (float *)v2[3];
      v11 = v7;
      if ( v11 <= (double)v8[1] && v11 >= (double)*v8 )
        BVHTreeTraversal(a2);
      v9 = v2[3];
      v10 = v11 < (double)*((float *)v9 + 4);
      v2 = (double **)(v9 + 2);
      if ( v10 || v11 > (double)*((float *)v2 + 1) )
        break;
      v3 = *((_WORD *)v2 + 4);
      if ( v3 < 0 )
        goto LABEL_11;
    }
  }
}

