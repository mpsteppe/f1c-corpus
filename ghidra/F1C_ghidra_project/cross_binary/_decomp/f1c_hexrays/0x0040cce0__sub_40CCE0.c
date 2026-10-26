// f1c  0x0040cce0  size=117
int __thiscall sub_40CCE0(int this)
{
  int result; // eax
  int (__thiscall ***v3)(_DWORD, int); // ecx
  int (__thiscall ***v4)(_DWORD, int); // ecx
  int (__thiscall ***v5)(_DWORD, int); // ecx

  if ( (unsigned __int8)sub_4D7A50(2, aDDevF119992002_15, 3785) )
    sub_4D7AA0(&unk_8AD25C, aEnteredCammanP);
  *(_DWORD *)(this + 8) = 0;
  result = sub_4083E0(&flt_5EA4E8);
  v3 = *(int (__thiscall ****)(_DWORD, int))(this + 24);
  if ( v3 )
  {
    result = (**v3)(v3, 1);
    *(_DWORD *)(this + 24) = 0;
  }
  v4 = *(int (__thiscall ****)(_DWORD, int))(this + 28);
  if ( v4 )
  {
    result = (**v4)(v4, 1);
    *(_DWORD *)(this + 28) = 0;
  }
  v5 = *(int (__thiscall ****)(_DWORD, int))(this + 32);
  if ( v5 )
  {
    result = (**v5)(v5, 1);
    *(_DWORD *)(this + 32) = 0;
  }
  *(_BYTE *)(this + 46) = 0;
  return result;
}
