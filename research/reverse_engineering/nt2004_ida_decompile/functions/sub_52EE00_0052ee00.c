char __thiscall sub_52EE00(int this, int a2, int a3, float *a4, float a5, char a6)
{
  char v7; // dl
  float *v8; // ecx
  double v9; // st7
  double v10; // st7
  float *v11; // edi
  char v12; // al
  char v13; // bl
  float v15; // [esp+0h] [ebp-ECh]
  int v16[52]; // [esp+1Ch] [ebp-D0h] BYREF

  if ( !sub_52E850((float *)this) )
    return v7;
  if ( sub_52E830(v8) && (v9 = *(float *)(this + 220), v9 < *(float *)&a2) )
  {
    v10 = *(float *)&a2 - v9;
    if ( v10 >= 0.001 )
    {
      if ( v10 > 0.5 )
        v10 = 0.5;
    }
    else
    {
      v10 = 0.001;
    }
    v15 = v10 + *(float *)&a2;
    sub_52DAB0(v15, this + 8, (int)v16, 1.0);
    v11 = a4;
    v12 = sub_52DF70((void *)this, a2, this + 216, (int)v16, (int)a4);
  }
  else
  {
    v11 = a4;
    v12 = sub_52DAB0(*(float *)&a2, this + 8, (int)a4, 1.0);
  }
  v13 = v12;
  sub_4D1850((_DWORD *)(this + 216), v11);
  if ( v13 )
  {
    if ( a6 )
      sub_52E740(v11, a5);
  }
  return v13;
}
