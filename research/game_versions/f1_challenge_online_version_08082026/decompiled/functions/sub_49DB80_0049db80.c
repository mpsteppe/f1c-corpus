int __thiscall sub_49DB80(_DWORD *this)
{
  int v1; // ebx
  int v2; // ebp
  int result; // eax
  int v5; // edi
  int v6; // eax
  char v7; // cl
  int v8; // eax
  char v9; // cl
  int v10; // edi
  int v11; // eax
  char v12; // cl
  int v13; // eax
  char v14; // cl
  int v15; // edi
  int v16; // eax
  char v17; // cl
  int v18; // eax
  char v19; // cl
  int v20; // edi
  int v21; // edi
  float v22; // [esp+0h] [ebp-58h]
  float v23; // [esp+0h] [ebp-58h]
  float v24; // [esp+0h] [ebp-58h]
  float v25; // [esp+0h] [ebp-58h]
  float v26; // [esp+0h] [ebp-58h]
  float v27; // [esp+0h] [ebp-58h]
  _BYTE v28[64]; // [esp+18h] [ebp-40h] BYREF

  v1 = dword_5CCBC0;
  v2 = dword_7CE238;
  result = this[2];
  v5 = dword_5CCBB8;
  if ( result )
  {
    if ( sub_423A00(byte_5EC4C0, aWater, byte_5EC4CC) )
    {
      v6 = 0;
      do
      {
        v7 = aWater[v6];
        byte_5EC4CC[v6++] = v7;
      }
      while ( v7 );
    }
    v8 = 0;
    do
    {
      v9 = byte_5EC4CC[v8];
      v28[v8++] = v9;
    }
    while ( v9 );
    sub_49F6A0(v28, v1, v5, this[2], *(_DWORD *)(this[5] + 84), 1);
    v22 = dbl_7C91B4 - 273.16;
    sub_49DB00(v22, (int)v28);
    sub_49F6A0(v28, v2, v5, this[2], *(_DWORD *)(this[5] + 84), 0);
    v10 = dword_5CCBBC + v5;
    if ( sub_423A00(byte_5EC4C0, aOil, byte_5EC4CC) )
    {
      v11 = 0;
      do
      {
        v12 = aOil[v11];
        byte_5EC4CC[v11++] = v12;
      }
      while ( v12 );
    }
    v13 = 0;
    do
    {
      v14 = byte_5EC4CC[v13];
      v28[v13++] = v14;
    }
    while ( v14 );
    sub_49F6A0(v28, v1, v10, this[2], *(_DWORD *)(this[5] + 84), 1);
    v23 = dbl_7C9174 - 273.16;
    sub_49DB00(v23, (int)v28);
    sub_49F6A0(v28, v2, v10, this[2], *(_DWORD *)(this[5] + 84), 0);
    v15 = dword_5CCBBC + v10;
    if ( sub_423A00(byte_5EC4C0, aBrakes_0, byte_5EC4CC) )
    {
      v16 = 0;
      do
      {
        v17 = aBrakes_0[v16];
        byte_5EC4CC[v16++] = v17;
      }
      while ( v17 );
    }
    v18 = 0;
    do
    {
      v19 = byte_5EC4CC[v18];
      v28[v18++] = v19;
    }
    while ( v19 );
    sub_49F6A0(v28, v1, v15, this[2], *(_DWORD *)(this[5] + 84), 1);
    v24 = dbl_7C7AB8 - 273.16;
    v20 = dword_5CCBBC + v15;
    sub_49DB00(v24, (int)v28);
    sub_49F6A0(v28, v1, v20, this[2], *(_DWORD *)(this[5] + 84), 1);
    v25 = dbl_7C7F1C - 273.16;
    sub_49DB00(v25, (int)v28);
    sub_49F6A0(v28, v2, v20, this[2], *(_DWORD *)(this[5] + 84), 0);
    v21 = dword_5CCBBC + v20;
    v26 = dbl_7C8380 - 273.16;
    sub_49DB00(v26, (int)v28);
    sub_49F6A0(v28, v1, v21, this[2], *(_DWORD *)(this[5] + 84), 1);
    v27 = dbl_7C87E4 - 273.16;
    sub_49DB00(v27, (int)v28);
    return sub_49F6A0(v28, v2, v21, this[2], *(_DWORD *)(this[5] + 84), 0);
  }
  return result;
}
