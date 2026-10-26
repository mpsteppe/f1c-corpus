int __thiscall sub_410A90(int this)
{
  int result; // eax
  int (__thiscall ***v3)(_DWORD, int); // ecx
  int (__thiscall ***v4)(_DWORD, int); // ecx
  int (__thiscall ***v5)(_DWORD, int); // ecx
  int (__thiscall ***v6)(_DWORD, int); // ecx
  char v7; // [esp+0h] [ebp-8h]

  result = sub_5612D0((int)byte_FAE910, 2, "\\Dev\\Src\\Copperhead\\App\\Source\\camera.cpp", 4379);
  if ( (_BYTE)result )
    result = sub_561210((int)byte_FAE910, "Entered CamMan::Post()", v7);
  *(_DWORD *)(this + 8) = 0;
  flt_757718 = 0.0;
  dword_75771C = 0;
  dword_757720 = 1065353216;
  dword_757724 = 0;
  dword_757728 = 0;
  byte_75772C = 0;
  if ( byte_75772D )
  {
    result = sub_562DD0(1);
    byte_75772D = 0;
  }
  v3 = *(int (__thiscall ****)(_DWORD, int))(this + 32);
  if ( v3 )
  {
    result = (**v3)(v3, 1);
    *(_DWORD *)(this + 32) = 0;
  }
  v4 = *(int (__thiscall ****)(_DWORD, int))(this + 36);
  if ( v4 )
  {
    result = (**v4)(v4, 1);
    *(_DWORD *)(this + 36) = 0;
  }
  v5 = *(int (__thiscall ****)(_DWORD, int))(this + 40);
  if ( v5 )
  {
    result = (**v5)(v5, 1);
    *(_DWORD *)(this + 40) = 0;
  }
  v6 = *(int (__thiscall ****)(_DWORD, int))(this + 44);
  if ( v6 )
  {
    result = (**v6)(v6, 1);
    *(_DWORD *)(this + 44) = 0;
  }
  *(_BYTE *)(this + 58) = 0;
  return result;
}
