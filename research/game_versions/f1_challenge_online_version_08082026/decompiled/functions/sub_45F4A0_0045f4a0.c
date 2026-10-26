int __thiscall sub_45F4A0(_DWORD *this)
{
  int v2; // edi
  _DWORD *v3; // ebx
  int v4; // ebx
  _DWORD *v5; // edi
  int v6; // eax
  int v7; // eax
  char *v8; // ebx
  int v9; // eax
  int v10; // edi
  int v12; // [esp+Ch] [ebp-24Ch]
  int v13; // [esp+Ch] [ebp-24Ch]
  _DWORD *v14; // [esp+10h] [ebp-248h] BYREF
  int v15; // [esp+14h] [ebp-244h]
  int *v16; // [esp+18h] [ebp-240h]
  unsigned __int8 v17[432]; // [esp+1Ch] [ebp-23Ch] BYREF
  _BYTE v18[140]; // [esp+1CCh] [ebp-8Ch] BYREF

  sub_4B3B30(&dword_83EE60);
  while ( sub_4B3AF0(v17) )
  {
    if ( (*(_DWORD *)v17 & 0x10000000) == 0 )
    {
      if ( (unsigned __int8)sub_461440(this) )
      {
        sub_465300(v17);
      }
      else
      {
        v15 = sub_462310(*this);
        v2 = 0;
        v12 = 0;
        if ( (int)this[3973] > 0 )
        {
          v3 = this + 229;
          v16 = this + 3869;
          v14 = this + 229;
          do
          {
            if ( v2 != v15
              && (this[4081] != 3 || (unsigned __int8)sub_461530(1))
              && ((*(_DWORD *)v17 & 0x8000000) != 0 || (unsigned __int8)sub_4614C0(v3)) )
            {
              v4 = *v16;
              v5 = &this[35 * v15];
              if ( (unsigned __int8)sub_4614C0(v5 + 229) && v17[0] < 0x68u )
                *(_DWORD *)v17 = *(_DWORD *)v17 & 0xFFFFFF00 | *((char *)v5 + 1040);
              sub_462250(v17, 1, v4, 2000);
              v2 = v12;
              v3 = v14;
            }
            v6 = this[3973];
            ++v2;
            v3 += 35;
            v12 = v2;
            ++v16;
            v14 = v3;
          }
          while ( v2 < v6 );
        }
      }
    }
  }
  if ( (unsigned __int8)sub_461440(this) )
  {
    v15 = sub_462310(*this);
    sub_461470(v18);
    sub_462300(*this);
    v7 = 0;
    v13 = 0;
    if ( (int)this[3973] > 0 )
    {
      v8 = (char *)(this + 260);
      do
      {
        if ( v7 != v15 && (this[4081] != 3 || (unsigned __int8)sub_461530(1)) )
        {
          if ( (unsigned __int8)sub_4614C0(v8 - 124) )
          {
            v9 = *v8;
            v10 = this[v9 + 3974];
            sub_465460(v9, v10);
            while ( (unsigned __int8)sub_465C30(&v14) )
              sub_462250(v14, 1, v10, 500);
          }
        }
        v7 = v13 + 1;
        v8 += 140;
        ++v13;
      }
      while ( v13 < this[3973] );
    }
    nullsub_3(v18);
  }
  return sub_57A730(0);
}
