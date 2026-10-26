int __thiscall sub_45E710(HCURSOR *this)
{
  HCURSOR v2; // eax
  HCURSOR v3; // eax
  HCURSOR v4; // eax
  HCURSOR v5; // eax
  int result; // eax
  char v7; // [esp+0h] [ebp-8h]

  if ( (unsigned __int8)sub_5612D0((int)byte_FAE910, 2, "\\Dev\\Src\\Copperhead\\App\\Source\\hwinput.cpp", 6649) )
    sub_561210((int)byte_FAE910, "Entered HWInput::Exit()", v7);
  v2 = this[1413];
  this[1570] = 0;
  if ( v2 )
  {
    (*(void (__stdcall **)(HCURSOR))(*(_DWORD *)v2 + 32))(v2);
    (*(void (__stdcall **)(HCURSOR))(*(_DWORD *)this[1413] + 8))(this[1413]);
    this[1413] = 0;
  }
  v3 = this[1156];
  this[1313] = 0;
  if ( v3 )
  {
    (*(void (__stdcall **)(HCURSOR))(*(_DWORD *)v3 + 32))(v3);
    (*(void (__stdcall **)(HCURSOR))(*(_DWORD *)this[1156] + 8))(this[1156]);
    this[1156] = 0;
  }
  v4 = this[899];
  this[1056] = 0;
  if ( v4 )
  {
    (*(void (__stdcall **)(HCURSOR))(*(_DWORD *)v4 + 32))(v4);
    (*(void (__stdcall **)(HCURSOR))(*(_DWORD *)this[899] + 8))(this[899]);
    this[899] = 0;
  }
  sub_45DD50(this + 816);
  v5 = this[2];
  this[159] = 0;
  if ( v5 )
  {
    (*(void (__stdcall **)(HCURSOR))(*(_DWORD *)v5 + 32))(v5);
    (*(void (__stdcall **)(HCURSOR))(*(_DWORD *)this[2] + 8))(this[2]);
    this[2] = 0;
  }
  result = (int)*this;
  if ( *this )
  {
    result = (*(int (__stdcall **)(HCURSOR))(*(_DWORD *)result + 8))(*this);
    *this = 0;
  }
  return result;
}
