void __thiscall sub_46CE80(void *this, int a2, int a3)
{
  if ( (double)a2 > 0.0 )
    *(_DWORD *)(*(_DWORD *)this + 80) = 1000 * a2 / 8;
  if ( (double)a3 > 0.0 )
    *(_DWORD *)(*(_DWORD *)this + 84) = 1000 * a3 / 8;
}
