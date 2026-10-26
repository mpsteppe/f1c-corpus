void __thiscall sub_4F8900(int this, int a2)
{
  int v2; // esi
  int v4; // eax
  unsigned __int8 *v5; // ebp
  unsigned __int8 v6; // al
  char v7; // bl
  _DWORD *v8; // ecx
  int v9; // esi
  char *v10; // esi
  bool v11; // al
  bool v12; // al
  int v13; // esi
  int v14; // eax
  unsigned __int8 *v15; // [esp+8h] [ebp-8h]

  v2 = a2;
  v4 = (*(_DWORD *)a2 >> 6) & 0x3FF;
  if ( *(_DWORD *)(this + 832) != v4 )
  {
    *(_DWORD *)(this + 832) = v4;
    *(float *)(this + 780) = *(float *)(a2 + 4);
  }
  sub_4F7CC0((_DWORD *)(this + 392));
  sub_4F7CC0((_DWORD *)(this + 4));
  if ( ((*(_DWORD *)a2 >> 6) & 0x3FF) != 0 )
  {
    v5 = (unsigned __int8 *)(this + 784);
    v15 = (unsigned __int8 *)(a2 + 8);
    while ( 1 )
    {
      v6 = *v15;
      if ( *v15 != *v5 )
      {
        *v5 = v6;
        *(float *)(this + 780) = *(float *)(v2 + 4);
      }
      v7 = 0;
      if ( (v6 & 0x40) != 0 )
      {
        v6 &= ~0x40u;
        v7 = 1;
      }
      if ( (v6 & 0x80u) == 0 )
      {
        v8 = (_DWORD *)(this + 392);
      }
      else
      {
        v6 &= ~0x80u;
        v8 = (_DWORD *)(this + 4);
      }
      v9 = v6;
      sub_4F7DC0(v8, v6, 0.0, 0);
      v10 = (char *)&unk_62BF68 + 25304 * v9;
      if ( *((_DWORD *)v10 + 4146) == 2 )
        v10[21121] = v7;
      ++v15;
      if ( (int)&(++v5)[-784 - this] >= ((*(_DWORD *)a2 >> 6) & 0x3FF) )
        break;
      v2 = a2;
    }
  }
  v11 = sub_42DBA0();
  if ( sub_4F8410((_DWORD *)this, v11 ? dword_75AACC : 0) )
  {
    v12 = sub_42DBA0();
    v13 = dword_75AACC;
    v14 = sub_4F82E0((_DWORD *)this, v12 ? dword_75AACC : 0);
    sub_4DCEB0((int *)(v13 + 20836), v14);
  }
}
