int __thiscall sub_4D12C0(_DWORD *this)
{
  int result; // eax
  _DWORD *i; // edi
  int v4; // ebx
  int v5; // edi
  _DWORD *v6; // eax
  _DWORD *v7; // edx
  _DWORD *v8; // eax
  int v9; // ecx
  _DWORD *v10; // eax
  int k; // edi
  int j; // edi
  _BYTE v13[272]; // [esp+8h] [ebp-110h] BYREF

  result = sub_568210(aPitorder);
  if ( result )
  {
    this[106] = 0;
    for ( i = (_DWORD *)sub_5679C0(aTeam); i; i = (_DWORD *)sub_49ADB0(i) )
    {
      v4 = this[106];
      *(_DWORD *)&v13[4 * v4 + 64] = sub_567970(i);
      this[106] = v4 + 1;
    }
    v5 = this[106];
    v6 = (_DWORD *)sub_587C03(8 * v5 + 4);
    if ( v6 )
    {
      v7 = v6 + 1;
      *v6 = v5;
      v8 = v6 + 1;
      if ( v5 - 1 >= 0 )
      {
        v9 = v5;
        do
        {
          *v8 = 0;
          v8[1] = -1;
          v8 += 2;
          --v9;
        }
        while ( v9 );
      }
      v10 = v7;
    }
    else
    {
      v10 = 0;
    }
    this[107] = v10;
    if ( sub_4C58A0((int)v13, 64, (int)aReversepitorde, 0) || !sub_588410(v13, aFalse_0) )
    {
      result = this[106];
      for ( j = 0; j < result; ++j )
      {
        sub_566650(*(_DWORD *)&v13[4 * j + 64]);
        result = this[106];
      }
    }
    else
    {
      result = this[106];
      for ( k = 0; k < result; ++k )
      {
        sub_566650(*(_DWORD *)&v13[4 * (result - k) + 60]);
        result = this[106];
      }
    }
  }
  return result;
}
