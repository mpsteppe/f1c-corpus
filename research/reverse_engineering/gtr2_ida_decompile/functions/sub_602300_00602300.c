int __thiscall sub_602300(_DWORD *this, _DWORD *a2, int a3, int a4, int a5, int a6)
{
  _DWORD *v6; // edi
  int v8; // ecx
  int v9; // ecx
  int v10; // eax
  int v11; // edx
  int v12; // ebx
  int v13; // eax
  int v15; // ecx
  int v16; // ebp
  int v17; // eax
  int v18; // ecx
  int v19; // ebx
  int v20; // eax
  int v21; // ebx
  int v22; // ebp
  int v23; // eax
  int v24; // [esp-20h] [ebp-34h]
  int v25; // [esp-1Ch] [ebp-30h]
  int v26; // [esp-18h] [ebp-2Ch]
  int v27; // [esp+10h] [ebp-4h]

  v6 = a2;
  if ( (*a2 & 0x20) == 0 )
  {
    v15 = this[1];
    if ( (*a2 & 0x10) != 0 )
    {
      v16 = a3;
      a3 = (int)(this + 1);
      if ( (v15 & 0x400000) == 0 )
        v16 = 1;
      v17 = a2[2];
      v18 = a2[1];
      a2 = 0;
      if ( v18 > v17 )
        v17 = v18;
      v19 = a6;
      v20 = sub_644E28(this[2387], v17, v16, a4, a5, a6, &a2);
      this[2] = v20;
      if ( !v20 )
      {
        if ( v19 == 2 )
          sub_5E71A0(v6, (int)a2, 4);
        else
          sub_5E71A0(v6, (int)a2, 8);
        v6[5] = v16;
        return 0;
      }
      sub_5D8C80(a3, (char *)0xFFFFFFFF, "Error 0x%x creating D3D cube render target", v20);
    }
    else
    {
      v21 = a3;
      a3 = (int)(this + 1);
      if ( (v15 & 0x200000) == 0 )
        v21 = 1;
      v22 = a6;
      v26 = a2[2];
      v25 = a2[1];
      v24 = this[2387];
      a2 = 0;
      v23 = sub_644DB8(v24, v25, v26, v21, a4, a5, a6, &a2);
      this[2] = v23;
      if ( !v23 )
      {
        if ( v22 == 2 )
          sub_5E71A0(v6, (int)a2, 4);
        else
          sub_5E71A0(v6, (int)a2, 8);
        v6[5] = v21;
        return 0;
      }
      sub_5D8C80(a3, (char *)0xFFFFFFFF, "Error 0x%x creating D3D render target", v23);
    }
    return -1;
  }
  v8 = this[1];
  v27 = a3;
  a3 = (int)(this + 1);
  if ( ((unsigned int)&byte_800000 & v8) == 0 )
    v27 = 1;
  v9 = a2[1];
  v10 = a2[2];
  a2 = 0;
  v11 = v9;
  if ( v9 <= v10 )
    v11 = v10;
  v12 = a6;
  v13 = sub_644E91(this[2387], v9, v10, v11, v27, a4, a5, a6, &a2);
  this[2] = v13;
  if ( v13 )
  {
    sub_5D8C80(a3, (char *)0xFFFFFFFF, "Error 0x%x creating D3D cube render target", v13);
    return -1;
  }
  else
  {
    if ( v12 == 2 )
      sub_5E71A0(v6, (int)a2, 4);
    else
      sub_5E71A0(v6, (int)a2, 8);
    v6[5] = v27;
    return 0;
  }
}
