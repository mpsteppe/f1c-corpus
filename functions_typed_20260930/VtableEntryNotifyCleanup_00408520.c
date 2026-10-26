int __thiscall sub_408520(_DWORD *this)
{
  int (__thiscall ***v2)(_DWORD, int); // ecx
  int result; // eax
  int (__thiscall ***v4)(_DWORD, int); // ecx
  int (__thiscall ***v5)(_DWORD, int); // ecx
  int (__thiscall ***v6)(_DWORD, int); // ecx
  int (__thiscall ***v7)(_DWORD, int); // ecx
  int (__thiscall ***v8)(_DWORD, int); // ecx
  int (__thiscall ***v9)(_DWORD, int); // ecx
  int (__thiscall ***v10)(_DWORD, int); // ecx
  int (__thiscall ***v11)(_DWORD, int); // ecx

  v2 = (int (__thiscall ***)(_DWORD, int))this[4];
  *this = &off_59E60C;
  if ( v2 )
    result = (**v2)(v2, 1);
  v4 = (int (__thiscall ***)(_DWORD, int))this[5];
  if ( v4 )
    result = (**v4)(v4, 1);
  v5 = (int (__thiscall ***)(_DWORD, int))this[6];
  if ( v5 )
    result = (**v5)(v5, 1);
  v6 = (int (__thiscall ***)(_DWORD, int))this[7];
  if ( v6 )
    result = (**v6)(v6, 1);
  v7 = (int (__thiscall ***)(_DWORD, int))this[8];
  if ( v7 )
    result = (**v7)(v7, 3);
  v8 = (int (__thiscall ***)(_DWORD, int))this[9];
  if ( v8 )
    result = (**v8)(v8, 1);
  v9 = (int (__thiscall ***)(_DWORD, int))this[10];
  if ( v9 )
    result = (**v9)(v9, 1);
  v10 = (int (__thiscall ***)(_DWORD, int))this[11];
  if ( v10 )
    result = (**v10)(v10, 1);
  v11 = (int (__thiscall ***)(_DWORD, int))this[12];
  if ( v11 )
    result = (**v11)(v11, 1);
  *this = &off_59E634;
  return result;
}

