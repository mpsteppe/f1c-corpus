double __thiscall sub_4355B0(int this, int a2)
{
  int v4; // ebx
  int v5; // eax
  double v6; // st7
  double v7; // st7
  double v8; // [esp+0h] [ebp-14h]

  sub_431630((int *)(this + 6896), *(_DWORD *)(((a2 + 45) << 6) + this + 3012), *(_DWORD *)(this + 5764));
  if ( !sub_560950(&dword_FAE908, &unk_FAF650) )
    return 0.0;
  v4 = sub_560800(*(_DWORD *)(this + 3012));
  if ( !v4 )
    return 0.0;
  v5 = sub_560800(*(_DWORD *)(this + 3076));
  if ( !v5 )
    return 0.0;
  if ( dword_FB0A90 )
  {
    if ( dword_FB0A90 == 1 )
    {
      v6 = (*(double *)(v5 + 1544) + *(double *)(v4 + 552)) * 0.5;
    }
    else
    {
      if ( dword_FB0A90 != 2 )
        return 0.0;
      v6 = *(double *)(v4 + 552);
    }
  }
  else
  {
    v6 = *(double *)(v5 + 1544) * 0.98;
  }
  v7 = v6 * 0.98;
  if ( v7 <= 0.0 )
    return 0.0;
  return v7 * (((double)*(int *)(this + 5572) * *(double *)(this + 5560) + *(double *)(this + 5552)) / v8);
}
