int __thiscall sub_463A70(int *this)
{
  int v2; // eax
  int v3; // eax
  int result; // eax
  char v5; // [esp+0h] [ebp-8h]

  if ( dword_B640C0 != 5
    && (unsigned __int8)sub_5612D0((int)byte_FAE910, 2, "\\Dev\\Src\\Copperhead\\App\\Source\\hwinput.cpp", 6625) )
  {
    sub_561210((int)byte_FAE910, "Entered HWInput::Post()", v5);
  }
  memset32(this + 161, (int)&nullsub_12, 0x40u);
  if ( this[1925] )
    sub_45E1C0(this + 1638);
  v2 = this[1413];
  this[1570] = 0;
  if ( v2 )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)v2 + 32))(v2);
    (*(void (__stdcall **)(int))(*(_DWORD *)this[1413] + 8))(this[1413]);
    this[1413] = 0;
  }
  v3 = this[1156];
  this[1313] = 0;
  if ( v3 )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)v3 + 32))(v3);
    (*(void (__stdcall **)(int))(*(_DWORD *)this[1156] + 8))(this[1156]);
    this[1156] = 0;
  }
  result = this[899];
  this[1056] = 0;
  if ( result )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)result + 32))(result);
    result = (*(int (__stdcall **)(int))(*(_DWORD *)this[899] + 8))(this[899]);
    this[899] = 0;
  }
  return result;
}
