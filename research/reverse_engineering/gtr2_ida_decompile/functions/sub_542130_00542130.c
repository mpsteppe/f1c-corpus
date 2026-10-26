int __thiscall sub_542130(int *this)
{
  int *v1; // esi
  const char *v3; // eax
  int v4; // edx
  int v5; // eax
  void (__thiscall ***v6)(_DWORD, int); // ecx
  void *Block[4]; // [esp+Ch] [ebp-220h] BYREF
  char v9; // [esp+1Ch] [ebp-210h]
  char Buffer[512]; // [esp+20h] [ebp-20Ch] BYREF
  int v11; // [esp+228h] [ebp-4h]

  v1 = (int *)dword_BE1D0C;
  if ( dword_BE1D0C )
  {
    sub_40B430();
    v3 = (const char *)dword_91CA88;
    v11 = 0;
    if ( !dword_91CA88 )
      v3 = WindowName;
    sprintf(Buffer, "%s%s%s", v3, "Ambient\\", "pithorn.wav");
    sub_615860(Buffer);
    v4 = *v1;
    Block[2] = (void *)-1;
    Block[3] = (void *)-1;
    v9 = 0;
    v5 = (*(int (__thiscall **)(int *, void **, _DWORD, int))(v4 + 92))(v1, Block, 0, 1);
    this[7] = v5;
    if ( v5 )
    {
      if ( (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 20))(v5) )
      {
        v6 = (void (__thiscall ***)(_DWORD, int))this[7];
        if ( v6 )
          (**v6)(v6, 1);
        this[7] = 0;
      }
      else
      {
        sub_40A770(this[7], flt_B70BAC, dword_B70BD0, flt_B70BF4);
      }
    }
    if ( Block[0] )
      j_j__free(Block[0]);
  }
  return 0;
}
