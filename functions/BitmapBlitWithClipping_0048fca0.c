int __thiscall sub_48FCA0(_DWORD *this, int a2, int a3)
{
  int result; // eax
  int v4; // edi
  int v6; // eax
  bool v7; // cc
  int v9; // eax
  int v10; // esi
  int v11; // edi
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // [esp-18h] [ebp-24h]
  int v17; // [esp+4h] [ebp-8h]
  int v18; // [esp+8h] [ebp-4h]
  int v19; // [esp+10h] [ebp+4h]
  int v20; // [esp+14h] [ebp+8h]

  result = this[14];
  if ( result )
  {
    v4 = *(_DWORD *)(result + 12);
    v18 = v4;
    if ( v4 )
    {
      v6 = this[9];
      v7 = a2 < v6;
      v17 = a2;
      v19 = a3;
      if ( v7 )
      {
        v20 = v6 - a2;
        v17 = this[9];
      }
      else
      {
        v20 = 0;
      }
      v9 = this[7];
      if ( a3 >= v9 )
      {
        v10 = 0;
      }
      else
      {
        v10 = v9 - a3;
        v19 = this[7];
      }
      v11 = *(_DWORD *)(v4 + 28);
      v12 = this[10];
      if ( v11 + a2 > v12 )
        v11 = v12 - a2;
      v13 = this[8];
      if ( *(_DWORD *)(v18 + 32) + a3 <= v13 )
        v14 = *(_DWORD *)(v18 + 32);
      else
        v14 = v13 - a3;
      v16 = v14;
      v15 = GlobalAccessor_5150(&unk_7CDE00);
      return F_10ParamForwarder(v18, v20, v10, v15, v17, v19, v11, v16, 0, 0);
    }
  }
  return result;
}
