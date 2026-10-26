int __thiscall sub_4A65D0(int this, char a2)
{
  int v3; // ebp
  _DWORD **v4; // eax
  char v5; // cl
  int *v6; // edi
  int v7; // esi
  _DWORD **v9; // [esp+8h] [ebp-4h]

  *(_DWORD *)this = &off_5EA000;
  sub_4A78A0();
  if ( *(_DWORD *)(this + 288) )
    sub_5BE8AE(*(LPVOID *)(this + 288));
  v3 = *(_DWORD *)(this + 272);
  while ( v3 )
  {
    v4 = (_DWORD **)v3;
    v5 = *(_BYTE *)(v3 + 8);
    v3 = *(_DWORD *)(v3 + 4);
    v9 = v4;
    if ( v5 )
    {
      v6 = *v4;
      if ( *v4 )
      {
        v7 = *v6;
        while ( v7 )
        {
          v7 = *(_DWORD *)(v7 + 4);
          sub_4A8220(1);
        }
        *v6 = 0;
        v6[1] = 0;
        v6[2] = 0;
        v6[3] = 0;
        sub_5BE8AE(v6);
        v4 = v9;
      }
    }
    sub_5BE8AE(v4);
  }
  *(_DWORD *)(this + 272) = 0;
  *(_DWORD *)(this + 276) = 0;
  *(_DWORD *)(this + 280) = 0;
  *(_DWORD *)(this + 284) = 0;
  sub_49C520((LPVOID *)this);
  if ( (a2 & 1) != 0 )
    sub_5BE8AE((LPVOID)this);
  return this;
}
