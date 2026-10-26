// f1c  0x00458050  size=316
int __thiscall sub_458050(void *this, int a2)
{
  int v2; // esi
  _DWORD *v3; // ebx
  int v4; // eax
  int v5; // eax
  int v6; // edx
  int v8; // [esp+14h] [ebp-418h] BYREF
  int v9; // [esp+18h] [ebp-414h] BYREF
  int v10; // [esp+1Ch] [ebp-410h] BYREF
  int v11; // [esp+20h] [ebp-40Ch]
  char v12[384]; // [esp+24h] [ebp-408h] BYREF
  int v13; // [esp+1A4h] [ebp-288h]
  char v14; // [esp+1A8h] [ebp-284h]
  int v15; // [esp+1B0h] [ebp-27Ch]
  int v16; // [esp+1B4h] [ebp-278h]
  int v17; // [esp+1B8h] [ebp-274h]
  _BYTE v18[384]; // [esp+1BCh] [ebp-270h] BYREF
  _DWORD v19[60]; // [esp+33Ch] [ebp-F0h] BYREF

  v11 = (int)this;
  memset(v18, 0, sizeof(v18));
  v13 = 0;
  v17 = 0;
  v15 = 0;
  v16 = 0;
  v14 = 1;
  v2 = 0;
  if ( !sub_566CC0(v18, 384) )
    return 1;
  v3 = v19;
  do
  {
    v4 = sub_5651B0(v12);
    if ( !v4 )
    {
      if ( sub_565870(aControlpoint, &v8, &v9, &v10, 0, 0, 0, 0, 0) && v2 < 20 )
      {
        v5 = v9;
        *v3 = v8;
        v6 = v10;
        v3[1] = v5;
        ++v2;
        v3[2] = v6;
        v3 += 3;
      }
      continue;
    }
    if ( v4 == 2 || v4 == 4 )
      break;
  }
  while ( sub_566CC0(v18, 384) );
  if ( v2 < 4 )
    return 1;
  else
    return sub_457F90(v11, v19, v2);
}
