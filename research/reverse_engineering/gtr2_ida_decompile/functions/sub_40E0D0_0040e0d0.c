void __thiscall sub_40E0D0(_DWORD *this)
{
  void (__thiscall ***v2)(_DWORD, int); // ecx
  void (__thiscall ***v3)(_DWORD, int); // ecx
  void (__thiscall ***v4)(_DWORD, int); // ecx
  void (__thiscall ***v5)(_DWORD, int); // ecx
  void (__thiscall ***v6)(_DWORD, int); // ecx
  void (__thiscall ***v7)(_DWORD, int); // ecx
  void (__thiscall ***v8)(_DWORD, int); // ecx
  void (__thiscall ***v9)(_DWORD, int); // ecx
  void (__thiscall ***v10)(_DWORD, int); // ecx

  *this = &off_6F1FA4;
  v2 = (void (__thiscall ***)(_DWORD, int))this[4];
  if ( v2 )
    (**v2)(v2, 1);
  v3 = (void (__thiscall ***)(_DWORD, int))this[5];
  if ( v3 )
    (**v3)(v3, 1);
  v4 = (void (__thiscall ***)(_DWORD, int))this[6];
  if ( v4 )
    (**v4)(v4, 1);
  v5 = (void (__thiscall ***)(_DWORD, int))this[7];
  if ( v5 )
    (**v5)(v5, 1);
  v6 = (void (__thiscall ***)(_DWORD, int))this[8];
  if ( v6 )
  {
    if ( *(v6 - 1) )
      (**v6)(v6, 3);
    else
      j_j__free(v6 - 1);
  }
  v7 = (void (__thiscall ***)(_DWORD, int))this[9];
  if ( v7 )
    (**v7)(v7, 1);
  v8 = (void (__thiscall ***)(_DWORD, int))this[10];
  if ( v8 )
    (**v8)(v8, 1);
  v9 = (void (__thiscall ***)(_DWORD, int))this[11];
  if ( v9 )
    (**v9)(v9, 1);
  v10 = (void (__thiscall ***)(_DWORD, int))this[12];
  if ( v10 )
    (**v10)(v10, 1);
  *this = &off_6F1F7C;
}
