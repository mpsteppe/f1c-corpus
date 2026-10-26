double __thiscall sub_431850(int this, int a2)
{
  int v4; // eax
  double v5; // st7
  double v6; // st7
  double v7; // [esp+4h] [ebp-8h]

  v7 = sub_42ED00((int *)this, a2 + 44);
  if ( !sub_4D7880(&unk_8ADB88) )
    return 0.0;
  v4 = sub_4D7570(*(_DWORD *)(this + 3012));
  if ( !v4 )
    return 0.0;
  if ( dword_8AEEC0 )
  {
    if ( dword_8AEEC0 == 1 )
    {
      v5 = (*(double *)(v4 + 384) + *(double *)(v4 + 56)) * 0.5;
    }
    else
    {
      if ( dword_8AEEC0 != 2 )
        return 0.0;
      v5 = *(double *)(v4 + 56);
    }
  }
  else
  {
    v5 = *(double *)(v4 + 384) * 0.98;
  }
  v6 = v5 * 0.98;
  if ( v6 > 0.0 )
    return v6 * (((double)*(int *)(this + 5508) * *(double *)(this + 5496) + *(double *)(this + 5488)) / v7);
  else
    return 0.0;
}
