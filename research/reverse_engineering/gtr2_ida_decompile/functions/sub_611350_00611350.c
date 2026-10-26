int __thiscall sub_611350(int this, void **a2, int a3, int a4, int a5)
{
  int v5; // edi
  _DWORD *v7; // eax
  char v9; // [esp+0h] [ebp-1Ch]

  v5 = 0;
  if ( a2 )
  {
    if ( *a2 )
    {
      sub_60B4D0();
    }
    else
    {
      v7 = operator new(0x50u);
      if ( v7 )
        *a2 = sub_60ADA0(v7);
      else
        *a2 = 0;
    }
    sub_60AC10(*a2);
    if ( *(char *)(this + 4) < 0 )
      v5 = 64;
    if ( (a5 & 1) != 0 )
      v5 |= 1u;
    if ( (a5 & 2) != 0 )
      v5 |= 2u;
    if ( (a5 & 4) != 0 )
      v5 |= 4u;
    if ( (a5 & 8) != 0 )
      v5 |= 8u;
    if ( (a5 & 0x40000) != 0 )
      v5 |= 0x40000u;
    *(_DWORD *)*a2 = v5;
    if ( !sub_60B2D0(*a2, *(_DWORD *)(this + 9548), a3, a4) )
      return 0;
    sub_5D8C80(this + 4, (char *)0xFFFFFFFF, "Error creating DirectX vertex buffer", v9);
  }
  else
  {
    sub_5D8C80(this + 4, (char *)0xFFFFFFFF, "Invalid CUBE vertex buffer pointer", v9);
  }
  return -1;
}
