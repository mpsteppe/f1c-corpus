void __thiscall sub_599BB0(int this, float a2, int a3)
{
  double v3; // st7

  v3 = *(float *)(a3 + 4);
  if ( v3 > a2 || v3 <= *(float *)(this + 860) )
  {
    if ( v3 > a2 && v3 < *(float *)(this + 12) )
      sub_51BFA0((_DWORD *)(this + 8), (_DWORD *)a3);
  }
  else
  {
    sub_51BFA0((_DWORD *)(this + 856), (_DWORD *)a3);
  }
}
