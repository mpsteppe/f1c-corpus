int __thiscall sub_5C4160(_DWORD *this)
{
  int result; // eax
  int v3; // ebx
  int i; // ebp
  _DWORD *v5; // esi
  int v6; // eax
  int v7; // ecx
  int v8; // edx
  int v9; // eax
  int v10; // ecx
  int v11; // edx
  int v12; // ecx
  int v13; // edx
  char v14; // [esp+7h] [ebp-29h] BYREF
  _DWORD v15[10]; // [esp+8h] [ebp-28h] BYREF

  result = this[9];
  if ( result )
  {
    result = this[1];
    v3 = *(_DWORD *)(result + 444);
    for ( i = 0; i < v3; ++i )
    {
      v5 = *(_DWORD **)(*(_DWORD *)(this[1] + 452) + 4 * i);
      result = v5[87];
      if ( result > 0 )
      {
        v14 = 0;
        sub_5D2070(v15, v5, &v14);
        v6 = v15[5];
        v7 = v15[6];
        v5[57] = v15[4];
        v8 = v15[0];
        v5[58] = v6;
        v9 = v15[1];
        v5[59] = v7;
        v10 = v15[2];
        v5[53] = v8;
        v11 = v15[3];
        v5[54] = v9;
        result = v15[7];
        v5[55] = v10;
        v12 = v15[8];
        v5[56] = v11;
        v13 = v15[9];
        v5[60] = result;
        v5[61] = v12;
        v5[62] = v13;
      }
    }
  }
  return result;
}
