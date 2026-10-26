int __thiscall sub_4EF7E0(_DWORD *this, LPCSTR lpFileName, char *Str)
{
  int i; // edi
  _DWORD *v5; // eax
  _DWORD *v6; // esi
  _DWORD *v7; // eax
  _BYTE v9[4]; // [esp+Ch] [ebp-4h] BYREF

  sub_578870(v9);
  sub_578A30(lpFileName, 0, Str, 0);
  for ( i = sub_578D80(v9); i; i = sub_578D80(v9) )
  {
    v5 = operator new(8u);
    v6 = v5;
    if ( v5 )
    {
      *v5 = 0;
      v5[1] = -1;
      sub_578600(i);
      v7 = operator new(0xCu);
      if ( v7 )
      {
        *v7 = v6;
        v7[1] = 0;
        *((_BYTE *)v7 + 8) = 1;
      }
      else
      {
        v7 = 0;
      }
      if ( this[1] )
      {
        *(_DWORD *)(this[2] + 4) = v7;
      }
      else
      {
        this[1] = v7;
        this[3] = v7;
      }
      this[2] = v7;
      ++this[4];
    }
    if ( !(unsigned __int8)sub_5789D0(v9) )
      break;
  }
  return sub_5788D0(v9);
}
