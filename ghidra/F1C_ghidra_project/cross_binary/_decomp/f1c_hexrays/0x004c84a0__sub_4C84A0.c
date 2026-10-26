// f1c  0x004c84a0  size=191
int __thiscall sub_4C84A0(_DWORD *this, LPCSTR lpFileName, int a3)
{
  int i; // edi
  _DWORD *v5; // eax
  _DWORD *v6; // esi
  int v7; // eax
  _BYTE v9[4]; // [esp+Ch] [ebp-4h] BYREF

  sub_565DC0(v9);
  sub_565F80(lpFileName, 0, a3, 0);
  for ( i = sub_5662D0(v9); i; i = sub_5662D0(v9) )
  {
    v5 = (_DWORD *)sub_587C03(8);
    v6 = v5;
    if ( v5 )
    {
      *v5 = 0;
      v5[1] = -1;
      sub_566650(i);
      v7 = sub_587C03(12);
      if ( v7 )
      {
        *(_DWORD *)v7 = v6;
        *(_DWORD *)(v7 + 4) = 0;
        *(_BYTE *)(v7 + 8) = 1;
      }
      else
      {
        v7 = 0;
      }
      if ( *this )
      {
        *(_DWORD *)(this[1] + 4) = v7;
      }
      else
      {
        *this = v7;
        this[2] = v7;
      }
      this[1] = v7;
      ++this[3];
    }
    if ( !(unsigned __int8)sub_565F20(v9) )
      break;
  }
  return sub_565E20(v9);
}
