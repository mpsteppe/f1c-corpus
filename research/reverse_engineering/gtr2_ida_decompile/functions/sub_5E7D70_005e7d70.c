int __thiscall sub_5E7D70(void *this, void **a2, int a3, int a4, int a5, int a6)
{
  _DWORD *v7; // eax
  _DWORD *v8; // esi
  int v9; // eax
  void *v11; // esi
  char v12; // [esp+0h] [ebp-18h]

  if ( a2 )
  {
    v7 = operator new(0x88u);
    if ( v7 )
      v8 = sub_5E70C0(v7);
    else
      v8 = 0;
    *a2 = v8;
    if ( !sub_5E71D0((int)v8, a5, 1) )
    {
      if ( a3 > 0 && a4 > 0 )
      {
        v8[1] = a3;
        v8[2] = a4;
      }
      v9 = v8[5];
      *v8 = 1;
      if ( !(*(int (__thiscall **)(int, _DWORD *, int))(*(_DWORD *)dword_FB27A4 + 216))(dword_FB27A4, v8, v9) )
      {
        sub_5FDFB0(*a2, 1);
        ++*((_DWORD *)*a2 + 27);
        return 0;
      }
    }
    v11 = *a2;
    if ( *a2 )
    {
      nullsub_7(*a2);
      j__free(v11);
    }
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error initializing surface", v12);
  }
  else
  {
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Invalid surface pointer", v12);
  }
  return -1;
}
