int __thiscall sub_5871A0(double *this, int a2, int a3, int a4, int a5)
{
  int result; // eax

  for ( result = (*(int (__thiscall **)(int, int, int))(*(_DWORD *)a3 + 36))(a3, a4 + 536, 512);
        result;
        result = (*(int (__thiscall **)(int, int, int))(*(_DWORD *)a3 + 36))(a3, a4 + 536, 512) )
  {
    result = sub_612EB0(a4);
    if ( result == 1 )
      break;
    if ( !result )
    {
      if ( sub_6136D0("FenderCenter", (int)(this + 10), (int)(this + 11), (int)(this + 12), 0) )
        *(_BYTE *)this = 1;
      sub_6136D0("FenderDragParams", (int)(this + 1), (int)(this + 2), (int)(this + 3), 0);
      sub_6136D0("FenderLiftParams", (int)(this + 4), (int)(this + 5), (int)(this + 6), 0);
      sub_6136D0("FenderSideways", (int)(this + 7), 0, 0, 0);
      if ( sub_6136D0("FenderPeakYaw", (int)(this + 8), (int)(this + 9), 0, 0) )
        this[8] = this[8] * 0.0174532925199433;
      sub_431730((char *)((a2 << 6) + a5 + 2992), a4, "FenderFlareRange", "FenderFlareSetting", 1.0);
    }
  }
  return result;
}
