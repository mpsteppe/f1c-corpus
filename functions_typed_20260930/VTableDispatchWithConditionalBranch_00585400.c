char __thiscall sub_585400(int *this, _DWORD *a2)
{
  if ( BitmapRangeOccupancyTestViaBitOps(a2) )
  {
    sub_584DD0(this, (int)a2);
  }
  else
  {
    (*(void (__thiscall **)(int *, _DWORD *))(*this + 44))(this, a2);
    sub_584230(this, a2);
    (*(void (__thiscall **)(int *, _DWORD *))(*this + 92))(this, a2);
  }
  return 1;
}

