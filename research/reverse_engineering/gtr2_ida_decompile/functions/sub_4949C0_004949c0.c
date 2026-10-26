int __thiscall sub_4949C0(_DWORD *this, int a2, int a3, int a4, int a5)
{
  int v6; // ebp
  int v7; // ecx
  int i; // ebx
  int v9; // eax
  int v10; // edi
  int v11; // eax
  int v13; // [esp-8h] [ebp-60h]
  int v14; // [esp+20h] [ebp-38h]
  int v15; // [esp+24h] [ebp-34h]

  sub_4CE5F0(a2, a3, a4, a5);
  sub_4E0080(this[12], off_759F14[0], 0, 0, 1, 0, 0, 0, 0);
  v15 = sub_4E0080(this[12], off_759F18[0], 0, 0, 1, 0, 0, 0, 0);
  v6 = this[1] + this[133] + this[135];
  v7 = 0;
  for ( i = this[3] + this[134] + this[136]; v7 < this[145]; ++v7 )
  {
    v9 = v7 + this[139];
    if ( v9 >= this[37] )
      break;
    v10 = v15;
    if ( v9 != this[146] )
      v10 = v14;
    if ( v10 )
    {
      v13 = *(_DWORD *)(v10 + 20);
      v11 = sub_4DDFE0(&unk_B6E2A0, *(_DWORD *)(v10 + 24));
      sub_4D5E10(this, v10, 0, 0, v11, i, v6, v13);
      v7 = 0;
    }
  }
  return 0;
}
