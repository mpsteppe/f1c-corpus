int __thiscall sub_5AB250(int this, _DWORD *a2, int a3)
{
  _DWORD *v3; // esi
  int v5; // eax
  _DWORD *v6; // eax
  _DWORD *v7; // ecx
  int v8; // edx
  int v9; // eax
  int v11; // ecx
  int v12; // eax

  v3 = *(_DWORD **)(a3 + 16);
  if ( (v3[14] & 0x400) == 0 )
  {
    v5 = sub_5AB160((int *)this, a3);
    *(_DWORD *)this = v5;
    if ( v5 == -1 )
    {
      if ( a2 && (v6 = *(_DWORD **)(sub_598170(a2) + 40)) != 0 )
      {
        while ( 1 )
        {
          v7 = (_DWORD *)v6[4];
          v8 = v7[14];
          if ( (v8 & 0x80000) == 0
            && (v8 & 0x400) != 0
            && v7[15] != 0x7FFFFFFF
            && v6[23] == *(_DWORD *)(a3 + 92)
            && v7[12] == v3[12]
            && v7[7] == v3[7]
            && v7[8] == v3[8] )
          {
            break;
          }
          v6 = (_DWORD *)v6[3];
          if ( !v6 )
            goto LABEL_13;
        }
        v3[14] |= 8u;
        v3[6] = v7[6];
        v7[6] = 0;
        v7[15] = 0;
        v7[14] &= 0xFFFFFBF7;
      }
      else
      {
LABEL_13:
        if ( sub_5B4BE0(this) )
          return 0;
        sub_5AB0A0(this, (int)a2);
        v9 = sub_5AB160((int *)this, a3);
        *(_DWORD *)this = v9;
        if ( v9 )
          return 0;
      }
    }
    v11 = v3[5];
    if ( v11 )
    {
      v12 = (*(int (__stdcall **)(_DWORD, int, _DWORD))(**(_DWORD **)(this + 4448) + 116))(
              *(_DWORD *)(this + 4448),
              v11,
              v3[6]);
      *(_DWORD *)this = v12;
      if ( v12 )
        return 0;
      v3[14] |= 0x400u;
    }
  }
  ++v3[15];
  return 1;
}
