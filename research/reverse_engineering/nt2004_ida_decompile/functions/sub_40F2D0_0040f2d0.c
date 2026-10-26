int __thiscall sub_40F2D0(int this)
{
  int v2; // edi
  _DWORD *v3; // ebp
  bool v4; // zf
  int v5; // edi
  _DWORD *v6; // ebp
  int v7; // edi
  _DWORD *v8; // ebp
  _DWORD *v9; // edi
  void *v10; // ebp
  _DWORD *v11; // edi
  void *v12; // ebp
  int result; // eax

  *(_DWORD *)(this + 4) = 0;
  *(_BYTE *)(this + 8) = 0;
  *(_BYTE *)(this + 9) = 0;
  v2 = *(_DWORD *)(this + 12);
  while ( v2 )
  {
    v3 = (_DWORD *)v2;
    v4 = *(_BYTE *)(v2 + 8) == 0;
    v2 = *(_DWORD *)(v2 + 4);
    if ( !v4 && *v3 )
      sub_4115A0(1);
    sub_5BE8AE(v3);
  }
  *(_DWORD *)(this + 12) = 0;
  *(_DWORD *)(this + 16) = 0;
  *(_DWORD *)(this + 20) = 0;
  *(_DWORD *)(this + 24) = 0;
  v5 = *(_DWORD *)(this + 28);
  while ( v5 )
  {
    v6 = (_DWORD *)v5;
    v4 = *(_BYTE *)(v5 + 8) == 0;
    v5 = *(_DWORD *)(v5 + 4);
    if ( !v4 && *v6 )
      sub_4115A0(1);
    sub_5BE8AE(v6);
  }
  *(_DWORD *)(this + 28) = 0;
  *(_DWORD *)(this + 32) = 0;
  *(_DWORD *)(this + 36) = 0;
  *(_DWORD *)(this + 40) = 0;
  v7 = *(_DWORD *)(this + 44);
  while ( v7 )
  {
    v8 = (_DWORD *)v7;
    v4 = *(_BYTE *)(v7 + 8) == 0;
    v7 = *(_DWORD *)(v7 + 4);
    if ( !v4 && *v8 )
      sub_4115A0(1);
    sub_5BE8AE(v8);
  }
  *(_DWORD *)(this + 44) = 0;
  *(_DWORD *)(this + 48) = 0;
  *(_DWORD *)(this + 52) = 0;
  *(_DWORD *)(this + 56) = 0;
  *(_DWORD *)(this + 76) = 0;
  *(_DWORD *)(this + 80) = -1;
  *(_BYTE *)(this + 84) = 0;
  *(_BYTE *)(this + 85) = 0;
  *(_BYTE *)(this + 86) = 0;
  *(_DWORD *)(this + 88) = 0;
  v9 = *(_DWORD **)(this + 96);
  while ( v9 )
  {
    v10 = v9;
    v9 = (_DWORD *)v9[1];
    sub_4145D0(v10);
    sub_5BE8AE(v10);
  }
  *(_DWORD *)(this + 96) = 0;
  *(_DWORD *)(this + 100) = 0;
  *(_DWORD *)(this + 104) = 0;
  *(_DWORD *)(this + 108) = 0;
  *(_DWORD *)(this + 92) = 0;
  *(_BYTE *)(this + 112) = 0;
  *(_BYTE *)(this + 113) = 0;
  *(_DWORD *)(this + 116) = 0;
  *(_DWORD *)(this + 120) = 0;
  *(_DWORD *)(this + 124) = 0;
  *(_DWORD *)(this + 128) = 0;
  v11 = *(_DWORD **)(this + 148);
  while ( v11 )
  {
    v12 = v11;
    v11 = (_DWORD *)v11[1];
    sub_4145A0(v12);
    sub_5BE8AE(v12);
  }
  *(_DWORD *)(this + 148) = 0;
  *(_DWORD *)(this + 152) = 0;
  *(_DWORD *)(this + 156) = 0;
  *(_DWORD *)(this + 160) = 0;
  result = sub_4667A0(this + 132);
  *(_BYTE *)(this + 164) = 0;
  return result;
}
