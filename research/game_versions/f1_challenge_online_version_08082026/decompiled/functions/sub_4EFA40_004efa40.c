void __thiscall sub_4EFA40(int this, char a2)
{
  double v2; // st7

  if ( *(_DWORD *)(this + 12988) )
  {
    if ( a2 )
    {
      if ( *(float *)(this + 14740) < (double)*(float *)(this + 14748) )
        *(_DWORD *)(this + 14740) = *(_DWORD *)(this + 14748);
    }
    else
    {
      v2 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
      *(float *)(this + 14776) = v2 * *(float *)(this + 14784) + *(float *)(this + 14788) + *(float *)(this + 14780);
    }
  }
  else
  {
    sub_4471F0((int)&dbl_7C7428, a2);
  }
}
