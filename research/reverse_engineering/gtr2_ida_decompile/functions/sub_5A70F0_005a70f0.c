char __thiscall sub_5A70F0(_DWORD *this, _DWORD *a2, _DWORD *a3)
{
  if ( (int)this[1] > 0 )
  {
    *a2 = *this;
    *a3 = this[2];
    return 1;
  }
  else
  {
    *a2 = 0;
    *a3 = 0;
    return 0;
  }
}
