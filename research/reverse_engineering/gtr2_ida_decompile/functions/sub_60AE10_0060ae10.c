int __thiscall sub_60AE10(int *this, int a2, int a3)
{
  int v4; // ecx
  int v5; // eax
  int v6; // eax
  char v8; // [esp+0h] [ebp-8h]

  v4 = *this;
  v5 = 0;
  if ( (v4 & 0x40) != 0 )
    v5 = 16;
  if ( (v4 & 2) != 0 )
    v5 |= 8u;
  if ( (v4 & 4) != 0 )
    v6 = v5 | 0x200;
  else
    v6 = v5 | 8;
  if ( (*(int (__stdcall **)(int, int, int, int, _DWORD, int *, _DWORD))(*(_DWORD *)a2 + 108))(
         a2,
         2 * a3,
         v6,
         101,
         0,
         this + 7,
         0) )
  {
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error creating DirectX index buffer", v8);
    return -1;
  }
  else
  {
    this[1] = a3;
    return 0;
  }
}
