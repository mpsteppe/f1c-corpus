char __thiscall sub_4D3840(_BYTE *this, _DWORD *a2, int a3)
{
  int v3; // ebp
  _DWORD *v4; // edi
  int v5; // eax
  _DWORD *v6; // esi
  _DWORD *v7; // eax
  int v8; // edx
  int v10; // [esp-8h] [ebp-18h]

  if ( !*this )
    return 0;
  switch ( *a2 >> 28 )
  {
    case 1:
      v3 = 0;
      break;
    case 2:
    case 3:
      v3 = 1;
      break;
    case 4:
      v3 = 2;
      break;
    case 6:
      v3 = 3;
      break;
    default:
      v3 = -1;
      break;
  }
  if ( sub_4D36C0(v3, (int)a2) )
    return 0;
  v4 = 0;
  sub_414470(&dword_7D5DC0);
  if ( dword_7D5DC8 )
  {
    v4 = *(_DWORD **)dword_7D5DC8;
    v10 = *(_DWORD *)dword_7D5DC8;
    *(_BYTE *)(dword_7D5DC8 + 8) = 0;
    if ( !(unsigned __int8)sub_4DAD10(v10, 1) )
      v4 = 0;
  }
  if ( !v4 )
  {
    if ( operator new(4u) )
      v5 = sub_4DAFA0(0);
    else
      v5 = 0;
    sub_4DB480(v5, 0);
    v4 = (_DWORD *)sub_4DB530(&dword_7D5DC0);
  }
  sub_4D1850(v4, a2);
  v6 = &this[16 * v3 + 64];
  if ( !v4 )
    return 0;
  v7 = operator new(0xCu);
  if ( v7 )
  {
    *v7 = v4;
    v7[1] = 0;
    *((_BYTE *)v7 + 8) = 0;
  }
  else
  {
    v7 = 0;
  }
  if ( *v6 )
  {
    v8 = v6[1];
    *(_DWORD *)(v8 + 4) = v7;
  }
  else
  {
    *v6 = v7;
    v6[2] = v7;
  }
  v6[1] = v7;
  ++v6[3];
  sub_4D3700((int)this, v8, 1, v3, *v4 & 0x3F);
  return 1;
}
