int __thiscall sub_47C180(void *this)
{
  int v3; // edi
  int v4; // edi

  if ( *(_DWORD *)dword_7689CC == 5 && sub_4633A0(dword_764D70) == 3 )
  {
    sub_465B70((char **)dword_764D70);
    if ( !sub_4634A0(dword_764D70) )
    {
      sub_464C40(dword_764D70);
      sub_4AD720(aMplobby, 1);
      return -1;
    }
    v3 = sub_464BA0(dword_764D70);
    if ( v3 )
      (*(void (__thiscall **)(void *, int))(*(_DWORD *)this + 36))(this, 1);
    else
      (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)this + 36))(this, 0);
    v4 = v3 - 2;
    if ( v4 )
    {
      if ( v4 == 1 )
      {
        sub_4AEE60(aVehicleInUse, 0x40000000);
        return 0;
      }
    }
    else
    {
      dword_608F60 = 1;
      sub_4AD720(a2003MultiClien, 1);
    }
  }
  return 0;
}
