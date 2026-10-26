int __thiscall sub_5071F0(
        int this,
        int a2,
        int a3,
        char *a4,
        float a5,
        float a6,
        float a7,
        float a8,
        float a9,
        int a10,
        int a11,
        int a12)
{
  int v12; // eax
  int result; // eax
  int v15; // [esp+0h] [ebp-8h]

  v12 = a10;
  if ( a10 >= 1 )
  {
    if ( a10 <= 1000 )
      goto LABEL_6;
    v12 = 1000;
  }
  else
  {
    v12 = 1;
  }
  a10 = v12;
LABEL_6:
  *(_DWORD *)(this + 64) = v12;
  *(float *)&v15 = (float)a10;
  sub_506B30((_DWORD *)this, 1065353216, v15);
  result = sub_506C20((_DWORD *)this, a2, a3, a4, a5, a6, a7, a8, a9, a11, a12);
  if ( !result )
    *(float *)(this + 68) = 1.0 / (double)*(int *)(this + 64);
  return result;
}
