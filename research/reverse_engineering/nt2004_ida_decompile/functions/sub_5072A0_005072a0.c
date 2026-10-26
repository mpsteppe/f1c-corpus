void __thiscall sub_5072A0(int this, char *Source, float a3, int a4, int a5, _DWORD *a6, float a7, float a8, CHAR *a9)
{
  float v9; // [esp+0h] [ebp-1Ch]

  if ( a4 >= 0 )
  {
    if ( a4 > *(_DWORD *)(this + 64) - 1 )
      a4 = *(_DWORD *)(this + 64) - 1;
  }
  else
  {
    a4 = 0;
  }
  v9 = (double)a4 * *(float *)(this + 68);
  sub_5070D0((float *)this, Source, a3, v9, a5, a6, a7, a8, a9, 0);
}
