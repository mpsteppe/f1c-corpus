int __thiscall sub_541F40(int *this)
{
  int v2; // esi
  int v3; // ebp
  int *v4; // edi
  const char *v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // ecx
  double v9; // st7
  double v11; // st6
  unsigned __int8 v12; // c0
  unsigned __int8 v13; // c3
  int v15; // [esp+10h] [ebp-22Ch]
  float v17; // [esp+18h] [ebp-224h]
  void *Block[4]; // [esp+1Ch] [ebp-220h] BYREF
  char v19; // [esp+2Ch] [ebp-210h]
  char Buffer[512]; // [esp+30h] [ebp-20Ch] BYREF
  int v21; // [esp+238h] [ebp-4h]

  v2 = 0;
  v15 = 0;
  sub_40B430();
  v3 = dword_BE1D0C;
  v21 = 0;
  if ( !dword_BE1D0C )
    goto LABEL_17;
  v4 = this + 8;
  while ( 1 )
  {
    v5 = (const char *)dword_91CA88;
    if ( !dword_91CA88 )
      v5 = WindowName;
    sprintf(Buffer, "%s%s%s%d%s", v5, "Ambient\\", "announcer_", ++v2, ".wav");
    sub_615860(Buffer);
    Block[2] = (void *)-1;
    Block[3] = (void *)-1;
    v19 = 0;
    v6 = (*(int (__thiscall **)(int, void **, int, int))(*(_DWORD *)v3 + 92))(v3, Block, 1, 17);
    *v4 = v6;
    if ( v6 )
      break;
LABEL_10:
    if ( !*v4 )
      goto LABEL_16;
    ++v4;
    if ( v2 >= 1 )
      goto LABEL_17;
  }
  v7 = (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 20))(v6);
  v8 = *v4;
  if ( !v7 )
  {
    v9 = flt_B70B64;
    v17 = *(float *)&dword_B70B88;
    v11 = 1.0;
    if ( !(v12 | v13) )
      v11 = 1.0 / flt_B70B40;
    *(float *)(v8 + 28) = v11;
    *(float *)(v8 + 32) = 1.0 - v11 * v17;
    *(float *)(v8 + 36) = v9;
    goto LABEL_10;
  }
  if ( v8 )
    (**(void (__thiscall ***)(int, int))v8)(v8, 1);
  *v4 = 0;
LABEL_16:
  v15 = 1;
  (*(void (__thiscall **)(int *))(*this + 8))(this);
LABEL_17:
  if ( Block[0] )
    j_j__free(Block[0]);
  return v15;
}
