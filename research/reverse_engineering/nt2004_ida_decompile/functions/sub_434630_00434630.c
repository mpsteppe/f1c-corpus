double __thiscall sub_434630(int this, int a2)
{
  int v4; // eax
  double v5; // st7
  double v6; // st7
  double v7; // [esp+4h] [ebp-8h]

  v7 = sub_431A00((int *)this, a2 + 44);
  if ( !sub_500DC0(byte_7D83E4) )
    return 0.0;
  v4 = sub_5009C0(*(_DWORD *)(this + 3012));
  if ( !v4 )
    return 0.0;
  if ( dword_7D9780 )
  {
    if ( dword_7D9780 == 1 )
    {
      v5 = (*(double *)(v4 + 1592) + *(double *)(v4 + 568)) * 0.5;
    }
    else
    {
      if ( dword_7D9780 != 2 )
        return 0.0;
      v5 = *(double *)(v4 + 568);
    }
  }
  else
  {
    v5 = *(double *)(v4 + 1592) * 0.98;
  }
  v6 = v5 * 0.98;
  if ( v6 > 0.0 )
    return v6 * (((double)*(int *)(this + 5508) * *(double *)(this + 5496) + *(double *)(this + 5488)) / v7);
  else
    return 0.0;
}
