double __thiscall sub_439C40(int this)
{
  if ( *(_DWORD *)(this + 9104) == 1 )
    return (*(double *)(this + 4744) + *(double *)(this + 3464) + *(double *)(this + 2184) + *(double *)(this + 904))
         * *(double *)(this + 9288)
         * 0.25;
  if ( *(_DWORD *)(this + 9104) == 2 )
    return (*(double *)(this + 2184) + *(double *)(this + 904)) * *(double *)(this + 9288) * 0.5;
  return (*(double *)(this + 4744) + *(double *)(this + 3464)) * *(double *)(this + 9288) * 0.5;
}
