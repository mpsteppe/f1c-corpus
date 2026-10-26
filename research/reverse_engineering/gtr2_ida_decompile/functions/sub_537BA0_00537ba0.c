int __thiscall sub_537BA0(int *this, int a2, int a3, int a4)
{
  int v5; // ebx
  _DWORD *v6; // eax
  _DWORD *v7; // edi
  int v8; // eax
  int v9; // ecx
  int i; // edx
  int v11; // eax
  int v12; // ecx
  int j; // edx
  int v15; // [esp+4h] [ebp-8h]
  int v16; // [esp+8h] [ebp-4h]

  if ( !sub_533890() )
  {
    sub_538940(&unk_BE1CFD, a2);
    v5 = dword_BE1CD8 + 396 * dword_BE1CD4;
    if ( v5 )
    {
      v6 = operator new(0x24u);
      if ( v6 )
      {
        *v6 = 0;
        v6[1] = -1;
        v6[2] = 0;
        v6[3] = -1;
        v6[4] = 0;
        v6[5] = -1;
        v6[7] = 0;
        v6[8] = 0;
        v6[6] = 3;
        v7 = v6;
      }
      else
      {
        v7 = 0;
      }
      sub_615860(v5 + 260);
      sub_615860(v5 + 4);
      sub_615860(v15);
      v7[6] = v16;
      sub_5FDFB0(v7, 1);
    }
  }
  v8 = sub_5354C0(*this);
  v9 = v8;
  *this = v8;
  if ( v8 )
  {
    for ( i = *(_DWORD *)(v8 + 4); i; i = *(_DWORD *)(i + 4) )
      v9 = i;
  }
  this[1] = v9;
  this[2] = v8;
  v11 = sub_5354C0(v8);
  v12 = v11;
  *this = v11;
  if ( v11 )
  {
    for ( j = *(_DWORD *)(v11 + 4); j; j = *(_DWORD *)(j + 4) )
      v12 = j;
  }
  this[2] = v11;
  this[1] = v12;
  return sub_533890();
}
