int __thiscall sub_414330(int this)
{
  int v2; // edi
  int v3; // eax
  char v5; // [esp+0h] [ebp-8h]

  if ( (unsigned __int8)sub_5612D0((int)byte_FAE910, 2, "\\Dev\\Src\\Copperhead\\App\\Source\\camera.cpp", 4215) )
    sub_561210((int)byte_FAE910, "Entered CamMan::Restart()", v5);
  if ( *(_BYTE *)(this + 57) )
  {
    v2 = *(_DWORD *)(this + 32);
    if ( *(_DWORD *)(v2 + 8) )
    {
      sub_5E5190(0);
      v3 = *(_DWORD *)(v2 + 12);
      if ( v3 )
        sub_5E6F50(0, 0, *(_DWORD *)(*(_DWORD *)(v2 + 12) + 4), *(_DWORD *)(v3 + 8), -13421773);
    }
  }
  flt_757718 = 0.0;
  dword_75771C = 0;
  dword_757720 = 1065353216;
  dword_757724 = 0;
  dword_757728 = 0;
  byte_75772C = 0;
  if ( byte_75772D )
  {
    sub_562DD0(1);
    byte_75772D = 0;
  }
  byte_75772C = 1;
  *(float *)&dword_757724 = (float)*(int *)dword_903EB8;
  *(float *)&dword_757728 = (float)dword_903EBC;
  *(_BYTE *)(this + 58) = 0;
  *(_BYTE *)(this + 77) = 0;
  *(_DWORD *)(this + 68) = -1;
  byte_B6A3E8 = 0;
  *(_DWORD *)(this + 80) = 0;
  *(_DWORD *)(this + 84) = 0;
  *(_DWORD *)(this + 88) = 0;
  *(_DWORD *)(this + 92) = 0;
  *(_DWORD *)(this + 96) = 0;
  *(_DWORD *)(this + 100) = 0;
  return sub_413DC0(this);
}
