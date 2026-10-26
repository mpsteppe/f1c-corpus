int __thiscall sub_541B60(int *this)
{
  int v2; // ebp
  int v3; // esi
  const char *v4; // eax
  int v5; // eax
  void (__thiscall ***v6)(_DWORD, int); // ecx
  void *Block[4]; // [esp+10h] [ebp-220h] BYREF
  char v9; // [esp+20h] [ebp-210h]
  char Buffer[512]; // [esp+24h] [ebp-20Ch] BYREF
  int v11; // [esp+22Ch] [ebp-4h]

  v2 = 0;
  sub_40B430();
  v3 = dword_BE1D0C;
  v11 = 0;
  if ( dword_BE1D0C )
  {
    if ( (dword_BE1D54 & 1) == 0 )
    {
      dword_BE1D54 |= 1u;
      rand();
      dword_BE1D50 = 0;
    }
    v4 = (const char *)dword_91CA88;
    ++dword_BE1D50;
    if ( !dword_91CA88 )
      v4 = WindowName;
    sprintf(Buffer, "%s%s%s%d%s", v4, "Ambient\\", "fans_normal_", 1, ".wav");
    sub_615860(Buffer);
    Block[2] = (void *)-1;
    Block[3] = (void *)-1;
    v9 = 0;
    v5 = (*(int (__thiscall **)(int, void **, int, int))(*(_DWORD *)v3 + 92))(v3, Block, 1, 17);
    this[8] = v5;
    if ( v5 )
    {
      if ( (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 20))(v5) )
      {
        v6 = (void (__thiscall ***)(_DWORD, int))this[8];
        if ( v6 )
          (**v6)(v6, 1);
        this[8] = 0;
      }
      else
      {
        sub_40A770(this[8], flt_B70A68, dword_B70A8C, flt_B70AB0);
      }
    }
    if ( !this[8] )
      v2 = 1;
  }
  if ( Block[0] )
    j_j__free(Block[0]);
  return v2;
}
