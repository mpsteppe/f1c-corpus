int __thiscall sub_559FB0(_DWORD *this, int a2, float *a3, float *a4, float *a5, float *a6)
{
  int v7; // edi
  int v8; // eax
  float *v9; // esi
  int v10; // eax
  float *v11; // esi
  float *v12; // esi
  float *v13; // esi

  v7 = 0;
  if ( sub_559D80(this, a2) )
  {
    v8 = this[195];
    v9 = a3;
    v10 = v8 + 1;
    v7 = 1;
    a2 = v10;
    if ( a3 )
    {
      *v9 = sub_58B077(v10, &a2);
      v10 = a2 + 1;
    }
    v11 = a4;
    if ( a4 )
    {
      *v11 = sub_58B077(v10, &a2);
      v10 = a2 + 1;
    }
    v12 = a5;
    if ( a5 )
    {
      *v12 = sub_58B077(v10, &a2);
      v10 = a2 + 1;
    }
    v13 = a6;
    if ( a6 )
      *v13 = sub_58B077(v10, &a2);
  }
  return v7;
}

