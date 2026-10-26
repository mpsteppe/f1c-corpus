int __thiscall sub_5FB180(_DWORD *this, int a2, int a3, int a4, int a5)
{
  _DWORD *v6; // eax
  void *v7; // edi
  _DWORD *v8; // esi
  _DWORD *i; // eax
  int v10; // ebp
  int v12; // eax
  _DWORD *v13; // eax
  _DWORD *v14; // eax
  int v15; // ebp
  bool v16; // zf
  int v17; // ebx
  _UNKNOWN *retaddr; // [esp+14h] [ebp+0h]

  v6 = (_DWORD *)this[72];
  v7 = this + 72;
  v8 = 0;
  this[74] = v6;
  if ( v6 )
  {
    for ( i = (_DWORD *)*v6; i; i = (_DWORD *)*v13 )
    {
      if ( i[2] == a2 && i[3] == a3 )
      {
        v10 = a4;
        if ( i[5] == a4 && i[6] == a5 )
          return -3;
      }
      else
      {
        v10 = a4;
      }
      v12 = this[74];
      if ( v12 )
        this[74] = *(_DWORD *)(v12 + 4);
      v13 = (_DWORD *)this[74];
      if ( !v13 )
        goto LABEL_14;
    }
  }
  v10 = a4;
LABEL_14:
  v14 = operator new(0x1Cu);
  if ( v14 )
  {
    *v14 = 0;
    v14[2] = 0;
    v14[3] = 0;
    v14[4] = 0;
    v14[6] = 0;
    v14[1] = -1;
    v14[5] = 255;
    v8 = v14;
  }
  switch ( v10 )
  {
    case 6:
    case 5:
      v15 = 16;
      break;
    case 7:
      v15 = 24;
      break;
    case 14:
      v15 = 32;
      break;
    default:
      v16 = v10 == 8;
      v15 = 32;
      if ( !v16 )
        v15 = a4;
      break;
  }
  v17 = this[75];
  sub_5FDFB0(v8, 1);
  sub_47F6E0(v7, this[75] - 1);
  v8[2] = retaddr;
  v8[1] = v17;
  v8[3] = a2;
  v8[4] = v15;
  v8[5] = a3;
  v8[6] = a4;
  return 0;
}
