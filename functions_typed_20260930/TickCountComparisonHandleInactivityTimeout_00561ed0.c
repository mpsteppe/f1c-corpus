char __thiscall sub_561ED0(int this)
{
  DWORD TickCount; // eax
  unsigned int v3; // ecx
  unsigned int v4; // edx

  TickCount = GetTickCount();
  if ( *(_DWORD *)(this + 4) != -1 )
  {
    v3 = *(_DWORD *)(this + 216);
    v4 = TickCount - v3;
    if ( TickCount - v3 <= 0x493E0 && v3 && TickCount >= v3 )
    {
      LOBYTE(TickCount) = *(_BYTE *)(this + 232);
      if ( (char)TickCount > 0 && v4 > 0x7530 )
      {
        sub_562AC0(this, 0);
        LOBYTE(TickCount) = *(_BYTE *)(this + 232) + 1;
        *(_BYTE *)(this + 232) = TickCount;
        if ( (char)TickCount > 10 )
          *(_BYTE *)(this + 232) = 0;
      }
    }
    else
    {
      LOBYTE(TickCount) = sub_562AC0(this, 0);
    }
  }
  return TickCount;
}

