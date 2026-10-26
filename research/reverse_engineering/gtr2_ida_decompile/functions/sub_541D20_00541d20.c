int __thiscall sub_541D20(int *this)
{
  int v2; // ebp
  int v3; // esi
  int *v4; // edi
  const char *v5; // eax
  int v6; // eax
  double v7; // st7
  float *v8; // ecx
  double v10; // st6
  unsigned __int8 v11; // c0
  unsigned __int8 v12; // c3
  float v14; // [esp+Ch] [ebp-224h]
  void *Block[4]; // [esp+10h] [ebp-220h] BYREF
  char v16; // [esp+20h] [ebp-210h]
  char Buffer[512]; // [esp+24h] [ebp-20Ch] BYREF
  int v18; // [esp+22Ch] [ebp-4h]

  sub_40B430();
  v2 = dword_BE1D0C;
  v3 = 0;
  v18 = 0;
  if ( dword_BE1D0C )
  {
    v4 = this + 7;
    do
    {
      v5 = (const char *)dword_91CA88;
      if ( !dword_91CA88 )
        v5 = WindowName;
      sprintf(Buffer, "%s%s%s%d%s", v5, "Ambient\\", "air_horns_", ++v3, ".wav");
      sub_615860(Buffer);
      Block[2] = (void *)-1;
      Block[3] = (void *)-1;
      v16 = 0;
      v6 = (*(int (__thiscall **)(int, void **, _DWORD, int))(*(_DWORD *)v2 + 92))(v2, Block, 0, 1);
      *v4 = v6;
      if ( v6 )
      {
        if ( (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 20))(v6) )
        {
          if ( *v4 )
            (**(void (__thiscall ***)(int, int))*v4)(*v4, 1);
          *v4 = 0;
        }
        else
        {
          v7 = flt_B70AF8;
          v14 = *(float *)&dword_B70B1C;
          v8 = (float *)*v4;
          v10 = 1.0;
          if ( !(v11 | v12) )
            v10 = 1.0 / flt_B70AD4;
          v8[7] = v10;
          v8[8] = 1.0 - v10 * v14;
          v8[9] = v7;
        }
      }
      ++v4;
    }
    while ( v3 < 3 );
  }
  if ( Block[0] )
    j_j__free(Block[0]);
  return 0;
}
