void __thiscall sub_441DD0(int this)
{
  double v1; // st7
  double v2; // st7
  double *v3; // ecx
  double v4; // st7
  double v5; // st7
  double *v6; // ecx
  double v7; // st7
  double v8; // st7
  double v9; // st7
  double v10; // [esp+0h] [ebp-8h]
  double v11; // [esp+0h] [ebp-8h]
  double v12; // [esp+0h] [ebp-8h]
  double v13; // [esp+0h] [ebp-8h]
  double v14; // [esp+0h] [ebp-8h]
  double v15; // [esp+0h] [ebp-8h]
  double v16; // [esp+0h] [ebp-8h]

  v10 = *(double *)(this + 7852) + 0.06;
  v1 = *(double *)(this + 7852);
  if ( v1 <= *(double *)(this + 6604) )
  {
    if ( *(double *)(this + 6604) > v10 )
      *(double *)(this + 6604) = v10;
  }
  else
  {
    *(double *)(this + 6604) = v1;
  }
  v11 = *(double *)(this + 7860) + 0.04;
  v2 = *(double *)(this + 7860);
  if ( v2 <= *(double *)(this + 6628) )
  {
    if ( *(double *)(this + 6628) > v11 )
      *(double *)(this + 6628) = v11;
  }
  else
  {
    *(double *)(this + 6628) = v2;
  }
  sub_43E550(this, *(double *)(this + 7844));
  v12 = *(double *)((char *)v3 + 7876) + 0.06;
  v4 = *(double *)((char *)v3 + 7876);
  if ( v4 <= *(double *)((char *)v3 + 6700) )
  {
    if ( *(double *)((char *)v3 + 6700) > v12 )
      *(double *)((char *)v3 + 6700) = v12;
  }
  else
  {
    *(double *)((char *)v3 + 6700) = v4;
  }
  v13 = *(double *)((char *)v3 + 7884) + 0.04;
  v5 = *(double *)((char *)v3 + 7884);
  if ( v5 <= *(double *)((char *)v3 + 6716) )
  {
    if ( *(double *)((char *)v3 + 6716) > v13 )
      *(double *)((char *)v3 + 6716) = v13;
  }
  else
  {
    *(double *)((char *)v3 + 6716) = v5;
  }
  sub_43E5F0(v3, *(double *)((char *)v3 + 7868));
  v14 = *(double *)((char *)v6 + 7892) + 0.1;
  v7 = *(double *)((char *)v6 + 7892);
  if ( v7 <= *(double *)((char *)v6 + 7756) )
  {
    if ( *(double *)((char *)v6 + 7756) > v14 )
      *(double *)((char *)v6 + 7756) = v14;
  }
  else
  {
    *(double *)((char *)v6 + 7756) = v7;
  }
  v15 = *(double *)((char *)v6 + 7908) + 0.06;
  v8 = *(double *)((char *)v6 + 7908);
  if ( v8 <= *(double *)((char *)v6 + 6652) )
  {
    if ( *(double *)((char *)v6 + 6652) > v15 )
      *(double *)((char *)v6 + 6652) = v15;
  }
  else
  {
    *(double *)((char *)v6 + 6652) = v8;
  }
  v16 = *(double *)((char *)v6 + 7916) + 0.04;
  v9 = *(double *)((char *)v6 + 7916);
  if ( v9 <= *(double *)((char *)v6 + 6676) )
  {
    if ( *(double *)((char *)v6 + 6676) > v16 )
      *(double *)((char *)v6 + 6676) = v16;
  }
  else
  {
    *(double *)((char *)v6 + 6676) = v9;
  }
  sub_43E5A0(v6, *(double *)((char *)v6 + 7900));
}
