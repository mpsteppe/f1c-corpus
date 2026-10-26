char __thiscall sub_459D90(void *this, _DWORD *a2)
{
  char result; // al
  int v3; // esi
  int *v4; // edi
  int v5; // eax
  int v6; // edx
  int *v7; // eax
  int v8; // ecx
  int v9; // ecx
  int v10; // eax
  int v11; // [esp+14h] [ebp-7E4h] BYREF
  int v12; // [esp+18h] [ebp-7E0h] BYREF
  int v13; // [esp+1Ch] [ebp-7DCh] BYREF
  int v14; // [esp+20h] [ebp-7D8h] BYREF
  int v15; // [esp+24h] [ebp-7D4h] BYREF
  int v16[2]; // [esp+28h] [ebp-7D0h] BYREF
  _BYTE v17[384]; // [esp+30h] [ebp-7C8h] BYREF
  int v18; // [esp+1B0h] [ebp-648h]
  char v19; // [esp+1B4h] [ebp-644h]
  int v20; // [esp+1BCh] [ebp-63Ch]
  int v21; // [esp+1C0h] [ebp-638h]
  int v22; // [esp+1C4h] [ebp-634h]
  char Buffer[384]; // [esp+1C8h] [ebp-630h] BYREF
  _BYTE v24[12]; // [esp+348h] [ebp-4B0h] BYREF
  char v25; // [esp+354h] [ebp-4A4h] BYREF

  v16[1] = (int)this;
  result = 0;
  if ( !*a2 )
    return result;
  memset(Buffer, 0, sizeof(Buffer));
  v18 = 0;
  v22 = 0;
  v20 = 0;
  v21 = 0;
  v3 = 0;
  v19 = 0;
  if ( !sub_57A490(Buffer, 384) )
    return 0;
  v4 = (int *)&v25;
  while ( 1 )
  {
    v5 = sub_577B60(v17);
    if ( v5 )
      break;
    if ( sub_578220(aControlpoint, (int)&v11, (int)&v12, (int)&v13, (int)&v14, (int)&v15, (int)v16, 0, 0) )
      goto LABEL_8;
    if ( sub_578220(aControlpoint, (int)&v11, (int)&v12, (int)&v13, 0, 0, 0, 0, 0) )
    {
      v14 = 0;
      v15 = 0;
      v16[0] = 0;
LABEL_8:
      if ( v3 >= 50 )
        goto LABEL_13;
      v6 = v12;
      v7 = v4 - 3;
      *v7 = v11;
      v8 = v13;
      v7[1] = v6;
      v7[2] = v8;
      v9 = v15;
      *v4 = v14;
      v10 = v16[0];
      v4[1] = v9;
      ++v3;
      v4[2] = v10;
      v4 += 6;
    }
LABEL_12:
    if ( !sub_57A490(Buffer, 384) )
      goto LABEL_13;
  }
  if ( v5 != 2 && v5 != 4 )
    goto LABEL_12;
LABEL_13:
  if ( v3 >= 4 )
    return sub_45A1F0(v24, v3);
  return 0;
}
